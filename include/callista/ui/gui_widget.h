#pragma once

#include <callista/build_info.h>

#if CS_OS_GTK
	#include <gtk/gtk.h>
#endif

struct GUI_Widget {

	#if CS_OS_GTK
		GtkWidget *gtk_widget;
	#endif
};