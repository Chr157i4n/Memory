/***************************************************************
 * Name:      memory2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2017-04-25
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "memory2Main.h"
#include <wx/msgdlg.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


//(*InternalHeaders(memory2Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

wxBitmapButton* button[20];
wxBitmap bild[11],verdeckt;

int kartenanzahl=20;

int zuganzahl=0,karte1X,karte1Y,karte2X,karte2Y,verbleibendekarten=10;
bool zweitekartegeklickt=false;



//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(memory2Frame)
const long memory2Frame::idMenuQuit = wxNewId();
const long memory2Frame::idMenuAbout = wxNewId();
const long memory2Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(memory2Frame,wxFrame)
    //(*EventTable(memory2Frame)
    //*)
END_EVENT_TABLE()





class Spielfeld {

public:
    int zahl;

};

Spielfeld Spielfeld[5][4];








memory2Frame::memory2Frame(wxWindow* parent,wxWindowID id)
{


bild[1].LoadFile("pfingstrose.jpg",wxBITMAP_TYPE_JPEG);
bild[2].LoadFile("sommer1.jpg",wxBITMAP_TYPE_JPEG);
bild[3].LoadFile("sommer2.jpg",wxBITMAP_TYPE_JPEG);
bild[4].LoadFile("sommer3.jpg",wxBITMAP_TYPE_JPEG);
bild[5].LoadFile("nelke.jpg",wxBITMAP_TYPE_JPEG);
bild[6].LoadFile("sommer5.jpg",wxBITMAP_TYPE_JPEG);
bild[7].LoadFile("sommer6.jpg",wxBITMAP_TYPE_JPEG);
bild[8].LoadFile("sommer7.jpg",wxBITMAP_TYPE_JPEG);
bild[9].LoadFile("tokio1.jpg",wxBITMAP_TYPE_JPEG);
bild[10].LoadFile("hundefutter.jpg",wxBITMAP_TYPE_JPEG);


verdeckt.LoadFile("verdeckt.jpg",wxBITMAP_TYPE_JPEG);



    //(*Initialize(memory2Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&memory2Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&memory2Frame::OnAbout);
    //*)



      for(int x=0; x<6; x++)
    {
        for(int y=0; y<5; y++)
        {
            Spielfeld[x][y].zahl=0;

        }
    }


    srand (time(NULL));
    int i = 1;
    bool spielpaar = false;
    while(i<=10)
    {
        int x,y;
        bool kartegesetzt=false;

        while(!kartegesetzt)
        {

            x = rand() % 5 ;
            y = rand() % 4 ;
               if(Spielfeld[x][y].zahl==0)
                {
                    kartegesetzt=true;
                    Spielfeld[x][y].zahl=i;
                }


        }

            if (!spielpaar)
            {
                spielpaar=true;
            }
            else
            {
                spielpaar=false;
                i++;
            }


    }




SetSize(750,580);


    int x=20;
    int y=20;

    for(int i=0;i<20;i++)
    {

        button[i] = new wxBitmapButton(this,1000+i,verdeckt,wxPoint(x,y),wxSize(100, 100));

        Connect(1000+i, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&memory2Frame::OnButton);

        x=x+120;
        if (x>=600) {x=20; y=y+120;}

    }

}



memory2Frame::kartenverdecken()
{
    zuganzahl=zuganzahl+2;

  if (Spielfeld[karte1X][karte1Y].zahl!=Spielfeld[karte2X][karte2Y].zahl)
  {



      button[(karte1X)+(karte1Y*5)]->SetBitmap(verdeckt);
      button[(karte2X)+(karte2Y*5)]->SetBitmap(verdeckt);

  }
  else
  {

      button[(karte1X)+(karte1Y*5)]->Enable(false);
      button[(karte2X)+(karte2Y*5)]->Enable(false);
      verbleibendekarten--;
  }

  if (verbleibendekarten<=0) {wxString msg = "Du hast ";  msg << zuganzahl; msg=msg+" Züge gebraucht"; wxMessageBox(msg,"Gewonnen");}
}




void memory2Frame::OnButton(wxCommandEvent & event)
{
    int a = (event.GetId())-1000;
    ///wxMessageBox(wxString::Format(_("%i"),a));

   int x= a % 5;
   int y= a/5;

 button[a]->SetBitmap(bild[Spielfeld[x][y].zahl]);

  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=x;
        karte1Y=y;
    }
    else if(!((karte1X==x) && (karte1Y==y)))
    {
        karte2X=x;
        karte2Y=y;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }

}







memory2Frame::~memory2Frame()
{
    //(*Destroy(memory2Frame)
    //*)
}

void memory2Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void memory2Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
