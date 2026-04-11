// By Edith Pugh on 2026-04-10

#include "myframe.hpp"

#include "defs.hpp"

enum MenuIDs {
    ID_Save = 1,
    ID_SaveAs,
    ID_SaveCopy,
    ID_Load,
    ID_Help,
    ID_Exit,
    ID_New,
};

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(ID_Save, MyFrame::on_save)
EVT_MENU(ID_SaveAs, MyFrame::on_save_as)
EVT_MENU(ID_SaveCopy, MyFrame::on_save_copy)
EVT_MENU(ID_Load, MyFrame::on_load)
EVT_MENU(ID_Help, MyFrame::on_help)
EVT_MENU(ID_Exit, MyFrame::on_close)
EVT_CLOSE(MyFrame::on_close)
END_EVENT_TABLE()

MyFrame::MyFrame(void) {
    menu_bar = new wxMenuBar();

    menu_file = new wxMenu();
    menu_help = new wxMenu();

    menu_file->Append(
        ID_New,
        "&New\tCtrl-N",
        "Clear current program to work on new program."
    );
    menu_file->Append(
        ID_Load,
        "&Load\tCtrl-O",
        "Clear current program and load in program file."
    );
    menu_file->AppendSeparator();
    menu_file->Append(
        ID_Save,
        "&Save\tCtrl-S",
        "Save commands in current file."
    );
    menu_file->Append(
        ID_SaveAs,
        "&Save as...\tShift-Ctrl-S",
        "Save commands in new file and make it the current file."
    );
    menu_file->Append(
        ID_SaveCopy,
        "&Save Copy...\tAlt-Ctrl-S",
        "Save commands in new file without making it the current file"
    );
    menu_file->AppendSeparator();
    menu_file->Append(
        ID_Exit,
        "&Exit SparkyBasic\tCtrl-Q",
        "Exit SparkyBasic without saving."
    );
}