// CWaveTransformDlg.cpp: 구현 파일
//

#include "pch.h"
#include "WaveletTransformDoc.h"
#include "WaveletTransform.h"
#include "CWaveTransformDlg.h"
#include "afxdialogex.h"

// CWaveTransformDlg 대화 상자

IMPLEMENT_DYNAMIC(CWaveTransformDlg, CDialog)

CWaveTransformDlg::CWaveTransformDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{
	m_pDoc = NULL;
}

CWaveTransformDlg::CWaveTransformDlg(CWaveletTransformDoc* pDoc, CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
{
	m_pDoc = pDoc; // Doc 클래스 참조
	m_Level = 1; // Wavelet 분해 레벨 초기화
	m_Error = 0.0f; // MSE 초기화
	m_SNR = 0.0f; // SNR 초기화
	m_FilterCheck = 0; // Filter Check 초기화
}

CWaveTransformDlg::~CWaveTransformDlg()
{
}

void CWaveTransformDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Level);
	DDX_Text(pDX, IDC_EDIT2, m_Error);
	DDX_Text(pDX, IDC_EDIT3, m_SNR);
	DDX_Radio(pDX, IDC_RADIO1, m_FilterCheck);
}


BEGIN_MESSAGE_MAP(CWaveTransformDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CWaveTransformDlg::OnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_ARRANGE, &CWaveTransformDlg::OnClickedButtonArrange)
	ON_BN_CLICKED(IDC_BUTTON_END, &CWaveTransformDlg::OnClickedButtonEnd)
END_MESSAGE_MAP()


// CWaveTransformDlg 메시지 처리기


void CWaveTransformDlg::OnClickedButtonUpdate()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_pDoc->m_Level = m_Level;

	m_pDoc->OnWaveletEncode();

	m_pDoc->OnWaveletDecode(); // 웨이브렛 역변환
	m_pDoc->OnSNR(); // 신호 대 잡음비

	UpdateData(FALSE);


}

#include "CArrangeDlg.h"
void CWaveTransformDlg::OnClickedButtonArrange()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CArrangeDlg dlg;
	dlg.m_tempImage = new unsigned char*[m_pDoc->m_Size];
	dlg.Width = m_pDoc->m_Width;
	dlg.Height = m_pDoc->m_Height;
	dlg.m_tempImage = m_pDoc->m_ArrangeImage;

	UpdateData(TRUE);

	dlg.DoModal(); // 정렬 영상을 위한 대화상자 출력

}


void CWaveTransformDlg::OnClickedButtonEnd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnOK();
}
