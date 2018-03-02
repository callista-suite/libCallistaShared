#include <callista/build_info.hpp>

#if CS_OS_GTK
	#include "gtk/button_impl.hpp"
#else
	#error "Unsupported platform."
#endif