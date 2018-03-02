
#define CALLISTA_INTERNAL

#include <callista/app.hpp>
#include <callista/types.hpp>
#include <callista/ui/document_window.hpp>

Dynarr<String> args;
CallistaApp app_config;

#if CS_OS_WIN32

	// I try to keep my code clean and professional,
	// but all I can say here is...
	//
	// What the fuck, Windows?
	//
	// Sigh...
	dynarr<string> _win32_get_cmdline();

#else
	#if CS_OS_GTK
		int __gtk_argc; char **__gtk_argv;
		#define GIVE_GTK_ARGS(argc, argv) do{__gtk_argc = argc; __gtk_argv = argv;}while(0)
	#else
		#define GIVE_GTK_ARGS(argc, argv)
	#endif
	void _nix_args(int argc, char *argv[]) {
		GIVE_GTK_ARGS(argc, argv);
		for(int i = 1; i < argc; i++) {
			args.push_back(String(argv[i]));
		}
	}
#endif

int _platform_init();

// This is the "entry point" for Callista.
// This is where we go from platform setup to actually
// making windows and beginning the application.
// 
// We can NOT guarantee that this runs on the same thread as everything from
// _callista_init and before.
void _post_init() {

	printf("Creating document window\n");
	DocumentWindow *window = create_document_window();

}

// This procedure doesn't really do anything
// It exists solely for future-proofing so that we can
// do stuff before platform initialization if we really HAVE to.
// Also, this calls the platform initialization function.
int _callista_init() {

	if(args.size() > 0) {
		// TODO: Parse arguments.
	}

	return _platform_init();
}

#define COMING_FROM_APP_CPP

#if CS_OS_WIN32
	#error "Unimplemented platform."
#elif CS_OS_DARWIN
	#error "Unimplemented platform."
#elif CS_OS_GTK
	#include "app_gtk_impl.hpp"
#else
	#error "Unimplemented platform."
#endif