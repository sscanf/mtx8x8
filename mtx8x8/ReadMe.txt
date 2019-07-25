========================================================================
       MICROSOFT FOUNDATION CLASS LIBRARY : mtx8x8
========================================================================


AppWizard has created this mtx8x8 application for you.  This application
not only demonstrates the basics of using the Microsoft Foundation classes
but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your mtx8x8 application.

mtx8x8.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CMtx8x8App application class.

mtx8x8.cpp
    This is the main application source file that contains the application
    class CMtx8x8App.

mtx8x8.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
	Developer Studio.

res\mtx8x8.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file mtx8x8.rc.

res\mtx8x8.rc2
    This file contains resources that are not edited by Microsoft 
	Developer Studio.  You should place all resources not
	editable by the resource editor in this file.

mtx8x8.clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

/////////////////////////////////////////////////////////////////////////////

For the main frame window:

MainFrm.h, MainFrm.cpp
    These files contain the frame class CMainFrame, which is derived from
    CFrameWnd and controls all SDI frame features.

res\Toolbar.bmp
    This bitmap file is used to create tiled images for the toolbar.
    The initial toolbar and status bar are constructed in the
    CMainFrame class.  Edit this toolbar bitmap along with the
    array in MainFrm.cpp to add more toolbar buttons.

/////////////////////////////////////////////////////////////////////////////

AppWizard creates one document type and one view:

mtx8x8Doc.h, mtx8x8Doc.cpp - the document
    These files contain your CMtx8x8Doc class.  Edit these files to
    add your special document data and to implement file saving and loading
    (via CMtx8x8Doc::Serialize).

mtx8x8View.h, mtx8x8View.cpp - the view of the document
    These files contain your CMtx8x8View class.
    CMtx8x8View objects are used to view CMtx8x8Doc objects.



/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named mtx8x8.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Developer Studio reads and updates this file.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, and your application is 
in a language other than the operating system's current language, you
will need to copy the corresponding localized resources MFC40XXX.DLL
from the Microsoft Visual C++ CD-ROM onto the system or system32 directory,
and rename it to be MFCLOC.DLL.  ("XXX" stands for the language abbreviation.
For example, MFC40DEU.DLL contains resources translated to German.)  If you
don't do this, some of the UI elements of your application will remain in the
language of the operating system.

/////////////////////////////////////////////////////////////////////////////
