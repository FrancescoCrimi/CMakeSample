#ifndef WINDOW_TWO_H
#define WINDOW_TWO_H

#include <gtk/gtk.h> // Necessario per GtkWindow

/**
 * @brief Crea e configura la seconda finestra secondaria.
 * @param parent_window Il puntatore alla finestra genitore (per transient, non obbligatorio per finestre indipendenti).
 * @return Un puntatore al nuovo GtkWindow creato.
 */
GtkWindow *create_window_two(GtkWindow *parent_window);

#endif // WINDOW_TWO_H
