#ifndef _PHONETICEDIT_H__14DB9384_043F_4ed7_AF18_33039CB8EB8C__
#define _PHONETICEDIT_H__14DB9384_043F_4ed7_AF18_33039CB8EB8C__

#include <ATLWin.h>
#include <AtlCtrls.h>

///////////////////////////////////////////////
/// Use REFLECT_NOTIFICATIONS() in the Parent Window Message map to 
/// let the Phonetic Edit Control handle the notifications
/// Example:
///    BEGIN_MSG_MAP(CMainDlg)
///        ...
///        REFLECT_NOTIFICATIONS()
///    END_MSG_MAP()
/////////////////////////////////////////////////
template<class T, class TBase = CEdit, class TWinTraits = CControlWinTraits>
class ATL_NO_VTABLE CPhoneticEditCtrlImpl : public CWindowImpl<T, TBase, TWinTraits>
{
public:
    DECLARE_WND_SUPERCLASS(NULL, TBase::GetClassName())

    BEGIN_MSG_MAP(CPhoneticEditCtrlImpl)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_CHAR, OnChar)
    END_MSG_MAP()

    CPhoneticEditCtrlImpl(void)
    {
    }

    virtual ~CPhoneticEditCtrlImpl(void)
    {
    }

    // Use the Existing Edit control as a Phonetic Edit Control
    CPhoneticEditCtrlImpl(HWND hEditWnd)
    {
        Attach(hEditWnd);
    }

    // If you have an Edit control that is already created (either on Dialog or
    // through the Win32 CreateWindow API use the below Attach method to let 
    // this CPhoneticEditCtrl handle its events and make it behave like a PhoneticEdit control
    BOOL Attach(HWND hEditWnd)
    {
#ifdef _DEBUG   // in Debug version ensure that the passed in handle is really an Edit control
        TCHAR szWndClassName[64] = {0};
        if(::GetClassName(hEditWnd, szWndClassName, _countof(szWndClassName)-1))
            ATLASSERT(::_tcsicmp(szWndClassName, CEdit::GetWndClassName()) == 0);
#endif
        return SubclassWindow(hEditWnd);
    }

    // Detaches a previously attached Edit Control.
    // Call this only if you want to use the Edit control for some other purpose before 
    // it is destroyed. Otherwise Framework will automatically Detach it when goes out of scope.
    HWND Detach()
    {
        return UnsubclassWindow();
    }

    LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        LRESULT lRetVal = DefWindowProc(uMsg, wParam, lParam);

        return lRetVal;
    }

    LRESULT OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        LRESULT lRetVal = DefWindowProc(uMsg, wParam, lParam);

        return lRetVal;
    }


};

class CPhoneticEditCtrl : public CPhoneticEditCtrlImpl<CPhoneticEditCtrl>
{
public:
    DECLARE_WND_SUPERCLASS(_T("WTL_PhoneticEdit"), GetWndClassName())
};

#endif // _PHONETICEDIT_H__14DB9384_043F_4ed7_AF18_33039CB8EB8C__