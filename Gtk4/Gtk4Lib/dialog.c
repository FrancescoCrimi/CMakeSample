#include "dialog.h"

/**
 * @brief Callback per response di MessageDialog.
 * 
 * Chiamata quando l'utente risponde al messaggio del dialogo
 * 
 * @param dialog puntatore al GtkDialog di origine
 * @param response_id il valore della risposta selezionata.
 * @param user_data puntatore alla GtkLabel della finestra principale.
 */
static void on_message_dialog_response(GtkDialog *dialog, gint response_id, gpointer user_data)
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
    gtk_window_destroy(GTK_WINDOW(dialog));
}

/**
 * @brief Callback per choose di AlertDialog
 * 
 * Chiamata quando l'utente risponde ad AlertDialog
 * 
 * @param dialog puntatore al GtkDialog di origine
 * @param res GAsyncResult
 * @param user_data puntatore alla GtkLabel della finestra principale.
 */
static void on_alert_dialog_choose(GObject *source_object, GAsyncResult *res, gpointer user_data)
{
    GtkAlertDialog *dialog = GTK_ALERT_DIALOG(source_object);
    GtkLabel *label = GTK_LABEL(user_data);
    GError *err = NULL;

    int button = gtk_alert_dialog_choose_finish(dialog, res, &err);

    if (err)
    {
        g_print("An error occured!\n");
        g_print("Error Message: %s\n", err->message);
        return;
    }

    if (button == 0)
        gtk_label_set_text(label, "You selected: Yes");
    else if (button == 1)
        gtk_label_set_text(label, "You selected: No");
    else if (button == 2)
        gtk_label_set_text(label, "You selected: Cancel");
    else
        gtk_label_set_text(label, "Unknown response");
}

void show_message_dialog(MyContextObject *widgets)
{
    /* Crea il dialogo impostato come modale, associato alla finestra principale.
       Il dialogo è di tipo "question" e non usa i pulsanti predefiniti (GTK_BUTTONS_NONE) */
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(widgets->window),                       // La finestra principale funge da genitore
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
    g_signal_connect(dialog, "response", G_CALLBACK(on_message_dialog_response), widgets->label);

    // Mostra il dialogo con tutti i widget
    gtk_window_present(GTK_WINDOW(dialog));
}

void show_alert_dialog(MyContextObject *widgets)
{
    GtkAlertDialog *dialog = gtk_alert_dialog_new("Confirm");
    const char *buttons[] = {"_Yes", "_No", "_Cancel", NULL};
    gtk_alert_dialog_set_detail(dialog, "Choose an option:");
    gtk_alert_dialog_set_buttons(dialog, buttons);
    gtk_alert_dialog_set_cancel_button(dialog, 2);
    gtk_alert_dialog_set_default_button(dialog, 0);
    gtk_alert_dialog_choose(dialog, GTK_WINDOW(widgets->window), NULL, on_alert_dialog_choose, widgets->label);
}
