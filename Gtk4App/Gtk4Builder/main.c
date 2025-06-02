#include "window.h"

/**
 * Callback per l'attivazione dell'applicazione.
 */
static void on_app_activate(GtkApplication *app, gpointer user_data)
{
    GtkWindow *window = create_main_window(app);
    gtk_window_present(window);
}

int main(int argc, char *argv[])
{
    GtkApplication *app = gtk_application_new("com.example.gtk4", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_app_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
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
