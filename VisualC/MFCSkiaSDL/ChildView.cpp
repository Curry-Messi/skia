
// ChildView.cpp: CChildView 类的实现
//

#include "stdafx.h"
#include "MFCSkiaSDL.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()



// CChildView 消息处理程序

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_psdlWnd = SDL_CreateWindowFrom(m_hWnd);

	return 0;
}


void CChildView::OnDestroy()
{
	CWnd::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//if (m_psdlWnd)
	//	SDL_DestroyWindow(m_psdlWnd);
}

void CChildView::draw1(SkCanvas* canvas)
{
	//canvas->drawColor(SK_ColorWHITE);

	SkPaint paint;
	paint.setStyle(SkPaint::kFill_Style);
	paint.setAntiAlias(true);
	paint.setStrokeWidth(4);
	paint.setColor(0xffFE938C);

	SkRect rect = SkRect::MakeXYWH(10, 10, 100, 160);
	canvas->drawRect(rect, paint);

	SkRRect oval;
	oval.setOval(rect);
	oval.offset(40, 80);
	paint.setColor(0xffE6B89C);
	canvas->drawRRect(oval, paint);

	paint.setColor(0xff9CAFB7);
	canvas->drawCircle(180, 50, 25, paint);

	rect.offset(80, 50);
	paint.setColor(0xff4281A4);
	paint.setStyle(SkPaint::kStroke_Style);
	canvas->drawRoundRect(rect, 10, 10, paint);
}

void CChildView::draw2(SkCanvas* canvas)
{
	canvas->translate(200, 0);
	SkPaint paint;
	SkRect rect;
	//// draw points with red.
	//paint.setARGB(255, 255, 0, 0);
	//paint.setStrokeWidth(4);
	//canvas->drawPoint(40, 30, paint);
	//canvas->drawPoint(80, 60, paint);
	//canvas->drawPoint(120, 90, paint);
	////draw a line with green.
	//paint.setARGB(255, 0, 255, 0);
	//paint.setStrokeWidth(4);
	//canvas->drawLine(160, 10, 320, 110, paint);
	////draw a rect
	//paint.setARGB(255, 255, 0, 0);
	//rect.set(25, 25, 145, 145);
	//canvas->drawRect(rect, paint);
	////draw a circle with bule.
	//paint.setARGB(255, 0, 0, 255);
	//canvas->drawCircle(80, 180, 50, paint);
	////draw text with red
	SkPaint paint1, paint2, paint3;

	paint1.setTextSize(64.0f);
	paint1.setAntiAlias(true);
	paint1.setColor(0xff4281A4);
	paint1.setStyle(SkPaint::kFill_Style);

	paint2.setTextSize(64.f);
	paint2.setAntiAlias(true);
	paint2.setColor(0xff9CAFB7);
	paint2.setStyle(SkPaint::kStroke_Style);
	paint2.setStrokeWidth(SkIntToScalar(3));

	paint3.setTextSize(64.0f);
	paint3.setAntiAlias(true);
	paint3.setColor(0xffE6B89C);
	paint3.setTextScaleX(SkFloatToScalar(1.5f));

	const char text[] = "Skia";
	canvas->drawText(text, strlen(text), 20.0f, 64.0f, paint1);
	canvas->drawText(text, strlen(text), 20.0f, 144.0f, paint2);
	canvas->drawText(text, strlen(text), 20.0f, 224.0f, paint3);
	//auto spfont = SkTypeface::MakeFromFile("simkai.ttf");
	//if (spfont)
	//{
	//	paint.setARGB(255, 255, 0, 0);
	//	paint.setTypeface(spfont);
	//	paint.setTextSize(24);
	//	canvas->drawText("HELLO!:)", 8, 200, 180, paint);
	//}
}


void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 用于绘制的设备上下文
	
	// TODO: 在此处添加消息处理程序代码
	
	// 不要为绘制消息而调用 CWnd::OnPaint()

	SDL_Surface* pWndSurface = NULL;
	pWndSurface = SDL_GetWindowSurface(m_psdlWnd);
	SDL_FillRect(pWndSurface, NULL, SDL_MapRGBA(pWndSurface->format, 255, 255, 255, 255));
	//
	CSkiaSDL sksdl;
	sksdl.CreateSurface(pWndSurface->w, pWndSurface->h);
	SkCanvas canvas(*sksdl.GetSkBitmapPtr());

	draw1(&canvas);
	//draw2(&canvas);

	sksdl.DrawSurface(pWndSurface, 0, 0);

	//提交屏幕显示
	SDL_UpdateWindowSurface(m_psdlWnd);

}


