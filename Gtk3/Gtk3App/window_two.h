#ifndef WINDOW_TWO_H
#define WINDOW_TWO_H

#include <gtk/gtk.h>

/**
 * Crea l'interfaccia grafica interamente in codice:
 *   - Crea una finestra
 *   - Aggiunge un contenitore GtkBox verticale
 *   - Crea e posiziona una label e due pulsanti
 *   - Collega i relativi segnali
 */
GtkWindow *create_window_two(GtkWindow *parent_window);

#endif /* WINDOW_TWO_H */
