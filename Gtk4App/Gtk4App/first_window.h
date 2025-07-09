#ifndef FIRST_WINDOW_H
#define FIRST_WINDOW_H

#include <gtk/gtk.h> // Necessario per GtkWindow

/**
 * @brief Crea e configura la prima finestra secondaria.
 * @param parent_window Il puntatore alla finestra genitore (per transient, non obbligatorio per finestre indipendenti).
 * @return Un puntatore al nuovo GtkWindow creato.
 */
GtkWindow *create_first_window(GtkWindow *parent_window);

#endif // FIRST_WINDOW_H