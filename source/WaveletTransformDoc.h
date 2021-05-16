
// WaveletTransformDoc.h: CWaveletTransformDoc 클래스의 인터페이스
//


#pragma once

#include "CWaveTransformDlg.h" 
class CWaveletTransformDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CWaveletTransformDoc() noexcept;
	DECLARE_DYNCREATE(CWaveletTransformDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CWaveletTransformDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	BOOL OnOpenDocument(LPCTSTR lpszPathName);
	int m_Height;
	int m_Width;
	int m_Size;
	unsigned char* m_InputImage;
	unsigned char* m_OutputImage;
	void OnWaveletTransform();
	CWaveTransformDlg* pDlg;
	void OnWaveletEncode();
	double** m_tempInput;
	double** m_tempOutput;
	unsigned char** m_ArrangeImage;
	int m_Level;
	int m_FilterTap;
	double* m_FilterH0;
	double* m_FilterH1;
	double* m_FilterG0;
	double* m_FilterG1;
	double* OnDownSampling(double* m_Target, int size);
	double* OnConvolution(double* m_Target, double* m_Filter, int size, int mode);
	void OnFilterGen(double* m_H0, double* m_H1, double* m_G0, double* m_G1);
	unsigned char** OnMem2DAllocUnsigned(int height, int width);
	double** OnMem2DAllocdouble(int height, int width);
	double** OnScale(double** m_Target, int height, int width);
	void OnFilterTapGen();
	void OnWaveletDecode();
	double* OnUpSampling(double* m_Target, int size);
	void OnSNR();
};
