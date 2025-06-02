#include "window.h"
#include "dialog.h"

/**
 * Callback "on_show_dialog_button_clicked":
 */
static void on_show_dialog_clicked(GtkWidget *button, gpointer user_data)
{
    // Cast del puntatore ricevuto ad una AppWidgets
    AppWidgets *appWidgets = (AppWidgets *)user_data;
    show_dialog(appWidgets);
}

static void on_exit_clicked(GtkButton *self, gpointer user_data)
{
    GApplication *app = G_APPLICATION(user_data);
    g_application_quit(app);
}

GtkWindow *get_window(GtkApplication *app)
{
    // Crea la finestra principale associata all'applicazione
    GtkWindow *window = (GtkWindow *)gtk_application_window_new(app);
    gtk_window_set_title(window, "GTK3 Manual Example");
    gtk_window_set_default_size(window, 400, 200);

    // Crea un contenitore verticale (GtkBox) con spacing di 10 pixel
    GtkBox *vbox = (GtkBox *)gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    // Aggiunge un margine per centrare meglio i widget
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 20);
    gtk_widget_set_halign(GTK_WIDGET(vbox), GTK_ALIGN_CENTER);
    gtk_widget_set_valign(GTK_WIDGET(vbox), GTK_ALIGN_CENTER);
    // Aggiunge il contenitore alla finestra
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(vbox));

    // Crea una label con testo iniziale
    GtkLabel *label = (GtkLabel *)gtk_label_new("Initial text");
    // Inserisce la label all'interno del contenitore, con espansione e riempimento
    gtk_box_pack_start(vbox, GTK_WIDGET(label), TRUE, TRUE, 0);

    // Struttura per i widget utili con malloc
    // AppWidgets *appWidgets = g_new0(AppWidgets, 1);
    // appWidgets->window = window;
    // appWidgets->label = label;

    // Struttura per i widget utili senza malloc
    static AppWidgets appWidgets;
    appWidgets.window = window;
    appWidgets.label = label;

    // Crea il pulsante "Show Dialog"
    GtkWidget *show_dialog_button = gtk_button_new_with_label("Show Dialog");
    // Inserisce dialog_button nel box
    gtk_box_pack_start(vbox, show_dialog_button, TRUE, TRUE, 0);
    // Collega il segnale "clicked" al relativo callback
    g_signal_connect(show_dialog_button, "clicked", G_CALLBACK(on_show_dialog_clicked), &appWidgets);

    // Crea il pulsante "Exit"
    GtkWidget *exit_button = gtk_button_new_with_label("Exit");
    // Inserisce exit_button nel box
    gtk_box_pack_start(vbox, exit_button, TRUE, TRUE, 0);
    // Collega il segnale "clicked" al callback che chiude l'applicazione
    g_signal_connect(exit_button, "clicked", G_CALLBACK(on_exit_clicked), app);

    return window;
}