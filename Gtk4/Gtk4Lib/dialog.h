#ifndef DIALOG_H
#define DIALOG_H

#include <gtk/gtk.h>


// Su Windows utilizziamo __declspec(dllexport)/__declspec(dllimport)
#ifdef _WIN32
    #ifdef MYLIBRARY_EXPORTS
        // Durante la compilazione della DLL
        #define MYLIB_API __declspec(dllexport)
    #else
        // Quando la DLL viene utilizzata
        #define MYLIB_API __declspec(dllimport)
    #endif
#else
    // Su altre piattaforme non sono necessarie direttive particolari
    #define MYLIB_API
#endif

/**
 * Struttura per passare referenze utili ai callback.
 * Contiene la finestra principale e la label, necessarie per aggiornare il testo.
 */
typedef struct
{
    GtkWindow *window;
    GtkLabel *label;
} MyContextObject;

/**
 * @brief Mostra un MessageDialog
 *
 * Mostra un MessageDialog  con:
 *     - Un messaggio primario (in markup per evidenziare il testo)
 *     - Un messaggio secondario
 *     - Tre bottoni: OK, No, Cancel
 * 
 * @param widgets struttura contenente la finestra e la label
 */
MYLIB_API void show_message_dialog(MyContextObject *widgets);

/**
 * @brief Mostra un moderno AlertDialog
 *
 * Mostra un nuovo AlertDialog con:
 *     - Un messaggio primario (in markup per evidenziare il testo)
 *     - Un messaggio secondario
 *     - Tre bottoni: OK, No, Cancel
 *
 * @param widgets struttura contenente la finestra e la label
 */
MYLIB_API void show_alert_dialog(MyContextObject *widgets);

#endif /* DIALOG_H */
