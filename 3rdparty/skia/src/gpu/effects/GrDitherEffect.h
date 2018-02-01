/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * This file was autogenerated from GrDitherEffect.fp; do not modify.
 */
#ifndef GrDitherEffect_DEFINED
#define GrDitherEffect_DEFINED
#include "SkTypes.h"
#if SK_SUPPORT_GPU
#include "GrFragmentProcessor.h"
#include "GrCoordTransform.h"
#include "GrColorSpaceXform.h"
class GrDitherEffect : public GrFragmentProcessor {
public:
    int rangeType() const { return fRangeType; }

    static std::unique_ptr<GrFragmentProcessor> Make(GrPixelConfig dstConfig) {
        int rangeType;
        switch (dstConfig) {
            case kGray_8_GrPixelConfig:
            case kRGBA_8888_GrPixelConfig:
            case kBGRA_8888_GrPixelConfig:
            case kSRGBA_8888_GrPixelConfig:
            case kSBGRA_8888_GrPixelConfig:
                rangeType = 0;
                break;
            case kRGB_565_GrPixelConfig:
                rangeType = 1;
                break;
            case kRGBA_4444_GrPixelConfig:
                rangeType = 2;
                break;
            case kUnknown_GrPixelConfig:
            case kAlpha_half_GrPixelConfig:
            case kRGBA_8888_sint_GrPixelConfig:
            case kRGBA_float_GrPixelConfig:
            case kRG_float_GrPixelConfig:
            case kRGBA_half_GrPixelConfig:
            case kAlpha_8_GrPixelConfig:
                return nullptr;
        }
        return std::unique_ptr<GrFragmentProcessor>(new GrDitherEffect(rangeType));
    }
    GrDitherEffect(const GrDitherEffect& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "DitherEffect"; }

private:
    GrDitherEffect(int rangeType)
            : INHERITED(kGrDitherEffect_ClassID, kNone_OptimizationFlags), fRangeType(rangeType) {}
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    int fRangeType;
    typedef GrFragmentProcessor INHERITED;
};
#endif
#endif
