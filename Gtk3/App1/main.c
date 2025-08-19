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

#include "main_window.h"

/**
 * @brief Funzione di attivazione dell'applicazione GTK.
 * Viene chiamata quando l'applicazione viene avviata.
 * @param app Il puntatore all'oggetto GtkApplication.
 * @param user_data Dati utente (non usati in questo caso).
 */
static void on_app_activate(GtkApplication *app, gpointer user_data)
{
    // Chiama la funzione per creare e mostrare la finestra principale.
    // Questa funzione è definita in main_window.c
    create_main_window(app);
}

/**
 * @brief Funzione Main del programma.
 * Punto di ingresso dell'applicazione.
 * @param argc Il numero di argomenti della riga di comando.
 * @param argv Gli argomenti della riga di comando.
 * @return Lo stato di uscita dell'applicazione.
 */
int main(int argc, char *argv[])
{
    GtkApplication *app;
    int status;

    // Crea una nuova istanza dell'applicazione con un ID e flag standard
    app = gtk_application_new("com.example.gtk3.builder", G_APPLICATION_DEFAULT_FLAGS);

    // Collega l'evento "activate" alla funzione "on_app_activate"
    g_signal_connect(app, "activate", G_CALLBACK(on_app_activate), NULL);

    // Avvia l'applicazione e ne attende la chiusura, salvando il valore di ritorno
    status = g_application_run(G_APPLICATION(app), argc, argv);

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
