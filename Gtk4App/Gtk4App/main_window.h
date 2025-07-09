#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtk/gtk.h> // Necessario per GtkApplication e GtkWindow

/**
 * @brief Crea e configura la finestra principale dell'applicazione.
 * @param app Il puntatore all'oggetto GtkApplication.
 * @return Un puntatore al GtkWindow creato.
 */
GtkWindow *create_main_window(GtkApplication *app);

#endif // MAIN_WINDOW_H
