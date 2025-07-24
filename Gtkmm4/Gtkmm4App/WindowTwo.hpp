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
 */
class WindowTwo : public Gtk::Window
{
public:
    WindowTwo();
    virtual ~WindowTwo();

private:
    // Callback per il pulsante "Show MessageDialog".
    void on_message_dialog_button_clicked();
    // Callback per il pulsante "Show AlertDialog".
    void on_alert_dialog_button_clicked();
    // Callback per il segnale "response" di MessageDialog
    void on_message_dialog_response(int response);
    // Callback per AlertDialog
    void on_alert_dialog_choose(const Glib::RefPtr<Gio::AsyncResult> &result, Glib::RefPtr<Gtk::AlertDialog> m_pDialog);

    Gtk::Label m_Label;

    Gtk::MessageDialog *m_pMessageDialog = nullptr;
    // std::unique_ptr<Gtk::MessageDialog> m_pMessageDialog;

    // Glib::RefPtr<Gtk::AlertDialog> m_pAlertDialog;
};

#endif // WINDOWTWO_H
