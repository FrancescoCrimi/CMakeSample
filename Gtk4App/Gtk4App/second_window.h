#ifndef SECOND_WINDOW_H
#define SECOND_WINDOW_H

#include <gtk/gtk.h> // Necessario per GtkWindow

/**
 * @brief Crea e configura la seconda finestra secondaria.
 * @param parent_window Il puntatore alla finestra genitore (per transient, non obbligatorio per finestre indipendenti).
 * @return Un puntatore al nuovo GtkWindow creato.
 */
GtkWindow *create_second_window(GtkWindow *parent_window);

#endif // SECOND_WINDOW_H
