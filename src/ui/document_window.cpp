#include <callista/build_info.h>

#if CS_OS_GTK
	#include "gtk/document_window_impl.h"
#else
	#error "Unsupported platform."
#endif