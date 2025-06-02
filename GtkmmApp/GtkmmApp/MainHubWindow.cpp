#include "MainHubWindow.hpp"
#include "ManualWindow.hpp"
#include "BuilderWindow.hpp"
#include <sigc++/sigc++.h>
#include <iostream>

MainHubWindow::MainHubWindow()
    : Gtk::Window(), m_pBox(nullptr), m_pManualButton(nullptr), m_pBuilderButton(nullptr)
{
    set_title("Main Hub Window");
    set_default_size(300, 200);

    // Crea un contenitore verticale con margini e spacing
    m_pBox = new Gtk::Box(Gtk::Orientation::VERTICAL, 10);
    m_pBox->set_margin_top(20);
    m_pBox->set_margin_bottom(20);
    m_pBox->set_margin_start(20);
    m_pBox->set_margin_end(20);
    set_child(*m_pBox);

    // Crea i pulsanti
    m_pManualButton = new Gtk::Button("Open Manual Window");
    m_pBuilderButton = new Gtk::Button("Open Builder Window");

    m_pBox->append(*m_pManualButton);
    m_pBox->append(*m_pBuilderButton);

    // Connette i segnali ai metodi membro
    m_pManualButton->signal_clicked().connect(
        sigc::mem_fun(*this, &MainHubWindow::on_manual_button_clicked));
    m_pBuilderButton->signal_clicked().connect(
        sigc::mem_fun(*this, &MainHubWindow::on_builder_button_clicked));
}

MainHubWindow::~MainHubWindow()
{
    // I widget figli vengono deallocati automaticamente dal contenitore.
}

void MainHubWindow::on_manual_button_clicked()
{
    // Crea e mostra una nuova ManualWindow (non modale)
    ManualWindow *pManual = new ManualWindow();
    pManual->set_transient_for(*this);
    pManual->show();
}

void MainHubWindow::on_builder_button_clicked()
{
    // Crea e mostra una nuova BuilderWindow (non modale)
    BuilderWindow *pBuilder = new BuilderWindow();
    pBuilder->set_transient_for(*this);
    pBuilder->show();
}
