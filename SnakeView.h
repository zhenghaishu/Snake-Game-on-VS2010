
// SnakeView.h : CSnakeView 类的接口
//

#pragma once


struct position
{
	int x; //贪食蛇每个节点左上角的横坐标
	int y; //贪食蛇每个节点左上角的纵坐标
};


class CSnakeView : public CView
{
protected: // 仅从序列化创建
	CSnakeView();
	DECLARE_DYNCREATE(CSnakeView)

// 特性
public:
	CSnakeDoc* GetDocument() const;

// 操作
private:
	int  snakeLength;	//蛇的节点数
	int  gameStart;     //游戏开始或停止状态，1为开始，0为停止
	int  pauseOrContinue;   //游戏状态，0为暂停游戏，1为继续游戏
	int  difficulty;	//游戏难度级别
	position a[200];	//蛇的最大节点数设为200
	position b;			//辅助蛇的头结点的变量
	int xfood;			//食物的左上角坐标
	int yfood;			//食物的右上角坐标
	CRect rect;
	int  foodOrNot;		//是否添加新食物，1为添加，0为不添加
	enum Move{left, up, right, down}; //移动的四个方向，枚举类型
	enum Move move;         //移动方向
	enum Move lastMove;		//蛇先前移动的方向，用于判断防止蛇逆行

	void	AliveOrDie();						//生死判官
	double	Random(double start, double end);	//随机产生食物的位置

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CSnakeView();
	void	Initialize();	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // SnakeView.cpp 中的调试版本
inline CSnakeDoc* CSnakeView::GetDocument() const
   { return reinterpret_cast<CSnakeDoc*>(m_pDocument); }
#endif

