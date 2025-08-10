#ifndef MANUAL_WINDOW_H
#define MANUAL_WINDOW_H

#include <gtk/gtk.h>

/**
 * Crea l'interfaccia grafica interamente in codice:
 *   - Crea una finestra
 *   - Aggiunge un contenitore GtkBox verticale
 *   - Crea e posiziona una label e due pulsanti
 *   - Collega i relativi segnali
 */
GtkWindow *create_manual_window(GtkWindow *parent_window);

#endif /* MANUAL_WINDOW_H */
