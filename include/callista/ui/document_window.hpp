#pragma once

#include <callista/build_info.hpp>
#include <callista/types.hpp>

#include "gui_widget.hpp"

struct Document;


// WARNING: Pointers to DocumentWindows can be invalidated at **ANY** time!!!
struct DocumentWindow {

// NOTE: Platform-specific implementation details MUST be at the top of the struct.
//       Some functions take void pointers for any component, and these pointers
//       need to be castable into backend data.
	GUI_Widget backend;

	// TODO(zachary): Should every program's document window have an array of tabs?
	//                For some programs, like Animate, this seemes... needless.
	Dynarr<Document*> tabs;

};

CS_LIB_PROC_C DocumentWindow *create_document_window();
CS_LIB_PROC_C void close_document_window(DocumentWindow *);