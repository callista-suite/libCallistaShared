
#ifndef COMING_FROM_APP_CPP
	// This file is only included by app.cpp
	// This is just for editor error checking stuff :)
	#include "app.c"
#endif

CallistaGtkData gtk_data;

void _platform_activate(GtkApplication *app, gpointer user_data) {
	gtk_data.app = app;
	_post_init();
}

int _platform_init() {
	
	GtkApplication *app;

	app = gtk_application_new(app_config.package_id, G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(_platform_activate), NULL);

	int status = g_application_run(G_APPLICATION(app), __gtk_argc, __gtk_argv);

	g_object_unref(app);

	return status;
}