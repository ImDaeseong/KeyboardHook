#pragma once

class CMFCApplication1Dlg : public CDialogEx
{
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	

protected:	
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();	
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL DestroyWindow();

private:	
	HHOOK hKeyboardHook;
	static LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM  wParam, WPARAM  lParam);
	void HookStart();
	void HookEnd();	
};
