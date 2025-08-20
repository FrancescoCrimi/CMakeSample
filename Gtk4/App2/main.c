/**
 * Tipo di applicazione: GTK4 minimale con GMainLoop
 *
 * Descrizione:
 *  - Inizializza manualmente GTK con gtk_init().
 *  - Crea e avvia un GMainLoop per il ciclo principale.
 *  - Alla chiusura della finestra, chiama g_main_loop_quit() per uscire.
 */

#include <gtk/gtk.h>

/**
 * @brief Callback per il primo pulsante. Apre la "Finestra Uno".
 * @param button Il pulsante che ha generato l'evento.
 * @param user_data Il puntatore alla finestra principale (GtkWindow *).
 */
static void on_builder_button_clicked(GtkButton *button, gpointer user_data)
{
    // GtkWindow *main_window = GTK_WINDOW(user_data);
    g_print("Pulsante 'Apri Finestra Uno' cliccato.\n");
    // // Chiama la funzione per creare la prima finestra, definita in first_window.c
    // create_builder_window(main_window);
}

/**
 * @brief Callback per il secondo pulsante. Apre la "Finestra Due".
 * @param button Il pulsante che ha generato l'evento.
 * @param user_data Il puntatore alla finestra principale (GtkWindow *).
 */
static void on_manual_button_clicked(GtkButton *button, gpointer user_data)
{
    // GtkWindow *main_window = GTK_WINDOW(user_data);
    g_print("Pulsante 'Apri Finestra Due' cliccato.\n");
    // // Chiama la funzione per creare la seconda finestra, definita in secondary_window.c
    // create_manual_window(main_window);
}

static gboolean on_close_request(GtkWindow *win, GMainLoop *loop)
{
    // Segnale gestito: quando si chiede la chiusura,
    // termina il GMainLoop e lascia che GTK distrugga la finestra.
    g_main_loop_quit(loop);
    return FALSE; // FALSE consente la distruzione della finestra
}

int main(int argc, char **argv)
{
    GMainLoop *loop;
    GtkWindow *window;
    GtkBox *vbox;
    GtkWidget *label;
    GtkWidget *builder_button;
    GtkWidget *manual_button;
    GtkWidget *exit_button;

    // Inizializzazione di GTK
    gtk_init();

    // Creazione del main loop
    loop = g_main_loop_new(NULL, FALSE);

    // Creazione della finestra principale
    window = GTK_WINDOW(gtk_window_new());
    gtk_window_set_title(window, "GTK4 App 2");
    gtk_window_set_default_size(window, 300, 250);

    // Collegamento del segnale di chiusura al nostro callback
    g_signal_connect(window, "close-request",
                     G_CALLBACK(on_close_request), loop);

    // Crea un GtkBox per organizzare i widget verticalmente
    vbox = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 15));
    gtk_widget_set_margin_bottom(GTK_WIDGET(vbox), 15);
    gtk_widget_set_margin_top(GTK_WIDGET(vbox), 15);
    gtk_widget_set_margin_start(GTK_WIDGET(vbox), 15);
    gtk_widget_set_margin_end(GTK_WIDGET(vbox), 15);
    gtk_widget_set_halign(GTK_WIDGET(vbox), GTK_ALIGN_CENTER);
    gtk_widget_set_valign(GTK_WIDGET(vbox), GTK_ALIGN_CENTER);
    gtk_window_set_child(window, GTK_WIDGET(vbox));

    // Crea la label di benvenuto
    label = gtk_label_new("Finestra Principale");
    gtk_label_set_markup(GTK_LABEL(label), "<big><b>Finestra Principale</b></big>");
    gtk_box_append(vbox, label);

    // Crea il primo pulsante
    builder_button = gtk_button_new_with_label("Apri Builder Window");
    g_signal_connect(builder_button, "clicked", G_CALLBACK(on_builder_button_clicked), window);
    gtk_box_append(vbox, builder_button);

    // Crea il secondo pulsante
    manual_button = gtk_button_new_with_label("Apri Manual Window");
    g_signal_connect(manual_button, "clicked", G_CALLBACK(on_manual_button_clicked), window);
    gtk_box_append(vbox, manual_button);

    // Crea pulsante Exit
    exit_button = gtk_button_new_with_label("Exit");
    g_signal_connect_swapped(exit_button, "clicked", G_CALLBACK(gtk_window_destroy), window);
    gtk_box_append(vbox, exit_button);

    // Mostra la finestra e avvia il loop
    gtk_window_present(window);
    g_main_loop_run(loop);

    // Pulizia delle risorse del main loop
    g_main_loop_unref(loop);
    return 0;
}

#ifdef _WIN32

#include <windows.h>

/*
 * Definizione di WinMain per compilare come applicazione GUI con MSVC o MinGW.
 * Per MSVC /SUBSYSTEM:WINDOWS (WIN32_EXECUTABLE) oppure per MinGW con -mwindows
 * non viene aperta la console.
 *
 * Le variabili globali __argc e __argv (disponibili con MSVC) vengono usate per
 * inoltrare gli argomenti a main.
 */
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    return main(__argc, __argv);
}

#endif
