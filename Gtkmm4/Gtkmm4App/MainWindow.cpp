#include "MainWindow.hpp"
#include "WindowTwo.hpp"
#include "WindowOne.hpp"
#include <sigc++/sigc++.h>
#include <iostream>

MainWindow::MainWindow()
    : Gtk::Window(), m_pBox(nullptr), m_pWelcomeLabel(nullptr), m_pManualButton(nullptr), m_pBuilderButton(nullptr), m_pExitButton(nullptr)
{
    set_title("App Gtkmm4");
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

    // Crea Label
    m_pWelcomeLabel = new Gtk::Label("Finestra Principale");
    m_pBox->append(*m_pWelcomeLabel);

    // Crea i pulsanti
    m_pManualButton = new Gtk::Button("Open Manual Window");
    m_pBuilderButton = new Gtk::Button("Open Builder Window");
    m_pExitButton = new Gtk::Button("Exit");

    m_pBox->append(*m_pManualButton);
    m_pBox->append(*m_pBuilderButton);
    m_pBox->append(*m_pExitButton);

    // Connette i segnali ai metodi membro
    m_pManualButton->signal_clicked().connect(
        sigc::mem_fun(*this, &MainWindow::on_manual_button_clicked));
    m_pBuilderButton->signal_clicked().connect(
        sigc::mem_fun(*this, &MainWindow::on_builder_button_clicked));
    m_pExitButton->signal_clicked().connect(
        sigc::mem_fun(*this, &MainWindow::on_exit_button_clicked));
}

MainWindow::~MainWindow()
{
    // I widget figli vengono deallocati automaticamente dal contenitore.
}

void MainWindow::on_manual_button_clicked()
{
    // Crea e mostra una nuova WindowTwo (non modale)
    WindowTwo *pManual = new WindowTwo();
    pManual->set_transient_for(*this);
    pManual->show();
}

void MainWindow::on_builder_button_clicked()
{
    // Crea e mostra una nuova WindowOne (non modale)
    WindowOne *pBuilder = new WindowOne();
    pBuilder->set_transient_for(*this);
    pBuilder->show();
}

void MainWindow::on_exit_button_clicked()
{
    close();
}
