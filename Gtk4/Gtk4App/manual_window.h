#ifndef MANUAL_WINDOW_H
#define MANUAL_WINDOW_H

#include <gtk/gtk.h> // Necessario per GtkWindow

/**
 * @brief Crea e configura la seconda finestra secondaria.
 * @param parent_window Il puntatore alla finestra genitore (per transient, non obbligatorio per finestre indipendenti).
 * @return Un puntatore al nuovo GtkWindow creato.
 */
GtkWindow *create_manual_window(GtkWindow *parent_window);

#endif // MANUAL_WINDOW_H
