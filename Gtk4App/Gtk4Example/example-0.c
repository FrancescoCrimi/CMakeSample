#include <gtk/gtk.h>

// Callback per l'attivazione dell'applicazione
static void activate(GtkApplication *app, gpointer user_data)
{
    // Crea la finestra principale
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hello, World!");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Mostra la finestra
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[])
{
    // Crea un'istanza di GtkApplication
    GtkApplication *app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);

    // Collega il segnale "activate"
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // Esegui l'applicazione
    int status = g_application_run(G_APPLICATION(app), argc, argv);

    // Libera la memoria
    g_object_unref(app);

    return status;
}
