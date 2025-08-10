#ifndef BUILDERWINDOW_H
#define BUILDERWINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/builder.h>

/*
 * BuilderWindow
 *
 * Questa classe implementa una finestra costruita tramite Gtk::Builder.
 * Il file XML (interface.ui) deve definire almeno:
 *    - Un contenitore (con id "builder_container") da usare come contenuto della finestra
 *    - Una label (con id "builder_label")
 *    - Un pulsante "Show Dialog" (con id "builder_dialog_button")
 *    - Un pulsante "Exit" (con id "builder_exit_button")
 *
 * I segnali sono connessi a metodi membro senza l'uso di lambda; il dialogo viene deallocato in sicurezza.
 */
class BuilderWindow : public Gtk::Window
{
public:
    BuilderWindow();
    virtual ~BuilderWindow();

protected:
    // Callback per il pulsante "Show MessageDialog".
    void on_message_dialog_button_clicked();
    // Callback per il segnale "response" di MessageDialog
    void on_message_dialog_response(int res, Gtk::MessageDialog *pDialog);
    // Callback per il pulsante "Exit".
    void on_exit_button_clicked();

    // Membri per memorizzare i widget principali ottenuti dal file UI.
    Glib::RefPtr<Gtk::Label> pLabel;
    Glib::RefPtr<Gtk::Button> pMessageDialogButton;
    Glib::RefPtr<Gtk::Button> pExitButton;
};

#endif // BUILDERWINDOW_H
