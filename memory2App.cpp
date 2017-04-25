/***************************************************************
 * Name:      memory2App.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2017-04-24
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "memory2App.h"

//(*AppHeaders
#include "memory2Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(memory2App);

bool memory2App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	memory2Frame* Frame = new memory2Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
