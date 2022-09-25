/**
 * @file about.cpp
 * @author Usitha Indeewara (https://github.com/usithadev)
 * @brief The forward declarations of classes and functions in about.h file.
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022 Usitha Indeewara. All Rights Reserved.
 * 
 */

#include "about.h"

AboutFrame::AboutFrame(wxWindow *parent, const wxString& title) : wxDialog(parent, wxID_ANY, title) {
    wxBoxSizer *top = new wxBoxSizer(wxVERTICAL);

    wxPanel *panel = new wxPanel(this, wxID_ANY, wxDefaultPosition);
    wxBoxSizer *panelsizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText *label = new wxStaticText(panel, wxID_ANY, "Hello. This is a simple Notepad application written by Usitha Indeewara using C++. \nPlease visit https://github.com/usithadev/UNotePad for more information. \n\nCopyright (c) 2022 Usitha Indeewara. All rights reserved.");
    panelsizer->Add(label, 1, wxALIGN_CENTER | wxALL, 10);

    panel->SetSizerAndFit(panelsizer);

    top->Add(panel, 1, wxALL | wxEXPAND, 0);
    this->SetSizerAndFit(top);
    this->SetMaxSize(this->GetSize());
    this->SetMaxSize(this->GetSize());
}