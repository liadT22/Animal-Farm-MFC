
// MFC project2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFC project2.h"
#include "MFC project2Dlg.h"
#include "afxdialogex.h"
#include <atlimage.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define STARTING_MONEY 100
#define ORANGE_WORTH 50
#define COW_WORTH 100
#define SHEEP_WORTH 80
#define FISH_WORTH 50



// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCproject2Dlg dialog



CMFCproject2Dlg::CMFCproject2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT2_DIALOG, pParent)
	, _moneyText(50)
	, _selectedAnimal(_T(""))
	, _selectedWhatToDo(_T("Move"))
	, _animalIsPressed(0)
	, _IndexPressedAnimal(-1)
	, _isSomeonePeeing(0)
	, _isSomeoneGivingMilk(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCproject2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, ID_Money, _moneyText);
	DDX_Control(pDX, IDC_COMBO1, _animalTypeList);
	DDX_Control(pDX, IDC_COMBO2, _whatToDoList);
	DDX_Control(pDX, IDC_PeeText, _PeeText);
	DDX_Control(pDX, IDC_TextCow, _TextMilk);
}

BEGIN_MESSAGE_MAP(CMFCproject2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCproject2Dlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCproject2Dlg::OnCbnSelchangeCombo1)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCproject2Dlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCproject2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCproject2Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCproject2Dlg message handlers

BOOL CMFCproject2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCproject2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCproject2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CPoint a;
		CPen milkPen(PS_SOLID, 8, RGB(255, 255, 255));
		CPen blackPen(PS_SOLID, 2, RGB(0, 0, 0));
		CPen peePen(PS_SOLID, 6, RGB(255, 255, 0));
		CBrush brownBrush(RGB(151, 101, 57));
		CBrush greenBrush(RGB(50, 150, 0));
		CBrush blueBrush(RGB(0, 120, 184));
		CBrush orangeBrush(RGB(255, 165, 0));
		CBrush sheep0Brush(RGB(120, 120, 120));
		CBrush sheep1Brush(RGB(160, 160, 160));
		CBrush sheep2Brush(RGB(200, 200, 200));
		CBrush sheep3Brush(RGB(240, 240, 240));
		CBrush cowBrush(RGB(165, 42, 42));
		CBrush fishBrush(RGB(255, 215, 0));
		CPen* oldPen = dc.SelectObject(&blackPen); //saving default pen with a ptr
		CBrush* oldBrush = dc.SelectObject(&brownBrush); //saving default brush with a ptr
		dc.Rectangle(945, 90, 1300, 430); // board for orange
		dc.SelectObject(&greenBrush);
		dc.Rectangle(20, 20, 350, 250);//board for Cow
		dc.Rectangle(20, 270, 350, 500);//board for Sheep
		dc.SelectObject(&blueBrush);
		dc.Rectangle(370, 20, 700, 250);//Board for fish
		dc.SelectObject(&orangeBrush);
		this->_orange.draw(&dc);//Drawing all oranges
		for (int i = 0; i < _animalArr.GetSize(); i++) {
			_animalArr[i]->draw(&dc);
		}
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCproject2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCproject2Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	int index;
	CPoint animalPos;
	bool didSomethingChanged = 0;
	index = _orange.isOnOrange(point);
	if (index != -1) {
		if (_orange.getIsOrange(index)) {
			didSomethingChanged = 1;
			this->_moneyText += ORANGE_WORTH;
			_orange.orangeIsPressed(index);
		}
	}
	if (_selectedWhatToDo == CString("Move")) {
		FindPressedAnimal(point);
	}
	if (_selectedWhatToDo == CString("Sell")) {
		FindPressedAnimal(point);
		this->SellAnimal();
		if (_isSomeonePeeing) {
			_isSomeonePeeing = 0;
			_PeeText.ShowWindow(SW_HIDE);
		}
		if (_isSomeoneGivingMilk) {
			_isSomeoneGivingMilk = 0;
			_TextMilk.ShowWindow(SW_HIDE);
		}
		if (this->_animalIsPressed == 1) {
			didSomethingChanged = 1;
			this->_animalIsPressed = 0;
		}
	}
	if (_selectedWhatToDo == CString("Play")) {
		FindPressedAnimal(point);
		if (this->_animalIsPressed == 1) {
			this->_animalArr[this->_IndexPressedAnimal]->play();
			if (this->_animalArr[this->_IndexPressedAnimal]->GetId() == 1)//cow
			{
				_TextMilk.ShowWindow(SW_SHOW);
				_isSomeoneGivingMilk = 1;
			}
			if (this->_animalArr[this->_IndexPressedAnimal]->GetId() == 2)//gold fish
			{
				_PeeText.ShowWindow(SW_SHOW);
				_isSomeonePeeing = 1;
			}
			didSomethingChanged = 1;
			this->_animalIsPressed = 0;
		}
	}
		if (didSomethingChanged == 1) {
			Invalidate();
			UpdateData(false);
		}
		CDialogEx::OnLButtonDown(nFlags, point);
}

void CMFCproject2Dlg::OnBnClickedButton1()
{
	bool didSomethingChanged = 0;
	if (_selectedAnimal == CString("Cow")) {
		if (_moneyText < COW_WORTH) {
			MessageBox(CString("You need to work more!"), CString("Liad and Shimon's project"), MB_OK | MB_ICONEXCLAMATION);
		}
		else {
			didSomethingChanged = 1;
			this->_moneyText -= COW_WORTH;
			_animalArr.Add(new Cow);
		}
	}
	if (_selectedAnimal == CString("Sheep")) {
		if (_moneyText < SHEEP_WORTH) {
			MessageBox(CString("You need to work more!"), CString("Liad and Shimon's project"), MB_OK | MB_ICONEXCLAMATION);
		}
		else {
			didSomethingChanged = 1;
			this->_moneyText -= SHEEP_WORTH;
			_animalArr.Add(new Sheep);
		}
	}
	if (_selectedAnimal == CString("Gold fish")) {
		if (_moneyText < FISH_WORTH) {
			MessageBox(CString("You need to work more!"), CString("Liad and Shimon's project"), MB_OK | MB_ICONEXCLAMATION);
		}
		else {
			didSomethingChanged = 1;
			this->_moneyText -= FISH_WORTH;
			_animalArr.Add(new GoldFish);
		}
	}
	if (didSomethingChanged == 1) {
		_animalArr[_animalArr.GetSize() - 1]->makeNoise();
		UpdateData(false);
		Invalidate();
	}
}

void CMFCproject2Dlg::FindPressedAnimal(CPoint point)
{
	int i;
	CPoint animalPos;
	for (i = _animalArr.GetSize()-1; i >= 0; i--) {
		animalPos = _animalArr[i]->getCord();
		if ((point.x >= animalPos.x && point.y >= animalPos.y) && (point.x <= animalPos.x + 100 && point.y <= animalPos.y + 50)) {
			this->_animalIsPressed = 1;
			this->_IndexPressedAnimal = i;
			return;
		}
	}
}

void CMFCproject2Dlg::OnCbnSelchangeCombo1()
{
	int comboBoxSelectedItem = _animalTypeList.GetCurSel();
	if (comboBoxSelectedItem != LB_ERR) {
		_animalTypeList.GetLBText(comboBoxSelectedItem, _selectedAnimal);
	}
}

void CMFCproject2Dlg::SellAnimal()
{
	if (this->_animalIsPressed) {
		if (_animalArr.GetSize() > 0) {
			_animalArr[_IndexPressedAnimal] = _animalArr[_animalArr.GetSize() - 1];
			_animalArr.SetSize(_animalArr.GetSize() - 1, -1);
			this->_moneyText += 50;
		}
	}
}


void CMFCproject2Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	bool didSomethingChanged = 0;
	if (this->_animalIsPressed) {
		CPoint topLeft, bottomRight;
		topLeft = _animalArr[this->_IndexPressedAnimal]->getAllowedPosTopLeft();
		bottomRight = _animalArr[this->_IndexPressedAnimal]->getAllowedPosBottomRight();
		_animalIsPressed = 0;
		if ((point.x >= topLeft.x && point.y >= topLeft.y) && (point.x <= bottomRight.x && point.y <= bottomRight.y)) {
			didSomethingChanged = 1;
			point.x -= 50;
			point.y -= 25;
			_animalArr[this->_IndexPressedAnimal]->setCord(point);
		}
		else {	
			if (_animalArr[this->_IndexPressedAnimal]->GetId() == 0) {
			MessageBox(CString("The sheep will run away\nif you put it there!"), CString("Liad and Shimon's project"), MB_OK | MB_ICONEXCLAMATION);
			}
			else if (_animalArr[this->_IndexPressedAnimal]->GetId() == 1) {
				MessageBox(CString("The cow will run away\nif you put it there!"), CString("Liad and Shimon's project"), MB_OK | MB_ICONEXCLAMATION);
			}
			else if (_animalArr[this->_IndexPressedAnimal]->GetId() == 2) {
				MessageBox(CString("The fish will die\nif you put it there!"), CString("Liad and Shimon's project"), MB_OK | MB_ICONEXCLAMATION);
			}
		}
	}
	if (didSomethingChanged) {
		UpdateData(false);
		Invalidate();
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCproject2Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	bool didSomethingChanged = 0;
	if (this->_animalIsPressed) {
		didSomethingChanged = 1;
		point.x -= 50;
		point.y -= 25;
		_animalArr[this->_IndexPressedAnimal]->setCord(point);
	}
	if (didSomethingChanged) {
		UpdateData(false);
		Invalidate();
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCproject2Dlg::OnCbnSelchangeCombo2()
{
	int comboBoxSelectedItem = _whatToDoList.GetCurSel();
	if (comboBoxSelectedItem != LB_ERR) {
		_whatToDoList.GetLBText(comboBoxSelectedItem, _selectedWhatToDo);
	}
}


void CMFCproject2Dlg::OnBnClickedButton2()
{
	CFileDialog dlg(FALSE, _T("._animalArr"), NULL, 0, _T("Animal (*._animalArr)|*._animalArr|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		_animalArr.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


	void CMFCproject2Dlg::OnBnClickedButton3()
	{
		CFileDialog dlg(TRUE, _T("._animalArr"), NULL, 0, _T("Animal (*._animalArr)|*._animalArr|All Files (*.*)|*.*||"));
		CString filename;
		if (dlg.DoModal() == IDOK)
		{
			filename = dlg.GetPathName(); // return full path and filename
			CFile file(filename, CFile::modeRead);
			CArchive ar(&file, CArchive::load);
			_animalArr.Serialize(ar);
			ar.Close();
			file.Close();
			Invalidate();
		}
	}

