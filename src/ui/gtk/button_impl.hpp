#include <callista/ui/button.hpp>


static gboolean _gtk_button_close_event(GtkWidget *widget, gpointer button) {
	free(button);
}

Button *button_create(ButtonKind kind) {

	Button *b = new Button;
	b->backend.gtk_widget = gtk_button_new();
	b->click_handler_id = 0;
	g_signal_connect(b->backend.gtk_widget, "destroy", G_CALLBACK(_gtk_button_close_event), b);
	gtk_widget_show_all(b->backend.gtk_widget);
	
	return b;
}
// TODO(zachary): Does casting gui widgets to GUI_Widget work?
void _button_set_parent(Button *button, GUI_Widget *parent) {
	gtk_container_add(GTK_CONTAINER(parent->gtk_widget), button->backend.gtk_widget);
}
void button_set_label(Button *button, char *label) {
	gtk_button_set_label(GTK_BUTTON(button->backend.gtk_widget), label);
}
void button_set_label(Button *button, String label) {
	button_set_label(button, label.c_str());
}
void button_set_icon(Button *button, Icon icon) {
	// TODO(zachary): For when we have vector rasterization.
}
void button_destroy(Button *button) {
	gtk_widget_destroy(button->backend.gtk_widget);
}
void button_register_callback(Button *button, void (*callback)()) {

	button_remove_callback(button);

	button->click_handler_id = g_signal_connect(button->backend.gtk_widget, "clicked", G_CALLBACK(callback), button);
}
void button_remove_callback(Button *button) {

	if(button->click_handler_id != 0) {

		g_signal_handler_disconnect(button->backend.gtk_widget, button->click_handler_id);
	}
}