#ifndef WINDOW_H
#define WINDOW_H

#include <gtk/gtk.h>

/**
 * Crea e inizializza la finestra principale dell'applicazione.
 *
 * @param app GtkApplication a cui appartiene la finestra.
 * @return GtkWindow* che rappresenta la finestra principale.
 */
GtkWindow *create_main_window(GtkApplication *app);

#endif /* WINDOW_H */