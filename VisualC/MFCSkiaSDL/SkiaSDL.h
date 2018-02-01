#pragma once


class CSkiaSDL
{
public:
	CSkiaSDL();
	~CSkiaSDL();

public:
	//创建位图
	bool CreateSurface(int w, int h);
	//是否可用
	bool IsNull();
	//获取画布
	SDL_Surface* GetSurfacePtr();
	SkBitmap* GetSkBitmapPtr();
	//绘画位图
	bool DrawSurface(SDL_Surface *pSurfaceDst, const int xDst, const int yDst);

private:
	class CSkiaSDLImpl;
	CSkiaSDLImpl *m_pImpl = NULL;
};

