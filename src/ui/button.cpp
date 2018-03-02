#include <callista/build_info.h>

#if CS_OS_GTK
	#include "gtk/button_impl.h"
#else
	#error "Unsupported platform."
#endif