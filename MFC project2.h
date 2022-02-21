
// MFC project2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCproject2App:
// See MFC project2.cpp for the implementation of this class
//

class CMFCproject2App : public CWinApp
{
public:
	CMFCproject2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	DECLARE_MESSAGE_MAP()
};

extern CMFCproject2App theApp;
