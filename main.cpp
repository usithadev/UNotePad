/**
 * @file main.cpp
 * @author Usitha Indeewara (https://github.com/usithadev)
 * @brief The forward declarations of classes and functions in main.h file.
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022 Usitha Indeewara. All Rights Reserved.
 * 
 */

#include "main.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame *frm = new MainFrame("UNotePad");
    frm->Show(true);

    return true;
}

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    this->SetIcon(wxICON(appicon)); // Set the application icon

    //
    // Widgets
    //
    
    wxBoxSizer *main = new wxBoxSizer(wxVERTICAL);        // The main sizer contains all the widgets
    
    wxBoxSizer *panelsizer = new wxBoxSizer(wxVERTICAL);  // The sizer of the panel
    
    panelsizer->Add(editor, 1, wxALL | wxEXPAND, 0);
    editor->SetMinSize(wxSize(300, 300));
    
    panel->SetSizerAndFit(panelsizer);

    main->Add(panel, 1, wxALL | wxEXPAND, 0);
    
    SetSizerAndFit(main);

    // 
    // Menu bar and status bar
    //
    wxMenu *file = new wxMenu;
    file->Append(wxID_EXIT);
    file->Append(wxID_SAVE);

    wxMenu *help = new wxMenu;
    help->Append(wxID_ABOUT);

    wxMenu *edit = new wxMenu;
    edit->Append(wxID_UNDO);
    edit->Append(wxID_REDO);
    edit->AppendSeparator();
    edit->Append(wxID_COPY);
    edit->Append(wxID_CUT);
    edit->Append(wxID_PASTE);

    wxMenuBar *menubar = new wxMenuBar;
    menubar->Append(file, "&File");
    menubar->Append(edit, "&Edit");
    menubar->Append(help, "&Help");

    SetMenuBar(menubar);

    CreateStatusBar();
    SetStatusText("POWERED BY UziDev");

    //
    // Event bindings
    //
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnSave, this, wxID_SAVE);
    Bind(wxEVT_MENU, &MainFrame::OnUndo, this, wxID_UNDO);
    Bind(wxEVT_MENU, &MainFrame::OnRedo, this, wxID_REDO);
    Bind(wxEVT_MENU, &MainFrame::OnCut, this, wxID_CUT);
    Bind(wxEVT_MENU, &MainFrame::OnCopy, this, wxID_COPY);
    Bind(wxEVT_MENU, &MainFrame::OnPaste, this, wxID_PASTE);

}

void MainFrame::OnExit(cmd& evt) {
    Close(true);
}

void MainFrame::OnAbout(cmd& evt) {
    AboutFrame *about = new AboutFrame(this, "About");
    about->Show(true);
}

void MainFrame::OnSave(cmd& WXUNUSED(evt)) {
    
    // The text of the editor
    wxString str = this->editor->GetText();

    // Getting the path
    wxFileDialog saveFileAs(this, "Save as", "", "", "Plain text files (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if(saveFileAs.ShowModal() == wxID_CANCEL) {
        return;
    }
    auto path = saveFileAs.GetPath();

    // Write the str to the Untitled.txt file
    wxFileOutputStream output(path);
    if(!output.IsOk()) {
        wxMessageBox("Unable to save the file");
        return;
    }

    wxFile *file = new wxFile(path, wxFile::write);
    if(file->IsOpened()) {
        file->Write(str);
    }
    file->Close();

}


// 
// The following forward declared functions are self-explanatory :)
// 

void MainFrame::OnUndo(cmd& evt) {
    this->editor->Undo();
}

void MainFrame::OnRedo(cmd& evt) {
    this->editor->Redo();
}

void MainFrame::OnCut(cmd& evt) {
    this->editor->Cut();
}

void MainFrame::OnCopy(cmd& evt) {
    this->editor->Copy();
}

void MainFrame::OnPaste(cmd& evt) {
    this->editor->Paste();
}