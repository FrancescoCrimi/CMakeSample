#ifndef WINDOWTWO_H
#define WINDOWTWO_H

#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/alertdialog.h>

/*
 * WindowTwo
 *
 * Questa finestra viene realizzata interamente in codice.
 * Mostra una label e tre pulsanti: "Show MessageDialog", "Show AlertDialog" e "Exit".
 *
 * "Show MessageDialog" crea un MessageDialog (modale) la cui risposta aggiorna la label;
 * la deallocazione del dialog avviene in modo sicuro tramite Glib::signal_idle().
 */
class WindowTwo : public Gtk::Window
{
public:
    WindowTwo();
    virtual ~WindowTwo();

protected:
    // Callback per il pulsante "Show MessageDialog".
    void on_message_dialog_button_clicked();
    // Callback per il pulsante "Show AlertDialog".
    void on_alert_dialog_button_clicked();
    // Callback per il segnale "response" di MessageDialog
    void on_message_dialog_response(int response, Gtk::MessageDialog *pDialog);
    // Callback per AlertDialog
    void on_alert_dialog_choose(const Glib::RefPtr<Gio::AsyncResult> &result, Glib::RefPtr<Gtk::AlertDialog> m_pDialog);
    // Callback per il pulsante "Exit"
    void on_exit_button_clicked();

    // Widget principali
    Gtk::Box *m_pBox;
    Gtk::Label *m_pLabel;
    Gtk::Button *m_pMessageDialogButton;
    Gtk::Button *m_pAlertDialogButton;
    Gtk::Button *m_pExitButton;
};

#endif // WINDOWTWO_H
