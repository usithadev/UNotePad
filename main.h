/**
 * @file main.h
 * @author Usitha Indeewara (https://github.com/usithadev)
 * @brief Declarations of main App class and main window.
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022 Usitha Indeewara. All Rights Reserved.
 */

#ifndef MAIN_H
#define MAIN_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/stc/stc.h>
#include <wx/file.h>
#include <wx/wfstream.h>
#include "about.h"

/**
 * @brief The main App class
 */
class App : public wxApp {
public:
    /**
     * @brief The application entry point
     *
     * @return true
     */
    virtual bool OnInit();
};

wxDECLARE_APP(App);

/**
 * @brief The main window object.
 * 
 */
class MainFrame : public wxFrame {    
public:
    MainFrame(const wxString& title);

private:
    using cmd = wxCommandEvent;
    wxPanel *panel = new wxPanel(this, wxID_ANY); // The main panel
    wxStyledTextCtrl *editor = new wxStyledTextCtrl(panel, wxID_ANY, wxDefaultPosition); // The text editor

    // Event methods for menu items
    void OnExit(cmd& evt);
    void OnAbout(cmd& evt);
    void OnSave(cmd& WXUNUSED(evt));
    void OnUndo(cmd& evt);
    void OnRedo(cmd& evt);
    void OnCopy(cmd& evt);
    void OnCut(cmd& evt);
    void OnPaste(cmd& evt);
};

#endif // MAIN_H

/**
 * @mainpage UNotePad
 * This is a simple text editor application written in C++ using [wxWidgets](https://wxwidgets.org) (which is a cross platform library for building graphical user interfaces). This project is for beginners who wants to learn about basics about wxWidgets. You can just read the code. It don't has a good documentation but is has a readable and self-explanatory code. You can learn basics of wxWidgets (sizers, frames, events, file handling, etc) by reading the code.  
 *   
 * Currently this app is saving an Untitled.txt file in the same directory. I will add a file dialog box and let the user to choose the directory to save the file when I have a time. And also feel free to contribute to this project.  
 * 
 * ## Build Instructions
 * 
 * To build this project you should have installed [CMake](https://cmake.org), a c++ compiler and built wxWidgets from source using CMake. (For wxWidgets build instructions see https://docs.wxwidgets.org/latest/overview_cmake.html).  
 *   
 * After that, open up the terminal:  
 * ```bash
 * git clone https://github.com/usithadev/UNotePad.git #For this you need git installed. You can also go to the github repository and download the coe.
 * 
 * cd UNotePad
 * 
 * cmake -DwxWidgets_DIR=path/to/wxWidgets -S . -B ./build -DCMAKE_BUILD_TYPE="Release" -G "MinGW Makefiles"
 * 
 * cd build
 * 
 * ```
 * 
 * Now you can find the UNotePad.exe (and the doxygen documentation files) in the build folder.
 * 
 * @author Usitha Indeewara
 * 
 */