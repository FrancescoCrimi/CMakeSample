#include "ManualWindow.hpp"
#include <iostream>
#include <exception>
#include <glibmm/main.h>
#include <gtkmm/alertdialog.h>
#include <gtkmm/error.h>

ManualWindow::ManualWindow() : m_Label("Initial text")
{
    set_title("Manual Window");
    set_default_size(300, 250);

    Gtk::Box box(Gtk::Orientation::VERTICAL, 15);
    box.set_margin_top(15);
    box.set_margin_bottom(15);
    box.set_margin_start(15);
    box.set_margin_end(15);
    box.set_halign(Gtk::Align::CENTER);
    box.set_valign(Gtk::Align::CENTER);
    set_child(box);

    box.append(m_Label);

    Gtk::Button messageDialogButton("Show MessageDialog");
    messageDialogButton.signal_clicked().connect(
        sigc::mem_fun(*this, &ManualWindow::on_message_dialog_button_clicked));
    box.append(messageDialogButton);

    Gtk::Button alertDialogButton("Show AlertDialog");
    alertDialogButton.signal_clicked().connect(
        sigc::mem_fun(*this, &ManualWindow::on_alert_dialog_button_clicked));
    box.append(alertDialogButton);

    Gtk::Button exitButton("Exit");
    exitButton.signal_clicked().connect(
        sigc::mem_fun(*this, &ManualWindow::close));
    box.append(exitButton);
}

ManualWindow::~ManualWindow()
{
    // I figli sono gestiti dal container (set_child e append).
}

void ManualWindow::on_message_dialog_button_clicked()
{
    // Crea un dialogo associato alla finestra principale.
    m_pMessageDialog = Gtk::make_managed<Gtk::MessageDialog>(*this,
                                                             "This is an MessageDialog.",
                                                             false,                      // Nessun testo secondario
                                                             Gtk::MessageType::QUESTION, // Tipo di messaggio: domanda
                                                             Gtk::ButtonsType::NONE,     // Nessun pulsante predefinito
                                                             true);                      // modal

    // m_pMessageDialog = std::make_unique<Gtk::MessageDialog>(*this,
    //                                                         "This is a QUESTION MessageDialog",
    //                                                         false,                          // use_markup
    //                                                         Gtk::MessageType::QUESTION,
    //                                                         Gtk::ButtonsType::OK_CANCEL,
    //                                                         true);                          // modal

    // Aggiunge i pulsanti con i rispettivi codici di risposta.
    m_pMessageDialog->add_button("Yes", Gtk::ResponseType::YES);
    m_pMessageDialog->add_button("No", Gtk::ResponseType::NO);
    m_pMessageDialog->add_button("Cancel", Gtk::ResponseType::CANCEL);
    m_pMessageDialog->set_secondary_text(
        "And this is the secondary text that explains things.");
    m_pMessageDialog->signal_response().connect(
        sigc::mem_fun(*this, &ManualWindow::on_message_dialog_response));

    // Mostra il dialogo in maniera asincrona.
    m_pMessageDialog->show();
}

void ManualWindow::on_alert_dialog_button_clicked()
{
    Glib::RefPtr<Gtk::AlertDialog> alertDialog = Gtk::AlertDialog::create();
    alertDialog->set_message("This is an AlertDialog.");
    alertDialog->set_detail("And this is the secondary text that explains things.");
    alertDialog->set_buttons({"Cancel", "Retry", "OK"});
    alertDialog->set_default_button(2); // OK button or Return key
    alertDialog->set_cancel_button(0);  // Cancel button or Escape key
    alertDialog->choose(*this,
                        sigc::bind(sigc::mem_fun(*this, &ManualWindow::on_alert_dialog_choose), alertDialog));
}

void ManualWindow::on_message_dialog_response(int response)
{
    switch (response)
    {
    case Gtk::ResponseType::YES:
        m_Label.set_text("You chose: Yes");
        break;
    case Gtk::ResponseType::NO:
        m_Label.set_text("You chose: No");
        break;
    case Gtk::ResponseType::CANCEL:
        m_Label.set_text("You chose: Cancel");
        break;
    case Gtk::ResponseType::DELETE_EVENT:
        m_Label.set_text("Dialog closed");
        break;
    default:
        m_Label.set_text("Unknown response");
        break;
    }

    // Nasconde o distrugge il dialogo
    m_pMessageDialog->hide();
    m_pMessageDialog = nullptr;
}

void ManualWindow::on_alert_dialog_choose(const Glib::RefPtr<Gio::AsyncResult> &result, Glib::RefPtr<Gtk::AlertDialog> alertDialog)
{
    try
    {
        const int response_id = alertDialog->choose_finish(result);
        switch (response_id)
        {
        case 0:
            m_Label.set_text("You chose: Cancel");
            break;
        case 1:
            m_Label.set_text("You chose: Retry");
            break;
        case 2:
            m_Label.set_text("You chose: OK");
            break;
        default:
            m_Label.set_text("You chose: Unknown");
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
