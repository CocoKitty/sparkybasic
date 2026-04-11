#pragma once
// By Edith Pugh on 2026-04-10

#include <wx/wx.h>

// These names like MyApp, MyPanel, etc aren't very descriptive but I can't
// think of any better ways to describe them that aren't kinda verbose like
// SparkyBasicApp (which would also make autocomplete p much useless)
class MyApp : public wxApp {
public:
    bool OnInit() override;
};