/***************************************************************
 * Name:      memory2Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2017-04-25
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef MEMORY2MAIN_H
#define MEMORY2MAIN_H

//(*Headers(memory2Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class memory2Frame: public wxFrame
{
    public:
         void OnButton(wxCommandEvent & event);
        memory2Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~memory2Frame();
        kartenverdecken();
        Neustart();
    private:

        //(*Handlers(memory2Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(memory2Frame)
        static const long idMenuQuit;
        static const long idMenuRestart;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(memory2Frame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MEMORY2MAIN_H
