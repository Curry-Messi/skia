
// ChildView.h: CChildView 类的接口
//


#pragma once

#include "SkiaSDL.h"

// CChildView 窗口

class CChildView : public CWnd
{
// 构造
public:
	CChildView();

// 特性
public:

// 操作
public:

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

public:
	void draw1(SkCanvas* canvas);
	void draw2(SkCanvas* canvas);


public:
	SDL_Window* m_psdlWnd = NULL;
};

