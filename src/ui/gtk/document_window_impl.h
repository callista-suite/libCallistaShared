
#include <gtk/gtk.h>
#include <callista/ui/document_window.h>
#include <callista/document/document.h>
#include <callista/app.h>
#include "../../function_stub.h"

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

	// Return false to close.
	// Return true to keep alive.

	free_document_window((DocumentWindow *)document_window);

	return false;
}

inline void free_document_window(DocumentWindow *window) {
	free(window);
}

function_stub("`close_document_window` can not be implemented for GTK.", void close_document_window(DocumentWindow *window));

/*
static void window_test_callback(GtkWidget *widget, gpointer data) {
	printf("Yo!\n");
}
*/

DocumentWindow *create_document_window() {

	// Hmmm... how do I plan for the lifecycle of this...

	DocumentWindow *window = new DocumentWindow;

	// TODO(zachary): Is there a way to use GtkApplicationWindow here, and is that the right approach?
	window->backend.gtk_widget = gtk_application_window_new(gtk_data.app);

	gtk_window_set_title(GTK_WINDOW(window->backend.gtk_widget), app_config.friendly_name);

	gtk_window_set_default_size(GTK_WINDOW(window->backend.gtk_widget), 800, 600);

/*
	GtkWidget *button = gtk_button_new_with_label("Close me!");
	g_signal_connect(button, "clicked", G_CALLBACK(window_test_callback), window);
	gtk_container_add(GTK_CONTAINER(window->backend.gtk_widget), button);
*/

	gtk_widget_show_all(window->backend.gtk_widget);

	// Do I need this?
	// g_object_set_data(G_OBJECT(window->backend.gtk_widget), CS_DOCUMENT_WINDOW_KEY, window);

	g_signal_connect(window->backend.gtk_widget, "delete-event", G_CALLBACK(_gtk_window_close_event), window);

	app_config.setup_document_window_proc(window);

	return window;

}