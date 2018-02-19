#include <callista/build_info.hpp>

#if CS_OS_GTK
	#include "gtk/document_window_impl.hpp"
#else
	#error "Unsupported platform."
#endif