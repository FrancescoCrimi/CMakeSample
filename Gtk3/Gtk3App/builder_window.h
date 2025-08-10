#ifndef BUILDER_WINDOW_H
#define BUILDER_WINDOW_H

#include <gtk/gtk.h>

/**
 * Carica l'interfaccia da "interface.ui" (il file XML) usando GtkBuilder.
 * Associa i widget (finestra, label, pulsanti) e connette i relativi segnali.
 */
GtkWindow *create_builder_window(GtkWindow *parent_window);

#endif /* BUILDER_WINDOW_H */
