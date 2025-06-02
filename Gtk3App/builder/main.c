/**
 * builder.c
 *
 * Questo file contiene l’implementazione dell’applicazione GTK+ 3 che carica l’interfaccia
 * da un file XML usando GtkBuilder.
 *
 * Funzionalità:
 *   - Carica l'interfaccia grafica definita in "interface.ui"
 *   - Visualizza una finestra contenente:
 *       • Una label
 *       • Un pulsante per mostrare un messaggio di dialogo con tre opzioni (Yes/No/Cancel)
 *       • Un pulsante per uscire dall’applicazione
 *   - Quando si preme il pulsante del dialogo, viene mostrato un dialogo modale.
 *     La scelta dell’utente (Yes/No/Cancel) modifica il testo della label contenuta nella finestra principale.
 *
 * Il codice è scritto in standard C (C17).
 */

#include "window.h"

/**
 * Callback "on_app_activate":
 * Funzione chiamata quando l'applicazione viene attivata.
 */
static void on_app_activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = GTK_WIDGET(get_window(GTK_APPLICATION(app)));

    if (window)
    {
        // Mostra la finestra principale con tutti i widget al suo interno
        gtk_widget_show_all(window);
    }
}

/**
 * Funzione main: punto d'ingresso dell'applicazione.
 * Crea un'istanza di GtkApplication, connette il segnale "activate" e avvia il ciclo degli eventi.
 */
int main(int argc, char *argv[])
{
    // Crea una nuova istanza dell'applicazione con un ID e flag standard
    GtkApplication *app = gtk_application_new("com.example.gtk3.builder", G_APPLICATION_DEFAULT_FLAGS);

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
