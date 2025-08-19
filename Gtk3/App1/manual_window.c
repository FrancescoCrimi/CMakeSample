#include "manual_window.h"
#include "dialog.h"

/**
 * @brief Crea e configura la seconda finestra secondaria.
 * @param parent_window Il puntatore alla finestra genitore (per transient, non obbligatorio per finestre indipendenti).
 * @return Un puntatore al nuovo GtkWindow creato.
 */
GtkWindow *create_manual_window(GtkWindow *parent_window)
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkLabel *label;
    GtkWidget *show_message_dialog_button;
    GtkWidget *exit_button;
    MyContextObject *shared_context;

    // Crea la finestra principale associata all'applicazione
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Manual Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Connette il segnale "destroy" della finestra secondaria per chiuderla.
    // Solo questa finestra verrà distrutta, l'applicazione principale rimarrà aperta.
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_widget_destroy), NULL);

    // Crea un contenitore verticale (GtkBox) con spacing di 15 pixel
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 15);
    // Aggiunge un margine per centrare meglio i widget
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 15);
    gtk_widget_set_halign(vbox, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(vbox, GTK_ALIGN_CENTER);
    // Aggiunge il contenitore alla finestra
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Crea una label con testo iniziale
    label = (GtkLabel *)gtk_label_new("Initial text");
    // Inserisce la label all'interno del contenitore, con espansione e riempimento
    gtk_box_pack_start(GTK_BOX(vbox), GTK_WIDGET(label), TRUE, TRUE, 0);

    // Struttura per i widget utili con malloc
    shared_context = g_new0(MyContextObject, 1);
    shared_context->window = GTK_WINDOW(window);
    shared_context->label = label;


    // Crea il pulsante "Show MessageDialog"
    show_message_dialog_button = gtk_button_new_with_label("Show MessageDialog");
    g_signal_connect_swapped(show_message_dialog_button, "clicked", G_CALLBACK(show_message_dialog), shared_context);
    gtk_box_pack_start(GTK_BOX(vbox), show_message_dialog_button, TRUE, TRUE, 0);

    // Crea il pulsante "Exit"
    exit_button = gtk_button_new_with_label("Exit");
    g_signal_connect_swapped(exit_button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_box_pack_start(GTK_BOX(vbox), exit_button, TRUE, TRUE, 0);

    gtk_widget_show_all(window);

    return GTK_WINDOW(window);
}