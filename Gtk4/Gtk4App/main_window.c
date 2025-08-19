#include <gtk/gtk.h>          // Necessario per le funzioni GTK
#include "main_window.h"      // Include l'header di questo modulo
#include "builder_window.h"   // Include l'header della prima finestra secondaria
#include "manual_window.h"    // Include l'header della seconda finestra secondaria

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
    GtkWindow *main_window;
    GtkBox *vbox;
    GtkWidget *welcome_label;
    GtkWidget *builder_button;
    GtkWidget *manual_button;
    GtkWidget *exit_button;

    // Crea la finestra principale dell'applicazione
    main_window = GTK_WINDOW(gtk_application_window_new(app)); // Associa la finestra all'applicazione
    gtk_window_set_title(main_window, "App Gtk4");
    gtk_window_set_default_size(main_window, 300, 250);
    // Connette il segnale "close-request" della finestra principale.
    // Questo segnale viene emesso quando l'utente tenta di chiudere la finestra.
    // gtk_window_destroy distrugge la finestra. Poiché è una GtkApplicationWindow,
    // se è l'ultima finestra, GtkApplication terminerà automaticamente.
    g_signal_connect(main_window, "close-request", G_CALLBACK(gtk_window_destroy), NULL);

    // Crea un GtkBox per organizzare i widget verticalmente
    vbox = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 15));
    gtk_widget_set_margin_bottom(GTK_WIDGET(vbox), 15);
    gtk_widget_set_margin_top(GTK_WIDGET(vbox), 15); 
    gtk_widget_set_margin_start(GTK_WIDGET(vbox), 15); 
    gtk_widget_set_margin_end(GTK_WIDGET(vbox), 15); 
    gtk_widget_set_halign(GTK_WIDGET(vbox), GTK_ALIGN_CENTER);
    gtk_widget_set_valign(GTK_WIDGET(vbox), GTK_ALIGN_CENTER);
    gtk_window_set_child(main_window, GTK_WIDGET(vbox));

    // Crea la label di benvenuto
    welcome_label = gtk_label_new("Finestra Principale");
    // Imposta il testo della label in grassetto per renderlo più evidente
    gtk_label_set_markup(GTK_LABEL(welcome_label), "<big><b>Finestra Principale</b></big>");
    gtk_box_append(vbox, welcome_label);

    // Crea il primo pulsante
    builder_button = gtk_button_new_with_label("Apri Builder Window");
    // Passa la finestra principale come user_data alla callback del pulsante
    g_signal_connect(builder_button, "clicked", G_CALLBACK(on_builder_button_clicked), main_window);
    gtk_box_append(vbox, builder_button);

    // Crea il secondo pulsante
    manual_button = gtk_button_new_with_label("Apri Manual Window");
    g_signal_connect(manual_button, "clicked", G_CALLBACK(on_manual_button_clicked), main_window);
    gtk_box_append(vbox, manual_button);

    // Crea pulsante Exit
    exit_button = gtk_button_new_with_label("Exit");
    g_signal_connect_swapped(exit_button, "clicked", G_CALLBACK(gtk_window_destroy), main_window);
    gtk_box_append(vbox, exit_button);

    // Mostra Finestra
    gtk_window_present(main_window);

    return main_window;
}
