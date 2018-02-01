#pragma once


class CSkiaSDL
{
public:
	CSkiaSDL();
	~CSkiaSDL();

public:
	//����λͼ
	bool CreateSurface(int w, int h);
	//�Ƿ����
	bool IsNull();
	//��ȡ����
	SDL_Surface* GetSurfacePtr();
	SkBitmap* GetSkBitmapPtr();
	//�滭λͼ
	bool DrawSurface(SDL_Surface *pSurfaceDst, const int xDst, const int yDst);

private:
	class CSkiaSDLImpl;
	CSkiaSDLImpl *m_pImpl = NULL;
};

