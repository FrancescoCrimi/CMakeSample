#include "main_window.h"   // Include l'header di questo modulo
#include "builder_window.h"  // Include l'header della prima finestra secondaria
#include "manual_window.h" // Include l'header della seconda finestra secondaria
#include <gtk/gtk.h>       // Necessario per le funzioni GTK

// --- Callback per i pulsanti della finestra principale ---

/**
 * @brief Callback per il primo pulsante. Apre la "Finestra Uno".
 * @param button Il pulsante che ha generato l'evento.
 * @param user_data Il puntatore alla finestra principale (GtkWindow *).
 */
static void on_builder_button_clicked(GtkButton *button, gpointer user_data)
{
    GtkWindow *main_window = GTK_WINDOW(user_data);
    g_print("Pulsante 'Apri Finestra Uno' cliccato.\n");
    // Chiama la funzione per creare la prima finestra, definita in first_window.c
    create_builder_window(main_window);
}

/**
 * @brief Callback per il secondo pulsante. Apre la "Finestra Due".
 * @param button Il pulsante che ha generato l'evento.
 * @param user_data Il puntatore alla finestra principale (GtkWindow *).
 */
static void on_manual_button_clicked(GtkButton *button, gpointer user_data)
{
    GtkWindow *main_window = GTK_WINDOW(user_data);
    g_print("Pulsante 'Apri Finestra Due' cliccato.\n");
    // Chiama la funzione per creare la seconda finestra, definita in secondary_window.c
    create_manual_window(main_window);
}

/**
 * @brief Crea e configura la finestra principale dell'applicazione.
 * @param app Il puntatore all'oggetto GtkApplication.
 * @return Un puntatore al GtkWindow creato.
 */
GtkWindow *create_main_window(GtkApplication *app)
{
    GtkWidget *main_window;
    GtkWidget *vbox;
    GtkWidget *welcome_label;
    GtkWidget *builder_button;
    GtkWidget *manual_button;
    GtkWidget *exit_button;

    // Crea la finestra principale dell'applicazione
    main_window = gtk_application_window_new(app); // Associa la finestra all'applicazione
    gtk_window_set_title(GTK_WINDOW(main_window), "App Gtk3");
    gtk_window_set_default_size(GTK_WINDOW(main_window), 300, 200);

    // Connette il segnale "destroy" della finestra principale per terminare l'applicazione
    // Quando la finestra principale viene chiusa, l'intera applicazione termina.
    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Crea un GtkBox per organizzare i widget verticalmente
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 15);
    // Aggiunge un margine per centrare meglio i widget
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 15);
    gtk_widget_set_halign(vbox, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(vbox, GTK_ALIGN_CENTER);
    gtk_container_add(GTK_CONTAINER(main_window), GTK_WIDGET(vbox));

    // Crea la label di benvenuto
    welcome_label = gtk_label_new("Finestra Principale");
    // Imposta il testo della label in grassetto per renderlo più evidente
    gtk_label_set_markup(GTK_LABEL(welcome_label), "<big><b>Finestra Principale</b></big>");
    gtk_box_pack_start(GTK_BOX(vbox), welcome_label, FALSE, FALSE, 0); // Non espandere, non riempire

    // Crea il primo pulsante
    builder_button = gtk_button_new_with_label("Apri Builder Window");
    // Passa la finestra principale come user_data alla callback del pulsante
    gtk_box_pack_start(GTK_BOX(vbox), builder_button, TRUE, TRUE, 0); // Espandi e riempi
    g_signal_connect(builder_button, "clicked", G_CALLBACK(on_builder_button_clicked), main_window);

    // Crea il secondo pulsante
    manual_button = gtk_button_new_with_label("Apri Manual Window");
    gtk_box_pack_start(GTK_BOX(vbox), manual_button, TRUE, TRUE, 0); // Espandi e riempi
    g_signal_connect(manual_button, "clicked", G_CALLBACK(on_manual_button_clicked), main_window);

    // Crea Pulsante Exit
    exit_button = gtk_button_new_with_label("Exit");
    gtk_box_pack_start(GTK_BOX(vbox), exit_button, TRUE, TRUE, 0);
    g_signal_connect_swapped(exit_button, "clicked", G_CALLBACK(gtk_widget_destroy), main_window);

    // Mostra tutti i widget nella finestra principale
    gtk_widget_show_all(main_window);

    return GTK_WINDOW(main_window);
}
