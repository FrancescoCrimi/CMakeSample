#ifndef WINDOW_H
#define WINDOW_H

#include <gtk/gtk.h>

/**
 * Crea l'interfaccia grafica interamente in codice:
 *   - Crea una finestra
 *   - Aggiunge un contenitore GtkBox verticale
 *   - Crea e posiziona una label e due pulsanti
 *   - Collega i relativi segnali
 */
GtkWindow *get_window(GtkApplication *app);

#endif /* WINDOW_H */
