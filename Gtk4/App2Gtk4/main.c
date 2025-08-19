/**
 * Tipo di applicazione: GTK4 minimale con GMainLoop
 *
 * Descrizione:
 *  - Inizializza manualmente GTK con gtk_init().
 *  - Crea e avvia un GMainLoop per il ciclo principale.
 *  - Alla chiusura della finestra, chiama g_main_loop_quit() per uscire.
 */

#include <gtk/gtk.h>

static gboolean on_close_request(GtkWindow *win, GMainLoop *loop)
{
    // Segnale gestito: quando si chiede la chiusura,
    // termina il GMainLoop e lascia che GTK distrugga la finestra.    
    g_main_loop_quit(loop);
    return FALSE; // FALSE consente la distruzione della finestra
}

int main(int argc, char **argv)
{
    // Inizializzazione di GTK
    gtk_init();

    // Creazione del main loop
    GMainLoop *loop = g_main_loop_new(NULL, FALSE);

    // Creazione della finestra principale
    GtkWindow *window = GTK_WINDOW(gtk_window_new());
    gtk_window_set_title(window, "GTK4 without GtkApplication");
    gtk_window_set_default_size(window, 400, 300);

    // Collegamento del segnale di chiusura al nostro callback
    g_signal_connect(window, "close-request",
                     G_CALLBACK(on_close_request), loop);

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
