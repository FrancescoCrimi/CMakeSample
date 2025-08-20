#include <stdlib.h>
#include <gtk/gtk.h>

static void helloWorld(GtkWidget *wid, GtkWidget *win)
{
	GtkWidget *dialog = NULL;

	// Crea MessageDialog
	dialog = gtk_message_dialog_new(GTK_WINDOW(win),
									GTK_DIALOG_MODAL,
									GTK_MESSAGE_INFO,
									// GTK_BUTTONS_CLOSE,
									GTK_BUTTONS_NONE,
									"Confirm");

	// Aggiunge Bottoni
	gtk_dialog_add_buttons(GTK_DIALOG(dialog),
						   "Yes", GTK_RESPONSE_YES,
						   "No", GTK_RESPONSE_NO,
						   "Cancel", GTK_RESPONSE_CANCEL,
						   NULL);

	/* Aggiungi un testo secondario */
	gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog),
											 "Choose an option:");

	gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[])
{
	GtkWidget *win = NULL;
	GtkWidget *vbox = NULL;
	GtkWidget *label;
	GtkWidget *button = NULL;

	// Inizializzazione di GTK
	g_log_set_handler("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc)gtk_false, NULL);
	gtk_init(&argc, &argv);
	g_log_set_handler("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

	// Crea la finestra principale dell'applicazione
	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(win), "Gtk3 App 2");
	gtk_window_set_default_size(GTK_WINDOW(win), 300, 250);
	gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
	gtk_widget_realize(win);

	// Connette il segnale "destroy" della finestra principale per terminare l'applicazione
	// Quando la finestra principale viene chiusa, l'intera applicazione termina.
	g_signal_connect(win, "destroy", gtk_main_quit, NULL);

	// Crea un GtkBox per organizzare i widget verticalmente
	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 15);
	// Aggiunge un margine per centrare meglio i widget
	gtk_container_set_border_width(GTK_CONTAINER(vbox), 15);
	gtk_widget_set_halign(vbox, GTK_ALIGN_CENTER);
	gtk_widget_set_valign(vbox, GTK_ALIGN_CENTER);
	gtk_container_add(GTK_CONTAINER(win), vbox);

	// Crea la label di benvenuto
	label = gtk_label_new("Finestra Principale");
	// Imposta il testo della label in grassetto per renderlo più evidente
	gtk_label_set_markup(GTK_LABEL(label), "<big><b>Finestra Principale</b></big>");
	gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0); // Non espandere, non riempire

	// Crea il primo pulsante
	button = gtk_button_new_with_label("Apri Window");
	gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(helloWorld), (gpointer)win);

	// Crea Pulsante Exit
	button = gtk_button_new_with_label("Exit");
	gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);
	g_signal_connect(button, "clicked", gtk_main_quit, NULL);

	// Mostra la finestra
	gtk_widget_show_all(win);

	// Entra nel main loop
	gtk_main();

	return 0;
}
