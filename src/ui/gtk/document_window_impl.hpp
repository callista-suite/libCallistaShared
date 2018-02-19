
#include <gtk/gtk.h>
#include <callista/ui/document_window.hpp>
#include <callista/document/document.hpp>
#include <callista/app.hpp>
#include "../../function_stub.hpp"

#include <stdlib.h>

inline void free_document_window(DocumentWindow *);

static gboolean _gtk_window_close_event(GtkWidget *widget, GdkEvent *event, gpointer document_window) {

	// We better hope that `data` is a pointer to a Document.
	// If not, we're going to do some wacky stuff here.

	printf("Close event\n");
	
	// TODO(zachary): Refactor this into a platform-agnostic verification function.
	for(size_t i = 0; i < ((DocumentWindow *)document_window)->tabs.size(); i++) {
		Document *document = ((DocumentWindow *)document_window)->tabs[i];
		if(document->is_modified) {
			// TODO(zachary): What if the document was modified?
			//                Verify the user's action here.
			// Hopefully dialogs in GTK (and all other platforms!) are blocking.
		}

		free_document(document);
	}

	srand(time(0));

	int thing = rand() % 10;

	printf("Close event. Picking a random number. %d\n", thing);

	if(thing >= 5) return true;
	
	free_document_window((DocumentWindow *)document_window);

	return false;
}

inline void free_document_window(DocumentWindow *window) {
	free(window);
}

function_stub("`close_document_window` can not implemented for GTK.", void close_document_window(DocumentWindow *window));
function_stub("`close_document_window` can not implemented for GTK.", bool close_document_window2(DocumentWindow *window));

static void window_test_callback(GtkWidget *widget, gpointer data) {
	printf("Yo!\n");
}

DocumentWindow *create_document_window() {

	// Hmmm... how do I plan for the lifecycle of this...

	DocumentWindow *window = new DocumentWindow;

	// TODO(zachary): Is there a way to use GtkApplicationWindow here, and is that the right approach?
	window->gtk_window = gtk_application_window_new(gtk_data.app);

	gtk_window_set_title(GTK_WINDOW(window->gtk_window), app_config.friendly_name);

	gtk_window_set_default_size(GTK_WINDOW(window->gtk_window), 800, 600);


	GtkWidget *button = gtk_button_new_with_label("Close me!");
	g_signal_connect(button, "clicked", G_CALLBACK(window_test_callback), window);
	gtk_container_add(GTK_CONTAINER(window->gtk_window), button);


	gtk_widget_show_all(window->gtk_window);

	// Do I need this?
	// g_object_set_data(G_OBJECT(window->gtk_window), CS_DOCUMENT_WINDOW_KEY, window);

	g_signal_connect(window->gtk_window, "delete-event", G_CALLBACK(_gtk_window_close_event), window);

	return window;

}