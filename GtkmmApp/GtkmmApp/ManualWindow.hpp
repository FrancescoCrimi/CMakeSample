#ifndef MANUALWINDOW_H
#define MANUALWINDOW_H

#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/messagedialog.h>

/*
 * ManualWindow
 *
 * Questa finestra viene realizzata interamente in codice.
 * Mostra una label e due pulsanti: "Show Dialog" e "Exit".
 *
 * "Show Dialog" crea un MessageDialog (modale) la cui risposta aggiorna la label;
 * la deallocazione del dialog avviene in modo sicuro tramite Glib::signal_idle().
 */
class ManualWindow : public Gtk::Window
{
public:
    ManualWindow();
    virtual ~ManualWindow();

protected:
    // Callback per il pulsante "Show Dialog".
    void on_dialog_button_clicked();
    // Callback per il segnale "response" del dialogo
    void on_dialog_response(int response, Gtk::MessageDialog *pDialog);
    // Callback per il pulsante "Exit"
    void on_exit_button_clicked();

    // Widget principali
    Gtk::Box *m_pBox;
    Gtk::Label *m_pLabel;
    Gtk::Button *m_pDialogButton;
    Gtk::Button *m_pExitButton;
};

#endif // MANUALWINDOW_H
