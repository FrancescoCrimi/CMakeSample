#include "dialog.h"

/**
 * Callback "on_dialog_response":
 * - Chiamata quando l'utente risponde al messaggio del dialogo.
 * - Il parametro "response_id" contiene il valore della risposta selezionata.
 * - "user_data" contiene un puntatore alla GtkLabel della finestra principale.
 */
static void on_dialog_response(GtkDialog *dialog, gint response_id, gpointer user_data)
{
    // Cast del puntatore ricevuto ad una GtkLabel
    GtkLabel *label = GTK_LABEL(user_data);

    // Verifica la risposta ed aggiorna il testo della label
    switch (response_id)
    {
    case GTK_RESPONSE_YES:
        gtk_label_set_text(label, "You chose: Yes");
        break;
    case GTK_RESPONSE_NO:
        gtk_label_set_text(label, "You chose: No");
        break;
    case GTK_RESPONSE_CANCEL:
        gtk_label_set_text(label, "You chose: Cancel");
        break;
    default:
        gtk_label_set_text(label, "Unknown response");
        break;
    }

    // Distrugge il dialogo per liberare le risorse
    gtk_widget_destroy(GTK_WIDGET(dialog));
}

void show_dialog(AppWidgets *appWidgets)
{
    /* Crea il dialogo impostato come modale, associato alla finestra principale.
       Il dialogo è di tipo "question" e non usa i pulsanti predefiniti (GTK_BUTTONS_NONE) */
    GtkWidget *dialog = gtk_message_dialog_new(appWidgets->window,                                // La finestra principale funge da genitore
                                               GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, // Modal e auto distruttivo
                                               GTK_MESSAGE_QUESTION,                              // Tipo di messaggio (domanda)
                                               GTK_BUTTONS_NONE,                                  // Nessun pulsante di default
                                               "Confirm");                                        // Testo del messaggio

    /* Aggiunge tre pulsanti personalizzati al dialogo:
       "Yes" con risposta GTK_RESPONSE_YES,
       "No" con risposta GTK_RESPONSE_NO,
       "Cancel" con risposta GTK_RESPONSE_CANCEL */
    gtk_dialog_add_buttons(GTK_DIALOG(dialog),
                           "Yes", GTK_RESPONSE_YES,
                           "No", GTK_RESPONSE_NO,
                           "Cancel", GTK_RESPONSE_CANCEL,
                           NULL);

    /* Aggiungi un testo secondario */
    gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog),
                                             "Choose an option:");

    // Collega l'evento "response" al callback on_dialog_response, passando la label come "user_data"
    g_signal_connect(dialog, "response", G_CALLBACK(on_dialog_response), appWidgets->label);

    // Mostra il dialogo con tutti i widget
    gtk_widget_show_all(dialog);
}