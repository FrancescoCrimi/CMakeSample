/**
 * manual.c
 *
 * Questo file implementa un’applicazione GTK+ 3 (versione 3.24) in cui l’interfaccia grafica
 * viene creata interamente in codice, senza l’uso di GtkBuilder.
 *
 * Funzionalità:
 *   - Crea dinamicamente una finestra contenente un contenitore verticale (GtkBox)
 *   - Inserisce una label con un testo iniziale e due pulsanti:
 *        • “Show Dialog”: mostra un dialogo modale con le opzioni Yes/No/Cancel. La scelta
 *          dell’utente modifica il testo della label.
 *        • “Exit”: esce dall’applicazione.
 *
 * Il codice è scritto in standard C (C17).
 */

#include "window.h"

/**
 * Callback "on_app_activate":
 * Viene chiamata quando l'applicazione viene attivata.
 */
static void on_app_activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = GTK_WIDGET(get_window(app));

    // Mostra la finestra principale con tutti i widget al suo interno
    gtk_widget_show_all(window);
}

/**
 * Funzione main: punto d'ingresso dell'applicazione.
 * Crea un'istanza di GtkApplication, connette il segnale "activate" e avvia il ciclo degli eventi.
 */
int main(int argc, char *argv[])
{
    // Crea una nuova istanza dell'applicazione con un ID e flag standard
    GtkApplication *app = gtk_application_new("com.example.gtk3.manual", G_APPLICATION_DEFAULT_FLAGS);

    // Collega l'evento "activate" alla funzione "on_app_activate"
    g_signal_connect(app, "activate", G_CALLBACK(on_app_activate), NULL);

    // Avvia l'applicazione e ne attende la chiusura, salvando il valore di ritorno
    int status = g_application_run(G_APPLICATION(app), argc, argv);

    // Libera l'oggetto app
    g_object_unref(app);

    return status;
}

#ifdef _WIN32

#include <windows.h>

/**
 * Definizione di WinMain per compilare come applicazione GUI con MSVC.
 * Per MSVC /SUBSYSTEM:WINDOWS (WIN32_EXECUTABLE) non viene aperta la console.
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
