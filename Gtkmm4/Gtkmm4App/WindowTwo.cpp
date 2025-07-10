#include "WindowTwo.hpp"
#include <iostream>
#include <glibmm/main.h>
#include <exception>

/*
 * ManualApp::ManualApp()
 * Costruttore: inizializza i puntatori a nullptr.
 */
WindowTwo::WindowTwo()
    : Gtk::Window(), m_pBox(nullptr), m_pLabel(nullptr),
      m_pDialogButton(nullptr), m_pExitButton(nullptr)
{
    set_title("GTKMM4 Manual Example");
    set_default_size(300, 250);

    // Crea un contenitore verticale con margini e spacing
    m_pBox = new Gtk::Box(Gtk::Orientation::VERTICAL, 15);
    m_pBox->set_margin_top(15);
    m_pBox->set_margin_bottom(15);
    m_pBox->set_margin_start(15);
    m_pBox->set_margin_end(15);
    m_pBox->set_halign(Gtk::Align::CENTER);
    m_pBox->set_valign(Gtk::Align::CENTER);
    set_child(*m_pBox);

    // Crea e aggiunge la label
    m_pLabel = new Gtk::Label("Initial text");
    m_pBox->append(*m_pLabel);

    // Crea il pulsante "Show Dialog" e lo aggiunge al contenitore
    m_pDialogButton = new Gtk::Button("Show Dialog");
    m_pBox->append(*m_pDialogButton);

    // Crea il pulsante "Exit" e lo aggiunge al contenitore.
    m_pExitButton = new Gtk::Button("Exit");
    m_pBox->append(*m_pExitButton);

    // Connette il segnale "clicked" al metodo on_dialog_button_clicked.
    m_pDialogButton->signal_clicked().connect(
        sigc::mem_fun(*this, &WindowTwo::on_dialog_button_clicked));

    // Connette il segnale "clicked" del pulsante "Exit".
    m_pExitButton->signal_clicked().connect(
        sigc::mem_fun(*this, &WindowTwo::on_exit_button_clicked));
}

WindowTwo::~WindowTwo()
{
    // I figli sono gestiti dal container (set_child e append).
}

void WindowTwo::on_dialog_button_clicked()
{
    // Crea un dialogo associato alla finestra principale.
    Gtk::MessageDialog *pDialog = new Gtk::MessageDialog(*this,
                                                         "Do you want to continue?",
                                                         false,                      // Nessun testo secondario
                                                         Gtk::MessageType::QUESTION, // Tipo di messaggio: domanda
                                                         Gtk::ButtonsType::NONE);    // Nessun pulsante predefinito
    // Rende il dialogo modale e lo lega alla finestra corrente
    pDialog->set_modal(true);
    pDialog->set_transient_for(*this);

    // Aggiunge i pulsanti con i rispettivi codici di risposta.
    pDialog->add_button("Yes", Gtk::ResponseType::YES);
    pDialog->add_button("No", Gtk::ResponseType::NO);
    pDialog->add_button("Cancel", Gtk::ResponseType::CANCEL);

    pDialog->set_secondary_text(
        "And this is the secondary text that explains things.");

    // Connette il segnale "response" del dialogo al metodo on_dialog_response().
    // Utilizza sigc::bind per passare il puntatore a pDialog come parametro addizionale.
    pDialog->signal_response().connect(
        sigc::bind(sigc::mem_fun(*this, &WindowTwo::on_dialog_response), pDialog));

    // Mostra il dialogo in maniera asincrona.
    pDialog->show();
}

void WindowTwo::on_dialog_response(int response, Gtk::MessageDialog *pDialog)
{
    switch (response)
    {
    case Gtk::ResponseType::YES:
        m_pLabel->set_text("You chose: Yes");
        break;
    case Gtk::ResponseType::NO:
        m_pLabel->set_text("You chose: No");
        break;
    case Gtk::ResponseType::CANCEL:
        m_pLabel->set_text("You chose: Cancel");
        break;
    case Gtk::ResponseType::DELETE_EVENT:
        m_pLabel->set_text("Dialog closed");
        break;
    default:
        m_pLabel->set_text("Unknown response");
        break;
    }

    // Nasconde il dialogo (non lo chiude forzatamente).
    pDialog->hide();

    // Dealloca il dialogo in modo sicuro utilizzando Glib::signal_idle().
    // Questo assicura che il dialogo sia rimosso dopo che GTK ha completato il ciclo eventi.
    Glib::signal_idle().connect_once(
        [pDialog]()
        { delete pDialog; });
}

void WindowTwo::on_exit_button_clicked()
{
    close();
}
