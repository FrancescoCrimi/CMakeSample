#ifndef MAINHUBWINDOW_H
#define MAINHUBWINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>

/*
 * MainHubWindow
 *
 * Questa finestra principale presenta due pulsanti:
 *  - "Open Manual Window": apre la ManualWindow (interfaccia creata in codice).
 *  - "Open Builder Window": apre la BuilderWindow (interfaccia caricata da XML).
 */
class MainHubWindow : public Gtk::Window
{
public:
    MainHubWindow();
    virtual ~MainHubWindow();

protected:
    // Callback per i due pulsanti
    void on_manual_button_clicked();
    void on_builder_button_clicked();

    // Widget
    Gtk::Box *m_pBox;
    Gtk::Button *m_pManualButton;
    Gtk::Button *m_pBuilderButton;
};

#endif // MAINHUBWINDOW_H
