#ifndef SECOND_WINDOW_H
#define SECOND_WINDOW_H

#include <gtk/gtk.h>

/**
 * Crea l'interfaccia grafica interamente in codice:
 *   - Crea una finestra
 *   - Aggiunge un contenitore GtkBox verticale
 *   - Crea e posiziona una label e due pulsanti
 *   - Collega i relativi segnali
 */
GtkWindow *create_second_window(GtkWindow *parent_window);

#endif /* SECOND_WINDOW_H */
