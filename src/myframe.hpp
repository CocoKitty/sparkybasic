#pragma once
// By Edith Pugh on 2026-04-10

#include <wx/wx.h>

class MyFrame : public wxFrame {
    wxMenuBar* menu_bar;
    wxMenu* menu_file;
    wxMenu* menu_help;
    
    wxPanel* panel;

    wxTextCtrl* output_box;
    wxTextCtrl* entry_box;

    DECLARE_EVENT_TABLE()
public:
    MyFrame(void);
}; // end class MyFrame