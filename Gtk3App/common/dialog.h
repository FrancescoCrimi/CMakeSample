#ifndef DIALOG_H
#define DIALOG_H

#include <gtk/gtk.h>

/**
 * Struttura per passare insieme i riferimenti principali della GUI
 * (la finestra principale e la label) ai callback.
 */
typedef struct
{
    GtkWindow *window;
    GtkLabel *label;
} AppWidgets;

/**
 * Crea e mostra un dialogo modale con le opzioni Yes/No/Cancel.
 */
void show_dialog(AppWidgets *appWidgets);

#endif /* DIALOG_H */