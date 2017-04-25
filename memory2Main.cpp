/***************************************************************
 * Name:      memory2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2017-04-24
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

wxBitmap bild1,bild2,bild3,bild4,bild5,bild6,bild7,bild8,bild9,bild10,verdeckt;
int spielfeld[5][4];
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
const long memory2Frame::ID_BITMAPBUTTON1 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON2 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON3 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON4 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON5 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON6 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON7 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON8 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON9 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON10 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON11 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON12 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON13 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON14 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON15 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON16 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON17 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON18 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON19 = wxNewId();
const long memory2Frame::ID_BITMAPBUTTON20 = wxNewId();
const long memory2Frame::idMenuQuit = wxNewId();
const long memory2Frame::idMenuAbout = wxNewId();
const long memory2Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(memory2Frame,wxFrame)
    //(*EventTable(memory2Frame)
    //*)
END_EVENT_TABLE()

memory2Frame::memory2Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(memory2Frame)
    wxGridSizer* GridSizer1;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(600,500));
    GridSizer1 = new wxGridSizer(0, 5, 0, 0);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    GridSizer1->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton2 = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    GridSizer1->Add(BitmapButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton3 = new wxBitmapButton(this, ID_BITMAPBUTTON3, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    GridSizer1->Add(BitmapButton3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton4 = new wxBitmapButton(this, ID_BITMAPBUTTON4, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    GridSizer1->Add(BitmapButton4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton5 = new wxBitmapButton(this, ID_BITMAPBUTTON5, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
    GridSizer1->Add(BitmapButton5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton6 = new wxBitmapButton(this, ID_BITMAPBUTTON6, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    GridSizer1->Add(BitmapButton6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton7 = new wxBitmapButton(this, ID_BITMAPBUTTON7, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
    GridSizer1->Add(BitmapButton7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton8 = new wxBitmapButton(this, ID_BITMAPBUTTON8, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON8"));
    GridSizer1->Add(BitmapButton8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton9 = new wxBitmapButton(this, ID_BITMAPBUTTON9, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON9"));
    GridSizer1->Add(BitmapButton9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton10 = new wxBitmapButton(this, ID_BITMAPBUTTON10, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON10"));
    GridSizer1->Add(BitmapButton10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton11 = new wxBitmapButton(this, ID_BITMAPBUTTON11, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON11"));
    GridSizer1->Add(BitmapButton11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton12 = new wxBitmapButton(this, ID_BITMAPBUTTON12, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON12"));
    GridSizer1->Add(BitmapButton12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton13 = new wxBitmapButton(this, ID_BITMAPBUTTON13, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON13"));
    GridSizer1->Add(BitmapButton13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton14 = new wxBitmapButton(this, ID_BITMAPBUTTON14, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON14"));
    GridSizer1->Add(BitmapButton14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton15 = new wxBitmapButton(this, ID_BITMAPBUTTON15, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON15"));
    GridSizer1->Add(BitmapButton15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton16 = new wxBitmapButton(this, ID_BITMAPBUTTON16, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON16"));
    GridSizer1->Add(BitmapButton16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton17 = new wxBitmapButton(this, ID_BITMAPBUTTON17, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON17"));
    GridSizer1->Add(BitmapButton17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton18 = new wxBitmapButton(this, ID_BITMAPBUTTON18, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON18"));
    GridSizer1->Add(BitmapButton18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton19 = new wxBitmapButton(this, ID_BITMAPBUTTON19, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON19"));
    GridSizer1->Add(BitmapButton19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton20 = new wxBitmapButton(this, ID_BITMAPBUTTON20, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON20"));
    GridSizer1->Add(BitmapButton20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(GridSizer1);
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
    SetSizer(GridSizer1);
    Layout();

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton1Click);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton2Click);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton3Click);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton4Click);
    Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton5Click);
    Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton6Click);
    Connect(ID_BITMAPBUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton7Click);
    Connect(ID_BITMAPBUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton8Click);
    Connect(ID_BITMAPBUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton9Click);
    Connect(ID_BITMAPBUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton10Click);
    Connect(ID_BITMAPBUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton11Click);
    Connect(ID_BITMAPBUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton12Click);
    Connect(ID_BITMAPBUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton13Click);
    Connect(ID_BITMAPBUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton14Click);
    Connect(ID_BITMAPBUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton15Click);
    Connect(ID_BITMAPBUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton16Click);
    Connect(ID_BITMAPBUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton17Click);
    Connect(ID_BITMAPBUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton18Click);
    Connect(ID_BITMAPBUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton19Click);
    Connect(ID_BITMAPBUTTON20,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&memory2Frame::OnBitmapButton20Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&memory2Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&memory2Frame::OnAbout);
    Connect(wxEVT_PAINT,(wxObjectEventFunction)&memory2Frame::OnPaint);
    //*)


bild1.LoadFile("pfingstrose.jpg",wxBITMAP_TYPE_JPEG);
bild2.LoadFile("sommer1.jpg",wxBITMAP_TYPE_JPEG);
bild3.LoadFile("sommer2.jpg",wxBITMAP_TYPE_JPEG);
bild4.LoadFile("sommer3.jpg",wxBITMAP_TYPE_JPEG);
bild5.LoadFile("nelke.jpg",wxBITMAP_TYPE_JPEG);
bild6.LoadFile("sommer5.jpg",wxBITMAP_TYPE_JPEG);
bild7.LoadFile("sommer6.jpg",wxBITMAP_TYPE_JPEG);
bild8.LoadFile("sommer7.jpg",wxBITMAP_TYPE_JPEG);
bild9.LoadFile("tokio1.jpg",wxBITMAP_TYPE_JPEG);
bild10.LoadFile("hundefutter.jpg",wxBITMAP_TYPE_JPEG);
verdeckt.LoadFile("verdeckt.jpg",wxBITMAP_TYPE_JPEG);

BitmapButton1->SetBitmap(verdeckt);
BitmapButton2->SetBitmap(verdeckt);
BitmapButton3->SetBitmap(verdeckt);
BitmapButton4->SetBitmap(verdeckt);
BitmapButton5->SetBitmap(verdeckt);
BitmapButton6->SetBitmap(verdeckt);
BitmapButton7->SetBitmap(verdeckt);
BitmapButton8->SetBitmap(verdeckt);
BitmapButton9->SetBitmap(verdeckt);
BitmapButton10->SetBitmap(verdeckt);
BitmapButton11->SetBitmap(verdeckt);
BitmapButton12->SetBitmap(verdeckt);
BitmapButton13->SetBitmap(verdeckt);
BitmapButton14->SetBitmap(verdeckt);
BitmapButton15->SetBitmap(verdeckt);
BitmapButton16->SetBitmap(verdeckt);
BitmapButton17->SetBitmap(verdeckt);
BitmapButton18->SetBitmap(verdeckt);
BitmapButton19->SetBitmap(verdeckt);
BitmapButton20->SetBitmap(verdeckt);

    for(int x=0; x<6; x++)
    {
        for(int y=0; y<5; y++)
        {
            spielfeld[x][y]=0;
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
               if(spielfeld[x][y]==0)
                {
                    kartegesetzt=true;
                    spielfeld[x][y]=i;
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

void memory2Frame::OnPaint(wxPaintEvent& event)
{

     //wxPaintDC dc(this);

     /* for(int x=0; x<5; x++)
    {
        for(int y=0; y<4; y++)
        {
            switch (spielfeld[x][y])
               {
                case 1:     dc.DrawBitmap(bild1,x*120+20,y*120+20);     break;
                case 2:     dc.DrawBitmap(bild2,x*120+20,y*120+20);     break;
                case 3:     dc.DrawBitmap(bild3,x*120+20,y*120+20);     break;
                case 4:     dc.DrawBitmap(bild4,x*120+20,y*120+20);     break;
                case 5:     dc.DrawBitmap(bild5,x*120+20,y*120+20);     break;
                case 6:     dc.DrawBitmap(bild6,x*120+20,y*120+20);     break;
                case 7:     dc.DrawBitmap(bild7,x*120+20,y*120+20);     break;
                case 8:     dc.DrawBitmap(bild8,x*120+20,y*120+20);     break;
                case 9:     dc.DrawBitmap(bild9,x*120+20,y*120+20);     break;
                case 10:    dc.DrawBitmap(bild10,x*120+20,y*120+20);    break;
               }
            }

        }*/

  /*   dc.SetTextForeground( *wxBLUE );
    dc.SetFont(wxFontInfo(20).FaceName("Comic Sans MS").Light());
    dc.DrawText("Züge: ",650,50);
    //dc.DrawText(zuganzahl,650,50);*/



}

/*void memory2Frame::OnLeftDown(wxMouseEvent& event)
{
    int mausX = (GetScreenPosition().x-20)/120;
    int mausY = (GetScreenPosition().y-20)/120;
    //wxMessagebox(wxT());
    spielfeld[mausX][mausY]=0;

    Refresh();
}*/
memory2Frame::kartenverdecken()
{
    zuganzahl=zuganzahl+2;

  if (spielfeld[karte1X][karte1Y]!=spielfeld[karte2X][karte2Y])
  {
        switch ((karte1X+1)+(karte1Y*5))
          {
                case 1:     BitmapButton1->SetBitmap(verdeckt);      break;
                case 2:     BitmapButton2->SetBitmap(verdeckt);      break;
                case 3:     BitmapButton3->SetBitmap(verdeckt);      break;
                case 4:     BitmapButton4->SetBitmap(verdeckt);      break;
                case 5:     BitmapButton5->SetBitmap(verdeckt);      break;
                case 6:     BitmapButton6->SetBitmap(verdeckt);      break;
                case 7:     BitmapButton7->SetBitmap(verdeckt);      break;
                case 8:     BitmapButton8->SetBitmap(verdeckt);      break;
                case 9:     BitmapButton9->SetBitmap(verdeckt);      break;
                case 10:    BitmapButton10->SetBitmap(verdeckt);   break;
                case 11:    BitmapButton11->SetBitmap(verdeckt);   break;
                case 12:    BitmapButton12->SetBitmap(verdeckt);   break;
                case 13:    BitmapButton13->SetBitmap(verdeckt);   break;
                case 14:    BitmapButton14->SetBitmap(verdeckt);   break;
                case 15:    BitmapButton15->SetBitmap(verdeckt);   break;
                case 16:    BitmapButton16->SetBitmap(verdeckt);   break;
                case 17:    BitmapButton17->SetBitmap(verdeckt);   break;
                case 18:    BitmapButton18->SetBitmap(verdeckt);   break;
                case 19:    BitmapButton19->SetBitmap(verdeckt);   break;
                case 20:    BitmapButton20->SetBitmap(verdeckt);    break;
          }
           switch ((karte2X+1)+(karte2Y*5))
          {
                case 1:     BitmapButton1->SetBitmap(verdeckt);     break;
                case 2:     BitmapButton2->SetBitmap(verdeckt);     break;
                case 3:     BitmapButton3->SetBitmap(verdeckt);     break;
                case 4:     BitmapButton4->SetBitmap(verdeckt);     break;
                case 5:     BitmapButton5->SetBitmap(verdeckt);     break;
                case 6:     BitmapButton6->SetBitmap(verdeckt);     break;
                case 7:     BitmapButton7->SetBitmap(verdeckt);     break;
                case 8:     BitmapButton8->SetBitmap(verdeckt);     break;
                case 9:     BitmapButton9->SetBitmap(verdeckt);     break;
                case 10:    BitmapButton10->SetBitmap(verdeckt);   break;
                case 11:    BitmapButton11->SetBitmap(verdeckt);   break;
                case 12:    BitmapButton12->SetBitmap(verdeckt);   break;
                case 13:    BitmapButton13->SetBitmap(verdeckt);   break;
                case 14:    BitmapButton14->SetBitmap(verdeckt);   break;
                case 15:    BitmapButton15->SetBitmap(verdeckt);   break;
                case 16:    BitmapButton16->SetBitmap(verdeckt);   break;
                case 17:    BitmapButton17->SetBitmap(verdeckt);   break;
                case 18:    BitmapButton18->SetBitmap(verdeckt);   break;
                case 19:    BitmapButton19->SetBitmap(verdeckt);   break;
                case 20:    BitmapButton20->SetBitmap(verdeckt);   break;
          }
  }
  else
  {

      switch ((karte1X+1)+(karte1Y*5))
          {
                case 1:      BitmapButton1->Enable(false);    break;
                case 2:      BitmapButton2->Enable(false);    break;
                case 3:      BitmapButton3->Enable(false);    break;
                case 4:      BitmapButton4->Enable(false);    break;
                case 5:      BitmapButton5->Enable(false);    break;
                case 6:      BitmapButton6->Enable(false);    break;
                case 7:      BitmapButton7->Enable(false);    break;
                case 8:      BitmapButton8->Enable(false);    break;
                case 9:      BitmapButton9->Enable(false);    break;
                case 10:     BitmapButton10->Enable(false);  break;
                case 11:     BitmapButton11->Enable(false);  break;
                case 12:     BitmapButton12->Enable(false);  break;
                case 13:     BitmapButton13->Enable(false);  break;
                case 14:     BitmapButton14->Enable(false);  break;
                case 15:     BitmapButton15->Enable(false);  break;
                case 16:     BitmapButton16->Enable(false);  break;
                case 17:     BitmapButton17->Enable(false);  break;
                case 18:     BitmapButton18->Enable(false);  break;
                case 19:     BitmapButton19->Enable(false);  break;
                case 20:     BitmapButton20->Enable(false);  break;
          }
           switch ((karte2X+1)+(karte2Y*5))
          {
                case 1:      BitmapButton1->Enable(false);    break;
                case 2:      BitmapButton2->Enable(false);    break;
                case 3:      BitmapButton3->Enable(false);    break;
                case 4:      BitmapButton4->Enable(false);    break;
                case 5:      BitmapButton5->Enable(false);    break;
                case 6:      BitmapButton6->Enable(false);    break;
                case 7:      BitmapButton7->Enable(false);    break;
                case 8:      BitmapButton8->Enable(false);    break;
                case 9:      BitmapButton9->Enable(false);    break;
                case 10:     BitmapButton10->Enable(false);  break;
                case 11:     BitmapButton11->Enable(false);  break;
                case 12:     BitmapButton12->Enable(false);  break;
                case 13:     BitmapButton13->Enable(false);  break;
                case 14:     BitmapButton14->Enable(false);  break;
                case 15:     BitmapButton15->Enable(false);  break;
                case 16:     BitmapButton16->Enable(false);  break;
                case 17:     BitmapButton17->Enable(false);  break;
                case 18:     BitmapButton18->Enable(false);  break;
                case 19:     BitmapButton19->Enable(false);  break;
                case 20:     BitmapButton20->Enable(false);  break;
          }

      verbleibendekarten--;
  }
  if (verbleibendekarten<=0) {wxString msg = "Du hast ";  msg << zuganzahl; msg=msg+" Züge gebraucht"; wxMessageBox(msg,"Gewonnen");}
}

void memory2Frame::OnBitmapButton1Click(wxCommandEvent& event)
{
switch (spielfeld[0][0])
               {
                case 1:     BitmapButton1->SetBitmap(bild1);     break;
                case 2:     BitmapButton1->SetBitmap(bild2);     break;
                case 3:     BitmapButton1->SetBitmap(bild3);     break;
                case 4:     BitmapButton1->SetBitmap(bild4);     break;
                case 5:     BitmapButton1->SetBitmap(bild5);     break;
                case 6:     BitmapButton1->SetBitmap(bild6);     break;
                case 7:     BitmapButton1->SetBitmap(bild7);     break;
                case 8:     BitmapButton1->SetBitmap(bild8);     break;
                case 9:     BitmapButton1->SetBitmap(bild9);     break;
                case 10:    BitmapButton1->SetBitmap(bild10);    break;
               }
    if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=0;
        karte1Y=0;
    }
    else if(!((karte1X==0) && (karte1Y==0)))
    {
        karte2X=0;
        karte2Y=0;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}


void memory2Frame::OnBitmapButton2Click(wxCommandEvent& event)
{
 switch (spielfeld[1][0])
               {
                case 1:     BitmapButton2->SetBitmap(bild1);     break;
                case 2:     BitmapButton2->SetBitmap(bild2);     break;
                case 3:     BitmapButton2->SetBitmap(bild3);     break;
                case 4:     BitmapButton2->SetBitmap(bild4);     break;
                case 5:     BitmapButton2->SetBitmap(bild5);     break;
                case 6:     BitmapButton2->SetBitmap(bild6);     break;
                case 7:     BitmapButton2->SetBitmap(bild7);     break;
                case 8:     BitmapButton2->SetBitmap(bild8);     break;
                case 9:     BitmapButton2->SetBitmap(bild9);     break;
                case 10:    BitmapButton2->SetBitmap(bild10);    break;
               }
  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=1;
        karte1Y=0;
    }
    else if(!((karte1X==1) && (karte1Y==0)))
    {
        karte2X=1;
        karte2Y=0;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton3Click(wxCommandEvent& event)
{
    switch (spielfeld[2][0])
               {
                case 1:     BitmapButton3->SetBitmap(bild1);     break;
                case 2:     BitmapButton3->SetBitmap(bild2);     break;
                case 3:     BitmapButton3->SetBitmap(bild3);     break;
                case 4:     BitmapButton3->SetBitmap(bild4);     break;
                case 5:     BitmapButton3->SetBitmap(bild5);     break;
                case 6:     BitmapButton3->SetBitmap(bild6);     break;
                case 7:     BitmapButton3->SetBitmap(bild7);     break;
                case 8:     BitmapButton3->SetBitmap(bild8);     break;
                case 9:     BitmapButton3->SetBitmap(bild9);     break;
                case 10:    BitmapButton3->SetBitmap(bild10);    break;
               }
  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=2;
        karte1Y=0;
    }
    else if(!((karte1X==2) && (karte1Y==0)))
    {
        karte2X=2;
        karte2Y=0;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton4Click(wxCommandEvent& event)
{
    switch (spielfeld[3][0])
               {
                case 1:     BitmapButton4->SetBitmap(bild1);     break;
                case 2:     BitmapButton4->SetBitmap(bild2);     break;
                case 3:     BitmapButton4->SetBitmap(bild3);     break;
                case 4:     BitmapButton4->SetBitmap(bild4);     break;
                case 5:     BitmapButton4->SetBitmap(bild5);     break;
                case 6:     BitmapButton4->SetBitmap(bild6);     break;
                case 7:     BitmapButton4->SetBitmap(bild7);     break;
                case 8:     BitmapButton4->SetBitmap(bild8);     break;
                case 9:     BitmapButton4->SetBitmap(bild9);     break;
                case 10:    BitmapButton4->SetBitmap(bild10);    break;
               }
  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=3;
        karte1Y=0;
    }
    else if(!((karte1X==3) && (karte1Y==0)))
    {
        karte2X=3;
        karte2Y=0;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton5Click(wxCommandEvent& event)
{switch (spielfeld[4][0])
               {
                case 1:     BitmapButton5->SetBitmap(bild1);     break;
                case 2:     BitmapButton5->SetBitmap(bild2);     break;
                case 3:     BitmapButton5->SetBitmap(bild3);     break;
                case 4:     BitmapButton5->SetBitmap(bild4);     break;
                case 5:     BitmapButton5->SetBitmap(bild5);     break;
                case 6:     BitmapButton5->SetBitmap(bild6);     break;
                case 7:     BitmapButton5->SetBitmap(bild7);     break;
                case 8:     BitmapButton5->SetBitmap(bild8);     break;
                case 9:     BitmapButton5->SetBitmap(bild9);     break;
                case 10:    BitmapButton5->SetBitmap(bild10);    break;
               }

  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=4;
        karte1Y=0;
    }
    else if(!((karte1X==4) && (karte1Y==0)))
    {
        karte2X=4;
        karte2Y=0;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton6Click(wxCommandEvent& event)
{
    switch (spielfeld[0][1])
               {
                case 1:     BitmapButton6->SetBitmap(bild1);     break;
                case 2:     BitmapButton6->SetBitmap(bild2);     break;
                case 3:     BitmapButton6->SetBitmap(bild3);     break;
                case 4:     BitmapButton6->SetBitmap(bild4);     break;
                case 5:     BitmapButton6->SetBitmap(bild5);     break;
                case 6:     BitmapButton6->SetBitmap(bild6);     break;
                case 7:     BitmapButton6->SetBitmap(bild7);     break;
                case 8:     BitmapButton6->SetBitmap(bild8);     break;
                case 9:     BitmapButton6->SetBitmap(bild9);     break;
                case 10:    BitmapButton6->SetBitmap(bild10);    break;
               }
  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=0;
        karte1Y=1;
    }
    else if(!((karte1X==0) && (karte1Y==1)))
    {
        karte2X=0;
        karte2Y=1;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton7Click(wxCommandEvent& event)
{
    switch (spielfeld[1][1])
               {
                case 1:     BitmapButton7->SetBitmap(bild1);     break;
                case 2:     BitmapButton7->SetBitmap(bild2);     break;
                case 3:     BitmapButton7->SetBitmap(bild3);     break;
                case 4:     BitmapButton7->SetBitmap(bild4);     break;
                case 5:     BitmapButton7->SetBitmap(bild5);     break;
                case 6:     BitmapButton7->SetBitmap(bild6);     break;
                case 7:     BitmapButton7->SetBitmap(bild7);     break;
                case 8:     BitmapButton7->SetBitmap(bild8);     break;
                case 9:     BitmapButton7->SetBitmap(bild9);     break;
                case 10:    BitmapButton7->SetBitmap(bild10);    break;
               }
  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=1;
        karte1Y=1;
    }
    else if(!((karte1X==1) && (karte1Y==1)))
    {
        karte2X=1;
        karte2Y=1;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton8Click(wxCommandEvent& event)
{
    switch (spielfeld[2][1])
               {
                case 1:     BitmapButton8->SetBitmap(bild1);     break;
                case 2:     BitmapButton8->SetBitmap(bild2);     break;
                case 3:     BitmapButton8->SetBitmap(bild3);     break;
                case 4:     BitmapButton8->SetBitmap(bild4);     break;
                case 5:     BitmapButton8->SetBitmap(bild5);     break;
                case 6:     BitmapButton8->SetBitmap(bild6);     break;
                case 7:     BitmapButton8->SetBitmap(bild7);     break;
                case 8:     BitmapButton8->SetBitmap(bild8);     break;
                case 9:     BitmapButton8->SetBitmap(bild9);     break;
                case 10:    BitmapButton8->SetBitmap(bild10);    break;
               }

  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=2;
        karte1Y=1;
    }
    else if(!((karte1X==2) && (karte1Y==1)))
    {
        karte2X=2;
        karte2Y=1;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton9Click(wxCommandEvent& event)
{
    switch (spielfeld[3][1])
               {
                case 1:     BitmapButton9->SetBitmap(bild1);     break;
                case 2:     BitmapButton9->SetBitmap(bild2);     break;
                case 3:     BitmapButton9->SetBitmap(bild3);     break;
                case 4:     BitmapButton9->SetBitmap(bild4);     break;
                case 5:     BitmapButton9->SetBitmap(bild5);     break;
                case 6:     BitmapButton9->SetBitmap(bild6);     break;
                case 7:     BitmapButton9->SetBitmap(bild7);     break;
                case 8:     BitmapButton9->SetBitmap(bild8);     break;
                case 9:     BitmapButton9->SetBitmap(bild9);     break;
                case 10:    BitmapButton9->SetBitmap(bild10);    break;
               }
  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=3;
        karte1Y=1;
    }
    else if(!((karte1X==3) && (karte1Y==1)))
    {
        karte2X=3;
        karte2Y=1;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton10Click(wxCommandEvent& event)
{
    switch (spielfeld[4][1])
               {
                case 1:     BitmapButton10->SetBitmap(bild1);     break;
                case 2:     BitmapButton10->SetBitmap(bild2);     break;
                case 3:     BitmapButton10->SetBitmap(bild3);     break;
                case 4:     BitmapButton10->SetBitmap(bild4);     break;
                case 5:     BitmapButton10->SetBitmap(bild5);     break;
                case 6:     BitmapButton10->SetBitmap(bild6);     break;
                case 7:     BitmapButton10->SetBitmap(bild7);     break;
                case 8:     BitmapButton10->SetBitmap(bild8);     break;
                case 9:     BitmapButton10->SetBitmap(bild9);     break;
                case 10:    BitmapButton10->SetBitmap(bild10);    break;
               }
  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=4;
        karte1Y=1;
    }
    else if(!((karte1X==4) && (karte1Y==1)))
    {
        karte2X=4;
        karte2Y=1;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton11Click(wxCommandEvent& event)
{
    switch (spielfeld[0][2])
               {
                case 1:     BitmapButton11->SetBitmap(bild1);     break;
                case 2:     BitmapButton11->SetBitmap(bild2);     break;
                case 3:     BitmapButton11->SetBitmap(bild3);     break;
                case 4:     BitmapButton11->SetBitmap(bild4);     break;
                case 5:     BitmapButton11->SetBitmap(bild5);     break;
                case 6:     BitmapButton11->SetBitmap(bild6);     break;
                case 7:     BitmapButton11->SetBitmap(bild7);     break;
                case 8:     BitmapButton11->SetBitmap(bild8);     break;
                case 9:     BitmapButton11->SetBitmap(bild9);     break;
                case 10:    BitmapButton11->SetBitmap(bild10);    break;
               }

  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=0;
        karte1Y=2;
    }
    else if(!((karte1X==0) && (karte1Y==2)))
    {
        karte2X=0;
        karte2Y=2;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton12Click(wxCommandEvent& event)
{
    switch (spielfeld[1][2])
               {
                case 1:     BitmapButton12->SetBitmap(bild1);     break;
                case 2:     BitmapButton12->SetBitmap(bild2);     break;
                case 3:     BitmapButton12->SetBitmap(bild3);     break;
                case 4:     BitmapButton12->SetBitmap(bild4);     break;
                case 5:     BitmapButton12->SetBitmap(bild5);     break;
                case 6:     BitmapButton12->SetBitmap(bild6);     break;
                case 7:     BitmapButton12->SetBitmap(bild7);     break;
                case 8:     BitmapButton12->SetBitmap(bild8);     break;
                case 9:     BitmapButton12->SetBitmap(bild9);     break;
                case 10:    BitmapButton12->SetBitmap(bild10);    break;
               }

  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=1;
        karte1Y=2;
    }
    else if(!((karte1X==1) && (karte1Y==2)))
    {
        karte2X=1;
        karte2Y=2;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton13Click(wxCommandEvent& event)
{
    switch (spielfeld[2][2])
               {
                case 1:     BitmapButton13->SetBitmap(bild1);     break;
                case 2:     BitmapButton13->SetBitmap(bild2);     break;
                case 3:     BitmapButton13->SetBitmap(bild3);     break;
                case 4:     BitmapButton13->SetBitmap(bild4);     break;
                case 5:     BitmapButton13->SetBitmap(bild5);     break;
                case 6:     BitmapButton13->SetBitmap(bild6);     break;
                case 7:     BitmapButton13->SetBitmap(bild7);     break;
                case 8:     BitmapButton13->SetBitmap(bild8);     break;
                case 9:     BitmapButton13->SetBitmap(bild9);     break;
                case 10:    BitmapButton13->SetBitmap(bild10);    break;
               }

  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=2;
        karte1Y=2;
    }
    else if(!((karte1X==2) && (karte1Y==2)))
    {
        karte2X=2;
        karte2Y=2;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton14Click(wxCommandEvent& event)
{switch (spielfeld[3][2])
               {
                case 1:     BitmapButton14->SetBitmap(bild1);     break;
                case 2:     BitmapButton14->SetBitmap(bild2);     break;
                case 3:     BitmapButton14->SetBitmap(bild3);     break;
                case 4:     BitmapButton14->SetBitmap(bild4);     break;
                case 5:     BitmapButton14->SetBitmap(bild5);     break;
                case 6:     BitmapButton14->SetBitmap(bild6);     break;
                case 7:     BitmapButton14->SetBitmap(bild7);     break;
                case 8:     BitmapButton14->SetBitmap(bild8);     break;
                case 9:     BitmapButton14->SetBitmap(bild9);     break;
                case 10:    BitmapButton14->SetBitmap(bild10);    break;
               }
  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=3;
        karte1Y=2;
    }
    else if(!((karte1X==3) && (karte1Y==2)))
    {
        karte2X=3;
        karte2Y=2;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton15Click(wxCommandEvent& event)
{
    switch (spielfeld[4][2])
               {
                case 1:     BitmapButton15->SetBitmap(bild1);     break;
                case 2:     BitmapButton15->SetBitmap(bild2);     break;
                case 3:     BitmapButton15->SetBitmap(bild3);     break;
                case 4:     BitmapButton15->SetBitmap(bild4);     break;
                case 5:     BitmapButton15->SetBitmap(bild5);     break;
                case 6:     BitmapButton15->SetBitmap(bild6);     break;
                case 7:     BitmapButton15->SetBitmap(bild7);     break;
                case 8:     BitmapButton15->SetBitmap(bild8);     break;
                case 9:     BitmapButton15->SetBitmap(bild9);     break;
                case 10:    BitmapButton15->SetBitmap(bild10);    break;
               }
  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=4;
        karte1Y=2;
    }
    else if(!((karte1X==4) && (karte1Y==2)))
    {
        karte2X=4;
        karte2Y=2;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton16Click(wxCommandEvent& event)
{
    switch (spielfeld[0][3])
               {
                case 1:     BitmapButton16->SetBitmap(bild1);     break;
                case 2:     BitmapButton16->SetBitmap(bild2);     break;
                case 3:     BitmapButton16->SetBitmap(bild3);     break;
                case 4:     BitmapButton16->SetBitmap(bild4);     break;
                case 5:     BitmapButton16->SetBitmap(bild5);     break;
                case 6:     BitmapButton16->SetBitmap(bild6);     break;
                case 7:     BitmapButton16->SetBitmap(bild7);     break;
                case 8:     BitmapButton16->SetBitmap(bild8);     break;
                case 9:     BitmapButton16->SetBitmap(bild9);     break;
                case 10:    BitmapButton16->SetBitmap(bild10);    break;
               }

  if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=0;
        karte1Y=3;
    }
    else if(!((karte1X==0) && (karte1Y==3)))
    {
        karte2X=0;
        karte2Y=3;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton17Click(wxCommandEvent& event)
{switch (spielfeld[1][3])
               {
                case 1:     BitmapButton17->SetBitmap(bild1);     break;
                case 2:     BitmapButton17->SetBitmap(bild2);     break;
                case 3:     BitmapButton17->SetBitmap(bild3);     break;
                case 4:     BitmapButton17->SetBitmap(bild4);     break;
                case 5:     BitmapButton17->SetBitmap(bild5);     break;
                case 6:     BitmapButton17->SetBitmap(bild6);     break;
                case 7:     BitmapButton17->SetBitmap(bild7);     break;
                case 8:     BitmapButton17->SetBitmap(bild8);     break;
                case 9:     BitmapButton17->SetBitmap(bild9);     break;
                case 10:    BitmapButton17->SetBitmap(bild10);    break;
               }
if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=1;
        karte1Y=3;
    }
    else if(!((karte1X==1) && (karte1Y==3)))
    {
        karte2X=1;
        karte2Y=3;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton18Click(wxCommandEvent& event)
{
    switch (spielfeld[2][3])
               {
                case 1:     BitmapButton18->SetBitmap(bild1);     break;
                case 2:     BitmapButton18->SetBitmap(bild2);     break;
                case 3:     BitmapButton18->SetBitmap(bild3);     break;
                case 4:     BitmapButton18->SetBitmap(bild4);     break;
                case 5:     BitmapButton18->SetBitmap(bild5);     break;
                case 6:     BitmapButton18->SetBitmap(bild6);     break;
                case 7:     BitmapButton18->SetBitmap(bild7);     break;
                case 8:     BitmapButton18->SetBitmap(bild8);     break;
                case 9:     BitmapButton18->SetBitmap(bild9);     break;
                case 10:    BitmapButton18->SetBitmap(bild10);    break;
               }

if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=2;
        karte1Y=3;
    }
    else if(!((karte1X==2) && (karte1Y==3)))
    {
        karte2X=2;
        karte2Y=3;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton19Click(wxCommandEvent& event)
{switch (spielfeld[3][3])
               {
                case 1:     BitmapButton19->SetBitmap(bild1);     break;
                case 2:     BitmapButton19->SetBitmap(bild2);     break;
                case 3:     BitmapButton19->SetBitmap(bild3);     break;
                case 4:     BitmapButton19->SetBitmap(bild4);     break;
                case 5:     BitmapButton19->SetBitmap(bild5);     break;
                case 6:     BitmapButton19->SetBitmap(bild6);     break;
                case 7:     BitmapButton19->SetBitmap(bild7);     break;
                case 8:     BitmapButton19->SetBitmap(bild8);     break;
                case 9:     BitmapButton19->SetBitmap(bild9);     break;
                case 10:    BitmapButton19->SetBitmap(bild10);    break;
               }

if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=3;
        karte1Y=3;
    }
    else if(!((karte1X==3) && (karte1Y==3)))
    {
        karte2X=3;
        karte2Y=3;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}

void memory2Frame::OnBitmapButton20Click(wxCommandEvent& event)
{switch (spielfeld[4][3])
               {
                case 1:     BitmapButton20->SetBitmap(bild1);     break;
                case 2:     BitmapButton20->SetBitmap(bild2);     break;
                case 3:     BitmapButton20->SetBitmap(bild3);     break;
                case 4:     BitmapButton20->SetBitmap(bild4);     break;
                case 5:     BitmapButton20->SetBitmap(bild5);     break;
                case 6:     BitmapButton20->SetBitmap(bild6);     break;
                case 7:     BitmapButton20->SetBitmap(bild7);     break;
                case 8:     BitmapButton20->SetBitmap(bild8);     break;
                case 9:     BitmapButton20->SetBitmap(bild9);     break;
                case 10:    BitmapButton20->SetBitmap(bild10);    break;
               }
if (!zweitekartegeklickt)
    {
        zweitekartegeklickt=true;
        karte1X=4;
        karte1Y=3;
    }
    else if(!((karte1X==4) && (karte1Y==3)))
    {
        karte2X=4;
        karte2Y=3;
        Update();
        Sleep(1000);
        kartenverdecken();
        zweitekartegeklickt=false;
    }
}
