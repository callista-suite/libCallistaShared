#pragma once

#include <callista/build_info.hpp>

#if CS_OS_WIN32

#error "No Win32 code has been written for app startup yet. Perhaps you could contribute something?"

#elif CS_OS_APPLE

#error "No macOS app code has been written yet. Perhaps you could contribute something?"

#else

#define CALLISTA_MAIN(init_proc) \
	int main(int argc, char *argv[]) { \
		_callista_init_pre(); \
		init_proc(); \
		return _callista_init_post(); \
	}

#endif

void _callista_init_pre();
int _callista_init_post();