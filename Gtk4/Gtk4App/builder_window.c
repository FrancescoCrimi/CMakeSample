#include "builder_window.h" // Include l'header di questo modulo
#include <gtk/gtk.h>      // Necessario per le funzioni GTK
#include "dialog.h"

/**
 * La funzione di distruzione per MyContextObject.
 * Verrà chiamata automaticamente da GTK quando l'oggetto GObject a cui è associata
 * viene distrutto (nel nostro caso, la GtkWindow principale).
 */
static void destroy_my_context_object(gpointer data)
{
    MyContextObject *obj = (MyContextObject *)data;
    if (obj != NULL)
    {
        g_print("DEBUG: Liberazione della memoria per MyContextObject.\n");
        g_free(obj);
    }
}

/**
 * @brief Crea e configura la prima finestra secondaria.
 * @param app Il puntatore all'oggetto GtkApplication.
 * @param parent_window Il puntatore alla finestra genitore (per transient, non obbligatorio per finestre indipendenti).
 * @return Un puntatore al nuovo GtkWindow creato.
 */
GtkWindow *create_builder_window(GtkWindow *parent_window)
{
    GtkWindow *window;
    GtkWidget *label;

    GtkBuilder *builder = gtk_builder_new_from_file("interface.ui");
    if (!builder)
        g_error("Errore fatale: Impossibile caricare il file interface.ui. Il programma termina.");

    /* Recupera i widget definiti nel file .ui */
    window = GTK_WINDOW(gtk_builder_get_object(builder, "first_window"));
    // gtk_window_set_application(window, app); // solo se la finestra è finestra principale
    g_signal_connect(window, "close-request", G_CALLBACK(gtk_window_destroy), NULL);

    label = GTK_WIDGET(gtk_builder_get_object(builder, "main_label"));

    /* Struttura per i Widget */
    MyContextObject *shared_context = g_new0(MyContextObject, 1);
    if (shared_context == NULL)
        g_error("Errore fatale: Impossibile allocare memoria per MyContextObject. Il programma termina.");
    shared_context->window = window;
    shared_context->label = GTK_LABEL(label);

    // Associa la MyContextObject alla GtkWindow.
    // Quando la finestra verrà distrutta, GTK chiamerà destroy_my_context_object()
    // passando 'shared_context' come argomento.
    g_object_set_data_full(G_OBJECT(window),
                           "my-shared-context",        // Chiave per recuperare i dati
                           shared_context,             // Il puntatore ai tuoi dati
                           destroy_my_context_object); // La funzione di distruzione!

    GtkWidget *show_message_dialog_button = GTK_WIDGET(gtk_builder_get_object(builder, "show_message_dialog_button"));
    g_signal_connect_swapped(show_message_dialog_button, "clicked", G_CALLBACK(show_message_dialog), shared_context);

    GtkWidget *show_alert_dialog_button = GTK_WIDGET(gtk_builder_get_object(builder, "show_alert_dialog_button"));
    g_signal_connect_swapped(show_alert_dialog_button, "clicked", G_CALLBACK(show_alert_dialog), shared_context);

    GtkWidget *exit_button = GTK_WIDGET(gtk_builder_get_object(builder, "exit_button"));
    g_signal_connect_swapped(exit_button, "clicked", G_CALLBACK(gtk_window_destroy), window);

    /* Libera il builder (le istanze dei widget sono gestite dal sistema di riferimento di GTK) */
    g_object_unref(builder);

    // Mostra Finestra
    gtk_window_present(window);

    return window;
}
