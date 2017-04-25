/***************************************************************
 * Name:      memory2Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2017-04-24
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef MEMORY2MAIN_H
#define MEMORY2MAIN_H

//(*Headers(memory2Frame)
#include <wx/bmpbuttn.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
//*)

class memory2Frame: public wxFrame
{
    public:

        memory2Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~memory2Frame();
        kartenverdecken();
    private:

        //(*Handlers(memory2Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnLeftDown(wxMouseEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnBitmapButton1Click1(wxCommandEvent& event);
        void OnBitmapButton2Click(wxCommandEvent& event);
        void OnBitmapButton3Click(wxCommandEvent& event);
        void OnBitmapButton4Click(wxCommandEvent& event);
        void OnBitmapButton5Click(wxCommandEvent& event);
        void OnBitmapButton6Click(wxCommandEvent& event);
        void OnBitmapButton7Click(wxCommandEvent& event);
        void OnBitmapButton8Click(wxCommandEvent& event);
        void OnBitmapButton9Click(wxCommandEvent& event);
        void OnBitmapButton10Click(wxCommandEvent& event);
        void OnBitmapButton11Click(wxCommandEvent& event);
        void OnBitmapButton12Click(wxCommandEvent& event);
        void OnBitmapButton13Click(wxCommandEvent& event);
        void OnBitmapButton14Click(wxCommandEvent& event);
        void OnBitmapButton15Click(wxCommandEvent& event);
        void OnBitmapButton16Click(wxCommandEvent& event);
        void OnBitmapButton17Click(wxCommandEvent& event);
        void OnBitmapButton18Click(wxCommandEvent& event);
        void OnBitmapButton19Click(wxCommandEvent& event);
        void OnBitmapButton20Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(memory2Frame)
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_BITMAPBUTTON4;
        static const long ID_BITMAPBUTTON5;
        static const long ID_BITMAPBUTTON6;
        static const long ID_BITMAPBUTTON7;
        static const long ID_BITMAPBUTTON8;
        static const long ID_BITMAPBUTTON9;
        static const long ID_BITMAPBUTTON10;
        static const long ID_BITMAPBUTTON11;
        static const long ID_BITMAPBUTTON12;
        static const long ID_BITMAPBUTTON13;
        static const long ID_BITMAPBUTTON14;
        static const long ID_BITMAPBUTTON15;
        static const long ID_BITMAPBUTTON16;
        static const long ID_BITMAPBUTTON17;
        static const long ID_BITMAPBUTTON18;
        static const long ID_BITMAPBUTTON19;
        static const long ID_BITMAPBUTTON20;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(memory2Frame)
        wxBitmapButton* BitmapButton10;
        wxBitmapButton* BitmapButton11;
        wxBitmapButton* BitmapButton12;
        wxBitmapButton* BitmapButton13;
        wxBitmapButton* BitmapButton14;
        wxBitmapButton* BitmapButton15;
        wxBitmapButton* BitmapButton16;
        wxBitmapButton* BitmapButton17;
        wxBitmapButton* BitmapButton18;
        wxBitmapButton* BitmapButton19;
        wxBitmapButton* BitmapButton1;
        wxBitmapButton* BitmapButton20;
        wxBitmapButton* BitmapButton2;
        wxBitmapButton* BitmapButton3;
        wxBitmapButton* BitmapButton4;
        wxBitmapButton* BitmapButton5;
        wxBitmapButton* BitmapButton6;
        wxBitmapButton* BitmapButton7;
        wxBitmapButton* BitmapButton8;
        wxBitmapButton* BitmapButton9;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MEMORY2MAIN_H
