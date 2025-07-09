#include "second_window.h" // Include l'header di questo modulo
#include "dialog.h"
#include <gtk/gtk.h> // Necessario per le funzioni GTK

/**
 * La funzione di distruzione per MyContextObject.
 * Verrà chiamata automaticamente da GTK quando l'oggetto GObject a cui è associata
 * viene distrutto (nel nostro caso, la GtkWindow principale).
 */
static void destroy_my_context_object(gpointer data)
{
    MyContextObject *obj = (MyContextObject *)data;
    // AppWidgets *widgets = (AppWidgets *)data;
    if (obj != NULL)
    {
        g_print("DEBUG: Liberazione della memoria per MyContextObject.\n");
        g_free(obj);
    }
}

/**
 * @brief Crea e configura la seconda finestra secondaria.
 * @param parent_window Il puntatore alla finestra genitore (per transient, non obbligatorio per finestre indipendenti).
 * @return Un puntatore al nuovo GtkWindow creato.
 */
GtkWindow *create_second_window(GtkWindow *parent_window)
{
    GtkWindow *window;
    GtkBox *vbox;
    GtkWidget *label;

    /* Crea la finestra principale */
    window = GTK_WINDOW(gtk_window_new());
    gtk_window_set_title(window, "GTK4 Manual Example");
    gtk_window_set_default_size(window, 400, 200);
    g_signal_connect(window, "close-request", G_CALLBACK(gtk_window_destroy), NULL);

    /* Crea un container verticale centrato */
    vbox = (GtkBox *)gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_halign(GTK_WIDGET(vbox), GTK_ALIGN_CENTER);
    gtk_widget_set_valign(GTK_WIDGET(vbox), GTK_ALIGN_CENTER);
    gtk_window_set_child(window, GTK_WIDGET(vbox));

    /* Crea la label */
    label = gtk_label_new("Initial text");
    gtk_box_append(vbox, label);

    /* Struttura per i Widget */
    MyContextObject *shared_context = g_new0(MyContextObject, 1);
    if (shared_context == NULL)
    {
        // g_error() stampa un messaggio e TERMINA il programma immediatamente.
        g_error("Errore fatale: Impossibile allocare memoria per MyContextObject. Il programma termina.");
    }

    shared_context->window = window;
    shared_context->label = GTK_LABEL(label);

    // Associa la MyContextObject alla GtkWindow.
    // Quando la finestra verrà distrutta, GTK chiamerà destroy_my_context_object()
    // passando 'shared_context' come argomento.
    g_object_set_data_full(G_OBJECT(window),
                           "my-shared-context",        // Chiave per recuperare i dati
                           shared_context,             // Il puntatore ai tuoi dati
                           destroy_my_context_object); // La funzione di distruzione!

    /* Crea il primo pulsante per mostrare il dialogo */
    GtkWidget *show_message_dialog_button = gtk_button_new_with_label("Show MessageDialog");
    gtk_box_append(vbox, show_message_dialog_button);
    g_signal_connect_swapped(show_message_dialog_button, "clicked", G_CALLBACK(show_message_dialog), shared_context);

    /* Crea il primo pulsante per mostrare il dialogo */
    GtkWidget *show_alert_dialog_button = gtk_button_new_with_label("Show AlertDialog");
    gtk_box_append(vbox, show_alert_dialog_button);
    g_signal_connect_swapped(show_alert_dialog_button, "clicked", G_CALLBACK(show_alert_dialog), shared_context);

    /* Crea il secondo pulsante per l'uscita */
    GtkWidget *exit_button = gtk_button_new_with_label("Exit");
    gtk_box_append(vbox, exit_button);
    g_signal_connect_swapped(exit_button, "clicked", G_CALLBACK(gtk_window_destroy), window);

    // Mostra Finestra
    gtk_window_present(window);

    return window;
}
