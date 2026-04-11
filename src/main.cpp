// By Edith Pugh on 2026-April-10, Sparky's third birthday.

#include "main.hpp"

#include "myframe.hpp"

#include <wx/wx.h>

bool MyApp::OnInit() {
    // wxWidgets sucks so we can't use unique_ptr.
    MyFrame* frame = new MyFrame();
    frame->Show();
    return true;
} // end MyApp::OnInit

wxIMPLEMENT_APP(MyApp);