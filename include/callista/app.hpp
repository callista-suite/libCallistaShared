#pragma once

#include <callista/build_info.hpp>
#include <callista/types.hpp>
#include <callista/ui/document_window.hpp>
#include <stdio.h>

extern Dynarr<String> args;

struct CallistaApp {
	const char* package_id;
	const char* friendly_name;
	void (*setup_document_window_proc)(DocumentWindow *window);
};

CS_LIB_PROC_C int _callista_init();

#if CS_OS_GTK
	#include <callista/os/app_gtk.hpp>
#endif


// Below isn't really part of the public API.
// It's not useful for an app developer, for the most part.

#if CS_OS_WIN32

	// dynarr<string> _win32_get_cmdline();

	#error "No Win32 code has been written for app startup yet. Perhaps you could contribute something?"

#elif CS_OS_APPLE

	#error "No macOS app code has been written yet. Perhaps you could contribute something?"

#else

	#define CALLISTA_MAIN(setup_app_struct) \
		int main(int argc, char *argv[]) { \
			_nix_args(argc, argv); \
			app_config = setup_app_struct(); \
			return _callista_init(); \
		}

#endif

#if CS_OS_WIN32

	// TODO(zachary): Red "ERROR:" prefix
	#define console_error(...) printf(__VA_ARGS__)

#else

	#define console_error(...) do{ printf("\033[1;31mERROR: \033[0m"); printf(__VA_ARGS__); }while(0)

	CS_LIB_PROC_C void _nix_args(int argc, char *argv[]);
#endif

extern CallistaApp app_config;

#ifdef CALLISTA_INTERNAL
	extern "C" CS_LIB_HIDE void _post_init();
#endif