#pragma once

#include <callista/build_info.hpp>
#include <callista/types.hpp>
#include "icon.hpp"

#include "gui_widget.hpp"

enum ButtonKind {
	BUTTONKIND_LABEL_ICON,
	BUTTONKIND_LABEL,
	BUTTONKIND_ICON
};

struct Button {

// NOTE: Platform-specific implementation details MUST be at the top of the struct.
//       Some functions take void pointers for any component, and these pointers
//       need to be castable into backend data.
	GUI_Widget backend;

#if CS_OS_GTK
	gulong click_handler_id;
#endif

	ButtonKind kind;
};


CS_LIB_PROC_C   Button *button_create            (ButtonKind kind);
CS_LIB_PROC_C   void   _button_set_parent        (Button *button, GUI_Widget *parent); // We have to REALLY hope that a proper GUI widget is passed here.
CS_LIB_PROC_C   void    button_set_label         (Button *button, char *label);
CS_LIB_PROC_CPP void    button_set_label         (Button *button, String label);
CS_LIB_PROC_C   void    button_set_icon          (Button *button, Icon icon);
CS_LIB_PROC_C   void    button_destroy           (Button *button);
CS_LIB_PROC_C   void    button_register_callback (Button *button, void (*callback)());
CS_LIB_PROC_C   void    button_remove_callback   (Button *button);


#define button_set_parent(button, parent) _button_set_parent(button, (GUI_Widget *)(parent))