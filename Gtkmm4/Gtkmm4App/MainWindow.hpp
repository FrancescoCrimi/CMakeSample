#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>

/*
 * MainWindow
 *
 * Questa finestra principale presenta due pulsanti:
 *  - "Open Manual Window": apre la ManualWindow (interfaccia creata in codice).
 *  - "Open Builder Window": apre la BuilderWindow (interfaccia caricata da XML).
 */
class MainWindow : public Gtk::Window
{
public:
    MainWindow();
    virtual ~MainWindow();

protected:
    // Callback per i due pulsanti
    void on_manual_button_clicked();
    void on_builder_button_clicked();
    void on_exit_button_clicked();

    // Widget
    Gtk::Box *m_pBox;
    Gtk::Label *m_pWelcomeLabel;
    Gtk::Button *m_pManualButton;
    Gtk::Button *m_pBuilderButton;
    Gtk::Button *m_pExitButton;
};

#endif // MAINWINDOW_H
