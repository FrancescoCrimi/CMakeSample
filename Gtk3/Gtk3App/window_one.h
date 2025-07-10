#ifndef WINDOW_ONE_H
#define WINDOW_ONE_H

#include <gtk/gtk.h>

/**
 * Carica l'interfaccia da "interface.ui" (il file XML) usando GtkBuilder.
 * Associa i widget (finestra, label, pulsanti) e connette i relativi segnali.
 */
GtkWindow *create_window_one(GtkWindow *parent_window);

#endif /* WINDOW_ONE_H */
