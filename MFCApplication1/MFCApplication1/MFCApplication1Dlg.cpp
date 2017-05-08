#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

LRESULT CALLBACK CMFCApplication1Dlg::LowLevelKeyboardProc(int nCode, WPARAM  wParam, WPARAM  lParam)
{
	if (nCode >= 0)
	{
		PKEYBOARDHOOKSTRUCT hookStruct = (PKEYBOARDHOOKSTRUCT)lParam;

		if ((wParam == WM_KEYDOWN) || (wParam == WM_SYSKEYDOWN))
		{
			if (hookStruct->vkCode == VK_TAB && (hookStruct->flags & LLKHF_ALTDOWN) != 0)
			{
				//<Alt>+<Tab> blocking
				return TRUE;
			}
		}
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void CMFCApplication1Dlg::HookStart()
{
	hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)LowLevelKeyboardProc, GetModuleHandle(NULL), NULL);
	if (hKeyboardHook == NULL)
	{		
		MessageBox(_T("hKeyboardHook failed"));
	}
	else
	{
		MessageBox(_T("hKeyboardHook Successed"));
	}
}

void CMFCApplication1Dlg::HookEnd()
{
	if (hKeyboardHook)
		UnhookWindowsHookEx(hKeyboardHook);
}

CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{	
	hKeyboardHook = NULL;
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	HookStart();

	return TRUE; 
}

void CMFCApplication1Dlg::OnPaint()
{
	CPaintDC dc(this);
}

BOOL CMFCApplication1Dlg::DestroyWindow()
{
	HookEnd();

	return CDialogEx::DestroyWindow();
}
