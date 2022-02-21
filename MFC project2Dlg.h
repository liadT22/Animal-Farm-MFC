
// MFC project2Dlg.h : header file
//

#pragma once
#include"Orange.h"
#include <iostream>
#include <mmsystem.h>
#include"Animal.h"
#include "Sheep.h"
#include"Cow.h"
#include"GoldFish.h"
#include"Mammal.h"
#include"Fish.h"


using namespace std;

// CMFCproject2Dlg dialog
class CMFCproject2Dlg : public CDialogEx
{
	// Construction
public:
	CMFCproject2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	Orange _orange;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	void FindPressedAnimal(CPoint point);
	int _moneyText;
	CString _selectedAnimal;
	CString _selectedWhatToDo;
	afx_msg void OnCbnSelchangeCombo1();
	void SellAnimal();
	CComboBox _animalTypeList;
	bool _animalIsPressed;
	bool _isSomeonePeeing;
	bool _isSomeoneGivingMilk;
	int _IndexPressedAnimal;
	CTypedPtrArray<CObArray, Animal*>_animalArr;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CComboBox _whatToDoList;
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CStatic _PeeText;
	CStatic _TextMilk;
};
