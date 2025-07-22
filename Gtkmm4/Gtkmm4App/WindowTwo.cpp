#include "WindowTwo.hpp"
#include <iostream>
#include <exception>
#include <glibmm/main.h>
#include <gtkmm/alertdialog.h>
#include <gtkmm/error.h>

/*
 * ManualApp::ManualApp()
 * Costruttore: inizializza i puntatori a nullptr.
 */
WindowTwo::WindowTwo()
    : Gtk::Window(), m_pBox(nullptr), m_pLabel(nullptr),
      m_pMessageDialogButton(nullptr), m_pAlertDialogButton(nullptr), m_pExitButton(nullptr)
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

    // Crea il pulsante "Show MessageDialog" e lo aggiunge al contenitore
    m_pMessageDialogButton = new Gtk::Button("Show MessageDialog");
    m_pBox->append(*m_pMessageDialogButton);

    // Crea il pulsante "Show AlertDialog" e lo aggiunge al contenitore
    m_pAlertDialogButton = new Gtk::Button("Show AlertDialog");
    m_pBox->append(*m_pAlertDialogButton);

    // Crea il pulsante "Exit" e lo aggiunge al contenitore.
    m_pExitButton = new Gtk::Button("Exit");
    m_pBox->append(*m_pExitButton);

    // Connette il segnale "clicked" al metodo on_message_dialog_button_clicked.
    m_pMessageDialogButton->signal_clicked().connect(
        sigc::mem_fun(*this, &WindowTwo::on_message_dialog_button_clicked));

    // Connete il segnale "clicked" al metodo on_alert_dialog_button_clicked.
    m_pAlertDialogButton->signal_clicked().connect(
        sigc::mem_fun(*this, &WindowTwo::on_alert_dialog_button_clicked));

    // Connette il segnale "clicked" del pulsante "Exit".
    m_pExitButton->signal_clicked().connect(
        sigc::mem_fun(*this, &WindowTwo::on_exit_button_clicked));
}

WindowTwo::~WindowTwo()
{
    // I figli sono gestiti dal container (set_child e append).
}

void WindowTwo::on_message_dialog_button_clicked()
{
    // Crea un dialogo associato alla finestra principale.
    Gtk::MessageDialog *messageDialog = new Gtk::MessageDialog(*this,
                                                               "This is an MessageDialog.",
                                                               false,                      // Nessun testo secondario
                                                               Gtk::MessageType::QUESTION, // Tipo di messaggio: domanda
                                                               Gtk::ButtonsType::NONE);    // Nessun pulsante predefinito
    // Rende il dialogo modale e lo lega alla finestra corrente
    messageDialog->set_modal(true);
    messageDialog->set_transient_for(*this);

    // Aggiunge i pulsanti con i rispettivi codici di risposta.
    messageDialog->add_button("Yes", Gtk::ResponseType::YES);
    messageDialog->add_button("No", Gtk::ResponseType::NO);
    messageDialog->add_button("Cancel", Gtk::ResponseType::CANCEL);

    messageDialog->set_secondary_text(
        "And this is the secondary text that explains things.");

    // Connette il segnale "response" del dialogo al metodo on_message_dialog_response().
    // Utilizza sigc::bind per passare il puntatore a messageDialog come parametro addizionale.
    messageDialog->signal_response().connect(
        sigc::bind(sigc::mem_fun(*this, &WindowTwo::on_message_dialog_response), messageDialog));

    // Mostra il dialogo in maniera asincrona.
    messageDialog->show();
}

void WindowTwo::on_alert_dialog_button_clicked()
{
    Glib::RefPtr<Gtk::AlertDialog> alertDialog = Gtk::AlertDialog::create();
    alertDialog->set_message("This is an AlertDialog.");
    alertDialog->set_detail("And this is the secondary text that explains things.");
    alertDialog->set_buttons({"Cancel", "Retry", "OK"});
    alertDialog->set_default_button(2); // OK button or Return key
    alertDialog->set_cancel_button(0);  // Cancel button or Escape key
    alertDialog->choose(*this,
                        sigc::bind(sigc::mem_fun(*this, &WindowTwo::on_alert_dialog_choose), alertDialog));
}

void WindowTwo::on_message_dialog_response(int response, Gtk::MessageDialog *messageDialog)
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
    messageDialog->hide();

    // Dealloca il dialogo in modo sicuro utilizzando Glib::signal_idle().
    // Questo assicura che il dialogo sia rimosso dopo che GTK ha completato il ciclo eventi.
    Glib::signal_idle().connect_once(
        [messageDialog]()
        { delete messageDialog; });
}

void WindowTwo::on_alert_dialog_choose(const Glib::RefPtr<Gio::AsyncResult> &result, Glib::RefPtr<Gtk::AlertDialog> alertDialog)
{
    try
    {
        const int response_id = alertDialog->choose_finish(result);
        switch (response_id)
        {
        case 0:
            m_pLabel->set_text("You chose: Cancel");
            break;
        case 1:
            m_pLabel->set_text("You chose: Retry");
            break;
        case 2:
            m_pLabel->set_text("You chose: OK");
            break;
        default:
            m_pLabel->set_text("You chose: Unknown");
            break;
        }
    }
    catch (const Gtk::DialogError &err)
    {
        // Can be thrown by alertDialog->choose_finish(result).
        std::cout << "DialogError, " << err.what() << std::endl;
    }
    catch (const Glib::Error &err)
    {
        std::cout << "Unexpected exception. " << err.what() << std::endl;
    }
}

void WindowTwo::on_exit_button_clicked()
{
    close();
}
