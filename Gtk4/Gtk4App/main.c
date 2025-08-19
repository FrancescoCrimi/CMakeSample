/**
 * Tipo di applicazione: GTK4 con GtkApplication
 *
 * Descrizione:
 *  - Usa GtkApplication per incapsulare il loop principale e le risorse di GTK.
 *  - Avvia l’app con g_application_run().
 *  - Esce pulitamente con g_application_quit() alla chiusura della finestra.
 */

#include <gtk/gtk.h>
#include "main_window.h" // Include l'header della finestra principale

/**
 * @brief Funzione di attivazione dell'applicazione GTK.
 * Viene chiamata quando l'applicazione viene avviata.
 * @param app Il puntatore all'oggetto GtkApplication.
 * @param user_data Dati utente (non usati in questo caso).
 */
static void on_activate(GtkApplication *app, gpointer user_data)
{
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

    // Crea una nuova GtkApplication con un ID applicazione unico
    app = gtk_application_new("org.example.gtk4", G_APPLICATION_DEFAULT_FLAGS);

    // Connette il segnale "activate" dell'applicazione alla funzione on_activate.
    // Questa funzione verrà chiamata quando l'applicazione viene attivata (es. avviata).
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    // Esegue l'applicazione. Questo avvia il loop principale di GTK e attende eventi.
    status = g_application_run(G_APPLICATION(app), argc, argv);

    // Libera l'oggetto GtkApplication quando l'applicazione termina
    g_object_unref(app);
    return status;
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
