// TestAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestApp.h"
#include "TestAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestAppDlg dialog




CTestAppDlg::CTestAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestAppDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDOK, &CTestAppDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CTestAppDlg::OnBnClickedCancel)
    ON_WM_CLOSE()
    ON_BN_CLICKED(IDC_BUTTON_SETFONT, &CTestAppDlg::OnBnClickedButtonSetfont)
END_MESSAGE_MAP()


// CTestAppDlg message handlers

BOOL CTestAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

    this->SetDlgItemInt(IDC_EDIT_FONTSIZE, 12);
    this->SetDlgItemText(IDC_EDIT_FONTNAME, _T("Arial"));

    OnBnClickedButtonSetfont();

    //m_pTranslator = GetTeluguTranslator();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestAppDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestAppDlg::OnBnClickedOk()
{
    CString strTextBox;
    this->GetDlgItemText(IDC_EDIT_INPUT, strTextBox);

    CStringA strAnsi(strTextBox, strTextBox.GetLength());

	// Get the size of the translated buffer to be allocated
    void* pHint = NULL;
    int nBufLen = GetTranslatedBufferLength(GetTeluguTranslator(), strAnsi, &pHint);
	wchar_t* pszUnicode = new wchar_t[nBufLen];

	// Get the buffer
	GetTranslatedBuffer(pszUnicode, &pHint);
    
    this->SetDlgItemTextW(IDC_EDIT_OUTPUT, pszUnicode);

	delete pszUnicode;
}

void CTestAppDlg::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    OnCancel();
}

void CTestAppDlg::OnClose()
{
   // ReleaseTranslator(m_pTranslator);

    CDialog::OnClose();
}

void CTestAppDlg::OnBnClickedButtonSetfont()
{
    int nSize = this->GetDlgItemInt(IDC_EDIT_FONTSIZE, NULL);

    CString strFontName;
    this->GetDlgItemText(IDC_EDIT_FONTNAME, strFontName);

    long lfHeight = -MulDiv(nSize, GetDeviceCaps(*GetDC(), LOGPIXELSY), 72);

    CFont font;
    VERIFY(font.CreateFont(
       lfHeight,                        // nHeight
       0,                         // nWidth
       0,                         // nEscapement
       0,                         // nOrientation
       FW_NORMAL,                 // nWeight
       FALSE,                     // bItalic
       FALSE,                     // bUnderline
       0,                         // cStrikeOut
       ANSI_CHARSET,              // nCharSet
       OUT_DEFAULT_PRECIS,        // nOutPrecision
       CLIP_DEFAULT_PRECIS,       // nClipPrecision
       ANTIALIASED_QUALITY,           // nQuality
       VARIABLE_PITCH | FF_SWISS,  // nPitchAndFamily
       strFontName));                 // lpszFacename

    SendDlgItemMessage(IDC_EDIT_OUTPUT, WM_SETFONT, (WPARAM)font.GetSafeHandle(), TRUE);
}
