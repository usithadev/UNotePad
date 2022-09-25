/**
 * @file about.cpp
 * @author Usitha Indeewara (https://github.com/usithadev)
 * @brief Class declaration of the about dialog frame
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022 Usitha Indeewara. All Rights Reserved.
 * 
 */

#ifndef ABOUT_H
#define ABOUT_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif // WX_PRECOMP

/**
 * @brief The about dialog frame
 * Inherited from wxDialog
 * 
 */
class AboutFrame : public wxDialog {
    public:

    /**
     * @brief Construct a new About Frame object
     * 
     * @param parent The parent window of the dialog.
     * @param title The title of the window.
     */
    AboutFrame(wxWindow *parent, const wxString& title);
};

#endif // ABOUT_H