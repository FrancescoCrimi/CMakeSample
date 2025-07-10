#include <gtkmm/application.h>
#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create("com.example.gtkmm4.combined");
    // MainWindow main_window;
    // return app->run(main_window);
    return app->make_window_and_run<MainWindow>(argc, argv);
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
