#pragma once
// CWaveTransformDlg 대화 상자
class CWaveletTransformDoc;

class CWaveTransformDlg : public CDialog
{
	DECLARE_DYNAMIC(CWaveTransformDlg)

public:
	CWaveTransformDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	CWaveTransformDlg(CWaveletTransformDoc* pDoc, CWnd* pParent = NULL);
	virtual ~CWaveTransformDlg();
	

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CWaveletTransformDoc* m_pDoc;
	int m_Level;
	float m_Error;
	float m_SNR;
	int m_FilterCheck;
	afx_msg void OnClickedButtonUpdate();
	afx_msg void OnClickedButtonArrange();
	afx_msg void OnClickedButtonEnd();
};
