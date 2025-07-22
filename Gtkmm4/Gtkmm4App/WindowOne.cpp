#include "WindowOne.hpp"
#include <gtkmm/builder.h>
#include <iostream>
#include <filesystem>
#include <glibmm/main.h>
#include <exception>

WindowOne::WindowOne()
    : Gtk::Window(), pLabel(), pMessageDialogButton(), pExitButton()
{
    set_title("Builder Window");
    set_default_size(300, 250);

    // Verifica l'esistenza del file di interfaccia
    if (!std::filesystem::exists("interface.ui"))
    {
        std::cerr << "Error: file 'interface.ui' not found." << std::endl;
        return;
    }

    try
    {
        // Crea il builder e carica il file "interface.ui".
        auto refBuilder = Gtk::Builder::create_from_file("interface.ui");

        // Recupera il contenitore (ad es. una GtkBox) definito nel file con id "builder_container"
        auto pContainer = refBuilder->get_object<Gtk::Widget>("builder_container");
        if (pContainer)
            set_child(*pContainer);
        else
            std::cerr << "Error: 'builder_container' not found in UI." << std::endl;

        // Recupera la label principale, il pulsante "Show Dialog" e "Exit".
        pLabel = refBuilder->get_object<Gtk::Label>("main_label");
        pMessageDialogButton = refBuilder->get_object<Gtk::Button>("dialog_button");
        pExitButton = refBuilder->get_object<Gtk::Button>("exit_button");

        // Verifica che i widget indispensabili siano stati trovati.
        if (!pLabel || !pMessageDialogButton || !pExitButton)
        {
            std::cerr << "Error: one or more required widgets (main_label, dialog_button, exit_button) "
                         "are missing in the UI file."
                      << std::endl;
            return;
        }

        // Collega il segnale "clicked" del pulsante "Show Dialog" al callback on_dialog_button_clicked.
        pMessageDialogButton->signal_clicked().connect(
            sigc::mem_fun(*this, &WindowOne::on_message_dialog_button_clicked));

        // Collega il segnale "clicked" del pulsante "Exit" al callback on_exit_button_clicked.
        pExitButton->signal_clicked().connect(
            sigc::mem_fun(*this, &WindowOne::on_exit_button_clicked));
    }
    catch (const Gtk::BuilderError &ex)
    {
        std::cerr << "Gtk::BuilderError: " << ex.what() << std::endl;
        return;
    }
    catch (const Glib::Error &ex)
    {
        std::cerr << "Glib::Error: " << ex.what() << std::endl;
        return;
    }
}

WindowOne::~WindowOne()
{
    // I Glib::RefPtr interni gestiscono l'ownership dei widget caricati.
}

void WindowOne::on_message_dialog_button_clicked()
{
    // Crea sul heap un nuovo Gtk::MessageDialog associato alla finestra principale.
    Gtk::MessageDialog *pDialog = new Gtk::MessageDialog(*this,
                                                         "Do you want to continue?",
                                                         false,                      // Nessun testo secondario
                                                         Gtk::MessageType::QUESTION, // Tipo di messaggio: domanda
                                                         Gtk::ButtonsType::NONE);    // Nessun pulsante predefinito
    // Imposta il dialog come modale
    pDialog->set_modal(true);
    // Associa il dialog alla finestra principale
    pDialog->set_transient_for(*this);

    // Aggiunge pulsanti personalizzati al dialogo specificando il valore di risposta.
    pDialog->add_button("Yes", Gtk::ResponseType::YES);
    pDialog->add_button("No", Gtk::ResponseType::NO);
    pDialog->add_button("Cancel", Gtk::ResponseType::CANCEL);

    pDialog->set_secondary_text(
        "And this is the secondary text that explains things.");

    pDialog->signal_response().connect(
        sigc::bind(sigc::mem_fun(*this, &WindowOne::on_message_dialog_response), pDialog));
    pDialog->show();
}

/*
 * BuilderApp::on_dialog_response()
 * Gestisce la risposta del dialogo aggiornando la label e deallocando il dialogo in sicurezza.
 */
void WindowOne::on_message_dialog_response(int response, Gtk::MessageDialog *pDialog)
{
    switch (response)
    {
    case Gtk::ResponseType::YES:
        pLabel->set_text("You chose: Yes");
        break;
    case Gtk::ResponseType::NO:
        pLabel->set_text("You chose: No");
        break;
    case Gtk::ResponseType::CANCEL:
        pLabel->set_text("You chose: Cancel");
        break;
    case Gtk::ResponseType::DELETE_EVENT:
        pLabel->set_text("Dialog closed");
        break;
    default:
        pLabel->set_text("Unknown response");
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

/*
 * BuilderApp::on_exit_button_clicked()
 * Chiude la finestra principale.
 */
void WindowOne::on_exit_button_clicked()
{
    close();
}
