#include "stdafx.h"
#include "SkiaSDL.h"


class CSkiaSDL::CSkiaSDLImpl
{
	friend class CSkiaSDL;

private:
	SDL_Surface *m_psurf = NULL;
	SkBitmap m_bmpSkia;
};

CSkiaSDL::CSkiaSDL()
	:m_pImpl(new CSkiaSDLImpl())
{
}


CSkiaSDL::~CSkiaSDL()
{
	if (m_pImpl)
	{
		m_pImpl->m_bmpSkia.reset();
		if (m_pImpl->m_psurf)
			SDL_FreeSurface(m_pImpl->m_psurf);
		m_pImpl->m_psurf = NULL;
		delete m_pImpl;
	}
	m_pImpl = NULL;
}

//创建位图
bool CSkiaSDL::CreateSurface(int w, int h)
{
	bool bRet = false;
	do
	{
		if (m_pImpl->m_psurf)
			SDL_FreeSurface(m_pImpl->m_psurf);
		m_pImpl->m_psurf = NULL;
		m_pImpl->m_bmpSkia.reset();
		m_pImpl->m_bmpSkia.setInfo(SkImageInfo::Make(w, h, kN32_SkColorType, kPremul_SkAlphaType));
		m_pImpl->m_psurf = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32, SDL_PIXELFORMAT_BGRA32);
		if (NULL == m_pImpl->m_psurf)
			break;
		m_pImpl->m_bmpSkia.setPixels(m_pImpl->m_psurf->pixels);
		//m_pImpl->m_bmpSkia.eraseColor(SkColorSetARGB(255,0, 0, 255));
		
		bRet = true;
	} while (false);
	return bRet;
}

//是否可用
bool CSkiaSDL::IsNull()
{
	return (!m_pImpl || !m_pImpl->m_psurf);
}

//获取画布
SDL_Surface* CSkiaSDL::GetSurfacePtr()
{
	return m_pImpl->m_psurf;
}

SkBitmap * CSkiaSDL::GetSkBitmapPtr()
{
	return &(m_pImpl->m_bmpSkia);
}


//绘画位图
bool CSkiaSDL::DrawSurface(SDL_Surface *pSurfaceDst, const int xDst, const int yDst)
{
	if (IsNull())
	{
		return false;
	}

	SDL_Rect rcSrc, rcDst;
	rcSrc.x = rcSrc.y = 0;
	rcDst.x = xDst, rcDst.y = yDst;
	rcDst.w = rcSrc.w = GetSurfacePtr()->w;
	rcDst.h = rcSrc.h = GetSurfacePtr()->h;
	int nResult = SDL_BlitSurface(GetSurfacePtr(), &rcSrc, pSurfaceDst, &rcDst);
	return (nResult == 0);

}
