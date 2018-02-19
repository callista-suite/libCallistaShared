#pragma once

#include <callista/build_info.hpp>
#include <callista/types.hpp>

#if CS_OS_GTK
	#include <gtk/gtk.h>
#endif

struct Document;


// WARNING: Pointers to DocumentWindows can be invalidated at **ANY** time!!!
struct DocumentWindow {

	// TODO(zachary): Should every program's document window have an array of tabs?
	//                For some programs, like Animate, this seemes... needless.
	Dynarr<Document*> tabs;

#if CS_OS_GTK
	GtkWidget *gtk_window;
#endif

};

DocumentWindow *create_document_window();
void close_document_window(DocumentWindow *);