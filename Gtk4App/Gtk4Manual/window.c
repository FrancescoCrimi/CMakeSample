#include "window.h"
#include "dialog.h"

/**
 * Callback per show_message_dialog_button.
 */
static void on_show_message_dialog_clicked(GtkWidget *button, gpointer user_data)
{
    AppWidgets *widgets = (AppWidgets *)user_data;
    show_message_dialog(widgets);
}

/**
 * Callback per show_alert_dialog_button.
 */
static void on_show_alert_dialog_clicked(GtkWidget *button, gpointer user_data)
{
    AppWidgets *widgets = (AppWidgets *)user_data;
    show_alert_dialog(widgets);
}

/**
 * Callback per exit_button terminare l'applicazione.
 */
static void on_exit_clicked(GtkWidget *button, gpointer user_data)
{
    GApplication *app = G_APPLICATION(user_data);
    g_application_quit(app);
}

GtkWindow *create_main_window(GtkApplication *app)
{
    /* Crea la finestra principale */
    GtkWindow *window = GTK_WINDOW(gtk_application_window_new(app));
    gtk_window_set_title(window, "GTK4 Manual Example");
    gtk_window_set_default_size(window, 400, 200);

    /* Crea un container verticale centrato */
    GtkBox *vbox = (GtkBox *)gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_halign(GTK_WIDGET(vbox), GTK_ALIGN_CENTER);
    gtk_widget_set_valign(GTK_WIDGET(vbox), GTK_ALIGN_CENTER);
    gtk_window_set_child(window, GTK_WIDGET(vbox));

    /* Crea la label */
    GtkWidget *label = gtk_label_new("Initial text");
    gtk_box_append(vbox, label);

    /* Struttura per i Widget */
    // AppWidgets *widgets = g_new0(AppWidgets, 1);
    // widgets->window = window;
    // widgets->label = GTK_LABEL(label);

    /* Struttura per i widget senza malloc */
    static AppWidgets widgets;
    widgets.window = window;
    widgets.label = GTK_LABEL(label);

    /* Crea il primo pulsante per mostrare il dialogo */
    GtkWidget *show_message_dialog_button = gtk_button_new_with_label("Show MessageDialog");
    gtk_box_append(vbox, show_message_dialog_button);
    g_signal_connect(show_message_dialog_button, "clicked", G_CALLBACK(on_show_message_dialog_clicked), &widgets);

    /* Crea il primo pulsante per mostrare il dialogo */
    GtkWidget *show_alert_dialog_button = gtk_button_new_with_label("Show AlertDialog");
    gtk_box_append(vbox, show_alert_dialog_button);
    g_signal_connect(show_alert_dialog_button, "clicked", G_CALLBACK(on_show_alert_dialog_clicked), &widgets);

    /* Crea il secondo pulsante per l'uscita */
    GtkWidget *exit_button = gtk_button_new_with_label("Exit");
    gtk_box_append(vbox, exit_button);
    g_signal_connect(exit_button, "clicked", G_CALLBACK(on_exit_clicked), app);

    return window;
}
