#ifndef WINDOW_H
#define WINDOW_H

#include <gtk/gtk.h>

/**
 * Carica l'interfaccia da "interface.ui" (il file XML) usando GtkBuilder.
 * Associa i widget (finestra, label, pulsanti) e connette i relativi segnali.
 */
GtkWindow *get_window(GtkApplication *app);

#endif /* WINDOW_H */
