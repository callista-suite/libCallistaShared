#pragma once

#include <callista/types.hpp>

#if CS_OS_GTK
	#include <gtk/gtk.h>
#endif

struct Icon {
	// TODO(zachary): Vector path
};

CS_LIB_PROC_C Icon get_platform_icon(String name, String fallback);