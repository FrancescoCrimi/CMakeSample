#include "window.h"
#include "dialog.h"

/**
 * Callback "on_show_dialog_button_clicked".
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
    // Carica il file XML contenente la descrizione dell'interfaccia
    GtkBuilder *builder = gtk_builder_new_from_file("interface.ui");
    if (!builder)
    {
        g_printerr("Error loading interface file\n");
        g_application_quit(G_APPLICATION(app));
        return NULL;
    }

    // Recupera i widget definiti nel file XML tramite i loro ID
    GtkWindow *window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));
    // Aggiunge la finestra all'istanza dell'applicazione
    gtk_window_set_application(window, app);

    GtkLabel *label = GTK_LABEL(gtk_builder_get_object(builder, "main_label"));

    // Struttura per i widget utili con malloc
    // AppWidgets *appWidgets = g_new0(AppWidgets, 1);
    // appWidgets->window = window;
    // appWidgets->label = label;

    // Struttura per i widget utili senza malloc
    static AppWidgets appWidgets;
    appWidgets.window = window;
    appWidgets.label = label;

    GtkWidget *show_dialog_button = GTK_WIDGET(gtk_builder_get_object(builder, "dialog_button"));
    // Collega il segnale "clicked" al relativo callback
    g_signal_connect(show_dialog_button, "clicked", G_CALLBACK(on_show_dialog_clicked), &appWidgets);

    GtkWidget *exit_button = GTK_WIDGET(gtk_builder_get_object(builder, "exit_button"));
    // Collega il segnale "clicked" al callback che chiude l'applicazione
    g_signal_connect(exit_button, "clicked", G_CALLBACK(on_exit_clicked), app);

    // Libera le risorse allocate per il builder
    g_object_unref(builder);

    return window;
}
