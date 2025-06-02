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
    GtkBuilder *builder = gtk_builder_new_from_file("interface.ui");
    if (!builder)
    {
        g_printerr("Error loading interface file\n");
        g_application_quit(G_APPLICATION(app));
        return NULL;
    }

    /* Recupera i widget definiti nel file .ui */
    GtkWindow *window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));
    gtk_window_set_application(window, app);

    GtkWidget *label = GTK_WIDGET(gtk_builder_get_object(builder, "main_label"));

    /* Struttura per i widget senza malloc */
    static AppWidgets widgets;
    widgets.window = window;
    widgets.label = GTK_LABEL(label);

    GtkWidget *show_message_dialog_button = GTK_WIDGET(gtk_builder_get_object(builder, "show_message_dialog_button"));
    g_signal_connect(show_message_dialog_button, "clicked", G_CALLBACK(on_show_message_dialog_clicked), &widgets);

    GtkWidget *show_alert_dialog_button = GTK_WIDGET(gtk_builder_get_object(builder, "show_alert_dialog_button"));
    g_signal_connect(show_alert_dialog_button, "clicked", G_CALLBACK(on_show_alert_dialog_clicked), &widgets);

    GtkWidget *exit_button = GTK_WIDGET(gtk_builder_get_object(builder, "exit_button"));
    g_signal_connect(exit_button, "clicked", G_CALLBACK(on_exit_clicked), app);

    /* Libera il builder (le istanze dei widget sono gestite dal sistema di riferimento di GTK) */
    g_object_unref(builder);

    return window;
}
