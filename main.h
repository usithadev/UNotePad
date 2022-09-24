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
private:
    using cmd = wxCommandEvent;
    wxPanel *panel = new wxPanel(this, wxID_ANY);
    wxStyledTextCtrl *editor = new wxStyledTextCtrl(panel, wxID_ANY, wxDefaultPosition);
    
public:
    /**
     * @brief Construct a new Main Frame object
     * 
     * @param title The title of the window.
     */
    MainFrame(const wxString& title);
    
    /**
     * @brief The event function of the `Quit` menu item
     * 
     * @param evt 
     */
    void OnExit(cmd& evt);

    /**
     * @brief The event function of the `About` menu item
     * 
     * @param evt 
     */
    void OnAbout(cmd& evt);

    /**
     * @brief The event function of the `Save` menu item
     * 
     * @param evt 
     */
    void OnSave(cmd& evt);

    /**
     * @brief The event function of the `Undo` menu item
     * 
     * @param evt 
     */
    void OnUndo(cmd& evt);

    /**
     * @brief The event function of the `Redo` menu item
     * 
     * @param evt 
     */
    void OnRedo(cmd& evt);

    /**
     * @brief The event function of the `Copy` menu item
     * 
     * @param evt 
     */
    void OnCopy(cmd& evt);

    /**
     * @brief The event function of the `Cut` menu item
     * 
     * @param evt 
     */
    void OnCut(cmd& evt);

    /**
     * @brief The event function of the `Paste` menu item
     * 
     * @param evt 
     */
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