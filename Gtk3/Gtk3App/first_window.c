#include "first_window.h"
#include "dialog.h"

/**
 * @brief Crea e configura la prima finestra secondaria.
 * @param parent_window Il puntatore alla finestra genitore (per transient, non obbligatorio per finestre indipendenti).
 * @return Un puntatore al nuovo GtkWindow creato.
 */
GtkWindow *create_first_window(GtkWindow *parent_window)
{
    GtkBuilder *builder;
    GtkWindow *window;
    GtkLabel *label;
    GtkWidget *show_dialog_button;
    GtkWidget *exit_button;
    MyContextObject *shared_context;

    // Carica il file XML contenente la descrizione dell'interfaccia
    builder = gtk_builder_new_from_file("interface.ui");
    if (!builder)
        g_error("Errore fatale: Impossibile caricare il file interface.ui. Il programma termina.");

    // Recupera i widget definiti nel file XML tramite i loro ID
    window = GTK_WINDOW(gtk_builder_get_object(builder, "first_window"));
    label = GTK_LABEL(gtk_builder_get_object(builder, "main_label"));

    // Struttura per i widget utili con malloc
    shared_context = g_new0(MyContextObject, 1);
    if (shared_context == NULL)
        g_error("Errore fatale: Impossibile allocare memoria per MyContextObject. Il programma termina.");
    shared_context->window = window;
    shared_context->label = label;


    show_dialog_button = GTK_WIDGET(gtk_builder_get_object(builder, "dialog_button"));
    // Collega il segnale "clicked" al relativo callback
    g_signal_connect_swapped(show_dialog_button, "clicked", G_CALLBACK(show_dialog), shared_context);

    exit_button = GTK_WIDGET(gtk_builder_get_object(builder, "exit_button"));
    // Collega il segnale "clicked" al callback che chiude l'applicazione
    g_signal_connect_swapped(exit_button, "clicked", G_CALLBACK(gtk_widget_destroy), window);

    // Libera le risorse allocate per il builder
    g_object_unref(builder);

    gtk_widget_show_all(window);

    return window;
}
