
// SnakeView.h : CSnakeView ��Ľӿ�
//

#pragma once


struct position
{
	int x; //̰ʳ��ÿ���ڵ����Ͻǵĺ�����
	int y; //̰ʳ��ÿ���ڵ����Ͻǵ�������
};


class CSnakeView : public CView
{
protected: // �������л�����
	CSnakeView();
	DECLARE_DYNCREATE(CSnakeView)

// ����
public:
	CSnakeDoc* GetDocument() const;

// ����
private:
	int  snakeLength;	//�ߵĽڵ���
	int  gameStart;     //��Ϸ��ʼ��ֹͣ״̬��1Ϊ��ʼ��0Ϊֹͣ
	int  pauseOrContinue;   //��Ϸ״̬��0Ϊ��ͣ��Ϸ��1Ϊ������Ϸ
	int  difficulty;	//��Ϸ�Ѷȼ���
	position a[200];	//�ߵ����ڵ�����Ϊ200
	position b;			//�����ߵ�ͷ���ı���
	int xfood;			//ʳ������Ͻ�����
	int yfood;			//ʳ������Ͻ�����
	CRect rect;
	int  foodOrNot;		//�Ƿ������ʳ�1Ϊ��ӣ�0Ϊ�����
	enum Move{left, up, right, down}; //�ƶ����ĸ�����ö������
	enum Move move;         //�ƶ�����
	enum Move lastMove;		//����ǰ�ƶ��ķ��������жϷ�ֹ������

	void	AliveOrDie();						//�����й�
	double	Random(double start, double end);	//�������ʳ���λ��

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSnakeView();
	void	Initialize();	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnStart();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDifficultyEasy();
	afx_msg void OnDifficultyNormal();
	afx_msg void OnDifficultyHard();
	afx_msg void OnDifficultyHarder();
	afx_msg void OnPause();
};

#ifndef _DEBUG  // SnakeView.cpp �еĵ��԰汾
inline CSnakeDoc* CSnakeView::GetDocument() const
   { return reinterpret_cast<CSnakeDoc*>(m_pDocument); }
#endif

