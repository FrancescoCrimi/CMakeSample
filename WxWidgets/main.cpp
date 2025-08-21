#include <wx/wx.h>

/*
 * Tipo di applicazione: wxWidgets 3.2 - App minimale
 *
 * Descrizione:
 *  - Crea una finestra principale con titolo e dimensioni.
 *  - Mostra un messaggio statico.
 *  - Gestisce la chiusura tramite il pulsante standard.
 */

// Classe principale dell'applicazione
class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

// Finestra principale
class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title);

private:
    void OnQuit(wxCommandEvent& event);
};

// Implementazione della finestra
MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)) {

    // Testo statico al centro
    wxStaticText* label = new wxStaticText(this, wxID_ANY,
        "Benvenuto in wxWidgets 3.2!",
        wxPoint(100, 130));

    // Menu File → Esci
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT, "&Esci\tCtrl-Q", "Chiudi l'applicazione");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    SetMenuBar(menuBar);

    // Gestione evento uscita
    Bind(wxEVT_MENU, &MyFrame::OnQuit, this, wxID_EXIT);
}

// Evento di chiusura
void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
    Close(true);
}

// Avvio dell'applicazione
bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame("Demo wxWidgets 3.2");
    frame->Show(true);
    return true;
}

// Macro per avviare l'app
// wxIMPLEMENT_APP(MyApp);

// 4) Entry point manuale
int main(int argc, char** argv)
{
    // Creiamo e registriamo l’istanza di MyApp
    wxApp::SetInstance(new MyApp());

    // Inizializzazione di wxWidgets (parser di linea di comando incluso)
    if ( wxEntryStart(argc, argv) == false )
        return -1;

    // Chiamata manuale a OnInit()
    wxTheApp->CallOnInit();

    // Avvio del loop degli eventi
    int exitCode = wxTheApp->OnRun();

    // Pulizia delle risorse di wxWidgets
    wxEntryCleanup();

    return exitCode;
}


#ifdef _WIN32

#include <windows.h>

/*
 * Definizione di WinMain per compilare come applicazione GUI con MSVC o MinGW.
 * Per MSVC /SUBSYSTEM:WINDOWS (WIN32_EXECUTABLE) oppure per MinGW con -mwindows
 * non viene aperta la console.
 *
 * Le variabili globali __argc e __argv (disponibili con MSVC) vengono usate per
 * inoltrare gli argomenti a main.
 */
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    return main(__argc, __argv);
}

#endif
