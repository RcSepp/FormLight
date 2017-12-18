#pragma once
#ifndef __OPENGL_H
#define __OPENGL_H

#include <string>

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;
typedef char GLchar;

#ifdef _WIN64
//typedef unsigned __int64 size_t;
typedef __int64          ptrdiff_t;
//typedef __int64          intptr_t;
#else
//typedef unsigned long int     size_t;
typedef long int              ptrdiff_t;
//typedef long int              intptr_t;
#endif
typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;

#undef None
#undef True
#undef False
#undef Bool
#undef Always


#define OPENGL_ENUM_START(enum_name) struct enum_name { private: unsigned int e; public: enum_name() : e(0) {} enum_name(unsigned int e) : e(e) {} operator unsigned int() const { return e; }
#define OPENGL_ENUM_END };

OPENGL_ENUM_START(AccumOp)
	static const AccumOp Accum;
	static const AccumOp Load;
	static const AccumOp Return;
	static const AccumOp Mult;
	static const AccumOp Add;
OPENGL_ENUM_END

OPENGL_ENUM_START(ActiveAttribType)
	static const ActiveAttribType None;
	static const ActiveAttribType Int;
	static const ActiveAttribType UnsignedInt;
	static const ActiveAttribType Float;
	static const ActiveAttribType Double;
	static const ActiveAttribType FloatVec2;
	static const ActiveAttribType FloatVec3;
	static const ActiveAttribType FloatVec4;
	static const ActiveAttribType IntVec2;
	static const ActiveAttribType IntVec3;
	static const ActiveAttribType IntVec4;
	static const ActiveAttribType FloatMat2;
	static const ActiveAttribType FloatMat3;
	static const ActiveAttribType FloatMat4;
	static const ActiveAttribType FloatMat2x3;
	static const ActiveAttribType FloatMat2x4;
	static const ActiveAttribType FloatMat3x2;
	static const ActiveAttribType FloatMat3x4;
	static const ActiveAttribType FloatMat4x2;
	static const ActiveAttribType FloatMat4x3;
	static const ActiveAttribType UnsignedIntVec2;
	static const ActiveAttribType UnsignedIntVec3;
	static const ActiveAttribType UnsignedIntVec4;
	static const ActiveAttribType DoubleMat2;
	static const ActiveAttribType DoubleMat3;
	static const ActiveAttribType DoubleMat4;
	static const ActiveAttribType DoubleMat2x3;
	static const ActiveAttribType DoubleMat2x4;
	static const ActiveAttribType DoubleMat3x2;
	static const ActiveAttribType DoubleMat3x4;
	static const ActiveAttribType DoubleMat4x2;
	static const ActiveAttribType DoubleMat4x3;
	static const ActiveAttribType DoubleVec2;
	static const ActiveAttribType DoubleVec3;
	static const ActiveAttribType DoubleVec4;
OPENGL_ENUM_END

OPENGL_ENUM_START(ActiveSubroutineUniformParameter)
	static const ActiveSubroutineUniformParameter UniformSize;
	static const ActiveSubroutineUniformParameter UniformNameLength;
	static const ActiveSubroutineUniformParameter NumCompatibleSubroutines;
	static const ActiveSubroutineUniformParameter CompatibleSubroutines;
OPENGL_ENUM_END

OPENGL_ENUM_START(ActiveUniformBlockParameter)
	static const ActiveUniformBlockParameter UniformBlockReferencedByTessControlShader;
	static const ActiveUniformBlockParameter UniformBlockReferencedByTessEvaluationShader;
	static const ActiveUniformBlockParameter UniformBlockBinding;
	static const ActiveUniformBlockParameter UniformBlockDataSize;
	static const ActiveUniformBlockParameter UniformBlockNameLength;
	static const ActiveUniformBlockParameter UniformBlockActiveUniforms;
	static const ActiveUniformBlockParameter UniformBlockActiveUniformIndices;
	static const ActiveUniformBlockParameter UniformBlockReferencedByVertexShader;
	static const ActiveUniformBlockParameter UniformBlockReferencedByGeometryShader;
	static const ActiveUniformBlockParameter UniformBlockReferencedByFragmentShader;
	static const ActiveUniformBlockParameter UniformBlockReferencedByComputeShader;
OPENGL_ENUM_END

OPENGL_ENUM_START(ActiveUniformParameter)
	static const ActiveUniformParameter UniformType;
	static const ActiveUniformParameter UniformSize;
	static const ActiveUniformParameter UniformNameLength;
	static const ActiveUniformParameter UniformBlockIndex;
	static const ActiveUniformParameter UniformOffset;
	static const ActiveUniformParameter UniformArrayStride;
	static const ActiveUniformParameter UniformMatrixStride;
	static const ActiveUniformParameter UniformIsRowMajor;
	static const ActiveUniformParameter UniformAtomicCounterBufferIndex;
OPENGL_ENUM_END

OPENGL_ENUM_START(ActiveUniformType)
	static const ActiveUniformType Int;
	static const ActiveUniformType UnsignedInt;
	static const ActiveUniformType Float;
	static const ActiveUniformType Double;
	static const ActiveUniformType FloatVec2;
	static const ActiveUniformType FloatVec3;
	static const ActiveUniformType FloatVec4;
	static const ActiveUniformType IntVec2;
	static const ActiveUniformType IntVec3;
	static const ActiveUniformType IntVec4;
	static const ActiveUniformType Bool;
	static const ActiveUniformType BoolVec2;
	static const ActiveUniformType BoolVec3;
	static const ActiveUniformType BoolVec4;
	static const ActiveUniformType FloatMat2;
	static const ActiveUniformType FloatMat3;
	static const ActiveUniformType FloatMat4;
	static const ActiveUniformType Sampler1D;
	static const ActiveUniformType Sampler2D;
	static const ActiveUniformType Sampler3D;
	static const ActiveUniformType SamplerCube;
	static const ActiveUniformType Sampler1DShadow;
	static const ActiveUniformType Sampler2DShadow;
	static const ActiveUniformType Sampler2DRect;
	static const ActiveUniformType Sampler2DRectShadow;
	static const ActiveUniformType FloatMat2x3;
	static const ActiveUniformType FloatMat2x4;
	static const ActiveUniformType FloatMat3x2;
	static const ActiveUniformType FloatMat3x4;
	static const ActiveUniformType FloatMat4x2;
	static const ActiveUniformType FloatMat4x3;
	static const ActiveUniformType Sampler1DArray;
	static const ActiveUniformType Sampler2DArray;
	static const ActiveUniformType SamplerBuffer;
	static const ActiveUniformType Sampler1DArrayShadow;
	static const ActiveUniformType Sampler2DArrayShadow;
	static const ActiveUniformType SamplerCubeShadow;
	static const ActiveUniformType UnsignedIntVec2;
	static const ActiveUniformType UnsignedIntVec3;
	static const ActiveUniformType UnsignedIntVec4;
	static const ActiveUniformType IntSampler1D;
	static const ActiveUniformType IntSampler2D;
	static const ActiveUniformType IntSampler3D;
	static const ActiveUniformType IntSamplerCube;
	static const ActiveUniformType IntSampler2DRect;
	static const ActiveUniformType IntSampler1DArray;
	static const ActiveUniformType IntSampler2DArray;
	static const ActiveUniformType IntSamplerBuffer;
	static const ActiveUniformType UnsignedIntSampler1D;
	static const ActiveUniformType UnsignedIntSampler2D;
	static const ActiveUniformType UnsignedIntSampler3D;
	static const ActiveUniformType UnsignedIntSamplerCube;
	static const ActiveUniformType UnsignedIntSampler2DRect;
	static const ActiveUniformType UnsignedIntSampler1DArray;
	static const ActiveUniformType UnsignedIntSampler2DArray;
	static const ActiveUniformType UnsignedIntSamplerBuffer;
	static const ActiveUniformType DoubleVec2;
	static const ActiveUniformType DoubleVec3;
	static const ActiveUniformType DoubleVec4;
	static const ActiveUniformType SamplerCubeMapArray;
	static const ActiveUniformType SamplerCubeMapArrayShadow;
	static const ActiveUniformType IntSamplerCubeMapArray;
	static const ActiveUniformType UnsignedIntSamplerCubeMapArray;
	static const ActiveUniformType Image1D;
	static const ActiveUniformType Image2D;
	static const ActiveUniformType Image3D;
	static const ActiveUniformType Image2DRect;
	static const ActiveUniformType ImageCube;
	static const ActiveUniformType ImageBuffer;
	static const ActiveUniformType Image1DArray;
	static const ActiveUniformType Image2DArray;
	static const ActiveUniformType ImageCubeMapArray;
	static const ActiveUniformType Image2DMultisample;
	static const ActiveUniformType Image2DMultisampleArray;
	static const ActiveUniformType IntImage1D;
	static const ActiveUniformType IntImage2D;
	static const ActiveUniformType IntImage3D;
	static const ActiveUniformType IntImage2DRect;
	static const ActiveUniformType IntImageCube;
	static const ActiveUniformType IntImageBuffer;
	static const ActiveUniformType IntImage1DArray;
	static const ActiveUniformType IntImage2DArray;
	static const ActiveUniformType IntImageCubeMapArray;
	static const ActiveUniformType IntImage2DMultisample;
	static const ActiveUniformType IntImage2DMultisampleArray;
	static const ActiveUniformType UnsignedIntImage1D;
	static const ActiveUniformType UnsignedIntImage2D;
	static const ActiveUniformType UnsignedIntImage3D;
	static const ActiveUniformType UnsignedIntImage2DRect;
	static const ActiveUniformType UnsignedIntImageCube;
	static const ActiveUniformType UnsignedIntImageBuffer;
	static const ActiveUniformType UnsignedIntImage1DArray;
	static const ActiveUniformType UnsignedIntImage2DArray;
	static const ActiveUniformType UnsignedIntImageCubeMapArray;
	static const ActiveUniformType UnsignedIntImage2DMultisample;
	static const ActiveUniformType UnsignedIntImage2DMultisampleArray;
	static const ActiveUniformType Sampler2DMultisample;
	static const ActiveUniformType IntSampler2DMultisample;
	static const ActiveUniformType UnsignedIntSampler2DMultisample;
	static const ActiveUniformType Sampler2DMultisampleArray;
	static const ActiveUniformType IntSampler2DMultisampleArray;
	static const ActiveUniformType UnsignedIntSampler2DMultisampleArray;
	static const ActiveUniformType UnsignedIntAtomicCounter;
OPENGL_ENUM_END

OPENGL_ENUM_START(All)
	static const All False;
	static const All LayoutDefaultIntel;
	static const All NoError;
	static const All None;
	static const All NoneOes;
	static const All Zero;
	static const All ClosePathNv;
	static const All Points;
	static const All PerfquerySingleContextIntel;
	static const All ClientPixelStoreBit;
	static const All ContextCoreProfileBit;
	static const All ContextFlagForwardCompatibleBit;
	static const All CurrentBit;
	static const All Gl2XBitAti;
	static const All PerfqueryGlobalContextIntel;
	static const All QueryDepthPassEventBitAmd;
	static const All RedBitAti;
	static const All SyncFlushCommandsBit;
	static const All TextureDeformationBitSgix;
	static const All TextureStorageSparseBitAmd;
	static const All VertexAttribArrayBarrierBit;
	static const All VertexAttribArrayBarrierBitExt;
	static const All VertexShaderBit;
	static const All VertexShaderBitExt;
	static const All ClientVertexArrayBit;
	static const All CompBitAti;
	static const All ContextCompatibilityProfileBit;
	static const All ContextFlagDebugBit;
	static const All ContextFlagDebugBitKhr;
	static const All ElementArrayBarrierBit;
	static const All ElementArrayBarrierBitExt;
	static const All FragmentShaderBit;
	static const All FragmentShaderBitExt;
	static const All GeometryDeformationBitSgix;
	static const All Gl4XBitAti;
	static const All GreenBitAti;
	static const All PointBit;
	static const All QueryDepthFailEventBitAmd;
	static const All BlueBitAti;
	static const All ContextFlagRobustAccessBit;
	static const All ContextFlagRobustAccessBitArb;
	static const All GeometryShaderBit;
	static const All GeometryShaderBitExt;
	static const All Gl8XBitAti;
	static const All GlUniformBarrierBit;
	static const All LineBit;
	static const All NegateBitAti;
	static const All QueryStencilFailEventBitAmd;
	static const All UniformBarrierBit;
	static const All UniformBarrierBitExt;
	static const All Vertex23BitPgi;
	static const All BiasBitAti;
	static const All GlTextureFetchBarrierBit;
	static const All HalfBitAti;
	static const All PolygonBit;
	static const All QueryDepthBoundsFailEventBitAmd;
	static const All TessControlShaderBit;
	static const All TessControlShaderBitExt;
	static const All TextureFetchBarrierBit;
	static const All TextureFetchBarrierBitExt;
	static const All Vertex4BitPgi;
	static const All PolygonStippleBit;
	static const All QuarterBitAti;
	static const All ShaderGlobalAccessBarrierBitNv;
	static const All TessEvaluationShaderBit;
	static const All TessEvaluationShaderBitExt;
	static const All ComputeShaderBit;
	static const All EighthBitAti;
	static const All GlShaderImageAccessBarrierBit;
	static const All PixelModeBit;
	static const All ShaderImageAccessBarrierBit;
	static const All ShaderImageAccessBarrierBitExt;
	static const All CommandBarrierBit;
	static const All CommandBarrierBitExt;
	static const All LightingBit;
	static const All SaturateBitAti;
	static const All FogBit;
	static const All PixelBufferBarrierBit;
	static const All PixelBufferBarrierBitExt;
	static const All DepthBufferBit;
	static const All TextureUpdateBarrierBit;
	static const All TextureUpdateBarrierBitExt;
	static const All AccumBufferBit;
	static const All BufferUpdateBarrierBit;
	static const All BufferUpdateBarrierBitExt;
	static const All FramebufferBarrierBit;
	static const All FramebufferBarrierBitExt;
	static const All GlFramebufferBarrierBit;
	static const All StencilBufferBit;
	static const All TransformFeedbackBarrierBit;
	static const All TransformFeedbackBarrierBitExt;
	static const All ViewportBit;
	static const All AtomicCounterBarrierBit;
	static const All AtomicCounterBarrierBitExt;
	static const All GlAtomicCounterBarrierBit;
	static const All TransformBit;
	static const All EnableBit;
	static const All ShaderStorageBarrierBit;
	static const All ClientMappedBufferBarrierBit;
	static const All ColorBufferBit;
	static const All CoverageBufferBitNv;
	static const All HintBit;
	static const All QueryBufferBarrierBit;
	static const All Lines;
	static const All MapReadBit;
	static const All MapReadBitExt;
	static const All RestartSun;
	static const All Color3BitPgi;
	static const All EvalBit;
	static const All FontXMinBoundsBitNv;
	static const All LineLoop;
	static const All MapWriteBit;
	static const All MapWriteBitExt;
	static const All ReplaceMiddleSun;
	static const All Color4BitPgi;
	static const All FontYMinBoundsBitNv;
	static const All ListBit;
	static const All LineStrip;
	static const All ReplaceOldestSun;
	static const All MapInvalidateRangeBit;
	static const All MapInvalidateRangeBitExt;
	static const All Triangles;
	static const All EdgeflagBitPgi;
	static const All FontXMaxBoundsBitNv;
	static const All TextureBit;
	static const All TriangleStrip;
	static const All TriangleFan;
	static const All Quads;
	static const All QuadsExt;
	static const All MapInvalidateBufferBit;
	static const All MapInvalidateBufferBitExt;
	static const All QuadStrip;
	static const All FontYMaxBoundsBitNv;
	static const All IndexBitPgi;
	static const All ScissorBit;
	static const All Polygon;
	static const All LinesAdjacency;
	static const All LinesAdjacencyArb;
	static const All LinesAdjacencyExt;
	static const All LineStripAdjacency;
	static const All LineStripAdjacencyArb;
	static const All LineStripAdjacencyExt;
	static const All TrianglesAdjacency;
	static const All TrianglesAdjacencyArb;
	static const All TrianglesAdjacencyExt;
	static const All TriangleStripAdjacency;
	static const All TriangleStripAdjacencyArb;
	static const All TriangleStripAdjacencyExt;
	static const All Patches;
	static const All PatchesExt;
	static const All MapFlushExplicitBit;
	static const All MapFlushExplicitBitExt;
	static const All FontUnitsPerEmBitNv;
	static const All MatAmbientBitPgi;
	static const All MapUnsynchronizedBit;
	static const All MapUnsynchronizedBitExt;
	static const All FontAscenderBitNv;
	static const All MatAmbientAndDiffuseBitPgi;
	static const All MapPersistentBit;
	static const All FontDescenderBitNv;
	static const All MatDiffuseBitPgi;
	static const All MapCoherentBit;
	static const All FontHeightBitNv;
	static const All MatEmissionBitPgi;
	static const All BoldBitNv;
	static const All GlyphWidthBitNv;
	static const All Accum;
	static const All DynamicStorageBit;
	static const All FontMaxAdvanceWidthBitNv;
	static const All MatColorIndexesBitPgi;
	static const All Load;
	static const All Return;
	static const All Mult;
	static const All Add;
	static const All GlyphHeightBitNv;
	static const All ItalicBitNv;
	static const All MoveToNv;
	static const All ClientStorageBit;
	static const All Never;
	static const All FontMaxAdvanceHeightBitNv;
	static const All MatShininessBitPgi;
	static const All Less;
	static const All Equal;
	static const All Lequal;
	static const All Greater;
	static const All Notequal;
	static const All Gequal;
	static const All Always;
	static const All RelativeMoveToNv;
	static const All SrcColor;
	static const All OneMinusSrcColor;
	static const All SrcAlpha;
	static const All OneMinusSrcAlpha;
	static const All DstAlpha;
	static const All OneMinusDstAlpha;
	static const All DstColor;
	static const All OneMinusDstColor;
	static const All SrcAlphaSaturate;
	static const All GlyphHorizontalBearingXBitNv;
	static const All LineToNv;
	static const All FrontLeft;
	static const All SparseStorageBitArb;
	static const All FontUnderlinePositionBitNv;
	static const All MatSpecularBitPgi;
	static const All FrontRight;
	static const All BackLeft;
	static const All BackRight;
	static const All Front;
	static const All Back;
	static const All Left;
	static const All Right;
	static const All FrontAndBack;
	static const All Aux0;
	static const All Aux1;
	static const All Aux2;
	static const All Aux3;
	static const All RelativeLineToNv;
	static const All InvalidEnum;
	static const All InvalidValue;
	static const All InvalidOperation;
	static const All StackOverflow;
	static const All StackOverflowKhr;
	static const All StackUnderflow;
	static const All StackUnderflowKhr;
	static const All OutOfMemory;
	static const All InvalidFramebufferOperation;
	static const All InvalidFramebufferOperationExt;
	static const All InvalidFramebufferOperationOes;
	static const All ContextLost;
	static const All ContextLostKhr;
	static const All HorizontalLineToNv;
	static const All Gl2D;
	static const All Gl3D;
	static const All Gl3DColor;
	static const All Gl3DColorTexture;
	static const All Gl4DColorTexture;
	static const All RelativeHorizontalLineToNv;
	static const All PassThroughToken;
	static const All PointToken;
	static const All LineToken;
	static const All PolygonToken;
	static const All BitmapToken;
	static const All DrawPixelToken;
	static const All CopyPixelToken;
	static const All LineResetToken;
	static const All GlyphHorizontalBearingYBitNv;
	static const All VerticalLineToNv;
	static const All Exp;
	static const All FontUnderlineThicknessBitNv;
	static const All NormalBitPgi;
	static const All Exp2;
	static const All RelativeVerticalLineToNv;
	static const All Cw;
	static const All Ccw;
	static const All QuadraticCurveToNv;
	static const All Coeff;
	static const All Order;
	static const All Domain;
	static const All RelativeQuadraticCurveToNv;
	static const All CurrentColor;
	static const All CurrentIndex;
	static const All CurrentNormal;
	static const All CurrentTextureCoords;
	static const All CurrentRasterColor;
	static const All CurrentRasterIndex;
	static const All CurrentRasterTextureCoords;
	static const All CurrentRasterPosition;
	static const All CurrentRasterPositionValid;
	static const All CurrentRasterDistance;
	static const All PointSmooth;
	static const All PointSize;
	static const All PointSizeRange;
	static const All SmoothPointSizeRange;
	static const All PointSizeGranularity;
	static const All SmoothPointSizeGranularity;
	static const All LineSmooth;
	static const All LineWidth;
	static const All LineWidthRange;
	static const All SmoothLineWidthRange;
	static const All LineWidthGranularity;
	static const All SmoothLineWidthGranularity;
	static const All LineStipple;
	static const All LineStipplePattern;
	static const All LineStippleRepeat;
	static const All ListMode;
	static const All MaxListNesting;
	static const All ListBase;
	static const All ListIndex;
	static const All PolygonMode;
	static const All PolygonSmooth;
	static const All PolygonStipple;
	static const All EdgeFlag;
	static const All CullFace;
	static const All CullFaceMode;
	static const All FrontFace;
	static const All Lighting;
	static const All LightModelLocalViewer;
	static const All LightModelTwoSide;
	static const All LightModelAmbient;
	static const All ShadeModel;
	static const All ColorMaterialFace;
	static const All ColorMaterialParameter;
	static const All ColorMaterial;
	static const All Fog;
	static const All FogIndex;
	static const All FogDensity;
	static const All FogStart;
	static const All FogEnd;
	static const All FogMode;
	static const All FogColor;
	static const All DepthRange;
	static const All DepthTest;
	static const All DepthWritemask;
	static const All DepthClearValue;
	static const All DepthFunc;
	static const All AccumClearValue;
	static const All StencilTest;
	static const All StencilClearValue;
	static const All StencilFunc;
	static const All StencilValueMask;
	static const All StencilFail;
	static const All StencilPassDepthFail;
	static const All StencilPassDepthPass;
	static const All StencilRef;
	static const All StencilWritemask;
	static const All MatrixMode;
	static const All Normalize;
	static const All Viewport;
	static const All Modelview0StackDepthExt;
	static const All ModelviewStackDepth;
	static const All PathModelviewStackDepthNv;
	static const All PathProjectionStackDepthNv;
	static const All ProjectionStackDepth;
	static const All TextureStackDepth;
	static const All Modelview0MatrixExt;
	static const All ModelviewMatrix;
	static const All PathModelviewMatrixNv;
	static const All PathProjectionMatrixNv;
	static const All ProjectionMatrix;
	static const All TextureMatrix;
	static const All AttribStackDepth;
	static const All ClientAttribStackDepth;
	static const All AlphaTest;
	static const All AlphaTestQcom;
	static const All AlphaTestFunc;
	static const All AlphaTestFuncQcom;
	static const All AlphaTestRef;
	static const All AlphaTestRefQcom;
	static const All Dither;
	static const All BlendDst;
	static const All BlendSrc;
	static const All Blend;
	static const All LogicOpMode;
	static const All IndexLogicOp;
	static const All LogicOp;
	static const All ColorLogicOp;
	static const All CubicCurveToNv;
	static const All AuxBuffers;
	static const All DrawBuffer;
	static const All DrawBufferExt;
	static const All ReadBuffer;
	static const All ReadBufferExt;
	static const All ReadBufferNv;
	static const All ScissorBox;
	static const All ScissorTest;
	static const All IndexClearValue;
	static const All IndexWritemask;
	static const All ColorClearValue;
	static const All ColorWritemask;
	static const All IndexMode;
	static const All RgbaMode;
	static const All Doublebuffer;
	static const All Stereo;
	static const All RenderMode;
	static const All PerspectiveCorrectionHint;
	static const All PointSmoothHint;
	static const All LineSmoothHint;
	static const All PolygonSmoothHint;
	static const All FogHint;
	static const All TextureGenS;
	static const All TextureGenT;
	static const All TextureGenR;
	static const All TextureGenQ;
	static const All PixelMapIToI;
	static const All PixelMapSToS;
	static const All PixelMapIToR;
	static const All PixelMapIToG;
	static const All PixelMapIToB;
	static const All PixelMapIToA;
	static const All PixelMapRToR;
	static const All PixelMapGToG;
	static const All PixelMapBToB;
	static const All PixelMapAToA;
	static const All PixelMapIToISize;
	static const All PixelMapSToSSize;
	static const All PixelMapIToRSize;
	static const All PixelMapIToGSize;
	static const All PixelMapIToBSize;
	static const All PixelMapIToASize;
	static const All PixelMapRToRSize;
	static const All PixelMapGToGSize;
	static const All PixelMapBToBSize;
	static const All PixelMapAToASize;
	static const All UnpackSwapBytes;
	static const All UnpackLsbFirst;
	static const All UnpackRowLength;
	static const All UnpackRowLengthExt;
	static const All UnpackSkipRows;
	static const All UnpackSkipRowsExt;
	static const All UnpackSkipPixels;
	static const All UnpackSkipPixelsExt;
	static const All UnpackAlignment;
	static const All RelativeCubicCurveToNv;
	static const All PackSwapBytes;
	static const All PackLsbFirst;
	static const All PackRowLength;
	static const All PackSkipRows;
	static const All PackSkipPixels;
	static const All PackAlignment;
	static const All MapColor;
	static const All MapStencil;
	static const All IndexShift;
	static const All IndexOffset;
	static const All RedScale;
	static const All RedBias;
	static const All ZoomX;
	static const All ZoomY;
	static const All GreenScale;
	static const All GreenBias;
	static const All BlueScale;
	static const All BlueBias;
	static const All AlphaScale;
	static const All AlphaBias;
	static const All DepthScale;
	static const All DepthBias;
	static const All MaxEvalOrder;
	static const All MaxLights;
	static const All MaxClipDistances;
	static const All MaxClipPlanes;
	static const All MaxTextureSize;
	static const All MaxPixelMapTable;
	static const All MaxAttribStackDepth;
	static const All MaxModelviewStackDepth;
	static const All PathMaxModelviewStackDepthNv;
	static const All MaxNameStackDepth;
	static const All MaxProjectionStackDepth;
	static const All PathMaxProjectionStackDepthNv;
	static const All MaxTextureStackDepth;
	static const All MaxViewportDims;
	static const All MaxClientAttribStackDepth;
	static const All SubpixelBits;
	static const All IndexBits;
	static const All RedBits;
	static const All GreenBits;
	static const All BlueBits;
	static const All AlphaBits;
	static const All DepthBits;
	static const All StencilBits;
	static const All AccumRedBits;
	static const All AccumGreenBits;
	static const All AccumBlueBits;
	static const All AccumAlphaBits;
	static const All NameStackDepth;
	static const All AutoNormal;
	static const All Map1Color4;
	static const All Map1Index;
	static const All Map1Normal;
	static const All Map1TextureCoord1;
	static const All Map1TextureCoord2;
	static const All Map1TextureCoord3;
	static const All Map1TextureCoord4;
	static const All Map1Vertex3;
	static const All Map1Vertex4;
	static const All Map2Color4;
	static const All Map2Index;
	static const All Map2Normal;
	static const All Map2TextureCoord1;
	static const All Map2TextureCoord2;
	static const All Map2TextureCoord3;
	static const All Map2TextureCoord4;
	static const All Map2Vertex3;
	static const All Map2Vertex4;
	static const All Map1GridDomain;
	static const All Map1GridSegments;
	static const All Map2GridDomain;
	static const All Map2GridSegments;
	static const All Texture1D;
	static const All Texture2D;
	static const All FeedbackBufferPointer;
	static const All FeedbackBufferSize;
	static const All FeedbackBufferType;
	static const All SelectionBufferPointer;
	static const All SelectionBufferSize;
	static const All SmoothQuadraticCurveToNv;
	static const All RelativeSmoothQuadraticCurveToNv;
	static const All GlyphHorizontalBearingAdvanceBitNv;
	static const All SmoothCubicCurveToNv;
	static const All GlyphHasKerningBitNv;
	static const All TextureWidth;
	static const All FontHasKerningBitNv;
	static const All Texcoord1BitPgi;
	static const All TextureHeight;
	static const All TextureComponents;
	static const All TextureInternalFormat;
	static const All TextureBorderColor;
	static const All TextureBorderColorNv;
	static const All TextureBorder;
	static const All TextureTarget;
	static const All RelativeSmoothCubicCurveToNv;
	static const All DontCare;
	static const All Fastest;
	static const All Nicest;
	static const All SmallCcwArcToNv;
	static const All Ambient;
	static const All Diffuse;
	static const All Specular;
	static const All Position;
	static const All SpotDirection;
	static const All SpotExponent;
	static const All SpotCutoff;
	static const All ConstantAttenuation;
	static const All LinearAttenuation;
	static const All QuadraticAttenuation;
	static const All RelativeSmallCcwArcToNv;
	static const All Compile;
	static const All CompileAndExecute;
	static const All SmallCwArcToNv;
	static const All Byte;
	static const All UnsignedByte;
	static const All Short;
	static const All UnsignedShort;
	static const All Int;
	static const All UnsignedInt;
	static const All Float;
	static const All Gl2Bytes;
	static const All Gl2BytesNv;
	static const All Gl3Bytes;
	static const All Gl3BytesNv;
	static const All Gl4Bytes;
	static const All Gl4BytesNv;
	static const All Double;
	static const All HalfApple;
	static const All HalfFloat;
	static const All HalfFloatArb;
	static const All HalfFloatNv;
	static const All Fixed;
	static const All FixedOes;
	static const All Int64Nv;
	static const All UnsignedInt64Arb;
	static const All UnsignedInt64Nv;
	static const All RelativeSmallCwArcToNv;
	static const All Clear;
	static const All And;
	static const All AndReverse;
	static const All Copy;
	static const All AndInverted;
	static const All Noop;
	static const All Xor;
	static const All XorNv;
	static const All Or;
	static const All Nor;
	static const All Equiv;
	static const All Invert;
	static const All OrReverse;
	static const All CopyInverted;
	static const All OrInverted;
	static const All Nand;
	static const All Set;
	static const All LargeCcwArcToNv;
	static const All Emission;
	static const All Shininess;
	static const All AmbientAndDiffuse;
	static const All ColorIndexes;
	static const All RelativeLargeCcwArcToNv;
	static const All Modelview;
	static const All Modelview0Arb;
	static const All Modelview0Ext;
	static const All PathModelviewNv;
	static const All PathProjectionNv;
	static const All Projection;
	static const All Texture;
	static const All LargeCwArcToNv;
	static const All Color;
	static const All ColorExt;
	static const All Depth;
	static const All DepthExt;
	static const All Stencil;
	static const All StencilExt;
	static const All RelativeLargeCwArcToNv;
	static const All ColorIndex;
	static const All StencilIndex;
	static const All DepthComponent;
	static const All Red;
	static const All RedExt;
	static const All RedNv;
	static const All Green;
	static const All GreenNv;
	static const All Blue;
	static const All BlueNv;
	static const All Alpha;
	static const All Rgb;
	static const All Rgba;
	static const All Luminance;
	static const All LuminanceAlpha;
	static const All RasterPositionUnclippedIbm;
	static const All ConicCurveToNv;
	static const All Bitmap;
	static const All PreferDoublebufferHintPgi;
	static const All ConserveMemoryHintPgi;
	static const All ReclaimMemoryHintPgi;
	static const All NativeGraphicsHandlePgi;
	static const All NativeGraphicsBeginHintPgi;
	static const All NativeGraphicsEndHintPgi;
	static const All AlwaysFastHintPgi;
	static const All AlwaysSoftHintPgi;
	static const All AllowDrawObjHintPgi;
	static const All AllowDrawWinHintPgi;
	static const All AllowDrawFrgHintPgi;
	static const All AllowDrawMemHintPgi;
	static const All StrictDepthfuncHintPgi;
	static const All StrictLightingHintPgi;
	static const All StrictScissorHintPgi;
	static const All FullStippleHintPgi;
	static const All ClipNearHintPgi;
	static const All ClipFarHintPgi;
	static const All WideLineHintPgi;
	static const All BackNormalsHintPgi;
	static const All VertexDataHintPgi;
	static const All VertexConsistentHintPgi;
	static const All MaterialSideHintPgi;
	static const All MaxVertexHintPgi;
	static const All RelativeConicCurveToNv;
	static const All Point;
	static const All Line;
	static const All Fill;
	static const All Render;
	static const All Feedback;
	static const All Select;
	static const All Flat;
	static const All Smooth;
	static const All Keep;
	static const All Replace;
	static const All Incr;
	static const All Decr;
	static const All Vendor;
	static const All Renderer;
	static const All Version;
	static const All Extensions;
	static const All GlyphVerticalBearingXBitNv;
	static const All S;
	static const All FontNumGlyphIndicesBitNv;
	static const All MultisampleBit;
	static const All MultisampleBit3Dfx;
	static const All MultisampleBitArb;
	static const All MultisampleBitExt;
	static const All Texcoord2BitPgi;
	static const All T;
	static const All R;
	static const All Q;
	static const All Modulate;
	static const All Decal;
	static const All TextureEnvMode;
	static const All TextureEnvColor;
	static const All TextureEnv;
	static const All EyeLinear;
	static const All EyeLinearNv;
	static const All ObjectLinear;
	static const All ObjectLinearNv;
	static const All SphereMap;
	static const All TextureGenMode;
	static const All ObjectPlane;
	static const All EyePlane;
	static const All Nearest;
	static const All Linear;
	static const All NearestMipmapNearest;
	static const All LinearMipmapNearest;
	static const All NearestMipmapLinear;
	static const All LinearMipmapLinear;
	static const All TextureMagFilter;
	static const All TextureMinFilter;
	static const All TextureWrapS;
	static const All TextureWrapT;
	static const All Clamp;
	static const All Repeat;
	static const All PolygonOffsetUnits;
	static const All PolygonOffsetPoint;
	static const All PolygonOffsetLine;
	static const All R3G3B2;
	static const All V2f;
	static const All V3f;
	static const All C4ubV2f;
	static const All C4ubV3f;
	static const All C3fV3f;
	static const All N3fV3f;
	static const All C4fN3fV3f;
	static const All T2fV3f;
	static const All T4fV4f;
	static const All T2fC4ubV3f;
	static const All T2fC3fV3f;
	static const All T2fN3fV3f;
	static const All T2fC4fN3fV3f;
	static const All T4fC4fN3fV4f;
	static const All ClipDistance0;
	static const All ClipPlane0;
	static const All ClipDistance1;
	static const All ClipPlane1;
	static const All ClipDistance2;
	static const All ClipPlane2;
	static const All ClipDistance3;
	static const All ClipPlane3;
	static const All ClipDistance4;
	static const All ClipPlane4;
	static const All ClipDistance5;
	static const All ClipPlane5;
	static const All ClipDistance6;
	static const All ClipDistance7;
	static const All GlyphVerticalBearingYBitNv;
	static const All Light0;
	static const All Texcoord3BitPgi;
	static const All Light1;
	static const All Light2;
	static const All Light3;
	static const All Light4;
	static const All Light5;
	static const All Light6;
	static const All Light7;
	static const All GlyphVerticalBearingAdvanceBitNv;
	static const All AbgrExt;
	static const All Texcoord4BitPgi;
	static const All ConstantColor;
	static const All ConstantColorExt;
	static const All OneMinusConstantColor;
	static const All OneMinusConstantColorExt;
	static const All ConstantAlpha;
	static const All ConstantAlphaExt;
	static const All OneMinusConstantAlpha;
	static const All OneMinusConstantAlphaExt;
	static const All BlendColor;
	static const All BlendColorExt;
	static const All FuncAdd;
	static const All FuncAddExt;
	static const All Min;
	static const All MinExt;
	static const All Max;
	static const All MaxExt;
	static const All BlendEquation;
	static const All BlendEquationExt;
	static const All BlendEquationRgb;
	static const All BlendEquationRgbExt;
	static const All FuncSubtract;
	static const All FuncSubtractExt;
	static const All FuncReverseSubtract;
	static const All FuncReverseSubtractExt;
	static const All CmykExt;
	static const All CmykaExt;
	static const All PackCmykHintExt;
	static const All UnpackCmykHintExt;
	static const All Convolution1D;
	static const All Convolution1DExt;
	static const All Convolution2D;
	static const All Convolution2DExt;
	static const All Separable2D;
	static const All Separable2DExt;
	static const All ConvolutionBorderMode;
	static const All ConvolutionBorderModeExt;
	static const All ConvolutionFilterScale;
	static const All ConvolutionFilterScaleExt;
	static const All ConvolutionFilterBias;
	static const All ConvolutionFilterBiasExt;
	static const All Reduce;
	static const All ReduceExt;
	static const All ConvolutionFormat;
	static const All ConvolutionFormatExt;
	static const All ConvolutionWidth;
	static const All ConvolutionWidthExt;
	static const All ConvolutionHeight;
	static const All ConvolutionHeightExt;
	static const All MaxConvolutionWidth;
	static const All MaxConvolutionWidthExt;
	static const All MaxConvolutionHeight;
	static const All MaxConvolutionHeightExt;
	static const All PostConvolutionRedScale;
	static const All PostConvolutionRedScaleExt;
	static const All PostConvolutionGreenScale;
	static const All PostConvolutionGreenScaleExt;
	static const All PostConvolutionBlueScale;
	static const All PostConvolutionBlueScaleExt;
	static const All PostConvolutionAlphaScale;
	static const All PostConvolutionAlphaScaleExt;
	static const All PostConvolutionRedBias;
	static const All PostConvolutionRedBiasExt;
	static const All PostConvolutionGreenBias;
	static const All PostConvolutionGreenBiasExt;
	static const All PostConvolutionBlueBias;
	static const All PostConvolutionBlueBiasExt;
	static const All PostConvolutionAlphaBias;
	static const All PostConvolutionAlphaBiasExt;
	static const All Histogram;
	static const All HistogramExt;
	static const All ProxyHistogram;
	static const All ProxyHistogramExt;
	static const All HistogramWidth;
	static const All HistogramWidthExt;
	static const All HistogramFormat;
	static const All HistogramFormatExt;
	static const All HistogramRedSize;
	static const All HistogramRedSizeExt;
	static const All HistogramGreenSize;
	static const All HistogramGreenSizeExt;
	static const All HistogramBlueSize;
	static const All HistogramBlueSizeExt;
	static const All HistogramAlphaSize;
	static const All HistogramAlphaSizeExt;
	static const All HistogramLuminanceSize;
	static const All HistogramLuminanceSizeExt;
	static const All HistogramSink;
	static const All HistogramSinkExt;
	static const All Minmax;
	static const All MinmaxExt;
	static const All MinmaxFormat;
	static const All MinmaxFormatExt;
	static const All MinmaxSink;
	static const All MinmaxSinkExt;
	static const All TableTooLarge;
	static const All TableTooLargeExt;
	static const All UnsignedByte332;
	static const All UnsignedByte332Ext;
	static const All UnsignedShort4444;
	static const All UnsignedShort4444Ext;
	static const All UnsignedShort5551;
	static const All UnsignedShort5551Ext;
	static const All UnsignedInt8888;
	static const All UnsignedInt8888Ext;
	static const All UnsignedInt1010102;
	static const All UnsignedInt1010102Ext;
	static const All PolygonOffsetExt;
	static const All PolygonOffsetFill;
	static const All PolygonOffsetFactor;
	static const All PolygonOffsetFactorExt;
	static const All PolygonOffsetBiasExt;
	static const All RescaleNormal;
	static const All RescaleNormalExt;
	static const All Alpha4;
	static const All Alpha4Ext;
	static const All Alpha8;
	static const All Alpha8Ext;
	static const All Alpha12;
	static const All Alpha12Ext;
	static const All Alpha16;
	static const All Alpha16Ext;
	static const All Luminance4;
	static const All Luminance4Ext;
	static const All Luminance8;
	static const All Luminance8Ext;
	static const All Luminance12;
	static const All Luminance12Ext;
	static const All Luminance16;
	static const All Luminance16Ext;
	static const All Luminance4Alpha4;
	static const All Luminance4Alpha4Ext;
	static const All Luminance6Alpha2;
	static const All Luminance6Alpha2Ext;
	static const All Luminance8Alpha8;
	static const All Luminance8Alpha8Ext;
	static const All Luminance12Alpha4;
	static const All Luminance12Alpha4Ext;
	static const All Luminance12Alpha12;
	static const All Luminance12Alpha12Ext;
	static const All Luminance16Alpha16;
	static const All Luminance16Alpha16Ext;
	static const All Intensity;
	static const All IntensityExt;
	static const All Intensity4;
	static const All Intensity4Ext;
	static const All Intensity8;
	static const All Intensity8Ext;
	static const All Intensity12;
	static const All Intensity12Ext;
	static const All Intensity16;
	static const All Intensity16Ext;
	static const All Rgb2Ext;
	static const All Rgb4;
	static const All Rgb4Ext;
	static const All Rgb5;
	static const All Rgb5Ext;
	static const All Rgb8;
	static const All Rgb8Ext;
	static const All Rgb10;
	static const All Rgb10Ext;
	static const All Rgb12;
	static const All Rgb12Ext;
	static const All Rgb16;
	static const All Rgb16Ext;
	static const All Rgba2;
	static const All Rgba2Ext;
	static const All Rgba4;
	static const All Rgba4Ext;
	static const All Rgb5A1;
	static const All Rgb5A1Ext;
	static const All Rgba8;
	static const All Rgba8Ext;
	static const All Rgb10A2;
	static const All Rgb10A2Ext;
	static const All Rgba12;
	static const All Rgba12Ext;
	static const All Rgba16;
	static const All Rgba16Ext;
	static const All TextureRedSize;
	static const All TextureRedSizeExt;
	static const All TextureGreenSize;
	static const All TextureGreenSizeExt;
	static const All TextureBlueSize;
	static const All TextureBlueSizeExt;
	static const All TextureAlphaSize;
	static const All TextureAlphaSizeExt;
	static const All TextureLuminanceSize;
	static const All TextureLuminanceSizeExt;
	static const All TextureIntensitySize;
	static const All TextureIntensitySizeExt;
	static const All ReplaceExt;
	static const All ProxyTexture1D;
	static const All ProxyTexture1DExt;
	static const All ProxyTexture2D;
	static const All ProxyTexture2DExt;
	static const All TextureTooLargeExt;
	static const All TexturePriority;
	static const All TexturePriorityExt;
	static const All TextureResident;
	static const All TextureResidentExt;
	static const All Texture1DBindingExt;
	static const All TextureBinding1D;
	static const All Texture2DBindingExt;
	static const All TextureBinding2D;
	static const All Texture3DBindingExt;
	static const All TextureBinding3D;
	static const All PackSkipImages;
	static const All PackSkipImagesExt;
	static const All PackImageHeight;
	static const All PackImageHeightExt;
	static const All UnpackSkipImages;
	static const All UnpackSkipImagesExt;
	static const All UnpackImageHeight;
	static const All UnpackImageHeightExt;
	static const All Texture3D;
	static const All Texture3DExt;
	static const All Texture3DOes;
	static const All ProxyTexture3D;
	static const All ProxyTexture3DExt;
	static const All TextureDepth;
	static const All TextureDepthExt;
	static const All TextureWrapR;
	static const All TextureWrapRExt;
	static const All TextureWrapROes;
	static const All Max3DTextureSize;
	static const All Max3DTextureSizeExt;
	static const All VertexArray;
	static const All VertexArrayExt;
	static const All VertexArrayKhr;
	static const All NormalArray;
	static const All NormalArrayExt;
	static const All ColorArray;
	static const All ColorArrayExt;
	static const All IndexArray;
	static const All IndexArrayExt;
	static const All TextureCoordArray;
	static const All TextureCoordArrayExt;
	static const All EdgeFlagArray;
	static const All EdgeFlagArrayExt;
	static const All VertexArraySize;
	static const All VertexArraySizeExt;
	static const All VertexArrayType;
	static const All VertexArrayTypeExt;
	static const All VertexArrayStride;
	static const All VertexArrayStrideExt;
	static const All VertexArrayCountExt;
	static const All NormalArrayType;
	static const All NormalArrayTypeExt;
	static const All NormalArrayStride;
	static const All NormalArrayStrideExt;
	static const All NormalArrayCountExt;
	static const All ColorArraySize;
	static const All ColorArraySizeExt;
	static const All ColorArrayType;
	static const All ColorArrayTypeExt;
	static const All ColorArrayStride;
	static const All ColorArrayStrideExt;
	static const All ColorArrayCountExt;
	static const All IndexArrayType;
	static const All IndexArrayTypeExt;
	static const All IndexArrayStride;
	static const All IndexArrayStrideExt;
	static const All IndexArrayCountExt;
	static const All TextureCoordArraySize;
	static const All TextureCoordArraySizeExt;
	static const All TextureCoordArrayType;
	static const All TextureCoordArrayTypeExt;
	static const All TextureCoordArrayStride;
	static const All TextureCoordArrayStrideExt;
	static const All TextureCoordArrayCountExt;
	static const All EdgeFlagArrayStride;
	static const All EdgeFlagArrayStrideExt;
	static const All EdgeFlagArrayCountExt;
	static const All VertexArrayPointer;
	static const All VertexArrayPointerExt;
	static const All NormalArrayPointer;
	static const All NormalArrayPointerExt;
	static const All ColorArrayPointer;
	static const All ColorArrayPointerExt;
	static const All IndexArrayPointer;
	static const All IndexArrayPointerExt;
	static const All TextureCoordArrayPointer;
	static const All TextureCoordArrayPointerExt;
	static const All EdgeFlagArrayPointer;
	static const All EdgeFlagArrayPointerExt;
	static const All InterlaceSgix;
	static const All DetailTexture2DSgis;
	static const All DetailTexture2DBindingSgis;
	static const All LinearDetailSgis;
	static const All LinearDetailAlphaSgis;
	static const All LinearDetailColorSgis;
	static const All DetailTextureLevelSgis;
	static const All DetailTextureModeSgis;
	static const All DetailTextureFuncPointsSgis;
	static const All Multisample;
	static const All MultisampleArb;
	static const All MultisampleExt;
	static const All MultisampleSgis;
	static const All SampleAlphaToCoverage;
	static const All SampleAlphaToCoverageArb;
	static const All SampleAlphaToMaskExt;
	static const All SampleAlphaToMaskSgis;
	static const All SampleAlphaToOne;
	static const All SampleAlphaToOneArb;
	static const All SampleAlphaToOneExt;
	static const All SampleAlphaToOneSgis;
	static const All SampleCoverage;
	static const All SampleCoverageArb;
	static const All SampleMaskExt;
	static const All SampleMaskSgis;
	static const All Gl1PassExt;
	static const All Gl1PassSgis;
	static const All Gl2Pass0Ext;
	static const All Gl2Pass0Sgis;
	static const All Gl2Pass1Ext;
	static const All Gl2Pass1Sgis;
	static const All Gl4Pass0Ext;
	static const All Gl4Pass0Sgis;
	static const All Gl4Pass1Ext;
	static const All Gl4Pass1Sgis;
	static const All Gl4Pass2Ext;
	static const All Gl4Pass2Sgis;
	static const All Gl4Pass3Ext;
	static const All Gl4Pass3Sgis;
	static const All SampleBuffers;
	static const All SampleBuffersArb;
	static const All SampleBuffersExt;
	static const All SampleBuffersSgis;
	static const All Samples;
	static const All SamplesArb;
	static const All SamplesExt;
	static const All SamplesSgis;
	static const All SampleCoverageValue;
	static const All SampleCoverageValueArb;
	static const All SampleMaskValueExt;
	static const All SampleMaskValueSgis;
	static const All SampleCoverageInvert;
	static const All SampleCoverageInvertArb;
	static const All SampleMaskInvertExt;
	static const All SampleMaskInvertSgis;
	static const All SamplePatternExt;
	static const All SamplePatternSgis;
	static const All LinearSharpenSgis;
	static const All LinearSharpenAlphaSgis;
	static const All LinearSharpenColorSgis;
	static const All SharpenTextureFuncPointsSgis;
	static const All ColorMatrix;
	static const All ColorMatrixSgi;
	static const All ColorMatrixStackDepth;
	static const All ColorMatrixStackDepthSgi;
	static const All MaxColorMatrixStackDepth;
	static const All MaxColorMatrixStackDepthSgi;
	static const All PostColorMatrixRedScale;
	static const All PostColorMatrixRedScaleSgi;
	static const All PostColorMatrixGreenScale;
	static const All PostColorMatrixGreenScaleSgi;
	static const All PostColorMatrixBlueScale;
	static const All PostColorMatrixBlueScaleSgi;
	static const All PostColorMatrixAlphaScale;
	static const All PostColorMatrixAlphaScaleSgi;
	static const All PostColorMatrixRedBias;
	static const All PostColorMatrixRedBiasSgi;
	static const All PostColorMatrixGreenBias;
	static const All PostColorMatrixGreenBiasSgi;
	static const All PostColorMatrixBlueBias;
	static const All PostColorMatrixBlueBiasSgi;
	static const All PostColorMatrixAlphaBias;
	static const All PostColorMatrixAlphaBiasSgi;
	static const All TextureColorTableSgi;
	static const All ProxyTextureColorTableSgi;
	static const All TextureEnvBiasSgix;
	static const All ShadowAmbientSgix;
	static const All TextureCompareFailValue;
	static const All TextureCompareFailValueArb;
	static const All BlendDstRgb;
	static const All BlendDstRgbExt;
	static const All BlendSrcRgb;
	static const All BlendSrcRgbExt;
	static const All BlendDstAlpha;
	static const All BlendDstAlphaExt;
	static const All BlendSrcAlpha;
	static const All BlendSrcAlphaExt;
	static const All Gl422Ext;
	static const All Gl422RevExt;
	static const All Gl422AverageExt;
	static const All Gl422RevAverageExt;
	static const All ColorTable;
	static const All ColorTableSgi;
	static const All PostConvolutionColorTable;
	static const All PostConvolutionColorTableSgi;
	static const All PostColorMatrixColorTable;
	static const All PostColorMatrixColorTableSgi;
	static const All ProxyColorTable;
	static const All ProxyColorTableSgi;
	static const All ProxyPostConvolutionColorTable;
	static const All ProxyPostConvolutionColorTableSgi;
	static const All ProxyPostColorMatrixColorTable;
	static const All ProxyPostColorMatrixColorTableSgi;
	static const All ColorTableScale;
	static const All ColorTableScaleSgi;
	static const All ColorTableBias;
	static const All ColorTableBiasSgi;
	static const All ColorTableFormat;
	static const All ColorTableFormatSgi;
	static const All ColorTableWidth;
	static const All ColorTableWidthSgi;
	static const All ColorTableRedSize;
	static const All ColorTableRedSizeSgi;
	static const All ColorTableGreenSize;
	static const All ColorTableGreenSizeSgi;
	static const All ColorTableBlueSize;
	static const All ColorTableBlueSizeSgi;
	static const All ColorTableAlphaSize;
	static const All ColorTableAlphaSizeSgi;
	static const All ColorTableLuminanceSize;
	static const All ColorTableLuminanceSizeSgi;
	static const All ColorTableIntensitySize;
	static const All ColorTableIntensitySizeSgi;
	static const All Bgr;
	static const All BgrExt;
	static const All Bgra;
	static const All BgraExt;
	static const All ColorIndex1Ext;
	static const All ColorIndex2Ext;
	static const All ColorIndex4Ext;
	static const All ColorIndex8Ext;
	static const All ColorIndex12Ext;
	static const All ColorIndex16Ext;
	static const All MaxElementsVertices;
	static const All MaxElementsVerticesExt;
	static const All MaxElementsIndices;
	static const All MaxElementsIndicesExt;
	static const All PhongWin;
	static const All PhongHintWin;
	static const All FogSpecularTextureWin;
	static const All TextureIndexSizeExt;
	static const All ParameterBufferArb;
	static const All ParameterBufferBindingArb;
	static const All ClipVolumeClippingHintExt;
	static const All DualAlpha4Sgis;
	static const All DualAlpha8Sgis;
	static const All DualAlpha12Sgis;
	static const All DualAlpha16Sgis;
	static const All DualLuminance4Sgis;
	static const All DualLuminance8Sgis;
	static const All DualLuminance12Sgis;
	static const All DualLuminance16Sgis;
	static const All DualIntensity4Sgis;
	static const All DualIntensity8Sgis;
	static const All DualIntensity12Sgis;
	static const All DualIntensity16Sgis;
	static const All DualLuminanceAlpha4Sgis;
	static const All DualLuminanceAlpha8Sgis;
	static const All QuadAlpha4Sgis;
	static const All QuadAlpha8Sgis;
	static const All QuadLuminance4Sgis;
	static const All QuadLuminance8Sgis;
	static const All QuadIntensity4Sgis;
	static const All QuadIntensity8Sgis;
	static const All DualTextureSelectSgis;
	static const All QuadTextureSelectSgis;
	static const All PointSizeMin;
	static const All PointSizeMinArb;
	static const All PointSizeMinExt;
	static const All PointSizeMinSgis;
	static const All PointSizeMax;
	static const All PointSizeMaxArb;
	static const All PointSizeMaxExt;
	static const All PointSizeMaxSgis;
	static const All PointFadeThresholdSize;
	static const All PointFadeThresholdSizeArb;
	static const All PointFadeThresholdSizeExt;
	static const All PointFadeThresholdSizeSgis;
	static const All DistanceAttenuationExt;
	static const All DistanceAttenuationSgis;
	static const All PointDistanceAttenuation;
	static const All PointDistanceAttenuationArb;
	static const All FogFuncSgis;
	static const All FogFuncPointsSgis;
	static const All MaxFogFuncPointsSgis;
	static const All ClampToBorder;
	static const All ClampToBorderArb;
	static const All ClampToBorderNv;
	static const All ClampToBorderSgis;
	static const All TextureMultiBufferHintSgix;
	static const All ClampToEdge;
	static const All ClampToEdgeSgis;
	static const All PackSkipVolumesSgis;
	static const All PackImageDepthSgis;
	static const All UnpackSkipVolumesSgis;
	static const All UnpackImageDepthSgis;
	static const All Texture4DSgis;
	static const All ProxyTexture4DSgis;
	static const All Texture4DsizeSgis;
	static const All TextureWrapQSgis;
	static const All Max4DTextureSizeSgis;
	static const All PixelTexGenSgix;
	static const All TextureMinLod;
	static const All TextureMinLodSgis;
	static const All TextureMaxLod;
	static const All TextureMaxLodSgis;
	static const All TextureBaseLevel;
	static const All TextureBaseLevelSgis;
	static const All TextureMaxLevel;
	static const All TextureMaxLevelSgis;
	static const All PixelTileBestAlignmentSgix;
	static const All PixelTileCacheIncrementSgix;
	static const All PixelTileWidthSgix;
	static const All PixelTileHeightSgix;
	static const All PixelTileGridWidthSgix;
	static const All PixelTileGridHeightSgix;
	static const All PixelTileGridDepthSgix;
	static const All PixelTileCacheSizeSgix;
	static const All Filter4Sgis;
	static const All TextureFilter4SizeSgis;
	static const All SpriteSgix;
	static const All SpriteModeSgix;
	static const All SpriteAxisSgix;
	static const All SpriteTranslationSgix;
	static const All SpriteAxialSgix;
	static const All SpriteObjectAlignedSgix;
	static const All SpriteEyeAlignedSgix;
	static const All Texture4DBindingSgis;
	static const All IgnoreBorderHp;
	static const All ConstantBorder;
	static const All ConstantBorderHp;
	static const All ReplicateBorder;
	static const All ReplicateBorderHp;
	static const All ConvolutionBorderColor;
	static const All ConvolutionBorderColorHp;
	static const All ImageScaleXHp;
	static const All ImageScaleYHp;
	static const All ImageTranslateXHp;
	static const All ImageTranslateYHp;
	static const All ImageRotateAngleHp;
	static const All ImageRotateOriginXHp;
	static const All ImageRotateOriginYHp;
	static const All ImageMagFilterHp;
	static const All ImageMinFilterHp;
	static const All ImageCubicWeightHp;
	static const All CubicHp;
	static const All AverageHp;
	static const All ImageTransform2DHp;
	static const All PostImageTransformColorTableHp;
	static const All ProxyPostImageTransformColorTableHp;
	static const All OcclusionTestHp;
	static const All OcclusionTestResultHp;
	static const All TextureLightingModeHp;
	static const All TexturePostSpecularHp;
	static const All TexturePreSpecularHp;
	static const All LinearClipmapLinearSgix;
	static const All TextureClipmapCenterSgix;
	static const All TextureClipmapFrameSgix;
	static const All TextureClipmapOffsetSgix;
	static const All TextureClipmapVirtualDepthSgix;
	static const All TextureClipmapLodOffsetSgix;
	static const All TextureClipmapDepthSgix;
	static const All MaxClipmapDepthSgix;
	static const All MaxClipmapVirtualDepthSgix;
	static const All PostTextureFilterBiasSgix;
	static const All PostTextureFilterScaleSgix;
	static const All PostTextureFilterBiasRangeSgix;
	static const All PostTextureFilterScaleRangeSgix;
	static const All ReferencePlaneSgix;
	static const All ReferencePlaneEquationSgix;
	static const All IrInstrument1Sgix;
	static const All InstrumentBufferPointerSgix;
	static const All InstrumentMeasurementsSgix;
	static const All ListPrioritySgix;
	static const All CalligraphicFragmentSgix;
	static const All PixelTexGenQCeilingSgix;
	static const All PixelTexGenQRoundSgix;
	static const All PixelTexGenQFloorSgix;
	static const All PixelTexGenAlphaReplaceSgix;
	static const All PixelTexGenAlphaNoReplaceSgix;
	static const All PixelTexGenAlphaLsSgix;
	static const All PixelTexGenAlphaMsSgix;
	static const All FramezoomSgix;
	static const All FramezoomFactorSgix;
	static const All MaxFramezoomFactorSgix;
	static const All TextureLodBiasSSgix;
	static const All TextureLodBiasTSgix;
	static const All TextureLodBiasRSgix;
	static const All GenerateMipmap;
	static const All GenerateMipmapSgis;
	static const All GenerateMipmapHint;
	static const All GenerateMipmapHintSgis;
	static const All GeometryDeformationSgix;
	static const All TextureDeformationSgix;
	static const All DeformationsMaskSgix;
	static const All MaxDeformationOrderSgix;
	static const All FogOffsetSgix;
	static const All FogOffsetValueSgix;
	static const All TextureCompareSgix;
	static const All TextureCompareOperatorSgix;
	static const All TextureLequalRSgix;
	static const All TextureGequalRSgix;
	static const All DepthComponent16;
	static const All DepthComponent16Arb;
	static const All DepthComponent16Sgix;
	static const All DepthComponent24;
	static const All DepthComponent24Arb;
	static const All DepthComponent24Sgix;
	static const All DepthComponent32;
	static const All DepthComponent32Arb;
	static const All DepthComponent32Sgix;
	static const All ArrayElementLockFirstExt;
	static const All ArrayElementLockCountExt;
	static const All CullVertexExt;
	static const All CullVertexEyePositionExt;
	static const All CullVertexObjectPositionExt;
	static const All IuiV2fExt;
	static const All IuiV3fExt;
	static const All IuiN3fV2fExt;
	static const All IuiN3fV3fExt;
	static const All T2fIuiV2fExt;
	static const All T2fIuiV3fExt;
	static const All T2fIuiN3fV2fExt;
	static const All T2fIuiN3fV3fExt;
	static const All IndexTestExt;
	static const All IndexTestFuncExt;
	static const All IndexTestRefExt;
	static const All IndexMaterialExt;
	static const All IndexMaterialParameterExt;
	static const All IndexMaterialFaceExt;
	static const All Ycrcb422Sgix;
	static const All Ycrcb444Sgix;
	static const All WrapBorderSun;
	static const All UnpackConstantDataSunx;
	static const All TextureConstantDataSunx;
	static const All TriangleListSun;
	static const All ReplacementCodeSun;
	static const All GlobalAlphaSun;
	static const All GlobalAlphaFactorSun;
	static const All TextureColorWritemaskSgis;
	static const All EyeDistanceToPointSgis;
	static const All ObjectDistanceToPointSgis;
	static const All EyeDistanceToLineSgis;
	static const All ObjectDistanceToLineSgis;
	static const All EyePointSgis;
	static const All ObjectPointSgis;
	static const All EyeLineSgis;
	static const All ObjectLineSgis;
	static const All LightModelColorControl;
	static const All LightModelColorControlExt;
	static const All SingleColor;
	static const All SingleColorExt;
	static const All SeparateSpecularColor;
	static const All SeparateSpecularColorExt;
	static const All SharedTexturePaletteExt;
	static const All TextFragmentShaderAti;
	static const All FramebufferAttachmentColorEncoding;
	static const All FramebufferAttachmentComponentType;
	static const All FramebufferAttachmentRedSize;
	static const All FramebufferAttachmentGreenSize;
	static const All FramebufferAttachmentBlueSize;
	static const All FramebufferAttachmentAlphaSize;
	static const All FramebufferAttachmentDepthSize;
	static const All FramebufferAttachmentStencilSize;
	static const All FramebufferDefault;
	static const All FramebufferUndefined;
	static const All DepthStencilAttachment;
	static const All MajorVersion;
	static const All MinorVersion;
	static const All NumExtensions;
	static const All ContextFlags;
	static const All BufferImmutableStorage;
	static const All BufferStorageFlags;
	static const All PrimitiveRestartForPatchesSupported;
	static const All Index;
	static const All CompressedRed;
	static const All CompressedRg;
	static const All Rg;
	static const All RgInteger;
	static const All R8;
	static const All R16;
	static const All Rg8;
	static const All Rg16;
	static const All R16f;
	static const All R32f;
	static const All Rg16f;
	static const All Rg32f;
	static const All R8i;
	static const All R8ui;
	static const All R16i;
	static const All R16ui;
	static const All R32i;
	static const All R32ui;
	static const All Rg8i;
	static const All Rg8ui;
	static const All Rg16i;
	static const All Rg16ui;
	static const All Rg32i;
	static const All Rg32ui;
	static const All SyncClEventArb;
	static const All SyncClEventCompleteArb;
	static const All DebugOutputSynchronous;
	static const All DebugOutputSynchronousArb;
	static const All DebugOutputSynchronousKhr;
	static const All DebugNextLoggedMessageLength;
	static const All DebugNextLoggedMessageLengthArb;
	static const All DebugNextLoggedMessageLengthKhr;
	static const All DebugCallbackFunction;
	static const All DebugCallbackFunctionArb;
	static const All DebugCallbackFunctionKhr;
	static const All DebugCallbackUserParam;
	static const All DebugCallbackUserParamArb;
	static const All DebugCallbackUserParamKhr;
	static const All DebugSourceApi;
	static const All DebugSourceApiArb;
	static const All DebugSourceApiKhr;
	static const All DebugSourceWindowSystem;
	static const All DebugSourceWindowSystemArb;
	static const All DebugSourceWindowSystemKhr;
	static const All DebugSourceShaderCompiler;
	static const All DebugSourceShaderCompilerArb;
	static const All DebugSourceShaderCompilerKhr;
	static const All DebugSourceThirdParty;
	static const All DebugSourceThirdPartyArb;
	static const All DebugSourceThirdPartyKhr;
	static const All DebugSourceApplication;
	static const All DebugSourceApplicationArb;
	static const All DebugSourceApplicationKhr;
	static const All DebugSourceOther;
	static const All DebugSourceOtherArb;
	static const All DebugSourceOtherKhr;
	static const All DebugTypeError;
	static const All DebugTypeErrorArb;
	static const All DebugTypeErrorKhr;
	static const All DebugTypeDeprecatedBehavior;
	static const All DebugTypeDeprecatedBehaviorArb;
	static const All DebugTypeDeprecatedBehaviorKhr;
	static const All DebugTypeUndefinedBehavior;
	static const All DebugTypeUndefinedBehaviorArb;
	static const All DebugTypeUndefinedBehaviorKhr;
	static const All DebugTypePortability;
	static const All DebugTypePortabilityArb;
	static const All DebugTypePortabilityKhr;
	static const All DebugTypePerformance;
	static const All DebugTypePerformanceArb;
	static const All DebugTypePerformanceKhr;
	static const All DebugTypeOther;
	static const All DebugTypeOtherArb;
	static const All DebugTypeOtherKhr;
	static const All LoseContextOnReset;
	static const All LoseContextOnResetArb;
	static const All LoseContextOnResetKhr;
	static const All GuiltyContextReset;
	static const All GuiltyContextResetArb;
	static const All GuiltyContextResetKhr;
	static const All InnocentContextReset;
	static const All InnocentContextResetArb;
	static const All InnocentContextResetKhr;
	static const All UnknownContextReset;
	static const All UnknownContextResetArb;
	static const All UnknownContextResetKhr;
	static const All ResetNotificationStrategy;
	static const All ResetNotificationStrategyArb;
	static const All ResetNotificationStrategyKhr;
	static const All ProgramBinaryRetrievableHint;
	static const All ProgramSeparable;
	static const All ProgramSeparableExt;
	static const All ActiveProgram;
	static const All ProgramPipelineBinding;
	static const All ProgramPipelineBindingExt;
	static const All MaxViewports;
	static const All ViewportSubpixelBits;
	static const All ViewportBoundsRange;
	static const All LayerProvokingVertex;
	static const All ViewportIndexProvokingVertex;
	static const All UndefinedVertex;
	static const All NoResetNotification;
	static const All NoResetNotificationArb;
	static const All NoResetNotificationKhr;
	static const All MaxComputeSharedMemorySize;
	static const All MaxComputeUniformComponents;
	static const All MaxComputeAtomicCounterBuffers;
	static const All MaxComputeAtomicCounters;
	static const All MaxCombinedComputeUniformComponents;
	static const All ComputeWorkGroupSize;
	static const All DebugTypeMarker;
	static const All DebugTypeMarkerKhr;
	static const All DebugTypePushGroup;
	static const All DebugTypePushGroupKhr;
	static const All DebugTypePopGroup;
	static const All DebugTypePopGroupKhr;
	static const All DebugSeverityNotification;
	static const All DebugSeverityNotificationKhr;
	static const All MaxDebugGroupStackDepth;
	static const All MaxDebugGroupStackDepthKhr;
	static const All DebugGroupStackDepth;
	static const All DebugGroupStackDepthKhr;
	static const All MaxUniformLocations;
	static const All InternalformatSupported;
	static const All InternalformatPreferred;
	static const All InternalformatRedSize;
	static const All InternalformatGreenSize;
	static const All InternalformatBlueSize;
	static const All InternalformatAlphaSize;
	static const All InternalformatDepthSize;
	static const All InternalformatStencilSize;
	static const All InternalformatSharedSize;
	static const All InternalformatRedType;
	static const All InternalformatGreenType;
	static const All InternalformatBlueType;
	static const All InternalformatAlphaType;
	static const All InternalformatDepthType;
	static const All InternalformatStencilType;
	static const All MaxWidth;
	static const All MaxHeight;
	static const All MaxDepth;
	static const All MaxLayers;
	static const All MaxCombinedDimensions;
	static const All ColorComponents;
	static const All DepthComponents;
	static const All StencilComponents;
	static const All ColorRenderable;
	static const All DepthRenderable;
	static const All StencilRenderable;
	static const All FramebufferRenderable;
	static const All FramebufferRenderableLayered;
	static const All FramebufferBlend;
	static const All ReadPixels;
	static const All ReadPixelsFormat;
	static const All ReadPixelsType;
	static const All TextureImageFormat;
	static const All TextureImageType;
	static const All GetTextureImageFormat;
	static const All GetTextureImageType;
	static const All Mipmap;
	static const All ManualGenerateMipmap;
	static const All AutoGenerateMipmap;
	static const All ColorEncoding;
	static const All SrgbRead;
	static const All SrgbWrite;
	static const All SrgbDecodeArb;
	static const All Filter;
	static const All VertexTexture;
	static const All TessControlTexture;
	static const All TessEvaluationTexture;
	static const All GeometryTexture;
	static const All FragmentTexture;
	static const All ComputeTexture;
	static const All TextureShadow;
	static const All TextureGather;
	static const All TextureGatherShadow;
	static const All ShaderImageLoad;
	static const All ShaderImageStore;
	static const All ShaderImageAtomic;
	static const All ImageTexelSize;
	static const All ImageCompatibilityClass;
	static const All ImagePixelFormat;
	static const All ImagePixelType;
	static const All SimultaneousTextureAndDepthTest;
	static const All SimultaneousTextureAndStencilTest;
	static const All SimultaneousTextureAndDepthWrite;
	static const All SimultaneousTextureAndStencilWrite;
	static const All TextureCompressedBlockWidth;
	static const All TextureCompressedBlockHeight;
	static const All TextureCompressedBlockSize;
	static const All ClearBuffer;
	static const All TextureView;
	static const All ViewCompatibilityClass;
	static const All FullSupport;
	static const All CaveatSupport;
	static const All ImageClass4X32;
	static const All ImageClass2X32;
	static const All ImageClass1X32;
	static const All ImageClass4X16;
	static const All ImageClass2X16;
	static const All ImageClass1X16;
	static const All ImageClass4X8;
	static const All ImageClass2X8;
	static const All ImageClass1X8;
	static const All ImageClass111110;
	static const All ImageClass1010102;
	static const All ViewClass128Bits;
	static const All ViewClass96Bits;
	static const All ViewClass64Bits;
	static const All ViewClass48Bits;
	static const All ViewClass32Bits;
	static const All ViewClass24Bits;
	static const All ViewClass16Bits;
	static const All ViewClass8Bits;
	static const All ViewClassS3tcDxt1Rgb;
	static const All ViewClassS3tcDxt1Rgba;
	static const All ViewClassS3tcDxt3Rgba;
	static const All ViewClassS3tcDxt5Rgba;
	static const All ViewClassRgtc1Red;
	static const All ViewClassRgtc2Rg;
	static const All ViewClassBptcUnorm;
	static const All ViewClassBptcFloat;
	static const All VertexAttribBinding;
	static const All VertexAttribRelativeOffset;
	static const All VertexBindingDivisor;
	static const All VertexBindingOffset;
	static const All VertexBindingStride;
	static const All MaxVertexAttribRelativeOffset;
	static const All MaxVertexAttribBindings;
	static const All TextureViewMinLevel;
	static const All TextureViewNumLevels;
	static const All TextureViewMinLayer;
	static const All TextureViewNumLayers;
	static const All TextureImmutableLevels;
	static const All Buffer;
	static const All BufferKhr;
	static const All Shader;
	static const All ShaderKhr;
	static const All Program;
	static const All ProgramKhr;
	static const All Query;
	static const All QueryKhr;
	static const All ProgramPipeline;
	static const All MaxVertexAttribStride;
	static const All Sampler;
	static const All SamplerKhr;
	static const All DisplayList;
	static const All MaxLabelLength;
	static const All MaxLabelLengthKhr;
	static const All NumShadingLanguageVersions;
	static const All QueryTarget;
	static const All TextureBinding;
	static const All TransformFeedbackOverflowArb;
	static const All TransformFeedbackStreamOverflowArb;
	static const All VerticesSubmittedArb;
	static const All PrimitivesSubmittedArb;
	static const All VertexShaderInvocationsArb;
	static const All TessControlShaderPatchesArb;
	static const All TessEvaluationShaderInvocationsArb;
	static const All GeometryShaderPrimitivesEmittedArb;
	static const All FragmentShaderInvocationsArb;
	static const All ComputeShaderInvocationsArb;
	static const All ClippingInputPrimitivesArb;
	static const All ClippingOutputPrimitivesArb;
	static const All SparseBufferPageSizeArb;
	static const All MaxCullDistances;
	static const All MaxCombinedClipAndCullDistances;
	static const All ContextReleaseBehavior;
	static const All ContextReleaseBehaviorKhr;
	static const All ContextReleaseBehaviorFlush;
	static const All ContextReleaseBehaviorFlushKhr;
	static const All ConvolutionHintSgix;
	static const All YcrcbSgix;
	static const All YcrcbaSgix;
	static const All AlphaMinSgix;
	static const All AlphaMaxSgix;
	static const All ScalebiasHintSgix;
	static const All AsyncMarkerSgix;
	static const All PixelTexGenModeSgix;
	static const All AsyncHistogramSgix;
	static const All MaxAsyncHistogramSgix;
	static const All PixelTransform2DExt;
	static const All PixelMagFilterExt;
	static const All PixelMinFilterExt;
	static const All PixelCubicWeightExt;
	static const All CubicExt;
	static const All AverageExt;
	static const All PixelTransform2DStackDepthExt;
	static const All MaxPixelTransform2DStackDepthExt;
	static const All PixelTransform2DMatrixExt;
	static const All FragmentMaterialExt;
	static const All FragmentNormalExt;
	static const All FragmentColorExt;
	static const All AttenuationExt;
	static const All ShadowAttenuationExt;
	static const All TextureApplicationModeExt;
	static const All TextureLightExt;
	static const All TextureMaterialFaceExt;
	static const All TextureMaterialParameterExt;
	static const All PixelTextureSgis;
	static const All PixelFragmentRgbSourceSgis;
	static const All PixelFragmentAlphaSourceSgis;
	static const All PixelGroupColorSgis;
	static const All LineQualityHintSgix;
	static const All AsyncTexImageSgix;
	static const All AsyncDrawPixelsSgix;
	static const All AsyncReadPixelsSgix;
	static const All MaxAsyncTexImageSgix;
	static const All MaxAsyncDrawPixelsSgix;
	static const All MaxAsyncReadPixelsSgix;
	static const All UnsignedByte233Rev;
	static const All UnsignedByte233Reversed;
	static const All UnsignedShort565;
	static const All UnsignedShort565Rev;
	static const All UnsignedShort565Reversed;
	static const All UnsignedShort4444Rev;
	static const All UnsignedShort4444Reversed;
	static const All UnsignedShort1555Rev;
	static const All UnsignedShort1555Reversed;
	static const All UnsignedInt8888Rev;
	static const All UnsignedInt8888Reversed;
	static const All UnsignedInt2101010Rev;
	static const All UnsignedInt2101010Reversed;
	static const All TextureMaxClampSSgix;
	static const All TextureMaxClampTSgix;
	static const All TextureMaxClampRSgix;
	static const All MirroredRepeat;
	static const All MirroredRepeatArb;
	static const All MirroredRepeatIbm;
	static const All RgbS3tc;
	static const All Rgb4S3tc;
	static const All RgbaS3tc;
	static const All Rgba4S3tc;
	static const All RgbaDxt5S3tc;
	static const All Rgba4Dxt5S3tc;
	static const All VertexPreclipSgix;
	static const All VertexPreclipHintSgix;
	static const All CompressedRgbS3tcDxt1Ext;
	static const All CompressedRgbaS3tcDxt1Ext;
	static const All CompressedRgbaS3tcDxt3Ext;
	static const All CompressedRgbaS3tcDxt5Ext;
	static const All ParallelArraysIntel;
	static const All VertexArrayParallelPointersIntel;
	static const All NormalArrayParallelPointersIntel;
	static const All ColorArrayParallelPointersIntel;
	static const All TextureCoordArrayParallelPointersIntel;
	static const All PerfqueryDonotFlushIntel;
	static const All PerfqueryFlushIntel;
	static const All PerfqueryWaitIntel;
	static const All TextureMemoryLayoutIntel;
	static const All FragmentLightingSgix;
	static const All FragmentColorMaterialSgix;
	static const All FragmentColorMaterialFaceSgix;
	static const All FragmentColorMaterialParameterSgix;
	static const All MaxFragmentLightsSgix;
	static const All MaxActiveLightsSgix;
	static const All CurrentRasterNormalSgix;
	static const All LightEnvModeSgix;
	static const All FragmentLightModelLocalViewerSgix;
	static const All FragmentLightModelTwoSideSgix;
	static const All FragmentLightModelAmbientSgix;
	static const All FragmentLightModelNormalInterpolationSgix;
	static const All FragmentLight0Sgix;
	static const All FragmentLight1Sgix;
	static const All FragmentLight2Sgix;
	static const All FragmentLight3Sgix;
	static const All FragmentLight4Sgix;
	static const All FragmentLight5Sgix;
	static const All FragmentLight6Sgix;
	static const All FragmentLight7Sgix;
	static const All PackResampleSgix;
	static const All UnpackResampleSgix;
	static const All ResampleReplicateSgix;
	static const All ResampleZeroFillSgix;
	static const All ResampleDecimateSgix;
	static const All TangentArrayExt;
	static const All BinormalArrayExt;
	static const All CurrentTangentExt;
	static const All CurrentBinormalExt;
	static const All TangentArrayTypeExt;
	static const All TangentArrayStrideExt;
	static const All BinormalArrayTypeExt;
	static const All BinormalArrayStrideExt;
	static const All TangentArrayPointerExt;
	static const All BinormalArrayPointerExt;
	static const All Map1TangentExt;
	static const All Map2TangentExt;
	static const All Map1BinormalExt;
	static const All Map2BinormalExt;
	static const All NearestClipmapNearestSgix;
	static const All NearestClipmapLinearSgix;
	static const All LinearClipmapNearestSgix;
	static const All FogCoordinateSource;
	static const All FogCoordinateSourceExt;
	static const All FogCoordSrc;
	static const All FogCoord;
	static const All FogCoordinate;
	static const All FogCoordinateExt;
	static const All FragmentDepth;
	static const All FragmentDepthExt;
	static const All CurrentFogCoord;
	static const All CurrentFogCoordinate;
	static const All CurrentFogCoordinateExt;
	static const All FogCoordArrayType;
	static const All FogCoordinateArrayType;
	static const All FogCoordinateArrayTypeExt;
	static const All FogCoordArrayStride;
	static const All FogCoordinateArrayStride;
	static const All FogCoordinateArrayStrideExt;
	static const All FogCoordArrayPointer;
	static const All FogCoordinateArrayPointer;
	static const All FogCoordinateArrayPointerExt;
	static const All FogCoordArray;
	static const All FogCoordinateArray;
	static const All FogCoordinateArrayExt;
	static const All ColorSum;
	static const All ColorSumArb;
	static const All ColorSumExt;
	static const All CurrentSecondaryColor;
	static const All CurrentSecondaryColorExt;
	static const All SecondaryColorArraySize;
	static const All SecondaryColorArraySizeExt;
	static const All SecondaryColorArrayType;
	static const All SecondaryColorArrayTypeExt;
	static const All SecondaryColorArrayStride;
	static const All SecondaryColorArrayStrideExt;
	static const All SecondaryColorArrayPointer;
	static const All SecondaryColorArrayPointerExt;
	static const All SecondaryColorArray;
	static const All SecondaryColorArrayExt;
	static const All CurrentRasterSecondaryColor;
	static const All RgbIccSgix;
	static const All RgbaIccSgix;
	static const All AlphaIccSgix;
	static const All LuminanceIccSgix;
	static const All IntensityIccSgix;
	static const All LuminanceAlphaIccSgix;
	static const All R5G6B5IccSgix;
	static const All R5G6B5A8IccSgix;
	static const All Alpha16IccSgix;
	static const All Luminance16IccSgix;
	static const All Intensity16IccSgix;
	static const All Luminance16Alpha8IccSgix;
	static const All AliasedPointSizeRange;
	static const All AliasedLineWidthRange;
	static const All ScreenCoordinatesRend;
	static const All InvertedScreenWRend;
	static const All Texture0;
	static const All Texture0Arb;
	static const All Texture1;
	static const All Texture1Arb;
	static const All Texture2;
	static const All Texture2Arb;
	static const All Texture3;
	static const All Texture3Arb;
	static const All Texture4;
	static const All Texture4Arb;
	static const All Texture5;
	static const All Texture5Arb;
	static const All Texture6;
	static const All Texture6Arb;
	static const All Texture7;
	static const All Texture7Arb;
	static const All Texture8;
	static const All Texture8Arb;
	static const All Texture9;
	static const All Texture9Arb;
	static const All Texture10;
	static const All Texture10Arb;
	static const All Texture11;
	static const All Texture11Arb;
	static const All Texture12;
	static const All Texture12Arb;
	static const All Texture13;
	static const All Texture13Arb;
	static const All Texture14;
	static const All Texture14Arb;
	static const All Texture15;
	static const All Texture15Arb;
	static const All Texture16;
	static const All Texture16Arb;
	static const All Texture17;
	static const All Texture17Arb;
	static const All Texture18;
	static const All Texture18Arb;
	static const All Texture19;
	static const All Texture19Arb;
	static const All Texture20;
	static const All Texture20Arb;
	static const All Texture21;
	static const All Texture21Arb;
	static const All Texture22;
	static const All Texture22Arb;
	static const All Texture23;
	static const All Texture23Arb;
	static const All Texture24;
	static const All Texture24Arb;
	static const All Texture25;
	static const All Texture25Arb;
	static const All Texture26;
	static const All Texture26Arb;
	static const All Texture27;
	static const All Texture27Arb;
	static const All Texture28;
	static const All Texture28Arb;
	static const All Texture29;
	static const All Texture29Arb;
	static const All Texture30;
	static const All Texture30Arb;
	static const All Texture31;
	static const All Texture31Arb;
	static const All ActiveTexture;
	static const All ActiveTextureArb;
	static const All ClientActiveTexture;
	static const All ClientActiveTextureArb;
	static const All MaxTextureUnits;
	static const All MaxTextureUnitsArb;
	static const All PathTransposeModelviewMatrixNv;
	static const All TransposeModelviewMatrix;
	static const All TransposeModelviewMatrixArb;
	static const All PathTransposeProjectionMatrixNv;
	static const All TransposeProjectionMatrix;
	static const All TransposeProjectionMatrixArb;
	static const All TransposeTextureMatrix;
	static const All TransposeTextureMatrixArb;
	static const All TransposeColorMatrix;
	static const All TransposeColorMatrixArb;
	static const All Subtract;
	static const All SubtractArb;
	static const All MaxRenderbufferSize;
	static const All MaxRenderbufferSizeExt;
	static const All CompressedAlpha;
	static const All CompressedAlphaArb;
	static const All CompressedLuminance;
	static const All CompressedLuminanceArb;
	static const All CompressedLuminanceAlpha;
	static const All CompressedLuminanceAlphaArb;
	static const All CompressedIntensity;
	static const All CompressedIntensityArb;
	static const All CompressedRgb;
	static const All CompressedRgbArb;
	static const All CompressedRgba;
	static const All CompressedRgbaArb;
	static const All TextureCompressionHint;
	static const All TextureCompressionHintArb;
	static const All UniformBlockReferencedByTessControlShader;
	static const All UniformBlockReferencedByTessEvaluationShader;
	static const All AllCompletedNv;
	static const All FenceStatusNv;
	static const All FenceConditionNv;
	static const All TextureRectangle;
	static const All TextureRectangleArb;
	static const All TextureRectangleNv;
	static const All TextureBindingRectangle;
	static const All TextureBindingRectangleArb;
	static const All TextureBindingRectangleNv;
	static const All ProxyTextureRectangle;
	static const All ProxyTextureRectangleArb;
	static const All ProxyTextureRectangleNv;
	static const All MaxRectangleTextureSize;
	static const All MaxRectangleTextureSizeArb;
	static const All MaxRectangleTextureSizeNv;
	static const All DepthStencil;
	static const All DepthStencilExt;
	static const All DepthStencilNv;
	static const All UnsignedInt248;
	static const All UnsignedInt248Ext;
	static const All UnsignedInt248Nv;
	static const All MaxTextureLodBias;
	static const All MaxTextureLodBiasExt;
	static const All TextureMaxAnisotropyExt;
	static const All MaxTextureMaxAnisotropyExt;
	static const All TextureFilterControl;
	static const All TextureFilterControlExt;
	static const All TextureLodBias;
	static const All TextureLodBiasExt;
	static const All Modelview1StackDepthExt;
	static const All Combine4Nv;
	static const All MaxShininessNv;
	static const All MaxSpotExponentNv;
	static const All Modelview1MatrixExt;
	static const All IncrWrap;
	static const All IncrWrapExt;
	static const All DecrWrap;
	static const All DecrWrapExt;
	static const All VertexWeightingExt;
	static const All Modelview1Arb;
	static const All Modelview1Ext;
	static const All CurrentVertexWeightExt;
	static const All VertexWeightArrayExt;
	static const All VertexWeightArraySizeExt;
	static const All VertexWeightArrayTypeExt;
	static const All VertexWeightArrayStrideExt;
	static const All VertexWeightArrayPointerExt;
	static const All NormalMap;
	static const All NormalMapArb;
	static const All NormalMapExt;
	static const All NormalMapNv;
	static const All ReflectionMap;
	static const All ReflectionMapArb;
	static const All ReflectionMapExt;
	static const All ReflectionMapNv;
	static const All TextureCubeMap;
	static const All TextureCubeMapArb;
	static const All TextureCubeMapExt;
	static const All TextureBindingCubeMap;
	static const All TextureBindingCubeMapArb;
	static const All TextureBindingCubeMapExt;
	static const All TextureCubeMapPositiveX;
	static const All TextureCubeMapPositiveXArb;
	static const All TextureCubeMapPositiveXExt;
	static const All TextureCubeMapNegativeX;
	static const All TextureCubeMapNegativeXArb;
	static const All TextureCubeMapNegativeXExt;
	static const All TextureCubeMapPositiveY;
	static const All TextureCubeMapPositiveYArb;
	static const All TextureCubeMapPositiveYExt;
	static const All TextureCubeMapNegativeY;
	static const All TextureCubeMapNegativeYArb;
	static const All TextureCubeMapNegativeYExt;
	static const All TextureCubeMapPositiveZ;
	static const All TextureCubeMapPositiveZArb;
	static const All TextureCubeMapPositiveZExt;
	static const All TextureCubeMapNegativeZ;
	static const All TextureCubeMapNegativeZArb;
	static const All TextureCubeMapNegativeZExt;
	static const All ProxyTextureCubeMap;
	static const All ProxyTextureCubeMapArb;
	static const All ProxyTextureCubeMapExt;
	static const All MaxCubeMapTextureSize;
	static const All MaxCubeMapTextureSizeArb;
	static const All MaxCubeMapTextureSizeExt;
	static const All VertexArrayRangeApple;
	static const All VertexArrayRangeNv;
	static const All VertexArrayRangeLengthApple;
	static const All VertexArrayRangeLengthNv;
	static const All VertexArrayRangeValidNv;
	static const All VertexArrayStorageHintApple;
	static const All MaxVertexArrayRangeElementNv;
	static const All VertexArrayRangePointerApple;
	static const All VertexArrayRangePointerNv;
	static const All RegisterCombinersNv;
	static const All VariableANv;
	static const All VariableBNv;
	static const All VariableCNv;
	static const All VariableDNv;
	static const All VariableENv;
	static const All VariableFNv;
	static const All VariableGNv;
	static const All ConstantColor0Nv;
	static const All ConstantColor1Nv;
	static const All PrimaryColorNv;
	static const All SecondaryColorNv;
	static const All Spare0Nv;
	static const All Spare1Nv;
	static const All DiscardNv;
	static const All ETimesFNv;
	static const All Spare0PlusSecondaryColorNv;
	static const All VertexArrayRangeWithoutFlushNv;
	static const All MultisampleFilterHintNv;
	static const All PerStageConstantsNv;
	static const All UnsignedIdentityNv;
	static const All UnsignedInvertNv;
	static const All ExpandNormalNv;
	static const All ExpandNegateNv;
	static const All HalfBiasNormalNv;
	static const All HalfBiasNegateNv;
	static const All SignedIdentityNv;
	static const All SignedNegateNv;
	static const All ScaleByTwoNv;
	static const All ScaleByFourNv;
	static const All ScaleByOneHalfNv;
	static const All BiasByNegativeOneHalfNv;
	static const All CombinerInputNv;
	static const All CombinerMappingNv;
	static const All CombinerComponentUsageNv;
	static const All CombinerAbDotProductNv;
	static const All CombinerCdDotProductNv;
	static const All CombinerMuxSumNv;
	static const All CombinerScaleNv;
	static const All CombinerBiasNv;
	static const All CombinerAbOutputNv;
	static const All CombinerCdOutputNv;
	static const All CombinerSumOutputNv;
	static const All MaxGeneralCombinersNv;
	static const All NumGeneralCombinersNv;
	static const All ColorSumClampNv;
	static const All Combiner0Nv;
	static const All Combiner1Nv;
	static const All Combiner2Nv;
	static const All Combiner3Nv;
	static const All Combiner4Nv;
	static const All Combiner5Nv;
	static const All Combiner6Nv;
	static const All Combiner7Nv;
	static const All PrimitiveRestartNv;
	static const All PrimitiveRestartIndexNv;
	static const All FogDistanceModeNv;
	static const All EyeRadialNv;
	static const All EyePlaneAbsoluteNv;
	static const All EmbossLightNv;
	static const All EmbossConstantNv;
	static const All EmbossMapNv;
	static const All RedMinClampIngr;
	static const All GreenMinClampIngr;
	static const All BlueMinClampIngr;
	static const All AlphaMinClampIngr;
	static const All RedMaxClampIngr;
	static const All GreenMaxClampIngr;
	static const All BlueMaxClampIngr;
	static const All AlphaMaxClampIngr;
	static const All InterlaceReadIngr;
	static const All Combine;
	static const All CombineArb;
	static const All CombineExt;
	static const All CombineRgb;
	static const All CombineRgbArb;
	static const All CombineRgbExt;
	static const All CombineAlpha;
	static const All CombineAlphaArb;
	static const All CombineAlphaExt;
	static const All RgbScale;
	static const All RgbScaleArb;
	static const All RgbScaleExt;
	static const All AddSigned;
	static const All AddSignedArb;
	static const All AddSignedExt;
	static const All Interpolate;
	static const All InterpolateArb;
	static const All InterpolateExt;
	static const All Constant;
	static const All ConstantArb;
	static const All ConstantExt;
	static const All ConstantNv;
	static const All PrimaryColor;
	static const All PrimaryColorArb;
	static const All PrimaryColorExt;
	static const All Previous;
	static const All PreviousArb;
	static const All PreviousExt;
	static const All Source0Rgb;
	static const All Source0RgbArb;
	static const All Source0RgbExt;
	static const All Src0Rgb;
	static const All Source1Rgb;
	static const All Source1RgbArb;
	static const All Source1RgbExt;
	static const All Src1Rgb;
	static const All Source2Rgb;
	static const All Source2RgbArb;
	static const All Source2RgbExt;
	static const All Src2Rgb;
	static const All Source3RgbNv;
	static const All Source0Alpha;
	static const All Source0AlphaArb;
	static const All Source0AlphaExt;
	static const All Src0Alpha;
	static const All Source1Alpha;
	static const All Source1AlphaArb;
	static const All Source1AlphaExt;
	static const All Src1Alpha;
	static const All Source2Alpha;
	static const All Source2AlphaArb;
	static const All Source2AlphaExt;
	static const All Src2Alpha;
	static const All Source3AlphaNv;
	static const All Operand0Rgb;
	static const All Operand0RgbArb;
	static const All Operand0RgbExt;
	static const All Operand1Rgb;
	static const All Operand1RgbArb;
	static const All Operand1RgbExt;
	static const All Operand2Rgb;
	static const All Operand2RgbArb;
	static const All Operand2RgbExt;
	static const All Operand3RgbNv;
	static const All Operand0Alpha;
	static const All Operand0AlphaArb;
	static const All Operand0AlphaExt;
	static const All Operand1Alpha;
	static const All Operand1AlphaArb;
	static const All Operand1AlphaExt;
	static const All Operand2Alpha;
	static const All Operand2AlphaArb;
	static const All Operand2AlphaExt;
	static const All Operand3AlphaNv;
	static const All PackSubsampleRateSgix;
	static const All UnpackSubsampleRateSgix;
	static const All PixelSubsample4444Sgix;
	static const All PixelSubsample2424Sgix;
	static const All PixelSubsample4242Sgix;
	static const All PerturbExt;
	static const All TextureNormalExt;
	static const All LightModelSpecularVectorApple;
	static const All TransformHintApple;
	static const All UnpackClientStorageApple;
	static const All BufferObjectApple;
	static const All StorageClientApple;
	static const All VertexArrayBinding;
	static const All VertexArrayBindingApple;
	static const All TextureRangeLengthApple;
	static const All TextureRangePointerApple;
	static const All Ycbcr422Apple;
	static const All UnsignedShort88Apple;
	static const All UnsignedShort88Mesa;
	static const All UnsignedShort88RevApple;
	static const All UnsignedShort88RevMesa;
	static const All TextureStorageHintApple;
	static const All StoragePrivateApple;
	static const All StorageCachedApple;
	static const All StorageSharedApple;
	static const All ReplacementCodeArraySun;
	static const All ReplacementCodeArrayTypeSun;
	static const All ReplacementCodeArrayStrideSun;
	static const All ReplacementCodeArrayPointerSun;
	static const All R1uiV3fSun;
	static const All R1uiC4ubV3fSun;
	static const All R1uiC3fV3fSun;
	static const All R1uiN3fV3fSun;
	static const All R1uiC4fN3fV3fSun;
	static const All R1uiT2fV3fSun;
	static const All R1uiT2fN3fV3fSun;
	static const All R1uiT2fC4fN3fV3fSun;
	static const All SliceAccumSun;
	static const All QuadMeshSun;
	static const All TriangleMeshSun;
	static const All VertexProgram;
	static const All VertexProgramArb;
	static const All VertexProgramNv;
	static const All VertexStateProgramNv;
	static const All ArrayEnabled;
	static const All VertexAttribArrayEnabled;
	static const All VertexAttribArrayEnabledArb;
	static const All AttribArraySizeNv;
	static const All VertexAttribArraySize;
	static const All VertexAttribArraySizeArb;
	static const All AttribArrayStrideNv;
	static const All VertexAttribArrayStride;
	static const All VertexAttribArrayStrideArb;
	static const All ArrayType;
	static const All AttribArrayTypeNv;
	static const All VertexAttribArrayType;
	static const All VertexAttribArrayTypeArb;
	static const All CurrentAttribNv;
	static const All CurrentVertexAttrib;
	static const All CurrentVertexAttribArb;
	static const All ProgramLength;
	static const All ProgramLengthArb;
	static const All ProgramLengthNv;
	static const All ProgramString;
	static const All ProgramStringArb;
	static const All ProgramStringNv;
	static const All ModelviewProjectionNv;
	static const All IdentityNv;
	static const All InverseNv;
	static const All TransposeNv;
	static const All InverseTransposeNv;
	static const All MaxProgramMatrixStackDepthArb;
	static const All MaxTrackMatrixStackDepthNv;
	static const All MaxProgramMatricesArb;
	static const All MaxTrackMatricesNv;
	static const All Matrix0Nv;
	static const All Matrix1Nv;
	static const All Matrix2Nv;
	static const All Matrix3Nv;
	static const All Matrix4Nv;
	static const All Matrix5Nv;
	static const All Matrix6Nv;
	static const All Matrix7Nv;
	static const All CurrentMatrixStackDepthArb;
	static const All CurrentMatrixStackDepthNv;
	static const All CurrentMatrixArb;
	static const All CurrentMatrixNv;
	static const All ProgramPointSize;
	static const All ProgramPointSizeArb;
	static const All ProgramPointSizeExt;
	static const All VertexProgramPointSize;
	static const All VertexProgramPointSizeArb;
	static const All VertexProgramPointSizeNv;
	static const All VertexProgramTwoSide;
	static const All VertexProgramTwoSideArb;
	static const All VertexProgramTwoSideNv;
	static const All ProgramParameterNv;
	static const All ArrayPointer;
	static const All AttribArrayPointerNv;
	static const All VertexAttribArrayPointer;
	static const All VertexAttribArrayPointerArb;
	static const All ProgramTargetNv;
	static const All ProgramResidentNv;
	static const All TrackMatrixNv;
	static const All TrackMatrixTransformNv;
	static const All VertexProgramBindingNv;
	static const All ProgramErrorPositionArb;
	static const All ProgramErrorPositionNv;
	static const All OffsetTextureRectangleNv;
	static const All OffsetTextureRectangleScaleNv;
	static const All DotProductTextureRectangleNv;
	static const All DepthClamp;
	static const All DepthClampNv;
	static const All VertexAttribArray0Nv;
	static const All VertexAttribArray1Nv;
	static const All VertexAttribArray2Nv;
	static const All VertexAttribArray3Nv;
	static const All VertexAttribArray4Nv;
	static const All VertexAttribArray5Nv;
	static const All VertexAttribArray6Nv;
	static const All VertexAttribArray7Nv;
	static const All VertexAttribArray8Nv;
	static const All VertexAttribArray9Nv;
	static const All VertexAttribArray10Nv;
	static const All VertexAttribArray11Nv;
	static const All VertexAttribArray12Nv;
	static const All VertexAttribArray13Nv;
	static const All VertexAttribArray14Nv;
	static const All VertexAttribArray15Nv;
	static const All Map1VertexAttrib04Nv;
	static const All Map1VertexAttrib14Nv;
	static const All Map1VertexAttrib24Nv;
	static const All Map1VertexAttrib34Nv;
	static const All Map1VertexAttrib44Nv;
	static const All Map1VertexAttrib54Nv;
	static const All Map1VertexAttrib64Nv;
	static const All Map1VertexAttrib74Nv;
	static const All Map1VertexAttrib84Nv;
	static const All Map1VertexAttrib94Nv;
	static const All Map1VertexAttrib104Nv;
	static const All Map1VertexAttrib114Nv;
	static const All Map1VertexAttrib124Nv;
	static const All Map1VertexAttrib134Nv;
	static const All Map1VertexAttrib144Nv;
	static const All Map1VertexAttrib154Nv;
	static const All Map2VertexAttrib04Nv;
	static const All Map2VertexAttrib14Nv;
	static const All Map2VertexAttrib24Nv;
	static const All Map2VertexAttrib34Nv;
	static const All Map2VertexAttrib44Nv;
	static const All Map2VertexAttrib54Nv;
	static const All Map2VertexAttrib64Nv;
	static const All Map2VertexAttrib74Nv;
	static const All ProgramBinding;
	static const All ProgramBindingArb;
	static const All Map2VertexAttrib84Nv;
	static const All Map2VertexAttrib94Nv;
	static const All Map2VertexAttrib104Nv;
	static const All Map2VertexAttrib114Nv;
	static const All Map2VertexAttrib124Nv;
	static const All Map2VertexAttrib134Nv;
	static const All Map2VertexAttrib144Nv;
	static const All Map2VertexAttrib154Nv;
	static const All TextureCompressedImageSize;
	static const All TextureCompressedImageSizeArb;
	static const All TextureCompressed;
	static const All TextureCompressedArb;
	static const All NumCompressedTextureFormats;
	static const All NumCompressedTextureFormatsArb;
	static const All CompressedTextureFormats;
	static const All CompressedTextureFormatsArb;
	static const All MaxVertexUnitsArb;
	static const All ActiveVertexUnitsArb;
	static const All WeightSumUnityArb;
	static const All VertexBlendArb;
	static const All CurrentWeightArb;
	static const All WeightArrayTypeArb;
	static const All WeightArrayStrideArb;
	static const All WeightArraySizeArb;
	static const All WeightArrayPointerArb;
	static const All WeightArrayArb;
	static const All Dot3Rgb;
	static const All Dot3RgbArb;
	static const All Dot3Rgba;
	static const All Dot3RgbaArb;
	static const All CompressedRgbFxt13Dfx;
	static const All CompressedRgbaFxt13Dfx;
	static const All Multisample3Dfx;
	static const All SampleBuffers3Dfx;
	static const All Samples3Dfx;
	static const All Eval2DNv;
	static const All EvalTriangular2DNv;
	static const All MapTessellationNv;
	static const All MapAttribUOrderNv;
	static const All MapAttribVOrderNv;
	static const All EvalFractionalTessellationNv;
	static const All EvalVertexAttrib0Nv;
	static const All EvalVertexAttrib1Nv;
	static const All EvalVertexAttrib2Nv;
	static const All EvalVertexAttrib3Nv;
	static const All EvalVertexAttrib4Nv;
	static const All EvalVertexAttrib5Nv;
	static const All EvalVertexAttrib6Nv;
	static const All EvalVertexAttrib7Nv;
	static const All EvalVertexAttrib8Nv;
	static const All EvalVertexAttrib9Nv;
	static const All EvalVertexAttrib10Nv;
	static const All EvalVertexAttrib11Nv;
	static const All EvalVertexAttrib12Nv;
	static const All EvalVertexAttrib13Nv;
	static const All EvalVertexAttrib14Nv;
	static const All EvalVertexAttrib15Nv;
	static const All MaxMapTessellationNv;
	static const All MaxRationalEvalOrderNv;
	static const All MaxProgramPatchAttribsNv;
	static const All RgbaUnsignedDotProductMappingNv;
	static const All UnsignedIntS8S888Nv;
	static const All UnsignedInt88S8S8RevNv;
	static const All DsdtMagIntensityNv;
	static const All ShaderConsistentNv;
	static const All TextureShaderNv;
	static const All ShaderOperationNv;
	static const All CullModesNv;
	static const All OffsetTexture2DMatrixNv;
	static const All OffsetTextureMatrixNv;
	static const All OffsetTexture2DScaleNv;
	static const All OffsetTextureScaleNv;
	static const All OffsetTexture2DBiasNv;
	static const All OffsetTextureBiasNv;
	static const All PreviousTextureInputNv;
	static const All ConstEyeNv;
	static const All PassThroughNv;
	static const All CullFragmentNv;
	static const All OffsetTexture2DNv;
	static const All DependentArTexture2DNv;
	static const All DependentGbTexture2DNv;
	static const All SurfaceStateNv;
	static const All DotProductNv;
	static const All DotProductDepthReplaceNv;
	static const All DotProductTexture2DNv;
	static const All DotProductTexture3DNv;
	static const All DotProductTextureCubeMapNv;
	static const All DotProductDiffuseCubeMapNv;
	static const All DotProductReflectCubeMapNv;
	static const All DotProductConstEyeReflectCubeMapNv;
	static const All HiloNv;
	static const All DsdtNv;
	static const All DsdtMagNv;
	static const All DsdtMagVibNv;
	static const All Hilo16Nv;
	static const All SignedHiloNv;
	static const All SignedHilo16Nv;
	static const All SignedRgbaNv;
	static const All SignedRgba8Nv;
	static const All SurfaceRegisteredNv;
	static const All SignedRgbNv;
	static const All SignedRgb8Nv;
	static const All SurfaceMappedNv;
	static const All SignedLuminanceNv;
	static const All SignedLuminance8Nv;
	static const All SignedLuminanceAlphaNv;
	static const All SignedLuminance8Alpha8Nv;
	static const All SignedAlphaNv;
	static const All SignedAlpha8Nv;
	static const All SignedIntensityNv;
	static const All SignedIntensity8Nv;
	static const All Dsdt8Nv;
	static const All Dsdt8Mag8Nv;
	static const All Dsdt8Mag8Intensity8Nv;
	static const All SignedRgbUnsignedAlphaNv;
	static const All SignedRgb8UnsignedAlpha8Nv;
	static const All HiScaleNv;
	static const All LoScaleNv;
	static const All DsScaleNv;
	static const All DtScaleNv;
	static const All MagnitudeScaleNv;
	static const All VibranceScaleNv;
	static const All HiBiasNv;
	static const All LoBiasNv;
	static const All DsBiasNv;
	static const All DtBiasNv;
	static const All MagnitudeBiasNv;
	static const All VibranceBiasNv;
	static const All TextureBorderValuesNv;
	static const All TextureHiSizeNv;
	static const All TextureLoSizeNv;
	static const All TextureDsSizeNv;
	static const All TextureDtSizeNv;
	static const All TextureMagSizeNv;
	static const All Modelview2Arb;
	static const All Modelview3Arb;
	static const All Modelview4Arb;
	static const All Modelview5Arb;
	static const All Modelview6Arb;
	static const All Modelview7Arb;
	static const All Modelview8Arb;
	static const All Modelview9Arb;
	static const All Modelview10Arb;
	static const All Modelview11Arb;
	static const All Modelview12Arb;
	static const All Modelview13Arb;
	static const All Modelview14Arb;
	static const All Modelview15Arb;
	static const All Modelview16Arb;
	static const All Modelview17Arb;
	static const All Modelview18Arb;
	static const All Modelview19Arb;
	static const All Modelview20Arb;
	static const All Modelview21Arb;
	static const All Modelview22Arb;
	static const All Modelview23Arb;
	static const All Modelview24Arb;
	static const All Modelview25Arb;
	static const All Modelview26Arb;
	static const All Modelview27Arb;
	static const All Modelview28Arb;
	static const All Modelview29Arb;
	static const All Modelview30Arb;
	static const All Modelview31Arb;
	static const All Dot3RgbExt;
	static const All Dot3RgbaExt;
	static const All ProgramBinaryLength;
	static const All MirrorClampAti;
	static const All MirrorClampExt;
	static const All MirrorClampToEdge;
	static const All MirrorClampToEdgeAti;
	static const All MirrorClampToEdgeExt;
	static const All ModulateAddAti;
	static const All ModulateSignedAddAti;
	static const All ModulateSubtractAti;
	static const All SetAmd;
	static const All ReplaceValueAmd;
	static const All StencilOpValueAmd;
	static const All StencilBackOpValueAmd;
	static const All VertexAttribArrayLong;
	static const All OcclusionQueryEventMaskAmd;
	static const All YcbcrMesa;
	static const All PackInvertMesa;
	static const All Texture1DStackMesax;
	static const All Texture2DStackMesax;
	static const All ProxyTexture1DStackMesax;
	static const All ProxyTexture2DStackMesax;
	static const All Texture1DStackBindingMesax;
	static const All Texture2DStackBindingMesax;
	static const All StaticAti;
	static const All DynamicAti;
	static const All PreserveAti;
	static const All DiscardAti;
	static const All BufferSize;
	static const All BufferSizeArb;
	static const All ObjectBufferSizeAti;
	static const All BufferUsage;
	static const All BufferUsageArb;
	static const All ObjectBufferUsageAti;
	static const All ArrayObjectBufferAti;
	static const All ArrayObjectOffsetAti;
	static const All ElementArrayAti;
	static const All ElementArrayTypeAti;
	static const All ElementArrayPointerAti;
	static const All MaxVertexStreamsAti;
	static const All VertexStream0Ati;
	static const All VertexStream1Ati;
	static const All VertexStream2Ati;
	static const All VertexStream3Ati;
	static const All VertexStream4Ati;
	static const All VertexStream5Ati;
	static const All VertexStream6Ati;
	static const All VertexStream7Ati;
	static const All VertexSourceAti;
	static const All BumpRotMatrixAti;
	static const All BumpRotMatrixSizeAti;
	static const All BumpNumTexUnitsAti;
	static const All BumpTexUnitsAti;
	static const All DudvAti;
	static const All Du8Dv8Ati;
	static const All BumpEnvmapAti;
	static const All BumpTargetAti;
	static const All VertexShaderExt;
	static const All VertexShaderBindingExt;
	static const All OpIndexExt;
	static const All OpNegateExt;
	static const All OpDot3Ext;
	static const All OpDot4Ext;
	static const All OpMulExt;
	static const All OpAddExt;
	static const All OpMaddExt;
	static const All OpFracExt;
	static const All OpMaxExt;
	static const All OpMinExt;
	static const All OpSetGeExt;
	static const All OpSetLtExt;
	static const All OpClampExt;
	static const All OpFloorExt;
	static const All OpRoundExt;
	static const All OpExpBase2Ext;
	static const All OpLogBase2Ext;
	static const All OpPowerExt;
	static const All OpRecipExt;
	static const All OpRecipSqrtExt;
	static const All OpSubExt;
	static const All OpCrossProductExt;
	static const All OpMultiplyMatrixExt;
	static const All OpMovExt;
	static const All OutputVertexExt;
	static const All OutputColor0Ext;
	static const All OutputColor1Ext;
	static const All OutputTextureCoord0Ext;
	static const All OutputTextureCoord1Ext;
	static const All OutputTextureCoord2Ext;
	static const All OutputTextureCoord3Ext;
	static const All OutputTextureCoord4Ext;
	static const All OutputTextureCoord5Ext;
	static const All OutputTextureCoord6Ext;
	static const All OutputTextureCoord7Ext;
	static const All OutputTextureCoord8Ext;
	static const All OutputTextureCoord9Ext;
	static const All OutputTextureCoord10Ext;
	static const All OutputTextureCoord11Ext;
	static const All OutputTextureCoord12Ext;
	static const All OutputTextureCoord13Ext;
	static const All OutputTextureCoord14Ext;
	static const All OutputTextureCoord15Ext;
	static const All OutputTextureCoord16Ext;
	static const All OutputTextureCoord17Ext;
	static const All OutputTextureCoord18Ext;
	static const All OutputTextureCoord19Ext;
	static const All OutputTextureCoord20Ext;
	static const All OutputTextureCoord21Ext;
	static const All OutputTextureCoord22Ext;
	static const All OutputTextureCoord23Ext;
	static const All OutputTextureCoord24Ext;
	static const All OutputTextureCoord25Ext;
	static const All OutputTextureCoord26Ext;
	static const All OutputTextureCoord27Ext;
	static const All OutputTextureCoord28Ext;
	static const All OutputTextureCoord29Ext;
	static const All OutputTextureCoord30Ext;
	static const All OutputTextureCoord31Ext;
	static const All OutputFogExt;
	static const All ScalarExt;
	static const All VectorExt;
	static const All MatrixExt;
	static const All VariantExt;
	static const All InvariantExt;
	static const All LocalConstantExt;
	static const All LocalExt;
	static const All MaxVertexShaderInstructionsExt;
	static const All MaxVertexShaderVariantsExt;
	static const All MaxVertexShaderInvariantsExt;
	static const All MaxVertexShaderLocalConstantsExt;
	static const All MaxVertexShaderLocalsExt;
	static const All MaxOptimizedVertexShaderInstructionsExt;
	static const All MaxOptimizedVertexShaderVariantsExt;
	static const All MaxOptimizedVertexShaderLocalConstantsExt;
	static const All MaxOptimizedVertexShaderInvariantsExt;
	static const All MaxOptimizedVertexShaderLocalsExt;
	static const All VertexShaderInstructionsExt;
	static const All VertexShaderVariantsExt;
	static const All VertexShaderInvariantsExt;
	static const All VertexShaderLocalConstantsExt;
	static const All VertexShaderLocalsExt;
	static const All VertexShaderOptimizedExt;
	static const All XExt;
	static const All YExt;
	static const All ZExt;
	static const All WExt;
	static const All NegativeXExt;
	static const All NegativeYExt;
	static const All NegativeZExt;
	static const All NegativeWExt;
	static const All ZeroExt;
	static const All OneExt;
	static const All NegativeOneExt;
	static const All NormalizedRangeExt;
	static const All FullRangeExt;
	static const All CurrentVertexExt;
	static const All MvpMatrixExt;
	static const All VariantValueExt;
	static const All VariantDatatypeExt;
	static const All VariantArrayStrideExt;
	static const All VariantArrayTypeExt;
	static const All VariantArrayExt;
	static const All VariantArrayPointerExt;
	static const All InvariantValueExt;
	static const All InvariantDatatypeExt;
	static const All LocalConstantValueExt;
	static const All LocalConstantDatatypeExt;
	static const All PnTrianglesAti;
	static const All MaxPnTrianglesTesselationLevelAti;
	static const All PnTrianglesPointModeAti;
	static const All PnTrianglesNormalModeAti;
	static const All PnTrianglesTesselationLevelAti;
	static const All PnTrianglesPointModeLinearAti;
	static const All PnTrianglesPointModeCubicAti;
	static const All PnTrianglesNormalModeLinearAti;
	static const All PnTrianglesNormalModeQuadraticAti;
	static const All VboFreeMemoryAti;
	static const All TextureFreeMemoryAti;
	static const All RenderbufferFreeMemoryAti;
	static const All NumProgramBinaryFormats;
	static const All ProgramBinaryFormats;
	static const All StencilBackFunc;
	static const All StencilBackFuncAti;
	static const All StencilBackFail;
	static const All StencilBackFailAti;
	static const All StencilBackPassDepthFail;
	static const All StencilBackPassDepthFailAti;
	static const All StencilBackPassDepthPass;
	static const All StencilBackPassDepthPassAti;
	static const All FragmentProgram;
	static const All FragmentProgramArb;
	static const All ProgramAluInstructionsArb;
	static const All ProgramTexInstructionsArb;
	static const All ProgramTexIndirectionsArb;
	static const All ProgramNativeAluInstructionsArb;
	static const All ProgramNativeTexInstructionsArb;
	static const All ProgramNativeTexIndirectionsArb;
	static const All MaxProgramAluInstructionsArb;
	static const All MaxProgramTexInstructionsArb;
	static const All MaxProgramTexIndirectionsArb;
	static const All MaxProgramNativeAluInstructionsArb;
	static const All MaxProgramNativeTexInstructionsArb;
	static const All MaxProgramNativeTexIndirectionsArb;
	static const All Rgba32f;
	static const All Rgba32fArb;
	static const All RgbaFloat32Apple;
	static const All RgbaFloat32Ati;
	static const All Rgb32f;
	static const All Rgb32fArb;
	static const All RgbFloat32Apple;
	static const All RgbFloat32Ati;
	static const All Alpha32fArb;
	static const All AlphaFloat32Apple;
	static const All AlphaFloat32Ati;
	static const All Intensity32fArb;
	static const All IntensityFloat32Apple;
	static const All IntensityFloat32Ati;
	static const All Luminance32fArb;
	static const All LuminanceFloat32Apple;
	static const All LuminanceFloat32Ati;
	static const All LuminanceAlpha32fArb;
	static const All LuminanceAlphaFloat32Apple;
	static const All LuminanceAlphaFloat32Ati;
	static const All Rgba16f;
	static const All Rgba16fArb;
	static const All RgbaFloat16Apple;
	static const All RgbaFloat16Ati;
	static const All Rgb16f;
	static const All Rgb16fArb;
	static const All RgbFloat16Apple;
	static const All RgbFloat16Ati;
	static const All Alpha16fArb;
	static const All AlphaFloat16Apple;
	static const All AlphaFloat16Ati;
	static const All Intensity16fArb;
	static const All IntensityFloat16Apple;
	static const All IntensityFloat16Ati;
	static const All Luminance16fArb;
	static const All LuminanceFloat16Apple;
	static const All LuminanceFloat16Ati;
	static const All LuminanceAlpha16fArb;
	static const All LuminanceAlphaFloat16Apple;
	static const All LuminanceAlphaFloat16Ati;
	static const All RgbaFloatMode;
	static const All RgbaFloatModeArb;
	static const All RgbaFloatModeAti;
	static const All MaxDrawBuffers;
	static const All MaxDrawBuffersArb;
	static const All MaxDrawBuffersAti;
	static const All DrawBuffer0;
	static const All DrawBuffer0Arb;
	static const All DrawBuffer0Ati;
	static const All DrawBuffer1;
	static const All DrawBuffer1Arb;
	static const All DrawBuffer1Ati;
	static const All DrawBuffer2;
	static const All DrawBuffer2Arb;
	static const All DrawBuffer2Ati;
	static const All DrawBuffer3;
	static const All DrawBuffer3Arb;
	static const All DrawBuffer3Ati;
	static const All DrawBuffer4;
	static const All DrawBuffer4Arb;
	static const All DrawBuffer4Ati;
	static const All DrawBuffer5;
	static const All DrawBuffer5Arb;
	static const All DrawBuffer5Ati;
	static const All DrawBuffer6;
	static const All DrawBuffer6Arb;
	static const All DrawBuffer6Ati;
	static const All DrawBuffer7;
	static const All DrawBuffer7Arb;
	static const All DrawBuffer7Ati;
	static const All DrawBuffer8;
	static const All DrawBuffer8Arb;
	static const All DrawBuffer8Ati;
	static const All DrawBuffer9;
	static const All DrawBuffer9Arb;
	static const All DrawBuffer9Ati;
	static const All DrawBuffer10;
	static const All DrawBuffer10Arb;
	static const All DrawBuffer10Ati;
	static const All DrawBuffer11;
	static const All DrawBuffer11Arb;
	static const All DrawBuffer11Ati;
	static const All DrawBuffer12;
	static const All DrawBuffer12Arb;
	static const All DrawBuffer12Ati;
	static const All DrawBuffer13;
	static const All DrawBuffer13Arb;
	static const All DrawBuffer13Ati;
	static const All DrawBuffer14;
	static const All DrawBuffer14Arb;
	static const All DrawBuffer14Ati;
	static const All DrawBuffer15;
	static const All DrawBuffer15Arb;
	static const All DrawBuffer15Ati;
	static const All ColorClearUnclampedValueAti;
	static const All BlendEquationAlpha;
	static const All BlendEquationAlphaExt;
	static const All SubsampleDistanceAmd;
	static const All MatrixPaletteArb;
	static const All MaxMatrixPaletteStackDepthArb;
	static const All MaxPaletteMatricesArb;
	static const All CurrentPaletteMatrixArb;
	static const All MatrixIndexArrayArb;
	static const All CurrentMatrixIndexArb;
	static const All MatrixIndexArraySizeArb;
	static const All MatrixIndexArrayTypeArb;
	static const All MatrixIndexArrayStrideArb;
	static const All MatrixIndexArrayPointerArb;
	static const All TextureDepthSize;
	static const All TextureDepthSizeArb;
	static const All DepthTextureMode;
	static const All DepthTextureModeArb;
	static const All TextureCompareMode;
	static const All TextureCompareModeArb;
	static const All TextureCompareFunc;
	static const All TextureCompareFuncArb;
	static const All CompareRefDepthToTextureExt;
	static const All CompareRefToTexture;
	static const All CompareRToTexture;
	static const All CompareRToTextureArb;
	static const All TextureCubeMapSeamless;
	static const All OffsetProjectiveTexture2DNv;
	static const All OffsetProjectiveTexture2DScaleNv;
	static const All OffsetProjectiveTextureRectangleNv;
	static const All OffsetProjectiveTextureRectangleScaleNv;
	static const All OffsetHiloTexture2DNv;
	static const All OffsetHiloTextureRectangleNv;
	static const All OffsetHiloProjectiveTexture2DNv;
	static const All OffsetHiloProjectiveTextureRectangleNv;
	static const All DependentHiloTexture2DNv;
	static const All DependentRgbTexture3DNv;
	static const All DependentRgbTextureCubeMapNv;
	static const All DotProductPassThroughNv;
	static const All DotProductTexture1DNv;
	static const All DotProductAffineDepthReplaceNv;
	static const All Hilo8Nv;
	static const All SignedHilo8Nv;
	static const All ForceBlueToOneNv;
	static const All PointSprite;
	static const All PointSpriteArb;
	static const All PointSpriteNv;
	static const All CoordReplace;
	static const All CoordReplaceArb;
	static const All CoordReplaceNv;
	static const All PointSpriteRModeNv;
	static const All PixelCounterBitsNv;
	static const All QueryCounterBits;
	static const All QueryCounterBitsArb;
	static const All CurrentOcclusionQueryIdNv;
	static const All CurrentQuery;
	static const All CurrentQueryArb;
	static const All PixelCountNv;
	static const All QueryResult;
	static const All QueryResultArb;
	static const All PixelCountAvailableNv;
	static const All QueryResultAvailable;
	static const All QueryResultAvailableArb;
	static const All MaxFragmentProgramLocalParametersNv;
	static const All MaxVertexAttribs;
	static const All MaxVertexAttribsArb;
	static const All ArrayNormalized;
	static const All VertexAttribArrayNormalized;
	static const All VertexAttribArrayNormalizedArb;
	static const All MaxTessControlInputComponents;
	static const All MaxTessEvaluationInputComponents;
	static const All DepthStencilToRgbaNv;
	static const All DepthStencilToBgraNv;
	static const All FragmentProgramNv;
	static const All MaxTextureCoords;
	static const All MaxTextureCoordsArb;
	static const All MaxTextureCoordsNv;
	static const All MaxTextureImageUnits;
	static const All MaxTextureImageUnitsArb;
	static const All MaxTextureImageUnitsNv;
	static const All FragmentProgramBindingNv;
	static const All ProgramErrorStringArb;
	static const All ProgramErrorStringNv;
	static const All ProgramFormatAsciiArb;
	static const All ProgramFormat;
	static const All ProgramFormatArb;
	static const All WritePixelDataRangeNv;
	static const All ReadPixelDataRangeNv;
	static const All WritePixelDataRangeLengthNv;
	static const All ReadPixelDataRangeLengthNv;
	static const All WritePixelDataRangePointerNv;
	static const All ReadPixelDataRangePointerNv;
	static const All GeometryShaderInvocations;
	static const All FloatRNv;
	static const All FloatRgNv;
	static const All FloatRgbNv;
	static const All FloatRgbaNv;
	static const All FloatR16Nv;
	static const All FloatR32Nv;
	static const All FloatRg16Nv;
	static const All FloatRg32Nv;
	static const All FloatRgb16Nv;
	static const All FloatRgb32Nv;
	static const All FloatRgba16Nv;
	static const All FloatRgba32Nv;
	static const All TextureFloatComponentsNv;
	static const All FloatClearColorValueNv;
	static const All FloatRgbaModeNv;
	static const All TextureUnsignedRemapModeNv;
	static const All DepthBoundsTestExt;
	static const All DepthBoundsExt;
	static const All ArrayBuffer;
	static const All ArrayBufferArb;
	static const All ElementArrayBuffer;
	static const All ElementArrayBufferArb;
	static const All ArrayBufferBinding;
	static const All ArrayBufferBindingArb;
	static const All ElementArrayBufferBinding;
	static const All ElementArrayBufferBindingArb;
	static const All VertexArrayBufferBinding;
	static const All VertexArrayBufferBindingArb;
	static const All NormalArrayBufferBinding;
	static const All NormalArrayBufferBindingArb;
	static const All ColorArrayBufferBinding;
	static const All ColorArrayBufferBindingArb;
	static const All IndexArrayBufferBinding;
	static const All IndexArrayBufferBindingArb;
	static const All TextureCoordArrayBufferBinding;
	static const All TextureCoordArrayBufferBindingArb;
	static const All EdgeFlagArrayBufferBinding;
	static const All EdgeFlagArrayBufferBindingArb;
	static const All SecondaryColorArrayBufferBinding;
	static const All SecondaryColorArrayBufferBindingArb;
	static const All FogCoordArrayBufferBinding;
	static const All FogCoordinateArrayBufferBinding;
	static const All FogCoordinateArrayBufferBindingArb;
	static const All WeightArrayBufferBinding;
	static const All WeightArrayBufferBindingArb;
	static const All VertexAttribArrayBufferBinding;
	static const All VertexAttribArrayBufferBindingArb;
	static const All ProgramInstruction;
	static const All ProgramInstructionsArb;
	static const All MaxProgramInstructions;
	static const All MaxProgramInstructionsArb;
	static const All ProgramNativeInstructions;
	static const All ProgramNativeInstructionsArb;
	static const All MaxProgramNativeInstructions;
	static const All MaxProgramNativeInstructionsArb;
	static const All ProgramTemporaries;
	static const All ProgramTemporariesArb;
	static const All MaxProgramTemporaries;
	static const All MaxProgramTemporariesArb;
	static const All ProgramNativeTemporaries;
	static const All ProgramNativeTemporariesArb;
	static const All MaxProgramNativeTemporaries;
	static const All MaxProgramNativeTemporariesArb;
	static const All ProgramParameters;
	static const All ProgramParametersArb;
	static const All MaxProgramParameters;
	static const All MaxProgramParametersArb;
	static const All ProgramNativeParameters;
	static const All ProgramNativeParametersArb;
	static const All MaxProgramNativeParameters;
	static const All MaxProgramNativeParametersArb;
	static const All ProgramAttribs;
	static const All ProgramAttribsArb;
	static const All MaxProgramAttribs;
	static const All MaxProgramAttribsArb;
	static const All ProgramNativeAttribs;
	static const All ProgramNativeAttribsArb;
	static const All MaxProgramNativeAttribs;
	static const All MaxProgramNativeAttribsArb;
	static const All ProgramAddressRegisters;
	static const All ProgramAddressRegistersArb;
	static const All MaxProgramAddressRegisters;
	static const All MaxProgramAddressRegistersArb;
	static const All ProgramNativeAddressRegisters;
	static const All ProgramNativeAddressRegistersArb;
	static const All MaxProgramNativeAddressRegisters;
	static const All MaxProgramNativeAddressRegistersArb;
	static const All MaxProgramLocalParameters;
	static const All MaxProgramLocalParametersArb;
	static const All MaxProgramEnvParameters;
	static const All MaxProgramEnvParametersArb;
	static const All ProgramUnderNativeLimits;
	static const All ProgramUnderNativeLimitsArb;
	static const All TransposeCurrentMatrixArb;
	static const All ReadOnly;
	static const All ReadOnlyArb;
	static const All WriteOnly;
	static const All WriteOnlyArb;
	static const All ReadWrite;
	static const All ReadWriteArb;
	static const All BufferAccess;
	static const All BufferAccessArb;
	static const All BufferMapped;
	static const All BufferMappedArb;
	static const All BufferMapPointer;
	static const All BufferMapPointerArb;
	static const All WriteDiscardNv;
	static const All TimeElapsed;
	static const All TimeElapsedExt;
	static const All Matrix0;
	static const All Matrix0Arb;
	static const All Matrix1;
	static const All Matrix1Arb;
	static const All Matrix2;
	static const All Matrix2Arb;
	static const All Matrix3;
	static const All Matrix3Arb;
	static const All Matrix4;
	static const All Matrix4Arb;
	static const All Matrix5;
	static const All Matrix5Arb;
	static const All Matrix6;
	static const All Matrix6Arb;
	static const All Matrix7;
	static const All Matrix7Arb;
	static const All Matrix8;
	static const All Matrix8Arb;
	static const All Matrix9;
	static const All Matrix9Arb;
	static const All Matrix10;
	static const All Matrix10Arb;
	static const All Matrix11;
	static const All Matrix11Arb;
	static const All Matrix12;
	static const All Matrix12Arb;
	static const All Matrix13;
	static const All Matrix13Arb;
	static const All Matrix14;
	static const All Matrix14Arb;
	static const All Matrix15;
	static const All Matrix15Arb;
	static const All Matrix16;
	static const All Matrix16Arb;
	static const All Matrix17;
	static const All Matrix17Arb;
	static const All Matrix18;
	static const All Matrix18Arb;
	static const All Matrix19;
	static const All Matrix19Arb;
	static const All Matrix20;
	static const All Matrix20Arb;
	static const All Matrix21;
	static const All Matrix21Arb;
	static const All Matrix22;
	static const All Matrix22Arb;
	static const All Matrix23;
	static const All Matrix23Arb;
	static const All Matrix24;
	static const All Matrix24Arb;
	static const All Matrix25;
	static const All Matrix25Arb;
	static const All Matrix26;
	static const All Matrix26Arb;
	static const All Matrix27;
	static const All Matrix27Arb;
	static const All Matrix28;
	static const All Matrix28Arb;
	static const All Matrix29;
	static const All Matrix29Arb;
	static const All Matrix30;
	static const All Matrix30Arb;
	static const All Matrix31;
	static const All Matrix31Arb;
	static const All StreamDraw;
	static const All StreamDrawArb;
	static const All StreamRead;
	static const All StreamReadArb;
	static const All StreamCopy;
	static const All StreamCopyArb;
	static const All StaticDraw;
	static const All StaticDrawArb;
	static const All StaticRead;
	static const All StaticReadArb;
	static const All StaticCopy;
	static const All StaticCopyArb;
	static const All DynamicDraw;
	static const All DynamicDrawArb;
	static const All DynamicRead;
	static const All DynamicReadArb;
	static const All DynamicCopy;
	static const All DynamicCopyArb;
	static const All PixelPackBuffer;
	static const All PixelPackBufferArb;
	static const All PixelPackBufferExt;
	static const All PixelUnpackBuffer;
	static const All PixelUnpackBufferArb;
	static const All PixelUnpackBufferExt;
	static const All PixelPackBufferBinding;
	static const All PixelPackBufferBindingArb;
	static const All PixelPackBufferBindingExt;
	static const All PixelUnpackBufferBinding;
	static const All PixelUnpackBufferBindingArb;
	static const All PixelUnpackBufferBindingExt;
	static const All Depth24Stencil8;
	static const All Depth24Stencil8Ext;
	static const All TextureStencilSize;
	static const All TextureStencilSizeExt;
	static const All StencilTagBitsExt;
	static const All StencilClearTagValueExt;
	static const All MaxProgramExecInstructionsNv;
	static const All MaxProgramCallDepthNv;
	static const All MaxProgramIfDepthNv;
	static const All MaxProgramLoopDepthNv;
	static const All MaxProgramLoopCountNv;
	static const All Src1Color;
	static const All OneMinusSrc1Color;
	static const All OneMinusSrc1Alpha;
	static const All MaxDualSourceDrawBuffers;
	static const All VertexAttribArrayInteger;
	static const All VertexAttribArrayIntegerExt;
	static const All VertexAttribArrayIntegerNv;
	static const All ArrayDivisor;
	static const All VertexAttribArrayDivisor;
	static const All VertexAttribArrayDivisorArb;
	static const All MaxArrayTextureLayers;
	static const All MaxArrayTextureLayersExt;
	static const All MinProgramTexelOffset;
	static const All MinProgramTexelOffsetExt;
	static const All MinProgramTexelOffsetNv;
	static const All MaxProgramTexelOffset;
	static const All MaxProgramTexelOffsetExt;
	static const All MaxProgramTexelOffsetNv;
	static const All ProgramAttribComponentsNv;
	static const All ProgramResultComponentsNv;
	static const All MaxProgramAttribComponentsNv;
	static const All MaxProgramResultComponentsNv;
	static const All StencilTestTwoSideExt;
	static const All ActiveStencilFaceExt;
	static const All MirrorClampToBorderExt;
	static const All SamplesPassed;
	static const All SamplesPassedArb;
	static const All GeometryVerticesOut;
	static const All GeometryInputType;
	static const All GeometryOutputType;
	static const All SamplerBinding;
	static const All ClampVertexColor;
	static const All ClampVertexColorArb;
	static const All ClampFragmentColor;
	static const All ClampFragmentColorArb;
	static const All ClampReadColor;
	static const All ClampReadColorArb;
	static const All FixedOnly;
	static const All FixedOnlyArb;
	static const All TessControlProgramNv;
	static const All TessEvaluationProgramNv;
	static const All FragmentShaderAti;
	static const All Reg0Ati;
	static const All Reg1Ati;
	static const All Reg2Ati;
	static const All Reg3Ati;
	static const All Reg4Ati;
	static const All Reg5Ati;
	static const All Reg6Ati;
	static const All Reg7Ati;
	static const All Reg8Ati;
	static const All Reg9Ati;
	static const All Reg10Ati;
	static const All Reg11Ati;
	static const All Reg12Ati;
	static const All Reg13Ati;
	static const All Reg14Ati;
	static const All Reg15Ati;
	static const All Reg16Ati;
	static const All Reg17Ati;
	static const All Reg18Ati;
	static const All Reg19Ati;
	static const All Reg20Ati;
	static const All Reg21Ati;
	static const All Reg22Ati;
	static const All Reg23Ati;
	static const All Reg24Ati;
	static const All Reg25Ati;
	static const All Reg26Ati;
	static const All Reg27Ati;
	static const All Reg28Ati;
	static const All Reg29Ati;
	static const All Reg30Ati;
	static const All Reg31Ati;
	static const All Con0Ati;
	static const All Con1Ati;
	static const All Con2Ati;
	static const All Con3Ati;
	static const All Con4Ati;
	static const All Con5Ati;
	static const All Con6Ati;
	static const All Con7Ati;
	static const All Con8Ati;
	static const All Con9Ati;
	static const All Con10Ati;
	static const All Con11Ati;
	static const All Con12Ati;
	static const All Con13Ati;
	static const All Con14Ati;
	static const All Con15Ati;
	static const All Con16Ati;
	static const All Con17Ati;
	static const All Con18Ati;
	static const All Con19Ati;
	static const All Con20Ati;
	static const All Con21Ati;
	static const All Con22Ati;
	static const All Con23Ati;
	static const All Con24Ati;
	static const All Con25Ati;
	static const All Con26Ati;
	static const All Con27Ati;
	static const All Con28Ati;
	static const All Con29Ati;
	static const All Con30Ati;
	static const All Con31Ati;
	static const All MovAti;
	static const All AddAti;
	static const All MulAti;
	static const All SubAti;
	static const All Dot3Ati;
	static const All Dot4Ati;
	static const All MadAti;
	static const All LerpAti;
	static const All CndAti;
	static const All Cnd0Ati;
	static const All Dot2AddAti;
	static const All SecondaryInterpolatorAti;
	static const All NumFragmentRegistersAti;
	static const All NumFragmentConstantsAti;
	static const All NumPassesAti;
	static const All NumInstructionsPerPassAti;
	static const All NumInstructionsTotalAti;
	static const All NumInputInterpolatorComponentsAti;
	static const All NumLoopbackComponentsAti;
	static const All ColorAlphaPairingAti;
	static const All SwizzleStrAti;
	static const All SwizzleStqAti;
	static const All SwizzleStrDrAti;
	static const All SwizzleStqDqAti;
	static const All SwizzleStrqAti;
	static const All SwizzleStrqDqAti;
	static const All InterlaceOml;
	static const All InterlaceReadOml;
	static const All FormatSubsample2424Oml;
	static const All FormatSubsample244244Oml;
	static const All PackResampleOml;
	static const All UnpackResampleOml;
	static const All ResampleReplicateOml;
	static const All ResampleZeroFillOml;
	static const All ResampleAverageOml;
	static const All ResampleDecimateOml;
	static const All VertexAttribMap1Apple;
	static const All VertexAttribMap2Apple;
	static const All VertexAttribMap1SizeApple;
	static const All VertexAttribMap1CoeffApple;
	static const All VertexAttribMap1OrderApple;
	static const All VertexAttribMap1DomainApple;
	static const All VertexAttribMap2SizeApple;
	static const All VertexAttribMap2CoeffApple;
	static const All VertexAttribMap2OrderApple;
	static const All VertexAttribMap2DomainApple;
	static const All DrawPixelsApple;
	static const All FenceApple;
	static const All ElementArrayApple;
	static const All ElementArrayTypeApple;
	static const All ElementArrayPointerApple;
	static const All ColorFloatApple;
	static const All UniformBuffer;
	static const All BufferSerializedModifyApple;
	static const All BufferFlushingUnmapApple;
	static const All AuxDepthStencilApple;
	static const All PackRowBytesApple;
	static const All UnpackRowBytesApple;
	static const All ReleasedApple;
	static const All VolatileApple;
	static const All RetainedApple;
	static const All UndefinedApple;
	static const All PurgeableApple;
	static const All Rgb422Apple;
	static const All UniformBufferBinding;
	static const All UniformBufferStart;
	static const All UniformBufferSize;
	static const All MaxVertexUniformBlocks;
	static const All MaxGeometryUniformBlocks;
	static const All MaxFragmentUniformBlocks;
	static const All MaxCombinedUniformBlocks;
	static const All MaxUniformBufferBindings;
	static const All MaxUniformBlockSize;
	static const All MaxCombinedVertexUniformComponents;
	static const All MaxCombinedGeometryUniformComponents;
	static const All MaxCombinedFragmentUniformComponents;
	static const All UniformBufferOffsetAlignment;
	static const All ActiveUniformBlockMaxNameLength;
	static const All ActiveUniformBlocks;
	static const All UniformType;
	static const All UniformSize;
	static const All UniformNameLength;
	static const All UniformBlockIndex;
	static const All UniformOffset;
	static const All UniformArrayStride;
	static const All UniformMatrixStride;
	static const All UniformIsRowMajor;
	static const All UniformBlockBinding;
	static const All UniformBlockDataSize;
	static const All UniformBlockNameLength;
	static const All UniformBlockActiveUniforms;
	static const All UniformBlockActiveUniformIndices;
	static const All UniformBlockReferencedByVertexShader;
	static const All UniformBlockReferencedByGeometryShader;
	static const All UniformBlockReferencedByFragmentShader;
	static const All TextureSrgbDecodeExt;
	static const All DecodeExt;
	static const All SkipDecodeExt;
	static const All ProgramPipelineObjectExt;
	static const All RgbRaw422Apple;
	static const All FragmentShader;
	static const All FragmentShaderArb;
	static const All VertexShader;
	static const All VertexShaderArb;
	static const All ProgramObjectArb;
	static const All ProgramObjectExt;
	static const All ShaderObjectArb;
	static const All ShaderObjectExt;
	static const All MaxFragmentUniformComponents;
	static const All MaxFragmentUniformComponentsArb;
	static const All MaxVertexUniformComponents;
	static const All MaxVertexUniformComponentsArb;
	static const All MaxVaryingComponents;
	static const All MaxVaryingComponentsExt;
	static const All MaxVaryingFloats;
	static const All MaxVaryingFloatsArb;
	static const All MaxVertexTextureImageUnits;
	static const All MaxVertexTextureImageUnitsArb;
	static const All MaxCombinedTextureImageUnits;
	static const All MaxCombinedTextureImageUnitsArb;
	static const All ObjectTypeArb;
	static const All ObjectSubtypeArb;
	static const All ShaderType;
	static const All FloatVec2;
	static const All FloatVec2Arb;
	static const All FloatVec3;
	static const All FloatVec3Arb;
	static const All FloatVec4;
	static const All FloatVec4Arb;
	static const All IntVec2;
	static const All IntVec2Arb;
	static const All IntVec3;
	static const All IntVec3Arb;
	static const All IntVec4;
	static const All IntVec4Arb;
	static const All Bool;
	static const All BoolArb;
	static const All BoolVec2;
	static const All BoolVec2Arb;
	static const All BoolVec3;
	static const All BoolVec3Arb;
	static const All BoolVec4;
	static const All BoolVec4Arb;
	static const All FloatMat2;
	static const All FloatMat2Arb;
	static const All FloatMat3;
	static const All FloatMat3Arb;
	static const All FloatMat4;
	static const All FloatMat4Arb;
	static const All Sampler1D;
	static const All Sampler1DArb;
	static const All Sampler2D;
	static const All Sampler2DArb;
	static const All Sampler3D;
	static const All Sampler3DArb;
	static const All SamplerCube;
	static const All SamplerCubeArb;
	static const All Sampler1DShadow;
	static const All Sampler1DShadowArb;
	static const All Sampler2DShadow;
	static const All Sampler2DShadowArb;
	static const All Sampler2DRect;
	static const All Sampler2DRectArb;
	static const All Sampler2DRectShadow;
	static const All Sampler2DRectShadowArb;
	static const All FloatMat2x3;
	static const All FloatMat2x4;
	static const All FloatMat3x2;
	static const All FloatMat3x4;
	static const All FloatMat4x2;
	static const All FloatMat4x3;
	static const All DeleteStatus;
	static const All ObjectDeleteStatusArb;
	static const All CompileStatus;
	static const All ObjectCompileStatusArb;
	static const All LinkStatus;
	static const All ObjectLinkStatusArb;
	static const All ObjectValidateStatusArb;
	static const All ValidateStatus;
	static const All InfoLogLength;
	static const All ObjectInfoLogLengthArb;
	static const All AttachedShaders;
	static const All ObjectAttachedObjectsArb;
	static const All ActiveUniforms;
	static const All ObjectActiveUniformsArb;
	static const All ActiveUniformMaxLength;
	static const All ObjectActiveUniformMaxLengthArb;
	static const All ObjectShaderSourceLengthArb;
	static const All ShaderSourceLength;
	static const All ActiveAttributes;
	static const All ObjectActiveAttributesArb;
	static const All ActiveAttributeMaxLength;
	static const All ObjectActiveAttributeMaxLengthArb;
	static const All FragmentShaderDerivativeHint;
	static const All FragmentShaderDerivativeHintArb;
	static const All FragmentShaderDerivativeHintOes;
	static const All ShadingLanguageVersion;
	static const All ShadingLanguageVersionArb;
	static const All ActiveProgramExt;
	static const All CurrentProgram;
	static const All Palette4Rgb8Oes;
	static const All Palette4Rgba8Oes;
	static const All Palette4R5G6B5Oes;
	static const All Palette4Rgba4Oes;
	static const All Palette4Rgb5A1Oes;
	static const All Palette8Rgb8Oes;
	static const All Palette8Rgba8Oes;
	static const All Palette8R5G6B5Oes;
	static const All Palette8Rgba4Oes;
	static const All Palette8Rgb5A1Oes;
	static const All ImplementationColorReadType;
	static const All ImplementationColorReadTypeOes;
	static const All ImplementationColorReadFormat;
	static const All ImplementationColorReadFormatOes;
	static const All CounterTypeAmd;
	static const All CounterRangeAmd;
	static const All UnsignedInt64Amd;
	static const All PercentageAmd;
	static const All PerfmonResultAvailableAmd;
	static const All PerfmonResultSizeAmd;
	static const All PerfmonResultAmd;
	static const All TextureRedType;
	static const All TextureRedTypeArb;
	static const All TextureGreenType;
	static const All TextureGreenTypeArb;
	static const All TextureBlueType;
	static const All TextureBlueTypeArb;
	static const All TextureAlphaType;
	static const All TextureAlphaTypeArb;
	static const All TextureLuminanceType;
	static const All TextureLuminanceTypeArb;
	static const All TextureIntensityType;
	static const All TextureIntensityTypeArb;
	static const All TextureDepthType;
	static const All TextureDepthTypeArb;
	static const All UnsignedNormalized;
	static const All UnsignedNormalizedArb;
	static const All Texture1DArray;
	static const All Texture1DArrayExt;
	static const All ProxyTexture1DArray;
	static const All ProxyTexture1DArrayExt;
	static const All Texture2DArray;
	static const All Texture2DArrayExt;
	static const All ProxyTexture2DArray;
	static const All ProxyTexture2DArrayExt;
	static const All TextureBinding1DArray;
	static const All TextureBinding1DArrayExt;
	static const All TextureBinding2DArray;
	static const All TextureBinding2DArrayExt;
	static const All GeometryProgramNv;
	static const All MaxProgramOutputVerticesNv;
	static const All MaxProgramTotalOutputComponentsNv;
	static const All MaxGeometryTextureImageUnits;
	static const All MaxGeometryTextureImageUnitsArb;
	static const All MaxGeometryTextureImageUnitsExt;
	static const All TextureBuffer;
	static const All TextureBufferArb;
	static const All TextureBufferBinding;
	static const All TextureBufferExt;
	static const All MaxTextureBufferSize;
	static const All MaxTextureBufferSizeArb;
	static const All MaxTextureBufferSizeExt;
	static const All TextureBindingBuffer;
	static const All TextureBindingBufferArb;
	static const All TextureBindingBufferExt;
	static const All TextureBufferDataStoreBinding;
	static const All TextureBufferDataStoreBindingArb;
	static const All TextureBufferDataStoreBindingExt;
	static const All TextureBufferFormatArb;
	static const All TextureBufferFormatExt;
	static const All AnySamplesPassed;
	static const All SampleShading;
	static const All SampleShadingArb;
	static const All MinSampleShadingValue;
	static const All MinSampleShadingValueArb;
	static const All R11fG11fB10f;
	static const All R11fG11fB10fExt;
	static const All UnsignedInt10F11F11FRev;
	static const All UnsignedInt10F11F11FRevExt;
	static const All RgbaSignedComponentsExt;
	static const All Rgb9E5;
	static const All Rgb9E5Ext;
	static const All UnsignedInt5999Rev;
	static const All UnsignedInt5999RevExt;
	static const All TextureSharedSize;
	static const All TextureSharedSizeExt;
	static const All Srgb;
	static const All SrgbExt;
	static const All Srgb8;
	static const All Srgb8Ext;
	static const All SrgbAlpha;
	static const All SrgbAlphaExt;
	static const All Srgb8Alpha8;
	static const All Srgb8Alpha8Ext;
	static const All SluminanceAlpha;
	static const All SluminanceAlphaExt;
	static const All Sluminance8Alpha8;
	static const All Sluminance8Alpha8Ext;
	static const All Sluminance;
	static const All SluminanceExt;
	static const All Sluminance8;
	static const All Sluminance8Ext;
	static const All CompressedSrgb;
	static const All CompressedSrgbExt;
	static const All CompressedSrgbAlpha;
	static const All CompressedSrgbAlphaExt;
	static const All CompressedSluminance;
	static const All CompressedSluminanceExt;
	static const All CompressedSluminanceAlpha;
	static const All CompressedSluminanceAlphaExt;
	static const All CompressedSrgbS3tcDxt1Ext;
	static const All CompressedSrgbAlphaS3tcDxt1Ext;
	static const All CompressedSrgbAlphaS3tcDxt3Ext;
	static const All CompressedSrgbAlphaS3tcDxt5Ext;
	static const All CompressedLuminanceLatc1Ext;
	static const All CompressedSignedLuminanceLatc1Ext;
	static const All CompressedLuminanceAlphaLatc2Ext;
	static const All CompressedSignedLuminanceAlphaLatc2Ext;
	static const All TessControlProgramParameterBufferNv;
	static const All TessEvaluationProgramParameterBufferNv;
	static const All TransformFeedbackVaryingMaxLength;
	static const All TransformFeedbackVaryingMaxLengthExt;
	static const All BackPrimaryColorNv;
	static const All BackSecondaryColorNv;
	static const All TextureCoordNv;
	static const All ClipDistanceNv;
	static const All VertexIdNv;
	static const All PrimitiveIdNv;
	static const All GenericAttribNv;
	static const All TransformFeedbackAttribsNv;
	static const All TransformFeedbackBufferMode;
	static const All TransformFeedbackBufferModeExt;
	static const All TransformFeedbackBufferModeNv;
	static const All MaxTransformFeedbackSeparateComponents;
	static const All MaxTransformFeedbackSeparateComponentsExt;
	static const All MaxTransformFeedbackSeparateComponentsNv;
	static const All ActiveVaryingsNv;
	static const All ActiveVaryingMaxLengthNv;
	static const All TransformFeedbackVaryings;
	static const All TransformFeedbackVaryingsExt;
	static const All TransformFeedbackVaryingsNv;
	static const All TransformFeedbackBufferStart;
	static const All TransformFeedbackBufferStartExt;
	static const All TransformFeedbackBufferStartNv;
	static const All TransformFeedbackBufferSize;
	static const All TransformFeedbackBufferSizeExt;
	static const All TransformFeedbackBufferSizeNv;
	static const All TransformFeedbackRecordNv;
	static const All PrimitivesGenerated;
	static const All PrimitivesGeneratedExt;
	static const All PrimitivesGeneratedNv;
	static const All TransformFeedbackPrimitivesWritten;
	static const All TransformFeedbackPrimitivesWrittenExt;
	static const All TransformFeedbackPrimitivesWrittenNv;
	static const All RasterizerDiscard;
	static const All RasterizerDiscardExt;
	static const All RasterizerDiscardNv;
	static const All MaxTransformFeedbackInterleavedComponents;
	static const All MaxTransformFeedbackInterleavedComponentsExt;
	static const All MaxTransformFeedbackInterleavedComponentsNv;
	static const All MaxTransformFeedbackSeparateAttribs;
	static const All MaxTransformFeedbackSeparateAttribsExt;
	static const All MaxTransformFeedbackSeparateAttribsNv;
	static const All InterleavedAttribs;
	static const All InterleavedAttribsExt;
	static const All InterleavedAttribsNv;
	static const All SeparateAttribs;
	static const All SeparateAttribsExt;
	static const All SeparateAttribsNv;
	static const All TransformFeedbackBuffer;
	static const All TransformFeedbackBufferExt;
	static const All TransformFeedbackBufferNv;
	static const All TransformFeedbackBufferBinding;
	static const All TransformFeedbackBufferBindingExt;
	static const All TransformFeedbackBufferBindingNv;
	static const All PointSpriteCoordOrigin;
	static const All LowerLeft;
	static const All UpperLeft;
	static const All StencilBackRef;
	static const All StencilBackValueMask;
	static const All StencilBackWritemask;
	static const All DrawFramebufferBinding;
	static const All DrawFramebufferBindingExt;
	static const All FramebufferBinding;
	static const All FramebufferBindingExt;
	static const All RenderbufferBinding;
	static const All RenderbufferBindingExt;
	static const All ReadFramebuffer;
	static const All ReadFramebufferExt;
	static const All DrawFramebuffer;
	static const All DrawFramebufferExt;
	static const All ReadFramebufferBinding;
	static const All ReadFramebufferBindingExt;
	static const All RenderbufferCoverageSamplesNv;
	static const All RenderbufferSamples;
	static const All RenderbufferSamplesExt;
	static const All DepthComponent32f;
	static const All Depth32fStencil8;
	static const All FramebufferAttachmentObjectType;
	static const All FramebufferAttachmentObjectTypeExt;
	static const All FramebufferAttachmentObjectName;
	static const All FramebufferAttachmentObjectNameExt;
	static const All FramebufferAttachmentTextureLevel;
	static const All FramebufferAttachmentTextureLevelExt;
	static const All FramebufferAttachmentTextureCubeMapFace;
	static const All FramebufferAttachmentTextureCubeMapFaceExt;
	static const All FramebufferAttachmentTexture3DZoffsetExt;
	static const All FramebufferAttachmentTextureLayer;
	static const All FramebufferAttachmentTextureLayerExt;
	static const All FramebufferComplete;
	static const All FramebufferCompleteExt;
	static const All FramebufferIncompleteAttachment;
	static const All FramebufferIncompleteAttachmentExt;
	static const All FramebufferIncompleteMissingAttachment;
	static const All FramebufferIncompleteMissingAttachmentExt;
	static const All FramebufferIncompleteDimensionsExt;
	static const All FramebufferIncompleteFormatsExt;
	static const All FramebufferIncompleteDrawBuffer;
	static const All FramebufferIncompleteDrawBufferExt;
	static const All FramebufferIncompleteReadBuffer;
	static const All FramebufferIncompleteReadBufferExt;
	static const All FramebufferUnsupported;
	static const All FramebufferUnsupportedExt;
	static const All MaxColorAttachments;
	static const All MaxColorAttachmentsExt;
	static const All ColorAttachment0;
	static const All ColorAttachment0Ext;
	static const All ColorAttachment1;
	static const All ColorAttachment1Ext;
	static const All ColorAttachment2;
	static const All ColorAttachment2Ext;
	static const All ColorAttachment3;
	static const All ColorAttachment3Ext;
	static const All ColorAttachment4;
	static const All ColorAttachment4Ext;
	static const All ColorAttachment5;
	static const All ColorAttachment5Ext;
	static const All ColorAttachment6;
	static const All ColorAttachment6Ext;
	static const All ColorAttachment7;
	static const All ColorAttachment7Ext;
	static const All ColorAttachment8;
	static const All ColorAttachment8Ext;
	static const All ColorAttachment9;
	static const All ColorAttachment9Ext;
	static const All ColorAttachment10;
	static const All ColorAttachment10Ext;
	static const All ColorAttachment11;
	static const All ColorAttachment11Ext;
	static const All ColorAttachment12;
	static const All ColorAttachment12Ext;
	static const All ColorAttachment13;
	static const All ColorAttachment13Ext;
	static const All ColorAttachment14;
	static const All ColorAttachment14Ext;
	static const All ColorAttachment15;
	static const All ColorAttachment15Ext;
	static const All DepthAttachment;
	static const All DepthAttachmentExt;
	static const All StencilAttachment;
	static const All StencilAttachmentExt;
	static const All Framebuffer;
	static const All FramebufferExt;
	static const All Renderbuffer;
	static const All RenderbufferExt;
	static const All RenderbufferWidth;
	static const All RenderbufferWidthExt;
	static const All RenderbufferHeight;
	static const All RenderbufferHeightExt;
	static const All RenderbufferInternalFormat;
	static const All RenderbufferInternalFormatExt;
	static const All StencilIndex1;
	static const All StencilIndex1Ext;
	static const All StencilIndex4;
	static const All StencilIndex4Ext;
	static const All StencilIndex8;
	static const All StencilIndex8Ext;
	static const All StencilIndex16;
	static const All StencilIndex16Ext;
	static const All RenderbufferRedSize;
	static const All RenderbufferRedSizeExt;
	static const All RenderbufferGreenSize;
	static const All RenderbufferGreenSizeExt;
	static const All RenderbufferBlueSize;
	static const All RenderbufferBlueSizeExt;
	static const All RenderbufferAlphaSize;
	static const All RenderbufferAlphaSizeExt;
	static const All RenderbufferDepthSize;
	static const All RenderbufferDepthSizeExt;
	static const All RenderbufferStencilSize;
	static const All RenderbufferStencilSizeExt;
	static const All FramebufferIncompleteMultisample;
	static const All FramebufferIncompleteMultisampleExt;
	static const All MaxSamples;
	static const All MaxSamplesExt;
	static const All Rgb565;
	static const All PrimitiveRestartFixedIndex;
	static const All AnySamplesPassedConservative;
	static const All MaxElementIndex;
	static const All Rgba32ui;
	static const All Rgba32uiExt;
	static const All Rgb32ui;
	static const All Rgb32uiExt;
	static const All Alpha32uiExt;
	static const All Intensity32uiExt;
	static const All Luminance32uiExt;
	static const All LuminanceAlpha32uiExt;
	static const All Rgba16ui;
	static const All Rgba16uiExt;
	static const All Rgb16ui;
	static const All Rgb16uiExt;
	static const All Alpha16uiExt;
	static const All Intensity16uiExt;
	static const All Luminance16uiExt;
	static const All LuminanceAlpha16uiExt;
	static const All Rgba8ui;
	static const All Rgba8uiExt;
	static const All Rgb8ui;
	static const All Rgb8uiExt;
	static const All Alpha8uiExt;
	static const All Intensity8uiExt;
	static const All Luminance8uiExt;
	static const All LuminanceAlpha8uiExt;
	static const All Rgba32i;
	static const All Rgba32iExt;
	static const All Rgb32i;
	static const All Rgb32iExt;
	static const All Alpha32iExt;
	static const All Intensity32iExt;
	static const All Luminance32iExt;
	static const All LuminanceAlpha32iExt;
	static const All Rgba16i;
	static const All Rgba16iExt;
	static const All Rgb16i;
	static const All Rgb16iExt;
	static const All Alpha16iExt;
	static const All Intensity16iExt;
	static const All Luminance16iExt;
	static const All LuminanceAlpha16iExt;
	static const All Rgba8i;
	static const All Rgba8iExt;
	static const All Rgb8i;
	static const All Rgb8iExt;
	static const All Alpha8iExt;
	static const All Intensity8iExt;
	static const All Luminance8iExt;
	static const All LuminanceAlpha8iExt;
	static const All RedInteger;
	static const All RedIntegerExt;
	static const All GreenInteger;
	static const All GreenIntegerExt;
	static const All BlueInteger;
	static const All BlueIntegerExt;
	static const All AlphaInteger;
	static const All AlphaIntegerExt;
	static const All RgbInteger;
	static const All RgbIntegerExt;
	static const All RgbaInteger;
	static const All RgbaIntegerExt;
	static const All BgrInteger;
	static const All BgrIntegerExt;
	static const All BgraInteger;
	static const All BgraIntegerExt;
	static const All LuminanceIntegerExt;
	static const All LuminanceAlphaIntegerExt;
	static const All RgbaIntegerModeExt;
	static const All Int2101010Rev;
	static const All MaxProgramParameterBufferBindingsNv;
	static const All MaxProgramParameterBufferSizeNv;
	static const All VertexProgramParameterBufferNv;
	static const All GeometryProgramParameterBufferNv;
	static const All FragmentProgramParameterBufferNv;
	static const All MaxProgramGenericAttribsNv;
	static const All MaxProgramGenericResultsNv;
	static const All FramebufferAttachmentLayered;
	static const All FramebufferAttachmentLayeredArb;
	static const All FramebufferAttachmentLayeredExt;
	static const All FramebufferIncompleteLayerTargets;
	static const All FramebufferIncompleteLayerTargetsArb;
	static const All FramebufferIncompleteLayerTargetsExt;
	static const All FramebufferIncompleteLayerCount;
	static const All FramebufferIncompleteLayerCountArb;
	static const All FramebufferIncompleteLayerCountExt;
	static const All LayerNv;
	static const All DepthComponent32fNv;
	static const All Depth32fStencil8Nv;
	static const All Float32UnsignedInt248Rev;
	static const All Float32UnsignedInt248RevNv;
	static const All ShaderIncludeArb;
	static const All DepthBufferFloatModeNv;
	static const All FramebufferSrgb;
	static const All FramebufferSrgbExt;
	static const All FramebufferSrgbCapableExt;
	static const All CompressedRedRgtc1;
	static const All CompressedRedRgtc1Ext;
	static const All CompressedSignedRedRgtc1;
	static const All CompressedSignedRedRgtc1Ext;
	static const All CompressedRedGreenRgtc2Ext;
	static const All CompressedRgRgtc2;
	static const All CompressedSignedRedGreenRgtc2Ext;
	static const All CompressedSignedRgRgtc2;
	static const All Sampler1DArray;
	static const All Sampler1DArrayExt;
	static const All Sampler2DArray;
	static const All Sampler2DArrayExt;
	static const All SamplerBuffer;
	static const All SamplerBufferExt;
	static const All Sampler1DArrayShadow;
	static const All Sampler1DArrayShadowExt;
	static const All Sampler2DArrayShadow;
	static const All Sampler2DArrayShadowExt;
	static const All SamplerCubeShadow;
	static const All SamplerCubeShadowExt;
	static const All UnsignedIntVec2;
	static const All UnsignedIntVec2Ext;
	static const All UnsignedIntVec3;
	static const All UnsignedIntVec3Ext;
	static const All UnsignedIntVec4;
	static const All UnsignedIntVec4Ext;
	static const All IntSampler1D;
	static const All IntSampler1DExt;
	static const All IntSampler2D;
	static const All IntSampler2DExt;
	static const All IntSampler3D;
	static const All IntSampler3DExt;
	static const All IntSamplerCube;
	static const All IntSamplerCubeExt;
	static const All IntSampler2DRect;
	static const All IntSampler2DRectExt;
	static const All IntSampler1DArray;
	static const All IntSampler1DArrayExt;
	static const All IntSampler2DArray;
	static const All IntSampler2DArrayExt;
	static const All IntSamplerBuffer;
	static const All IntSamplerBufferExt;
	static const All UnsignedIntSampler1D;
	static const All UnsignedIntSampler1DExt;
	static const All UnsignedIntSampler2D;
	static const All UnsignedIntSampler2DExt;
	static const All UnsignedIntSampler3D;
	static const All UnsignedIntSampler3DExt;
	static const All UnsignedIntSamplerCube;
	static const All UnsignedIntSamplerCubeExt;
	static const All UnsignedIntSampler2DRect;
	static const All UnsignedIntSampler2DRectExt;
	static const All UnsignedIntSampler1DArray;
	static const All UnsignedIntSampler1DArrayExt;
	static const All UnsignedIntSampler2DArray;
	static const All UnsignedIntSampler2DArrayExt;
	static const All UnsignedIntSamplerBuffer;
	static const All UnsignedIntSamplerBufferExt;
	static const All GeometryShader;
	static const All GeometryShaderArb;
	static const All GeometryShaderExt;
	static const All GeometryVerticesOutArb;
	static const All GeometryVerticesOutExt;
	static const All GeometryInputTypeArb;
	static const All GeometryInputTypeExt;
	static const All GeometryOutputTypeArb;
	static const All GeometryOutputTypeExt;
	static const All MaxGeometryVaryingComponents;
	static const All MaxGeometryVaryingComponentsArb;
	static const All MaxGeometryVaryingComponentsExt;
	static const All MaxVertexVaryingComponents;
	static const All MaxVertexVaryingComponentsArb;
	static const All MaxVertexVaryingComponentsExt;
	static const All MaxGeometryUniformComponents;
	static const All MaxGeometryUniformComponentsArb;
	static const All MaxGeometryUniformComponentsExt;
	static const All MaxGeometryOutputVertices;
	static const All MaxGeometryOutputVerticesArb;
	static const All MaxGeometryOutputVerticesExt;
	static const All MaxGeometryTotalOutputComponents;
	static const All MaxGeometryTotalOutputComponentsArb;
	static const All MaxGeometryTotalOutputComponentsExt;
	static const All MaxVertexBindableUniformsExt;
	static const All MaxFragmentBindableUniformsExt;
	static const All MaxGeometryBindableUniformsExt;
	static const All ActiveSubroutines;
	static const All ActiveSubroutineUniforms;
	static const All MaxSubroutines;
	static const All MaxSubroutineUniformLocations;
	static const All NamedStringLengthArb;
	static const All NamedStringTypeArb;
	static const All MaxBindableUniformSizeExt;
	static const All UniformBufferExt;
	static const All UniformBufferBindingExt;
	static const All LowFloat;
	static const All MediumFloat;
	static const All HighFloat;
	static const All LowInt;
	static const All MediumInt;
	static const All HighInt;
	static const All ShaderBinaryFormats;
	static const All NumShaderBinaryFormats;
	static const All ShaderCompiler;
	static const All MaxVertexUniformVectors;
	static const All MaxVaryingVectors;
	static const All MaxFragmentUniformVectors;
	static const All RenderbufferColorSamplesNv;
	static const All MaxMultisampleCoverageModesNv;
	static const All MultisampleCoverageModesNv;
	static const All QueryWait;
	static const All QueryWaitNv;
	static const All QueryNoWait;
	static const All QueryNoWaitNv;
	static const All QueryByRegionWait;
	static const All QueryByRegionWaitNv;
	static const All QueryByRegionNoWait;
	static const All QueryByRegionNoWaitNv;
	static const All QueryWaitInverted;
	static const All QueryNoWaitInverted;
	static const All QueryByRegionWaitInverted;
	static const All QueryByRegionNoWaitInverted;
	static const All MaxCombinedTessControlUniformComponents;
	static const All MaxCombinedTessEvaluationUniformComponents;
	static const All ColorSamplesNv;
	static const All TransformFeedback;
	static const All TransformFeedbackNv;
	static const All TransformFeedbackBufferPaused;
	static const All TransformFeedbackBufferPausedNv;
	static const All TransformFeedbackPaused;
	static const All TransformFeedbackActive;
	static const All TransformFeedbackBufferActive;
	static const All TransformFeedbackBufferActiveNv;
	static const All TransformFeedbackBinding;
	static const All TransformFeedbackBindingNv;
	static const All FrameNv;
	static const All FieldsNv;
	static const All CurrentTimeNv;
	static const All Timestamp;
	static const All NumFillStreamsNv;
	static const All PresentTimeNv;
	static const All PresentDurationNv;
	static const All ProgramMatrixExt;
	static const All TransposeProgramMatrixExt;
	static const All ProgramMatrixStackDepthExt;
	static const All TextureSwizzleR;
	static const All TextureSwizzleRExt;
	static const All TextureSwizzleG;
	static const All TextureSwizzleGExt;
	static const All TextureSwizzleB;
	static const All TextureSwizzleBExt;
	static const All TextureSwizzleA;
	static const All TextureSwizzleAExt;
	static const All TextureSwizzleRgba;
	static const All TextureSwizzleRgbaExt;
	static const All ActiveSubroutineUniformLocations;
	static const All ActiveSubroutineMaxLength;
	static const All ActiveSubroutineUniformMaxLength;
	static const All NumCompatibleSubroutines;
	static const All CompatibleSubroutines;
	static const All QuadsFollowProvokingVertexConvention;
	static const All QuadsFollowProvokingVertexConventionExt;
	static const All FirstVertexConvention;
	static const All FirstVertexConventionExt;
	static const All LastVertexConvention;
	static const All LastVertexConventionExt;
	static const All ProvokingVertex;
	static const All ProvokingVertexExt;
	static const All SamplePosition;
	static const All SamplePositionNv;
	static const All SampleMask;
	static const All SampleMaskNv;
	static const All SampleMaskValue;
	static const All SampleMaskValueNv;
	static const All TextureBindingRenderbufferNv;
	static const All TextureRenderbufferDataStoreBindingNv;
	static const All TextureRenderbufferNv;
	static const All SamplerRenderbufferNv;
	static const All IntSamplerRenderbufferNv;
	static const All UnsignedIntSamplerRenderbufferNv;
	static const All MaxSampleMaskWords;
	static const All MaxSampleMaskWordsNv;
	static const All MaxGeometryProgramInvocationsNv;
	static const All MaxGeometryShaderInvocations;
	static const All MinFragmentInterpolationOffset;
	static const All MinFragmentInterpolationOffsetNv;
	static const All MaxFragmentInterpolationOffset;
	static const All MaxFragmentInterpolationOffsetNv;
	static const All FragmentInterpolationOffsetBits;
	static const All FragmentProgramInterpolationOffsetBitsNv;
	static const All MinProgramTextureGatherOffset;
	static const All MinProgramTextureGatherOffsetArb;
	static const All MinProgramTextureGatherOffsetNv;
	static const All MaxProgramTextureGatherOffset;
	static const All MaxProgramTextureGatherOffsetArb;
	static const All MaxProgramTextureGatherOffsetNv;
	static const All MaxTransformFeedbackBuffers;
	static const All MaxVertexStreams;
	static const All PatchVertices;
	static const All PatchDefaultInnerLevel;
	static const All PatchDefaultOuterLevel;
	static const All TessControlOutputVertices;
	static const All TessGenMode;
	static const All TessGenSpacing;
	static const All TessGenVertexOrder;
	static const All TessGenPointMode;
	static const All Isolines;
	static const All FractionalOdd;
	static const All FractionalEven;
	static const All MaxPatchVertices;
	static const All MaxTessGenLevel;
	static const All MaxTessControlUniformComponents;
	static const All MaxTessEvaluationUniformComponents;
	static const All MaxTessControlTextureImageUnits;
	static const All MaxTessEvaluationTextureImageUnits;
	static const All MaxTessControlOutputComponents;
	static const All MaxTessPatchComponents;
	static const All MaxTessControlTotalOutputComponents;
	static const All MaxTessEvaluationOutputComponents;
	static const All TessEvaluationShader;
	static const All TessControlShader;
	static const All MaxTessControlUniformBlocks;
	static const All MaxTessEvaluationUniformBlocks;
	static const All CompressedRgbaBptcUnorm;
	static const All CompressedRgbaBptcUnormArb;
	static const All CompressedSrgbAlphaBptcUnorm;
	static const All CompressedSrgbAlphaBptcUnormArb;
	static const All CompressedRgbBptcSignedFloat;
	static const All CompressedRgbBptcSignedFloatArb;
	static const All CompressedRgbBptcUnsignedFloat;
	static const All CompressedRgbBptcUnsignedFloatArb;
	static const All BufferGpuAddressNv;
	static const All VertexAttribArrayUnifiedNv;
	static const All ElementArrayUnifiedNv;
	static const All VertexAttribArrayAddressNv;
	static const All VertexArrayAddressNv;
	static const All NormalArrayAddressNv;
	static const All ColorArrayAddressNv;
	static const All IndexArrayAddressNv;
	static const All TextureCoordArrayAddressNv;
	static const All EdgeFlagArrayAddressNv;
	static const All SecondaryColorArrayAddressNv;
	static const All FogCoordArrayAddressNv;
	static const All ElementArrayAddressNv;
	static const All VertexAttribArrayLengthNv;
	static const All VertexArrayLengthNv;
	static const All NormalArrayLengthNv;
	static const All ColorArrayLengthNv;
	static const All IndexArrayLengthNv;
	static const All TextureCoordArrayLengthNv;
	static const All EdgeFlagArrayLengthNv;
	static const All SecondaryColorArrayLengthNv;
	static const All FogCoordArrayLengthNv;
	static const All ElementArrayLengthNv;
	static const All GpuAddressNv;
	static const All MaxShaderBufferAddressNv;
	static const All CopyReadBuffer;
	static const All CopyReadBufferBinding;
	static const All CopyWriteBuffer;
	static const All CopyWriteBufferBinding;
	static const All MaxImageUnits;
	static const All MaxImageUnitsExt;
	static const All MaxCombinedImageUnitsAndFragmentOutputs;
	static const All MaxCombinedImageUnitsAndFragmentOutputsExt;
	static const All MaxCombinedShaderOutputResources;
	static const All ImageBindingName;
	static const All ImageBindingNameExt;
	static const All ImageBindingLevel;
	static const All ImageBindingLevelExt;
	static const All ImageBindingLayered;
	static const All ImageBindingLayeredExt;
	static const All ImageBindingLayer;
	static const All ImageBindingLayerExt;
	static const All ImageBindingAccess;
	static const All ImageBindingAccessExt;
	static const All DrawIndirectBuffer;
	static const All DrawIndirectUnifiedNv;
	static const All DrawIndirectAddressNv;
	static const All DrawIndirectLengthNv;
	static const All DrawIndirectBufferBinding;
	static const All MaxProgramSubroutineParametersNv;
	static const All MaxProgramSubroutineNumNv;
	static const All DoubleMat2;
	static const All DoubleMat2Ext;
	static const All DoubleMat3;
	static const All DoubleMat3Ext;
	static const All DoubleMat4;
	static const All DoubleMat4Ext;
	static const All DoubleMat2x3;
	static const All DoubleMat2x3Ext;
	static const All DoubleMat2x4;
	static const All DoubleMat2x4Ext;
	static const All DoubleMat3x2;
	static const All DoubleMat3x2Ext;
	static const All DoubleMat3x4;
	static const All DoubleMat3x4Ext;
	static const All DoubleMat4x2;
	static const All DoubleMat4x2Ext;
	static const All DoubleMat4x3;
	static const All DoubleMat4x3Ext;
	static const All VertexBindingBuffer;
	static const All RedSnorm;
	static const All RgSnorm;
	static const All RgbSnorm;
	static const All RgbaSnorm;
	static const All R8Snorm;
	static const All Rg8Snorm;
	static const All Rgb8Snorm;
	static const All Rgba8Snorm;
	static const All R16Snorm;
	static const All Rg16Snorm;
	static const All Rgb16Snorm;
	static const All Rgba16Snorm;
	static const All SignedNormalized;
	static const All PrimitiveRestart;
	static const All PrimitiveRestartIndex;
	static const All MaxProgramTextureGatherComponentsArb;
	static const All BinningControlHintQcom;
	static const All Int8Nv;
	static const All Int8Vec2Nv;
	static const All Int8Vec3Nv;
	static const All Int8Vec4Nv;
	static const All Int16Nv;
	static const All Int16Vec2Nv;
	static const All Int16Vec3Nv;
	static const All Int16Vec4Nv;
	static const All Int64Vec2Nv;
	static const All Int64Vec3Nv;
	static const All Int64Vec4Nv;
	static const All UnsignedInt8Nv;
	static const All UnsignedInt8Vec2Nv;
	static const All UnsignedInt8Vec3Nv;
	static const All UnsignedInt8Vec4Nv;
	static const All UnsignedInt16Nv;
	static const All UnsignedInt16Vec2Nv;
	static const All UnsignedInt16Vec3Nv;
	static const All UnsignedInt16Vec4Nv;
	static const All UnsignedInt64Vec2Nv;
	static const All UnsignedInt64Vec3Nv;
	static const All UnsignedInt64Vec4Nv;
	static const All Float16Nv;
	static const All Float16Vec2Nv;
	static const All Float16Vec3Nv;
	static const All Float16Vec4Nv;
	static const All DoubleVec2;
	static const All DoubleVec2Ext;
	static const All DoubleVec3;
	static const All DoubleVec3Ext;
	static const All DoubleVec4;
	static const All DoubleVec4Ext;
	static const All SamplerBufferAmd;
	static const All IntSamplerBufferAmd;
	static const All UnsignedIntSamplerBufferAmd;
	static const All TessellationModeAmd;
	static const All TessellationFactorAmd;
	static const All DiscreteAmd;
	static const All ContinuousAmd;
	static const All TextureCubeMapArray;
	static const All TextureCubeMapArrayArb;
	static const All TextureBindingCubeMapArray;
	static const All TextureBindingCubeMapArrayArb;
	static const All ProxyTextureCubeMapArray;
	static const All ProxyTextureCubeMapArrayArb;
	static const All SamplerCubeMapArray;
	static const All SamplerCubeMapArrayArb;
	static const All SamplerCubeMapArrayShadow;
	static const All SamplerCubeMapArrayShadowArb;
	static const All IntSamplerCubeMapArray;
	static const All IntSamplerCubeMapArrayArb;
	static const All UnsignedIntSamplerCubeMapArray;
	static const All UnsignedIntSamplerCubeMapArrayArb;
	static const All AlphaSnorm;
	static const All LuminanceSnorm;
	static const All LuminanceAlphaSnorm;
	static const All IntensitySnorm;
	static const All Alpha8Snorm;
	static const All Luminance8Snorm;
	static const All Luminance8Alpha8Snorm;
	static const All Intensity8Snorm;
	static const All Alpha16Snorm;
	static const All Luminance16Snorm;
	static const All Luminance16Alpha16Snorm;
	static const All Intensity16Snorm;
	static const All FactorMinAmd;
	static const All FactorMaxAmd;
	static const All DepthClampNearAmd;
	static const All DepthClampFarAmd;
	static const All VideoBufferNv;
	static const All VideoBufferBindingNv;
	static const All FieldUpperNv;
	static const All FieldLowerNv;
	static const All NumVideoCaptureStreamsNv;
	static const All NextVideoCaptureBufferStatusNv;
	static const All VideoCaptureTo422SupportedNv;
	static const All LastVideoCaptureStatusNv;
	static const All VideoBufferPitchNv;
	static const All VideoColorConversionMatrixNv;
	static const All VideoColorConversionMaxNv;
	static const All VideoColorConversionMinNv;
	static const All VideoColorConversionOffsetNv;
	static const All VideoBufferInternalFormatNv;
	static const All PartialSuccessNv;
	static const All SuccessNv;
	static const All FailureNv;
	static const All Ycbycr8422Nv;
	static const All Ycbaycr8A4224Nv;
	static const All Z6y10z6cb10z6y10z6cr10422Nv;
	static const All Z6y10z6cb10z6A10z6y10z6cr10z6A104224Nv;
	static const All Z4y12z4cb12z4y12z4cr12422Nv;
	static const All Z4y12z4cb12z4A12z4y12z4cr12z4A124224Nv;
	static const All Z4y12z4cb12z4cr12444Nv;
	static const All VideoCaptureFrameWidthNv;
	static const All VideoCaptureFrameHeightNv;
	static const All VideoCaptureFieldUpperHeightNv;
	static const All VideoCaptureFieldLowerHeightNv;
	static const All VideoCaptureSurfaceOriginNv;
	static const All TextureCoverageSamplesNv;
	static const All TextureColorSamplesNv;
	static const All GpuMemoryInfoDedicatedVidmemNvx;
	static const All GpuMemoryInfoTotalAvailableMemoryNvx;
	static const All GpuMemoryInfoCurrentAvailableVidmemNvx;
	static const All GpuMemoryInfoEvictionCountNvx;
	static const All GpuMemoryInfoEvictedMemoryNvx;
	static const All Image1D;
	static const All Image1DExt;
	static const All Image2D;
	static const All Image2DExt;
	static const All Image3D;
	static const All Image3DExt;
	static const All Image2DRect;
	static const All Image2DRectExt;
	static const All ImageCube;
	static const All ImageCubeExt;
	static const All ImageBuffer;
	static const All ImageBufferExt;
	static const All Image1DArray;
	static const All Image1DArrayExt;
	static const All Image2DArray;
	static const All Image2DArrayExt;
	static const All ImageCubeMapArray;
	static const All ImageCubeMapArrayExt;
	static const All Image2DMultisample;
	static const All Image2DMultisampleExt;
	static const All Image2DMultisampleArray;
	static const All Image2DMultisampleArrayExt;
	static const All IntImage1D;
	static const All IntImage1DExt;
	static const All IntImage2D;
	static const All IntImage2DExt;
	static const All IntImage3D;
	static const All IntImage3DExt;
	static const All IntImage2DRect;
	static const All IntImage2DRectExt;
	static const All IntImageCube;
	static const All IntImageCubeExt;
	static const All IntImageBuffer;
	static const All IntImageBufferExt;
	static const All IntImage1DArray;
	static const All IntImage1DArrayExt;
	static const All IntImage2DArray;
	static const All IntImage2DArrayExt;
	static const All IntImageCubeMapArray;
	static const All IntImageCubeMapArrayExt;
	static const All IntImage2DMultisample;
	static const All IntImage2DMultisampleExt;
	static const All IntImage2DMultisampleArray;
	static const All IntImage2DMultisampleArrayExt;
	static const All UnsignedIntImage1D;
	static const All UnsignedIntImage1DExt;
	static const All UnsignedIntImage2D;
	static const All UnsignedIntImage2DExt;
	static const All UnsignedIntImage3D;
	static const All UnsignedIntImage3DExt;
	static const All UnsignedIntImage2DRect;
	static const All UnsignedIntImage2DRectExt;
	static const All UnsignedIntImageCube;
	static const All UnsignedIntImageCubeExt;
	static const All UnsignedIntImageBuffer;
	static const All UnsignedIntImageBufferExt;
	static const All UnsignedIntImage1DArray;
	static const All UnsignedIntImage1DArrayExt;
	static const All UnsignedIntImage2DArray;
	static const All UnsignedIntImage2DArrayExt;
	static const All UnsignedIntImageCubeMapArray;
	static const All UnsignedIntImageCubeMapArrayExt;
	static const All UnsignedIntImage2DMultisample;
	static const All UnsignedIntImage2DMultisampleExt;
	static const All UnsignedIntImage2DMultisampleArray;
	static const All UnsignedIntImage2DMultisampleArrayExt;
	static const All MaxImageSamples;
	static const All MaxImageSamplesExt;
	static const All ImageBindingFormat;
	static const All ImageBindingFormatExt;
	static const All Rgb10A2ui;
	static const All PathFormatSvgNv;
	static const All PathFormatPsNv;
	static const All StandardFontNameNv;
	static const All SystemFontNameNv;
	static const All FileNameNv;
	static const All PathStrokeWidthNv;
	static const All PathEndCapsNv;
	static const All PathInitialEndCapNv;
	static const All PathTerminalEndCapNv;
	static const All PathJoinStyleNv;
	static const All PathMiterLimitNv;
	static const All PathDashCapsNv;
	static const All PathInitialDashCapNv;
	static const All PathTerminalDashCapNv;
	static const All PathDashOffsetNv;
	static const All PathClientLengthNv;
	static const All PathFillModeNv;
	static const All PathFillMaskNv;
	static const All PathFillCoverModeNv;
	static const All PathStrokeCoverModeNv;
	static const All PathStrokeMaskNv;
	static const All CountUpNv;
	static const All CountDownNv;
	static const All PathObjectBoundingBoxNv;
	static const All ConvexHullNv;
	static const All BoundingBoxNv;
	static const All TranslateXNv;
	static const All TranslateYNv;
	static const All Translate2DNv;
	static const All Translate3DNv;
	static const All Affine2DNv;
	static const All Affine3DNv;
	static const All TransposeAffine2DNv;
	static const All TransposeAffine3DNv;
	static const All Utf8Nv;
	static const All Utf16Nv;
	static const All BoundingBoxOfBoundingBoxesNv;
	static const All PathCommandCountNv;
	static const All PathCoordCountNv;
	static const All PathDashArrayCountNv;
	static const All PathComputedLengthNv;
	static const All PathFillBoundingBoxNv;
	static const All PathStrokeBoundingBoxNv;
	static const All SquareNv;
	static const All RoundNv;
	static const All TriangularNv;
	static const All BevelNv;
	static const All MiterRevertNv;
	static const All MiterTruncateNv;
	static const All SkipMissingGlyphNv;
	static const All UseMissingGlyphNv;
	static const All PathErrorPositionNv;
	static const All PathFogGenModeNv;
	static const All AccumAdjacentPairsNv;
	static const All AdjacentPairsNv;
	static const All FirstToRestNv;
	static const All PathGenModeNv;
	static const All PathGenCoeffNv;
	static const All PathGenColorFormatNv;
	static const All PathGenComponentsNv;
	static const All PathDashOffsetResetNv;
	static const All MoveToResetsNv;
	static const All MoveToContinuesNv;
	static const All PathStencilFuncNv;
	static const All PathStencilRefNv;
	static const All PathStencilValueMaskNv;
	static const All ScaledResolveFastestExt;
	static const All ScaledResolveNicestExt;
	static const All MinMapBufferAlignment;
	static const All PathStencilDepthOffsetFactorNv;
	static const All PathStencilDepthOffsetUnitsNv;
	static const All PathCoverDepthFuncNv;
	static const All ImageFormatCompatibilityType;
	static const All ImageFormatCompatibilityBySize;
	static const All ImageFormatCompatibilityByClass;
	static const All MaxVertexImageUniforms;
	static const All MaxTessControlImageUniforms;
	static const All MaxTessEvaluationImageUniforms;
	static const All MaxGeometryImageUniforms;
	static const All MaxFragmentImageUniforms;
	static const All MaxCombinedImageUniforms;
	static const All MaxDeep3DTextureWidthHeightNv;
	static const All MaxDeep3DTextureDepthNv;
	static const All ShaderStorageBuffer;
	static const All ShaderStorageBufferBinding;
	static const All ShaderStorageBufferStart;
	static const All ShaderStorageBufferSize;
	static const All MaxVertexShaderStorageBlocks;
	static const All MaxGeometryShaderStorageBlocks;
	static const All MaxTessControlShaderStorageBlocks;
	static const All MaxTessEvaluationShaderStorageBlocks;
	static const All MaxFragmentShaderStorageBlocks;
	static const All MaxComputeShaderStorageBlocks;
	static const All MaxCombinedShaderStorageBlocks;
	static const All MaxShaderStorageBufferBindings;
	static const All MaxShaderStorageBlockSize;
	static const All ShaderStorageBufferOffsetAlignment;
	static const All SyncX11FenceExt;
	static const All DepthStencilTextureMode;
	static const All MaxComputeFixedGroupInvocationsArb;
	static const All MaxComputeWorkGroupInvocations;
	static const All UniformBlockReferencedByComputeShader;
	static const All AtomicCounterBufferReferencedByComputeShader;
	static const All DispatchIndirectBuffer;
	static const All DispatchIndirectBufferBinding;
	static const All ContextRobustAccess;
	static const All ContextRobustAccessKhr;
	static const All ComputeProgramNv;
	static const All ComputeProgramParameterBufferNv;
	static const All Texture2DMultisample;
	static const All ProxyTexture2DMultisample;
	static const All Texture2DMultisampleArray;
	static const All ProxyTexture2DMultisampleArray;
	static const All TextureBinding2DMultisample;
	static const All TextureBinding2DMultisampleArray;
	static const All TextureSamples;
	static const All TextureFixedSampleLocations;
	static const All Sampler2DMultisample;
	static const All IntSampler2DMultisample;
	static const All UnsignedIntSampler2DMultisample;
	static const All Sampler2DMultisampleArray;
	static const All IntSampler2DMultisampleArray;
	static const All UnsignedIntSampler2DMultisampleArray;
	static const All MaxColorTextureSamples;
	static const All MaxDepthTextureSamples;
	static const All MaxIntegerSamples;
	static const All MaxServerWaitTimeout;
	static const All ObjectType;
	static const All SyncCondition;
	static const All SyncStatus;
	static const All SyncFlags;
	static const All SyncFence;
	static const All SyncGpuCommandsComplete;
	static const All Unsignaled;
	static const All Signaled;
	static const All AlreadySignaled;
	static const All TimeoutExpired;
	static const All ConditionSatisfied;
	static const All WaitFailed;
	static const All BufferAccessFlags;
	static const All BufferMapLength;
	static const All BufferMapOffset;
	static const All MaxVertexOutputComponents;
	static const All MaxGeometryInputComponents;
	static const All MaxGeometryOutputComponents;
	static const All MaxFragmentInputComponents;
	static const All ContextProfileMask;
	static const All UnpackCompressedBlockWidth;
	static const All UnpackCompressedBlockHeight;
	static const All UnpackCompressedBlockDepth;
	static const All UnpackCompressedBlockSize;
	static const All PackCompressedBlockWidth;
	static const All PackCompressedBlockHeight;
	static const All PackCompressedBlockDepth;
	static const All PackCompressedBlockSize;
	static const All TextureImmutableFormat;
	static const All MaxDebugMessageLength;
	static const All MaxDebugMessageLengthAmd;
	static const All MaxDebugMessageLengthArb;
	static const All MaxDebugMessageLengthKhr;
	static const All MaxDebugLoggedMessages;
	static const All MaxDebugLoggedMessagesAmd;
	static const All MaxDebugLoggedMessagesArb;
	static const All MaxDebugLoggedMessagesKhr;
	static const All DebugLoggedMessages;
	static const All DebugLoggedMessagesAmd;
	static const All DebugLoggedMessagesArb;
	static const All DebugLoggedMessagesKhr;
	static const All DebugSeverityHigh;
	static const All DebugSeverityHighAmd;
	static const All DebugSeverityHighArb;
	static const All DebugSeverityHighKhr;
	static const All DebugSeverityMedium;
	static const All DebugSeverityMediumAmd;
	static const All DebugSeverityMediumArb;
	static const All DebugSeverityMediumKhr;
	static const All DebugSeverityLow;
	static const All DebugSeverityLowAmd;
	static const All DebugSeverityLowArb;
	static const All DebugSeverityLowKhr;
	static const All DebugCategoryApiErrorAmd;
	static const All DebugCategoryWindowSystemAmd;
	static const All DebugCategoryDeprecationAmd;
	static const All DebugCategoryUndefinedBehaviorAmd;
	static const All DebugCategoryPerformanceAmd;
	static const All DebugCategoryShaderCompilerAmd;
	static const All DebugCategoryApplicationAmd;
	static const All DebugCategoryOtherAmd;
	static const All BufferObjectExt;
	static const All DataBufferAmd;
	static const All PerformanceMonitorAmd;
	static const All QueryObjectAmd;
	static const All QueryObjectExt;
	static const All VertexArrayObjectAmd;
	static const All VertexArrayObjectExt;
	static const All SamplerObjectAmd;
	static const All ExternalVirtualMemoryBufferAmd;
	static const All QueryBuffer;
	static const All QueryBufferAmd;
	static const All QueryBufferBinding;
	static const All QueryBufferBindingAmd;
	static const All QueryResultNoWait;
	static const All QueryResultNoWaitAmd;
	static const All VirtualPageSizeXAmd;
	static const All VirtualPageSizeXArb;
	static const All VirtualPageSizeYAmd;
	static const All VirtualPageSizeYArb;
	static const All VirtualPageSizeZAmd;
	static const All VirtualPageSizeZArb;
	static const All MaxSparseTextureSizeAmd;
	static const All MaxSparseTextureSizeArb;
	static const All MaxSparse3DTextureSizeAmd;
	static const All MaxSparse3DTextureSizeArb;
	static const All MaxSparseArrayTextureLayers;
	static const All MaxSparseArrayTextureLayersArb;
	static const All MinSparseLevelAmd;
	static const All MinSparseLevelArb;
	static const All MinLodWarningAmd;
	static const All TextureBufferOffset;
	static const All TextureBufferSize;
	static const All TextureBufferOffsetAlignment;
	static const All StreamRasterizationAmd;
	static const All VertexElementSwizzleAmd;
	static const All VertexIdSwizzleAmd;
	static const All TextureSparseArb;
	static const All VirtualPageSizeIndexArb;
	static const All NumVirtualPageSizesArb;
	static const All SparseTextureFullArrayCubeMipmapsArb;
	static const All ComputeShader;
	static const All MaxComputeUniformBlocks;
	static const All MaxComputeTextureImageUnits;
	static const All MaxComputeImageUniforms;
	static const All MaxComputeWorkGroupCount;
	static const All MaxComputeFixedGroupSizeArb;
	static const All MaxComputeWorkGroupSize;
	static const All CompressedR11Eac;
	static const All CompressedSignedR11Eac;
	static const All CompressedRg11Eac;
	static const All CompressedSignedRg11Eac;
	static const All CompressedRgb8Etc2;
	static const All CompressedSrgb8Etc2;
	static const All CompressedRgb8PunchthroughAlpha1Etc2;
	static const All CompressedSrgb8PunchthroughAlpha1Etc2;
	static const All CompressedRgba8Etc2Eac;
	static const All CompressedSrgb8Alpha8Etc2Eac;
	static const All BlendPremultipliedSrcNv;
	static const All BlendOverlapNv;
	static const All UncorrelatedNv;
	static const All DisjointNv;
	static const All ConjointNv;
	static const All BlendAdvancedCoherentKhr;
	static const All BlendAdvancedCoherentNv;
	static const All SrcNv;
	static const All DstNv;
	static const All SrcOverNv;
	static const All DstOverNv;
	static const All SrcInNv;
	static const All DstInNv;
	static const All SrcOutNv;
	static const All DstOutNv;
	static const All SrcAtopNv;
	static const All DstAtopNv;
	static const All PlusNv;
	static const All PlusDarkerNv;
	static const All MultiplyKhr;
	static const All MultiplyNv;
	static const All ScreenKhr;
	static const All ScreenNv;
	static const All OverlayKhr;
	static const All OverlayNv;
	static const All DarkenKhr;
	static const All DarkenNv;
	static const All LightenKhr;
	static const All LightenNv;
	static const All ColordodgeKhr;
	static const All ColordodgeNv;
	static const All ColorburnKhr;
	static const All ColorburnNv;
	static const All HardlightKhr;
	static const All HardlightNv;
	static const All SoftlightKhr;
	static const All SoftlightNv;
	static const All DifferenceKhr;
	static const All DifferenceNv;
	static const All MinusNv;
	static const All ExclusionKhr;
	static const All ExclusionNv;
	static const All ContrastNv;
	static const All InvertRgbNv;
	static const All LineardodgeNv;
	static const All LinearburnNv;
	static const All VividlightNv;
	static const All LinearlightNv;
	static const All PinlightNv;
	static const All HardmixNv;
	static const All HslHueKhr;
	static const All HslHueNv;
	static const All HslSaturationKhr;
	static const All HslSaturationNv;
	static const All HslColorKhr;
	static const All HslColorNv;
	static const All HslLuminosityKhr;
	static const All HslLuminosityNv;
	static const All PlusClampedNv;
	static const All PlusClampedAlphaNv;
	static const All MinusClampedNv;
	static const All InvertOvgNv;
	static const All AtomicCounterBuffer;
	static const All AtomicCounterBufferBinding;
	static const All AtomicCounterBufferStart;
	static const All AtomicCounterBufferSize;
	static const All AtomicCounterBufferDataSize;
	static const All AtomicCounterBufferActiveAtomicCounters;
	static const All AtomicCounterBufferActiveAtomicCounterIndices;
	static const All AtomicCounterBufferReferencedByVertexShader;
	static const All AtomicCounterBufferReferencedByTessControlShader;
	static const All AtomicCounterBufferReferencedByTessEvaluationShader;
	static const All AtomicCounterBufferReferencedByGeometryShader;
	static const All AtomicCounterBufferReferencedByFragmentShader;
	static const All MaxVertexAtomicCounterBuffers;
	static const All MaxTessControlAtomicCounterBuffers;
	static const All MaxTessEvaluationAtomicCounterBuffers;
	static const All MaxGeometryAtomicCounterBuffers;
	static const All MaxFragmentAtomicCounterBuffers;
	static const All MaxCombinedAtomicCounterBuffers;
	static const All MaxVertexAtomicCounters;
	static const All MaxTessControlAtomicCounters;
	static const All MaxTessEvaluationAtomicCounters;
	static const All MaxGeometryAtomicCounters;
	static const All MaxFragmentAtomicCounters;
	static const All MaxCombinedAtomicCounters;
	static const All MaxAtomicCounterBufferSize;
	static const All ActiveAtomicCounterBuffers;
	static const All UniformAtomicCounterBufferIndex;
	static const All UnsignedIntAtomicCounter;
	static const All MaxAtomicCounterBufferBindings;
	static const All DebugOutput;
	static const All DebugOutputKhr;
	static const All Uniform;
	static const All UniformBlock;
	static const All ProgramInput;
	static const All ProgramOutput;
	static const All BufferVariable;
	static const All ShaderStorageBlock;
	static const All IsPerPatch;
	static const All VertexSubroutine;
	static const All TessControlSubroutine;
	static const All TessEvaluationSubroutine;
	static const All GeometrySubroutine;
	static const All FragmentSubroutine;
	static const All ComputeSubroutine;
	static const All VertexSubroutineUniform;
	static const All TessControlSubroutineUniform;
	static const All TessEvaluationSubroutineUniform;
	static const All GeometrySubroutineUniform;
	static const All FragmentSubroutineUniform;
	static const All ComputeSubroutineUniform;
	static const All TransformFeedbackVarying;
	static const All ActiveResources;
	static const All MaxNameLength;
	static const All MaxNumActiveVariables;
	static const All MaxNumCompatibleSubroutines;
	static const All NameLength;
	static const All Type;
	static const All ArraySize;
	static const All Offset;
	static const All BlockIndex;
	static const All ArrayStride;
	static const All MatrixStride;
	static const All IsRowMajor;
	static const All AtomicCounterBufferIndex;
	static const All BufferBinding;
	static const All BufferDataSize;
	static const All NumActiveVariables;
	static const All ActiveVariables;
	static const All ReferencedByVertexShader;
	static const All ReferencedByTessControlShader;
	static const All ReferencedByTessEvaluationShader;
	static const All ReferencedByGeometryShader;
	static const All ReferencedByFragmentShader;
	static const All ReferencedByComputeShader;
	static const All TopLevelArraySize;
	static const All TopLevelArrayStride;
	static const All Location;
	static const All LocationIndex;
	static const All FramebufferDefaultWidth;
	static const All FramebufferDefaultHeight;
	static const All FramebufferDefaultLayers;
	static const All FramebufferDefaultSamples;
	static const All FramebufferDefaultFixedSampleLocations;
	static const All MaxFramebufferWidth;
	static const All MaxFramebufferHeight;
	static const All MaxFramebufferLayers;
	static const All MaxFramebufferSamples;
	static const All WarpSizeNv;
	static const All WarpsPerSmNv;
	static const All SmCountNv;
	static const All MaxComputeVariableGroupInvocationsArb;
	static const All MaxComputeVariableGroupSizeArb;
	static const All LocationComponent;
	static const All TransformFeedbackBufferIndex;
	static const All TransformFeedbackBufferStride;
	static const All ClipOrigin;
	static const All ClipDepthMode;
	static const All NegativeOneToOne;
	static const All ZeroToOne;
	static const All ClearTexture;
	static const All FontGlyphsAvailableNv;
	static const All FontTargetUnavailableNv;
	static const All FontUnavailableNv;
	static const All FontUnintelligibleNv;
	static const All StandardFontFormatNv;
	static const All FragmentInputNv;
	static const All NumSampleCounts;
	static const All CompressedRgbaAstc4X4Khr;
	static const All CompressedRgbaAstc5X4Khr;
	static const All CompressedRgbaAstc5X5Khr;
	static const All CompressedRgbaAstc6X5Khr;
	static const All CompressedRgbaAstc6X6Khr;
	static const All CompressedRgbaAstc8X5Khr;
	static const All CompressedRgbaAstc8X6Khr;
	static const All CompressedRgbaAstc8X8Khr;
	static const All CompressedRgbaAstc10X5Khr;
	static const All CompressedRgbaAstc10X6Khr;
	static const All CompressedRgbaAstc10X8Khr;
	static const All CompressedRgbaAstc10X10Khr;
	static const All CompressedRgbaAstc12X10Khr;
	static const All CompressedRgbaAstc12X12Khr;
	static const All CompressedSrgb8Alpha8Astc4X4Khr;
	static const All CompressedSrgb8Alpha8Astc5X4Khr;
	static const All CompressedSrgb8Alpha8Astc5X5Khr;
	static const All CompressedSrgb8Alpha8Astc6X5Khr;
	static const All CompressedSrgb8Alpha8Astc6X6Khr;
	static const All CompressedSrgb8Alpha8Astc8X5Khr;
	static const All CompressedSrgb8Alpha8Astc8X6Khr;
	static const All CompressedSrgb8Alpha8Astc8X8Khr;
	static const All CompressedSrgb8Alpha8Astc10X5Khr;
	static const All CompressedSrgb8Alpha8Astc10X6Khr;
	static const All CompressedSrgb8Alpha8Astc10X8Khr;
	static const All CompressedSrgb8Alpha8Astc10X10Khr;
	static const All CompressedSrgb8Alpha8Astc12X10Khr;
	static const All CompressedSrgb8Alpha8Astc12X12Khr;
	static const All PerfqueryCounterEventIntel;
	static const All PerfqueryCounterDurationNormIntel;
	static const All PerfqueryCounterDurationRawIntel;
	static const All PerfqueryCounterThroughputIntel;
	static const All PerfqueryCounterRawIntel;
	static const All PerfqueryCounterTimestampIntel;
	static const All PerfqueryCounterDataUint32Intel;
	static const All PerfqueryCounterDataUint64Intel;
	static const All PerfqueryCounterDataFloatIntel;
	static const All PerfqueryCounterDataDoubleIntel;
	static const All PerfqueryCounterDataBool32Intel;
	static const All PerfqueryQueryNameLengthMaxIntel;
	static const All PerfqueryCounterNameLengthMaxIntel;
	static const All PerfqueryCounterDescLengthMaxIntel;
	static const All PerfqueryGpaExtendedCountersIntel;
	static const All RoundedRectNv;
	static const All RelativeRoundedRectNv;
	static const All RoundedRect2Nv;
	static const All RelativeRoundedRect2Nv;
	static const All RoundedRect4Nv;
	static const All RelativeRoundedRect4Nv;
	static const All RoundedRect8Nv;
	static const All RelativeRoundedRect8Nv;
	static const All RestartPathNv;
	static const All DupFirstCubicCurveToNv;
	static const All DupLastCubicCurveToNv;
	static const All RectNv;
	static const All RelativeRectNv;
	static const All CircularCcwArcToNv;
	static const All CircularCwArcToNv;
	static const All CircularTangentArcToNv;
	static const All ArcToNv;
	static const All RelativeArcToNv;
	static const All AllAttribBits;
	static const All AllBarrierBits;
	static const All AllBarrierBitsExt;
	static const All AllShaderBits;
	static const All AllShaderBitsExt;
	static const All ClientAllAttribBits;
	static const All GlAllBarrierBits;
	static const All InvalidIndex;
	static const All QueryAllEventBitsAmd;
	static const All TimeoutIgnored;
	static const All LayoutLinearIntel;
	static const All One;
	static const All True;
	static const All CullVertexIbm;
	static const All AllStaticDataIbm;
	static const All StaticVertexArrayIbm;
	static const All VertexArrayListIbm;
	static const All NormalArrayListIbm;
	static const All ColorArrayListIbm;
	static const All IndexArrayListIbm;
	static const All TextureCoordArrayListIbm;
	static const All EdgeFlagArrayListIbm;
	static const All FogCoordinateArrayListIbm;
	static const All SecondaryColorArrayListIbm;
	static const All VertexArrayListStrideIbm;
	static const All NormalArrayListStrideIbm;
	static const All ColorArrayListStrideIbm;
	static const All IndexArrayListStrideIbm;
	static const All TextureCoordArrayListStrideIbm;
	static const All EdgeFlagArrayListStrideIbm;
	static const All FogCoordinateArrayListStrideIbm;
	static const All SecondaryColorArrayListStrideIbm;
	static const All LayoutLinearCpuCachedIntel;
	static const All Two;
	static const All NextBufferNv;
	static const All Three;
	static const All SkipComponents4Nv;
	static const All Four;
	static const All SkipComponents3Nv;
	static const All SkipComponents2Nv;
	static const All SkipComponents1Nv;
OPENGL_ENUM_END

OPENGL_ENUM_START(AlphaFunction)
	static const AlphaFunction Never;
	static const AlphaFunction Less;
	static const AlphaFunction Equal;
	static const AlphaFunction Lequal;
	static const AlphaFunction Greater;
	static const AlphaFunction Notequal;
	static const AlphaFunction Gequal;
	static const AlphaFunction Always;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdBlendMinmaxFactor)
	static const AmdBlendMinmaxFactor FactorMinAmd;
	static const AmdBlendMinmaxFactor FactorMaxAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdConservativeDepth)
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdDebugOutput)
	static const AmdDebugOutput MaxDebugMessageLengthAmd;
	static const AmdDebugOutput MaxDebugLoggedMessagesAmd;
	static const AmdDebugOutput DebugLoggedMessagesAmd;
	static const AmdDebugOutput DebugSeverityHighAmd;
	static const AmdDebugOutput DebugSeverityMediumAmd;
	static const AmdDebugOutput DebugSeverityLowAmd;
	static const AmdDebugOutput DebugCategoryApiErrorAmd;
	static const AmdDebugOutput DebugCategoryWindowSystemAmd;
	static const AmdDebugOutput DebugCategoryDeprecationAmd;
	static const AmdDebugOutput DebugCategoryUndefinedBehaviorAmd;
	static const AmdDebugOutput DebugCategoryPerformanceAmd;
	static const AmdDebugOutput DebugCategoryShaderCompilerAmd;
	static const AmdDebugOutput DebugCategoryApplicationAmd;
	static const AmdDebugOutput DebugCategoryOtherAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdDepthClampSeparate)
	static const AmdDepthClampSeparate DepthClampNearAmd;
	static const AmdDepthClampSeparate DepthClampFarAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdDrawBuffersBlend)
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdGcnShader)
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdGpuShaderInt64)
	static const AmdGpuShaderInt64 Int64Nv;
	static const AmdGpuShaderInt64 UnsignedInt64Nv;
	static const AmdGpuShaderInt64 Int8Nv;
	static const AmdGpuShaderInt64 Int8Vec2Nv;
	static const AmdGpuShaderInt64 Int8Vec3Nv;
	static const AmdGpuShaderInt64 Int8Vec4Nv;
	static const AmdGpuShaderInt64 Int16Nv;
	static const AmdGpuShaderInt64 Int16Vec2Nv;
	static const AmdGpuShaderInt64 Int16Vec3Nv;
	static const AmdGpuShaderInt64 Int16Vec4Nv;
	static const AmdGpuShaderInt64 Int64Vec2Nv;
	static const AmdGpuShaderInt64 Int64Vec3Nv;
	static const AmdGpuShaderInt64 Int64Vec4Nv;
	static const AmdGpuShaderInt64 UnsignedInt8Nv;
	static const AmdGpuShaderInt64 UnsignedInt8Vec2Nv;
	static const AmdGpuShaderInt64 UnsignedInt8Vec3Nv;
	static const AmdGpuShaderInt64 UnsignedInt8Vec4Nv;
	static const AmdGpuShaderInt64 UnsignedInt16Nv;
	static const AmdGpuShaderInt64 UnsignedInt16Vec2Nv;
	static const AmdGpuShaderInt64 UnsignedInt16Vec3Nv;
	static const AmdGpuShaderInt64 UnsignedInt16Vec4Nv;
	static const AmdGpuShaderInt64 UnsignedInt64Vec2Nv;
	static const AmdGpuShaderInt64 UnsignedInt64Vec3Nv;
	static const AmdGpuShaderInt64 UnsignedInt64Vec4Nv;
	static const AmdGpuShaderInt64 Float16Nv;
	static const AmdGpuShaderInt64 Float16Vec2Nv;
	static const AmdGpuShaderInt64 Float16Vec3Nv;
	static const AmdGpuShaderInt64 Float16Vec4Nv;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdInterleavedElements)
	static const AmdInterleavedElements Red;
	static const AmdInterleavedElements Green;
	static const AmdInterleavedElements Blue;
	static const AmdInterleavedElements Alpha;
	static const AmdInterleavedElements Rg8ui;
	static const AmdInterleavedElements Rg16ui;
	static const AmdInterleavedElements Rgba8ui;
	static const AmdInterleavedElements VertexElementSwizzleAmd;
	static const AmdInterleavedElements VertexIdSwizzleAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdMultiDrawIndirect)
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdNameGenDelete)
	static const AmdNameGenDelete DataBufferAmd;
	static const AmdNameGenDelete PerformanceMonitorAmd;
	static const AmdNameGenDelete QueryObjectAmd;
	static const AmdNameGenDelete VertexArrayObjectAmd;
	static const AmdNameGenDelete SamplerObjectAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdOcclusionQueryEvent)
	static const AmdOcclusionQueryEvent QueryDepthPassEventBitAmd;
	static const AmdOcclusionQueryEvent QueryDepthFailEventBitAmd;
	static const AmdOcclusionQueryEvent QueryStencilFailEventBitAmd;
	static const AmdOcclusionQueryEvent QueryDepthBoundsFailEventBitAmd;
	static const AmdOcclusionQueryEvent OcclusionQueryEventMaskAmd;
	static const AmdOcclusionQueryEvent QueryAllEventBitsAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdPerformanceMonitor)
	static const AmdPerformanceMonitor CounterTypeAmd;
	static const AmdPerformanceMonitor CounterRangeAmd;
	static const AmdPerformanceMonitor UnsignedInt64Amd;
	static const AmdPerformanceMonitor PercentageAmd;
	static const AmdPerformanceMonitor PerfmonResultAvailableAmd;
	static const AmdPerformanceMonitor PerfmonResultSizeAmd;
	static const AmdPerformanceMonitor PerfmonResultAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdPinnedMemory)
	static const AmdPinnedMemory ExternalVirtualMemoryBufferAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdQueryBufferObject)
	static const AmdQueryBufferObject QueryBufferAmd;
	static const AmdQueryBufferObject QueryBufferBindingAmd;
	static const AmdQueryBufferObject QueryResultNoWaitAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdSamplePositions)
	static const AmdSamplePositions SubsampleDistanceAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdSeamlessCubemapPerTexture)
	static const AmdSeamlessCubemapPerTexture TextureCubeMapSeamless;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdShaderAtomicCounterOps)
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdShaderStencilExport)
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdShaderTrinaryMinmax)
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdSparseTexture)
	static const AmdSparseTexture TextureStorageSparseBitAmd;
	static const AmdSparseTexture VirtualPageSizeXAmd;
	static const AmdSparseTexture VirtualPageSizeYAmd;
	static const AmdSparseTexture VirtualPageSizeZAmd;
	static const AmdSparseTexture MaxSparseTextureSizeAmd;
	static const AmdSparseTexture MaxSparse3DTextureSizeAmd;
	static const AmdSparseTexture MaxSparseArrayTextureLayers;
	static const AmdSparseTexture MinSparseLevelAmd;
	static const AmdSparseTexture MinLodWarningAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdStencilOperationExtended)
	static const AmdStencilOperationExtended SetAmd;
	static const AmdStencilOperationExtended ReplaceValueAmd;
	static const AmdStencilOperationExtended StencilOpValueAmd;
	static const AmdStencilOperationExtended StencilBackOpValueAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdTextureTexture4)
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdTransformFeedback3LinesTriangles)
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdTransformFeedback4)
	static const AmdTransformFeedback4 StreamRasterizationAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdVertexShaderLayer)
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdVertexShaderTesselator)
	static const AmdVertexShaderTesselator SamplerBufferAmd;
	static const AmdVertexShaderTesselator IntSamplerBufferAmd;
	static const AmdVertexShaderTesselator UnsignedIntSamplerBufferAmd;
	static const AmdVertexShaderTesselator TessellationModeAmd;
	static const AmdVertexShaderTesselator TessellationFactorAmd;
	static const AmdVertexShaderTesselator DiscreteAmd;
	static const AmdVertexShaderTesselator ContinuousAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdVertexShaderTessellator)
	static const AmdVertexShaderTessellator SamplerBufferAmd;
	static const AmdVertexShaderTessellator IntSamplerBufferAmd;
	static const AmdVertexShaderTessellator UnsignedIntSamplerBufferAmd;
	static const AmdVertexShaderTessellator TessellationModeAmd;
	static const AmdVertexShaderTessellator TessellationFactorAmd;
	static const AmdVertexShaderTessellator DiscreteAmd;
	static const AmdVertexShaderTessellator ContinuousAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(AmdVertexShaderViewportIndex)
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleAuxDepthStencil)
	static const AppleAuxDepthStencil AuxDepthStencilApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleClientStorage)
	static const AppleClientStorage UnpackClientStorageApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleElementArray)
	static const AppleElementArray ElementArrayApple;
	static const AppleElementArray ElementArrayTypeApple;
	static const AppleElementArray ElementArrayPointerApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleFence)
	static const AppleFence DrawPixelsApple;
	static const AppleFence FenceApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleFloatPixels)
	static const AppleFloatPixels HalfApple;
	static const AppleFloatPixels RgbaFloat32Apple;
	static const AppleFloatPixels RgbFloat32Apple;
	static const AppleFloatPixels AlphaFloat32Apple;
	static const AppleFloatPixels IntensityFloat32Apple;
	static const AppleFloatPixels LuminanceFloat32Apple;
	static const AppleFloatPixels LuminanceAlphaFloat32Apple;
	static const AppleFloatPixels RgbaFloat16Apple;
	static const AppleFloatPixels RgbFloat16Apple;
	static const AppleFloatPixels AlphaFloat16Apple;
	static const AppleFloatPixels IntensityFloat16Apple;
	static const AppleFloatPixels LuminanceFloat16Apple;
	static const AppleFloatPixels LuminanceAlphaFloat16Apple;
	static const AppleFloatPixels ColorFloatApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleFlushBufferRange)
	static const AppleFlushBufferRange BufferSerializedModifyApple;
	static const AppleFlushBufferRange BufferFlushingUnmapApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleObjectPurgeable)
	static const AppleObjectPurgeable BufferObjectApple;
	static const AppleObjectPurgeable ReleasedApple;
	static const AppleObjectPurgeable VolatileApple;
	static const AppleObjectPurgeable RetainedApple;
	static const AppleObjectPurgeable UndefinedApple;
	static const AppleObjectPurgeable PurgeableApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleRgb422)
	static const AppleRgb422 UnsignedShort88Apple;
	static const AppleRgb422 UnsignedShort88RevApple;
	static const AppleRgb422 Rgb422Apple;
	static const AppleRgb422 RgbRaw422Apple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleRowBytes)
	static const AppleRowBytes PackRowBytesApple;
	static const AppleRowBytes UnpackRowBytesApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleSpecularVector)
	static const AppleSpecularVector LightModelSpecularVectorApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleTextureRange)
	static const AppleTextureRange TextureRangeLengthApple;
	static const AppleTextureRange TextureRangePointerApple;
	static const AppleTextureRange TextureStorageHintApple;
	static const AppleTextureRange StoragePrivateApple;
	static const AppleTextureRange StorageCachedApple;
	static const AppleTextureRange StorageSharedApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleTransformHint)
	static const AppleTransformHint TransformHintApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleVertexArrayObject)
	static const AppleVertexArrayObject VertexArrayBindingApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleVertexArrayRange)
	static const AppleVertexArrayRange VertexArrayRangeApple;
	static const AppleVertexArrayRange VertexArrayRangeLengthApple;
	static const AppleVertexArrayRange VertexArrayStorageHintApple;
	static const AppleVertexArrayRange VertexArrayRangePointerApple;
	static const AppleVertexArrayRange StorageClientApple;
	static const AppleVertexArrayRange StorageCachedApple;
	static const AppleVertexArrayRange StorageSharedApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleVertexProgramEvaluators)
	static const AppleVertexProgramEvaluators VertexAttribMap1Apple;
	static const AppleVertexProgramEvaluators VertexAttribMap2Apple;
	static const AppleVertexProgramEvaluators VertexAttribMap1SizeApple;
	static const AppleVertexProgramEvaluators VertexAttribMap1CoeffApple;
	static const AppleVertexProgramEvaluators VertexAttribMap1OrderApple;
	static const AppleVertexProgramEvaluators VertexAttribMap1DomainApple;
	static const AppleVertexProgramEvaluators VertexAttribMap2SizeApple;
	static const AppleVertexProgramEvaluators VertexAttribMap2CoeffApple;
	static const AppleVertexProgramEvaluators VertexAttribMap2OrderApple;
	static const AppleVertexProgramEvaluators VertexAttribMap2DomainApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(AppleYcbcr422)
	static const AppleYcbcr422 Ycbcr422Apple;
	static const AppleYcbcr422 UnsignedShort88Apple;
	static const AppleYcbcr422 UnsignedShort88RevApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbArraysOfArrays)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbBaseInstance)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbBindlessTexture)
	static const ArbBindlessTexture UnsignedInt64Arb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbBlendFuncExtended)
	static const ArbBlendFuncExtended Src1Alpha;
	static const ArbBlendFuncExtended Src1Color;
	static const ArbBlendFuncExtended OneMinusSrc1Color;
	static const ArbBlendFuncExtended OneMinusSrc1Alpha;
	static const ArbBlendFuncExtended MaxDualSourceDrawBuffers;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbBufferStorage)
	static const ArbBufferStorage ClientMappedBufferBarrierBit;
	static const ArbBufferStorage MapReadBit;
	static const ArbBufferStorage MapWriteBit;
	static const ArbBufferStorage MapPersistentBit;
	static const ArbBufferStorage MapCoherentBit;
	static const ArbBufferStorage DynamicStorageBit;
	static const ArbBufferStorage ClientStorageBit;
	static const ArbBufferStorage BufferImmutableStorage;
	static const ArbBufferStorage BufferStorageFlags;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbClearBufferObject)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbClearTexture)
	static const ArbClearTexture ClearTexture;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbClEvent)
	static const ArbClEvent SyncClEventArb;
	static const ArbClEvent SyncClEventCompleteArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbClipControl)
	static const ArbClipControl LowerLeft;
	static const ArbClipControl UpperLeft;
	static const ArbClipControl ClipOrigin;
	static const ArbClipControl ClipDepthMode;
	static const ArbClipControl NegativeOneToOne;
	static const ArbClipControl ZeroToOne;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbColorBufferFloat)
	static const ArbColorBufferFloat RgbaFloatModeArb;
	static const ArbColorBufferFloat ClampVertexColorArb;
	static const ArbColorBufferFloat ClampFragmentColorArb;
	static const ArbColorBufferFloat ClampReadColorArb;
	static const ArbColorBufferFloat FixedOnlyArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbCompatibility)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbCompressedTexturePixelStorage)
	static const ArbCompressedTexturePixelStorage UnpackCompressedBlockWidth;
	static const ArbCompressedTexturePixelStorage UnpackCompressedBlockHeight;
	static const ArbCompressedTexturePixelStorage UnpackCompressedBlockDepth;
	static const ArbCompressedTexturePixelStorage UnpackCompressedBlockSize;
	static const ArbCompressedTexturePixelStorage PackCompressedBlockWidth;
	static const ArbCompressedTexturePixelStorage PackCompressedBlockHeight;
	static const ArbCompressedTexturePixelStorage PackCompressedBlockDepth;
	static const ArbCompressedTexturePixelStorage PackCompressedBlockSize;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbComputeShader)
	static const ArbComputeShader ComputeShaderBit;
	static const ArbComputeShader MaxComputeSharedMemorySize;
	static const ArbComputeShader MaxComputeUniformComponents;
	static const ArbComputeShader MaxComputeAtomicCounterBuffers;
	static const ArbComputeShader MaxComputeAtomicCounters;
	static const ArbComputeShader MaxCombinedComputeUniformComponents;
	static const ArbComputeShader ComputeWorkGroupSize;
	static const ArbComputeShader MaxComputeWorkGroupInvocations;
	static const ArbComputeShader UniformBlockReferencedByComputeShader;
	static const ArbComputeShader AtomicCounterBufferReferencedByComputeShader;
	static const ArbComputeShader DispatchIndirectBuffer;
	static const ArbComputeShader DispatchIndirectBufferBinding;
	static const ArbComputeShader ComputeShader;
	static const ArbComputeShader MaxComputeUniformBlocks;
	static const ArbComputeShader MaxComputeTextureImageUnits;
	static const ArbComputeShader MaxComputeImageUniforms;
	static const ArbComputeShader MaxComputeWorkGroupCount;
	static const ArbComputeShader MaxComputeWorkGroupSize;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbComputeVariableGroupSize)
	static const ArbComputeVariableGroupSize MaxComputeFixedGroupInvocationsArb;
	static const ArbComputeVariableGroupSize MaxComputeFixedGroupSizeArb;
	static const ArbComputeVariableGroupSize MaxComputeVariableGroupInvocationsArb;
	static const ArbComputeVariableGroupSize MaxComputeVariableGroupSizeArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbConditionalRenderInverted)
	static const ArbConditionalRenderInverted QueryWaitInverted;
	static const ArbConditionalRenderInverted QueryNoWaitInverted;
	static const ArbConditionalRenderInverted QueryByRegionWaitInverted;
	static const ArbConditionalRenderInverted QueryByRegionNoWaitInverted;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbConservativeDepth)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbCopyBuffer)
	static const ArbCopyBuffer CopyReadBuffer;
	static const ArbCopyBuffer CopyReadBufferBinding;
	static const ArbCopyBuffer CopyWriteBuffer;
	static const ArbCopyBuffer CopyWriteBufferBinding;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbCopyImage)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbCullDistance)
	static const ArbCullDistance MaxCullDistances;
	static const ArbCullDistance MaxCombinedClipAndCullDistances;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbDebugOutput)
	static const ArbDebugOutput DebugOutputSynchronousArb;
	static const ArbDebugOutput DebugNextLoggedMessageLengthArb;
	static const ArbDebugOutput DebugCallbackFunctionArb;
	static const ArbDebugOutput DebugCallbackUserParamArb;
	static const ArbDebugOutput DebugSourceApiArb;
	static const ArbDebugOutput DebugSourceWindowSystemArb;
	static const ArbDebugOutput DebugSourceShaderCompilerArb;
	static const ArbDebugOutput DebugSourceThirdPartyArb;
	static const ArbDebugOutput DebugSourceApplicationArb;
	static const ArbDebugOutput DebugSourceOtherArb;
	static const ArbDebugOutput DebugTypeErrorArb;
	static const ArbDebugOutput DebugTypeDeprecatedBehaviorArb;
	static const ArbDebugOutput DebugTypeUndefinedBehaviorArb;
	static const ArbDebugOutput DebugTypePortabilityArb;
	static const ArbDebugOutput DebugTypePerformanceArb;
	static const ArbDebugOutput DebugTypeOtherArb;
	static const ArbDebugOutput MaxDebugMessageLengthArb;
	static const ArbDebugOutput MaxDebugLoggedMessagesArb;
	static const ArbDebugOutput DebugLoggedMessagesArb;
	static const ArbDebugOutput DebugSeverityHighArb;
	static const ArbDebugOutput DebugSeverityMediumArb;
	static const ArbDebugOutput DebugSeverityLowArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbDepthBufferFloat)
	static const ArbDepthBufferFloat DepthComponent32f;
	static const ArbDepthBufferFloat Depth32fStencil8;
	static const ArbDepthBufferFloat Float32UnsignedInt248Rev;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbDepthClamp)
	static const ArbDepthClamp DepthClamp;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbDepthTexture)
	static const ArbDepthTexture DepthComponent16Arb;
	static const ArbDepthTexture DepthComponent24Arb;
	static const ArbDepthTexture DepthComponent32Arb;
	static const ArbDepthTexture TextureDepthSizeArb;
	static const ArbDepthTexture DepthTextureModeArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbDerivativeControl)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbDirectStateAccess)
	static const ArbDirectStateAccess TextureTarget;
	static const ArbDirectStateAccess TextureBinding1D;
	static const ArbDirectStateAccess TextureBinding2D;
	static const ArbDirectStateAccess TextureBinding3D;
	static const ArbDirectStateAccess QueryTarget;
	static const ArbDirectStateAccess TextureBinding;
	static const ArbDirectStateAccess TextureBindingRectangle;
	static const ArbDirectStateAccess TextureBindingCubeMap;
	static const ArbDirectStateAccess TextureBinding1DArray;
	static const ArbDirectStateAccess TextureBinding2DArray;
	static const ArbDirectStateAccess TextureBindingBuffer;
	static const ArbDirectStateAccess TextureBindingCubeMapArray;
	static const ArbDirectStateAccess TextureBinding2DMultisample;
	static const ArbDirectStateAccess TextureBinding2DMultisampleArray;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbDrawBuffers)
	static const ArbDrawBuffers MaxDrawBuffersArb;
	static const ArbDrawBuffers DrawBuffer0Arb;
	static const ArbDrawBuffers DrawBuffer1Arb;
	static const ArbDrawBuffers DrawBuffer2Arb;
	static const ArbDrawBuffers DrawBuffer3Arb;
	static const ArbDrawBuffers DrawBuffer4Arb;
	static const ArbDrawBuffers DrawBuffer5Arb;
	static const ArbDrawBuffers DrawBuffer6Arb;
	static const ArbDrawBuffers DrawBuffer7Arb;
	static const ArbDrawBuffers DrawBuffer8Arb;
	static const ArbDrawBuffers DrawBuffer9Arb;
	static const ArbDrawBuffers DrawBuffer10Arb;
	static const ArbDrawBuffers DrawBuffer11Arb;
	static const ArbDrawBuffers DrawBuffer12Arb;
	static const ArbDrawBuffers DrawBuffer13Arb;
	static const ArbDrawBuffers DrawBuffer14Arb;
	static const ArbDrawBuffers DrawBuffer15Arb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbDrawBuffersBlend)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbDrawElementsBaseVertex)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbDrawIndirect)
	static const ArbDrawIndirect DrawIndirectBuffer;
	static const ArbDrawIndirect DrawIndirectBufferBinding;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbDrawInstanced)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbEnhancedLayouts)
	static const ArbEnhancedLayouts TransformFeedbackBuffer;
	static const ArbEnhancedLayouts LocationComponent;
	static const ArbEnhancedLayouts TransformFeedbackBufferIndex;
	static const ArbEnhancedLayouts TransformFeedbackBufferStride;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbEs2Compatibility)
	static const ArbEs2Compatibility Fixed;
	static const ArbEs2Compatibility ImplementationColorReadType;
	static const ArbEs2Compatibility ImplementationColorReadFormat;
	static const ArbEs2Compatibility Rgb565;
	static const ArbEs2Compatibility LowFloat;
	static const ArbEs2Compatibility MediumFloat;
	static const ArbEs2Compatibility HighFloat;
	static const ArbEs2Compatibility LowInt;
	static const ArbEs2Compatibility MediumInt;
	static const ArbEs2Compatibility HighInt;
	static const ArbEs2Compatibility ShaderBinaryFormats;
	static const ArbEs2Compatibility NumShaderBinaryFormats;
	static const ArbEs2Compatibility ShaderCompiler;
	static const ArbEs2Compatibility MaxVertexUniformVectors;
	static const ArbEs2Compatibility MaxVaryingVectors;
	static const ArbEs2Compatibility MaxFragmentUniformVectors;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbEs31Compatibility)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbEs3Compatibility)
	static const ArbEs3Compatibility PrimitiveRestartFixedIndex;
	static const ArbEs3Compatibility AnySamplesPassedConservative;
	static const ArbEs3Compatibility MaxElementIndex;
	static const ArbEs3Compatibility CompressedR11Eac;
	static const ArbEs3Compatibility CompressedSignedR11Eac;
	static const ArbEs3Compatibility CompressedRg11Eac;
	static const ArbEs3Compatibility CompressedSignedRg11Eac;
	static const ArbEs3Compatibility CompressedRgb8Etc2;
	static const ArbEs3Compatibility CompressedSrgb8Etc2;
	static const ArbEs3Compatibility CompressedRgb8PunchthroughAlpha1Etc2;
	static const ArbEs3Compatibility CompressedSrgb8PunchthroughAlpha1Etc2;
	static const ArbEs3Compatibility CompressedRgba8Etc2Eac;
	static const ArbEs3Compatibility CompressedSrgb8Alpha8Etc2Eac;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbExplicitAttribLocation)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbExplicitUniformLocation)
	static const ArbExplicitUniformLocation MaxUniformLocations;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbFragmentCoordConventions)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbFragmentLayerViewport)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbFragmentProgram)
	static const ArbFragmentProgram ProgramLengthArb;
	static const ArbFragmentProgram ProgramStringArb;
	static const ArbFragmentProgram MaxProgramMatrixStackDepthArb;
	static const ArbFragmentProgram MaxProgramMatricesArb;
	static const ArbFragmentProgram CurrentMatrixStackDepthArb;
	static const ArbFragmentProgram CurrentMatrixArb;
	static const ArbFragmentProgram ProgramErrorPositionArb;
	static const ArbFragmentProgram ProgramBindingArb;
	static const ArbFragmentProgram FragmentProgramArb;
	static const ArbFragmentProgram ProgramAluInstructionsArb;
	static const ArbFragmentProgram ProgramTexInstructionsArb;
	static const ArbFragmentProgram ProgramTexIndirectionsArb;
	static const ArbFragmentProgram ProgramNativeAluInstructionsArb;
	static const ArbFragmentProgram ProgramNativeTexInstructionsArb;
	static const ArbFragmentProgram ProgramNativeTexIndirectionsArb;
	static const ArbFragmentProgram MaxProgramAluInstructionsArb;
	static const ArbFragmentProgram MaxProgramTexInstructionsArb;
	static const ArbFragmentProgram MaxProgramTexIndirectionsArb;
	static const ArbFragmentProgram MaxProgramNativeAluInstructionsArb;
	static const ArbFragmentProgram MaxProgramNativeTexInstructionsArb;
	static const ArbFragmentProgram MaxProgramNativeTexIndirectionsArb;
	static const ArbFragmentProgram MaxTextureCoordsArb;
	static const ArbFragmentProgram MaxTextureImageUnitsArb;
	static const ArbFragmentProgram ProgramErrorStringArb;
	static const ArbFragmentProgram ProgramFormatAsciiArb;
	static const ArbFragmentProgram ProgramFormatArb;
	static const ArbFragmentProgram ProgramInstructionsArb;
	static const ArbFragmentProgram MaxProgramInstructionsArb;
	static const ArbFragmentProgram ProgramNativeInstructionsArb;
	static const ArbFragmentProgram MaxProgramNativeInstructionsArb;
	static const ArbFragmentProgram ProgramTemporariesArb;
	static const ArbFragmentProgram MaxProgramTemporariesArb;
	static const ArbFragmentProgram ProgramNativeTemporariesArb;
	static const ArbFragmentProgram MaxProgramNativeTemporariesArb;
	static const ArbFragmentProgram ProgramParametersArb;
	static const ArbFragmentProgram MaxProgramParametersArb;
	static const ArbFragmentProgram ProgramNativeParametersArb;
	static const ArbFragmentProgram MaxProgramNativeParametersArb;
	static const ArbFragmentProgram ProgramAttribsArb;
	static const ArbFragmentProgram MaxProgramAttribsArb;
	static const ArbFragmentProgram ProgramNativeAttribsArb;
	static const ArbFragmentProgram MaxProgramNativeAttribsArb;
	static const ArbFragmentProgram MaxProgramLocalParametersArb;
	static const ArbFragmentProgram MaxProgramEnvParametersArb;
	static const ArbFragmentProgram ProgramUnderNativeLimitsArb;
	static const ArbFragmentProgram TransposeCurrentMatrixArb;
	static const ArbFragmentProgram Matrix0Arb;
	static const ArbFragmentProgram Matrix1Arb;
	static const ArbFragmentProgram Matrix2Arb;
	static const ArbFragmentProgram Matrix3Arb;
	static const ArbFragmentProgram Matrix4Arb;
	static const ArbFragmentProgram Matrix5Arb;
	static const ArbFragmentProgram Matrix6Arb;
	static const ArbFragmentProgram Matrix7Arb;
	static const ArbFragmentProgram Matrix8Arb;
	static const ArbFragmentProgram Matrix9Arb;
	static const ArbFragmentProgram Matrix10Arb;
	static const ArbFragmentProgram Matrix11Arb;
	static const ArbFragmentProgram Matrix12Arb;
	static const ArbFragmentProgram Matrix13Arb;
	static const ArbFragmentProgram Matrix14Arb;
	static const ArbFragmentProgram Matrix15Arb;
	static const ArbFragmentProgram Matrix16Arb;
	static const ArbFragmentProgram Matrix17Arb;
	static const ArbFragmentProgram Matrix18Arb;
	static const ArbFragmentProgram Matrix19Arb;
	static const ArbFragmentProgram Matrix20Arb;
	static const ArbFragmentProgram Matrix21Arb;
	static const ArbFragmentProgram Matrix22Arb;
	static const ArbFragmentProgram Matrix23Arb;
	static const ArbFragmentProgram Matrix24Arb;
	static const ArbFragmentProgram Matrix25Arb;
	static const ArbFragmentProgram Matrix26Arb;
	static const ArbFragmentProgram Matrix27Arb;
	static const ArbFragmentProgram Matrix28Arb;
	static const ArbFragmentProgram Matrix29Arb;
	static const ArbFragmentProgram Matrix30Arb;
	static const ArbFragmentProgram Matrix31Arb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbFragmentProgramShadow)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbFragmentShader)
	static const ArbFragmentShader FragmentShaderArb;
	static const ArbFragmentShader MaxFragmentUniformComponentsArb;
	static const ArbFragmentShader FragmentShaderDerivativeHintArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbFramebufferNoAttachments)
	static const ArbFramebufferNoAttachments FramebufferDefaultWidth;
	static const ArbFramebufferNoAttachments FramebufferDefaultHeight;
	static const ArbFramebufferNoAttachments FramebufferDefaultLayers;
	static const ArbFramebufferNoAttachments FramebufferDefaultSamples;
	static const ArbFramebufferNoAttachments FramebufferDefaultFixedSampleLocations;
	static const ArbFramebufferNoAttachments MaxFramebufferWidth;
	static const ArbFramebufferNoAttachments MaxFramebufferHeight;
	static const ArbFramebufferNoAttachments MaxFramebufferLayers;
	static const ArbFramebufferNoAttachments MaxFramebufferSamples;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbFramebufferObject)
	static const ArbFramebufferObject InvalidFramebufferOperation;
	static const ArbFramebufferObject FramebufferAttachmentColorEncoding;
	static const ArbFramebufferObject FramebufferAttachmentComponentType;
	static const ArbFramebufferObject FramebufferAttachmentRedSize;
	static const ArbFramebufferObject FramebufferAttachmentGreenSize;
	static const ArbFramebufferObject FramebufferAttachmentBlueSize;
	static const ArbFramebufferObject FramebufferAttachmentAlphaSize;
	static const ArbFramebufferObject FramebufferAttachmentDepthSize;
	static const ArbFramebufferObject FramebufferAttachmentStencilSize;
	static const ArbFramebufferObject FramebufferDefault;
	static const ArbFramebufferObject FramebufferUndefined;
	static const ArbFramebufferObject DepthStencilAttachment;
	static const ArbFramebufferObject Index;
	static const ArbFramebufferObject MaxRenderbufferSize;
	static const ArbFramebufferObject DepthStencil;
	static const ArbFramebufferObject UnsignedInt248;
	static const ArbFramebufferObject Depth24Stencil8;
	static const ArbFramebufferObject TextureStencilSize;
	static const ArbFramebufferObject TextureRedType;
	static const ArbFramebufferObject TextureGreenType;
	static const ArbFramebufferObject TextureBlueType;
	static const ArbFramebufferObject TextureAlphaType;
	static const ArbFramebufferObject TextureLuminanceType;
	static const ArbFramebufferObject TextureIntensityType;
	static const ArbFramebufferObject TextureDepthType;
	static const ArbFramebufferObject UnsignedNormalized;
	static const ArbFramebufferObject DrawFramebufferBinding;
	static const ArbFramebufferObject FramebufferBinding;
	static const ArbFramebufferObject RenderbufferBinding;
	static const ArbFramebufferObject ReadFramebuffer;
	static const ArbFramebufferObject DrawFramebuffer;
	static const ArbFramebufferObject ReadFramebufferBinding;
	static const ArbFramebufferObject RenderbufferSamples;
	static const ArbFramebufferObject FramebufferAttachmentObjectType;
	static const ArbFramebufferObject FramebufferAttachmentObjectName;
	static const ArbFramebufferObject FramebufferAttachmentTextureLevel;
	static const ArbFramebufferObject FramebufferAttachmentTextureCubeMapFace;
	static const ArbFramebufferObject FramebufferAttachmentTextureLayer;
	static const ArbFramebufferObject FramebufferComplete;
	static const ArbFramebufferObject FramebufferIncompleteAttachment;
	static const ArbFramebufferObject FramebufferIncompleteMissingAttachment;
	static const ArbFramebufferObject FramebufferIncompleteDrawBuffer;
	static const ArbFramebufferObject FramebufferIncompleteReadBuffer;
	static const ArbFramebufferObject FramebufferUnsupported;
	static const ArbFramebufferObject MaxColorAttachments;
	static const ArbFramebufferObject ColorAttachment0;
	static const ArbFramebufferObject ColorAttachment1;
	static const ArbFramebufferObject ColorAttachment2;
	static const ArbFramebufferObject ColorAttachment3;
	static const ArbFramebufferObject ColorAttachment4;
	static const ArbFramebufferObject ColorAttachment5;
	static const ArbFramebufferObject ColorAttachment6;
	static const ArbFramebufferObject ColorAttachment7;
	static const ArbFramebufferObject ColorAttachment8;
	static const ArbFramebufferObject ColorAttachment9;
	static const ArbFramebufferObject ColorAttachment10;
	static const ArbFramebufferObject ColorAttachment11;
	static const ArbFramebufferObject ColorAttachment12;
	static const ArbFramebufferObject ColorAttachment13;
	static const ArbFramebufferObject ColorAttachment14;
	static const ArbFramebufferObject ColorAttachment15;
	static const ArbFramebufferObject DepthAttachment;
	static const ArbFramebufferObject StencilAttachment;
	static const ArbFramebufferObject Framebuffer;
	static const ArbFramebufferObject Renderbuffer;
	static const ArbFramebufferObject RenderbufferWidth;
	static const ArbFramebufferObject RenderbufferHeight;
	static const ArbFramebufferObject RenderbufferInternalFormat;
	static const ArbFramebufferObject StencilIndex1;
	static const ArbFramebufferObject StencilIndex4;
	static const ArbFramebufferObject StencilIndex8;
	static const ArbFramebufferObject StencilIndex16;
	static const ArbFramebufferObject RenderbufferRedSize;
	static const ArbFramebufferObject RenderbufferGreenSize;
	static const ArbFramebufferObject RenderbufferBlueSize;
	static const ArbFramebufferObject RenderbufferAlphaSize;
	static const ArbFramebufferObject RenderbufferDepthSize;
	static const ArbFramebufferObject RenderbufferStencilSize;
	static const ArbFramebufferObject FramebufferIncompleteMultisample;
	static const ArbFramebufferObject MaxSamples;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbFramebufferSrgb)
	static const ArbFramebufferSrgb FramebufferSrgb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbGeometryShader4)
	static const ArbGeometryShader4 LinesAdjacencyArb;
	static const ArbGeometryShader4 LineStripAdjacencyArb;
	static const ArbGeometryShader4 TrianglesAdjacencyArb;
	static const ArbGeometryShader4 TriangleStripAdjacencyArb;
	static const ArbGeometryShader4 ProgramPointSizeArb;
	static const ArbGeometryShader4 MaxVaryingComponents;
	static const ArbGeometryShader4 MaxGeometryTextureImageUnitsArb;
	static const ArbGeometryShader4 FramebufferAttachmentTextureLayer;
	static const ArbGeometryShader4 FramebufferAttachmentLayeredArb;
	static const ArbGeometryShader4 FramebufferIncompleteLayerTargetsArb;
	static const ArbGeometryShader4 FramebufferIncompleteLayerCountArb;
	static const ArbGeometryShader4 GeometryShaderArb;
	static const ArbGeometryShader4 GeometryVerticesOutArb;
	static const ArbGeometryShader4 GeometryInputTypeArb;
	static const ArbGeometryShader4 GeometryOutputTypeArb;
	static const ArbGeometryShader4 MaxGeometryVaryingComponentsArb;
	static const ArbGeometryShader4 MaxVertexVaryingComponentsArb;
	static const ArbGeometryShader4 MaxGeometryUniformComponentsArb;
	static const ArbGeometryShader4 MaxGeometryOutputVerticesArb;
	static const ArbGeometryShader4 MaxGeometryTotalOutputComponentsArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbGetProgramBinary)
	static const ArbGetProgramBinary ProgramBinaryRetrievableHint;
	static const ArbGetProgramBinary ProgramBinaryLength;
	static const ArbGetProgramBinary NumProgramBinaryFormats;
	static const ArbGetProgramBinary ProgramBinaryFormats;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbGetTextureSubImage)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbGpuShader5)
	static const ArbGpuShader5 GeometryShaderInvocations;
	static const ArbGpuShader5 MaxGeometryShaderInvocations;
	static const ArbGpuShader5 MinFragmentInterpolationOffset;
	static const ArbGpuShader5 MaxFragmentInterpolationOffset;
	static const ArbGpuShader5 FragmentInterpolationOffsetBits;
	static const ArbGpuShader5 MaxVertexStreams;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbGpuShaderFp64)
	static const ArbGpuShaderFp64 Double;
	static const ArbGpuShaderFp64 DoubleMat2;
	static const ArbGpuShaderFp64 DoubleMat3;
	static const ArbGpuShaderFp64 DoubleMat4;
	static const ArbGpuShaderFp64 DoubleMat2x3;
	static const ArbGpuShaderFp64 DoubleMat2x4;
	static const ArbGpuShaderFp64 DoubleMat3x2;
	static const ArbGpuShaderFp64 DoubleMat3x4;
	static const ArbGpuShaderFp64 DoubleMat4x2;
	static const ArbGpuShaderFp64 DoubleMat4x3;
	static const ArbGpuShaderFp64 DoubleVec2;
	static const ArbGpuShaderFp64 DoubleVec3;
	static const ArbGpuShaderFp64 DoubleVec4;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbHalfFloatPixel)
	static const ArbHalfFloatPixel HalfFloatArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbHalfFloatVertex)
	static const ArbHalfFloatVertex HalfFloat;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbImaging)
	static const ArbImaging ConstantColor;
	static const ArbImaging OneMinusConstantColor;
	static const ArbImaging ConstantAlpha;
	static const ArbImaging OneMinusConstantAlpha;
	static const ArbImaging BlendColor;
	static const ArbImaging FuncAdd;
	static const ArbImaging Min;
	static const ArbImaging Max;
	static const ArbImaging BlendEquation;
	static const ArbImaging FuncSubtract;
	static const ArbImaging FuncReverseSubtract;
	static const ArbImaging Convolution1D;
	static const ArbImaging Convolution2D;
	static const ArbImaging Separable2D;
	static const ArbImaging ConvolutionBorderMode;
	static const ArbImaging ConvolutionFilterScale;
	static const ArbImaging ConvolutionFilterBias;
	static const ArbImaging Reduce;
	static const ArbImaging ConvolutionFormat;
	static const ArbImaging ConvolutionWidth;
	static const ArbImaging ConvolutionHeight;
	static const ArbImaging MaxConvolutionWidth;
	static const ArbImaging MaxConvolutionHeight;
	static const ArbImaging PostConvolutionRedScale;
	static const ArbImaging PostConvolutionGreenScale;
	static const ArbImaging PostConvolutionBlueScale;
	static const ArbImaging PostConvolutionAlphaScale;
	static const ArbImaging PostConvolutionRedBias;
	static const ArbImaging PostConvolutionGreenBias;
	static const ArbImaging PostConvolutionBlueBias;
	static const ArbImaging PostConvolutionAlphaBias;
	static const ArbImaging Histogram;
	static const ArbImaging ProxyHistogram;
	static const ArbImaging HistogramWidth;
	static const ArbImaging HistogramFormat;
	static const ArbImaging HistogramRedSize;
	static const ArbImaging HistogramGreenSize;
	static const ArbImaging HistogramBlueSize;
	static const ArbImaging HistogramAlphaSize;
	static const ArbImaging HistogramLuminanceSize;
	static const ArbImaging HistogramSink;
	static const ArbImaging Minmax;
	static const ArbImaging MinmaxFormat;
	static const ArbImaging MinmaxSink;
	static const ArbImaging TableTooLarge;
	static const ArbImaging ColorMatrix;
	static const ArbImaging ColorMatrixStackDepth;
	static const ArbImaging MaxColorMatrixStackDepth;
	static const ArbImaging PostColorMatrixRedScale;
	static const ArbImaging PostColorMatrixGreenScale;
	static const ArbImaging PostColorMatrixBlueScale;
	static const ArbImaging PostColorMatrixAlphaScale;
	static const ArbImaging PostColorMatrixRedBias;
	static const ArbImaging PostColorMatrixGreenBias;
	static const ArbImaging PostColorMatrixBlueBias;
	static const ArbImaging PostColorMatrixAlphaBias;
	static const ArbImaging ColorTable;
	static const ArbImaging PostConvolutionColorTable;
	static const ArbImaging PostColorMatrixColorTable;
	static const ArbImaging ProxyColorTable;
	static const ArbImaging ProxyPostConvolutionColorTable;
	static const ArbImaging ProxyPostColorMatrixColorTable;
	static const ArbImaging ColorTableScale;
	static const ArbImaging ColorTableBias;
	static const ArbImaging ColorTableFormat;
	static const ArbImaging ColorTableWidth;
	static const ArbImaging ColorTableRedSize;
	static const ArbImaging ColorTableGreenSize;
	static const ArbImaging ColorTableBlueSize;
	static const ArbImaging ColorTableAlphaSize;
	static const ArbImaging ColorTableLuminanceSize;
	static const ArbImaging ColorTableIntensitySize;
	static const ArbImaging ConstantBorder;
	static const ArbImaging ReplicateBorder;
	static const ArbImaging ConvolutionBorderColor;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbIndirectParameters)
	static const ArbIndirectParameters ParameterBufferArb;
	static const ArbIndirectParameters ParameterBufferBindingArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbInstancedArrays)
	static const ArbInstancedArrays VertexAttribArrayDivisorArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbInternalformatQuery)
	static const ArbInternalformatQuery NumSampleCounts;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbInternalformatQuery2)
	static const ArbInternalformatQuery2 Texture1D;
	static const ArbInternalformatQuery2 Texture2D;
	static const ArbInternalformatQuery2 Texture3D;
	static const ArbInternalformatQuery2 Samples;
	static const ArbInternalformatQuery2 InternalformatSupported;
	static const ArbInternalformatQuery2 InternalformatPreferred;
	static const ArbInternalformatQuery2 InternalformatRedSize;
	static const ArbInternalformatQuery2 InternalformatGreenSize;
	static const ArbInternalformatQuery2 InternalformatBlueSize;
	static const ArbInternalformatQuery2 InternalformatAlphaSize;
	static const ArbInternalformatQuery2 InternalformatDepthSize;
	static const ArbInternalformatQuery2 InternalformatStencilSize;
	static const ArbInternalformatQuery2 InternalformatSharedSize;
	static const ArbInternalformatQuery2 InternalformatRedType;
	static const ArbInternalformatQuery2 InternalformatGreenType;
	static const ArbInternalformatQuery2 InternalformatBlueType;
	static const ArbInternalformatQuery2 InternalformatAlphaType;
	static const ArbInternalformatQuery2 InternalformatDepthType;
	static const ArbInternalformatQuery2 InternalformatStencilType;
	static const ArbInternalformatQuery2 MaxWidth;
	static const ArbInternalformatQuery2 MaxHeight;
	static const ArbInternalformatQuery2 MaxDepth;
	static const ArbInternalformatQuery2 MaxLayers;
	static const ArbInternalformatQuery2 MaxCombinedDimensions;
	static const ArbInternalformatQuery2 ColorComponents;
	static const ArbInternalformatQuery2 DepthComponents;
	static const ArbInternalformatQuery2 StencilComponents;
	static const ArbInternalformatQuery2 ColorRenderable;
	static const ArbInternalformatQuery2 DepthRenderable;
	static const ArbInternalformatQuery2 StencilRenderable;
	static const ArbInternalformatQuery2 FramebufferRenderable;
	static const ArbInternalformatQuery2 FramebufferRenderableLayered;
	static const ArbInternalformatQuery2 FramebufferBlend;
	static const ArbInternalformatQuery2 ReadPixels;
	static const ArbInternalformatQuery2 ReadPixelsFormat;
	static const ArbInternalformatQuery2 ReadPixelsType;
	static const ArbInternalformatQuery2 TextureImageFormat;
	static const ArbInternalformatQuery2 TextureImageType;
	static const ArbInternalformatQuery2 GetTextureImageFormat;
	static const ArbInternalformatQuery2 GetTextureImageType;
	static const ArbInternalformatQuery2 Mipmap;
	static const ArbInternalformatQuery2 ManualGenerateMipmap;
	static const ArbInternalformatQuery2 AutoGenerateMipmap;
	static const ArbInternalformatQuery2 ColorEncoding;
	static const ArbInternalformatQuery2 SrgbRead;
	static const ArbInternalformatQuery2 SrgbWrite;
	static const ArbInternalformatQuery2 SrgbDecodeArb;
	static const ArbInternalformatQuery2 Filter;
	static const ArbInternalformatQuery2 VertexTexture;
	static const ArbInternalformatQuery2 TessControlTexture;
	static const ArbInternalformatQuery2 TessEvaluationTexture;
	static const ArbInternalformatQuery2 GeometryTexture;
	static const ArbInternalformatQuery2 FragmentTexture;
	static const ArbInternalformatQuery2 ComputeTexture;
	static const ArbInternalformatQuery2 TextureShadow;
	static const ArbInternalformatQuery2 TextureGather;
	static const ArbInternalformatQuery2 TextureGatherShadow;
	static const ArbInternalformatQuery2 ShaderImageLoad;
	static const ArbInternalformatQuery2 ShaderImageStore;
	static const ArbInternalformatQuery2 ShaderImageAtomic;
	static const ArbInternalformatQuery2 ImageTexelSize;
	static const ArbInternalformatQuery2 ImageCompatibilityClass;
	static const ArbInternalformatQuery2 ImagePixelFormat;
	static const ArbInternalformatQuery2 ImagePixelType;
	static const ArbInternalformatQuery2 SimultaneousTextureAndDepthTest;
	static const ArbInternalformatQuery2 SimultaneousTextureAndStencilTest;
	static const ArbInternalformatQuery2 SimultaneousTextureAndDepthWrite;
	static const ArbInternalformatQuery2 SimultaneousTextureAndStencilWrite;
	static const ArbInternalformatQuery2 TextureCompressedBlockWidth;
	static const ArbInternalformatQuery2 TextureCompressedBlockHeight;
	static const ArbInternalformatQuery2 TextureCompressedBlockSize;
	static const ArbInternalformatQuery2 ClearBuffer;
	static const ArbInternalformatQuery2 TextureView;
	static const ArbInternalformatQuery2 ViewCompatibilityClass;
	static const ArbInternalformatQuery2 FullSupport;
	static const ArbInternalformatQuery2 CaveatSupport;
	static const ArbInternalformatQuery2 ImageClass4X32;
	static const ArbInternalformatQuery2 ImageClass2X32;
	static const ArbInternalformatQuery2 ImageClass1X32;
	static const ArbInternalformatQuery2 ImageClass4X16;
	static const ArbInternalformatQuery2 ImageClass2X16;
	static const ArbInternalformatQuery2 ImageClass1X16;
	static const ArbInternalformatQuery2 ImageClass4X8;
	static const ArbInternalformatQuery2 ImageClass2X8;
	static const ArbInternalformatQuery2 ImageClass1X8;
	static const ArbInternalformatQuery2 ImageClass111110;
	static const ArbInternalformatQuery2 ImageClass1010102;
	static const ArbInternalformatQuery2 ViewClass128Bits;
	static const ArbInternalformatQuery2 ViewClass96Bits;
	static const ArbInternalformatQuery2 ViewClass64Bits;
	static const ArbInternalformatQuery2 ViewClass48Bits;
	static const ArbInternalformatQuery2 ViewClass32Bits;
	static const ArbInternalformatQuery2 ViewClass24Bits;
	static const ArbInternalformatQuery2 ViewClass16Bits;
	static const ArbInternalformatQuery2 ViewClass8Bits;
	static const ArbInternalformatQuery2 ViewClassS3tcDxt1Rgb;
	static const ArbInternalformatQuery2 ViewClassS3tcDxt1Rgba;
	static const ArbInternalformatQuery2 ViewClassS3tcDxt3Rgba;
	static const ArbInternalformatQuery2 ViewClassS3tcDxt5Rgba;
	static const ArbInternalformatQuery2 ViewClassRgtc1Red;
	static const ArbInternalformatQuery2 ViewClassRgtc2Rg;
	static const ArbInternalformatQuery2 ViewClassBptcUnorm;
	static const ArbInternalformatQuery2 ViewClassBptcFloat;
	static const ArbInternalformatQuery2 TextureRectangle;
	static const ArbInternalformatQuery2 TextureCubeMap;
	static const ArbInternalformatQuery2 TextureCompressed;
	static const ArbInternalformatQuery2 Texture1DArray;
	static const ArbInternalformatQuery2 Texture2DArray;
	static const ArbInternalformatQuery2 TextureBuffer;
	static const ArbInternalformatQuery2 Renderbuffer;
	static const ArbInternalformatQuery2 TextureCubeMapArray;
	static const ArbInternalformatQuery2 ImageFormatCompatibilityType;
	static const ArbInternalformatQuery2 Texture2DMultisample;
	static const ArbInternalformatQuery2 Texture2DMultisampleArray;
	static const ArbInternalformatQuery2 NumSampleCounts;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbInvalidateSubdata)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbMapBufferAlignment)
	static const ArbMapBufferAlignment MinMapBufferAlignment;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbMapBufferRange)
	static const ArbMapBufferRange MapReadBit;
	static const ArbMapBufferRange MapWriteBit;
	static const ArbMapBufferRange MapInvalidateRangeBit;
	static const ArbMapBufferRange MapInvalidateBufferBit;
	static const ArbMapBufferRange MapFlushExplicitBit;
	static const ArbMapBufferRange MapUnsynchronizedBit;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbMatrixPalette)
	static const ArbMatrixPalette MatrixPaletteArb;
	static const ArbMatrixPalette MaxMatrixPaletteStackDepthArb;
	static const ArbMatrixPalette MaxPaletteMatricesArb;
	static const ArbMatrixPalette CurrentPaletteMatrixArb;
	static const ArbMatrixPalette MatrixIndexArrayArb;
	static const ArbMatrixPalette CurrentMatrixIndexArb;
	static const ArbMatrixPalette MatrixIndexArraySizeArb;
	static const ArbMatrixPalette MatrixIndexArrayTypeArb;
	static const ArbMatrixPalette MatrixIndexArrayStrideArb;
	static const ArbMatrixPalette MatrixIndexArrayPointerArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbMultiBind)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbMultiDrawIndirect)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbMultisample)
	static const ArbMultisample MultisampleBitArb;
	static const ArbMultisample MultisampleArb;
	static const ArbMultisample SampleAlphaToCoverageArb;
	static const ArbMultisample SampleAlphaToOneArb;
	static const ArbMultisample SampleCoverageArb;
	static const ArbMultisample SampleBuffersArb;
	static const ArbMultisample SamplesArb;
	static const ArbMultisample SampleCoverageValueArb;
	static const ArbMultisample SampleCoverageInvertArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbMultitexture)
	static const ArbMultitexture Texture0Arb;
	static const ArbMultitexture Texture1Arb;
	static const ArbMultitexture Texture2Arb;
	static const ArbMultitexture Texture3Arb;
	static const ArbMultitexture Texture4Arb;
	static const ArbMultitexture Texture5Arb;
	static const ArbMultitexture Texture6Arb;
	static const ArbMultitexture Texture7Arb;
	static const ArbMultitexture Texture8Arb;
	static const ArbMultitexture Texture9Arb;
	static const ArbMultitexture Texture10Arb;
	static const ArbMultitexture Texture11Arb;
	static const ArbMultitexture Texture12Arb;
	static const ArbMultitexture Texture13Arb;
	static const ArbMultitexture Texture14Arb;
	static const ArbMultitexture Texture15Arb;
	static const ArbMultitexture Texture16Arb;
	static const ArbMultitexture Texture17Arb;
	static const ArbMultitexture Texture18Arb;
	static const ArbMultitexture Texture19Arb;
	static const ArbMultitexture Texture20Arb;
	static const ArbMultitexture Texture21Arb;
	static const ArbMultitexture Texture22Arb;
	static const ArbMultitexture Texture23Arb;
	static const ArbMultitexture Texture24Arb;
	static const ArbMultitexture Texture25Arb;
	static const ArbMultitexture Texture26Arb;
	static const ArbMultitexture Texture27Arb;
	static const ArbMultitexture Texture28Arb;
	static const ArbMultitexture Texture29Arb;
	static const ArbMultitexture Texture30Arb;
	static const ArbMultitexture Texture31Arb;
	static const ArbMultitexture ActiveTextureArb;
	static const ArbMultitexture ClientActiveTextureArb;
	static const ArbMultitexture MaxTextureUnitsArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbOcclusionQuery)
	static const ArbOcclusionQuery QueryCounterBitsArb;
	static const ArbOcclusionQuery CurrentQueryArb;
	static const ArbOcclusionQuery QueryResultArb;
	static const ArbOcclusionQuery QueryResultAvailableArb;
	static const ArbOcclusionQuery SamplesPassedArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbOcclusionQuery2)
	static const ArbOcclusionQuery2 AnySamplesPassed;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbPipelineStatisticsQuery)
	static const ArbPipelineStatisticsQuery VerticesSubmittedArb;
	static const ArbPipelineStatisticsQuery PrimitivesSubmittedArb;
	static const ArbPipelineStatisticsQuery VertexShaderInvocationsArb;
	static const ArbPipelineStatisticsQuery TessControlShaderPatchesArb;
	static const ArbPipelineStatisticsQuery TessEvaluationShaderInvocationsArb;
	static const ArbPipelineStatisticsQuery GeometryShaderPrimitivesEmittedArb;
	static const ArbPipelineStatisticsQuery FragmentShaderInvocationsArb;
	static const ArbPipelineStatisticsQuery ComputeShaderInvocationsArb;
	static const ArbPipelineStatisticsQuery ClippingInputPrimitivesArb;
	static const ArbPipelineStatisticsQuery ClippingOutputPrimitivesArb;
	static const ArbPipelineStatisticsQuery GeometryShaderInvocations;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbPixelBufferObject)
	static const ArbPixelBufferObject PixelPackBufferArb;
	static const ArbPixelBufferObject PixelUnpackBufferArb;
	static const ArbPixelBufferObject PixelPackBufferBindingArb;
	static const ArbPixelBufferObject PixelUnpackBufferBindingArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbPointParameters)
	static const ArbPointParameters PointSizeMinArb;
	static const ArbPointParameters PointSizeMaxArb;
	static const ArbPointParameters PointFadeThresholdSizeArb;
	static const ArbPointParameters PointDistanceAttenuationArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbPointSprite)
	static const ArbPointSprite PointSpriteArb;
	static const ArbPointSprite CoordReplaceArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbProgramInterfaceQuery)
	static const ArbProgramInterfaceQuery NumCompatibleSubroutines;
	static const ArbProgramInterfaceQuery CompatibleSubroutines;
	static const ArbProgramInterfaceQuery AtomicCounterBuffer;
	static const ArbProgramInterfaceQuery Uniform;
	static const ArbProgramInterfaceQuery UniformBlock;
	static const ArbProgramInterfaceQuery ProgramInput;
	static const ArbProgramInterfaceQuery ProgramOutput;
	static const ArbProgramInterfaceQuery BufferVariable;
	static const ArbProgramInterfaceQuery ShaderStorageBlock;
	static const ArbProgramInterfaceQuery IsPerPatch;
	static const ArbProgramInterfaceQuery VertexSubroutine;
	static const ArbProgramInterfaceQuery TessControlSubroutine;
	static const ArbProgramInterfaceQuery TessEvaluationSubroutine;
	static const ArbProgramInterfaceQuery GeometrySubroutine;
	static const ArbProgramInterfaceQuery FragmentSubroutine;
	static const ArbProgramInterfaceQuery ComputeSubroutine;
	static const ArbProgramInterfaceQuery VertexSubroutineUniform;
	static const ArbProgramInterfaceQuery TessControlSubroutineUniform;
	static const ArbProgramInterfaceQuery TessEvaluationSubroutineUniform;
	static const ArbProgramInterfaceQuery GeometrySubroutineUniform;
	static const ArbProgramInterfaceQuery FragmentSubroutineUniform;
	static const ArbProgramInterfaceQuery ComputeSubroutineUniform;
	static const ArbProgramInterfaceQuery TransformFeedbackVarying;
	static const ArbProgramInterfaceQuery ActiveResources;
	static const ArbProgramInterfaceQuery MaxNameLength;
	static const ArbProgramInterfaceQuery MaxNumActiveVariables;
	static const ArbProgramInterfaceQuery MaxNumCompatibleSubroutines;
	static const ArbProgramInterfaceQuery NameLength;
	static const ArbProgramInterfaceQuery Type;
	static const ArbProgramInterfaceQuery ArraySize;
	static const ArbProgramInterfaceQuery Offset;
	static const ArbProgramInterfaceQuery BlockIndex;
	static const ArbProgramInterfaceQuery ArrayStride;
	static const ArbProgramInterfaceQuery MatrixStride;
	static const ArbProgramInterfaceQuery IsRowMajor;
	static const ArbProgramInterfaceQuery AtomicCounterBufferIndex;
	static const ArbProgramInterfaceQuery BufferBinding;
	static const ArbProgramInterfaceQuery BufferDataSize;
	static const ArbProgramInterfaceQuery NumActiveVariables;
	static const ArbProgramInterfaceQuery ActiveVariables;
	static const ArbProgramInterfaceQuery ReferencedByVertexShader;
	static const ArbProgramInterfaceQuery ReferencedByTessControlShader;
	static const ArbProgramInterfaceQuery ReferencedByTessEvaluationShader;
	static const ArbProgramInterfaceQuery ReferencedByGeometryShader;
	static const ArbProgramInterfaceQuery ReferencedByFragmentShader;
	static const ArbProgramInterfaceQuery ReferencedByComputeShader;
	static const ArbProgramInterfaceQuery TopLevelArraySize;
	static const ArbProgramInterfaceQuery TopLevelArrayStride;
	static const ArbProgramInterfaceQuery Location;
	static const ArbProgramInterfaceQuery LocationIndex;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbProvokingVertex)
	static const ArbProvokingVertex QuadsFollowProvokingVertexConvention;
	static const ArbProvokingVertex FirstVertexConvention;
	static const ArbProvokingVertex LastVertexConvention;
	static const ArbProvokingVertex ProvokingVertex;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbQueryBufferObject)
	static const ArbQueryBufferObject QueryBufferBarrierBit;
	static const ArbQueryBufferObject QueryBuffer;
	static const ArbQueryBufferObject QueryBufferBinding;
	static const ArbQueryBufferObject QueryResultNoWait;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbRobustBufferAccessBehavior)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbRobustness)
	static const ArbRobustness NoError;
	static const ArbRobustness ContextFlagRobustAccessBitArb;
	static const ArbRobustness LoseContextOnResetArb;
	static const ArbRobustness GuiltyContextResetArb;
	static const ArbRobustness InnocentContextResetArb;
	static const ArbRobustness UnknownContextResetArb;
	static const ArbRobustness ResetNotificationStrategyArb;
	static const ArbRobustness NoResetNotificationArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbRobustnessIsolation)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbSamplerObjects)
	static const ArbSamplerObjects SamplerBinding;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbSampleShading)
	static const ArbSampleShading SampleShadingArb;
	static const ArbSampleShading MinSampleShadingValueArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbSeamlessCubeMap)
	static const ArbSeamlessCubeMap TextureCubeMapSeamless;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbSeamlessCubemapPerTexture)
	static const ArbSeamlessCubemapPerTexture TextureCubeMapSeamless;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbSeparateShaderObjects)
	static const ArbSeparateShaderObjects VertexShaderBit;
	static const ArbSeparateShaderObjects FragmentShaderBit;
	static const ArbSeparateShaderObjects GeometryShaderBit;
	static const ArbSeparateShaderObjects TessControlShaderBit;
	static const ArbSeparateShaderObjects TessEvaluationShaderBit;
	static const ArbSeparateShaderObjects ProgramSeparable;
	static const ArbSeparateShaderObjects ActiveProgram;
	static const ArbSeparateShaderObjects ProgramPipelineBinding;
	static const ArbSeparateShaderObjects AllShaderBits;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderAtomicCounters)
	static const ArbShaderAtomicCounters AtomicCounterBuffer;
	static const ArbShaderAtomicCounters AtomicCounterBufferBinding;
	static const ArbShaderAtomicCounters AtomicCounterBufferStart;
	static const ArbShaderAtomicCounters AtomicCounterBufferSize;
	static const ArbShaderAtomicCounters AtomicCounterBufferDataSize;
	static const ArbShaderAtomicCounters AtomicCounterBufferActiveAtomicCounters;
	static const ArbShaderAtomicCounters AtomicCounterBufferActiveAtomicCounterIndices;
	static const ArbShaderAtomicCounters AtomicCounterBufferReferencedByVertexShader;
	static const ArbShaderAtomicCounters AtomicCounterBufferReferencedByTessControlShader;
	static const ArbShaderAtomicCounters AtomicCounterBufferReferencedByTessEvaluationShader;
	static const ArbShaderAtomicCounters AtomicCounterBufferReferencedByGeometryShader;
	static const ArbShaderAtomicCounters AtomicCounterBufferReferencedByFragmentShader;
	static const ArbShaderAtomicCounters MaxVertexAtomicCounterBuffers;
	static const ArbShaderAtomicCounters MaxTessControlAtomicCounterBuffers;
	static const ArbShaderAtomicCounters MaxTessEvaluationAtomicCounterBuffers;
	static const ArbShaderAtomicCounters MaxGeometryAtomicCounterBuffers;
	static const ArbShaderAtomicCounters MaxFragmentAtomicCounterBuffers;
	static const ArbShaderAtomicCounters MaxCombinedAtomicCounterBuffers;
	static const ArbShaderAtomicCounters MaxVertexAtomicCounters;
	static const ArbShaderAtomicCounters MaxTessControlAtomicCounters;
	static const ArbShaderAtomicCounters MaxTessEvaluationAtomicCounters;
	static const ArbShaderAtomicCounters MaxGeometryAtomicCounters;
	static const ArbShaderAtomicCounters MaxFragmentAtomicCounters;
	static const ArbShaderAtomicCounters MaxCombinedAtomicCounters;
	static const ArbShaderAtomicCounters MaxAtomicCounterBufferSize;
	static const ArbShaderAtomicCounters ActiveAtomicCounterBuffers;
	static const ArbShaderAtomicCounters UniformAtomicCounterBufferIndex;
	static const ArbShaderAtomicCounters UnsignedIntAtomicCounter;
	static const ArbShaderAtomicCounters MaxAtomicCounterBufferBindings;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderBitEncoding)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderDrawParameters)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderGroupVote)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderImageLoadStore)
	static const ArbShaderImageLoadStore VertexAttribArrayBarrierBit;
	static const ArbShaderImageLoadStore ElementArrayBarrierBit;
	static const ArbShaderImageLoadStore UniformBarrierBit;
	static const ArbShaderImageLoadStore TextureFetchBarrierBit;
	static const ArbShaderImageLoadStore ShaderImageAccessBarrierBit;
	static const ArbShaderImageLoadStore CommandBarrierBit;
	static const ArbShaderImageLoadStore PixelBufferBarrierBit;
	static const ArbShaderImageLoadStore TextureUpdateBarrierBit;
	static const ArbShaderImageLoadStore BufferUpdateBarrierBit;
	static const ArbShaderImageLoadStore FramebufferBarrierBit;
	static const ArbShaderImageLoadStore TransformFeedbackBarrierBit;
	static const ArbShaderImageLoadStore AtomicCounterBarrierBit;
	static const ArbShaderImageLoadStore MaxImageUnits;
	static const ArbShaderImageLoadStore MaxCombinedImageUnitsAndFragmentOutputs;
	static const ArbShaderImageLoadStore ImageBindingName;
	static const ArbShaderImageLoadStore ImageBindingLevel;
	static const ArbShaderImageLoadStore ImageBindingLayered;
	static const ArbShaderImageLoadStore ImageBindingLayer;
	static const ArbShaderImageLoadStore ImageBindingAccess;
	static const ArbShaderImageLoadStore Image1D;
	static const ArbShaderImageLoadStore Image2D;
	static const ArbShaderImageLoadStore Image3D;
	static const ArbShaderImageLoadStore Image2DRect;
	static const ArbShaderImageLoadStore ImageCube;
	static const ArbShaderImageLoadStore ImageBuffer;
	static const ArbShaderImageLoadStore Image1DArray;
	static const ArbShaderImageLoadStore Image2DArray;
	static const ArbShaderImageLoadStore ImageCubeMapArray;
	static const ArbShaderImageLoadStore Image2DMultisample;
	static const ArbShaderImageLoadStore Image2DMultisampleArray;
	static const ArbShaderImageLoadStore IntImage1D;
	static const ArbShaderImageLoadStore IntImage2D;
	static const ArbShaderImageLoadStore IntImage3D;
	static const ArbShaderImageLoadStore IntImage2DRect;
	static const ArbShaderImageLoadStore IntImageCube;
	static const ArbShaderImageLoadStore IntImageBuffer;
	static const ArbShaderImageLoadStore IntImage1DArray;
	static const ArbShaderImageLoadStore IntImage2DArray;
	static const ArbShaderImageLoadStore IntImageCubeMapArray;
	static const ArbShaderImageLoadStore IntImage2DMultisample;
	static const ArbShaderImageLoadStore IntImage2DMultisampleArray;
	static const ArbShaderImageLoadStore UnsignedIntImage1D;
	static const ArbShaderImageLoadStore UnsignedIntImage2D;
	static const ArbShaderImageLoadStore UnsignedIntImage3D;
	static const ArbShaderImageLoadStore UnsignedIntImage2DRect;
	static const ArbShaderImageLoadStore UnsignedIntImageCube;
	static const ArbShaderImageLoadStore UnsignedIntImageBuffer;
	static const ArbShaderImageLoadStore UnsignedIntImage1DArray;
	static const ArbShaderImageLoadStore UnsignedIntImage2DArray;
	static const ArbShaderImageLoadStore UnsignedIntImageCubeMapArray;
	static const ArbShaderImageLoadStore UnsignedIntImage2DMultisample;
	static const ArbShaderImageLoadStore UnsignedIntImage2DMultisampleArray;
	static const ArbShaderImageLoadStore MaxImageSamples;
	static const ArbShaderImageLoadStore ImageBindingFormat;
	static const ArbShaderImageLoadStore ImageFormatCompatibilityType;
	static const ArbShaderImageLoadStore ImageFormatCompatibilityBySize;
	static const ArbShaderImageLoadStore ImageFormatCompatibilityByClass;
	static const ArbShaderImageLoadStore MaxVertexImageUniforms;
	static const ArbShaderImageLoadStore MaxTessControlImageUniforms;
	static const ArbShaderImageLoadStore MaxTessEvaluationImageUniforms;
	static const ArbShaderImageLoadStore MaxGeometryImageUniforms;
	static const ArbShaderImageLoadStore MaxFragmentImageUniforms;
	static const ArbShaderImageLoadStore MaxCombinedImageUniforms;
	static const ArbShaderImageLoadStore AllBarrierBits;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderImageSize)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderObjects)
	static const ArbShaderObjects ProgramObjectArb;
	static const ArbShaderObjects ShaderObjectArb;
	static const ArbShaderObjects ObjectTypeArb;
	static const ArbShaderObjects ObjectSubtypeArb;
	static const ArbShaderObjects FloatVec2Arb;
	static const ArbShaderObjects FloatVec3Arb;
	static const ArbShaderObjects FloatVec4Arb;
	static const ArbShaderObjects IntVec2Arb;
	static const ArbShaderObjects IntVec3Arb;
	static const ArbShaderObjects IntVec4Arb;
	static const ArbShaderObjects BoolArb;
	static const ArbShaderObjects BoolVec2Arb;
	static const ArbShaderObjects BoolVec3Arb;
	static const ArbShaderObjects BoolVec4Arb;
	static const ArbShaderObjects FloatMat2Arb;
	static const ArbShaderObjects FloatMat3Arb;
	static const ArbShaderObjects FloatMat4Arb;
	static const ArbShaderObjects Sampler1DArb;
	static const ArbShaderObjects Sampler2DArb;
	static const ArbShaderObjects Sampler3DArb;
	static const ArbShaderObjects SamplerCubeArb;
	static const ArbShaderObjects Sampler1DShadowArb;
	static const ArbShaderObjects Sampler2DShadowArb;
	static const ArbShaderObjects Sampler2DRectArb;
	static const ArbShaderObjects Sampler2DRectShadowArb;
	static const ArbShaderObjects ObjectDeleteStatusArb;
	static const ArbShaderObjects ObjectCompileStatusArb;
	static const ArbShaderObjects ObjectLinkStatusArb;
	static const ArbShaderObjects ObjectValidateStatusArb;
	static const ArbShaderObjects ObjectInfoLogLengthArb;
	static const ArbShaderObjects ObjectAttachedObjectsArb;
	static const ArbShaderObjects ObjectActiveUniformsArb;
	static const ArbShaderObjects ObjectActiveUniformMaxLengthArb;
	static const ArbShaderObjects ObjectShaderSourceLengthArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderPrecision)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderStencilExport)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderStorageBufferObject)
	static const ArbShaderStorageBufferObject ShaderStorageBarrierBit;
	static const ArbShaderStorageBufferObject MaxCombinedImageUnitsAndFragmentOutputs;
	static const ArbShaderStorageBufferObject MaxCombinedShaderOutputResources;
	static const ArbShaderStorageBufferObject ShaderStorageBuffer;
	static const ArbShaderStorageBufferObject ShaderStorageBufferBinding;
	static const ArbShaderStorageBufferObject ShaderStorageBufferStart;
	static const ArbShaderStorageBufferObject ShaderStorageBufferSize;
	static const ArbShaderStorageBufferObject MaxVertexShaderStorageBlocks;
	static const ArbShaderStorageBufferObject MaxGeometryShaderStorageBlocks;
	static const ArbShaderStorageBufferObject MaxTessControlShaderStorageBlocks;
	static const ArbShaderStorageBufferObject MaxTessEvaluationShaderStorageBlocks;
	static const ArbShaderStorageBufferObject MaxFragmentShaderStorageBlocks;
	static const ArbShaderStorageBufferObject MaxComputeShaderStorageBlocks;
	static const ArbShaderStorageBufferObject MaxCombinedShaderStorageBlocks;
	static const ArbShaderStorageBufferObject MaxShaderStorageBufferBindings;
	static const ArbShaderStorageBufferObject MaxShaderStorageBlockSize;
	static const ArbShaderStorageBufferObject ShaderStorageBufferOffsetAlignment;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderSubroutine)
	static const ArbShaderSubroutine UniformSize;
	static const ArbShaderSubroutine UniformNameLength;
	static const ArbShaderSubroutine ActiveSubroutines;
	static const ArbShaderSubroutine ActiveSubroutineUniforms;
	static const ArbShaderSubroutine MaxSubroutines;
	static const ArbShaderSubroutine MaxSubroutineUniformLocations;
	static const ArbShaderSubroutine ActiveSubroutineUniformLocations;
	static const ArbShaderSubroutine ActiveSubroutineMaxLength;
	static const ArbShaderSubroutine ActiveSubroutineUniformMaxLength;
	static const ArbShaderSubroutine NumCompatibleSubroutines;
	static const ArbShaderSubroutine CompatibleSubroutines;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderTextureImageSamples)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShaderTextureLod)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShadingLanguage100)
	static const ArbShadingLanguage100 ShadingLanguageVersionArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShadingLanguage420pack)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShadingLanguageInclude)
	static const ArbShadingLanguageInclude ShaderIncludeArb;
	static const ArbShadingLanguageInclude NamedStringLengthArb;
	static const ArbShadingLanguageInclude NamedStringTypeArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShadingLanguagePacking)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShadow)
	static const ArbShadow TextureCompareModeArb;
	static const ArbShadow TextureCompareFuncArb;
	static const ArbShadow CompareRToTextureArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbShadowAmbient)
	static const ArbShadowAmbient TextureCompareFailValueArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbSparseBuffer)
	static const ArbSparseBuffer SparseStorageBitArb;
	static const ArbSparseBuffer SparseBufferPageSizeArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbSparseTexture)
	static const ArbSparseTexture VirtualPageSizeXArb;
	static const ArbSparseTexture VirtualPageSizeYArb;
	static const ArbSparseTexture VirtualPageSizeZArb;
	static const ArbSparseTexture MaxSparseTextureSizeArb;
	static const ArbSparseTexture MaxSparse3DTextureSizeArb;
	static const ArbSparseTexture MaxSparseArrayTextureLayersArb;
	static const ArbSparseTexture MinSparseLevelArb;
	static const ArbSparseTexture TextureSparseArb;
	static const ArbSparseTexture VirtualPageSizeIndexArb;
	static const ArbSparseTexture NumVirtualPageSizesArb;
	static const ArbSparseTexture SparseTextureFullArrayCubeMipmapsArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbStencilTexturing)
	static const ArbStencilTexturing DepthStencilTextureMode;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbSync)
	static const ArbSync SyncFlushCommandsBit;
	static const ArbSync MaxServerWaitTimeout;
	static const ArbSync ObjectType;
	static const ArbSync SyncCondition;
	static const ArbSync SyncStatus;
	static const ArbSync SyncFlags;
	static const ArbSync SyncFence;
	static const ArbSync SyncGpuCommandsComplete;
	static const ArbSync Unsignaled;
	static const ArbSync Signaled;
	static const ArbSync AlreadySignaled;
	static const ArbSync TimeoutExpired;
	static const ArbSync ConditionSatisfied;
	static const ArbSync WaitFailed;
	static const ArbSync TimeoutIgnored;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTessellationShader)
	static const ArbTessellationShader Triangles;
	static const ArbTessellationShader Quads;
	static const ArbTessellationShader Patches;
	static const ArbTessellationShader Equal;
	static const ArbTessellationShader Cw;
	static const ArbTessellationShader Ccw;
	static const ArbTessellationShader UniformBlockReferencedByTessControlShader;
	static const ArbTessellationShader UniformBlockReferencedByTessEvaluationShader;
	static const ArbTessellationShader MaxTessControlInputComponents;
	static const ArbTessellationShader MaxTessEvaluationInputComponents;
	static const ArbTessellationShader MaxCombinedTessControlUniformComponents;
	static const ArbTessellationShader MaxCombinedTessEvaluationUniformComponents;
	static const ArbTessellationShader PatchVertices;
	static const ArbTessellationShader PatchDefaultInnerLevel;
	static const ArbTessellationShader PatchDefaultOuterLevel;
	static const ArbTessellationShader TessControlOutputVertices;
	static const ArbTessellationShader TessGenMode;
	static const ArbTessellationShader TessGenSpacing;
	static const ArbTessellationShader TessGenVertexOrder;
	static const ArbTessellationShader TessGenPointMode;
	static const ArbTessellationShader Isolines;
	static const ArbTessellationShader FractionalOdd;
	static const ArbTessellationShader FractionalEven;
	static const ArbTessellationShader MaxPatchVertices;
	static const ArbTessellationShader MaxTessGenLevel;
	static const ArbTessellationShader MaxTessControlUniformComponents;
	static const ArbTessellationShader MaxTessEvaluationUniformComponents;
	static const ArbTessellationShader MaxTessControlTextureImageUnits;
	static const ArbTessellationShader MaxTessEvaluationTextureImageUnits;
	static const ArbTessellationShader MaxTessControlOutputComponents;
	static const ArbTessellationShader MaxTessPatchComponents;
	static const ArbTessellationShader MaxTessControlTotalOutputComponents;
	static const ArbTessellationShader MaxTessEvaluationOutputComponents;
	static const ArbTessellationShader TessEvaluationShader;
	static const ArbTessellationShader TessControlShader;
	static const ArbTessellationShader MaxTessControlUniformBlocks;
	static const ArbTessellationShader MaxTessEvaluationUniformBlocks;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureBarrier)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureBorderClamp)
	static const ArbTextureBorderClamp ClampToBorderArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureBufferObject)
	static const ArbTextureBufferObject TextureBufferArb;
	static const ArbTextureBufferObject MaxTextureBufferSizeArb;
	static const ArbTextureBufferObject TextureBindingBufferArb;
	static const ArbTextureBufferObject TextureBufferDataStoreBindingArb;
	static const ArbTextureBufferObject TextureBufferFormatArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureBufferObjectRgb32)
	static const ArbTextureBufferObjectRgb32 Rgb32f;
	static const ArbTextureBufferObjectRgb32 Rgb32ui;
	static const ArbTextureBufferObjectRgb32 Rgb32i;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureBufferRange)
	static const ArbTextureBufferRange TextureBufferOffset;
	static const ArbTextureBufferRange TextureBufferSize;
	static const ArbTextureBufferRange TextureBufferOffsetAlignment;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureCompression)
	static const ArbTextureCompression CompressedAlphaArb;
	static const ArbTextureCompression CompressedLuminanceArb;
	static const ArbTextureCompression CompressedLuminanceAlphaArb;
	static const ArbTextureCompression CompressedIntensityArb;
	static const ArbTextureCompression CompressedRgbArb;
	static const ArbTextureCompression CompressedRgbaArb;
	static const ArbTextureCompression TextureCompressionHintArb;
	static const ArbTextureCompression TextureCompressedImageSizeArb;
	static const ArbTextureCompression TextureCompressedArb;
	static const ArbTextureCompression NumCompressedTextureFormatsArb;
	static const ArbTextureCompression CompressedTextureFormatsArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureCompressionBptc)
	static const ArbTextureCompressionBptc CompressedRgbaBptcUnormArb;
	static const ArbTextureCompressionBptc CompressedSrgbAlphaBptcUnormArb;
	static const ArbTextureCompressionBptc CompressedRgbBptcSignedFloatArb;
	static const ArbTextureCompressionBptc CompressedRgbBptcUnsignedFloatArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureCompressionRgtc)
	static const ArbTextureCompressionRgtc CompressedRedRgtc1;
	static const ArbTextureCompressionRgtc CompressedSignedRedRgtc1;
	static const ArbTextureCompressionRgtc CompressedRgRgtc2;
	static const ArbTextureCompressionRgtc CompressedSignedRgRgtc2;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureCubeMap)
	static const ArbTextureCubeMap NormalMapArb;
	static const ArbTextureCubeMap ReflectionMapArb;
	static const ArbTextureCubeMap TextureCubeMapArb;
	static const ArbTextureCubeMap TextureBindingCubeMapArb;
	static const ArbTextureCubeMap TextureCubeMapPositiveXArb;
	static const ArbTextureCubeMap TextureCubeMapNegativeXArb;
	static const ArbTextureCubeMap TextureCubeMapPositiveYArb;
	static const ArbTextureCubeMap TextureCubeMapNegativeYArb;
	static const ArbTextureCubeMap TextureCubeMapPositiveZArb;
	static const ArbTextureCubeMap TextureCubeMapNegativeZArb;
	static const ArbTextureCubeMap ProxyTextureCubeMapArb;
	static const ArbTextureCubeMap MaxCubeMapTextureSizeArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureCubeMapArray)
	static const ArbTextureCubeMapArray TextureCubeMapArrayArb;
	static const ArbTextureCubeMapArray TextureBindingCubeMapArrayArb;
	static const ArbTextureCubeMapArray ProxyTextureCubeMapArrayArb;
	static const ArbTextureCubeMapArray SamplerCubeMapArrayArb;
	static const ArbTextureCubeMapArray SamplerCubeMapArrayShadowArb;
	static const ArbTextureCubeMapArray IntSamplerCubeMapArrayArb;
	static const ArbTextureCubeMapArray UnsignedIntSamplerCubeMapArrayArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureEnvAdd)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureEnvCombine)
	static const ArbTextureEnvCombine SubtractArb;
	static const ArbTextureEnvCombine CombineArb;
	static const ArbTextureEnvCombine CombineRgbArb;
	static const ArbTextureEnvCombine CombineAlphaArb;
	static const ArbTextureEnvCombine RgbScaleArb;
	static const ArbTextureEnvCombine AddSignedArb;
	static const ArbTextureEnvCombine InterpolateArb;
	static const ArbTextureEnvCombine ConstantArb;
	static const ArbTextureEnvCombine PrimaryColorArb;
	static const ArbTextureEnvCombine PreviousArb;
	static const ArbTextureEnvCombine Source0RgbArb;
	static const ArbTextureEnvCombine Source1RgbArb;
	static const ArbTextureEnvCombine Source2RgbArb;
	static const ArbTextureEnvCombine Source0AlphaArb;
	static const ArbTextureEnvCombine Source1AlphaArb;
	static const ArbTextureEnvCombine Source2AlphaArb;
	static const ArbTextureEnvCombine Operand0RgbArb;
	static const ArbTextureEnvCombine Operand1RgbArb;
	static const ArbTextureEnvCombine Operand2RgbArb;
	static const ArbTextureEnvCombine Operand0AlphaArb;
	static const ArbTextureEnvCombine Operand1AlphaArb;
	static const ArbTextureEnvCombine Operand2AlphaArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureEnvCrossbar)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureEnvDot3)
	static const ArbTextureEnvDot3 Dot3RgbArb;
	static const ArbTextureEnvDot3 Dot3RgbaArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureFloat)
	static const ArbTextureFloat Rgba32fArb;
	static const ArbTextureFloat Rgb32fArb;
	static const ArbTextureFloat Alpha32fArb;
	static const ArbTextureFloat Intensity32fArb;
	static const ArbTextureFloat Luminance32fArb;
	static const ArbTextureFloat LuminanceAlpha32fArb;
	static const ArbTextureFloat Rgba16fArb;
	static const ArbTextureFloat Rgb16fArb;
	static const ArbTextureFloat Alpha16fArb;
	static const ArbTextureFloat Intensity16fArb;
	static const ArbTextureFloat Luminance16fArb;
	static const ArbTextureFloat LuminanceAlpha16fArb;
	static const ArbTextureFloat TextureRedTypeArb;
	static const ArbTextureFloat TextureGreenTypeArb;
	static const ArbTextureFloat TextureBlueTypeArb;
	static const ArbTextureFloat TextureAlphaTypeArb;
	static const ArbTextureFloat TextureLuminanceTypeArb;
	static const ArbTextureFloat TextureIntensityTypeArb;
	static const ArbTextureFloat TextureDepthTypeArb;
	static const ArbTextureFloat UnsignedNormalizedArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureGather)
	static const ArbTextureGather MinProgramTextureGatherOffsetArb;
	static const ArbTextureGather MaxProgramTextureGatherOffsetArb;
	static const ArbTextureGather MaxProgramTextureGatherComponentsArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureMirrorClampToEdge)
	static const ArbTextureMirrorClampToEdge MirrorClampToEdge;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureMirroredRepeat)
	static const ArbTextureMirroredRepeat MirroredRepeatArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureMultisample)
	static const ArbTextureMultisample SamplePosition;
	static const ArbTextureMultisample SampleMask;
	static const ArbTextureMultisample SampleMaskValue;
	static const ArbTextureMultisample MaxSampleMaskWords;
	static const ArbTextureMultisample Texture2DMultisample;
	static const ArbTextureMultisample ProxyTexture2DMultisample;
	static const ArbTextureMultisample Texture2DMultisampleArray;
	static const ArbTextureMultisample ProxyTexture2DMultisampleArray;
	static const ArbTextureMultisample TextureBinding2DMultisample;
	static const ArbTextureMultisample TextureBinding2DMultisampleArray;
	static const ArbTextureMultisample TextureSamples;
	static const ArbTextureMultisample TextureFixedSampleLocations;
	static const ArbTextureMultisample Sampler2DMultisample;
	static const ArbTextureMultisample IntSampler2DMultisample;
	static const ArbTextureMultisample UnsignedIntSampler2DMultisample;
	static const ArbTextureMultisample Sampler2DMultisampleArray;
	static const ArbTextureMultisample IntSampler2DMultisampleArray;
	static const ArbTextureMultisample UnsignedIntSampler2DMultisampleArray;
	static const ArbTextureMultisample MaxColorTextureSamples;
	static const ArbTextureMultisample MaxDepthTextureSamples;
	static const ArbTextureMultisample MaxIntegerSamples;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureNonPowerOfTwo)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureQueryLevels)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureQueryLod)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureRectangle)
	static const ArbTextureRectangle TextureRectangleArb;
	static const ArbTextureRectangle TextureBindingRectangleArb;
	static const ArbTextureRectangle ProxyTextureRectangleArb;
	static const ArbTextureRectangle MaxRectangleTextureSizeArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureRg)
	static const ArbTextureRg Rg;
	static const ArbTextureRg RgInteger;
	static const ArbTextureRg R8;
	static const ArbTextureRg R16;
	static const ArbTextureRg Rg8;
	static const ArbTextureRg Rg16;
	static const ArbTextureRg R16f;
	static const ArbTextureRg R32f;
	static const ArbTextureRg Rg16f;
	static const ArbTextureRg Rg32f;
	static const ArbTextureRg R8i;
	static const ArbTextureRg R8ui;
	static const ArbTextureRg R16i;
	static const ArbTextureRg R16ui;
	static const ArbTextureRg R32i;
	static const ArbTextureRg R32ui;
	static const ArbTextureRg Rg8i;
	static const ArbTextureRg Rg8ui;
	static const ArbTextureRg Rg16i;
	static const ArbTextureRg Rg16ui;
	static const ArbTextureRg Rg32i;
	static const ArbTextureRg Rg32ui;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureRgb10A2ui)
	static const ArbTextureRgb10A2ui Rgb10A2ui;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureStencil8)
	static const ArbTextureStencil8 StencilIndex;
	static const ArbTextureStencil8 StencilIndex8;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureStorage)
	static const ArbTextureStorage TextureImmutableFormat;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureStorageMultisample)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureSwizzle)
	static const ArbTextureSwizzle TextureSwizzleR;
	static const ArbTextureSwizzle TextureSwizzleG;
	static const ArbTextureSwizzle TextureSwizzleB;
	static const ArbTextureSwizzle TextureSwizzleA;
	static const ArbTextureSwizzle TextureSwizzleRgba;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTextureView)
	static const ArbTextureView TextureViewMinLevel;
	static const ArbTextureView TextureViewNumLevels;
	static const ArbTextureView TextureViewMinLayer;
	static const ArbTextureView TextureViewNumLayers;
	static const ArbTextureView TextureImmutableLevels;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTimerQuery)
	static const ArbTimerQuery TimeElapsed;
	static const ArbTimerQuery Timestamp;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTransformFeedback2)
	static const ArbTransformFeedback2 TransformFeedback;
	static const ArbTransformFeedback2 TransformFeedbackBufferPaused;
	static const ArbTransformFeedback2 TransformFeedbackPaused;
	static const ArbTransformFeedback2 TransformFeedbackActive;
	static const ArbTransformFeedback2 TransformFeedbackBufferActive;
	static const ArbTransformFeedback2 TransformFeedbackBinding;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTransformFeedback3)
	static const ArbTransformFeedback3 MaxTransformFeedbackBuffers;
	static const ArbTransformFeedback3 MaxVertexStreams;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTransformFeedbackInstanced)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTransformFeedbackOverflowQuery)
	static const ArbTransformFeedbackOverflowQuery TransformFeedbackOverflowArb;
	static const ArbTransformFeedbackOverflowQuery TransformFeedbackStreamOverflowArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbTransposeMatrix)
	static const ArbTransposeMatrix TransposeModelviewMatrixArb;
	static const ArbTransposeMatrix TransposeProjectionMatrixArb;
	static const ArbTransposeMatrix TransposeTextureMatrixArb;
	static const ArbTransposeMatrix TransposeColorMatrixArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbUniformBufferObject)
	static const ArbUniformBufferObject UniformBuffer;
	static const ArbUniformBufferObject UniformBufferBinding;
	static const ArbUniformBufferObject UniformBufferStart;
	static const ArbUniformBufferObject UniformBufferSize;
	static const ArbUniformBufferObject MaxVertexUniformBlocks;
	static const ArbUniformBufferObject MaxGeometryUniformBlocks;
	static const ArbUniformBufferObject MaxFragmentUniformBlocks;
	static const ArbUniformBufferObject MaxCombinedUniformBlocks;
	static const ArbUniformBufferObject MaxUniformBufferBindings;
	static const ArbUniformBufferObject MaxUniformBlockSize;
	static const ArbUniformBufferObject MaxCombinedVertexUniformComponents;
	static const ArbUniformBufferObject MaxCombinedGeometryUniformComponents;
	static const ArbUniformBufferObject MaxCombinedFragmentUniformComponents;
	static const ArbUniformBufferObject UniformBufferOffsetAlignment;
	static const ArbUniformBufferObject ActiveUniformBlockMaxNameLength;
	static const ArbUniformBufferObject ActiveUniformBlocks;
	static const ArbUniformBufferObject UniformType;
	static const ArbUniformBufferObject UniformSize;
	static const ArbUniformBufferObject UniformNameLength;
	static const ArbUniformBufferObject UniformBlockIndex;
	static const ArbUniformBufferObject UniformOffset;
	static const ArbUniformBufferObject UniformArrayStride;
	static const ArbUniformBufferObject UniformMatrixStride;
	static const ArbUniformBufferObject UniformIsRowMajor;
	static const ArbUniformBufferObject UniformBlockBinding;
	static const ArbUniformBufferObject UniformBlockDataSize;
	static const ArbUniformBufferObject UniformBlockNameLength;
	static const ArbUniformBufferObject UniformBlockActiveUniforms;
	static const ArbUniformBufferObject UniformBlockActiveUniformIndices;
	static const ArbUniformBufferObject UniformBlockReferencedByVertexShader;
	static const ArbUniformBufferObject UniformBlockReferencedByGeometryShader;
	static const ArbUniformBufferObject UniformBlockReferencedByFragmentShader;
	static const ArbUniformBufferObject InvalidIndex;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbVertexArrayBgra)
	static const ArbVertexArrayBgra Bgra;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbVertexArrayObject)
	static const ArbVertexArrayObject VertexArrayBinding;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbVertexAttrib64bit)
	static const ArbVertexAttrib64bit Rgb32i;
	static const ArbVertexAttrib64bit DoubleMat2;
	static const ArbVertexAttrib64bit DoubleMat3;
	static const ArbVertexAttrib64bit DoubleMat4;
	static const ArbVertexAttrib64bit DoubleMat2x3;
	static const ArbVertexAttrib64bit DoubleMat2x4;
	static const ArbVertexAttrib64bit DoubleMat3x2;
	static const ArbVertexAttrib64bit DoubleMat3x4;
	static const ArbVertexAttrib64bit DoubleMat4x2;
	static const ArbVertexAttrib64bit DoubleMat4x3;
	static const ArbVertexAttrib64bit DoubleVec2;
	static const ArbVertexAttrib64bit DoubleVec3;
	static const ArbVertexAttrib64bit DoubleVec4;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbVertexAttribBinding)
	static const ArbVertexAttribBinding VertexAttribBinding;
	static const ArbVertexAttribBinding VertexAttribRelativeOffset;
	static const ArbVertexAttribBinding VertexBindingDivisor;
	static const ArbVertexAttribBinding VertexBindingOffset;
	static const ArbVertexAttribBinding VertexBindingStride;
	static const ArbVertexAttribBinding MaxVertexAttribRelativeOffset;
	static const ArbVertexAttribBinding MaxVertexAttribBindings;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbVertexBlend)
	static const ArbVertexBlend Modelview0Arb;
	static const ArbVertexBlend Modelview1Arb;
	static const ArbVertexBlend MaxVertexUnitsArb;
	static const ArbVertexBlend ActiveVertexUnitsArb;
	static const ArbVertexBlend WeightSumUnityArb;
	static const ArbVertexBlend VertexBlendArb;
	static const ArbVertexBlend CurrentWeightArb;
	static const ArbVertexBlend WeightArrayTypeArb;
	static const ArbVertexBlend WeightArrayStrideArb;
	static const ArbVertexBlend WeightArraySizeArb;
	static const ArbVertexBlend WeightArrayPointerArb;
	static const ArbVertexBlend WeightArrayArb;
	static const ArbVertexBlend Modelview2Arb;
	static const ArbVertexBlend Modelview3Arb;
	static const ArbVertexBlend Modelview4Arb;
	static const ArbVertexBlend Modelview5Arb;
	static const ArbVertexBlend Modelview6Arb;
	static const ArbVertexBlend Modelview7Arb;
	static const ArbVertexBlend Modelview8Arb;
	static const ArbVertexBlend Modelview9Arb;
	static const ArbVertexBlend Modelview10Arb;
	static const ArbVertexBlend Modelview11Arb;
	static const ArbVertexBlend Modelview12Arb;
	static const ArbVertexBlend Modelview13Arb;
	static const ArbVertexBlend Modelview14Arb;
	static const ArbVertexBlend Modelview15Arb;
	static const ArbVertexBlend Modelview16Arb;
	static const ArbVertexBlend Modelview17Arb;
	static const ArbVertexBlend Modelview18Arb;
	static const ArbVertexBlend Modelview19Arb;
	static const ArbVertexBlend Modelview20Arb;
	static const ArbVertexBlend Modelview21Arb;
	static const ArbVertexBlend Modelview22Arb;
	static const ArbVertexBlend Modelview23Arb;
	static const ArbVertexBlend Modelview24Arb;
	static const ArbVertexBlend Modelview25Arb;
	static const ArbVertexBlend Modelview26Arb;
	static const ArbVertexBlend Modelview27Arb;
	static const ArbVertexBlend Modelview28Arb;
	static const ArbVertexBlend Modelview29Arb;
	static const ArbVertexBlend Modelview30Arb;
	static const ArbVertexBlend Modelview31Arb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbVertexBufferObject)
	static const ArbVertexBufferObject BufferSizeArb;
	static const ArbVertexBufferObject BufferUsageArb;
	static const ArbVertexBufferObject ArrayBufferArb;
	static const ArbVertexBufferObject ElementArrayBufferArb;
	static const ArbVertexBufferObject ArrayBufferBindingArb;
	static const ArbVertexBufferObject ElementArrayBufferBindingArb;
	static const ArbVertexBufferObject VertexArrayBufferBindingArb;
	static const ArbVertexBufferObject NormalArrayBufferBindingArb;
	static const ArbVertexBufferObject ColorArrayBufferBindingArb;
	static const ArbVertexBufferObject IndexArrayBufferBindingArb;
	static const ArbVertexBufferObject TextureCoordArrayBufferBindingArb;
	static const ArbVertexBufferObject EdgeFlagArrayBufferBindingArb;
	static const ArbVertexBufferObject SecondaryColorArrayBufferBindingArb;
	static const ArbVertexBufferObject FogCoordinateArrayBufferBindingArb;
	static const ArbVertexBufferObject WeightArrayBufferBindingArb;
	static const ArbVertexBufferObject VertexAttribArrayBufferBindingArb;
	static const ArbVertexBufferObject ReadOnlyArb;
	static const ArbVertexBufferObject WriteOnlyArb;
	static const ArbVertexBufferObject ReadWriteArb;
	static const ArbVertexBufferObject BufferAccessArb;
	static const ArbVertexBufferObject BufferMappedArb;
	static const ArbVertexBufferObject BufferMapPointerArb;
	static const ArbVertexBufferObject StreamDrawArb;
	static const ArbVertexBufferObject StreamReadArb;
	static const ArbVertexBufferObject StreamCopyArb;
	static const ArbVertexBufferObject StaticDrawArb;
	static const ArbVertexBufferObject StaticReadArb;
	static const ArbVertexBufferObject StaticCopyArb;
	static const ArbVertexBufferObject DynamicDrawArb;
	static const ArbVertexBufferObject DynamicReadArb;
	static const ArbVertexBufferObject DynamicCopyArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbVertexProgram)
	static const ArbVertexProgram ColorSumArb;
	static const ArbVertexProgram VertexProgramArb;
	static const ArbVertexProgram VertexAttribArrayEnabledArb;
	static const ArbVertexProgram VertexAttribArraySizeArb;
	static const ArbVertexProgram VertexAttribArrayStrideArb;
	static const ArbVertexProgram VertexAttribArrayTypeArb;
	static const ArbVertexProgram CurrentVertexAttribArb;
	static const ArbVertexProgram ProgramLengthArb;
	static const ArbVertexProgram ProgramStringArb;
	static const ArbVertexProgram MaxProgramMatrixStackDepthArb;
	static const ArbVertexProgram MaxProgramMatricesArb;
	static const ArbVertexProgram CurrentMatrixStackDepthArb;
	static const ArbVertexProgram CurrentMatrixArb;
	static const ArbVertexProgram VertexProgramPointSizeArb;
	static const ArbVertexProgram VertexProgramTwoSideArb;
	static const ArbVertexProgram VertexAttribArrayPointerArb;
	static const ArbVertexProgram ProgramErrorPositionArb;
	static const ArbVertexProgram ProgramBindingArb;
	static const ArbVertexProgram MaxVertexAttribsArb;
	static const ArbVertexProgram VertexAttribArrayNormalizedArb;
	static const ArbVertexProgram ProgramErrorStringArb;
	static const ArbVertexProgram ProgramFormatAsciiArb;
	static const ArbVertexProgram ProgramFormatArb;
	static const ArbVertexProgram ProgramInstructionsArb;
	static const ArbVertexProgram MaxProgramInstructionsArb;
	static const ArbVertexProgram ProgramNativeInstructionsArb;
	static const ArbVertexProgram MaxProgramNativeInstructionsArb;
	static const ArbVertexProgram ProgramTemporariesArb;
	static const ArbVertexProgram MaxProgramTemporariesArb;
	static const ArbVertexProgram ProgramNativeTemporariesArb;
	static const ArbVertexProgram MaxProgramNativeTemporariesArb;
	static const ArbVertexProgram ProgramParametersArb;
	static const ArbVertexProgram MaxProgramParametersArb;
	static const ArbVertexProgram ProgramNativeParametersArb;
	static const ArbVertexProgram MaxProgramNativeParametersArb;
	static const ArbVertexProgram ProgramAttribsArb;
	static const ArbVertexProgram MaxProgramAttribsArb;
	static const ArbVertexProgram ProgramNativeAttribsArb;
	static const ArbVertexProgram MaxProgramNativeAttribsArb;
	static const ArbVertexProgram ProgramAddressRegistersArb;
	static const ArbVertexProgram MaxProgramAddressRegistersArb;
	static const ArbVertexProgram ProgramNativeAddressRegistersArb;
	static const ArbVertexProgram MaxProgramNativeAddressRegistersArb;
	static const ArbVertexProgram MaxProgramLocalParametersArb;
	static const ArbVertexProgram MaxProgramEnvParametersArb;
	static const ArbVertexProgram ProgramUnderNativeLimitsArb;
	static const ArbVertexProgram TransposeCurrentMatrixArb;
	static const ArbVertexProgram Matrix0Arb;
	static const ArbVertexProgram Matrix1Arb;
	static const ArbVertexProgram Matrix2Arb;
	static const ArbVertexProgram Matrix3Arb;
	static const ArbVertexProgram Matrix4Arb;
	static const ArbVertexProgram Matrix5Arb;
	static const ArbVertexProgram Matrix6Arb;
	static const ArbVertexProgram Matrix7Arb;
	static const ArbVertexProgram Matrix8Arb;
	static const ArbVertexProgram Matrix9Arb;
	static const ArbVertexProgram Matrix10Arb;
	static const ArbVertexProgram Matrix11Arb;
	static const ArbVertexProgram Matrix12Arb;
	static const ArbVertexProgram Matrix13Arb;
	static const ArbVertexProgram Matrix14Arb;
	static const ArbVertexProgram Matrix15Arb;
	static const ArbVertexProgram Matrix16Arb;
	static const ArbVertexProgram Matrix17Arb;
	static const ArbVertexProgram Matrix18Arb;
	static const ArbVertexProgram Matrix19Arb;
	static const ArbVertexProgram Matrix20Arb;
	static const ArbVertexProgram Matrix21Arb;
	static const ArbVertexProgram Matrix22Arb;
	static const ArbVertexProgram Matrix23Arb;
	static const ArbVertexProgram Matrix24Arb;
	static const ArbVertexProgram Matrix25Arb;
	static const ArbVertexProgram Matrix26Arb;
	static const ArbVertexProgram Matrix27Arb;
	static const ArbVertexProgram Matrix28Arb;
	static const ArbVertexProgram Matrix29Arb;
	static const ArbVertexProgram Matrix30Arb;
	static const ArbVertexProgram Matrix31Arb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbVertexShader)
	static const ArbVertexShader Float;
	static const ArbVertexShader VertexAttribArrayEnabledArb;
	static const ArbVertexShader VertexAttribArraySizeArb;
	static const ArbVertexShader VertexAttribArrayStrideArb;
	static const ArbVertexShader VertexAttribArrayTypeArb;
	static const ArbVertexShader CurrentVertexAttribArb;
	static const ArbVertexShader VertexProgramPointSizeArb;
	static const ArbVertexShader VertexProgramTwoSideArb;
	static const ArbVertexShader VertexAttribArrayPointerArb;
	static const ArbVertexShader MaxVertexAttribsArb;
	static const ArbVertexShader VertexAttribArrayNormalizedArb;
	static const ArbVertexShader MaxTextureCoordsArb;
	static const ArbVertexShader MaxTextureImageUnitsArb;
	static const ArbVertexShader VertexShaderArb;
	static const ArbVertexShader MaxVertexUniformComponentsArb;
	static const ArbVertexShader MaxVaryingFloatsArb;
	static const ArbVertexShader MaxVertexTextureImageUnitsArb;
	static const ArbVertexShader MaxCombinedTextureImageUnitsArb;
	static const ArbVertexShader FloatVec2Arb;
	static const ArbVertexShader FloatVec3Arb;
	static const ArbVertexShader FloatVec4Arb;
	static const ArbVertexShader FloatMat2Arb;
	static const ArbVertexShader FloatMat3Arb;
	static const ArbVertexShader FloatMat4Arb;
	static const ArbVertexShader ObjectActiveAttributesArb;
	static const ArbVertexShader ObjectActiveAttributeMaxLengthArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbVertexType10f11f11fRev)
	static const ArbVertexType10f11f11fRev UnsignedInt10F11F11FRev;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbVertexType2101010Rev)
	static const ArbVertexType2101010Rev UnsignedInt2101010Rev;
	static const ArbVertexType2101010Rev Int2101010Rev;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbViewportArray)
	static const ArbViewportArray DepthRange;
	static const ArbViewportArray Viewport;
	static const ArbViewportArray ScissorBox;
	static const ArbViewportArray ScissorTest;
	static const ArbViewportArray MaxViewports;
	static const ArbViewportArray ViewportSubpixelBits;
	static const ArbViewportArray ViewportBoundsRange;
	static const ArbViewportArray LayerProvokingVertex;
	static const ArbViewportArray ViewportIndexProvokingVertex;
	static const ArbViewportArray UndefinedVertex;
	static const ArbViewportArray FirstVertexConvention;
	static const ArbViewportArray LastVertexConvention;
	static const ArbViewportArray ProvokingVertex;
OPENGL_ENUM_END

OPENGL_ENUM_START(ArbWindowPos)
OPENGL_ENUM_END

OPENGL_ENUM_START(ArrayCap)
	static const ArrayCap VertexArray;
	static const ArrayCap NormalArray;
	static const ArrayCap ColorArray;
	static const ArrayCap IndexArray;
	static const ArrayCap TextureCoordArray;
	static const ArrayCap EdgeFlagArray;
	static const ArrayCap FogCoordArray;
	static const ArrayCap SecondaryColorArray;
OPENGL_ENUM_END

OPENGL_ENUM_START(AssemblyProgramFormatArb)
	static const AssemblyProgramFormatArb ProgramFormatAsciiArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(AssemblyProgramParameterArb)
	static const AssemblyProgramParameterArb ProgramBinaryRetrievableHint;
	static const AssemblyProgramParameterArb ProgramSeparable;
	static const AssemblyProgramParameterArb ProgramLength;
	static const AssemblyProgramParameterArb ProgramBinding;
	static const AssemblyProgramParameterArb ProgramAluInstructionsArb;
	static const AssemblyProgramParameterArb ProgramTexInstructionsArb;
	static const AssemblyProgramParameterArb ProgramTexIndirectionsArb;
	static const AssemblyProgramParameterArb ProgramNativeAluInstructionsArb;
	static const AssemblyProgramParameterArb ProgramNativeTexInstructionsArb;
	static const AssemblyProgramParameterArb ProgramNativeTexIndirectionsArb;
	static const AssemblyProgramParameterArb MaxProgramAluInstructionsArb;
	static const AssemblyProgramParameterArb MaxProgramTexInstructionsArb;
	static const AssemblyProgramParameterArb MaxProgramTexIndirectionsArb;
	static const AssemblyProgramParameterArb MaxProgramNativeAluInstructionsArb;
	static const AssemblyProgramParameterArb MaxProgramNativeTexInstructionsArb;
	static const AssemblyProgramParameterArb MaxProgramNativeTexIndirectionsArb;
	static const AssemblyProgramParameterArb ProgramFormat;
	static const AssemblyProgramParameterArb ProgramInstruction;
	static const AssemblyProgramParameterArb MaxProgramInstructions;
	static const AssemblyProgramParameterArb ProgramNativeInstructions;
	static const AssemblyProgramParameterArb MaxProgramNativeInstructions;
	static const AssemblyProgramParameterArb ProgramTemporaries;
	static const AssemblyProgramParameterArb MaxProgramTemporaries;
	static const AssemblyProgramParameterArb ProgramNativeTemporaries;
	static const AssemblyProgramParameterArb MaxProgramNativeTemporaries;
	static const AssemblyProgramParameterArb ProgramParameters;
	static const AssemblyProgramParameterArb MaxProgramParameters;
	static const AssemblyProgramParameterArb ProgramNativeParameters;
	static const AssemblyProgramParameterArb MaxProgramNativeParameters;
	static const AssemblyProgramParameterArb ProgramAttribs;
	static const AssemblyProgramParameterArb MaxProgramAttribs;
	static const AssemblyProgramParameterArb ProgramNativeAttribs;
	static const AssemblyProgramParameterArb MaxProgramNativeAttribs;
	static const AssemblyProgramParameterArb ProgramAddressRegisters;
	static const AssemblyProgramParameterArb MaxProgramAddressRegisters;
	static const AssemblyProgramParameterArb ProgramNativeAddressRegisters;
	static const AssemblyProgramParameterArb MaxProgramNativeAddressRegisters;
	static const AssemblyProgramParameterArb MaxProgramLocalParameters;
	static const AssemblyProgramParameterArb MaxProgramEnvParameters;
	static const AssemblyProgramParameterArb ProgramUnderNativeLimits;
	static const AssemblyProgramParameterArb GeometryVerticesOut;
	static const AssemblyProgramParameterArb GeometryInputType;
	static const AssemblyProgramParameterArb GeometryOutputType;
OPENGL_ENUM_END

OPENGL_ENUM_START(AssemblyProgramStringParameterArb)
	static const AssemblyProgramStringParameterArb ProgramString;
OPENGL_ENUM_END

OPENGL_ENUM_START(AssemblyProgramTargetArb)
	static const AssemblyProgramTargetArb VertexProgram;
	static const AssemblyProgramTargetArb FragmentProgram;
	static const AssemblyProgramTargetArb GeometryProgramNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiDrawBuffers)
	static const AtiDrawBuffers MaxDrawBuffersAti;
	static const AtiDrawBuffers DrawBuffer0Ati;
	static const AtiDrawBuffers DrawBuffer1Ati;
	static const AtiDrawBuffers DrawBuffer2Ati;
	static const AtiDrawBuffers DrawBuffer3Ati;
	static const AtiDrawBuffers DrawBuffer4Ati;
	static const AtiDrawBuffers DrawBuffer5Ati;
	static const AtiDrawBuffers DrawBuffer6Ati;
	static const AtiDrawBuffers DrawBuffer7Ati;
	static const AtiDrawBuffers DrawBuffer8Ati;
	static const AtiDrawBuffers DrawBuffer9Ati;
	static const AtiDrawBuffers DrawBuffer10Ati;
	static const AtiDrawBuffers DrawBuffer11Ati;
	static const AtiDrawBuffers DrawBuffer12Ati;
	static const AtiDrawBuffers DrawBuffer13Ati;
	static const AtiDrawBuffers DrawBuffer14Ati;
	static const AtiDrawBuffers DrawBuffer15Ati;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiElementArray)
	static const AtiElementArray ElementArrayAti;
	static const AtiElementArray ElementArrayTypeAti;
	static const AtiElementArray ElementArrayPointerAti;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiEnvmapBumpmap)
	static const AtiEnvmapBumpmap BumpRotMatrixAti;
	static const AtiEnvmapBumpmap BumpRotMatrixSizeAti;
	static const AtiEnvmapBumpmap BumpNumTexUnitsAti;
	static const AtiEnvmapBumpmap BumpTexUnitsAti;
	static const AtiEnvmapBumpmap DudvAti;
	static const AtiEnvmapBumpmap Du8Dv8Ati;
	static const AtiEnvmapBumpmap BumpEnvmapAti;
	static const AtiEnvmapBumpmap BumpTargetAti;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiFragmentShader)
	static const AtiFragmentShader Gl2XBitAti;
	static const AtiFragmentShader RedBitAti;
	static const AtiFragmentShader CompBitAti;
	static const AtiFragmentShader Gl4XBitAti;
	static const AtiFragmentShader GreenBitAti;
	static const AtiFragmentShader BlueBitAti;
	static const AtiFragmentShader Gl8XBitAti;
	static const AtiFragmentShader NegateBitAti;
	static const AtiFragmentShader BiasBitAti;
	static const AtiFragmentShader HalfBitAti;
	static const AtiFragmentShader QuarterBitAti;
	static const AtiFragmentShader EighthBitAti;
	static const AtiFragmentShader SaturateBitAti;
	static const AtiFragmentShader FragmentShaderAti;
	static const AtiFragmentShader Reg0Ati;
	static const AtiFragmentShader Reg1Ati;
	static const AtiFragmentShader Reg2Ati;
	static const AtiFragmentShader Reg3Ati;
	static const AtiFragmentShader Reg4Ati;
	static const AtiFragmentShader Reg5Ati;
	static const AtiFragmentShader Reg6Ati;
	static const AtiFragmentShader Reg7Ati;
	static const AtiFragmentShader Reg8Ati;
	static const AtiFragmentShader Reg9Ati;
	static const AtiFragmentShader Reg10Ati;
	static const AtiFragmentShader Reg11Ati;
	static const AtiFragmentShader Reg12Ati;
	static const AtiFragmentShader Reg13Ati;
	static const AtiFragmentShader Reg14Ati;
	static const AtiFragmentShader Reg15Ati;
	static const AtiFragmentShader Reg16Ati;
	static const AtiFragmentShader Reg17Ati;
	static const AtiFragmentShader Reg18Ati;
	static const AtiFragmentShader Reg19Ati;
	static const AtiFragmentShader Reg20Ati;
	static const AtiFragmentShader Reg21Ati;
	static const AtiFragmentShader Reg22Ati;
	static const AtiFragmentShader Reg23Ati;
	static const AtiFragmentShader Reg24Ati;
	static const AtiFragmentShader Reg25Ati;
	static const AtiFragmentShader Reg26Ati;
	static const AtiFragmentShader Reg27Ati;
	static const AtiFragmentShader Reg28Ati;
	static const AtiFragmentShader Reg29Ati;
	static const AtiFragmentShader Reg30Ati;
	static const AtiFragmentShader Reg31Ati;
	static const AtiFragmentShader Con0Ati;
	static const AtiFragmentShader Con1Ati;
	static const AtiFragmentShader Con2Ati;
	static const AtiFragmentShader Con3Ati;
	static const AtiFragmentShader Con4Ati;
	static const AtiFragmentShader Con5Ati;
	static const AtiFragmentShader Con6Ati;
	static const AtiFragmentShader Con7Ati;
	static const AtiFragmentShader Con8Ati;
	static const AtiFragmentShader Con9Ati;
	static const AtiFragmentShader Con10Ati;
	static const AtiFragmentShader Con11Ati;
	static const AtiFragmentShader Con12Ati;
	static const AtiFragmentShader Con13Ati;
	static const AtiFragmentShader Con14Ati;
	static const AtiFragmentShader Con15Ati;
	static const AtiFragmentShader Con16Ati;
	static const AtiFragmentShader Con17Ati;
	static const AtiFragmentShader Con18Ati;
	static const AtiFragmentShader Con19Ati;
	static const AtiFragmentShader Con20Ati;
	static const AtiFragmentShader Con21Ati;
	static const AtiFragmentShader Con22Ati;
	static const AtiFragmentShader Con23Ati;
	static const AtiFragmentShader Con24Ati;
	static const AtiFragmentShader Con25Ati;
	static const AtiFragmentShader Con26Ati;
	static const AtiFragmentShader Con27Ati;
	static const AtiFragmentShader Con28Ati;
	static const AtiFragmentShader Con29Ati;
	static const AtiFragmentShader Con30Ati;
	static const AtiFragmentShader Con31Ati;
	static const AtiFragmentShader MovAti;
	static const AtiFragmentShader AddAti;
	static const AtiFragmentShader MulAti;
	static const AtiFragmentShader SubAti;
	static const AtiFragmentShader Dot3Ati;
	static const AtiFragmentShader Dot4Ati;
	static const AtiFragmentShader MadAti;
	static const AtiFragmentShader LerpAti;
	static const AtiFragmentShader CndAti;
	static const AtiFragmentShader Cnd0Ati;
	static const AtiFragmentShader Dot2AddAti;
	static const AtiFragmentShader SecondaryInterpolatorAti;
	static const AtiFragmentShader NumFragmentRegistersAti;
	static const AtiFragmentShader NumFragmentConstantsAti;
	static const AtiFragmentShader NumPassesAti;
	static const AtiFragmentShader NumInstructionsPerPassAti;
	static const AtiFragmentShader NumInstructionsTotalAti;
	static const AtiFragmentShader NumInputInterpolatorComponentsAti;
	static const AtiFragmentShader NumLoopbackComponentsAti;
	static const AtiFragmentShader ColorAlphaPairingAti;
	static const AtiFragmentShader SwizzleStrAti;
	static const AtiFragmentShader SwizzleStqAti;
	static const AtiFragmentShader SwizzleStrDrAti;
	static const AtiFragmentShader SwizzleStqDqAti;
	static const AtiFragmentShader SwizzleStrqAti;
	static const AtiFragmentShader SwizzleStrqDqAti;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiMapObjectBuffer)
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiMeminfo)
	static const AtiMeminfo VboFreeMemoryAti;
	static const AtiMeminfo TextureFreeMemoryAti;
	static const AtiMeminfo RenderbufferFreeMemoryAti;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiPixelFormatFloat)
	static const AtiPixelFormatFloat RgbaFloatModeAti;
	static const AtiPixelFormatFloat ColorClearUnclampedValueAti;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiPnTriangles)
	static const AtiPnTriangles PnTrianglesAti;
	static const AtiPnTriangles MaxPnTrianglesTesselationLevelAti;
	static const AtiPnTriangles PnTrianglesPointModeAti;
	static const AtiPnTriangles PnTrianglesNormalModeAti;
	static const AtiPnTriangles PnTrianglesTesselationLevelAti;
	static const AtiPnTriangles PnTrianglesPointModeLinearAti;
	static const AtiPnTriangles PnTrianglesPointModeCubicAti;
	static const AtiPnTriangles PnTrianglesNormalModeLinearAti;
	static const AtiPnTriangles PnTrianglesNormalModeQuadraticAti;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiSeparateStencil)
	static const AtiSeparateStencil StencilBackFuncAti;
	static const AtiSeparateStencil StencilBackFailAti;
	static const AtiSeparateStencil StencilBackPassDepthFailAti;
	static const AtiSeparateStencil StencilBackPassDepthPassAti;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiTextFragmentShader)
	static const AtiTextFragmentShader TextFragmentShaderAti;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiTextureEnvCombine3)
	static const AtiTextureEnvCombine3 ModulateAddAti;
	static const AtiTextureEnvCombine3 ModulateSignedAddAti;
	static const AtiTextureEnvCombine3 ModulateSubtractAti;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiTextureFloat)
	static const AtiTextureFloat RgbaFloat32Ati;
	static const AtiTextureFloat RgbFloat32Ati;
	static const AtiTextureFloat AlphaFloat32Ati;
	static const AtiTextureFloat IntensityFloat32Ati;
	static const AtiTextureFloat LuminanceFloat32Ati;
	static const AtiTextureFloat LuminanceAlphaFloat32Ati;
	static const AtiTextureFloat RgbaFloat16Ati;
	static const AtiTextureFloat RgbFloat16Ati;
	static const AtiTextureFloat AlphaFloat16Ati;
	static const AtiTextureFloat IntensityFloat16Ati;
	static const AtiTextureFloat LuminanceFloat16Ati;
	static const AtiTextureFloat LuminanceAlphaFloat16Ati;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiTextureMirrorOnce)
	static const AtiTextureMirrorOnce MirrorClampAti;
	static const AtiTextureMirrorOnce MirrorClampToEdgeAti;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiVertexArrayObject)
	static const AtiVertexArrayObject StaticAti;
	static const AtiVertexArrayObject DynamicAti;
	static const AtiVertexArrayObject PreserveAti;
	static const AtiVertexArrayObject DiscardAti;
	static const AtiVertexArrayObject ObjectBufferSizeAti;
	static const AtiVertexArrayObject ObjectBufferUsageAti;
	static const AtiVertexArrayObject ArrayObjectBufferAti;
	static const AtiVertexArrayObject ArrayObjectOffsetAti;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiVertexAttribArrayObject)
OPENGL_ENUM_END

OPENGL_ENUM_START(AtiVertexStreams)
	static const AtiVertexStreams MaxVertexStreamsAti;
	static const AtiVertexStreams VertexStream0Ati;
	static const AtiVertexStreams VertexStream1Ati;
	static const AtiVertexStreams VertexStream2Ati;
	static const AtiVertexStreams VertexStream3Ati;
	static const AtiVertexStreams VertexStream4Ati;
	static const AtiVertexStreams VertexStream5Ati;
	static const AtiVertexStreams VertexStream6Ati;
	static const AtiVertexStreams VertexStream7Ati;
	static const AtiVertexStreams VertexSourceAti;
OPENGL_ENUM_END

OPENGL_ENUM_START(AtomicCounterBufferParameter)
	static const AtomicCounterBufferParameter AtomicCounterBufferReferencedByComputeShader;
	static const AtomicCounterBufferParameter AtomicCounterBufferBinding;
	static const AtomicCounterBufferParameter AtomicCounterBufferDataSize;
	static const AtomicCounterBufferParameter AtomicCounterBufferActiveAtomicCounters;
	static const AtomicCounterBufferParameter AtomicCounterBufferActiveAtomicCounterIndices;
	static const AtomicCounterBufferParameter AtomicCounterBufferReferencedByVertexShader;
	static const AtomicCounterBufferParameter AtomicCounterBufferReferencedByTessControlShader;
	static const AtomicCounterBufferParameter AtomicCounterBufferReferencedByTessEvaluationShader;
	static const AtomicCounterBufferParameter AtomicCounterBufferReferencedByGeometryShader;
	static const AtomicCounterBufferParameter AtomicCounterBufferReferencedByFragmentShader;
OPENGL_ENUM_END

OPENGL_ENUM_START(AttribMask)
	static const AttribMask CurrentBit;
	static const AttribMask PointBit;
	static const AttribMask LineBit;
	static const AttribMask PolygonBit;
	static const AttribMask PolygonStippleBit;
	static const AttribMask PixelModeBit;
	static const AttribMask LightingBit;
	static const AttribMask FogBit;
	static const AttribMask DepthBufferBit;
	static const AttribMask AccumBufferBit;
	static const AttribMask StencilBufferBit;
	static const AttribMask ViewportBit;
	static const AttribMask TransformBit;
	static const AttribMask EnableBit;
	static const AttribMask ColorBufferBit;
	static const AttribMask HintBit;
	static const AttribMask EvalBit;
	static const AttribMask ListBit;
	static const AttribMask TextureBit;
	static const AttribMask ScissorBit;
	static const AttribMask MultisampleBit;
	static const AttribMask MultisampleBit3Dfx;
	static const AttribMask MultisampleBitArb;
	static const AttribMask MultisampleBitExt;
	static const AttribMask AllAttribBits;
OPENGL_ENUM_END

OPENGL_ENUM_START(BeginFeedbackMode)
	static const BeginFeedbackMode Points;
	static const BeginFeedbackMode Lines;
	static const BeginFeedbackMode Triangles;
OPENGL_ENUM_END

OPENGL_ENUM_START(BeginMode)
	static const BeginMode Points;
	static const BeginMode Lines;
	static const BeginMode LineLoop;
	static const BeginMode LineStrip;
	static const BeginMode Triangles;
	static const BeginMode TriangleStrip;
	static const BeginMode TriangleFan;
	static const BeginMode Quads;
	static const BeginMode QuadStrip;
	static const BeginMode Polygon;
	static const BeginMode Patches;
	static const BeginMode LinesAdjacency;
	static const BeginMode LineStripAdjacency;
	static const BeginMode TrianglesAdjacency;
	static const BeginMode TriangleStripAdjacency;
OPENGL_ENUM_END

OPENGL_ENUM_START(BinaryFormat)
OPENGL_ENUM_END

OPENGL_ENUM_START(BlendEquationMode)
	static const BlendEquationMode FuncAdd;
	static const BlendEquationMode Min;
	static const BlendEquationMode Max;
	static const BlendEquationMode FuncSubtract;
	static const BlendEquationMode FuncReverseSubtract;
OPENGL_ENUM_END

OPENGL_ENUM_START(BlendEquationModeExt)
	static const BlendEquationModeExt LogicOp;
	static const BlendEquationModeExt FuncAddExt;
	static const BlendEquationModeExt MinExt;
	static const BlendEquationModeExt MaxExt;
	static const BlendEquationModeExt FuncSubtractExt;
	static const BlendEquationModeExt FuncReverseSubtractExt;
	static const BlendEquationModeExt AlphaMinSgix;
	static const BlendEquationModeExt AlphaMaxSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(BlendingFactorDest)
	static const BlendingFactorDest Zero;
	static const BlendingFactorDest SrcColor;
	static const BlendingFactorDest OneMinusSrcColor;
	static const BlendingFactorDest SrcAlpha;
	static const BlendingFactorDest OneMinusSrcAlpha;
	static const BlendingFactorDest DstAlpha;
	static const BlendingFactorDest OneMinusDstAlpha;
	static const BlendingFactorDest DstColor;
	static const BlendingFactorDest OneMinusDstColor;
	static const BlendingFactorDest SrcAlphaSaturate;
	static const BlendingFactorDest ConstantColor;
	static const BlendingFactorDest ConstantColorExt;
	static const BlendingFactorDest OneMinusConstantColor;
	static const BlendingFactorDest OneMinusConstantColorExt;
	static const BlendingFactorDest ConstantAlpha;
	static const BlendingFactorDest ConstantAlphaExt;
	static const BlendingFactorDest OneMinusConstantAlpha;
	static const BlendingFactorDest OneMinusConstantAlphaExt;
	static const BlendingFactorDest Src1Alpha;
	static const BlendingFactorDest Src1Color;
	static const BlendingFactorDest OneMinusSrc1Color;
	static const BlendingFactorDest OneMinusSrc1Alpha;
	static const BlendingFactorDest One;
OPENGL_ENUM_END

OPENGL_ENUM_START(BlendingFactorSrc)
	static const BlendingFactorSrc Zero;
	static const BlendingFactorSrc SrcColor;
	static const BlendingFactorSrc OneMinusSrcColor;
	static const BlendingFactorSrc SrcAlpha;
	static const BlendingFactorSrc OneMinusSrcAlpha;
	static const BlendingFactorSrc DstAlpha;
	static const BlendingFactorSrc OneMinusDstAlpha;
	static const BlendingFactorSrc DstColor;
	static const BlendingFactorSrc OneMinusDstColor;
	static const BlendingFactorSrc SrcAlphaSaturate;
	static const BlendingFactorSrc ConstantColor;
	static const BlendingFactorSrc ConstantColorExt;
	static const BlendingFactorSrc OneMinusConstantColor;
	static const BlendingFactorSrc OneMinusConstantColorExt;
	static const BlendingFactorSrc ConstantAlpha;
	static const BlendingFactorSrc ConstantAlphaExt;
	static const BlendingFactorSrc OneMinusConstantAlpha;
	static const BlendingFactorSrc OneMinusConstantAlphaExt;
	static const BlendingFactorSrc Src1Alpha;
	static const BlendingFactorSrc Src1Color;
	static const BlendingFactorSrc OneMinusSrc1Color;
	static const BlendingFactorSrc OneMinusSrc1Alpha;
	static const BlendingFactorSrc One;
OPENGL_ENUM_END

OPENGL_ENUM_START(BlitFramebufferFilter)
	static const BlitFramebufferFilter Nearest;
	static const BlitFramebufferFilter Linear;
OPENGL_ENUM_END

OPENGL_ENUM_START(Boolean)
	static const Boolean False;
	static const Boolean True;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferAccess)
	static const BufferAccess ReadOnly;
	static const BufferAccess WriteOnly;
	static const BufferAccess ReadWrite;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferAccessArb)
	static const BufferAccessArb ReadOnly;
	static const BufferAccessArb WriteOnly;
	static const BufferAccessArb ReadWrite;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferAccessMask)
	static const BufferAccessMask MapReadBit;
	static const BufferAccessMask MapWriteBit;
	static const BufferAccessMask MapInvalidateRangeBit;
	static const BufferAccessMask MapInvalidateBufferBit;
	static const BufferAccessMask MapFlushExplicitBit;
	static const BufferAccessMask MapUnsynchronizedBit;
	static const BufferAccessMask MapPersistentBit;
	static const BufferAccessMask MapCoherentBit;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferParameterApple)
	static const BufferParameterApple BufferSerializedModifyApple;
	static const BufferParameterApple BufferFlushingUnmapApple;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferParameterName)
	static const BufferParameterName BufferImmutableStorage;
	static const BufferParameterName BufferStorageFlags;
	static const BufferParameterName BufferSize;
	static const BufferParameterName BufferUsage;
	static const BufferParameterName BufferAccess;
	static const BufferParameterName BufferMapped;
	static const BufferParameterName BufferAccessFlags;
	static const BufferParameterName BufferMapLength;
	static const BufferParameterName BufferMapOffset;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferParameterNameArb)
	static const BufferParameterNameArb BufferSize;
	static const BufferParameterNameArb BufferUsage;
	static const BufferParameterNameArb BufferAccess;
	static const BufferParameterNameArb BufferMapped;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferPointer)
	static const BufferPointer BufferMapPointer;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferPointerNameArb)
	static const BufferPointerNameArb BufferMapPointer;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferRangeTarget)
	static const BufferRangeTarget UniformBuffer;
	static const BufferRangeTarget TransformFeedbackBuffer;
	static const BufferRangeTarget ShaderStorageBuffer;
	static const BufferRangeTarget AtomicCounterBuffer;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferStorageFlags)
	static const BufferStorageFlags None;
	static const BufferStorageFlags MapReadBit;
	static const BufferStorageFlags MapWriteBit;
	static const BufferStorageFlags MapPersistentBit;
	static const BufferStorageFlags MapCoherentBit;
	static const BufferStorageFlags DynamicStorageBit;
	static const BufferStorageFlags ClientStorageBit;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferTarget)
	static const BufferTarget ArrayBuffer;
	static const BufferTarget ElementArrayBuffer;
	static const BufferTarget PixelPackBuffer;
	static const BufferTarget PixelUnpackBuffer;
	static const BufferTarget UniformBuffer;
	static const BufferTarget TextureBuffer;
	static const BufferTarget TransformFeedbackBuffer;
	static const BufferTarget CopyReadBuffer;
	static const BufferTarget CopyWriteBuffer;
	static const BufferTarget DrawIndirectBuffer;
	static const BufferTarget ShaderStorageBuffer;
	static const BufferTarget DispatchIndirectBuffer;
	static const BufferTarget QueryBuffer;
	static const BufferTarget AtomicCounterBuffer;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferTargetArb)
	static const BufferTargetArb ArrayBuffer;
	static const BufferTargetArb ElementArrayBuffer;
	static const BufferTargetArb TextureBuffer;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferUsageArb)
	static const BufferUsageArb StreamDraw;
	static const BufferUsageArb StreamRead;
	static const BufferUsageArb StreamCopy;
	static const BufferUsageArb StaticDraw;
	static const BufferUsageArb StaticRead;
	static const BufferUsageArb StaticCopy;
	static const BufferUsageArb DynamicDraw;
	static const BufferUsageArb DynamicRead;
	static const BufferUsageArb DynamicCopy;
OPENGL_ENUM_END

OPENGL_ENUM_START(BufferUsageHint)
	static const BufferUsageHint StreamDraw;
	static const BufferUsageHint StreamRead;
	static const BufferUsageHint StreamCopy;
	static const BufferUsageHint StaticDraw;
	static const BufferUsageHint StaticRead;
	static const BufferUsageHint StaticCopy;
	static const BufferUsageHint DynamicDraw;
	static const BufferUsageHint DynamicRead;
	static const BufferUsageHint DynamicCopy;
OPENGL_ENUM_END

OPENGL_ENUM_START(ClampColorMode)
	static const ClampColorMode False;
	static const ClampColorMode FixedOnly;
	static const ClampColorMode True;
OPENGL_ENUM_END

OPENGL_ENUM_START(ClampColorTarget)
	static const ClampColorTarget ClampVertexColor;
	static const ClampColorTarget ClampFragmentColor;
	static const ClampColorTarget ClampReadColor;
OPENGL_ENUM_END

OPENGL_ENUM_START(ClearBuffer)
	static const ClearBuffer Color;
	static const ClearBuffer Depth;
	static const ClearBuffer Stencil;
OPENGL_ENUM_END

OPENGL_ENUM_START(ClearBufferCombined)
	static const ClearBufferCombined DepthStencil;
OPENGL_ENUM_END

OPENGL_ENUM_START(ClearBufferMask)
	static const ClearBufferMask None;
	static const ClearBufferMask DepthBufferBit;
	static const ClearBufferMask AccumBufferBit;
	static const ClearBufferMask StencilBufferBit;
	static const ClearBufferMask ColorBufferBit;
	static const ClearBufferMask CoverageBufferBitNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(ClientAttribMask)
	static const ClientAttribMask ClientPixelStoreBit;
	static const ClientAttribMask ClientVertexArrayBit;
	static const ClientAttribMask ClientAllAttribBits;
OPENGL_ENUM_END

OPENGL_ENUM_START(ClientWaitSyncFlags)
	static const ClientWaitSyncFlags None;
	static const ClientWaitSyncFlags SyncFlushCommandsBit;
OPENGL_ENUM_END

OPENGL_ENUM_START(ClipControl)
OPENGL_ENUM_END

OPENGL_ENUM_START(ClipDepthMode)
	static const ClipDepthMode NegativeOneToOne;
	static const ClipDepthMode ZeroToOne;
OPENGL_ENUM_END

OPENGL_ENUM_START(ClipOrigin)
	static const ClipOrigin LowerLeft;
	static const ClipOrigin UpperLeft;
OPENGL_ENUM_END

OPENGL_ENUM_START(ClipPlaneName)
	static const ClipPlaneName ClipDistance0;
	static const ClipPlaneName ClipPlane0;
	static const ClipPlaneName ClipDistance1;
	static const ClipPlaneName ClipPlane1;
	static const ClipPlaneName ClipDistance2;
	static const ClipPlaneName ClipPlane2;
	static const ClipPlaneName ClipDistance3;
	static const ClipPlaneName ClipPlane3;
	static const ClipPlaneName ClipDistance4;
	static const ClipPlaneName ClipPlane4;
	static const ClipPlaneName ClipDistance5;
	static const ClipPlaneName ClipPlane5;
	static const ClipPlaneName ClipDistance6;
	static const ClipPlaneName ClipDistance7;
OPENGL_ENUM_END

OPENGL_ENUM_START(ColorMaterialFace)
	static const ColorMaterialFace Front;
	static const ColorMaterialFace Back;
	static const ColorMaterialFace FrontAndBack;
OPENGL_ENUM_END

OPENGL_ENUM_START(ColorMaterialParameter)
	static const ColorMaterialParameter Ambient;
	static const ColorMaterialParameter Diffuse;
	static const ColorMaterialParameter Specular;
	static const ColorMaterialParameter Emission;
	static const ColorMaterialParameter AmbientAndDiffuse;
OPENGL_ENUM_END

OPENGL_ENUM_START(ColorPointerType)
	static const ColorPointerType Byte;
	static const ColorPointerType UnsignedByte;
	static const ColorPointerType Short;
	static const ColorPointerType UnsignedShort;
	static const ColorPointerType Int;
	static const ColorPointerType UnsignedInt;
	static const ColorPointerType Float;
	static const ColorPointerType Double;
	static const ColorPointerType HalfFloat;
	static const ColorPointerType UnsignedInt2101010Rev;
	static const ColorPointerType Int2101010Rev;
OPENGL_ENUM_END

OPENGL_ENUM_START(ColorTableParameterPName)
	static const ColorTableParameterPName ColorTableScale;
	static const ColorTableParameterPName ColorTableBias;
OPENGL_ENUM_END

OPENGL_ENUM_START(ColorTableParameterPNameSgi)
	static const ColorTableParameterPNameSgi ColorTableScale;
	static const ColorTableParameterPNameSgi ColorTableScaleSgi;
	static const ColorTableParameterPNameSgi ColorTableBias;
	static const ColorTableParameterPNameSgi ColorTableBiasSgi;
OPENGL_ENUM_END

OPENGL_ENUM_START(ColorTableTarget)
	static const ColorTableTarget ColorTable;
	static const ColorTableTarget PostConvolutionColorTable;
	static const ColorTableTarget PostColorMatrixColorTable;
	static const ColorTableTarget ProxyColorTable;
	static const ColorTableTarget ProxyPostConvolutionColorTable;
	static const ColorTableTarget ProxyPostColorMatrixColorTable;
OPENGL_ENUM_END

OPENGL_ENUM_START(ColorTableTargetSgi)
	static const ColorTableTargetSgi TextureColorTableSgi;
	static const ColorTableTargetSgi ProxyTextureColorTableSgi;
	static const ColorTableTargetSgi ColorTable;
	static const ColorTableTargetSgi ColorTableSgi;
	static const ColorTableTargetSgi PostConvolutionColorTable;
	static const ColorTableTargetSgi PostConvolutionColorTableSgi;
	static const ColorTableTargetSgi PostColorMatrixColorTable;
	static const ColorTableTargetSgi PostColorMatrixColorTableSgi;
	static const ColorTableTargetSgi ProxyColorTable;
	static const ColorTableTargetSgi ProxyColorTableSgi;
	static const ColorTableTargetSgi ProxyPostConvolutionColorTable;
	static const ColorTableTargetSgi ProxyPostConvolutionColorTableSgi;
	static const ColorTableTargetSgi ProxyPostColorMatrixColorTable;
	static const ColorTableTargetSgi ProxyPostColorMatrixColorTableSgi;
OPENGL_ENUM_END

OPENGL_ENUM_START(ConditionalRenderType)
	static const ConditionalRenderType QueryWait;
	static const ConditionalRenderType QueryNoWait;
	static const ConditionalRenderType QueryByRegionWait;
	static const ConditionalRenderType QueryByRegionNoWait;
	static const ConditionalRenderType QueryWaitInverted;
	static const ConditionalRenderType QueryNoWaitInverted;
	static const ConditionalRenderType QueryByRegionWaitInverted;
	static const ConditionalRenderType QueryByRegionNoWaitInverted;
OPENGL_ENUM_END

OPENGL_ENUM_START(ContextFlagMask)
	static const ContextFlagMask ContextFlagForwardCompatibleBit;
	static const ContextFlagMask ContextFlagDebugBit;
	static const ContextFlagMask ContextFlagDebugBitKhr;
	static const ContextFlagMask ContextFlagRobustAccessBitArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(ContextProfileMask)
	static const ContextProfileMask ContextCoreProfileBit;
	static const ContextProfileMask ContextCompatibilityProfileBit;
OPENGL_ENUM_END

OPENGL_ENUM_START(ConvolutionBorderModeExt)
	static const ConvolutionBorderModeExt Reduce;
	static const ConvolutionBorderModeExt ReduceExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ConvolutionParameter)
	static const ConvolutionParameter ConvolutionBorderMode;
	static const ConvolutionParameter ConvolutionFilterScale;
	static const ConvolutionParameter ConvolutionFilterBias;
OPENGL_ENUM_END

OPENGL_ENUM_START(ConvolutionParameterExt)
	static const ConvolutionParameterExt ConvolutionBorderMode;
	static const ConvolutionParameterExt ConvolutionBorderModeExt;
	static const ConvolutionParameterExt ConvolutionFilterScale;
	static const ConvolutionParameterExt ConvolutionFilterScaleExt;
	static const ConvolutionParameterExt ConvolutionFilterBias;
	static const ConvolutionParameterExt ConvolutionFilterBiasExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ConvolutionParameterValue)
	static const ConvolutionParameterValue Reduce;
	static const ConvolutionParameterValue ConstantBorder;
	static const ConvolutionParameterValue ReplicateBorder;
OPENGL_ENUM_END

OPENGL_ENUM_START(ConvolutionTarget)
	static const ConvolutionTarget Convolution1D;
	static const ConvolutionTarget Convolution2D;
	static const ConvolutionTarget Separable2D;
OPENGL_ENUM_END

OPENGL_ENUM_START(ConvolutionTargetExt)
	static const ConvolutionTargetExt Convolution1D;
	static const ConvolutionTargetExt Convolution1DExt;
	static const ConvolutionTargetExt Convolution2D;
	static const ConvolutionTargetExt Convolution2DExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(CullFaceMode)
	static const CullFaceMode Front;
	static const CullFaceMode Back;
	static const CullFaceMode FrontAndBack;
OPENGL_ENUM_END

OPENGL_ENUM_START(DataType)
OPENGL_ENUM_END

OPENGL_ENUM_START(DebugSeverity)
	static const DebugSeverity DebugSeverityNotification;
	static const DebugSeverity DebugSeverityHigh;
	static const DebugSeverity DebugSeverityMedium;
	static const DebugSeverity DebugSeverityLow;
OPENGL_ENUM_END

OPENGL_ENUM_START(DebugSeverityControl)
	static const DebugSeverityControl DontCare;
	static const DebugSeverityControl DebugSeverityNotification;
	static const DebugSeverityControl DebugSeverityHigh;
	static const DebugSeverityControl DebugSeverityMedium;
	static const DebugSeverityControl DebugSeverityLow;
OPENGL_ENUM_END

OPENGL_ENUM_START(DebugSource)
	static const DebugSource DebugSourceApi;
	static const DebugSource DebugSourceWindowSystem;
	static const DebugSource DebugSourceShaderCompiler;
	static const DebugSource DebugSourceThirdParty;
	static const DebugSource DebugSourceApplication;
	static const DebugSource DebugSourceOther;
OPENGL_ENUM_END

OPENGL_ENUM_START(DebugSourceControl)
	static const DebugSourceControl DontCare;
	static const DebugSourceControl DebugSourceApi;
	static const DebugSourceControl DebugSourceWindowSystem;
	static const DebugSourceControl DebugSourceShaderCompiler;
	static const DebugSourceControl DebugSourceThirdParty;
	static const DebugSourceControl DebugSourceApplication;
	static const DebugSourceControl DebugSourceOther;
OPENGL_ENUM_END

OPENGL_ENUM_START(DebugSourceExternal)
	static const DebugSourceExternal DebugSourceThirdParty;
	static const DebugSourceExternal DebugSourceApplication;
OPENGL_ENUM_END

OPENGL_ENUM_START(DebugType)
	static const DebugType DebugTypeError;
	static const DebugType DebugTypeDeprecatedBehavior;
	static const DebugType DebugTypeUndefinedBehavior;
	static const DebugType DebugTypePortability;
	static const DebugType DebugTypePerformance;
	static const DebugType DebugTypeOther;
	static const DebugType DebugTypeMarker;
	static const DebugType DebugTypePushGroup;
	static const DebugType DebugTypePopGroup;
OPENGL_ENUM_END

OPENGL_ENUM_START(DebugTypeControl)
	static const DebugTypeControl DontCare;
	static const DebugTypeControl DebugTypeError;
	static const DebugTypeControl DebugTypeDeprecatedBehavior;
	static const DebugTypeControl DebugTypeUndefinedBehavior;
	static const DebugTypeControl DebugTypePortability;
	static const DebugTypeControl DebugTypePerformance;
	static const DebugTypeControl DebugTypeOther;
	static const DebugTypeControl DebugTypeMarker;
	static const DebugTypeControl DebugTypePushGroup;
	static const DebugTypeControl DebugTypePopGroup;
OPENGL_ENUM_END

OPENGL_ENUM_START(DepthFunction)
	static const DepthFunction Never;
	static const DepthFunction Less;
	static const DepthFunction Equal;
	static const DepthFunction Lequal;
	static const DepthFunction Greater;
	static const DepthFunction Notequal;
	static const DepthFunction Gequal;
	static const DepthFunction Always;
OPENGL_ENUM_END

OPENGL_ENUM_START(DrawBufferMode)
	static const DrawBufferMode None;
	static const DrawBufferMode NoneOes;
	static const DrawBufferMode FrontLeft;
	static const DrawBufferMode FrontRight;
	static const DrawBufferMode BackLeft;
	static const DrawBufferMode BackRight;
	static const DrawBufferMode Front;
	static const DrawBufferMode Back;
	static const DrawBufferMode Left;
	static const DrawBufferMode Right;
	static const DrawBufferMode FrontAndBack;
	static const DrawBufferMode Aux0;
	static const DrawBufferMode Aux1;
	static const DrawBufferMode Aux2;
	static const DrawBufferMode Aux3;
	static const DrawBufferMode ColorAttachment0;
	static const DrawBufferMode ColorAttachment1;
	static const DrawBufferMode ColorAttachment2;
	static const DrawBufferMode ColorAttachment3;
	static const DrawBufferMode ColorAttachment4;
	static const DrawBufferMode ColorAttachment5;
	static const DrawBufferMode ColorAttachment6;
	static const DrawBufferMode ColorAttachment7;
	static const DrawBufferMode ColorAttachment8;
	static const DrawBufferMode ColorAttachment9;
	static const DrawBufferMode ColorAttachment10;
	static const DrawBufferMode ColorAttachment11;
	static const DrawBufferMode ColorAttachment12;
	static const DrawBufferMode ColorAttachment13;
	static const DrawBufferMode ColorAttachment14;
	static const DrawBufferMode ColorAttachment15;
OPENGL_ENUM_END

OPENGL_ENUM_START(DrawBuffersEnum)
	static const DrawBuffersEnum None;
	static const DrawBuffersEnum FrontLeft;
	static const DrawBuffersEnum FrontRight;
	static const DrawBuffersEnum BackLeft;
	static const DrawBuffersEnum BackRight;
	static const DrawBuffersEnum Aux0;
	static const DrawBuffersEnum Aux1;
	static const DrawBuffersEnum Aux2;
	static const DrawBuffersEnum Aux3;
	static const DrawBuffersEnum ColorAttachment0;
	static const DrawBuffersEnum ColorAttachment1;
	static const DrawBuffersEnum ColorAttachment2;
	static const DrawBuffersEnum ColorAttachment3;
	static const DrawBuffersEnum ColorAttachment4;
	static const DrawBuffersEnum ColorAttachment5;
	static const DrawBuffersEnum ColorAttachment6;
	static const DrawBuffersEnum ColorAttachment7;
	static const DrawBuffersEnum ColorAttachment8;
	static const DrawBuffersEnum ColorAttachment9;
	static const DrawBuffersEnum ColorAttachment10;
	static const DrawBuffersEnum ColorAttachment11;
	static const DrawBuffersEnum ColorAttachment12;
	static const DrawBuffersEnum ColorAttachment13;
	static const DrawBuffersEnum ColorAttachment14;
	static const DrawBuffersEnum ColorAttachment15;
OPENGL_ENUM_END

OPENGL_ENUM_START(DrawElementsType)
	static const DrawElementsType UnsignedByte;
	static const DrawElementsType UnsignedShort;
	static const DrawElementsType UnsignedInt;
OPENGL_ENUM_END

OPENGL_ENUM_START(EnableCap)
	static const EnableCap PointSmooth;
	static const EnableCap LineSmooth;
	static const EnableCap LineStipple;
	static const EnableCap PolygonSmooth;
	static const EnableCap PolygonStipple;
	static const EnableCap CullFace;
	static const EnableCap Lighting;
	static const EnableCap ColorMaterial;
	static const EnableCap Fog;
	static const EnableCap DepthTest;
	static const EnableCap StencilTest;
	static const EnableCap Normalize;
	static const EnableCap AlphaTest;
	static const EnableCap Dither;
	static const EnableCap Blend;
	static const EnableCap IndexLogicOp;
	static const EnableCap ColorLogicOp;
	static const EnableCap ScissorTest;
	static const EnableCap TextureGenS;
	static const EnableCap TextureGenT;
	static const EnableCap TextureGenR;
	static const EnableCap TextureGenQ;
	static const EnableCap AutoNormal;
	static const EnableCap Map1Color4;
	static const EnableCap Map1Index;
	static const EnableCap Map1Normal;
	static const EnableCap Map1TextureCoord1;
	static const EnableCap Map1TextureCoord2;
	static const EnableCap Map1TextureCoord3;
	static const EnableCap Map1TextureCoord4;
	static const EnableCap Map1Vertex3;
	static const EnableCap Map1Vertex4;
	static const EnableCap Map2Color4;
	static const EnableCap Map2Index;
	static const EnableCap Map2Normal;
	static const EnableCap Map2TextureCoord1;
	static const EnableCap Map2TextureCoord2;
	static const EnableCap Map2TextureCoord3;
	static const EnableCap Map2TextureCoord4;
	static const EnableCap Map2Vertex3;
	static const EnableCap Map2Vertex4;
	static const EnableCap Texture1D;
	static const EnableCap Texture2D;
	static const EnableCap PolygonOffsetPoint;
	static const EnableCap PolygonOffsetLine;
	static const EnableCap ClipDistance0;
	static const EnableCap ClipPlane0;
	static const EnableCap ClipDistance1;
	static const EnableCap ClipPlane1;
	static const EnableCap ClipDistance2;
	static const EnableCap ClipPlane2;
	static const EnableCap ClipDistance3;
	static const EnableCap ClipPlane3;
	static const EnableCap ClipDistance4;
	static const EnableCap ClipPlane4;
	static const EnableCap ClipDistance5;
	static const EnableCap ClipPlane5;
	static const EnableCap ClipDistance6;
	static const EnableCap ClipDistance7;
	static const EnableCap Light0;
	static const EnableCap Light1;
	static const EnableCap Light2;
	static const EnableCap Light3;
	static const EnableCap Light4;
	static const EnableCap Light5;
	static const EnableCap Light6;
	static const EnableCap Light7;
	static const EnableCap Convolution1D;
	static const EnableCap Convolution1DExt;
	static const EnableCap Convolution2D;
	static const EnableCap Convolution2DExt;
	static const EnableCap Separable2D;
	static const EnableCap Separable2DExt;
	static const EnableCap Histogram;
	static const EnableCap HistogramExt;
	static const EnableCap MinmaxExt;
	static const EnableCap PolygonOffsetFill;
	static const EnableCap RescaleNormal;
	static const EnableCap RescaleNormalExt;
	static const EnableCap Texture3DExt;
	static const EnableCap VertexArray;
	static const EnableCap NormalArray;
	static const EnableCap ColorArray;
	static const EnableCap IndexArray;
	static const EnableCap TextureCoordArray;
	static const EnableCap EdgeFlagArray;
	static const EnableCap InterlaceSgix;
	static const EnableCap Multisample;
	static const EnableCap MultisampleSgis;
	static const EnableCap SampleAlphaToCoverage;
	static const EnableCap SampleAlphaToMaskSgis;
	static const EnableCap SampleAlphaToOne;
	static const EnableCap SampleAlphaToOneSgis;
	static const EnableCap SampleCoverage;
	static const EnableCap SampleMaskSgis;
	static const EnableCap TextureColorTableSgi;
	static const EnableCap ColorTable;
	static const EnableCap ColorTableSgi;
	static const EnableCap PostConvolutionColorTable;
	static const EnableCap PostConvolutionColorTableSgi;
	static const EnableCap PostColorMatrixColorTable;
	static const EnableCap PostColorMatrixColorTableSgi;
	static const EnableCap Texture4DSgis;
	static const EnableCap PixelTexGenSgix;
	static const EnableCap SpriteSgix;
	static const EnableCap ReferencePlaneSgix;
	static const EnableCap IrInstrument1Sgix;
	static const EnableCap CalligraphicFragmentSgix;
	static const EnableCap FramezoomSgix;
	static const EnableCap FogOffsetSgix;
	static const EnableCap SharedTexturePaletteExt;
	static const EnableCap DebugOutputSynchronous;
	static const EnableCap AsyncHistogramSgix;
	static const EnableCap PixelTextureSgis;
	static const EnableCap AsyncTexImageSgix;
	static const EnableCap AsyncDrawPixelsSgix;
	static const EnableCap AsyncReadPixelsSgix;
	static const EnableCap FragmentLightingSgix;
	static const EnableCap FragmentColorMaterialSgix;
	static const EnableCap FragmentLight0Sgix;
	static const EnableCap FragmentLight1Sgix;
	static const EnableCap FragmentLight2Sgix;
	static const EnableCap FragmentLight3Sgix;
	static const EnableCap FragmentLight4Sgix;
	static const EnableCap FragmentLight5Sgix;
	static const EnableCap FragmentLight6Sgix;
	static const EnableCap FragmentLight7Sgix;
	static const EnableCap FogCoordArray;
	static const EnableCap ColorSum;
	static const EnableCap SecondaryColorArray;
	static const EnableCap TextureRectangle;
	static const EnableCap TextureCubeMap;
	static const EnableCap ProgramPointSize;
	static const EnableCap VertexProgramPointSize;
	static const EnableCap VertexProgramTwoSide;
	static const EnableCap DepthClamp;
	static const EnableCap TextureCubeMapSeamless;
	static const EnableCap PointSprite;
	static const EnableCap SampleShading;
	static const EnableCap RasterizerDiscard;
	static const EnableCap PrimitiveRestartFixedIndex;
	static const EnableCap FramebufferSrgb;
	static const EnableCap SampleMask;
	static const EnableCap PrimitiveRestart;
	static const EnableCap DebugOutput;
OPENGL_ENUM_END

OPENGL_ENUM_START(ErrorCode)
	static const ErrorCode NoError;
	static const ErrorCode InvalidEnum;
	static const ErrorCode InvalidValue;
	static const ErrorCode InvalidOperation;
	static const ErrorCode StackOverflow;
	static const ErrorCode StackUnderflow;
	static const ErrorCode OutOfMemory;
	static const ErrorCode InvalidFramebufferOperation;
	static const ErrorCode InvalidFramebufferOperationExt;
	static const ErrorCode InvalidFramebufferOperationOes;
	static const ErrorCode ContextLost;
	static const ErrorCode TableTooLarge;
	static const ErrorCode TableTooLargeExt;
	static const ErrorCode TextureTooLargeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(Ext422Pixels)
	static const Ext422Pixels Gl422Ext;
	static const Ext422Pixels Gl422RevExt;
	static const Ext422Pixels Gl422AverageExt;
	static const Ext422Pixels Gl422RevAverageExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtAbgr)
	static const ExtAbgr AbgrExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtBgra)
	static const ExtBgra BgrExt;
	static const ExtBgra BgraExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtBindableUniform)
	static const ExtBindableUniform MaxVertexBindableUniformsExt;
	static const ExtBindableUniform MaxFragmentBindableUniformsExt;
	static const ExtBindableUniform MaxGeometryBindableUniformsExt;
	static const ExtBindableUniform MaxBindableUniformSizeExt;
	static const ExtBindableUniform UniformBufferExt;
	static const ExtBindableUniform UniformBufferBindingExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtBlendColor)
	static const ExtBlendColor ConstantColorExt;
	static const ExtBlendColor OneMinusConstantColorExt;
	static const ExtBlendColor ConstantAlphaExt;
	static const ExtBlendColor OneMinusConstantAlphaExt;
	static const ExtBlendColor BlendColorExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtBlendEquationSeparate)
	static const ExtBlendEquationSeparate BlendEquationRgbExt;
	static const ExtBlendEquationSeparate BlendEquationAlphaExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtBlendFuncSeparate)
	static const ExtBlendFuncSeparate BlendDstRgbExt;
	static const ExtBlendFuncSeparate BlendSrcRgbExt;
	static const ExtBlendFuncSeparate BlendDstAlphaExt;
	static const ExtBlendFuncSeparate BlendSrcAlphaExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtBlendLogicOp)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtBlendMinmax)
	static const ExtBlendMinmax FuncAddExt;
	static const ExtBlendMinmax MinExt;
	static const ExtBlendMinmax MaxExt;
	static const ExtBlendMinmax BlendEquationExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtBlendSubtract)
	static const ExtBlendSubtract FuncSubtractExt;
	static const ExtBlendSubtract FuncReverseSubtractExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtClipVolumeHint)
	static const ExtClipVolumeHint ClipVolumeClippingHintExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtCmyka)
	static const ExtCmyka CmykExt;
	static const ExtCmyka CmykaExt;
	static const ExtCmyka PackCmykHintExt;
	static const ExtCmyka UnpackCmykHintExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtColorSubtable)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtCompiledVertexArray)
	static const ExtCompiledVertexArray ArrayElementLockFirstExt;
	static const ExtCompiledVertexArray ArrayElementLockCountExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtConvolution)
	static const ExtConvolution Convolution1DExt;
	static const ExtConvolution Convolution2DExt;
	static const ExtConvolution Separable2DExt;
	static const ExtConvolution ConvolutionBorderModeExt;
	static const ExtConvolution ConvolutionFilterScaleExt;
	static const ExtConvolution ConvolutionFilterBiasExt;
	static const ExtConvolution ReduceExt;
	static const ExtConvolution ConvolutionFormatExt;
	static const ExtConvolution ConvolutionWidthExt;
	static const ExtConvolution ConvolutionHeightExt;
	static const ExtConvolution MaxConvolutionWidthExt;
	static const ExtConvolution MaxConvolutionHeightExt;
	static const ExtConvolution PostConvolutionRedScaleExt;
	static const ExtConvolution PostConvolutionGreenScaleExt;
	static const ExtConvolution PostConvolutionBlueScaleExt;
	static const ExtConvolution PostConvolutionAlphaScaleExt;
	static const ExtConvolution PostConvolutionRedBiasExt;
	static const ExtConvolution PostConvolutionGreenBiasExt;
	static const ExtConvolution PostConvolutionBlueBiasExt;
	static const ExtConvolution PostConvolutionAlphaBiasExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtCoordinateFrame)
	static const ExtCoordinateFrame TangentArrayExt;
	static const ExtCoordinateFrame BinormalArrayExt;
	static const ExtCoordinateFrame CurrentTangentExt;
	static const ExtCoordinateFrame CurrentBinormalExt;
	static const ExtCoordinateFrame TangentArrayTypeExt;
	static const ExtCoordinateFrame TangentArrayStrideExt;
	static const ExtCoordinateFrame BinormalArrayTypeExt;
	static const ExtCoordinateFrame BinormalArrayStrideExt;
	static const ExtCoordinateFrame TangentArrayPointerExt;
	static const ExtCoordinateFrame BinormalArrayPointerExt;
	static const ExtCoordinateFrame Map1TangentExt;
	static const ExtCoordinateFrame Map2TangentExt;
	static const ExtCoordinateFrame Map1BinormalExt;
	static const ExtCoordinateFrame Map2BinormalExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtCopyTexture)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtCullVertex)
	static const ExtCullVertex CullVertexExt;
	static const ExtCullVertex CullVertexEyePositionExt;
	static const ExtCullVertex CullVertexObjectPositionExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtDebugLabel)
	static const ExtDebugLabel Sampler;
	static const ExtDebugLabel ProgramPipelineObjectExt;
	static const ExtDebugLabel ProgramObjectExt;
	static const ExtDebugLabel ShaderObjectExt;
	static const ExtDebugLabel TransformFeedback;
	static const ExtDebugLabel BufferObjectExt;
	static const ExtDebugLabel QueryObjectExt;
	static const ExtDebugLabel VertexArrayObjectExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtDebugMarker)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtDepthBoundsTest)
	static const ExtDepthBoundsTest DepthBoundsTestExt;
	static const ExtDepthBoundsTest DepthBoundsExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtDirectStateAccess)
	static const ExtDirectStateAccess ProgramMatrixExt;
	static const ExtDirectStateAccess TransposeProgramMatrixExt;
	static const ExtDirectStateAccess ProgramMatrixStackDepthExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtDrawBuffers2)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtDrawInstanced)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtDrawRangeElements)
	static const ExtDrawRangeElements MaxElementsVerticesExt;
	static const ExtDrawRangeElements MaxElementsIndicesExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtFogCoord)
	static const ExtFogCoord FogCoordinateSourceExt;
	static const ExtFogCoord FogCoordinateExt;
	static const ExtFogCoord FragmentDepthExt;
	static const ExtFogCoord CurrentFogCoordinateExt;
	static const ExtFogCoord FogCoordinateArrayTypeExt;
	static const ExtFogCoord FogCoordinateArrayStrideExt;
	static const ExtFogCoord FogCoordinateArrayPointerExt;
	static const ExtFogCoord FogCoordinateArrayExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtFramebufferBlit)
	static const ExtFramebufferBlit DrawFramebufferBindingExt;
	static const ExtFramebufferBlit ReadFramebufferExt;
	static const ExtFramebufferBlit DrawFramebufferExt;
	static const ExtFramebufferBlit ReadFramebufferBindingExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtFramebufferMultisample)
	static const ExtFramebufferMultisample RenderbufferSamplesExt;
	static const ExtFramebufferMultisample FramebufferIncompleteMultisampleExt;
	static const ExtFramebufferMultisample MaxSamplesExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtFramebufferMultisampleBlitScaled)
	static const ExtFramebufferMultisampleBlitScaled ScaledResolveFastestExt;
	static const ExtFramebufferMultisampleBlitScaled ScaledResolveNicestExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtFramebufferObject)
	static const ExtFramebufferObject InvalidFramebufferOperationExt;
	static const ExtFramebufferObject MaxRenderbufferSizeExt;
	static const ExtFramebufferObject FramebufferBindingExt;
	static const ExtFramebufferObject RenderbufferBindingExt;
	static const ExtFramebufferObject FramebufferAttachmentObjectTypeExt;
	static const ExtFramebufferObject FramebufferAttachmentObjectNameExt;
	static const ExtFramebufferObject FramebufferAttachmentTextureLevelExt;
	static const ExtFramebufferObject FramebufferAttachmentTextureCubeMapFaceExt;
	static const ExtFramebufferObject FramebufferAttachmentTexture3DZoffsetExt;
	static const ExtFramebufferObject FramebufferCompleteExt;
	static const ExtFramebufferObject FramebufferIncompleteAttachmentExt;
	static const ExtFramebufferObject FramebufferIncompleteMissingAttachmentExt;
	static const ExtFramebufferObject FramebufferIncompleteDimensionsExt;
	static const ExtFramebufferObject FramebufferIncompleteFormatsExt;
	static const ExtFramebufferObject FramebufferIncompleteDrawBufferExt;
	static const ExtFramebufferObject FramebufferIncompleteReadBufferExt;
	static const ExtFramebufferObject FramebufferUnsupportedExt;
	static const ExtFramebufferObject MaxColorAttachmentsExt;
	static const ExtFramebufferObject ColorAttachment0Ext;
	static const ExtFramebufferObject ColorAttachment1Ext;
	static const ExtFramebufferObject ColorAttachment2Ext;
	static const ExtFramebufferObject ColorAttachment3Ext;
	static const ExtFramebufferObject ColorAttachment4Ext;
	static const ExtFramebufferObject ColorAttachment5Ext;
	static const ExtFramebufferObject ColorAttachment6Ext;
	static const ExtFramebufferObject ColorAttachment7Ext;
	static const ExtFramebufferObject ColorAttachment8Ext;
	static const ExtFramebufferObject ColorAttachment9Ext;
	static const ExtFramebufferObject ColorAttachment10Ext;
	static const ExtFramebufferObject ColorAttachment11Ext;
	static const ExtFramebufferObject ColorAttachment12Ext;
	static const ExtFramebufferObject ColorAttachment13Ext;
	static const ExtFramebufferObject ColorAttachment14Ext;
	static const ExtFramebufferObject ColorAttachment15Ext;
	static const ExtFramebufferObject DepthAttachmentExt;
	static const ExtFramebufferObject StencilAttachmentExt;
	static const ExtFramebufferObject FramebufferExt;
	static const ExtFramebufferObject RenderbufferExt;
	static const ExtFramebufferObject RenderbufferWidthExt;
	static const ExtFramebufferObject RenderbufferHeightExt;
	static const ExtFramebufferObject RenderbufferInternalFormatExt;
	static const ExtFramebufferObject StencilIndex1Ext;
	static const ExtFramebufferObject StencilIndex4Ext;
	static const ExtFramebufferObject StencilIndex8Ext;
	static const ExtFramebufferObject StencilIndex16Ext;
	static const ExtFramebufferObject RenderbufferRedSizeExt;
	static const ExtFramebufferObject RenderbufferGreenSizeExt;
	static const ExtFramebufferObject RenderbufferBlueSizeExt;
	static const ExtFramebufferObject RenderbufferAlphaSizeExt;
	static const ExtFramebufferObject RenderbufferDepthSizeExt;
	static const ExtFramebufferObject RenderbufferStencilSizeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtFramebufferSrgb)
	static const ExtFramebufferSrgb FramebufferSrgbExt;
	static const ExtFramebufferSrgb FramebufferSrgbCapableExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtGeometryShader4)
	static const ExtGeometryShader4 LinesAdjacencyExt;
	static const ExtGeometryShader4 LineStripAdjacencyExt;
	static const ExtGeometryShader4 TrianglesAdjacencyExt;
	static const ExtGeometryShader4 TriangleStripAdjacencyExt;
	static const ExtGeometryShader4 ProgramPointSizeExt;
	static const ExtGeometryShader4 MaxVaryingComponentsExt;
	static const ExtGeometryShader4 MaxGeometryTextureImageUnitsExt;
	static const ExtGeometryShader4 FramebufferAttachmentTextureLayerExt;
	static const ExtGeometryShader4 FramebufferAttachmentLayeredExt;
	static const ExtGeometryShader4 FramebufferIncompleteLayerTargetsExt;
	static const ExtGeometryShader4 FramebufferIncompleteLayerCountExt;
	static const ExtGeometryShader4 GeometryShaderExt;
	static const ExtGeometryShader4 GeometryVerticesOutExt;
	static const ExtGeometryShader4 GeometryInputTypeExt;
	static const ExtGeometryShader4 GeometryOutputTypeExt;
	static const ExtGeometryShader4 MaxGeometryVaryingComponentsExt;
	static const ExtGeometryShader4 MaxVertexVaryingComponentsExt;
	static const ExtGeometryShader4 MaxGeometryUniformComponentsExt;
	static const ExtGeometryShader4 MaxGeometryOutputVerticesExt;
	static const ExtGeometryShader4 MaxGeometryTotalOutputComponentsExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtGpuProgramParameters)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtGpuShader4)
	static const ExtGpuShader4 VertexAttribArrayIntegerExt;
	static const ExtGpuShader4 MinProgramTexelOffsetExt;
	static const ExtGpuShader4 MaxProgramTexelOffsetExt;
	static const ExtGpuShader4 Sampler1DArrayExt;
	static const ExtGpuShader4 Sampler2DArrayExt;
	static const ExtGpuShader4 SamplerBufferExt;
	static const ExtGpuShader4 Sampler1DArrayShadowExt;
	static const ExtGpuShader4 Sampler2DArrayShadowExt;
	static const ExtGpuShader4 SamplerCubeShadowExt;
	static const ExtGpuShader4 UnsignedIntVec2Ext;
	static const ExtGpuShader4 UnsignedIntVec3Ext;
	static const ExtGpuShader4 UnsignedIntVec4Ext;
	static const ExtGpuShader4 IntSampler1DExt;
	static const ExtGpuShader4 IntSampler2DExt;
	static const ExtGpuShader4 IntSampler3DExt;
	static const ExtGpuShader4 IntSamplerCubeExt;
	static const ExtGpuShader4 IntSampler2DRectExt;
	static const ExtGpuShader4 IntSampler1DArrayExt;
	static const ExtGpuShader4 IntSampler2DArrayExt;
	static const ExtGpuShader4 IntSamplerBufferExt;
	static const ExtGpuShader4 UnsignedIntSampler1DExt;
	static const ExtGpuShader4 UnsignedIntSampler2DExt;
	static const ExtGpuShader4 UnsignedIntSampler3DExt;
	static const ExtGpuShader4 UnsignedIntSamplerCubeExt;
	static const ExtGpuShader4 UnsignedIntSampler2DRectExt;
	static const ExtGpuShader4 UnsignedIntSampler1DArrayExt;
	static const ExtGpuShader4 UnsignedIntSampler2DArrayExt;
	static const ExtGpuShader4 UnsignedIntSamplerBufferExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtHistogram)
	static const ExtHistogram HistogramExt;
	static const ExtHistogram ProxyHistogramExt;
	static const ExtHistogram HistogramWidthExt;
	static const ExtHistogram HistogramFormatExt;
	static const ExtHistogram HistogramRedSizeExt;
	static const ExtHistogram HistogramGreenSizeExt;
	static const ExtHistogram HistogramBlueSizeExt;
	static const ExtHistogram HistogramAlphaSizeExt;
	static const ExtHistogram HistogramLuminanceSizeExt;
	static const ExtHistogram HistogramSinkExt;
	static const ExtHistogram MinmaxExt;
	static const ExtHistogram MinmaxFormatExt;
	static const ExtHistogram MinmaxSinkExt;
	static const ExtHistogram TableTooLargeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtIndexArrayFormats)
	static const ExtIndexArrayFormats IuiV2fExt;
	static const ExtIndexArrayFormats IuiV3fExt;
	static const ExtIndexArrayFormats IuiN3fV2fExt;
	static const ExtIndexArrayFormats IuiN3fV3fExt;
	static const ExtIndexArrayFormats T2fIuiV2fExt;
	static const ExtIndexArrayFormats T2fIuiV3fExt;
	static const ExtIndexArrayFormats T2fIuiN3fV2fExt;
	static const ExtIndexArrayFormats T2fIuiN3fV3fExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtIndexFunc)
	static const ExtIndexFunc IndexTestExt;
	static const ExtIndexFunc IndexTestFuncExt;
	static const ExtIndexFunc IndexTestRefExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtIndexMaterial)
	static const ExtIndexMaterial IndexMaterialExt;
	static const ExtIndexMaterial IndexMaterialParameterExt;
	static const ExtIndexMaterial IndexMaterialFaceExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtIndexTexture)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtLightTexture)
	static const ExtLightTexture FragmentMaterialExt;
	static const ExtLightTexture FragmentNormalExt;
	static const ExtLightTexture FragmentColorExt;
	static const ExtLightTexture AttenuationExt;
	static const ExtLightTexture ShadowAttenuationExt;
	static const ExtLightTexture TextureApplicationModeExt;
	static const ExtLightTexture TextureLightExt;
	static const ExtLightTexture TextureMaterialFaceExt;
	static const ExtLightTexture TextureMaterialParameterExt;
	static const ExtLightTexture FragmentDepthExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtMiscAttribute)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtMultiDrawArrays)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtMultisample)
	static const ExtMultisample MultisampleBitExt;
	static const ExtMultisample MultisampleExt;
	static const ExtMultisample SampleAlphaToMaskExt;
	static const ExtMultisample SampleAlphaToOneExt;
	static const ExtMultisample SampleMaskExt;
	static const ExtMultisample Gl1PassExt;
	static const ExtMultisample Gl2Pass0Ext;
	static const ExtMultisample Gl2Pass1Ext;
	static const ExtMultisample Gl4Pass0Ext;
	static const ExtMultisample Gl4Pass1Ext;
	static const ExtMultisample Gl4Pass2Ext;
	static const ExtMultisample Gl4Pass3Ext;
	static const ExtMultisample SampleBuffersExt;
	static const ExtMultisample SamplesExt;
	static const ExtMultisample SampleMaskValueExt;
	static const ExtMultisample SampleMaskInvertExt;
	static const ExtMultisample SamplePatternExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtPackedDepthStencil)
	static const ExtPackedDepthStencil DepthStencilExt;
	static const ExtPackedDepthStencil UnsignedInt248Ext;
	static const ExtPackedDepthStencil Depth24Stencil8Ext;
	static const ExtPackedDepthStencil TextureStencilSizeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtPackedFloat)
	static const ExtPackedFloat R11fG11fB10fExt;
	static const ExtPackedFloat UnsignedInt10F11F11FRevExt;
	static const ExtPackedFloat RgbaSignedComponentsExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtPackedPixels)
	static const ExtPackedPixels UnsignedByte332Ext;
	static const ExtPackedPixels UnsignedShort4444Ext;
	static const ExtPackedPixels UnsignedShort5551Ext;
	static const ExtPackedPixels UnsignedInt8888Ext;
	static const ExtPackedPixels UnsignedInt1010102Ext;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtPalettedTexture)
	static const ExtPalettedTexture ColorIndex1Ext;
	static const ExtPalettedTexture ColorIndex2Ext;
	static const ExtPalettedTexture ColorIndex4Ext;
	static const ExtPalettedTexture ColorIndex8Ext;
	static const ExtPalettedTexture ColorIndex12Ext;
	static const ExtPalettedTexture ColorIndex16Ext;
	static const ExtPalettedTexture TextureIndexSizeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtPixelBufferObject)
	static const ExtPixelBufferObject PixelPackBufferExt;
	static const ExtPixelBufferObject PixelUnpackBufferExt;
	static const ExtPixelBufferObject PixelPackBufferBindingExt;
	static const ExtPixelBufferObject PixelUnpackBufferBindingExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtPixelTransform)
	static const ExtPixelTransform PixelTransform2DExt;
	static const ExtPixelTransform PixelMagFilterExt;
	static const ExtPixelTransform PixelMinFilterExt;
	static const ExtPixelTransform PixelCubicWeightExt;
	static const ExtPixelTransform CubicExt;
	static const ExtPixelTransform AverageExt;
	static const ExtPixelTransform PixelTransform2DStackDepthExt;
	static const ExtPixelTransform MaxPixelTransform2DStackDepthExt;
	static const ExtPixelTransform PixelTransform2DMatrixExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtPixelTransformColorTable)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtPointParameters)
	static const ExtPointParameters PointSizeMinExt;
	static const ExtPointParameters PointSizeMaxExt;
	static const ExtPointParameters PointFadeThresholdSizeExt;
	static const ExtPointParameters DistanceAttenuationExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtPolygonOffset)
	static const ExtPolygonOffset PolygonOffsetExt;
	static const ExtPolygonOffset PolygonOffsetFactorExt;
	static const ExtPolygonOffset PolygonOffsetBiasExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtProvokingVertex)
	static const ExtProvokingVertex QuadsFollowProvokingVertexConventionExt;
	static const ExtProvokingVertex FirstVertexConventionExt;
	static const ExtProvokingVertex LastVertexConventionExt;
	static const ExtProvokingVertex ProvokingVertexExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtRescaleNormal)
	static const ExtRescaleNormal RescaleNormalExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtSecondaryColor)
	static const ExtSecondaryColor ColorSumExt;
	static const ExtSecondaryColor CurrentSecondaryColorExt;
	static const ExtSecondaryColor SecondaryColorArraySizeExt;
	static const ExtSecondaryColor SecondaryColorArrayTypeExt;
	static const ExtSecondaryColor SecondaryColorArrayStrideExt;
	static const ExtSecondaryColor SecondaryColorArrayPointerExt;
	static const ExtSecondaryColor SecondaryColorArrayExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtSeparateShaderObjects)
	static const ExtSeparateShaderObjects VertexShaderBitExt;
	static const ExtSeparateShaderObjects FragmentShaderBitExt;
	static const ExtSeparateShaderObjects ProgramSeparableExt;
	static const ExtSeparateShaderObjects ProgramPipelineBindingExt;
	static const ExtSeparateShaderObjects ActiveProgramExt;
	static const ExtSeparateShaderObjects AllShaderBitsExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtSeparateSpecularColor)
	static const ExtSeparateSpecularColor LightModelColorControlExt;
	static const ExtSeparateSpecularColor SingleColorExt;
	static const ExtSeparateSpecularColor SeparateSpecularColorExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtShaderImageLoadFormatted)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtShaderImageLoadStore)
	static const ExtShaderImageLoadStore VertexAttribArrayBarrierBitExt;
	static const ExtShaderImageLoadStore ElementArrayBarrierBitExt;
	static const ExtShaderImageLoadStore UniformBarrierBitExt;
	static const ExtShaderImageLoadStore TextureFetchBarrierBitExt;
	static const ExtShaderImageLoadStore ShaderImageAccessBarrierBitExt;
	static const ExtShaderImageLoadStore CommandBarrierBitExt;
	static const ExtShaderImageLoadStore PixelBufferBarrierBitExt;
	static const ExtShaderImageLoadStore TextureUpdateBarrierBitExt;
	static const ExtShaderImageLoadStore BufferUpdateBarrierBitExt;
	static const ExtShaderImageLoadStore FramebufferBarrierBitExt;
	static const ExtShaderImageLoadStore TransformFeedbackBarrierBitExt;
	static const ExtShaderImageLoadStore AtomicCounterBarrierBitExt;
	static const ExtShaderImageLoadStore MaxImageUnitsExt;
	static const ExtShaderImageLoadStore MaxCombinedImageUnitsAndFragmentOutputsExt;
	static const ExtShaderImageLoadStore ImageBindingNameExt;
	static const ExtShaderImageLoadStore ImageBindingLevelExt;
	static const ExtShaderImageLoadStore ImageBindingLayeredExt;
	static const ExtShaderImageLoadStore ImageBindingLayerExt;
	static const ExtShaderImageLoadStore ImageBindingAccessExt;
	static const ExtShaderImageLoadStore Image1DExt;
	static const ExtShaderImageLoadStore Image2DExt;
	static const ExtShaderImageLoadStore Image3DExt;
	static const ExtShaderImageLoadStore Image2DRectExt;
	static const ExtShaderImageLoadStore ImageCubeExt;
	static const ExtShaderImageLoadStore ImageBufferExt;
	static const ExtShaderImageLoadStore Image1DArrayExt;
	static const ExtShaderImageLoadStore Image2DArrayExt;
	static const ExtShaderImageLoadStore ImageCubeMapArrayExt;
	static const ExtShaderImageLoadStore Image2DMultisampleExt;
	static const ExtShaderImageLoadStore Image2DMultisampleArrayExt;
	static const ExtShaderImageLoadStore IntImage1DExt;
	static const ExtShaderImageLoadStore IntImage2DExt;
	static const ExtShaderImageLoadStore IntImage3DExt;
	static const ExtShaderImageLoadStore IntImage2DRectExt;
	static const ExtShaderImageLoadStore IntImageCubeExt;
	static const ExtShaderImageLoadStore IntImageBufferExt;
	static const ExtShaderImageLoadStore IntImage1DArrayExt;
	static const ExtShaderImageLoadStore IntImage2DArrayExt;
	static const ExtShaderImageLoadStore IntImageCubeMapArrayExt;
	static const ExtShaderImageLoadStore IntImage2DMultisampleExt;
	static const ExtShaderImageLoadStore IntImage2DMultisampleArrayExt;
	static const ExtShaderImageLoadStore UnsignedIntImage1DExt;
	static const ExtShaderImageLoadStore UnsignedIntImage2DExt;
	static const ExtShaderImageLoadStore UnsignedIntImage3DExt;
	static const ExtShaderImageLoadStore UnsignedIntImage2DRectExt;
	static const ExtShaderImageLoadStore UnsignedIntImageCubeExt;
	static const ExtShaderImageLoadStore UnsignedIntImageBufferExt;
	static const ExtShaderImageLoadStore UnsignedIntImage1DArrayExt;
	static const ExtShaderImageLoadStore UnsignedIntImage2DArrayExt;
	static const ExtShaderImageLoadStore UnsignedIntImageCubeMapArrayExt;
	static const ExtShaderImageLoadStore UnsignedIntImage2DMultisampleExt;
	static const ExtShaderImageLoadStore UnsignedIntImage2DMultisampleArrayExt;
	static const ExtShaderImageLoadStore MaxImageSamplesExt;
	static const ExtShaderImageLoadStore ImageBindingFormatExt;
	static const ExtShaderImageLoadStore AllBarrierBitsExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtShaderIntegerMix)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtShadowFuncs)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtSharedTexturePalette)
	static const ExtSharedTexturePalette SharedTexturePaletteExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtStencilClearTag)
	static const ExtStencilClearTag StencilTagBitsExt;
	static const ExtStencilClearTag StencilClearTagValueExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtStencilTwoSide)
	static const ExtStencilTwoSide StencilTestTwoSideExt;
	static const ExtStencilTwoSide ActiveStencilFaceExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtStencilWrap)
	static const ExtStencilWrap IncrWrapExt;
	static const ExtStencilWrap DecrWrapExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtSubtexture)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTexture)
	static const ExtTexture Alpha4Ext;
	static const ExtTexture Alpha8Ext;
	static const ExtTexture Alpha12Ext;
	static const ExtTexture Alpha16Ext;
	static const ExtTexture Luminance4Ext;
	static const ExtTexture Luminance8Ext;
	static const ExtTexture Luminance12Ext;
	static const ExtTexture Luminance16Ext;
	static const ExtTexture Luminance4Alpha4Ext;
	static const ExtTexture Luminance6Alpha2Ext;
	static const ExtTexture Luminance8Alpha8Ext;
	static const ExtTexture Luminance12Alpha4Ext;
	static const ExtTexture Luminance12Alpha12Ext;
	static const ExtTexture Luminance16Alpha16Ext;
	static const ExtTexture IntensityExt;
	static const ExtTexture Intensity4Ext;
	static const ExtTexture Intensity8Ext;
	static const ExtTexture Intensity12Ext;
	static const ExtTexture Intensity16Ext;
	static const ExtTexture Rgb2Ext;
	static const ExtTexture Rgb4Ext;
	static const ExtTexture Rgb5Ext;
	static const ExtTexture Rgb8Ext;
	static const ExtTexture Rgb10Ext;
	static const ExtTexture Rgb12Ext;
	static const ExtTexture Rgb16Ext;
	static const ExtTexture Rgba2Ext;
	static const ExtTexture Rgba4Ext;
	static const ExtTexture Rgb5A1Ext;
	static const ExtTexture Rgba8Ext;
	static const ExtTexture Rgb10A2Ext;
	static const ExtTexture Rgba12Ext;
	static const ExtTexture Rgba16Ext;
	static const ExtTexture TextureRedSizeExt;
	static const ExtTexture TextureGreenSizeExt;
	static const ExtTexture TextureBlueSizeExt;
	static const ExtTexture TextureAlphaSizeExt;
	static const ExtTexture TextureLuminanceSizeExt;
	static const ExtTexture TextureIntensitySizeExt;
	static const ExtTexture ReplaceExt;
	static const ExtTexture ProxyTexture1DExt;
	static const ExtTexture ProxyTexture2DExt;
	static const ExtTexture TextureTooLargeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTexture3D)
	static const ExtTexture3D PackSkipImagesExt;
	static const ExtTexture3D PackImageHeightExt;
	static const ExtTexture3D UnpackSkipImagesExt;
	static const ExtTexture3D UnpackImageHeightExt;
	static const ExtTexture3D Texture3DExt;
	static const ExtTexture3D ProxyTexture3DExt;
	static const ExtTexture3D TextureDepthExt;
	static const ExtTexture3D TextureWrapRExt;
	static const ExtTexture3D Max3DTextureSizeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureArray)
	static const ExtTextureArray CompareRefDepthToTextureExt;
	static const ExtTextureArray MaxArrayTextureLayersExt;
	static const ExtTextureArray Texture1DArrayExt;
	static const ExtTextureArray ProxyTexture1DArrayExt;
	static const ExtTextureArray Texture2DArrayExt;
	static const ExtTextureArray ProxyTexture2DArrayExt;
	static const ExtTextureArray TextureBinding1DArrayExt;
	static const ExtTextureArray TextureBinding2DArrayExt;
	static const ExtTextureArray FramebufferAttachmentTextureLayerExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureBufferObject)
	static const ExtTextureBufferObject TextureBufferExt;
	static const ExtTextureBufferObject MaxTextureBufferSizeExt;
	static const ExtTextureBufferObject TextureBindingBufferExt;
	static const ExtTextureBufferObject TextureBufferDataStoreBindingExt;
	static const ExtTextureBufferObject TextureBufferFormatExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureCompressionLatc)
	static const ExtTextureCompressionLatc CompressedLuminanceLatc1Ext;
	static const ExtTextureCompressionLatc CompressedSignedLuminanceLatc1Ext;
	static const ExtTextureCompressionLatc CompressedLuminanceAlphaLatc2Ext;
	static const ExtTextureCompressionLatc CompressedSignedLuminanceAlphaLatc2Ext;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureCompressionRgtc)
	static const ExtTextureCompressionRgtc CompressedRedRgtc1Ext;
	static const ExtTextureCompressionRgtc CompressedSignedRedRgtc1Ext;
	static const ExtTextureCompressionRgtc CompressedRedGreenRgtc2Ext;
	static const ExtTextureCompressionRgtc CompressedSignedRedGreenRgtc2Ext;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureCompressionS3tc)
	static const ExtTextureCompressionS3tc CompressedRgbS3tcDxt1Ext;
	static const ExtTextureCompressionS3tc CompressedRgbaS3tcDxt1Ext;
	static const ExtTextureCompressionS3tc CompressedRgbaS3tcDxt3Ext;
	static const ExtTextureCompressionS3tc CompressedRgbaS3tcDxt5Ext;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureCubeMap)
	static const ExtTextureCubeMap NormalMapExt;
	static const ExtTextureCubeMap ReflectionMapExt;
	static const ExtTextureCubeMap TextureCubeMapExt;
	static const ExtTextureCubeMap TextureBindingCubeMapExt;
	static const ExtTextureCubeMap TextureCubeMapPositiveXExt;
	static const ExtTextureCubeMap TextureCubeMapNegativeXExt;
	static const ExtTextureCubeMap TextureCubeMapPositiveYExt;
	static const ExtTextureCubeMap TextureCubeMapNegativeYExt;
	static const ExtTextureCubeMap TextureCubeMapPositiveZExt;
	static const ExtTextureCubeMap TextureCubeMapNegativeZExt;
	static const ExtTextureCubeMap ProxyTextureCubeMapExt;
	static const ExtTextureCubeMap MaxCubeMapTextureSizeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureEnvAdd)
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureEnvCombine)
	static const ExtTextureEnvCombine CombineExt;
	static const ExtTextureEnvCombine CombineRgbExt;
	static const ExtTextureEnvCombine CombineAlphaExt;
	static const ExtTextureEnvCombine RgbScaleExt;
	static const ExtTextureEnvCombine AddSignedExt;
	static const ExtTextureEnvCombine InterpolateExt;
	static const ExtTextureEnvCombine ConstantExt;
	static const ExtTextureEnvCombine PrimaryColorExt;
	static const ExtTextureEnvCombine PreviousExt;
	static const ExtTextureEnvCombine Source0RgbExt;
	static const ExtTextureEnvCombine Source1RgbExt;
	static const ExtTextureEnvCombine Source2RgbExt;
	static const ExtTextureEnvCombine Source0AlphaExt;
	static const ExtTextureEnvCombine Source1AlphaExt;
	static const ExtTextureEnvCombine Source2AlphaExt;
	static const ExtTextureEnvCombine Operand0RgbExt;
	static const ExtTextureEnvCombine Operand1RgbExt;
	static const ExtTextureEnvCombine Operand2RgbExt;
	static const ExtTextureEnvCombine Operand0AlphaExt;
	static const ExtTextureEnvCombine Operand1AlphaExt;
	static const ExtTextureEnvCombine Operand2AlphaExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureEnvDot3)
	static const ExtTextureEnvDot3 Dot3RgbExt;
	static const ExtTextureEnvDot3 Dot3RgbaExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureFilterAnisotropic)
	static const ExtTextureFilterAnisotropic TextureMaxAnisotropyExt;
	static const ExtTextureFilterAnisotropic MaxTextureMaxAnisotropyExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureInteger)
	static const ExtTextureInteger Rgba32uiExt;
	static const ExtTextureInteger Rgb32uiExt;
	static const ExtTextureInteger Alpha32uiExt;
	static const ExtTextureInteger Intensity32uiExt;
	static const ExtTextureInteger Luminance32uiExt;
	static const ExtTextureInteger LuminanceAlpha32uiExt;
	static const ExtTextureInteger Rgba16uiExt;
	static const ExtTextureInteger Rgb16uiExt;
	static const ExtTextureInteger Alpha16uiExt;
	static const ExtTextureInteger Intensity16uiExt;
	static const ExtTextureInteger Luminance16uiExt;
	static const ExtTextureInteger LuminanceAlpha16uiExt;
	static const ExtTextureInteger Rgba8uiExt;
	static const ExtTextureInteger Rgb8uiExt;
	static const ExtTextureInteger Alpha8uiExt;
	static const ExtTextureInteger Intensity8uiExt;
	static const ExtTextureInteger Luminance8uiExt;
	static const ExtTextureInteger LuminanceAlpha8uiExt;
	static const ExtTextureInteger Rgba32iExt;
	static const ExtTextureInteger Rgb32iExt;
	static const ExtTextureInteger Alpha32iExt;
	static const ExtTextureInteger Intensity32iExt;
	static const ExtTextureInteger Luminance32iExt;
	static const ExtTextureInteger LuminanceAlpha32iExt;
	static const ExtTextureInteger Rgba16iExt;
	static const ExtTextureInteger Rgb16iExt;
	static const ExtTextureInteger Alpha16iExt;
	static const ExtTextureInteger Intensity16iExt;
	static const ExtTextureInteger Luminance16iExt;
	static const ExtTextureInteger LuminanceAlpha16iExt;
	static const ExtTextureInteger Rgba8iExt;
	static const ExtTextureInteger Rgb8iExt;
	static const ExtTextureInteger Alpha8iExt;
	static const ExtTextureInteger Intensity8iExt;
	static const ExtTextureInteger Luminance8iExt;
	static const ExtTextureInteger LuminanceAlpha8iExt;
	static const ExtTextureInteger RedIntegerExt;
	static const ExtTextureInteger GreenIntegerExt;
	static const ExtTextureInteger BlueIntegerExt;
	static const ExtTextureInteger AlphaIntegerExt;
	static const ExtTextureInteger RgbIntegerExt;
	static const ExtTextureInteger RgbaIntegerExt;
	static const ExtTextureInteger BgrIntegerExt;
	static const ExtTextureInteger BgraIntegerExt;
	static const ExtTextureInteger LuminanceIntegerExt;
	static const ExtTextureInteger LuminanceAlphaIntegerExt;
	static const ExtTextureInteger RgbaIntegerModeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureLodBias)
	static const ExtTextureLodBias MaxTextureLodBiasExt;
	static const ExtTextureLodBias TextureFilterControlExt;
	static const ExtTextureLodBias TextureLodBiasExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureMirrorClamp)
	static const ExtTextureMirrorClamp MirrorClampExt;
	static const ExtTextureMirrorClamp MirrorClampToEdgeExt;
	static const ExtTextureMirrorClamp MirrorClampToBorderExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureObject)
	static const ExtTextureObject TexturePriorityExt;
	static const ExtTextureObject TextureResidentExt;
	static const ExtTextureObject Texture1DBindingExt;
	static const ExtTextureObject Texture2DBindingExt;
	static const ExtTextureObject Texture3DBindingExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTexturePerturbNormal)
	static const ExtTexturePerturbNormal PerturbExt;
	static const ExtTexturePerturbNormal TextureNormalExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureSharedExponent)
	static const ExtTextureSharedExponent Rgb9E5Ext;
	static const ExtTextureSharedExponent UnsignedInt5999RevExt;
	static const ExtTextureSharedExponent TextureSharedSizeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureSnorm)
	static const ExtTextureSnorm RedSnorm;
	static const ExtTextureSnorm RgSnorm;
	static const ExtTextureSnorm RgbSnorm;
	static const ExtTextureSnorm RgbaSnorm;
	static const ExtTextureSnorm R8Snorm;
	static const ExtTextureSnorm Rg8Snorm;
	static const ExtTextureSnorm Rgb8Snorm;
	static const ExtTextureSnorm Rgba8Snorm;
	static const ExtTextureSnorm R16Snorm;
	static const ExtTextureSnorm Rg16Snorm;
	static const ExtTextureSnorm Rgb16Snorm;
	static const ExtTextureSnorm Rgba16Snorm;
	static const ExtTextureSnorm SignedNormalized;
	static const ExtTextureSnorm AlphaSnorm;
	static const ExtTextureSnorm LuminanceSnorm;
	static const ExtTextureSnorm LuminanceAlphaSnorm;
	static const ExtTextureSnorm IntensitySnorm;
	static const ExtTextureSnorm Alpha8Snorm;
	static const ExtTextureSnorm Luminance8Snorm;
	static const ExtTextureSnorm Luminance8Alpha8Snorm;
	static const ExtTextureSnorm Intensity8Snorm;
	static const ExtTextureSnorm Alpha16Snorm;
	static const ExtTextureSnorm Luminance16Snorm;
	static const ExtTextureSnorm Luminance16Alpha16Snorm;
	static const ExtTextureSnorm Intensity16Snorm;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureSrgb)
	static const ExtTextureSrgb SrgbExt;
	static const ExtTextureSrgb Srgb8Ext;
	static const ExtTextureSrgb SrgbAlphaExt;
	static const ExtTextureSrgb Srgb8Alpha8Ext;
	static const ExtTextureSrgb SluminanceAlphaExt;
	static const ExtTextureSrgb Sluminance8Alpha8Ext;
	static const ExtTextureSrgb SluminanceExt;
	static const ExtTextureSrgb Sluminance8Ext;
	static const ExtTextureSrgb CompressedSrgbExt;
	static const ExtTextureSrgb CompressedSrgbAlphaExt;
	static const ExtTextureSrgb CompressedSluminanceExt;
	static const ExtTextureSrgb CompressedSluminanceAlphaExt;
	static const ExtTextureSrgb CompressedSrgbS3tcDxt1Ext;
	static const ExtTextureSrgb CompressedSrgbAlphaS3tcDxt1Ext;
	static const ExtTextureSrgb CompressedSrgbAlphaS3tcDxt3Ext;
	static const ExtTextureSrgb CompressedSrgbAlphaS3tcDxt5Ext;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureSrgbDecode)
	static const ExtTextureSrgbDecode TextureSrgbDecodeExt;
	static const ExtTextureSrgbDecode DecodeExt;
	static const ExtTextureSrgbDecode SkipDecodeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTextureSwizzle)
	static const ExtTextureSwizzle TextureSwizzleRExt;
	static const ExtTextureSwizzle TextureSwizzleGExt;
	static const ExtTextureSwizzle TextureSwizzleBExt;
	static const ExtTextureSwizzle TextureSwizzleAExt;
	static const ExtTextureSwizzle TextureSwizzleRgbaExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTimerQuery)
	static const ExtTimerQuery TimeElapsedExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtTransformFeedback)
	static const ExtTransformFeedback TransformFeedbackVaryingMaxLengthExt;
	static const ExtTransformFeedback TransformFeedbackBufferModeExt;
	static const ExtTransformFeedback MaxTransformFeedbackSeparateComponentsExt;
	static const ExtTransformFeedback TransformFeedbackVaryingsExt;
	static const ExtTransformFeedback TransformFeedbackBufferStartExt;
	static const ExtTransformFeedback TransformFeedbackBufferSizeExt;
	static const ExtTransformFeedback PrimitivesGeneratedExt;
	static const ExtTransformFeedback TransformFeedbackPrimitivesWrittenExt;
	static const ExtTransformFeedback RasterizerDiscardExt;
	static const ExtTransformFeedback MaxTransformFeedbackInterleavedComponentsExt;
	static const ExtTransformFeedback MaxTransformFeedbackSeparateAttribsExt;
	static const ExtTransformFeedback InterleavedAttribsExt;
	static const ExtTransformFeedback SeparateAttribsExt;
	static const ExtTransformFeedback TransformFeedbackBufferExt;
	static const ExtTransformFeedback TransformFeedbackBufferBindingExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtVertexArray)
	static const ExtVertexArray VertexArrayExt;
	static const ExtVertexArray NormalArrayExt;
	static const ExtVertexArray ColorArrayExt;
	static const ExtVertexArray IndexArrayExt;
	static const ExtVertexArray TextureCoordArrayExt;
	static const ExtVertexArray EdgeFlagArrayExt;
	static const ExtVertexArray VertexArraySizeExt;
	static const ExtVertexArray VertexArrayTypeExt;
	static const ExtVertexArray VertexArrayStrideExt;
	static const ExtVertexArray VertexArrayCountExt;
	static const ExtVertexArray NormalArrayTypeExt;
	static const ExtVertexArray NormalArrayStrideExt;
	static const ExtVertexArray NormalArrayCountExt;
	static const ExtVertexArray ColorArraySizeExt;
	static const ExtVertexArray ColorArrayTypeExt;
	static const ExtVertexArray ColorArrayStrideExt;
	static const ExtVertexArray ColorArrayCountExt;
	static const ExtVertexArray IndexArrayTypeExt;
	static const ExtVertexArray IndexArrayStrideExt;
	static const ExtVertexArray IndexArrayCountExt;
	static const ExtVertexArray TextureCoordArraySizeExt;
	static const ExtVertexArray TextureCoordArrayTypeExt;
	static const ExtVertexArray TextureCoordArrayStrideExt;
	static const ExtVertexArray TextureCoordArrayCountExt;
	static const ExtVertexArray EdgeFlagArrayStrideExt;
	static const ExtVertexArray EdgeFlagArrayCountExt;
	static const ExtVertexArray VertexArrayPointerExt;
	static const ExtVertexArray NormalArrayPointerExt;
	static const ExtVertexArray ColorArrayPointerExt;
	static const ExtVertexArray IndexArrayPointerExt;
	static const ExtVertexArray TextureCoordArrayPointerExt;
	static const ExtVertexArray EdgeFlagArrayPointerExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtVertexArrayBgra)
	static const ExtVertexArrayBgra Bgra;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtVertexAttrib64bit)
	static const ExtVertexAttrib64bit Double;
	static const ExtVertexAttrib64bit DoubleMat2Ext;
	static const ExtVertexAttrib64bit DoubleMat3Ext;
	static const ExtVertexAttrib64bit DoubleMat4Ext;
	static const ExtVertexAttrib64bit DoubleMat2x3Ext;
	static const ExtVertexAttrib64bit DoubleMat2x4Ext;
	static const ExtVertexAttrib64bit DoubleMat3x2Ext;
	static const ExtVertexAttrib64bit DoubleMat3x4Ext;
	static const ExtVertexAttrib64bit DoubleMat4x2Ext;
	static const ExtVertexAttrib64bit DoubleMat4x3Ext;
	static const ExtVertexAttrib64bit DoubleVec2Ext;
	static const ExtVertexAttrib64bit DoubleVec3Ext;
	static const ExtVertexAttrib64bit DoubleVec4Ext;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtVertexShader)
	static const ExtVertexShader VertexShaderExt;
	static const ExtVertexShader VertexShaderBindingExt;
	static const ExtVertexShader OpIndexExt;
	static const ExtVertexShader OpNegateExt;
	static const ExtVertexShader OpDot3Ext;
	static const ExtVertexShader OpDot4Ext;
	static const ExtVertexShader OpMulExt;
	static const ExtVertexShader OpAddExt;
	static const ExtVertexShader OpMaddExt;
	static const ExtVertexShader OpFracExt;
	static const ExtVertexShader OpMaxExt;
	static const ExtVertexShader OpMinExt;
	static const ExtVertexShader OpSetGeExt;
	static const ExtVertexShader OpSetLtExt;
	static const ExtVertexShader OpClampExt;
	static const ExtVertexShader OpFloorExt;
	static const ExtVertexShader OpRoundExt;
	static const ExtVertexShader OpExpBase2Ext;
	static const ExtVertexShader OpLogBase2Ext;
	static const ExtVertexShader OpPowerExt;
	static const ExtVertexShader OpRecipExt;
	static const ExtVertexShader OpRecipSqrtExt;
	static const ExtVertexShader OpSubExt;
	static const ExtVertexShader OpCrossProductExt;
	static const ExtVertexShader OpMultiplyMatrixExt;
	static const ExtVertexShader OpMovExt;
	static const ExtVertexShader OutputVertexExt;
	static const ExtVertexShader OutputColor0Ext;
	static const ExtVertexShader OutputColor1Ext;
	static const ExtVertexShader OutputTextureCoord0Ext;
	static const ExtVertexShader OutputTextureCoord1Ext;
	static const ExtVertexShader OutputTextureCoord2Ext;
	static const ExtVertexShader OutputTextureCoord3Ext;
	static const ExtVertexShader OutputTextureCoord4Ext;
	static const ExtVertexShader OutputTextureCoord5Ext;
	static const ExtVertexShader OutputTextureCoord6Ext;
	static const ExtVertexShader OutputTextureCoord7Ext;
	static const ExtVertexShader OutputTextureCoord8Ext;
	static const ExtVertexShader OutputTextureCoord9Ext;
	static const ExtVertexShader OutputTextureCoord10Ext;
	static const ExtVertexShader OutputTextureCoord11Ext;
	static const ExtVertexShader OutputTextureCoord12Ext;
	static const ExtVertexShader OutputTextureCoord13Ext;
	static const ExtVertexShader OutputTextureCoord14Ext;
	static const ExtVertexShader OutputTextureCoord15Ext;
	static const ExtVertexShader OutputTextureCoord16Ext;
	static const ExtVertexShader OutputTextureCoord17Ext;
	static const ExtVertexShader OutputTextureCoord18Ext;
	static const ExtVertexShader OutputTextureCoord19Ext;
	static const ExtVertexShader OutputTextureCoord20Ext;
	static const ExtVertexShader OutputTextureCoord21Ext;
	static const ExtVertexShader OutputTextureCoord22Ext;
	static const ExtVertexShader OutputTextureCoord23Ext;
	static const ExtVertexShader OutputTextureCoord24Ext;
	static const ExtVertexShader OutputTextureCoord25Ext;
	static const ExtVertexShader OutputTextureCoord26Ext;
	static const ExtVertexShader OutputTextureCoord27Ext;
	static const ExtVertexShader OutputTextureCoord28Ext;
	static const ExtVertexShader OutputTextureCoord29Ext;
	static const ExtVertexShader OutputTextureCoord30Ext;
	static const ExtVertexShader OutputTextureCoord31Ext;
	static const ExtVertexShader OutputFogExt;
	static const ExtVertexShader ScalarExt;
	static const ExtVertexShader VectorExt;
	static const ExtVertexShader MatrixExt;
	static const ExtVertexShader VariantExt;
	static const ExtVertexShader InvariantExt;
	static const ExtVertexShader LocalConstantExt;
	static const ExtVertexShader LocalExt;
	static const ExtVertexShader MaxVertexShaderInstructionsExt;
	static const ExtVertexShader MaxVertexShaderVariantsExt;
	static const ExtVertexShader MaxVertexShaderInvariantsExt;
	static const ExtVertexShader MaxVertexShaderLocalConstantsExt;
	static const ExtVertexShader MaxVertexShaderLocalsExt;
	static const ExtVertexShader MaxOptimizedVertexShaderInstructionsExt;
	static const ExtVertexShader MaxOptimizedVertexShaderVariantsExt;
	static const ExtVertexShader MaxOptimizedVertexShaderLocalConstantsExt;
	static const ExtVertexShader MaxOptimizedVertexShaderInvariantsExt;
	static const ExtVertexShader MaxOptimizedVertexShaderLocalsExt;
	static const ExtVertexShader VertexShaderInstructionsExt;
	static const ExtVertexShader VertexShaderVariantsExt;
	static const ExtVertexShader VertexShaderInvariantsExt;
	static const ExtVertexShader VertexShaderLocalConstantsExt;
	static const ExtVertexShader VertexShaderLocalsExt;
	static const ExtVertexShader VertexShaderOptimizedExt;
	static const ExtVertexShader XExt;
	static const ExtVertexShader YExt;
	static const ExtVertexShader ZExt;
	static const ExtVertexShader WExt;
	static const ExtVertexShader NegativeXExt;
	static const ExtVertexShader NegativeYExt;
	static const ExtVertexShader NegativeZExt;
	static const ExtVertexShader NegativeWExt;
	static const ExtVertexShader ZeroExt;
	static const ExtVertexShader OneExt;
	static const ExtVertexShader NegativeOneExt;
	static const ExtVertexShader NormalizedRangeExt;
	static const ExtVertexShader FullRangeExt;
	static const ExtVertexShader CurrentVertexExt;
	static const ExtVertexShader MvpMatrixExt;
	static const ExtVertexShader VariantValueExt;
	static const ExtVertexShader VariantDatatypeExt;
	static const ExtVertexShader VariantArrayStrideExt;
	static const ExtVertexShader VariantArrayTypeExt;
	static const ExtVertexShader VariantArrayExt;
	static const ExtVertexShader VariantArrayPointerExt;
	static const ExtVertexShader InvariantValueExt;
	static const ExtVertexShader InvariantDatatypeExt;
	static const ExtVertexShader LocalConstantValueExt;
	static const ExtVertexShader LocalConstantDatatypeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtVertexWeighting)
	static const ExtVertexWeighting Modelview0StackDepthExt;
	static const ExtVertexWeighting Modelview0MatrixExt;
	static const ExtVertexWeighting Modelview0Ext;
	static const ExtVertexWeighting Modelview1StackDepthExt;
	static const ExtVertexWeighting Modelview1MatrixExt;
	static const ExtVertexWeighting VertexWeightingExt;
	static const ExtVertexWeighting Modelview1Ext;
	static const ExtVertexWeighting CurrentVertexWeightExt;
	static const ExtVertexWeighting VertexWeightArrayExt;
	static const ExtVertexWeighting VertexWeightArraySizeExt;
	static const ExtVertexWeighting VertexWeightArrayTypeExt;
	static const ExtVertexWeighting VertexWeightArrayStrideExt;
	static const ExtVertexWeighting VertexWeightArrayPointerExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ExtX11SyncObject)
	static const ExtX11SyncObject SyncX11FenceExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(FeedBackToken)
	static const FeedBackToken PassThroughToken;
	static const FeedBackToken PointToken;
	static const FeedBackToken LineToken;
	static const FeedBackToken PolygonToken;
	static const FeedBackToken BitmapToken;
	static const FeedBackToken DrawPixelToken;
	static const FeedBackToken CopyPixelToken;
	static const FeedBackToken LineResetToken;
OPENGL_ENUM_END

OPENGL_ENUM_START(FeedbackType)
	static const FeedbackType Gl2D;
	static const FeedbackType Gl3D;
	static const FeedbackType Gl3DColor;
	static const FeedbackType Gl3DColorTexture;
	static const FeedbackType Gl4DColorTexture;
OPENGL_ENUM_END

OPENGL_ENUM_START(FfdMaskSgix)
OPENGL_ENUM_END

OPENGL_ENUM_START(FfdTargetSgix)
	static const FfdTargetSgix GeometryDeformationSgix;
	static const FfdTargetSgix TextureDeformationSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(FogCoordinatePointerType)
	static const FogCoordinatePointerType Float;
	static const FogCoordinatePointerType Double;
	static const FogCoordinatePointerType HalfFloat;
OPENGL_ENUM_END

OPENGL_ENUM_START(FogMode)
	static const FogMode Exp;
	static const FogMode Exp2;
	static const FogMode Linear;
	static const FogMode FogFuncSgis;
	static const FogMode FogCoord;
	static const FogMode FragmentDepth;
OPENGL_ENUM_END

OPENGL_ENUM_START(FogParameter)
	static const FogParameter FogIndex;
	static const FogParameter FogDensity;
	static const FogParameter FogStart;
	static const FogParameter FogEnd;
	static const FogParameter FogMode;
	static const FogParameter FogColor;
	static const FogParameter FogOffsetValueSgix;
	static const FogParameter FogCoordSrc;
OPENGL_ENUM_END

OPENGL_ENUM_START(FogPointerType)
	static const FogPointerType Float;
	static const FogPointerType Double;
	static const FogPointerType HalfFloat;
OPENGL_ENUM_END

OPENGL_ENUM_START(FogPointerTypeExt)
	static const FogPointerTypeExt Float;
	static const FogPointerTypeExt Double;
	static const FogPointerTypeExt HalfFloat;
OPENGL_ENUM_END

OPENGL_ENUM_START(FogPointerTypeIbm)
	static const FogPointerTypeIbm Float;
	static const FogPointerTypeIbm Double;
	static const FogPointerTypeIbm HalfFloat;
OPENGL_ENUM_END

OPENGL_ENUM_START(FragmentLightModelParameterSgix)
	static const FragmentLightModelParameterSgix FragmentLightModelLocalViewerSgix;
	static const FragmentLightModelParameterSgix FragmentLightModelTwoSideSgix;
	static const FragmentLightModelParameterSgix FragmentLightModelAmbientSgix;
	static const FragmentLightModelParameterSgix FragmentLightModelNormalInterpolationSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(FramebufferAttachment)
	static const FramebufferAttachment FrontLeft;
	static const FramebufferAttachment FrontRight;
	static const FramebufferAttachment BackLeft;
	static const FramebufferAttachment BackRight;
	static const FramebufferAttachment Aux0;
	static const FramebufferAttachment Aux1;
	static const FramebufferAttachment Aux2;
	static const FramebufferAttachment Aux3;
	static const FramebufferAttachment Color;
	static const FramebufferAttachment Depth;
	static const FramebufferAttachment Stencil;
	static const FramebufferAttachment DepthStencilAttachment;
	static const FramebufferAttachment ColorAttachment0;
	static const FramebufferAttachment ColorAttachment0Ext;
	static const FramebufferAttachment ColorAttachment1;
	static const FramebufferAttachment ColorAttachment1Ext;
	static const FramebufferAttachment ColorAttachment2;
	static const FramebufferAttachment ColorAttachment2Ext;
	static const FramebufferAttachment ColorAttachment3;
	static const FramebufferAttachment ColorAttachment3Ext;
	static const FramebufferAttachment ColorAttachment4;
	static const FramebufferAttachment ColorAttachment4Ext;
	static const FramebufferAttachment ColorAttachment5;
	static const FramebufferAttachment ColorAttachment5Ext;
	static const FramebufferAttachment ColorAttachment6;
	static const FramebufferAttachment ColorAttachment6Ext;
	static const FramebufferAttachment ColorAttachment7;
	static const FramebufferAttachment ColorAttachment7Ext;
	static const FramebufferAttachment ColorAttachment8;
	static const FramebufferAttachment ColorAttachment8Ext;
	static const FramebufferAttachment ColorAttachment9;
	static const FramebufferAttachment ColorAttachment9Ext;
	static const FramebufferAttachment ColorAttachment10;
	static const FramebufferAttachment ColorAttachment10Ext;
	static const FramebufferAttachment ColorAttachment11;
	static const FramebufferAttachment ColorAttachment11Ext;
	static const FramebufferAttachment ColorAttachment12;
	static const FramebufferAttachment ColorAttachment12Ext;
	static const FramebufferAttachment ColorAttachment13;
	static const FramebufferAttachment ColorAttachment13Ext;
	static const FramebufferAttachment ColorAttachment14;
	static const FramebufferAttachment ColorAttachment14Ext;
	static const FramebufferAttachment ColorAttachment15;
	static const FramebufferAttachment ColorAttachment15Ext;
	static const FramebufferAttachment DepthAttachment;
	static const FramebufferAttachment DepthAttachmentExt;
	static const FramebufferAttachment StencilAttachment;
	static const FramebufferAttachment StencilAttachmentExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(FramebufferAttachmentComponentType)
	static const FramebufferAttachmentComponentType Int;
	static const FramebufferAttachmentComponentType Float;
	static const FramebufferAttachmentComponentType Index;
	static const FramebufferAttachmentComponentType UnsignedNormalized;
OPENGL_ENUM_END

OPENGL_ENUM_START(FramebufferAttachmentObjectType)
	static const FramebufferAttachmentObjectType None;
	static const FramebufferAttachmentObjectType Texture;
	static const FramebufferAttachmentObjectType FramebufferDefault;
	static const FramebufferAttachmentObjectType Renderbuffer;
OPENGL_ENUM_END

OPENGL_ENUM_START(FramebufferDefaultParameter)
	static const FramebufferDefaultParameter FramebufferDefaultWidth;
	static const FramebufferDefaultParameter FramebufferDefaultHeight;
	static const FramebufferDefaultParameter FramebufferDefaultLayers;
	static const FramebufferDefaultParameter FramebufferDefaultSamples;
	static const FramebufferDefaultParameter FramebufferDefaultFixedSampleLocations;
OPENGL_ENUM_END

OPENGL_ENUM_START(FramebufferErrorCode)
	static const FramebufferErrorCode FramebufferUndefined;
	static const FramebufferErrorCode FramebufferComplete;
	static const FramebufferErrorCode FramebufferCompleteExt;
	static const FramebufferErrorCode FramebufferIncompleteAttachment;
	static const FramebufferErrorCode FramebufferIncompleteAttachmentExt;
	static const FramebufferErrorCode FramebufferIncompleteMissingAttachment;
	static const FramebufferErrorCode FramebufferIncompleteMissingAttachmentExt;
	static const FramebufferErrorCode FramebufferIncompleteDimensionsExt;
	static const FramebufferErrorCode FramebufferIncompleteFormatsExt;
	static const FramebufferErrorCode FramebufferIncompleteDrawBuffer;
	static const FramebufferErrorCode FramebufferIncompleteDrawBufferExt;
	static const FramebufferErrorCode FramebufferIncompleteReadBuffer;
	static const FramebufferErrorCode FramebufferIncompleteReadBufferExt;
	static const FramebufferErrorCode FramebufferUnsupported;
	static const FramebufferErrorCode FramebufferUnsupportedExt;
	static const FramebufferErrorCode FramebufferIncompleteMultisample;
	static const FramebufferErrorCode FramebufferIncompleteLayerTargets;
	static const FramebufferErrorCode FramebufferIncompleteLayerCount;
OPENGL_ENUM_END

OPENGL_ENUM_START(FramebufferParameterName)
	static const FramebufferParameterName FramebufferAttachmentColorEncoding;
	static const FramebufferParameterName FramebufferAttachmentComponentType;
	static const FramebufferParameterName FramebufferAttachmentRedSize;
	static const FramebufferParameterName FramebufferAttachmentGreenSize;
	static const FramebufferParameterName FramebufferAttachmentBlueSize;
	static const FramebufferParameterName FramebufferAttachmentAlphaSize;
	static const FramebufferParameterName FramebufferAttachmentDepthSize;
	static const FramebufferParameterName FramebufferAttachmentStencilSize;
	static const FramebufferParameterName FramebufferAttachmentObjectType;
	static const FramebufferParameterName FramebufferAttachmentObjectTypeExt;
	static const FramebufferParameterName FramebufferAttachmentObjectName;
	static const FramebufferParameterName FramebufferAttachmentObjectNameExt;
	static const FramebufferParameterName FramebufferAttachmentTextureLevel;
	static const FramebufferParameterName FramebufferAttachmentTextureLevelExt;
	static const FramebufferParameterName FramebufferAttachmentTextureCubeMapFace;
	static const FramebufferParameterName FramebufferAttachmentTextureCubeMapFaceExt;
	static const FramebufferParameterName FramebufferAttachmentTexture3DZoffsetExt;
	static const FramebufferParameterName FramebufferAttachmentTextureLayer;
	static const FramebufferParameterName FramebufferAttachmentLayered;
OPENGL_ENUM_END

OPENGL_ENUM_START(FramebufferTarget)
	static const FramebufferTarget ReadFramebuffer;
	static const FramebufferTarget DrawFramebuffer;
	static const FramebufferTarget Framebuffer;
	static const FramebufferTarget FramebufferExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(FrontFaceDirection)
	static const FrontFaceDirection Cw;
	static const FrontFaceDirection Ccw;
OPENGL_ENUM_END

OPENGL_ENUM_START(GenerateMipmapTarget)
	static const GenerateMipmapTarget Texture1D;
	static const GenerateMipmapTarget Texture2D;
	static const GenerateMipmapTarget Texture3D;
	static const GenerateMipmapTarget TextureCubeMap;
	static const GenerateMipmapTarget Texture1DArray;
	static const GenerateMipmapTarget Texture2DArray;
	static const GenerateMipmapTarget TextureCubeMapArray;
	static const GenerateMipmapTarget Texture2DMultisample;
	static const GenerateMipmapTarget Texture2DMultisampleArray;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetColorTableParameterPName)
	static const GetColorTableParameterPName ColorTableScale;
	static const GetColorTableParameterPName ColorTableBias;
	static const GetColorTableParameterPName ColorTableFormat;
	static const GetColorTableParameterPName ColorTableWidth;
	static const GetColorTableParameterPName ColorTableRedSize;
	static const GetColorTableParameterPName ColorTableGreenSize;
	static const GetColorTableParameterPName ColorTableBlueSize;
	static const GetColorTableParameterPName ColorTableAlphaSize;
	static const GetColorTableParameterPName ColorTableLuminanceSize;
	static const GetColorTableParameterPName ColorTableIntensitySize;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetColorTableParameterPNameSgi)
	static const GetColorTableParameterPNameSgi ColorTableScaleSgi;
	static const GetColorTableParameterPNameSgi ColorTableBiasSgi;
	static const GetColorTableParameterPNameSgi ColorTableFormatSgi;
	static const GetColorTableParameterPNameSgi ColorTableWidthSgi;
	static const GetColorTableParameterPNameSgi ColorTableRedSizeSgi;
	static const GetColorTableParameterPNameSgi ColorTableGreenSizeSgi;
	static const GetColorTableParameterPNameSgi ColorTableBlueSizeSgi;
	static const GetColorTableParameterPNameSgi ColorTableAlphaSizeSgi;
	static const GetColorTableParameterPNameSgi ColorTableLuminanceSizeSgi;
	static const GetColorTableParameterPNameSgi ColorTableIntensitySizeSgi;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetConvolutionParameter)
	static const GetConvolutionParameter ConvolutionBorderModeExt;
	static const GetConvolutionParameter ConvolutionFilterScaleExt;
	static const GetConvolutionParameter ConvolutionFilterBiasExt;
	static const GetConvolutionParameter ConvolutionFormatExt;
	static const GetConvolutionParameter ConvolutionWidthExt;
	static const GetConvolutionParameter ConvolutionHeightExt;
	static const GetConvolutionParameter MaxConvolutionWidthExt;
	static const GetConvolutionParameter MaxConvolutionHeightExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetConvolutionParameterPName)
	static const GetConvolutionParameterPName ConvolutionBorderMode;
	static const GetConvolutionParameterPName ConvolutionFilterScale;
	static const GetConvolutionParameterPName ConvolutionFilterBias;
	static const GetConvolutionParameterPName ConvolutionFormat;
	static const GetConvolutionParameterPName ConvolutionWidth;
	static const GetConvolutionParameterPName ConvolutionHeight;
	static const GetConvolutionParameterPName MaxConvolutionWidth;
	static const GetConvolutionParameterPName MaxConvolutionHeight;
	static const GetConvolutionParameterPName ConvolutionBorderColor;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetHistogramParameterPName)
	static const GetHistogramParameterPName HistogramWidth;
	static const GetHistogramParameterPName HistogramFormat;
	static const GetHistogramParameterPName HistogramRedSize;
	static const GetHistogramParameterPName HistogramGreenSize;
	static const GetHistogramParameterPName HistogramBlueSize;
	static const GetHistogramParameterPName HistogramAlphaSize;
	static const GetHistogramParameterPName HistogramLuminanceSize;
	static const GetHistogramParameterPName HistogramSink;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetHistogramParameterPNameExt)
	static const GetHistogramParameterPNameExt HistogramWidthExt;
	static const GetHistogramParameterPNameExt HistogramFormatExt;
	static const GetHistogramParameterPNameExt HistogramRedSizeExt;
	static const GetHistogramParameterPNameExt HistogramGreenSizeExt;
	static const GetHistogramParameterPNameExt HistogramBlueSizeExt;
	static const GetHistogramParameterPNameExt HistogramAlphaSizeExt;
	static const GetHistogramParameterPNameExt HistogramLuminanceSizeExt;
	static const GetHistogramParameterPNameExt HistogramSinkExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetIndexedPName)
	static const GetIndexedPName DepthRange;
	static const GetIndexedPName Viewport;
	static const GetIndexedPName ScissorBox;
	static const GetIndexedPName ColorWritemask;
	static const GetIndexedPName TextureBinding1D;
	static const GetIndexedPName TextureBinding2D;
	static const GetIndexedPName TextureBinding3D;
	static const GetIndexedPName TextureBinding;
	static const GetIndexedPName TextureBindingRectangle;
	static const GetIndexedPName TextureBindingCubeMap;
	static const GetIndexedPName UniformBufferBinding;
	static const GetIndexedPName UniformBufferStart;
	static const GetIndexedPName UniformBufferSize;
	static const GetIndexedPName TextureBinding1DArray;
	static const GetIndexedPName TextureBinding2DArray;
	static const GetIndexedPName TextureBindingBuffer;
	static const GetIndexedPName TransformFeedbackBufferStart;
	static const GetIndexedPName TransformFeedbackBufferSize;
	static const GetIndexedPName TransformFeedbackBufferBinding;
	static const GetIndexedPName SampleMaskValue;
	static const GetIndexedPName TextureBindingCubeMapArray;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetMapQuery)
	static const GetMapQuery Coeff;
	static const GetMapQuery Order;
	static const GetMapQuery Domain;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetMinmaxParameterPName)
	static const GetMinmaxParameterPName MinmaxFormat;
	static const GetMinmaxParameterPName MinmaxSink;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetMinmaxParameterPNameExt)
	static const GetMinmaxParameterPNameExt MinmaxFormat;
	static const GetMinmaxParameterPNameExt MinmaxFormatExt;
	static const GetMinmaxParameterPNameExt MinmaxSink;
	static const GetMinmaxParameterPNameExt MinmaxSinkExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetMultisamplePName)
	static const GetMultisamplePName SamplePosition;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetPixelMap)
	static const GetPixelMap PixelMapIToI;
	static const GetPixelMap PixelMapSToS;
	static const GetPixelMap PixelMapIToR;
	static const GetPixelMap PixelMapIToG;
	static const GetPixelMap PixelMapIToB;
	static const GetPixelMap PixelMapIToA;
	static const GetPixelMap PixelMapRToR;
	static const GetPixelMap PixelMapGToG;
	static const GetPixelMap PixelMapBToB;
	static const GetPixelMap PixelMapAToA;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetPName)
	static const GetPName CurrentColor;
	static const GetPName CurrentIndex;
	static const GetPName CurrentNormal;
	static const GetPName CurrentTextureCoords;
	static const GetPName CurrentRasterColor;
	static const GetPName CurrentRasterIndex;
	static const GetPName CurrentRasterTextureCoords;
	static const GetPName CurrentRasterPosition;
	static const GetPName CurrentRasterPositionValid;
	static const GetPName CurrentRasterDistance;
	static const GetPName PointSmooth;
	static const GetPName PointSize;
	static const GetPName PointSizeRange;
	static const GetPName SmoothPointSizeRange;
	static const GetPName PointSizeGranularity;
	static const GetPName SmoothPointSizeGranularity;
	static const GetPName LineSmooth;
	static const GetPName LineWidth;
	static const GetPName LineWidthRange;
	static const GetPName SmoothLineWidthRange;
	static const GetPName LineWidthGranularity;
	static const GetPName SmoothLineWidthGranularity;
	static const GetPName LineStipple;
	static const GetPName LineStipplePattern;
	static const GetPName LineStippleRepeat;
	static const GetPName ListMode;
	static const GetPName MaxListNesting;
	static const GetPName ListBase;
	static const GetPName ListIndex;
	static const GetPName PolygonMode;
	static const GetPName PolygonSmooth;
	static const GetPName PolygonStipple;
	static const GetPName EdgeFlag;
	static const GetPName CullFace;
	static const GetPName CullFaceMode;
	static const GetPName FrontFace;
	static const GetPName Lighting;
	static const GetPName LightModelLocalViewer;
	static const GetPName LightModelTwoSide;
	static const GetPName LightModelAmbient;
	static const GetPName ShadeModel;
	static const GetPName ColorMaterialFace;
	static const GetPName ColorMaterialParameter;
	static const GetPName ColorMaterial;
	static const GetPName Fog;
	static const GetPName FogIndex;
	static const GetPName FogDensity;
	static const GetPName FogStart;
	static const GetPName FogEnd;
	static const GetPName FogMode;
	static const GetPName FogColor;
	static const GetPName DepthRange;
	static const GetPName DepthTest;
	static const GetPName DepthWritemask;
	static const GetPName DepthClearValue;
	static const GetPName DepthFunc;
	static const GetPName AccumClearValue;
	static const GetPName StencilTest;
	static const GetPName StencilClearValue;
	static const GetPName StencilFunc;
	static const GetPName StencilValueMask;
	static const GetPName StencilFail;
	static const GetPName StencilPassDepthFail;
	static const GetPName StencilPassDepthPass;
	static const GetPName StencilRef;
	static const GetPName StencilWritemask;
	static const GetPName MatrixMode;
	static const GetPName Normalize;
	static const GetPName Viewport;
	static const GetPName Modelview0StackDepthExt;
	static const GetPName ModelviewStackDepth;
	static const GetPName ProjectionStackDepth;
	static const GetPName TextureStackDepth;
	static const GetPName Modelview0MatrixExt;
	static const GetPName ModelviewMatrix;
	static const GetPName ProjectionMatrix;
	static const GetPName TextureMatrix;
	static const GetPName AttribStackDepth;
	static const GetPName ClientAttribStackDepth;
	static const GetPName AlphaTest;
	static const GetPName AlphaTestQcom;
	static const GetPName AlphaTestFunc;
	static const GetPName AlphaTestFuncQcom;
	static const GetPName AlphaTestRef;
	static const GetPName AlphaTestRefQcom;
	static const GetPName Dither;
	static const GetPName BlendDst;
	static const GetPName BlendSrc;
	static const GetPName Blend;
	static const GetPName LogicOpMode;
	static const GetPName IndexLogicOp;
	static const GetPName LogicOp;
	static const GetPName ColorLogicOp;
	static const GetPName AuxBuffers;
	static const GetPName DrawBuffer;
	static const GetPName DrawBufferExt;
	static const GetPName ReadBuffer;
	static const GetPName ReadBufferExt;
	static const GetPName ReadBufferNv;
	static const GetPName ScissorBox;
	static const GetPName ScissorTest;
	static const GetPName IndexClearValue;
	static const GetPName IndexWritemask;
	static const GetPName ColorClearValue;
	static const GetPName ColorWritemask;
	static const GetPName IndexMode;
	static const GetPName RgbaMode;
	static const GetPName Doublebuffer;
	static const GetPName Stereo;
	static const GetPName RenderMode;
	static const GetPName PerspectiveCorrectionHint;
	static const GetPName PointSmoothHint;
	static const GetPName LineSmoothHint;
	static const GetPName PolygonSmoothHint;
	static const GetPName FogHint;
	static const GetPName TextureGenS;
	static const GetPName TextureGenT;
	static const GetPName TextureGenR;
	static const GetPName TextureGenQ;
	static const GetPName PixelMapIToISize;
	static const GetPName PixelMapSToSSize;
	static const GetPName PixelMapIToRSize;
	static const GetPName PixelMapIToGSize;
	static const GetPName PixelMapIToBSize;
	static const GetPName PixelMapIToASize;
	static const GetPName PixelMapRToRSize;
	static const GetPName PixelMapGToGSize;
	static const GetPName PixelMapBToBSize;
	static const GetPName PixelMapAToASize;
	static const GetPName UnpackSwapBytes;
	static const GetPName UnpackLsbFirst;
	static const GetPName UnpackRowLength;
	static const GetPName UnpackSkipRows;
	static const GetPName UnpackSkipPixels;
	static const GetPName UnpackAlignment;
	static const GetPName PackSwapBytes;
	static const GetPName PackLsbFirst;
	static const GetPName PackRowLength;
	static const GetPName PackSkipRows;
	static const GetPName PackSkipPixels;
	static const GetPName PackAlignment;
	static const GetPName MapColor;
	static const GetPName MapStencil;
	static const GetPName IndexShift;
	static const GetPName IndexOffset;
	static const GetPName RedScale;
	static const GetPName RedBias;
	static const GetPName ZoomX;
	static const GetPName ZoomY;
	static const GetPName GreenScale;
	static const GetPName GreenBias;
	static const GetPName BlueScale;
	static const GetPName BlueBias;
	static const GetPName AlphaScale;
	static const GetPName AlphaBias;
	static const GetPName DepthScale;
	static const GetPName DepthBias;
	static const GetPName MaxEvalOrder;
	static const GetPName MaxLights;
	static const GetPName MaxClipDistances;
	static const GetPName MaxClipPlanes;
	static const GetPName MaxTextureSize;
	static const GetPName MaxPixelMapTable;
	static const GetPName MaxAttribStackDepth;
	static const GetPName MaxModelviewStackDepth;
	static const GetPName MaxNameStackDepth;
	static const GetPName MaxProjectionStackDepth;
	static const GetPName MaxTextureStackDepth;
	static const GetPName MaxViewportDims;
	static const GetPName MaxClientAttribStackDepth;
	static const GetPName SubpixelBits;
	static const GetPName IndexBits;
	static const GetPName RedBits;
	static const GetPName GreenBits;
	static const GetPName BlueBits;
	static const GetPName AlphaBits;
	static const GetPName DepthBits;
	static const GetPName StencilBits;
	static const GetPName AccumRedBits;
	static const GetPName AccumGreenBits;
	static const GetPName AccumBlueBits;
	static const GetPName AccumAlphaBits;
	static const GetPName NameStackDepth;
	static const GetPName AutoNormal;
	static const GetPName Map1Color4;
	static const GetPName Map1Index;
	static const GetPName Map1Normal;
	static const GetPName Map1TextureCoord1;
	static const GetPName Map1TextureCoord2;
	static const GetPName Map1TextureCoord3;
	static const GetPName Map1TextureCoord4;
	static const GetPName Map1Vertex3;
	static const GetPName Map1Vertex4;
	static const GetPName Map2Color4;
	static const GetPName Map2Index;
	static const GetPName Map2Normal;
	static const GetPName Map2TextureCoord1;
	static const GetPName Map2TextureCoord2;
	static const GetPName Map2TextureCoord3;
	static const GetPName Map2TextureCoord4;
	static const GetPName Map2Vertex3;
	static const GetPName Map2Vertex4;
	static const GetPName Map1GridDomain;
	static const GetPName Map1GridSegments;
	static const GetPName Map2GridDomain;
	static const GetPName Map2GridSegments;
	static const GetPName Texture1D;
	static const GetPName Texture2D;
	static const GetPName FeedbackBufferSize;
	static const GetPName FeedbackBufferType;
	static const GetPName SelectionBufferSize;
	static const GetPName PolygonOffsetUnits;
	static const GetPName PolygonOffsetPoint;
	static const GetPName PolygonOffsetLine;
	static const GetPName ClipPlane0;
	static const GetPName ClipPlane1;
	static const GetPName ClipPlane2;
	static const GetPName ClipPlane3;
	static const GetPName ClipPlane4;
	static const GetPName ClipPlane5;
	static const GetPName Light0;
	static const GetPName Light1;
	static const GetPName Light2;
	static const GetPName Light3;
	static const GetPName Light4;
	static const GetPName Light5;
	static const GetPName Light6;
	static const GetPName Light7;
	static const GetPName BlendColorExt;
	static const GetPName BlendEquationExt;
	static const GetPName BlendEquationRgb;
	static const GetPName PackCmykHintExt;
	static const GetPName UnpackCmykHintExt;
	static const GetPName Convolution1DExt;
	static const GetPName Convolution2DExt;
	static const GetPName Separable2DExt;
	static const GetPName PostConvolutionRedScaleExt;
	static const GetPName PostConvolutionGreenScaleExt;
	static const GetPName PostConvolutionBlueScaleExt;
	static const GetPName PostConvolutionAlphaScaleExt;
	static const GetPName PostConvolutionRedBiasExt;
	static const GetPName PostConvolutionGreenBiasExt;
	static const GetPName PostConvolutionBlueBiasExt;
	static const GetPName PostConvolutionAlphaBiasExt;
	static const GetPName HistogramExt;
	static const GetPName MinmaxExt;
	static const GetPName PolygonOffsetFill;
	static const GetPName PolygonOffsetFactor;
	static const GetPName PolygonOffsetBiasExt;
	static const GetPName RescaleNormalExt;
	static const GetPName TextureBinding1D;
	static const GetPName TextureBinding2D;
	static const GetPName Texture3DBindingExt;
	static const GetPName TextureBinding3D;
	static const GetPName PackSkipImagesExt;
	static const GetPName PackImageHeightExt;
	static const GetPName UnpackSkipImagesExt;
	static const GetPName UnpackImageHeightExt;
	static const GetPName Texture3DExt;
	static const GetPName Max3DTextureSize;
	static const GetPName Max3DTextureSizeExt;
	static const GetPName VertexArray;
	static const GetPName NormalArray;
	static const GetPName ColorArray;
	static const GetPName IndexArray;
	static const GetPName TextureCoordArray;
	static const GetPName EdgeFlagArray;
	static const GetPName VertexArraySize;
	static const GetPName VertexArrayType;
	static const GetPName VertexArrayStride;
	static const GetPName VertexArrayCountExt;
	static const GetPName NormalArrayType;
	static const GetPName NormalArrayStride;
	static const GetPName NormalArrayCountExt;
	static const GetPName ColorArraySize;
	static const GetPName ColorArrayType;
	static const GetPName ColorArrayStride;
	static const GetPName ColorArrayCountExt;
	static const GetPName IndexArrayType;
	static const GetPName IndexArrayStride;
	static const GetPName IndexArrayCountExt;
	static const GetPName TextureCoordArraySize;
	static const GetPName TextureCoordArrayType;
	static const GetPName TextureCoordArrayStride;
	static const GetPName TextureCoordArrayCountExt;
	static const GetPName EdgeFlagArrayStride;
	static const GetPName EdgeFlagArrayCountExt;
	static const GetPName InterlaceSgix;
	static const GetPName DetailTexture2DBindingSgis;
	static const GetPName Multisample;
	static const GetPName MultisampleSgis;
	static const GetPName SampleAlphaToCoverage;
	static const GetPName SampleAlphaToMaskSgis;
	static const GetPName SampleAlphaToOne;
	static const GetPName SampleAlphaToOneSgis;
	static const GetPName SampleCoverage;
	static const GetPName SampleMaskSgis;
	static const GetPName SampleBuffers;
	static const GetPName SampleBuffersSgis;
	static const GetPName Samples;
	static const GetPName SamplesSgis;
	static const GetPName SampleCoverageValue;
	static const GetPName SampleMaskValueSgis;
	static const GetPName SampleCoverageInvert;
	static const GetPName SampleMaskInvertSgis;
	static const GetPName SamplePatternSgis;
	static const GetPName ColorMatrixSgi;
	static const GetPName ColorMatrixStackDepthSgi;
	static const GetPName MaxColorMatrixStackDepthSgi;
	static const GetPName PostColorMatrixRedScaleSgi;
	static const GetPName PostColorMatrixGreenScaleSgi;
	static const GetPName PostColorMatrixBlueScaleSgi;
	static const GetPName PostColorMatrixAlphaScaleSgi;
	static const GetPName PostColorMatrixRedBiasSgi;
	static const GetPName PostColorMatrixGreenBiasSgi;
	static const GetPName PostColorMatrixBlueBiasSgi;
	static const GetPName PostColorMatrixAlphaBiasSgi;
	static const GetPName TextureColorTableSgi;
	static const GetPName BlendDstRgb;
	static const GetPName BlendSrcRgb;
	static const GetPName BlendDstAlpha;
	static const GetPName BlendSrcAlpha;
	static const GetPName ColorTableSgi;
	static const GetPName PostConvolutionColorTableSgi;
	static const GetPName PostColorMatrixColorTableSgi;
	static const GetPName MaxElementsVertices;
	static const GetPName MaxElementsIndices;
	static const GetPName PointSizeMin;
	static const GetPName PointSizeMinSgis;
	static const GetPName PointSizeMax;
	static const GetPName PointSizeMaxSgis;
	static const GetPName PointFadeThresholdSize;
	static const GetPName PointFadeThresholdSizeSgis;
	static const GetPName DistanceAttenuationSgis;
	static const GetPName PointDistanceAttenuation;
	static const GetPName FogFuncPointsSgis;
	static const GetPName MaxFogFuncPointsSgis;
	static const GetPName PackSkipVolumesSgis;
	static const GetPName PackImageDepthSgis;
	static const GetPName UnpackSkipVolumesSgis;
	static const GetPName UnpackImageDepthSgis;
	static const GetPName Texture4DSgis;
	static const GetPName Max4DTextureSizeSgis;
	static const GetPName PixelTexGenSgix;
	static const GetPName PixelTileBestAlignmentSgix;
	static const GetPName PixelTileCacheIncrementSgix;
	static const GetPName PixelTileWidthSgix;
	static const GetPName PixelTileHeightSgix;
	static const GetPName PixelTileGridWidthSgix;
	static const GetPName PixelTileGridHeightSgix;
	static const GetPName PixelTileGridDepthSgix;
	static const GetPName PixelTileCacheSizeSgix;
	static const GetPName SpriteSgix;
	static const GetPName SpriteModeSgix;
	static const GetPName SpriteAxisSgix;
	static const GetPName SpriteTranslationSgix;
	static const GetPName Texture4DBindingSgis;
	static const GetPName MaxClipmapDepthSgix;
	static const GetPName MaxClipmapVirtualDepthSgix;
	static const GetPName PostTextureFilterBiasRangeSgix;
	static const GetPName PostTextureFilterScaleRangeSgix;
	static const GetPName ReferencePlaneSgix;
	static const GetPName ReferencePlaneEquationSgix;
	static const GetPName IrInstrument1Sgix;
	static const GetPName InstrumentMeasurementsSgix;
	static const GetPName CalligraphicFragmentSgix;
	static const GetPName FramezoomSgix;
	static const GetPName FramezoomFactorSgix;
	static const GetPName MaxFramezoomFactorSgix;
	static const GetPName GenerateMipmapHint;
	static const GetPName GenerateMipmapHintSgis;
	static const GetPName DeformationsMaskSgix;
	static const GetPName FogOffsetSgix;
	static const GetPName FogOffsetValueSgix;
	static const GetPName LightModelColorControl;
	static const GetPName SharedTexturePaletteExt;
	static const GetPName MajorVersion;
	static const GetPName MinorVersion;
	static const GetPName NumExtensions;
	static const GetPName ContextFlags;
	static const GetPName ResetNotificationStrategy;
	static const GetPName ProgramPipelineBinding;
	static const GetPName MaxViewports;
	static const GetPName ViewportSubpixelBits;
	static const GetPName ViewportBoundsRange;
	static const GetPName LayerProvokingVertex;
	static const GetPName ViewportIndexProvokingVertex;
	static const GetPName MaxCullDistances;
	static const GetPName MaxCombinedClipAndCullDistances;
	static const GetPName ContextReleaseBehavior;
	static const GetPName ConvolutionHintSgix;
	static const GetPName AsyncMarkerSgix;
	static const GetPName PixelTexGenModeSgix;
	static const GetPName AsyncHistogramSgix;
	static const GetPName MaxAsyncHistogramSgix;
	static const GetPName PixelTextureSgis;
	static const GetPName AsyncTexImageSgix;
	static const GetPName AsyncDrawPixelsSgix;
	static const GetPName AsyncReadPixelsSgix;
	static const GetPName MaxAsyncTexImageSgix;
	static const GetPName MaxAsyncDrawPixelsSgix;
	static const GetPName MaxAsyncReadPixelsSgix;
	static const GetPName VertexPreclipSgix;
	static const GetPName VertexPreclipHintSgix;
	static const GetPName FragmentLightingSgix;
	static const GetPName FragmentColorMaterialSgix;
	static const GetPName FragmentColorMaterialFaceSgix;
	static const GetPName FragmentColorMaterialParameterSgix;
	static const GetPName MaxFragmentLightsSgix;
	static const GetPName MaxActiveLightsSgix;
	static const GetPName LightEnvModeSgix;
	static const GetPName FragmentLightModelLocalViewerSgix;
	static const GetPName FragmentLightModelTwoSideSgix;
	static const GetPName FragmentLightModelAmbientSgix;
	static const GetPName FragmentLightModelNormalInterpolationSgix;
	static const GetPName FragmentLight0Sgix;
	static const GetPName PackResampleSgix;
	static const GetPName UnpackResampleSgix;
	static const GetPName CurrentFogCoord;
	static const GetPName FogCoordArrayType;
	static const GetPName FogCoordArrayStride;
	static const GetPName ColorSum;
	static const GetPName CurrentSecondaryColor;
	static const GetPName SecondaryColorArraySize;
	static const GetPName SecondaryColorArrayType;
	static const GetPName SecondaryColorArrayStride;
	static const GetPName CurrentRasterSecondaryColor;
	static const GetPName AliasedPointSizeRange;
	static const GetPName AliasedLineWidthRange;
	static const GetPName ActiveTexture;
	static const GetPName ClientActiveTexture;
	static const GetPName MaxTextureUnits;
	static const GetPName TransposeModelviewMatrix;
	static const GetPName TransposeProjectionMatrix;
	static const GetPName TransposeTextureMatrix;
	static const GetPName TransposeColorMatrix;
	static const GetPName MaxRenderbufferSize;
	static const GetPName MaxRenderbufferSizeExt;
	static const GetPName TextureCompressionHint;
	static const GetPName TextureBindingRectangle;
	static const GetPName MaxRectangleTextureSize;
	static const GetPName MaxTextureLodBias;
	static const GetPName TextureCubeMap;
	static const GetPName TextureBindingCubeMap;
	static const GetPName MaxCubeMapTextureSize;
	static const GetPName PackSubsampleRateSgix;
	static const GetPName UnpackSubsampleRateSgix;
	static const GetPName VertexArrayBinding;
	static const GetPName ProgramPointSize;
	static const GetPName DepthClamp;
	static const GetPName NumCompressedTextureFormats;
	static const GetPName CompressedTextureFormats;
	static const GetPName NumProgramBinaryFormats;
	static const GetPName ProgramBinaryFormats;
	static const GetPName StencilBackFunc;
	static const GetPName StencilBackFail;
	static const GetPName StencilBackPassDepthFail;
	static const GetPName StencilBackPassDepthPass;
	static const GetPName RgbaFloatMode;
	static const GetPName MaxDrawBuffers;
	static const GetPName DrawBuffer0;
	static const GetPName DrawBuffer1;
	static const GetPName DrawBuffer2;
	static const GetPName DrawBuffer3;
	static const GetPName DrawBuffer4;
	static const GetPName DrawBuffer5;
	static const GetPName DrawBuffer6;
	static const GetPName DrawBuffer7;
	static const GetPName DrawBuffer8;
	static const GetPName DrawBuffer9;
	static const GetPName DrawBuffer10;
	static const GetPName DrawBuffer11;
	static const GetPName DrawBuffer12;
	static const GetPName DrawBuffer13;
	static const GetPName DrawBuffer14;
	static const GetPName DrawBuffer15;
	static const GetPName BlendEquationAlpha;
	static const GetPName TextureCubeMapSeamless;
	static const GetPName PointSprite;
	static const GetPName MaxVertexAttribs;
	static const GetPName MaxTessControlInputComponents;
	static const GetPName MaxTessEvaluationInputComponents;
	static const GetPName MaxTextureCoords;
	static const GetPName MaxTextureImageUnits;
	static const GetPName ArrayBufferBinding;
	static const GetPName ElementArrayBufferBinding;
	static const GetPName VertexArrayBufferBinding;
	static const GetPName NormalArrayBufferBinding;
	static const GetPName ColorArrayBufferBinding;
	static const GetPName IndexArrayBufferBinding;
	static const GetPName TextureCoordArrayBufferBinding;
	static const GetPName EdgeFlagArrayBufferBinding;
	static const GetPName SecondaryColorArrayBufferBinding;
	static const GetPName FogCoordArrayBufferBinding;
	static const GetPName WeightArrayBufferBinding;
	static const GetPName VertexAttribArrayBufferBinding;
	static const GetPName PixelPackBufferBinding;
	static const GetPName PixelUnpackBufferBinding;
	static const GetPName MaxDualSourceDrawBuffers;
	static const GetPName MaxArrayTextureLayers;
	static const GetPName MinProgramTexelOffset;
	static const GetPName MaxProgramTexelOffset;
	static const GetPName SamplerBinding;
	static const GetPName ClampVertexColor;
	static const GetPName ClampFragmentColor;
	static const GetPName ClampReadColor;
	static const GetPName MaxVertexUniformBlocks;
	static const GetPName MaxGeometryUniformBlocks;
	static const GetPName MaxFragmentUniformBlocks;
	static const GetPName MaxCombinedUniformBlocks;
	static const GetPName MaxUniformBufferBindings;
	static const GetPName MaxUniformBlockSize;
	static const GetPName MaxCombinedVertexUniformComponents;
	static const GetPName MaxCombinedGeometryUniformComponents;
	static const GetPName MaxCombinedFragmentUniformComponents;
	static const GetPName UniformBufferOffsetAlignment;
	static const GetPName MaxFragmentUniformComponents;
	static const GetPName MaxVertexUniformComponents;
	static const GetPName MaxVaryingComponents;
	static const GetPName MaxVaryingFloats;
	static const GetPName MaxVertexTextureImageUnits;
	static const GetPName MaxCombinedTextureImageUnits;
	static const GetPName FragmentShaderDerivativeHint;
	static const GetPName CurrentProgram;
	static const GetPName ImplementationColorReadType;
	static const GetPName ImplementationColorReadFormat;
	static const GetPName TextureBinding1DArray;
	static const GetPName TextureBinding2DArray;
	static const GetPName MaxGeometryTextureImageUnits;
	static const GetPName TextureBuffer;
	static const GetPName MaxTextureBufferSize;
	static const GetPName TextureBindingBuffer;
	static const GetPName TextureBufferDataStoreBinding;
	static const GetPName SampleShading;
	static const GetPName MinSampleShadingValue;
	static const GetPName MaxTransformFeedbackSeparateComponents;
	static const GetPName MaxTransformFeedbackInterleavedComponents;
	static const GetPName MaxTransformFeedbackSeparateAttribs;
	static const GetPName StencilBackRef;
	static const GetPName StencilBackValueMask;
	static const GetPName StencilBackWritemask;
	static const GetPName DrawFramebufferBinding;
	static const GetPName FramebufferBinding;
	static const GetPName FramebufferBindingExt;
	static const GetPName RenderbufferBinding;
	static const GetPName RenderbufferBindingExt;
	static const GetPName ReadFramebufferBinding;
	static const GetPName MaxColorAttachments;
	static const GetPName MaxColorAttachmentsExt;
	static const GetPName MaxSamples;
	static const GetPName FramebufferSrgb;
	static const GetPName MaxGeometryVaryingComponents;
	static const GetPName MaxVertexVaryingComponents;
	static const GetPName MaxGeometryUniformComponents;
	static const GetPName MaxGeometryOutputVertices;
	static const GetPName MaxGeometryTotalOutputComponents;
	static const GetPName MaxSubroutines;
	static const GetPName MaxSubroutineUniformLocations;
	static const GetPName ShaderBinaryFormats;
	static const GetPName NumShaderBinaryFormats;
	static const GetPName ShaderCompiler;
	static const GetPName MaxVertexUniformVectors;
	static const GetPName MaxVaryingVectors;
	static const GetPName MaxFragmentUniformVectors;
	static const GetPName MaxCombinedTessControlUniformComponents;
	static const GetPName MaxCombinedTessEvaluationUniformComponents;
	static const GetPName TransformFeedbackBufferPaused;
	static const GetPName TransformFeedbackBufferActive;
	static const GetPName TransformFeedbackBinding;
	static const GetPName Timestamp;
	static const GetPName QuadsFollowProvokingVertexConvention;
	static const GetPName ProvokingVertex;
	static const GetPName SampleMask;
	static const GetPName MaxSampleMaskWords;
	static const GetPName MaxGeometryShaderInvocations;
	static const GetPName MinFragmentInterpolationOffset;
	static const GetPName MaxFragmentInterpolationOffset;
	static const GetPName FragmentInterpolationOffsetBits;
	static const GetPName MinProgramTextureGatherOffset;
	static const GetPName MaxProgramTextureGatherOffset;
	static const GetPName MaxTransformFeedbackBuffers;
	static const GetPName MaxVertexStreams;
	static const GetPName PatchVertices;
	static const GetPName PatchDefaultInnerLevel;
	static const GetPName PatchDefaultOuterLevel;
	static const GetPName MaxPatchVertices;
	static const GetPName MaxTessGenLevel;
	static const GetPName MaxTessControlUniformComponents;
	static const GetPName MaxTessEvaluationUniformComponents;
	static const GetPName MaxTessControlTextureImageUnits;
	static const GetPName MaxTessEvaluationTextureImageUnits;
	static const GetPName MaxTessControlOutputComponents;
	static const GetPName MaxTessPatchComponents;
	static const GetPName MaxTessControlTotalOutputComponents;
	static const GetPName MaxTessEvaluationOutputComponents;
	static const GetPName MaxTessControlUniformBlocks;
	static const GetPName MaxTessEvaluationUniformBlocks;
	static const GetPName DrawIndirectBufferBinding;
	static const GetPName MaxVertexImageUniforms;
	static const GetPName MaxTessControlImageUniforms;
	static const GetPName MaxTessEvaluationImageUniforms;
	static const GetPName MaxGeometryImageUniforms;
	static const GetPName MaxFragmentImageUniforms;
	static const GetPName MaxCombinedImageUniforms;
	static const GetPName ContextRobustAccess;
	static const GetPName TextureBinding2DMultisample;
	static const GetPName TextureBinding2DMultisampleArray;
	static const GetPName MaxColorTextureSamples;
	static const GetPName MaxDepthTextureSamples;
	static const GetPName MaxIntegerSamples;
	static const GetPName MaxVertexOutputComponents;
	static const GetPName MaxGeometryInputComponents;
	static const GetPName MaxGeometryOutputComponents;
	static const GetPName MaxFragmentInputComponents;
	static const GetPName MaxComputeImageUniforms;
	static const GetPName ClipOrigin;
	static const GetPName ClipDepthMode;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetPointervPName)
	static const GetPointervPName FeedbackBufferPointer;
	static const GetPointervPName SelectionBufferPointer;
	static const GetPointervPName VertexArrayPointer;
	static const GetPointervPName VertexArrayPointerExt;
	static const GetPointervPName NormalArrayPointer;
	static const GetPointervPName NormalArrayPointerExt;
	static const GetPointervPName ColorArrayPointer;
	static const GetPointervPName ColorArrayPointerExt;
	static const GetPointervPName IndexArrayPointer;
	static const GetPointervPName IndexArrayPointerExt;
	static const GetPointervPName TextureCoordArrayPointer;
	static const GetPointervPName TextureCoordArrayPointerExt;
	static const GetPointervPName EdgeFlagArrayPointer;
	static const GetPointervPName EdgeFlagArrayPointerExt;
	static const GetPointervPName InstrumentBufferPointerSgix;
	static const GetPointervPName FogCoordArrayPointer;
	static const GetPointervPName SecondaryColorArrayPointer;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetProgramParameterName)
	static const GetProgramParameterName ProgramBinaryRetrievableHint;
	static const GetProgramParameterName ProgramSeparable;
	static const GetProgramParameterName GeometryShaderInvocations;
	static const GetProgramParameterName GeometryVerticesOut;
	static const GetProgramParameterName GeometryInputType;
	static const GetProgramParameterName GeometryOutputType;
	static const GetProgramParameterName ActiveUniformBlockMaxNameLength;
	static const GetProgramParameterName ActiveUniformBlocks;
	static const GetProgramParameterName DeleteStatus;
	static const GetProgramParameterName LinkStatus;
	static const GetProgramParameterName ValidateStatus;
	static const GetProgramParameterName InfoLogLength;
	static const GetProgramParameterName AttachedShaders;
	static const GetProgramParameterName ActiveUniforms;
	static const GetProgramParameterName ActiveUniformMaxLength;
	static const GetProgramParameterName ActiveAttributes;
	static const GetProgramParameterName ActiveAttributeMaxLength;
	static const GetProgramParameterName TransformFeedbackVaryingMaxLength;
	static const GetProgramParameterName TransformFeedbackBufferMode;
	static const GetProgramParameterName TransformFeedbackVaryings;
	static const GetProgramParameterName TessControlOutputVertices;
	static const GetProgramParameterName TessGenMode;
	static const GetProgramParameterName TessGenSpacing;
	static const GetProgramParameterName TessGenVertexOrder;
	static const GetProgramParameterName TessGenPointMode;
	static const GetProgramParameterName MaxComputeWorkGroupSize;
	static const GetProgramParameterName ActiveAtomicCounterBuffers;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetQueryObjectParam)
	static const GetQueryObjectParam QueryTarget;
	static const GetQueryObjectParam QueryResult;
	static const GetQueryObjectParam QueryResultAvailable;
	static const GetQueryObjectParam QueryResultNoWait;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetQueryParam)
	static const GetQueryParam QueryCounterBits;
	static const GetQueryParam CurrentQuery;
OPENGL_ENUM_END

OPENGL_ENUM_START(GetTextureParameter)
	static const GetTextureParameter TextureWidth;
	static const GetTextureParameter TextureHeight;
	static const GetTextureParameter TextureComponents;
	static const GetTextureParameter TextureInternalFormat;
	static const GetTextureParameter TextureBorderColor;
	static const GetTextureParameter TextureBorderColorNv;
	static const GetTextureParameter TextureBorder;
	static const GetTextureParameter TextureTarget;
	static const GetTextureParameter TextureMagFilter;
	static const GetTextureParameter TextureMinFilter;
	static const GetTextureParameter TextureWrapS;
	static const GetTextureParameter TextureWrapT;
	static const GetTextureParameter TextureRedSize;
	static const GetTextureParameter TextureGreenSize;
	static const GetTextureParameter TextureBlueSize;
	static const GetTextureParameter TextureAlphaSize;
	static const GetTextureParameter TextureLuminanceSize;
	static const GetTextureParameter TextureIntensitySize;
	static const GetTextureParameter TexturePriority;
	static const GetTextureParameter TextureResident;
	static const GetTextureParameter TextureDepth;
	static const GetTextureParameter TextureDepthExt;
	static const GetTextureParameter TextureWrapR;
	static const GetTextureParameter TextureWrapRExt;
	static const GetTextureParameter DetailTextureLevelSgis;
	static const GetTextureParameter DetailTextureModeSgis;
	static const GetTextureParameter DetailTextureFuncPointsSgis;
	static const GetTextureParameter SharpenTextureFuncPointsSgis;
	static const GetTextureParameter ShadowAmbientSgix;
	static const GetTextureParameter DualTextureSelectSgis;
	static const GetTextureParameter QuadTextureSelectSgis;
	static const GetTextureParameter Texture4DsizeSgis;
	static const GetTextureParameter TextureWrapQSgis;
	static const GetTextureParameter TextureMinLod;
	static const GetTextureParameter TextureMinLodSgis;
	static const GetTextureParameter TextureMaxLod;
	static const GetTextureParameter TextureMaxLodSgis;
	static const GetTextureParameter TextureBaseLevel;
	static const GetTextureParameter TextureBaseLevelSgis;
	static const GetTextureParameter TextureMaxLevel;
	static const GetTextureParameter TextureMaxLevelSgis;
	static const GetTextureParameter TextureFilter4SizeSgis;
	static const GetTextureParameter TextureClipmapCenterSgix;
	static const GetTextureParameter TextureClipmapFrameSgix;
	static const GetTextureParameter TextureClipmapOffsetSgix;
	static const GetTextureParameter TextureClipmapVirtualDepthSgix;
	static const GetTextureParameter TextureClipmapLodOffsetSgix;
	static const GetTextureParameter TextureClipmapDepthSgix;
	static const GetTextureParameter PostTextureFilterBiasSgix;
	static const GetTextureParameter PostTextureFilterScaleSgix;
	static const GetTextureParameter TextureLodBiasSSgix;
	static const GetTextureParameter TextureLodBiasTSgix;
	static const GetTextureParameter TextureLodBiasRSgix;
	static const GetTextureParameter GenerateMipmap;
	static const GetTextureParameter GenerateMipmapSgis;
	static const GetTextureParameter TextureCompareSgix;
	static const GetTextureParameter TextureCompareOperatorSgix;
	static const GetTextureParameter TextureLequalRSgix;
	static const GetTextureParameter TextureGequalRSgix;
	static const GetTextureParameter TextureViewMinLevel;
	static const GetTextureParameter TextureViewNumLevels;
	static const GetTextureParameter TextureViewMinLayer;
	static const GetTextureParameter TextureViewNumLayers;
	static const GetTextureParameter TextureImmutableLevels;
	static const GetTextureParameter TextureMaxClampSSgix;
	static const GetTextureParameter TextureMaxClampTSgix;
	static const GetTextureParameter TextureMaxClampRSgix;
	static const GetTextureParameter TextureCompressedImageSize;
	static const GetTextureParameter TextureCompressed;
	static const GetTextureParameter TextureDepthSize;
	static const GetTextureParameter DepthTextureMode;
	static const GetTextureParameter TextureCompareMode;
	static const GetTextureParameter TextureCompareFunc;
	static const GetTextureParameter TextureStencilSize;
	static const GetTextureParameter TextureRedType;
	static const GetTextureParameter TextureGreenType;
	static const GetTextureParameter TextureBlueType;
	static const GetTextureParameter TextureAlphaType;
	static const GetTextureParameter TextureLuminanceType;
	static const GetTextureParameter TextureIntensityType;
	static const GetTextureParameter TextureDepthType;
	static const GetTextureParameter TextureSharedSize;
	static const GetTextureParameter TextureSwizzleR;
	static const GetTextureParameter TextureSwizzleG;
	static const GetTextureParameter TextureSwizzleB;
	static const GetTextureParameter TextureSwizzleA;
	static const GetTextureParameter TextureSwizzleRgba;
	static const GetTextureParameter ImageFormatCompatibilityType;
	static const GetTextureParameter TextureSamples;
	static const GetTextureParameter TextureFixedSampleLocations;
	static const GetTextureParameter TextureImmutableFormat;
OPENGL_ENUM_END

OPENGL_ENUM_START(Gl3DfxMultisample)
	static const Gl3DfxMultisample MultisampleBit3Dfx;
	static const Gl3DfxMultisample Multisample3Dfx;
	static const Gl3DfxMultisample SampleBuffers3Dfx;
	static const Gl3DfxMultisample Samples3Dfx;
OPENGL_ENUM_END

OPENGL_ENUM_START(Gl3DfxTbuffer)
OPENGL_ENUM_END

OPENGL_ENUM_START(Gl3DfxTextureCompressionFxt1)
	static const Gl3DfxTextureCompressionFxt1 CompressedRgbFxt13Dfx;
	static const Gl3DfxTextureCompressionFxt1 CompressedRgbaFxt13Dfx;
OPENGL_ENUM_END

OPENGL_ENUM_START(GremedyFrameTerminator)
OPENGL_ENUM_END

OPENGL_ENUM_START(GremedyStringMarker)
OPENGL_ENUM_END

OPENGL_ENUM_START(HintMode)
	static const HintMode DontCare;
	static const HintMode Fastest;
	static const HintMode Nicest;
OPENGL_ENUM_END

OPENGL_ENUM_START(HintTarget)
	static const HintTarget PerspectiveCorrectionHint;
	static const HintTarget PointSmoothHint;
	static const HintTarget LineSmoothHint;
	static const HintTarget PolygonSmoothHint;
	static const HintTarget FogHint;
	static const HintTarget PreferDoublebufferHintPgi;
	static const HintTarget ConserveMemoryHintPgi;
	static const HintTarget ReclaimMemoryHintPgi;
	static const HintTarget NativeGraphicsBeginHintPgi;
	static const HintTarget NativeGraphicsEndHintPgi;
	static const HintTarget AlwaysFastHintPgi;
	static const HintTarget AlwaysSoftHintPgi;
	static const HintTarget AllowDrawObjHintPgi;
	static const HintTarget AllowDrawWinHintPgi;
	static const HintTarget AllowDrawFrgHintPgi;
	static const HintTarget AllowDrawMemHintPgi;
	static const HintTarget StrictDepthfuncHintPgi;
	static const HintTarget StrictLightingHintPgi;
	static const HintTarget StrictScissorHintPgi;
	static const HintTarget FullStippleHintPgi;
	static const HintTarget ClipNearHintPgi;
	static const HintTarget ClipFarHintPgi;
	static const HintTarget WideLineHintPgi;
	static const HintTarget BackNormalsHintPgi;
	static const HintTarget VertexDataHintPgi;
	static const HintTarget VertexConsistentHintPgi;
	static const HintTarget MaterialSideHintPgi;
	static const HintTarget MaxVertexHintPgi;
	static const HintTarget PackCmykHintExt;
	static const HintTarget UnpackCmykHintExt;
	static const HintTarget PhongHintWin;
	static const HintTarget ClipVolumeClippingHintExt;
	static const HintTarget TextureMultiBufferHintSgix;
	static const HintTarget GenerateMipmapHint;
	static const HintTarget GenerateMipmapHintSgis;
	static const HintTarget ProgramBinaryRetrievableHint;
	static const HintTarget ConvolutionHintSgix;
	static const HintTarget ScalebiasHintSgix;
	static const HintTarget LineQualityHintSgix;
	static const HintTarget VertexPreclipSgix;
	static const HintTarget VertexPreclipHintSgix;
	static const HintTarget TextureCompressionHint;
	static const HintTarget TextureCompressionHintArb;
	static const HintTarget VertexArrayStorageHintApple;
	static const HintTarget MultisampleFilterHintNv;
	static const HintTarget TransformHintApple;
	static const HintTarget TextureStorageHintApple;
	static const HintTarget FragmentShaderDerivativeHint;
	static const HintTarget FragmentShaderDerivativeHintArb;
	static const HintTarget FragmentShaderDerivativeHintOes;
	static const HintTarget BinningControlHintQcom;
OPENGL_ENUM_END

OPENGL_ENUM_START(HistogramTarget)
	static const HistogramTarget Histogram;
	static const HistogramTarget ProxyHistogram;
OPENGL_ENUM_END

OPENGL_ENUM_START(HistogramTargetExt)
	static const HistogramTargetExt Histogram;
	static const HistogramTargetExt HistogramExt;
	static const HistogramTargetExt ProxyHistogram;
	static const HistogramTargetExt ProxyHistogramExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(HpConvolutionBorderModes)
	static const HpConvolutionBorderModes IgnoreBorderHp;
	static const HpConvolutionBorderModes ConstantBorderHp;
	static const HpConvolutionBorderModes ReplicateBorderHp;
	static const HpConvolutionBorderModes ConvolutionBorderColorHp;
OPENGL_ENUM_END

OPENGL_ENUM_START(HpImageTransform)
	static const HpImageTransform ImageScaleXHp;
	static const HpImageTransform ImageScaleYHp;
	static const HpImageTransform ImageTranslateXHp;
	static const HpImageTransform ImageTranslateYHp;
	static const HpImageTransform ImageRotateAngleHp;
	static const HpImageTransform ImageRotateOriginXHp;
	static const HpImageTransform ImageRotateOriginYHp;
	static const HpImageTransform ImageMagFilterHp;
	static const HpImageTransform ImageMinFilterHp;
	static const HpImageTransform ImageCubicWeightHp;
	static const HpImageTransform CubicHp;
	static const HpImageTransform AverageHp;
	static const HpImageTransform ImageTransform2DHp;
	static const HpImageTransform PostImageTransformColorTableHp;
	static const HpImageTransform ProxyPostImageTransformColorTableHp;
OPENGL_ENUM_END

OPENGL_ENUM_START(HpOcclusionTest)
	static const HpOcclusionTest OcclusionTestHp;
	static const HpOcclusionTest OcclusionTestResultHp;
OPENGL_ENUM_END

OPENGL_ENUM_START(HpTextureLighting)
	static const HpTextureLighting TextureLightingModeHp;
	static const HpTextureLighting TexturePostSpecularHp;
	static const HpTextureLighting TexturePreSpecularHp;
OPENGL_ENUM_END

OPENGL_ENUM_START(IbmCullVertex)
	static const IbmCullVertex CullVertexIbm;
OPENGL_ENUM_END

OPENGL_ENUM_START(IbmMultimodeDrawArrays)
OPENGL_ENUM_END

OPENGL_ENUM_START(IbmRasterposClip)
	static const IbmRasterposClip RasterPositionUnclippedIbm;
OPENGL_ENUM_END

OPENGL_ENUM_START(IbmStaticData)
	static const IbmStaticData AllStaticDataIbm;
	static const IbmStaticData StaticVertexArrayIbm;
OPENGL_ENUM_END

OPENGL_ENUM_START(IbmTextureMirroredRepeat)
	static const IbmTextureMirroredRepeat MirroredRepeatIbm;
OPENGL_ENUM_END

OPENGL_ENUM_START(IbmVertexArrayLists)
	static const IbmVertexArrayLists VertexArrayListIbm;
	static const IbmVertexArrayLists NormalArrayListIbm;
	static const IbmVertexArrayLists ColorArrayListIbm;
	static const IbmVertexArrayLists IndexArrayListIbm;
	static const IbmVertexArrayLists TextureCoordArrayListIbm;
	static const IbmVertexArrayLists EdgeFlagArrayListIbm;
	static const IbmVertexArrayLists FogCoordinateArrayListIbm;
	static const IbmVertexArrayLists SecondaryColorArrayListIbm;
	static const IbmVertexArrayLists VertexArrayListStrideIbm;
	static const IbmVertexArrayLists NormalArrayListStrideIbm;
	static const IbmVertexArrayLists ColorArrayListStrideIbm;
	static const IbmVertexArrayLists IndexArrayListStrideIbm;
	static const IbmVertexArrayLists TextureCoordArrayListStrideIbm;
	static const IbmVertexArrayLists EdgeFlagArrayListStrideIbm;
	static const IbmVertexArrayLists FogCoordinateArrayListStrideIbm;
	static const IbmVertexArrayLists SecondaryColorArrayListStrideIbm;
OPENGL_ENUM_END

OPENGL_ENUM_START(ImageTarget)
	static const ImageTarget Texture1D;
	static const ImageTarget Texture2D;
	static const ImageTarget Texture3D;
	static const ImageTarget TextureRectangle;
	static const ImageTarget TextureCubeMap;
	static const ImageTarget Texture1DArray;
	static const ImageTarget Texture2DArray;
	static const ImageTarget TextureBuffer;
	static const ImageTarget Renderbuffer;
	static const ImageTarget TextureCubeMapArray;
	static const ImageTarget Texture2DMultisample;
	static const ImageTarget Texture2DMultisampleArray;
OPENGL_ENUM_END

OPENGL_ENUM_START(IndexedEnableCap)
	static const IndexedEnableCap Blend;
	static const IndexedEnableCap ScissorTest;
OPENGL_ENUM_END

OPENGL_ENUM_START(IndexPointerType)
	static const IndexPointerType Short;
	static const IndexPointerType Int;
	static const IndexPointerType Float;
	static const IndexPointerType Double;
OPENGL_ENUM_END

OPENGL_ENUM_START(IngrBlendFuncSeparate)
OPENGL_ENUM_END

OPENGL_ENUM_START(IngrColorClamp)
	static const IngrColorClamp RedMinClampIngr;
	static const IngrColorClamp GreenMinClampIngr;
	static const IngrColorClamp BlueMinClampIngr;
	static const IngrColorClamp AlphaMinClampIngr;
	static const IngrColorClamp RedMaxClampIngr;
	static const IngrColorClamp GreenMaxClampIngr;
	static const IngrColorClamp BlueMaxClampIngr;
	static const IngrColorClamp AlphaMaxClampIngr;
OPENGL_ENUM_END

OPENGL_ENUM_START(IngrInterlaceRead)
	static const IngrInterlaceRead InterlaceReadIngr;
OPENGL_ENUM_END

OPENGL_ENUM_START(IntelFragmentShaderOrdering)
OPENGL_ENUM_END

OPENGL_ENUM_START(IntelMapTexture)
	static const IntelMapTexture LayoutDefaultIntel;
	static const IntelMapTexture TextureMemoryLayoutIntel;
	static const IntelMapTexture LayoutLinearIntel;
	static const IntelMapTexture LayoutLinearCpuCachedIntel;
OPENGL_ENUM_END

OPENGL_ENUM_START(IntelParallelArrays)
	static const IntelParallelArrays ParallelArraysIntel;
	static const IntelParallelArrays VertexArrayParallelPointersIntel;
	static const IntelParallelArrays NormalArrayParallelPointersIntel;
	static const IntelParallelArrays ColorArrayParallelPointersIntel;
	static const IntelParallelArrays TextureCoordArrayParallelPointersIntel;
OPENGL_ENUM_END

OPENGL_ENUM_START(IntelPerformanceQuery)
	static const IntelPerformanceQuery PerfquerySingleContextIntel;
	static const IntelPerformanceQuery PerfqueryGlobalContextIntel;
	static const IntelPerformanceQuery PerfqueryDonotFlushIntel;
	static const IntelPerformanceQuery PerfqueryFlushIntel;
	static const IntelPerformanceQuery PerfqueryWaitIntel;
	static const IntelPerformanceQuery PerfqueryCounterEventIntel;
	static const IntelPerformanceQuery PerfqueryCounterDurationNormIntel;
	static const IntelPerformanceQuery PerfqueryCounterDurationRawIntel;
	static const IntelPerformanceQuery PerfqueryCounterThroughputIntel;
	static const IntelPerformanceQuery PerfqueryCounterRawIntel;
	static const IntelPerformanceQuery PerfqueryCounterTimestampIntel;
	static const IntelPerformanceQuery PerfqueryCounterDataUint32Intel;
	static const IntelPerformanceQuery PerfqueryCounterDataUint64Intel;
	static const IntelPerformanceQuery PerfqueryCounterDataFloatIntel;
	static const IntelPerformanceQuery PerfqueryCounterDataDoubleIntel;
	static const IntelPerformanceQuery PerfqueryCounterDataBool32Intel;
	static const IntelPerformanceQuery PerfqueryQueryNameLengthMaxIntel;
	static const IntelPerformanceQuery PerfqueryCounterNameLengthMaxIntel;
	static const IntelPerformanceQuery PerfqueryCounterDescLengthMaxIntel;
	static const IntelPerformanceQuery PerfqueryGpaExtendedCountersIntel;
OPENGL_ENUM_END

OPENGL_ENUM_START(InterleavedArrayFormat)
	static const InterleavedArrayFormat V2f;
	static const InterleavedArrayFormat V3f;
	static const InterleavedArrayFormat C4ubV2f;
	static const InterleavedArrayFormat C4ubV3f;
	static const InterleavedArrayFormat C3fV3f;
	static const InterleavedArrayFormat N3fV3f;
	static const InterleavedArrayFormat C4fN3fV3f;
	static const InterleavedArrayFormat T2fV3f;
	static const InterleavedArrayFormat T4fV4f;
	static const InterleavedArrayFormat T2fC4ubV3f;
	static const InterleavedArrayFormat T2fC3fV3f;
	static const InterleavedArrayFormat T2fN3fV3f;
	static const InterleavedArrayFormat T2fC4fN3fV3f;
	static const InterleavedArrayFormat T4fC4fN3fV4f;
OPENGL_ENUM_END

OPENGL_ENUM_START(InternalFormat)
	static const InternalFormat R3G3B2;
	static const InternalFormat Alpha4;
	static const InternalFormat Alpha8;
	static const InternalFormat Alpha12;
	static const InternalFormat Alpha16;
	static const InternalFormat Luminance4;
	static const InternalFormat Luminance8;
	static const InternalFormat Luminance12;
	static const InternalFormat Luminance16;
	static const InternalFormat Luminance4Alpha4;
	static const InternalFormat Luminance6Alpha2;
	static const InternalFormat Luminance8Alpha8;
	static const InternalFormat Luminance12Alpha4;
	static const InternalFormat Luminance12Alpha12;
	static const InternalFormat Luminance16Alpha16;
	static const InternalFormat Intensity;
	static const InternalFormat Intensity4;
	static const InternalFormat Intensity8;
	static const InternalFormat Intensity12;
	static const InternalFormat Intensity16;
	static const InternalFormat Rgb2Ext;
	static const InternalFormat Rgb4;
	static const InternalFormat Rgb5;
	static const InternalFormat Rgb8;
	static const InternalFormat Rgb10;
	static const InternalFormat Rgb12;
	static const InternalFormat Rgb16;
	static const InternalFormat Rgba2;
	static const InternalFormat Rgba4;
	static const InternalFormat Rgb5A1;
	static const InternalFormat Rgba8;
	static const InternalFormat Rgb10A2;
	static const InternalFormat Rgba12;
	static const InternalFormat Rgba16;
	static const InternalFormat DualAlpha4Sgis;
	static const InternalFormat DualAlpha8Sgis;
	static const InternalFormat DualAlpha12Sgis;
	static const InternalFormat DualAlpha16Sgis;
	static const InternalFormat DualLuminance4Sgis;
	static const InternalFormat DualLuminance8Sgis;
	static const InternalFormat DualLuminance12Sgis;
	static const InternalFormat DualLuminance16Sgis;
	static const InternalFormat DualIntensity4Sgis;
	static const InternalFormat DualIntensity8Sgis;
	static const InternalFormat DualIntensity12Sgis;
	static const InternalFormat DualIntensity16Sgis;
	static const InternalFormat DualLuminanceAlpha4Sgis;
	static const InternalFormat DualLuminanceAlpha8Sgis;
	static const InternalFormat QuadAlpha4Sgis;
	static const InternalFormat QuadAlpha8Sgis;
	static const InternalFormat QuadLuminance4Sgis;
	static const InternalFormat QuadLuminance8Sgis;
	static const InternalFormat QuadIntensity4Sgis;
	static const InternalFormat QuadIntensity8Sgis;
	static const InternalFormat DepthComponent16Sgix;
	static const InternalFormat DepthComponent24Sgix;
	static const InternalFormat DepthComponent32Sgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(InternalFormatParameter)
	static const InternalFormatParameter Samples;
	static const InternalFormatParameter InternalformatSupported;
	static const InternalFormatParameter InternalformatPreferred;
	static const InternalFormatParameter InternalformatRedSize;
	static const InternalFormatParameter InternalformatGreenSize;
	static const InternalFormatParameter InternalformatBlueSize;
	static const InternalFormatParameter InternalformatAlphaSize;
	static const InternalFormatParameter InternalformatDepthSize;
	static const InternalFormatParameter InternalformatStencilSize;
	static const InternalFormatParameter InternalformatSharedSize;
	static const InternalFormatParameter InternalformatRedType;
	static const InternalFormatParameter InternalformatGreenType;
	static const InternalFormatParameter InternalformatBlueType;
	static const InternalFormatParameter InternalformatAlphaType;
	static const InternalFormatParameter InternalformatDepthType;
	static const InternalFormatParameter InternalformatStencilType;
	static const InternalFormatParameter MaxWidth;
	static const InternalFormatParameter MaxHeight;
	static const InternalFormatParameter MaxDepth;
	static const InternalFormatParameter MaxLayers;
	static const InternalFormatParameter MaxCombinedDimensions;
	static const InternalFormatParameter ColorComponents;
	static const InternalFormatParameter DepthComponents;
	static const InternalFormatParameter StencilComponents;
	static const InternalFormatParameter ColorRenderable;
	static const InternalFormatParameter DepthRenderable;
	static const InternalFormatParameter StencilRenderable;
	static const InternalFormatParameter FramebufferRenderable;
	static const InternalFormatParameter FramebufferRenderableLayered;
	static const InternalFormatParameter FramebufferBlend;
	static const InternalFormatParameter ReadPixelsFormat;
	static const InternalFormatParameter ReadPixelsType;
	static const InternalFormatParameter TextureImageFormat;
	static const InternalFormatParameter TextureImageType;
	static const InternalFormatParameter GetTextureImageFormat;
	static const InternalFormatParameter GetTextureImageType;
	static const InternalFormatParameter Mipmap;
	static const InternalFormatParameter ManualGenerateMipmap;
	static const InternalFormatParameter ColorEncoding;
	static const InternalFormatParameter SrgbRead;
	static const InternalFormatParameter SrgbWrite;
	static const InternalFormatParameter Filter;
	static const InternalFormatParameter VertexTexture;
	static const InternalFormatParameter TessControlTexture;
	static const InternalFormatParameter TessEvaluationTexture;
	static const InternalFormatParameter GeometryTexture;
	static const InternalFormatParameter FragmentTexture;
	static const InternalFormatParameter ComputeTexture;
	static const InternalFormatParameter TextureShadow;
	static const InternalFormatParameter TextureGather;
	static const InternalFormatParameter TextureGatherShadow;
	static const InternalFormatParameter ShaderImageLoad;
	static const InternalFormatParameter ShaderImageStore;
	static const InternalFormatParameter ShaderImageAtomic;
	static const InternalFormatParameter ImageTexelSize;
	static const InternalFormatParameter ImageCompatibilityClass;
	static const InternalFormatParameter ImagePixelFormat;
	static const InternalFormatParameter ImagePixelType;
	static const InternalFormatParameter SimultaneousTextureAndDepthTest;
	static const InternalFormatParameter SimultaneousTextureAndStencilTest;
	static const InternalFormatParameter SimultaneousTextureAndStencilWrite;
	static const InternalFormatParameter TextureCompressedBlockWidth;
	static const InternalFormatParameter TextureCompressedBlockHeight;
	static const InternalFormatParameter TextureCompressedBlockSize;
	static const InternalFormatParameter ClearBuffer;
	static const InternalFormatParameter TextureView;
	static const InternalFormatParameter ViewCompatibilityClass;
	static const InternalFormatParameter TextureCompressed;
	static const InternalFormatParameter ImageFormatCompatibilityType;
	static const InternalFormatParameter ClearTexture;
	static const InternalFormatParameter NumSampleCounts;
OPENGL_ENUM_END

OPENGL_ENUM_START(KhrBlendEquationAdvanced)
	static const KhrBlendEquationAdvanced BlendAdvancedCoherentKhr;
	static const KhrBlendEquationAdvanced MultiplyKhr;
	static const KhrBlendEquationAdvanced ScreenKhr;
	static const KhrBlendEquationAdvanced OverlayKhr;
	static const KhrBlendEquationAdvanced DarkenKhr;
	static const KhrBlendEquationAdvanced LightenKhr;
	static const KhrBlendEquationAdvanced ColordodgeKhr;
	static const KhrBlendEquationAdvanced ColorburnKhr;
	static const KhrBlendEquationAdvanced HardlightKhr;
	static const KhrBlendEquationAdvanced SoftlightKhr;
	static const KhrBlendEquationAdvanced DifferenceKhr;
	static const KhrBlendEquationAdvanced ExclusionKhr;
	static const KhrBlendEquationAdvanced HslHueKhr;
	static const KhrBlendEquationAdvanced HslSaturationKhr;
	static const KhrBlendEquationAdvanced HslColorKhr;
	static const KhrBlendEquationAdvanced HslLuminosityKhr;
OPENGL_ENUM_END

OPENGL_ENUM_START(KhrBlendEquationAdvancedCoherent)
	static const KhrBlendEquationAdvancedCoherent BlendAdvancedCoherentKhr;
OPENGL_ENUM_END

OPENGL_ENUM_START(KhrContextFlushControl)
	static const KhrContextFlushControl None;
	static const KhrContextFlushControl ContextReleaseBehavior;
	static const KhrContextFlushControl ContextReleaseBehaviorKhr;
	static const KhrContextFlushControl ContextReleaseBehaviorFlush;
	static const KhrContextFlushControl ContextReleaseBehaviorFlushKhr;
OPENGL_ENUM_END

OPENGL_ENUM_START(KhrDebug)
	static const KhrDebug ContextFlagDebugBit;
	static const KhrDebug ContextFlagDebugBitKhr;
	static const KhrDebug StackOverflow;
	static const KhrDebug StackOverflowKhr;
	static const KhrDebug StackUnderflow;
	static const KhrDebug StackUnderflowKhr;
	static const KhrDebug VertexArray;
	static const KhrDebug VertexArrayKhr;
	static const KhrDebug DebugOutputSynchronous;
	static const KhrDebug DebugOutputSynchronousKhr;
	static const KhrDebug DebugNextLoggedMessageLength;
	static const KhrDebug DebugNextLoggedMessageLengthKhr;
	static const KhrDebug DebugCallbackFunction;
	static const KhrDebug DebugCallbackFunctionKhr;
	static const KhrDebug DebugCallbackUserParam;
	static const KhrDebug DebugCallbackUserParamKhr;
	static const KhrDebug DebugSourceApi;
	static const KhrDebug DebugSourceApiKhr;
	static const KhrDebug DebugSourceWindowSystem;
	static const KhrDebug DebugSourceWindowSystemKhr;
	static const KhrDebug DebugSourceShaderCompiler;
	static const KhrDebug DebugSourceShaderCompilerKhr;
	static const KhrDebug DebugSourceThirdParty;
	static const KhrDebug DebugSourceThirdPartyKhr;
	static const KhrDebug DebugSourceApplication;
	static const KhrDebug DebugSourceApplicationKhr;
	static const KhrDebug DebugSourceOther;
	static const KhrDebug DebugSourceOtherKhr;
	static const KhrDebug DebugTypeError;
	static const KhrDebug DebugTypeErrorKhr;
	static const KhrDebug DebugTypeDeprecatedBehavior;
	static const KhrDebug DebugTypeDeprecatedBehaviorKhr;
	static const KhrDebug DebugTypeUndefinedBehavior;
	static const KhrDebug DebugTypeUndefinedBehaviorKhr;
	static const KhrDebug DebugTypePortability;
	static const KhrDebug DebugTypePortabilityKhr;
	static const KhrDebug DebugTypePerformance;
	static const KhrDebug DebugTypePerformanceKhr;
	static const KhrDebug DebugTypeOther;
	static const KhrDebug DebugTypeOtherKhr;
	static const KhrDebug DebugTypeMarker;
	static const KhrDebug DebugTypeMarkerKhr;
	static const KhrDebug DebugTypePushGroup;
	static const KhrDebug DebugTypePushGroupKhr;
	static const KhrDebug DebugTypePopGroup;
	static const KhrDebug DebugTypePopGroupKhr;
	static const KhrDebug DebugSeverityNotification;
	static const KhrDebug DebugSeverityNotificationKhr;
	static const KhrDebug MaxDebugGroupStackDepth;
	static const KhrDebug MaxDebugGroupStackDepthKhr;
	static const KhrDebug DebugGroupStackDepth;
	static const KhrDebug DebugGroupStackDepthKhr;
	static const KhrDebug Buffer;
	static const KhrDebug BufferKhr;
	static const KhrDebug Shader;
	static const KhrDebug ShaderKhr;
	static const KhrDebug Program;
	static const KhrDebug ProgramKhr;
	static const KhrDebug Query;
	static const KhrDebug QueryKhr;
	static const KhrDebug ProgramPipeline;
	static const KhrDebug Sampler;
	static const KhrDebug SamplerKhr;
	static const KhrDebug DisplayList;
	static const KhrDebug MaxLabelLength;
	static const KhrDebug MaxLabelLengthKhr;
	static const KhrDebug MaxDebugMessageLength;
	static const KhrDebug MaxDebugMessageLengthKhr;
	static const KhrDebug MaxDebugLoggedMessages;
	static const KhrDebug MaxDebugLoggedMessagesKhr;
	static const KhrDebug DebugLoggedMessages;
	static const KhrDebug DebugLoggedMessagesKhr;
	static const KhrDebug DebugSeverityHigh;
	static const KhrDebug DebugSeverityHighKhr;
	static const KhrDebug DebugSeverityMedium;
	static const KhrDebug DebugSeverityMediumKhr;
	static const KhrDebug DebugSeverityLow;
	static const KhrDebug DebugSeverityLowKhr;
	static const KhrDebug DebugOutput;
	static const KhrDebug DebugOutputKhr;
OPENGL_ENUM_END

OPENGL_ENUM_START(KhrRobustBufferAccessBehavior)
OPENGL_ENUM_END

OPENGL_ENUM_START(KhrRobustness)
	static const KhrRobustness NoError;
	static const KhrRobustness ContextLost;
	static const KhrRobustness ContextLostKhr;
	static const KhrRobustness LoseContextOnReset;
	static const KhrRobustness LoseContextOnResetKhr;
	static const KhrRobustness GuiltyContextReset;
	static const KhrRobustness GuiltyContextResetKhr;
	static const KhrRobustness InnocentContextReset;
	static const KhrRobustness InnocentContextResetKhr;
	static const KhrRobustness UnknownContextReset;
	static const KhrRobustness UnknownContextResetKhr;
	static const KhrRobustness ResetNotificationStrategy;
	static const KhrRobustness ResetNotificationStrategyKhr;
	static const KhrRobustness NoResetNotification;
	static const KhrRobustness NoResetNotificationKhr;
	static const KhrRobustness ContextRobustAccess;
	static const KhrRobustness ContextRobustAccessKhr;
OPENGL_ENUM_END

OPENGL_ENUM_START(KhrTextureCompressionAstcHdr)
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc4X4Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc5X4Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc5X5Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc6X5Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc6X6Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc8X5Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc8X6Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc8X8Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc10X5Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc10X6Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc10X8Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc10X10Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc12X10Khr;
	static const KhrTextureCompressionAstcHdr CompressedRgbaAstc12X12Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc4X4Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc5X4Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc5X5Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc6X5Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc6X6Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc8X5Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc8X6Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc8X8Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc10X5Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc10X6Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc10X8Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc10X10Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc12X10Khr;
	static const KhrTextureCompressionAstcHdr CompressedSrgb8Alpha8Astc12X12Khr;
OPENGL_ENUM_END

OPENGL_ENUM_START(KhrTextureCompressionAstcLdr)
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc4X4Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc5X4Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc5X5Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc6X5Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc6X6Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc8X5Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc8X6Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc8X8Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc10X5Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc10X6Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc10X8Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc10X10Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc12X10Khr;
	static const KhrTextureCompressionAstcLdr CompressedRgbaAstc12X12Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc4X4Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc5X4Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc5X5Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc6X5Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc6X6Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc8X5Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc8X6Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc8X8Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc10X5Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc10X6Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc10X8Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc10X10Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc12X10Khr;
	static const KhrTextureCompressionAstcLdr CompressedSrgb8Alpha8Astc12X12Khr;
OPENGL_ENUM_END

OPENGL_ENUM_START(LightEnvModeSgix)
	static const LightEnvModeSgix Add;
	static const LightEnvModeSgix Replace;
	static const LightEnvModeSgix Modulate;
OPENGL_ENUM_END

OPENGL_ENUM_START(LightEnvParameterSgix)
	static const LightEnvParameterSgix LightEnvModeSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(LightModelColorControl)
	static const LightModelColorControl SingleColor;
	static const LightModelColorControl SingleColorExt;
	static const LightModelColorControl SeparateSpecularColor;
	static const LightModelColorControl SeparateSpecularColorExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(LightModelParameter)
	static const LightModelParameter LightModelLocalViewer;
	static const LightModelParameter LightModelTwoSide;
	static const LightModelParameter LightModelAmbient;
	static const LightModelParameter LightModelColorControl;
	static const LightModelParameter LightModelColorControlExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(LightName)
	static const LightName Light0;
	static const LightName Light1;
	static const LightName Light2;
	static const LightName Light3;
	static const LightName Light4;
	static const LightName Light5;
	static const LightName Light6;
	static const LightName Light7;
	static const LightName FragmentLight0Sgix;
	static const LightName FragmentLight1Sgix;
	static const LightName FragmentLight2Sgix;
	static const LightName FragmentLight3Sgix;
	static const LightName FragmentLight4Sgix;
	static const LightName FragmentLight5Sgix;
	static const LightName FragmentLight6Sgix;
	static const LightName FragmentLight7Sgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(LightParameter)
	static const LightParameter Ambient;
	static const LightParameter Diffuse;
	static const LightParameter Specular;
	static const LightParameter Position;
	static const LightParameter SpotDirection;
	static const LightParameter SpotExponent;
	static const LightParameter SpotCutoff;
	static const LightParameter ConstantAttenuation;
	static const LightParameter LinearAttenuation;
	static const LightParameter QuadraticAttenuation;
OPENGL_ENUM_END

OPENGL_ENUM_START(ListMode)
	static const ListMode Compile;
	static const ListMode CompileAndExecute;
OPENGL_ENUM_END

OPENGL_ENUM_START(ListNameType)
	static const ListNameType Byte;
	static const ListNameType UnsignedByte;
	static const ListNameType Short;
	static const ListNameType UnsignedShort;
	static const ListNameType Int;
	static const ListNameType UnsignedInt;
	static const ListNameType Float;
	static const ListNameType Gl2Bytes;
	static const ListNameType Gl3Bytes;
	static const ListNameType Gl4Bytes;
OPENGL_ENUM_END

OPENGL_ENUM_START(ListParameterName)
	static const ListParameterName ListPrioritySgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(LogicOp)
	static const LogicOp Clear;
	static const LogicOp And;
	static const LogicOp AndReverse;
	static const LogicOp Copy;
	static const LogicOp AndInverted;
	static const LogicOp Noop;
	static const LogicOp Xor;
	static const LogicOp Or;
	static const LogicOp Nor;
	static const LogicOp Equiv;
	static const LogicOp Invert;
	static const LogicOp OrReverse;
	static const LogicOp CopyInverted;
	static const LogicOp OrInverted;
	static const LogicOp Nand;
	static const LogicOp Set;
OPENGL_ENUM_END

OPENGL_ENUM_START(MapBufferUsageMask)
	static const MapBufferUsageMask MapReadBit;
	static const MapBufferUsageMask MapReadBitExt;
	static const MapBufferUsageMask MapWriteBit;
	static const MapBufferUsageMask MapWriteBitExt;
	static const MapBufferUsageMask MapInvalidateRangeBit;
	static const MapBufferUsageMask MapInvalidateRangeBitExt;
	static const MapBufferUsageMask MapInvalidateBufferBit;
	static const MapBufferUsageMask MapInvalidateBufferBitExt;
	static const MapBufferUsageMask MapFlushExplicitBit;
	static const MapBufferUsageMask MapFlushExplicitBitExt;
	static const MapBufferUsageMask MapUnsynchronizedBit;
	static const MapBufferUsageMask MapUnsynchronizedBitExt;
	static const MapBufferUsageMask MapPersistentBit;
	static const MapBufferUsageMask MapCoherentBit;
	static const MapBufferUsageMask DynamicStorageBit;
	static const MapBufferUsageMask ClientStorageBit;
OPENGL_ENUM_END

OPENGL_ENUM_START(MapTarget)
	static const MapTarget Map1Color4;
	static const MapTarget Map1Index;
	static const MapTarget Map1Normal;
	static const MapTarget Map1TextureCoord1;
	static const MapTarget Map1TextureCoord2;
	static const MapTarget Map1TextureCoord3;
	static const MapTarget Map1TextureCoord4;
	static const MapTarget Map1Vertex3;
	static const MapTarget Map1Vertex4;
	static const MapTarget Map2Color4;
	static const MapTarget Map2Index;
	static const MapTarget Map2Normal;
	static const MapTarget Map2TextureCoord1;
	static const MapTarget Map2TextureCoord2;
	static const MapTarget Map2TextureCoord3;
	static const MapTarget Map2TextureCoord4;
	static const MapTarget Map2Vertex3;
	static const MapTarget Map2Vertex4;
	static const MapTarget GeometryDeformationSgix;
	static const MapTarget TextureDeformationSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(MapTextureFormatIntel)
	static const MapTextureFormatIntel LayoutDefaultIntel;
	static const MapTextureFormatIntel LayoutLinearIntel;
	static const MapTextureFormatIntel LayoutLinearCpuCachedIntel;
OPENGL_ENUM_END

OPENGL_ENUM_START(MaterialFace)
	static const MaterialFace Front;
	static const MaterialFace Back;
	static const MaterialFace FrontAndBack;
OPENGL_ENUM_END

OPENGL_ENUM_START(MaterialParameter)
	static const MaterialParameter Ambient;
	static const MaterialParameter Diffuse;
	static const MaterialParameter Specular;
	static const MaterialParameter Emission;
	static const MaterialParameter Shininess;
	static const MaterialParameter AmbientAndDiffuse;
	static const MaterialParameter ColorIndexes;
OPENGL_ENUM_END

OPENGL_ENUM_START(MatrixMode)
	static const MatrixMode Modelview;
	static const MatrixMode Modelview0Ext;
	static const MatrixMode Projection;
	static const MatrixMode Texture;
	static const MatrixMode Color;
OPENGL_ENUM_END

OPENGL_ENUM_START(MatrixModeArb)
	static const MatrixModeArb Modelview;
	static const MatrixModeArb Projection;
	static const MatrixModeArb Texture;
	static const MatrixModeArb Color;
	static const MatrixModeArb Matrix0;
	static const MatrixModeArb Matrix1;
	static const MatrixModeArb Matrix2;
	static const MatrixModeArb Matrix3;
	static const MatrixModeArb Matrix4;
	static const MatrixModeArb Matrix5;
	static const MatrixModeArb Matrix6;
	static const MatrixModeArb Matrix7;
	static const MatrixModeArb Matrix8;
	static const MatrixModeArb Matrix9;
	static const MatrixModeArb Matrix10;
	static const MatrixModeArb Matrix11;
	static const MatrixModeArb Matrix12;
	static const MatrixModeArb Matrix13;
	static const MatrixModeArb Matrix14;
	static const MatrixModeArb Matrix15;
	static const MatrixModeArb Matrix16;
	static const MatrixModeArb Matrix17;
	static const MatrixModeArb Matrix18;
	static const MatrixModeArb Matrix19;
	static const MatrixModeArb Matrix20;
	static const MatrixModeArb Matrix21;
	static const MatrixModeArb Matrix22;
	static const MatrixModeArb Matrix23;
	static const MatrixModeArb Matrix24;
	static const MatrixModeArb Matrix25;
	static const MatrixModeArb Matrix26;
	static const MatrixModeArb Matrix27;
	static const MatrixModeArb Matrix28;
	static const MatrixModeArb Matrix29;
	static const MatrixModeArb Matrix30;
	static const MatrixModeArb Matrix31;
OPENGL_ENUM_END

OPENGL_ENUM_START(MemoryBarrierFlags)
	static const MemoryBarrierFlags VertexAttribArrayBarrierBit;
	static const MemoryBarrierFlags ElementArrayBarrierBit;
	static const MemoryBarrierFlags UniformBarrierBit;
	static const MemoryBarrierFlags TextureFetchBarrierBit;
	static const MemoryBarrierFlags ShaderImageAccessBarrierBit;
	static const MemoryBarrierFlags CommandBarrierBit;
	static const MemoryBarrierFlags PixelBufferBarrierBit;
	static const MemoryBarrierFlags TextureUpdateBarrierBit;
	static const MemoryBarrierFlags BufferUpdateBarrierBit;
	static const MemoryBarrierFlags FramebufferBarrierBit;
	static const MemoryBarrierFlags TransformFeedbackBarrierBit;
	static const MemoryBarrierFlags AtomicCounterBarrierBit;
	static const MemoryBarrierFlags ShaderStorageBarrierBit;
	static const MemoryBarrierFlags ClientMappedBufferBarrierBit;
	static const MemoryBarrierFlags QueryBufferBarrierBit;
	static const MemoryBarrierFlags AllBarrierBits;
OPENGL_ENUM_END

OPENGL_ENUM_START(MemoryBarrierMask)
	static const MemoryBarrierMask VertexAttribArrayBarrierBit;
	static const MemoryBarrierMask VertexAttribArrayBarrierBitExt;
	static const MemoryBarrierMask ElementArrayBarrierBit;
	static const MemoryBarrierMask ElementArrayBarrierBitExt;
	static const MemoryBarrierMask UniformBarrierBit;
	static const MemoryBarrierMask UniformBarrierBitExt;
	static const MemoryBarrierMask TextureFetchBarrierBit;
	static const MemoryBarrierMask TextureFetchBarrierBitExt;
	static const MemoryBarrierMask ShaderGlobalAccessBarrierBitNv;
	static const MemoryBarrierMask ShaderImageAccessBarrierBit;
	static const MemoryBarrierMask ShaderImageAccessBarrierBitExt;
	static const MemoryBarrierMask CommandBarrierBit;
	static const MemoryBarrierMask CommandBarrierBitExt;
	static const MemoryBarrierMask PixelBufferBarrierBit;
	static const MemoryBarrierMask PixelBufferBarrierBitExt;
	static const MemoryBarrierMask TextureUpdateBarrierBit;
	static const MemoryBarrierMask TextureUpdateBarrierBitExt;
	static const MemoryBarrierMask BufferUpdateBarrierBit;
	static const MemoryBarrierMask BufferUpdateBarrierBitExt;
	static const MemoryBarrierMask FramebufferBarrierBit;
	static const MemoryBarrierMask FramebufferBarrierBitExt;
	static const MemoryBarrierMask TransformFeedbackBarrierBit;
	static const MemoryBarrierMask TransformFeedbackBarrierBitExt;
	static const MemoryBarrierMask AtomicCounterBarrierBit;
	static const MemoryBarrierMask AtomicCounterBarrierBitExt;
	static const MemoryBarrierMask ShaderStorageBarrierBit;
	static const MemoryBarrierMask ClientMappedBufferBarrierBit;
	static const MemoryBarrierMask QueryBufferBarrierBit;
	static const MemoryBarrierMask AllBarrierBits;
	static const MemoryBarrierMask AllBarrierBitsExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(MemoryBarrierRegionFlags)
	static const MemoryBarrierRegionFlags GlUniformBarrierBit;
	static const MemoryBarrierRegionFlags GlTextureFetchBarrierBit;
	static const MemoryBarrierRegionFlags GlShaderImageAccessBarrierBit;
	static const MemoryBarrierRegionFlags GlFramebufferBarrierBit;
	static const MemoryBarrierRegionFlags GlAtomicCounterBarrierBit;
	static const MemoryBarrierRegionFlags GlAllBarrierBits;
OPENGL_ENUM_END

OPENGL_ENUM_START(MesaPackInvert)
	static const MesaPackInvert PackInvertMesa;
OPENGL_ENUM_END

OPENGL_ENUM_START(MesaResizeBuffers)
OPENGL_ENUM_END

OPENGL_ENUM_START(MesaWindowPos)
OPENGL_ENUM_END

OPENGL_ENUM_START(MesaxTextureStack)
	static const MesaxTextureStack Texture1DStackMesax;
	static const MesaxTextureStack Texture2DStackMesax;
	static const MesaxTextureStack ProxyTexture1DStackMesax;
	static const MesaxTextureStack ProxyTexture2DStackMesax;
	static const MesaxTextureStack Texture1DStackBindingMesax;
	static const MesaxTextureStack Texture2DStackBindingMesax;
OPENGL_ENUM_END

OPENGL_ENUM_START(MesaYcbcrTexture)
	static const MesaYcbcrTexture UnsignedShort88Mesa;
	static const MesaYcbcrTexture UnsignedShort88RevMesa;
	static const MesaYcbcrTexture YcbcrMesa;
OPENGL_ENUM_END

OPENGL_ENUM_START(MeshMode1)
	static const MeshMode1 Point;
	static const MeshMode1 Line;
OPENGL_ENUM_END

OPENGL_ENUM_START(MeshMode2)
	static const MeshMode2 Point;
	static const MeshMode2 Line;
	static const MeshMode2 Fill;
OPENGL_ENUM_END

OPENGL_ENUM_START(MinmaxTarget)
	static const MinmaxTarget Minmax;
OPENGL_ENUM_END

OPENGL_ENUM_START(MinmaxTargetExt)
	static const MinmaxTargetExt Minmax;
	static const MinmaxTargetExt MinmaxExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(NormalPointerType)
	static const NormalPointerType Byte;
	static const NormalPointerType Short;
	static const NormalPointerType Int;
	static const NormalPointerType Float;
	static const NormalPointerType Double;
	static const NormalPointerType HalfFloat;
	static const NormalPointerType UnsignedInt2101010Rev;
	static const NormalPointerType Int2101010Rev;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvBindlessMultiDrawIndirect)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvBindlessMultiDrawIndirectCount)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvBindlessTexture)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvBlendEquationAdvanced)
	static const NvBlendEquationAdvanced Zero;
	static const NvBlendEquationAdvanced XorNv;
	static const NvBlendEquationAdvanced Invert;
	static const NvBlendEquationAdvanced RedNv;
	static const NvBlendEquationAdvanced GreenNv;
	static const NvBlendEquationAdvanced BlueNv;
	static const NvBlendEquationAdvanced BlendPremultipliedSrcNv;
	static const NvBlendEquationAdvanced BlendOverlapNv;
	static const NvBlendEquationAdvanced UncorrelatedNv;
	static const NvBlendEquationAdvanced DisjointNv;
	static const NvBlendEquationAdvanced ConjointNv;
	static const NvBlendEquationAdvanced SrcNv;
	static const NvBlendEquationAdvanced DstNv;
	static const NvBlendEquationAdvanced SrcOverNv;
	static const NvBlendEquationAdvanced DstOverNv;
	static const NvBlendEquationAdvanced SrcInNv;
	static const NvBlendEquationAdvanced DstInNv;
	static const NvBlendEquationAdvanced SrcOutNv;
	static const NvBlendEquationAdvanced DstOutNv;
	static const NvBlendEquationAdvanced SrcAtopNv;
	static const NvBlendEquationAdvanced DstAtopNv;
	static const NvBlendEquationAdvanced PlusNv;
	static const NvBlendEquationAdvanced PlusDarkerNv;
	static const NvBlendEquationAdvanced MultiplyNv;
	static const NvBlendEquationAdvanced ScreenNv;
	static const NvBlendEquationAdvanced OverlayNv;
	static const NvBlendEquationAdvanced DarkenNv;
	static const NvBlendEquationAdvanced LightenNv;
	static const NvBlendEquationAdvanced ColordodgeNv;
	static const NvBlendEquationAdvanced ColorburnNv;
	static const NvBlendEquationAdvanced HardlightNv;
	static const NvBlendEquationAdvanced SoftlightNv;
	static const NvBlendEquationAdvanced DifferenceNv;
	static const NvBlendEquationAdvanced MinusNv;
	static const NvBlendEquationAdvanced ExclusionNv;
	static const NvBlendEquationAdvanced ContrastNv;
	static const NvBlendEquationAdvanced InvertRgbNv;
	static const NvBlendEquationAdvanced LineardodgeNv;
	static const NvBlendEquationAdvanced LinearburnNv;
	static const NvBlendEquationAdvanced VividlightNv;
	static const NvBlendEquationAdvanced LinearlightNv;
	static const NvBlendEquationAdvanced PinlightNv;
	static const NvBlendEquationAdvanced HardmixNv;
	static const NvBlendEquationAdvanced HslHueNv;
	static const NvBlendEquationAdvanced HslSaturationNv;
	static const NvBlendEquationAdvanced HslColorNv;
	static const NvBlendEquationAdvanced HslLuminosityNv;
	static const NvBlendEquationAdvanced PlusClampedNv;
	static const NvBlendEquationAdvanced PlusClampedAlphaNv;
	static const NvBlendEquationAdvanced MinusClampedNv;
	static const NvBlendEquationAdvanced InvertOvgNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvBlendEquationAdvancedCoherent)
	static const NvBlendEquationAdvancedCoherent BlendAdvancedCoherentNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvBlendSquare)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvComputeProgram5)
	static const NvComputeProgram5 ComputeProgramNv;
	static const NvComputeProgram5 ComputeProgramParameterBufferNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvConditionalRender)
	static const NvConditionalRender QueryWaitNv;
	static const NvConditionalRender QueryNoWaitNv;
	static const NvConditionalRender QueryByRegionWaitNv;
	static const NvConditionalRender QueryByRegionNoWaitNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvCopyDepthToColor)
	static const NvCopyDepthToColor DepthStencilToRgbaNv;
	static const NvCopyDepthToColor DepthStencilToBgraNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvCopyImage)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvDeepTexture3D)
	static const NvDeepTexture3D MaxDeep3DTextureWidthHeightNv;
	static const NvDeepTexture3D MaxDeep3DTextureDepthNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvDepthBufferFloat)
	static const NvDepthBufferFloat DepthComponent32fNv;
	static const NvDepthBufferFloat Depth32fStencil8Nv;
	static const NvDepthBufferFloat Float32UnsignedInt248RevNv;
	static const NvDepthBufferFloat DepthBufferFloatModeNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvDepthClamp)
	static const NvDepthClamp DepthClampNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvDrawTexture)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvEvaluators)
	static const NvEvaluators Eval2DNv;
	static const NvEvaluators EvalTriangular2DNv;
	static const NvEvaluators MapTessellationNv;
	static const NvEvaluators MapAttribUOrderNv;
	static const NvEvaluators MapAttribVOrderNv;
	static const NvEvaluators EvalFractionalTessellationNv;
	static const NvEvaluators EvalVertexAttrib0Nv;
	static const NvEvaluators EvalVertexAttrib1Nv;
	static const NvEvaluators EvalVertexAttrib2Nv;
	static const NvEvaluators EvalVertexAttrib3Nv;
	static const NvEvaluators EvalVertexAttrib4Nv;
	static const NvEvaluators EvalVertexAttrib5Nv;
	static const NvEvaluators EvalVertexAttrib6Nv;
	static const NvEvaluators EvalVertexAttrib7Nv;
	static const NvEvaluators EvalVertexAttrib8Nv;
	static const NvEvaluators EvalVertexAttrib9Nv;
	static const NvEvaluators EvalVertexAttrib10Nv;
	static const NvEvaluators EvalVertexAttrib11Nv;
	static const NvEvaluators EvalVertexAttrib12Nv;
	static const NvEvaluators EvalVertexAttrib13Nv;
	static const NvEvaluators EvalVertexAttrib14Nv;
	static const NvEvaluators EvalVertexAttrib15Nv;
	static const NvEvaluators MaxMapTessellationNv;
	static const NvEvaluators MaxRationalEvalOrderNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvExplicitMultisample)
	static const NvExplicitMultisample SamplePositionNv;
	static const NvExplicitMultisample SampleMaskNv;
	static const NvExplicitMultisample SampleMaskValueNv;
	static const NvExplicitMultisample TextureBindingRenderbufferNv;
	static const NvExplicitMultisample TextureRenderbufferDataStoreBindingNv;
	static const NvExplicitMultisample TextureRenderbufferNv;
	static const NvExplicitMultisample SamplerRenderbufferNv;
	static const NvExplicitMultisample IntSamplerRenderbufferNv;
	static const NvExplicitMultisample UnsignedIntSamplerRenderbufferNv;
	static const NvExplicitMultisample MaxSampleMaskWordsNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvFence)
	static const NvFence AllCompletedNv;
	static const NvFence FenceStatusNv;
	static const NvFence FenceConditionNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvFloatBuffer)
	static const NvFloatBuffer FloatRNv;
	static const NvFloatBuffer FloatRgNv;
	static const NvFloatBuffer FloatRgbNv;
	static const NvFloatBuffer FloatRgbaNv;
	static const NvFloatBuffer FloatR16Nv;
	static const NvFloatBuffer FloatR32Nv;
	static const NvFloatBuffer FloatRg16Nv;
	static const NvFloatBuffer FloatRg32Nv;
	static const NvFloatBuffer FloatRgb16Nv;
	static const NvFloatBuffer FloatRgb32Nv;
	static const NvFloatBuffer FloatRgba16Nv;
	static const NvFloatBuffer FloatRgba32Nv;
	static const NvFloatBuffer TextureFloatComponentsNv;
	static const NvFloatBuffer FloatClearColorValueNv;
	static const NvFloatBuffer FloatRgbaModeNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvFogDistance)
	static const NvFogDistance EyePlane;
	static const NvFogDistance FogDistanceModeNv;
	static const NvFogDistance EyeRadialNv;
	static const NvFogDistance EyePlaneAbsoluteNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvFragmentProgram)
	static const NvFragmentProgram MaxFragmentProgramLocalParametersNv;
	static const NvFragmentProgram FragmentProgramNv;
	static const NvFragmentProgram MaxTextureCoordsNv;
	static const NvFragmentProgram MaxTextureImageUnitsNv;
	static const NvFragmentProgram FragmentProgramBindingNv;
	static const NvFragmentProgram ProgramErrorStringNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvFragmentProgram2)
	static const NvFragmentProgram2 MaxProgramExecInstructionsNv;
	static const NvFragmentProgram2 MaxProgramCallDepthNv;
	static const NvFragmentProgram2 MaxProgramIfDepthNv;
	static const NvFragmentProgram2 MaxProgramLoopDepthNv;
	static const NvFragmentProgram2 MaxProgramLoopCountNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvFragmentProgram4)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvFragmentProgramOption)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvFramebufferMultisampleCoverage)
	static const NvFramebufferMultisampleCoverage RenderbufferCoverageSamplesNv;
	static const NvFramebufferMultisampleCoverage RenderbufferColorSamplesNv;
	static const NvFramebufferMultisampleCoverage MaxMultisampleCoverageModesNv;
	static const NvFramebufferMultisampleCoverage MultisampleCoverageModesNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvGeometryProgram4)
	static const NvGeometryProgram4 LinesAdjacencyExt;
	static const NvGeometryProgram4 LineStripAdjacencyExt;
	static const NvGeometryProgram4 TrianglesAdjacencyExt;
	static const NvGeometryProgram4 TriangleStripAdjacencyExt;
	static const NvGeometryProgram4 ProgramPointSizeExt;
	static const NvGeometryProgram4 GeometryProgramNv;
	static const NvGeometryProgram4 MaxProgramOutputVerticesNv;
	static const NvGeometryProgram4 MaxProgramTotalOutputComponentsNv;
	static const NvGeometryProgram4 MaxGeometryTextureImageUnitsExt;
	static const NvGeometryProgram4 FramebufferAttachmentTextureLayerExt;
	static const NvGeometryProgram4 FramebufferAttachmentLayeredExt;
	static const NvGeometryProgram4 FramebufferIncompleteLayerTargetsExt;
	static const NvGeometryProgram4 FramebufferIncompleteLayerCountExt;
	static const NvGeometryProgram4 GeometryVerticesOutExt;
	static const NvGeometryProgram4 GeometryInputTypeExt;
	static const NvGeometryProgram4 GeometryOutputTypeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvGeometryShader4)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvGpuProgram4)
	static const NvGpuProgram4 MinProgramTexelOffsetNv;
	static const NvGpuProgram4 MaxProgramTexelOffsetNv;
	static const NvGpuProgram4 ProgramAttribComponentsNv;
	static const NvGpuProgram4 ProgramResultComponentsNv;
	static const NvGpuProgram4 MaxProgramAttribComponentsNv;
	static const NvGpuProgram4 MaxProgramResultComponentsNv;
	static const NvGpuProgram4 MaxProgramGenericAttribsNv;
	static const NvGpuProgram4 MaxProgramGenericResultsNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvGpuProgram5)
	static const NvGpuProgram5 MaxGeometryProgramInvocationsNv;
	static const NvGpuProgram5 MinFragmentInterpolationOffsetNv;
	static const NvGpuProgram5 MaxFragmentInterpolationOffsetNv;
	static const NvGpuProgram5 FragmentProgramInterpolationOffsetBitsNv;
	static const NvGpuProgram5 MinProgramTextureGatherOffsetNv;
	static const NvGpuProgram5 MaxProgramTextureGatherOffsetNv;
	static const NvGpuProgram5 MaxProgramSubroutineParametersNv;
	static const NvGpuProgram5 MaxProgramSubroutineNumNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvGpuProgram5MemExtended)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvGpuShader5)
	static const NvGpuShader5 Patches;
	static const NvGpuShader5 Int64Nv;
	static const NvGpuShader5 UnsignedInt64Nv;
	static const NvGpuShader5 Int8Nv;
	static const NvGpuShader5 Int8Vec2Nv;
	static const NvGpuShader5 Int8Vec3Nv;
	static const NvGpuShader5 Int8Vec4Nv;
	static const NvGpuShader5 Int16Nv;
	static const NvGpuShader5 Int16Vec2Nv;
	static const NvGpuShader5 Int16Vec3Nv;
	static const NvGpuShader5 Int16Vec4Nv;
	static const NvGpuShader5 Int64Vec2Nv;
	static const NvGpuShader5 Int64Vec3Nv;
	static const NvGpuShader5 Int64Vec4Nv;
	static const NvGpuShader5 UnsignedInt8Nv;
	static const NvGpuShader5 UnsignedInt8Vec2Nv;
	static const NvGpuShader5 UnsignedInt8Vec3Nv;
	static const NvGpuShader5 UnsignedInt8Vec4Nv;
	static const NvGpuShader5 UnsignedInt16Nv;
	static const NvGpuShader5 UnsignedInt16Vec2Nv;
	static const NvGpuShader5 UnsignedInt16Vec3Nv;
	static const NvGpuShader5 UnsignedInt16Vec4Nv;
	static const NvGpuShader5 UnsignedInt64Vec2Nv;
	static const NvGpuShader5 UnsignedInt64Vec3Nv;
	static const NvGpuShader5 UnsignedInt64Vec4Nv;
	static const NvGpuShader5 Float16Nv;
	static const NvGpuShader5 Float16Vec2Nv;
	static const NvGpuShader5 Float16Vec3Nv;
	static const NvGpuShader5 Float16Vec4Nv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvHalfFloat)
	static const NvHalfFloat HalfFloatNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvLightMaxExponent)
	static const NvLightMaxExponent MaxShininessNv;
	static const NvLightMaxExponent MaxSpotExponentNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvMultisampleCoverage)
	static const NvMultisampleCoverage SamplesArb;
	static const NvMultisampleCoverage ColorSamplesNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvMultisampleFilterHint)
	static const NvMultisampleFilterHint MultisampleFilterHintNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvOcclusionQuery)
	static const NvOcclusionQuery PixelCounterBitsNv;
	static const NvOcclusionQuery CurrentOcclusionQueryIdNv;
	static const NvOcclusionQuery PixelCountNv;
	static const NvOcclusionQuery PixelCountAvailableNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvPackedDepthStencil)
	static const NvPackedDepthStencil DepthStencilNv;
	static const NvPackedDepthStencil UnsignedInt248Nv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvParameterBufferObject)
	static const NvParameterBufferObject MaxProgramParameterBufferBindingsNv;
	static const NvParameterBufferObject MaxProgramParameterBufferSizeNv;
	static const NvParameterBufferObject VertexProgramParameterBufferNv;
	static const NvParameterBufferObject GeometryProgramParameterBufferNv;
	static const NvParameterBufferObject FragmentProgramParameterBufferNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvParameterBufferObject2)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvPathRendering)
	static const NvPathRendering ClosePathNv;
	static const NvPathRendering FontXMinBoundsBitNv;
	static const NvPathRendering FontYMinBoundsBitNv;
	static const NvPathRendering FontXMaxBoundsBitNv;
	static const NvPathRendering FontYMaxBoundsBitNv;
	static const NvPathRendering FontUnitsPerEmBitNv;
	static const NvPathRendering FontAscenderBitNv;
	static const NvPathRendering FontDescenderBitNv;
	static const NvPathRendering FontHeightBitNv;
	static const NvPathRendering BoldBitNv;
	static const NvPathRendering GlyphWidthBitNv;
	static const NvPathRendering FontMaxAdvanceWidthBitNv;
	static const NvPathRendering GlyphHeightBitNv;
	static const NvPathRendering ItalicBitNv;
	static const NvPathRendering MoveToNv;
	static const NvPathRendering FontMaxAdvanceHeightBitNv;
	static const NvPathRendering RelativeMoveToNv;
	static const NvPathRendering GlyphHorizontalBearingXBitNv;
	static const NvPathRendering LineToNv;
	static const NvPathRendering FontUnderlinePositionBitNv;
	static const NvPathRendering RelativeLineToNv;
	static const NvPathRendering HorizontalLineToNv;
	static const NvPathRendering RelativeHorizontalLineToNv;
	static const NvPathRendering GlyphHorizontalBearingYBitNv;
	static const NvPathRendering VerticalLineToNv;
	static const NvPathRendering FontUnderlineThicknessBitNv;
	static const NvPathRendering RelativeVerticalLineToNv;
	static const NvPathRendering QuadraticCurveToNv;
	static const NvPathRendering RelativeQuadraticCurveToNv;
	static const NvPathRendering PathModelviewStackDepthNv;
	static const NvPathRendering PathProjectionStackDepthNv;
	static const NvPathRendering PathModelviewMatrixNv;
	static const NvPathRendering PathProjectionMatrixNv;
	static const NvPathRendering CubicCurveToNv;
	static const NvPathRendering RelativeCubicCurveToNv;
	static const NvPathRendering PathMaxModelviewStackDepthNv;
	static const NvPathRendering PathMaxProjectionStackDepthNv;
	static const NvPathRendering SmoothQuadraticCurveToNv;
	static const NvPathRendering RelativeSmoothQuadraticCurveToNv;
	static const NvPathRendering GlyphHorizontalBearingAdvanceBitNv;
	static const NvPathRendering SmoothCubicCurveToNv;
	static const NvPathRendering GlyphHasKerningBitNv;
	static const NvPathRendering FontHasKerningBitNv;
	static const NvPathRendering RelativeSmoothCubicCurveToNv;
	static const NvPathRendering SmallCcwArcToNv;
	static const NvPathRendering RelativeSmallCcwArcToNv;
	static const NvPathRendering SmallCwArcToNv;
	static const NvPathRendering Gl2BytesNv;
	static const NvPathRendering Gl3BytesNv;
	static const NvPathRendering Gl4BytesNv;
	static const NvPathRendering RelativeSmallCwArcToNv;
	static const NvPathRendering LargeCcwArcToNv;
	static const NvPathRendering RelativeLargeCcwArcToNv;
	static const NvPathRendering PathModelviewNv;
	static const NvPathRendering PathProjectionNv;
	static const NvPathRendering LargeCwArcToNv;
	static const NvPathRendering RelativeLargeCwArcToNv;
	static const NvPathRendering ConicCurveToNv;
	static const NvPathRendering RelativeConicCurveToNv;
	static const NvPathRendering GlyphVerticalBearingXBitNv;
	static const NvPathRendering FontNumGlyphIndicesBitNv;
	static const NvPathRendering EyeLinearNv;
	static const NvPathRendering ObjectLinearNv;
	static const NvPathRendering GlyphVerticalBearingYBitNv;
	static const NvPathRendering GlyphVerticalBearingAdvanceBitNv;
	static const NvPathRendering PathTransposeModelviewMatrixNv;
	static const NvPathRendering PathTransposeProjectionMatrixNv;
	static const NvPathRendering PrimaryColorNv;
	static const NvPathRendering SecondaryColorNv;
	static const NvPathRendering ConstantNv;
	static const NvPathRendering PrimaryColor;
	static const NvPathRendering PathFormatSvgNv;
	static const NvPathRendering PathFormatPsNv;
	static const NvPathRendering StandardFontNameNv;
	static const NvPathRendering SystemFontNameNv;
	static const NvPathRendering FileNameNv;
	static const NvPathRendering PathStrokeWidthNv;
	static const NvPathRendering PathEndCapsNv;
	static const NvPathRendering PathInitialEndCapNv;
	static const NvPathRendering PathTerminalEndCapNv;
	static const NvPathRendering PathJoinStyleNv;
	static const NvPathRendering PathMiterLimitNv;
	static const NvPathRendering PathDashCapsNv;
	static const NvPathRendering PathInitialDashCapNv;
	static const NvPathRendering PathTerminalDashCapNv;
	static const NvPathRendering PathDashOffsetNv;
	static const NvPathRendering PathClientLengthNv;
	static const NvPathRendering PathFillModeNv;
	static const NvPathRendering PathFillMaskNv;
	static const NvPathRendering PathFillCoverModeNv;
	static const NvPathRendering PathStrokeCoverModeNv;
	static const NvPathRendering PathStrokeMaskNv;
	static const NvPathRendering CountUpNv;
	static const NvPathRendering CountDownNv;
	static const NvPathRendering PathObjectBoundingBoxNv;
	static const NvPathRendering ConvexHullNv;
	static const NvPathRendering BoundingBoxNv;
	static const NvPathRendering TranslateXNv;
	static const NvPathRendering TranslateYNv;
	static const NvPathRendering Translate2DNv;
	static const NvPathRendering Translate3DNv;
	static const NvPathRendering Affine2DNv;
	static const NvPathRendering Affine3DNv;
	static const NvPathRendering TransposeAffine2DNv;
	static const NvPathRendering TransposeAffine3DNv;
	static const NvPathRendering Utf8Nv;
	static const NvPathRendering Utf16Nv;
	static const NvPathRendering BoundingBoxOfBoundingBoxesNv;
	static const NvPathRendering PathCommandCountNv;
	static const NvPathRendering PathCoordCountNv;
	static const NvPathRendering PathDashArrayCountNv;
	static const NvPathRendering PathComputedLengthNv;
	static const NvPathRendering PathFillBoundingBoxNv;
	static const NvPathRendering PathStrokeBoundingBoxNv;
	static const NvPathRendering SquareNv;
	static const NvPathRendering RoundNv;
	static const NvPathRendering TriangularNv;
	static const NvPathRendering BevelNv;
	static const NvPathRendering MiterRevertNv;
	static const NvPathRendering MiterTruncateNv;
	static const NvPathRendering SkipMissingGlyphNv;
	static const NvPathRendering UseMissingGlyphNv;
	static const NvPathRendering PathErrorPositionNv;
	static const NvPathRendering PathFogGenModeNv;
	static const NvPathRendering AccumAdjacentPairsNv;
	static const NvPathRendering AdjacentPairsNv;
	static const NvPathRendering FirstToRestNv;
	static const NvPathRendering PathGenModeNv;
	static const NvPathRendering PathGenCoeffNv;
	static const NvPathRendering PathGenColorFormatNv;
	static const NvPathRendering PathGenComponentsNv;
	static const NvPathRendering PathDashOffsetResetNv;
	static const NvPathRendering MoveToResetsNv;
	static const NvPathRendering MoveToContinuesNv;
	static const NvPathRendering PathStencilFuncNv;
	static const NvPathRendering PathStencilRefNv;
	static const NvPathRendering PathStencilValueMaskNv;
	static const NvPathRendering PathStencilDepthOffsetFactorNv;
	static const NvPathRendering PathStencilDepthOffsetUnitsNv;
	static const NvPathRendering PathCoverDepthFuncNv;
	static const NvPathRendering FontGlyphsAvailableNv;
	static const NvPathRendering FontTargetUnavailableNv;
	static const NvPathRendering FontUnavailableNv;
	static const NvPathRendering FontUnintelligibleNv;
	static const NvPathRendering StandardFontFormatNv;
	static const NvPathRendering FragmentInputNv;
	static const NvPathRendering RoundedRectNv;
	static const NvPathRendering RelativeRoundedRectNv;
	static const NvPathRendering RoundedRect2Nv;
	static const NvPathRendering RelativeRoundedRect2Nv;
	static const NvPathRendering RoundedRect4Nv;
	static const NvPathRendering RelativeRoundedRect4Nv;
	static const NvPathRendering RoundedRect8Nv;
	static const NvPathRendering RelativeRoundedRect8Nv;
	static const NvPathRendering RestartPathNv;
	static const NvPathRendering DupFirstCubicCurveToNv;
	static const NvPathRendering DupLastCubicCurveToNv;
	static const NvPathRendering RectNv;
	static const NvPathRendering RelativeRectNv;
	static const NvPathRendering CircularCcwArcToNv;
	static const NvPathRendering CircularCwArcToNv;
	static const NvPathRendering CircularTangentArcToNv;
	static const NvPathRendering ArcToNv;
	static const NvPathRendering RelativeArcToNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvPixelDataRange)
	static const NvPixelDataRange WritePixelDataRangeNv;
	static const NvPixelDataRange ReadPixelDataRangeNv;
	static const NvPixelDataRange WritePixelDataRangeLengthNv;
	static const NvPixelDataRange ReadPixelDataRangeLengthNv;
	static const NvPixelDataRange WritePixelDataRangePointerNv;
	static const NvPixelDataRange ReadPixelDataRangePointerNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvPointSprite)
	static const NvPointSprite PointSpriteNv;
	static const NvPointSprite CoordReplaceNv;
	static const NvPointSprite PointSpriteRModeNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvPresentVideo)
	static const NvPresentVideo FrameNv;
	static const NvPresentVideo FieldsNv;
	static const NvPresentVideo CurrentTimeNv;
	static const NvPresentVideo NumFillStreamsNv;
	static const NvPresentVideo PresentTimeNv;
	static const NvPresentVideo PresentDurationNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvPrimitiveRestart)
	static const NvPrimitiveRestart PrimitiveRestartNv;
	static const NvPrimitiveRestart PrimitiveRestartIndexNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvRegisterCombiners)
	static const NvRegisterCombiners None;
	static const NvRegisterCombiners Zero;
	static const NvRegisterCombiners Fog;
	static const NvRegisterCombiners Texture0Arb;
	static const NvRegisterCombiners Texture1Arb;
	static const NvRegisterCombiners RegisterCombinersNv;
	static const NvRegisterCombiners VariableANv;
	static const NvRegisterCombiners VariableBNv;
	static const NvRegisterCombiners VariableCNv;
	static const NvRegisterCombiners VariableDNv;
	static const NvRegisterCombiners VariableENv;
	static const NvRegisterCombiners VariableFNv;
	static const NvRegisterCombiners VariableGNv;
	static const NvRegisterCombiners ConstantColor0Nv;
	static const NvRegisterCombiners ConstantColor1Nv;
	static const NvRegisterCombiners PrimaryColorNv;
	static const NvRegisterCombiners SecondaryColorNv;
	static const NvRegisterCombiners Spare0Nv;
	static const NvRegisterCombiners Spare1Nv;
	static const NvRegisterCombiners DiscardNv;
	static const NvRegisterCombiners ETimesFNv;
	static const NvRegisterCombiners Spare0PlusSecondaryColorNv;
	static const NvRegisterCombiners UnsignedIdentityNv;
	static const NvRegisterCombiners UnsignedInvertNv;
	static const NvRegisterCombiners ExpandNormalNv;
	static const NvRegisterCombiners ExpandNegateNv;
	static const NvRegisterCombiners HalfBiasNormalNv;
	static const NvRegisterCombiners HalfBiasNegateNv;
	static const NvRegisterCombiners SignedIdentityNv;
	static const NvRegisterCombiners SignedNegateNv;
	static const NvRegisterCombiners ScaleByTwoNv;
	static const NvRegisterCombiners ScaleByFourNv;
	static const NvRegisterCombiners ScaleByOneHalfNv;
	static const NvRegisterCombiners BiasByNegativeOneHalfNv;
	static const NvRegisterCombiners CombinerInputNv;
	static const NvRegisterCombiners CombinerMappingNv;
	static const NvRegisterCombiners CombinerComponentUsageNv;
	static const NvRegisterCombiners CombinerAbDotProductNv;
	static const NvRegisterCombiners CombinerCdDotProductNv;
	static const NvRegisterCombiners CombinerMuxSumNv;
	static const NvRegisterCombiners CombinerScaleNv;
	static const NvRegisterCombiners CombinerBiasNv;
	static const NvRegisterCombiners CombinerAbOutputNv;
	static const NvRegisterCombiners CombinerCdOutputNv;
	static const NvRegisterCombiners CombinerSumOutputNv;
	static const NvRegisterCombiners MaxGeneralCombinersNv;
	static const NvRegisterCombiners NumGeneralCombinersNv;
	static const NvRegisterCombiners ColorSumClampNv;
	static const NvRegisterCombiners Combiner0Nv;
	static const NvRegisterCombiners Combiner1Nv;
	static const NvRegisterCombiners Combiner2Nv;
	static const NvRegisterCombiners Combiner3Nv;
	static const NvRegisterCombiners Combiner4Nv;
	static const NvRegisterCombiners Combiner5Nv;
	static const NvRegisterCombiners Combiner6Nv;
	static const NvRegisterCombiners Combiner7Nv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvRegisterCombiners2)
	static const NvRegisterCombiners2 PerStageConstantsNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvShaderAtomicCounters)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvShaderAtomicFloat)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvShaderAtomicInt64)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvShaderBufferLoad)
	static const NvShaderBufferLoad BufferGpuAddressNv;
	static const NvShaderBufferLoad GpuAddressNv;
	static const NvShaderBufferLoad MaxShaderBufferAddressNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvShaderBufferStore)
	static const NvShaderBufferStore ShaderGlobalAccessBarrierBitNv;
	static const NvShaderBufferStore WriteOnly;
	static const NvShaderBufferStore ReadWrite;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvShaderStorageBufferObject)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvShaderThreadGroup)
	static const NvShaderThreadGroup WarpSizeNv;
	static const NvShaderThreadGroup WarpsPerSmNv;
	static const NvShaderThreadGroup SmCountNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvShaderThreadShuffle)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTessellationProgram5)
	static const NvTessellationProgram5 MaxProgramPatchAttribsNv;
	static const NvTessellationProgram5 TessControlProgramNv;
	static const NvTessellationProgram5 TessEvaluationProgramNv;
	static const NvTessellationProgram5 TessControlProgramParameterBufferNv;
	static const NvTessellationProgram5 TessEvaluationProgramParameterBufferNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTexgenEmboss)
	static const NvTexgenEmboss EmbossLightNv;
	static const NvTexgenEmboss EmbossConstantNv;
	static const NvTexgenEmboss EmbossMapNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTexgenReflection)
	static const NvTexgenReflection NormalMapNv;
	static const NvTexgenReflection ReflectionMapNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTextureBarrier)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTextureCompressionVtc)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTextureEnvCombine4)
	static const NvTextureEnvCombine4 Combine4Nv;
	static const NvTextureEnvCombine4 Source3RgbNv;
	static const NvTextureEnvCombine4 Source3AlphaNv;
	static const NvTextureEnvCombine4 Operand3RgbNv;
	static const NvTextureEnvCombine4 Operand3AlphaNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTextureExpandNormal)
	static const NvTextureExpandNormal TextureUnsignedRemapModeNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTextureMultisample)
	static const NvTextureMultisample TextureCoverageSamplesNv;
	static const NvTextureMultisample TextureColorSamplesNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTextureRectangle)
	static const NvTextureRectangle TextureRectangleNv;
	static const NvTextureRectangle TextureBindingRectangleNv;
	static const NvTextureRectangle ProxyTextureRectangleNv;
	static const NvTextureRectangle MaxRectangleTextureSizeNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTextureShader)
	static const NvTextureShader OffsetTextureRectangleNv;
	static const NvTextureShader OffsetTextureRectangleScaleNv;
	static const NvTextureShader DotProductTextureRectangleNv;
	static const NvTextureShader RgbaUnsignedDotProductMappingNv;
	static const NvTextureShader UnsignedIntS8S888Nv;
	static const NvTextureShader UnsignedInt88S8S8RevNv;
	static const NvTextureShader DsdtMagIntensityNv;
	static const NvTextureShader ShaderConsistentNv;
	static const NvTextureShader TextureShaderNv;
	static const NvTextureShader ShaderOperationNv;
	static const NvTextureShader CullModesNv;
	static const NvTextureShader OffsetTexture2DMatrixNv;
	static const NvTextureShader OffsetTextureMatrixNv;
	static const NvTextureShader OffsetTexture2DScaleNv;
	static const NvTextureShader OffsetTextureScaleNv;
	static const NvTextureShader OffsetTexture2DBiasNv;
	static const NvTextureShader OffsetTextureBiasNv;
	static const NvTextureShader PreviousTextureInputNv;
	static const NvTextureShader ConstEyeNv;
	static const NvTextureShader PassThroughNv;
	static const NvTextureShader CullFragmentNv;
	static const NvTextureShader OffsetTexture2DNv;
	static const NvTextureShader DependentArTexture2DNv;
	static const NvTextureShader DependentGbTexture2DNv;
	static const NvTextureShader DotProductNv;
	static const NvTextureShader DotProductDepthReplaceNv;
	static const NvTextureShader DotProductTexture2DNv;
	static const NvTextureShader DotProductTextureCubeMapNv;
	static const NvTextureShader DotProductDiffuseCubeMapNv;
	static const NvTextureShader DotProductReflectCubeMapNv;
	static const NvTextureShader DotProductConstEyeReflectCubeMapNv;
	static const NvTextureShader HiloNv;
	static const NvTextureShader DsdtNv;
	static const NvTextureShader DsdtMagNv;
	static const NvTextureShader DsdtMagVibNv;
	static const NvTextureShader Hilo16Nv;
	static const NvTextureShader SignedHiloNv;
	static const NvTextureShader SignedHilo16Nv;
	static const NvTextureShader SignedRgbaNv;
	static const NvTextureShader SignedRgba8Nv;
	static const NvTextureShader SignedRgbNv;
	static const NvTextureShader SignedRgb8Nv;
	static const NvTextureShader SignedLuminanceNv;
	static const NvTextureShader SignedLuminance8Nv;
	static const NvTextureShader SignedLuminanceAlphaNv;
	static const NvTextureShader SignedLuminance8Alpha8Nv;
	static const NvTextureShader SignedAlphaNv;
	static const NvTextureShader SignedAlpha8Nv;
	static const NvTextureShader SignedIntensityNv;
	static const NvTextureShader SignedIntensity8Nv;
	static const NvTextureShader Dsdt8Nv;
	static const NvTextureShader Dsdt8Mag8Nv;
	static const NvTextureShader Dsdt8Mag8Intensity8Nv;
	static const NvTextureShader SignedRgbUnsignedAlphaNv;
	static const NvTextureShader SignedRgb8UnsignedAlpha8Nv;
	static const NvTextureShader HiScaleNv;
	static const NvTextureShader LoScaleNv;
	static const NvTextureShader DsScaleNv;
	static const NvTextureShader DtScaleNv;
	static const NvTextureShader MagnitudeScaleNv;
	static const NvTextureShader VibranceScaleNv;
	static const NvTextureShader HiBiasNv;
	static const NvTextureShader LoBiasNv;
	static const NvTextureShader DsBiasNv;
	static const NvTextureShader DtBiasNv;
	static const NvTextureShader MagnitudeBiasNv;
	static const NvTextureShader VibranceBiasNv;
	static const NvTextureShader TextureBorderValuesNv;
	static const NvTextureShader TextureHiSizeNv;
	static const NvTextureShader TextureLoSizeNv;
	static const NvTextureShader TextureDsSizeNv;
	static const NvTextureShader TextureDtSizeNv;
	static const NvTextureShader TextureMagSizeNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTextureShader2)
	static const NvTextureShader2 DotProductTexture3DNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTextureShader3)
	static const NvTextureShader3 OffsetProjectiveTexture2DNv;
	static const NvTextureShader3 OffsetProjectiveTexture2DScaleNv;
	static const NvTextureShader3 OffsetProjectiveTextureRectangleNv;
	static const NvTextureShader3 OffsetProjectiveTextureRectangleScaleNv;
	static const NvTextureShader3 OffsetHiloTexture2DNv;
	static const NvTextureShader3 OffsetHiloTextureRectangleNv;
	static const NvTextureShader3 OffsetHiloProjectiveTexture2DNv;
	static const NvTextureShader3 OffsetHiloProjectiveTextureRectangleNv;
	static const NvTextureShader3 DependentHiloTexture2DNv;
	static const NvTextureShader3 DependentRgbTexture3DNv;
	static const NvTextureShader3 DependentRgbTextureCubeMapNv;
	static const NvTextureShader3 DotProductPassThroughNv;
	static const NvTextureShader3 DotProductTexture1DNv;
	static const NvTextureShader3 DotProductAffineDepthReplaceNv;
	static const NvTextureShader3 Hilo8Nv;
	static const NvTextureShader3 SignedHilo8Nv;
	static const NvTextureShader3 ForceBlueToOneNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTransformFeedback)
	static const NvTransformFeedback BackPrimaryColorNv;
	static const NvTransformFeedback BackSecondaryColorNv;
	static const NvTransformFeedback TextureCoordNv;
	static const NvTransformFeedback ClipDistanceNv;
	static const NvTransformFeedback VertexIdNv;
	static const NvTransformFeedback PrimitiveIdNv;
	static const NvTransformFeedback GenericAttribNv;
	static const NvTransformFeedback TransformFeedbackAttribsNv;
	static const NvTransformFeedback TransformFeedbackBufferModeNv;
	static const NvTransformFeedback MaxTransformFeedbackSeparateComponentsNv;
	static const NvTransformFeedback ActiveVaryingsNv;
	static const NvTransformFeedback ActiveVaryingMaxLengthNv;
	static const NvTransformFeedback TransformFeedbackVaryingsNv;
	static const NvTransformFeedback TransformFeedbackBufferStartNv;
	static const NvTransformFeedback TransformFeedbackBufferSizeNv;
	static const NvTransformFeedback TransformFeedbackRecordNv;
	static const NvTransformFeedback PrimitivesGeneratedNv;
	static const NvTransformFeedback TransformFeedbackPrimitivesWrittenNv;
	static const NvTransformFeedback RasterizerDiscardNv;
	static const NvTransformFeedback MaxTransformFeedbackInterleavedComponentsNv;
	static const NvTransformFeedback MaxTransformFeedbackSeparateAttribsNv;
	static const NvTransformFeedback InterleavedAttribsNv;
	static const NvTransformFeedback SeparateAttribsNv;
	static const NvTransformFeedback TransformFeedbackBufferNv;
	static const NvTransformFeedback TransformFeedbackBufferBindingNv;
	static const NvTransformFeedback LayerNv;
	static const NvTransformFeedback NextBufferNv;
	static const NvTransformFeedback SkipComponents4Nv;
	static const NvTransformFeedback SkipComponents3Nv;
	static const NvTransformFeedback SkipComponents2Nv;
	static const NvTransformFeedback SkipComponents1Nv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvTransformFeedback2)
	static const NvTransformFeedback2 TransformFeedbackNv;
	static const NvTransformFeedback2 TransformFeedbackBufferPausedNv;
	static const NvTransformFeedback2 TransformFeedbackBufferActiveNv;
	static const NvTransformFeedback2 TransformFeedbackBindingNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvVdpauInterop)
	static const NvVdpauInterop SurfaceStateNv;
	static const NvVdpauInterop SurfaceRegisteredNv;
	static const NvVdpauInterop SurfaceMappedNv;
	static const NvVdpauInterop WriteDiscardNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvVertexArrayRange)
	static const NvVertexArrayRange VertexArrayRangeNv;
	static const NvVertexArrayRange VertexArrayRangeLengthNv;
	static const NvVertexArrayRange VertexArrayRangeValidNv;
	static const NvVertexArrayRange MaxVertexArrayRangeElementNv;
	static const NvVertexArrayRange VertexArrayRangePointerNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvVertexArrayRange2)
	static const NvVertexArrayRange2 VertexArrayRangeWithoutFlushNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvVertexAttribInteger64bit)
	static const NvVertexAttribInteger64bit Int64Nv;
	static const NvVertexAttribInteger64bit UnsignedInt64Nv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvVertexBufferUnifiedMemory)
	static const NvVertexBufferUnifiedMemory VertexAttribArrayUnifiedNv;
	static const NvVertexBufferUnifiedMemory ElementArrayUnifiedNv;
	static const NvVertexBufferUnifiedMemory VertexAttribArrayAddressNv;
	static const NvVertexBufferUnifiedMemory VertexArrayAddressNv;
	static const NvVertexBufferUnifiedMemory NormalArrayAddressNv;
	static const NvVertexBufferUnifiedMemory ColorArrayAddressNv;
	static const NvVertexBufferUnifiedMemory IndexArrayAddressNv;
	static const NvVertexBufferUnifiedMemory TextureCoordArrayAddressNv;
	static const NvVertexBufferUnifiedMemory EdgeFlagArrayAddressNv;
	static const NvVertexBufferUnifiedMemory SecondaryColorArrayAddressNv;
	static const NvVertexBufferUnifiedMemory FogCoordArrayAddressNv;
	static const NvVertexBufferUnifiedMemory ElementArrayAddressNv;
	static const NvVertexBufferUnifiedMemory VertexAttribArrayLengthNv;
	static const NvVertexBufferUnifiedMemory VertexArrayLengthNv;
	static const NvVertexBufferUnifiedMemory NormalArrayLengthNv;
	static const NvVertexBufferUnifiedMemory ColorArrayLengthNv;
	static const NvVertexBufferUnifiedMemory IndexArrayLengthNv;
	static const NvVertexBufferUnifiedMemory TextureCoordArrayLengthNv;
	static const NvVertexBufferUnifiedMemory EdgeFlagArrayLengthNv;
	static const NvVertexBufferUnifiedMemory SecondaryColorArrayLengthNv;
	static const NvVertexBufferUnifiedMemory FogCoordArrayLengthNv;
	static const NvVertexBufferUnifiedMemory ElementArrayLengthNv;
	static const NvVertexBufferUnifiedMemory DrawIndirectUnifiedNv;
	static const NvVertexBufferUnifiedMemory DrawIndirectAddressNv;
	static const NvVertexBufferUnifiedMemory DrawIndirectLengthNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvVertexProgram)
	static const NvVertexProgram VertexProgramNv;
	static const NvVertexProgram VertexStateProgramNv;
	static const NvVertexProgram AttribArraySizeNv;
	static const NvVertexProgram AttribArrayStrideNv;
	static const NvVertexProgram AttribArrayTypeNv;
	static const NvVertexProgram CurrentAttribNv;
	static const NvVertexProgram ProgramLengthNv;
	static const NvVertexProgram ProgramStringNv;
	static const NvVertexProgram ModelviewProjectionNv;
	static const NvVertexProgram IdentityNv;
	static const NvVertexProgram InverseNv;
	static const NvVertexProgram TransposeNv;
	static const NvVertexProgram InverseTransposeNv;
	static const NvVertexProgram MaxTrackMatrixStackDepthNv;
	static const NvVertexProgram MaxTrackMatricesNv;
	static const NvVertexProgram Matrix0Nv;
	static const NvVertexProgram Matrix1Nv;
	static const NvVertexProgram Matrix2Nv;
	static const NvVertexProgram Matrix3Nv;
	static const NvVertexProgram Matrix4Nv;
	static const NvVertexProgram Matrix5Nv;
	static const NvVertexProgram Matrix6Nv;
	static const NvVertexProgram Matrix7Nv;
	static const NvVertexProgram CurrentMatrixStackDepthNv;
	static const NvVertexProgram CurrentMatrixNv;
	static const NvVertexProgram VertexProgramPointSizeNv;
	static const NvVertexProgram VertexProgramTwoSideNv;
	static const NvVertexProgram ProgramParameterNv;
	static const NvVertexProgram AttribArrayPointerNv;
	static const NvVertexProgram ProgramTargetNv;
	static const NvVertexProgram ProgramResidentNv;
	static const NvVertexProgram TrackMatrixNv;
	static const NvVertexProgram TrackMatrixTransformNv;
	static const NvVertexProgram VertexProgramBindingNv;
	static const NvVertexProgram ProgramErrorPositionNv;
	static const NvVertexProgram VertexAttribArray0Nv;
	static const NvVertexProgram VertexAttribArray1Nv;
	static const NvVertexProgram VertexAttribArray2Nv;
	static const NvVertexProgram VertexAttribArray3Nv;
	static const NvVertexProgram VertexAttribArray4Nv;
	static const NvVertexProgram VertexAttribArray5Nv;
	static const NvVertexProgram VertexAttribArray6Nv;
	static const NvVertexProgram VertexAttribArray7Nv;
	static const NvVertexProgram VertexAttribArray8Nv;
	static const NvVertexProgram VertexAttribArray9Nv;
	static const NvVertexProgram VertexAttribArray10Nv;
	static const NvVertexProgram VertexAttribArray11Nv;
	static const NvVertexProgram VertexAttribArray12Nv;
	static const NvVertexProgram VertexAttribArray13Nv;
	static const NvVertexProgram VertexAttribArray14Nv;
	static const NvVertexProgram VertexAttribArray15Nv;
	static const NvVertexProgram Map1VertexAttrib04Nv;
	static const NvVertexProgram Map1VertexAttrib14Nv;
	static const NvVertexProgram Map1VertexAttrib24Nv;
	static const NvVertexProgram Map1VertexAttrib34Nv;
	static const NvVertexProgram Map1VertexAttrib44Nv;
	static const NvVertexProgram Map1VertexAttrib54Nv;
	static const NvVertexProgram Map1VertexAttrib64Nv;
	static const NvVertexProgram Map1VertexAttrib74Nv;
	static const NvVertexProgram Map1VertexAttrib84Nv;
	static const NvVertexProgram Map1VertexAttrib94Nv;
	static const NvVertexProgram Map1VertexAttrib104Nv;
	static const NvVertexProgram Map1VertexAttrib114Nv;
	static const NvVertexProgram Map1VertexAttrib124Nv;
	static const NvVertexProgram Map1VertexAttrib134Nv;
	static const NvVertexProgram Map1VertexAttrib144Nv;
	static const NvVertexProgram Map1VertexAttrib154Nv;
	static const NvVertexProgram Map2VertexAttrib04Nv;
	static const NvVertexProgram Map2VertexAttrib14Nv;
	static const NvVertexProgram Map2VertexAttrib24Nv;
	static const NvVertexProgram Map2VertexAttrib34Nv;
	static const NvVertexProgram Map2VertexAttrib44Nv;
	static const NvVertexProgram Map2VertexAttrib54Nv;
	static const NvVertexProgram Map2VertexAttrib64Nv;
	static const NvVertexProgram Map2VertexAttrib74Nv;
	static const NvVertexProgram Map2VertexAttrib84Nv;
	static const NvVertexProgram Map2VertexAttrib94Nv;
	static const NvVertexProgram Map2VertexAttrib104Nv;
	static const NvVertexProgram Map2VertexAttrib114Nv;
	static const NvVertexProgram Map2VertexAttrib124Nv;
	static const NvVertexProgram Map2VertexAttrib134Nv;
	static const NvVertexProgram Map2VertexAttrib144Nv;
	static const NvVertexProgram Map2VertexAttrib154Nv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvVertexProgram11)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvVertexProgram2)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvVertexProgram2Option)
	static const NvVertexProgram2Option MaxProgramExecInstructionsNv;
	static const NvVertexProgram2Option MaxProgramCallDepthNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvVertexProgram3)
	static const NvVertexProgram3 MaxVertexTextureImageUnitsArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvVertexProgram4)
	static const NvVertexProgram4 VertexAttribArrayIntegerNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvVideoCapture)
	static const NvVideoCapture VideoBufferNv;
	static const NvVideoCapture VideoBufferBindingNv;
	static const NvVideoCapture FieldUpperNv;
	static const NvVideoCapture FieldLowerNv;
	static const NvVideoCapture NumVideoCaptureStreamsNv;
	static const NvVideoCapture NextVideoCaptureBufferStatusNv;
	static const NvVideoCapture VideoCaptureTo422SupportedNv;
	static const NvVideoCapture LastVideoCaptureStatusNv;
	static const NvVideoCapture VideoBufferPitchNv;
	static const NvVideoCapture VideoColorConversionMatrixNv;
	static const NvVideoCapture VideoColorConversionMaxNv;
	static const NvVideoCapture VideoColorConversionMinNv;
	static const NvVideoCapture VideoColorConversionOffsetNv;
	static const NvVideoCapture VideoBufferInternalFormatNv;
	static const NvVideoCapture PartialSuccessNv;
	static const NvVideoCapture SuccessNv;
	static const NvVideoCapture FailureNv;
	static const NvVideoCapture Ycbycr8422Nv;
	static const NvVideoCapture Ycbaycr8A4224Nv;
	static const NvVideoCapture Z6y10z6cb10z6y10z6cr10422Nv;
	static const NvVideoCapture Z6y10z6cb10z6A10z6y10z6cr10z6A104224Nv;
	static const NvVideoCapture Z4y12z4cb12z4y12z4cr12422Nv;
	static const NvVideoCapture Z4y12z4cb12z4A12z4y12z4cr12z4A124224Nv;
	static const NvVideoCapture Z4y12z4cb12z4cr12444Nv;
	static const NvVideoCapture VideoCaptureFrameWidthNv;
	static const NvVideoCapture VideoCaptureFrameHeightNv;
	static const NvVideoCapture VideoCaptureFieldUpperHeightNv;
	static const NvVideoCapture VideoCaptureFieldLowerHeightNv;
	static const NvVideoCapture VideoCaptureSurfaceOriginNv;
OPENGL_ENUM_END

OPENGL_ENUM_START(NvxConditionalRender)
OPENGL_ENUM_END

OPENGL_ENUM_START(NvxGpuMemoryInfo)
	static const NvxGpuMemoryInfo GpuMemoryInfoDedicatedVidmemNvx;
	static const NvxGpuMemoryInfo GpuMemoryInfoTotalAvailableMemoryNvx;
	static const NvxGpuMemoryInfo GpuMemoryInfoCurrentAvailableVidmemNvx;
	static const NvxGpuMemoryInfo GpuMemoryInfoEvictionCountNvx;
	static const NvxGpuMemoryInfo GpuMemoryInfoEvictedMemoryNvx;
OPENGL_ENUM_END

OPENGL_ENUM_START(ObjectLabelIdentifier)
	static const ObjectLabelIdentifier Texture;
	static const ObjectLabelIdentifier VertexArray;
	static const ObjectLabelIdentifier Buffer;
	static const ObjectLabelIdentifier Shader;
	static const ObjectLabelIdentifier Program;
	static const ObjectLabelIdentifier Query;
	static const ObjectLabelIdentifier ProgramPipeline;
	static const ObjectLabelIdentifier Sampler;
	static const ObjectLabelIdentifier Framebuffer;
	static const ObjectLabelIdentifier Renderbuffer;
	static const ObjectLabelIdentifier TransformFeedback;
OPENGL_ENUM_END

OPENGL_ENUM_START(OcclusionQueryEventMaskAmd)
	static const OcclusionQueryEventMaskAmd QueryDepthPassEventBitAmd;
	static const OcclusionQueryEventMaskAmd QueryDepthFailEventBitAmd;
	static const OcclusionQueryEventMaskAmd QueryStencilFailEventBitAmd;
	static const OcclusionQueryEventMaskAmd QueryDepthBoundsFailEventBitAmd;
	static const OcclusionQueryEventMaskAmd QueryAllEventBitsAmd;
OPENGL_ENUM_END

OPENGL_ENUM_START(OesByteCoordinates)
	static const OesByteCoordinates Byte;
OPENGL_ENUM_END

OPENGL_ENUM_START(OesCompressedPalettedTexture)
	static const OesCompressedPalettedTexture Palette4Rgb8Oes;
	static const OesCompressedPalettedTexture Palette4Rgba8Oes;
	static const OesCompressedPalettedTexture Palette4R5G6B5Oes;
	static const OesCompressedPalettedTexture Palette4Rgba4Oes;
	static const OesCompressedPalettedTexture Palette4Rgb5A1Oes;
	static const OesCompressedPalettedTexture Palette8Rgb8Oes;
	static const OesCompressedPalettedTexture Palette8Rgba8Oes;
	static const OesCompressedPalettedTexture Palette8R5G6B5Oes;
	static const OesCompressedPalettedTexture Palette8Rgba4Oes;
	static const OesCompressedPalettedTexture Palette8Rgb5A1Oes;
OPENGL_ENUM_END

OPENGL_ENUM_START(OesFixedPoint)
	static const OesFixedPoint FixedOes;
OPENGL_ENUM_END

OPENGL_ENUM_START(OesQueryMatrix)
OPENGL_ENUM_END

OPENGL_ENUM_START(OesReadFormat)
	static const OesReadFormat ImplementationColorReadTypeOes;
	static const OesReadFormat ImplementationColorReadFormatOes;
OPENGL_ENUM_END

OPENGL_ENUM_START(OesSinglePrecision)
OPENGL_ENUM_END

OPENGL_ENUM_START(OmlInterlace)
	static const OmlInterlace InterlaceOml;
	static const OmlInterlace InterlaceReadOml;
OPENGL_ENUM_END

OPENGL_ENUM_START(OmlResample)
	static const OmlResample PackResampleOml;
	static const OmlResample UnpackResampleOml;
	static const OmlResample ResampleReplicateOml;
	static const OmlResample ResampleZeroFillOml;
	static const OmlResample ResampleAverageOml;
	static const OmlResample ResampleDecimateOml;
OPENGL_ENUM_END

OPENGL_ENUM_START(OmlSubsample)
	static const OmlSubsample FormatSubsample2424Oml;
	static const OmlSubsample FormatSubsample244244Oml;
OPENGL_ENUM_END

OPENGL_ENUM_START(PackedPointerType)
	static const PackedPointerType UnsignedInt2101010Rev;
	static const PackedPointerType Int2101010Rev;
OPENGL_ENUM_END

OPENGL_ENUM_START(PatchParameterFloat)
	static const PatchParameterFloat PatchDefaultInnerLevel;
	static const PatchParameterFloat PatchDefaultOuterLevel;
OPENGL_ENUM_END

OPENGL_ENUM_START(PatchParameterInt)
	static const PatchParameterInt PatchVertices;
OPENGL_ENUM_END

OPENGL_ENUM_START(PgiMiscHints)
	static const PgiMiscHints PreferDoublebufferHintPgi;
	static const PgiMiscHints ConserveMemoryHintPgi;
	static const PgiMiscHints ReclaimMemoryHintPgi;
	static const PgiMiscHints NativeGraphicsHandlePgi;
	static const PgiMiscHints NativeGraphicsBeginHintPgi;
	static const PgiMiscHints NativeGraphicsEndHintPgi;
	static const PgiMiscHints AlwaysFastHintPgi;
	static const PgiMiscHints AlwaysSoftHintPgi;
	static const PgiMiscHints AllowDrawObjHintPgi;
	static const PgiMiscHints AllowDrawWinHintPgi;
	static const PgiMiscHints AllowDrawFrgHintPgi;
	static const PgiMiscHints AllowDrawMemHintPgi;
	static const PgiMiscHints StrictDepthfuncHintPgi;
	static const PgiMiscHints StrictLightingHintPgi;
	static const PgiMiscHints StrictScissorHintPgi;
	static const PgiMiscHints FullStippleHintPgi;
	static const PgiMiscHints ClipNearHintPgi;
	static const PgiMiscHints ClipFarHintPgi;
	static const PgiMiscHints WideLineHintPgi;
	static const PgiMiscHints BackNormalsHintPgi;
OPENGL_ENUM_END

OPENGL_ENUM_START(PgiVertexHints)
	static const PgiVertexHints Vertex23BitPgi;
	static const PgiVertexHints Vertex4BitPgi;
	static const PgiVertexHints Color3BitPgi;
	static const PgiVertexHints Color4BitPgi;
	static const PgiVertexHints EdgeflagBitPgi;
	static const PgiVertexHints IndexBitPgi;
	static const PgiVertexHints MatAmbientBitPgi;
	static const PgiVertexHints MatAmbientAndDiffuseBitPgi;
	static const PgiVertexHints MatDiffuseBitPgi;
	static const PgiVertexHints MatEmissionBitPgi;
	static const PgiVertexHints MatColorIndexesBitPgi;
	static const PgiVertexHints MatShininessBitPgi;
	static const PgiVertexHints MatSpecularBitPgi;
	static const PgiVertexHints NormalBitPgi;
	static const PgiVertexHints Texcoord1BitPgi;
	static const PgiVertexHints VertexDataHintPgi;
	static const PgiVertexHints VertexConsistentHintPgi;
	static const PgiVertexHints MaterialSideHintPgi;
	static const PgiVertexHints MaxVertexHintPgi;
	static const PgiVertexHints Texcoord2BitPgi;
	static const PgiVertexHints Texcoord3BitPgi;
	static const PgiVertexHints Texcoord4BitPgi;
OPENGL_ENUM_END

OPENGL_ENUM_START(PixelCopyType)
	static const PixelCopyType Color;
	static const PixelCopyType ColorExt;
	static const PixelCopyType Depth;
	static const PixelCopyType DepthExt;
	static const PixelCopyType Stencil;
	static const PixelCopyType StencilExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(PixelFormat)
	static const PixelFormat UnsignedShort;
	static const PixelFormat UnsignedInt;
	static const PixelFormat ColorIndex;
	static const PixelFormat StencilIndex;
	static const PixelFormat DepthComponent;
	static const PixelFormat Red;
	static const PixelFormat RedExt;
	static const PixelFormat Green;
	static const PixelFormat Blue;
	static const PixelFormat Alpha;
	static const PixelFormat Rgb;
	static const PixelFormat Rgba;
	static const PixelFormat Luminance;
	static const PixelFormat LuminanceAlpha;
	static const PixelFormat AbgrExt;
	static const PixelFormat CmykExt;
	static const PixelFormat CmykaExt;
	static const PixelFormat Bgr;
	static const PixelFormat Bgra;
	static const PixelFormat Ycrcb422Sgix;
	static const PixelFormat Ycrcb444Sgix;
	static const PixelFormat Rg;
	static const PixelFormat RgInteger;
	static const PixelFormat R5G6B5IccSgix;
	static const PixelFormat R5G6B5A8IccSgix;
	static const PixelFormat Alpha16IccSgix;
	static const PixelFormat Luminance16IccSgix;
	static const PixelFormat Luminance16Alpha8IccSgix;
	static const PixelFormat DepthStencil;
	static const PixelFormat RedInteger;
	static const PixelFormat GreenInteger;
	static const PixelFormat BlueInteger;
	static const PixelFormat AlphaInteger;
	static const PixelFormat RgbInteger;
	static const PixelFormat RgbaInteger;
	static const PixelFormat BgrInteger;
	static const PixelFormat BgraInteger;
OPENGL_ENUM_END

OPENGL_ENUM_START(PixelInternalFormat)
	static const PixelInternalFormat DepthComponent;
	static const PixelInternalFormat Alpha;
	static const PixelInternalFormat Rgb;
	static const PixelInternalFormat Rgba;
	static const PixelInternalFormat Luminance;
	static const PixelInternalFormat LuminanceAlpha;
	static const PixelInternalFormat R3G3B2;
	static const PixelInternalFormat Alpha4;
	static const PixelInternalFormat Alpha8;
	static const PixelInternalFormat Alpha12;
	static const PixelInternalFormat Alpha16;
	static const PixelInternalFormat Luminance4;
	static const PixelInternalFormat Luminance8;
	static const PixelInternalFormat Luminance12;
	static const PixelInternalFormat Luminance16;
	static const PixelInternalFormat Luminance4Alpha4;
	static const PixelInternalFormat Luminance6Alpha2;
	static const PixelInternalFormat Luminance8Alpha8;
	static const PixelInternalFormat Luminance12Alpha4;
	static const PixelInternalFormat Luminance12Alpha12;
	static const PixelInternalFormat Luminance16Alpha16;
	static const PixelInternalFormat Intensity;
	static const PixelInternalFormat Intensity4;
	static const PixelInternalFormat Intensity8;
	static const PixelInternalFormat Intensity12;
	static const PixelInternalFormat Intensity16;
	static const PixelInternalFormat Rgb2Ext;
	static const PixelInternalFormat Rgb4;
	static const PixelInternalFormat Rgb5;
	static const PixelInternalFormat Rgb8;
	static const PixelInternalFormat Rgb10;
	static const PixelInternalFormat Rgb12;
	static const PixelInternalFormat Rgb16;
	static const PixelInternalFormat Rgba2;
	static const PixelInternalFormat Rgba4;
	static const PixelInternalFormat Rgb5A1;
	static const PixelInternalFormat Rgba8;
	static const PixelInternalFormat Rgb10A2;
	static const PixelInternalFormat Rgba12;
	static const PixelInternalFormat Rgba16;
	static const PixelInternalFormat DualAlpha4Sgis;
	static const PixelInternalFormat DualAlpha8Sgis;
	static const PixelInternalFormat DualAlpha12Sgis;
	static const PixelInternalFormat DualAlpha16Sgis;
	static const PixelInternalFormat DualLuminance4Sgis;
	static const PixelInternalFormat DualLuminance8Sgis;
	static const PixelInternalFormat DualLuminance12Sgis;
	static const PixelInternalFormat DualLuminance16Sgis;
	static const PixelInternalFormat DualIntensity4Sgis;
	static const PixelInternalFormat DualIntensity8Sgis;
	static const PixelInternalFormat DualIntensity12Sgis;
	static const PixelInternalFormat DualIntensity16Sgis;
	static const PixelInternalFormat DualLuminanceAlpha4Sgis;
	static const PixelInternalFormat DualLuminanceAlpha8Sgis;
	static const PixelInternalFormat QuadAlpha4Sgis;
	static const PixelInternalFormat QuadAlpha8Sgis;
	static const PixelInternalFormat QuadLuminance4Sgis;
	static const PixelInternalFormat QuadLuminance8Sgis;
	static const PixelInternalFormat QuadIntensity4Sgis;
	static const PixelInternalFormat QuadIntensity8Sgis;
	static const PixelInternalFormat DepthComponent16;
	static const PixelInternalFormat DepthComponent16Sgix;
	static const PixelInternalFormat DepthComponent24;
	static const PixelInternalFormat DepthComponent24Sgix;
	static const PixelInternalFormat DepthComponent32;
	static const PixelInternalFormat DepthComponent32Sgix;
	static const PixelInternalFormat CompressedRed;
	static const PixelInternalFormat CompressedRg;
	static const PixelInternalFormat R8;
	static const PixelInternalFormat R16;
	static const PixelInternalFormat Rg8;
	static const PixelInternalFormat Rg16;
	static const PixelInternalFormat R16f;
	static const PixelInternalFormat R32f;
	static const PixelInternalFormat Rg16f;
	static const PixelInternalFormat Rg32f;
	static const PixelInternalFormat R8i;
	static const PixelInternalFormat R8ui;
	static const PixelInternalFormat R16i;
	static const PixelInternalFormat R16ui;
	static const PixelInternalFormat R32i;
	static const PixelInternalFormat R32ui;
	static const PixelInternalFormat Rg8i;
	static const PixelInternalFormat Rg8ui;
	static const PixelInternalFormat Rg16i;
	static const PixelInternalFormat Rg16ui;
	static const PixelInternalFormat Rg32i;
	static const PixelInternalFormat Rg32ui;
	static const PixelInternalFormat CompressedRgbS3tcDxt1Ext;
	static const PixelInternalFormat CompressedRgbaS3tcDxt1Ext;
	static const PixelInternalFormat CompressedRgbaS3tcDxt3Ext;
	static const PixelInternalFormat CompressedRgbaS3tcDxt5Ext;
	static const PixelInternalFormat RgbIccSgix;
	static const PixelInternalFormat RgbaIccSgix;
	static const PixelInternalFormat AlphaIccSgix;
	static const PixelInternalFormat LuminanceIccSgix;
	static const PixelInternalFormat IntensityIccSgix;
	static const PixelInternalFormat LuminanceAlphaIccSgix;
	static const PixelInternalFormat R5G6B5IccSgix;
	static const PixelInternalFormat R5G6B5A8IccSgix;
	static const PixelInternalFormat Alpha16IccSgix;
	static const PixelInternalFormat Luminance16IccSgix;
	static const PixelInternalFormat Intensity16IccSgix;
	static const PixelInternalFormat Luminance16Alpha8IccSgix;
	static const PixelInternalFormat CompressedAlpha;
	static const PixelInternalFormat CompressedLuminance;
	static const PixelInternalFormat CompressedLuminanceAlpha;
	static const PixelInternalFormat CompressedIntensity;
	static const PixelInternalFormat CompressedRgb;
	static const PixelInternalFormat CompressedRgba;
	static const PixelInternalFormat DepthStencil;
	static const PixelInternalFormat Rgba32f;
	static const PixelInternalFormat Rgb32f;
	static const PixelInternalFormat Rgba16f;
	static const PixelInternalFormat Rgb16f;
	static const PixelInternalFormat Depth24Stencil8;
	static const PixelInternalFormat R11fG11fB10f;
	static const PixelInternalFormat Rgb9E5;
	static const PixelInternalFormat Srgb;
	static const PixelInternalFormat Srgb8;
	static const PixelInternalFormat SrgbAlpha;
	static const PixelInternalFormat Srgb8Alpha8;
	static const PixelInternalFormat SluminanceAlpha;
	static const PixelInternalFormat Sluminance8Alpha8;
	static const PixelInternalFormat Sluminance;
	static const PixelInternalFormat Sluminance8;
	static const PixelInternalFormat CompressedSrgb;
	static const PixelInternalFormat CompressedSrgbAlpha;
	static const PixelInternalFormat CompressedSluminance;
	static const PixelInternalFormat CompressedSluminanceAlpha;
	static const PixelInternalFormat CompressedSrgbS3tcDxt1Ext;
	static const PixelInternalFormat CompressedSrgbAlphaS3tcDxt1Ext;
	static const PixelInternalFormat CompressedSrgbAlphaS3tcDxt3Ext;
	static const PixelInternalFormat CompressedSrgbAlphaS3tcDxt5Ext;
	static const PixelInternalFormat DepthComponent32f;
	static const PixelInternalFormat Depth32fStencil8;
	static const PixelInternalFormat Rgba32ui;
	static const PixelInternalFormat Rgb32ui;
	static const PixelInternalFormat Rgba16ui;
	static const PixelInternalFormat Rgb16ui;
	static const PixelInternalFormat Rgba8ui;
	static const PixelInternalFormat Rgb8ui;
	static const PixelInternalFormat Rgba32i;
	static const PixelInternalFormat Rgb32i;
	static const PixelInternalFormat Rgba16i;
	static const PixelInternalFormat Rgb16i;
	static const PixelInternalFormat Rgba8i;
	static const PixelInternalFormat Rgb8i;
	static const PixelInternalFormat Float32UnsignedInt248Rev;
	static const PixelInternalFormat CompressedRedRgtc1;
	static const PixelInternalFormat CompressedSignedRedRgtc1;
	static const PixelInternalFormat CompressedRgRgtc2;
	static const PixelInternalFormat CompressedSignedRgRgtc2;
	static const PixelInternalFormat CompressedRgbaBptcUnorm;
	static const PixelInternalFormat CompressedSrgbAlphaBptcUnorm;
	static const PixelInternalFormat CompressedRgbBptcSignedFloat;
	static const PixelInternalFormat CompressedRgbBptcUnsignedFloat;
	static const PixelInternalFormat R8Snorm;
	static const PixelInternalFormat Rg8Snorm;
	static const PixelInternalFormat Rgb8Snorm;
	static const PixelInternalFormat Rgba8Snorm;
	static const PixelInternalFormat R16Snorm;
	static const PixelInternalFormat Rg16Snorm;
	static const PixelInternalFormat Rgb16Snorm;
	static const PixelInternalFormat Rgba16Snorm;
	static const PixelInternalFormat Rgb10A2ui;
	static const PixelInternalFormat One;
	static const PixelInternalFormat Two;
	static const PixelInternalFormat Three;
	static const PixelInternalFormat Four;
OPENGL_ENUM_END

OPENGL_ENUM_START(PixelMap)
	static const PixelMap PixelMapIToI;
	static const PixelMap PixelMapSToS;
	static const PixelMap PixelMapIToR;
	static const PixelMap PixelMapIToG;
	static const PixelMap PixelMapIToB;
	static const PixelMap PixelMapIToA;
	static const PixelMap PixelMapRToR;
	static const PixelMap PixelMapGToG;
	static const PixelMap PixelMapBToB;
	static const PixelMap PixelMapAToA;
OPENGL_ENUM_END

OPENGL_ENUM_START(PixelStoreParameter)
	static const PixelStoreParameter UnpackSwapBytes;
	static const PixelStoreParameter UnpackLsbFirst;
	static const PixelStoreParameter UnpackRowLength;
	static const PixelStoreParameter UnpackRowLengthExt;
	static const PixelStoreParameter UnpackSkipRows;
	static const PixelStoreParameter UnpackSkipRowsExt;
	static const PixelStoreParameter UnpackSkipPixels;
	static const PixelStoreParameter UnpackSkipPixelsExt;
	static const PixelStoreParameter UnpackAlignment;
	static const PixelStoreParameter PackSwapBytes;
	static const PixelStoreParameter PackLsbFirst;
	static const PixelStoreParameter PackRowLength;
	static const PixelStoreParameter PackSkipRows;
	static const PixelStoreParameter PackSkipPixels;
	static const PixelStoreParameter PackAlignment;
	static const PixelStoreParameter PackSkipImages;
	static const PixelStoreParameter PackSkipImagesExt;
	static const PixelStoreParameter PackImageHeight;
	static const PixelStoreParameter PackImageHeightExt;
	static const PixelStoreParameter UnpackSkipImages;
	static const PixelStoreParameter UnpackSkipImagesExt;
	static const PixelStoreParameter UnpackImageHeight;
	static const PixelStoreParameter UnpackImageHeightExt;
	static const PixelStoreParameter PackSkipVolumesSgis;
	static const PixelStoreParameter PackImageDepthSgis;
	static const PixelStoreParameter UnpackSkipVolumesSgis;
	static const PixelStoreParameter UnpackImageDepthSgis;
	static const PixelStoreParameter PixelTileWidthSgix;
	static const PixelStoreParameter PixelTileHeightSgix;
	static const PixelStoreParameter PixelTileGridWidthSgix;
	static const PixelStoreParameter PixelTileGridHeightSgix;
	static const PixelStoreParameter PixelTileGridDepthSgix;
	static const PixelStoreParameter PixelTileCacheSizeSgix;
	static const PixelStoreParameter PackResampleSgix;
	static const PixelStoreParameter UnpackResampleSgix;
	static const PixelStoreParameter PackSubsampleRateSgix;
	static const PixelStoreParameter UnpackSubsampleRateSgix;
	static const PixelStoreParameter PackResampleOml;
	static const PixelStoreParameter UnpackResampleOml;
	static const PixelStoreParameter UnpackCompressedBlockWidth;
	static const PixelStoreParameter UnpackCompressedBlockHeight;
	static const PixelStoreParameter UnpackCompressedBlockDepth;
	static const PixelStoreParameter UnpackCompressedBlockSize;
	static const PixelStoreParameter PackCompressedBlockWidth;
	static const PixelStoreParameter PackCompressedBlockHeight;
	static const PixelStoreParameter PackCompressedBlockDepth;
	static const PixelStoreParameter PackCompressedBlockSize;
OPENGL_ENUM_END

OPENGL_ENUM_START(PixelStoreResampleMode)
	static const PixelStoreResampleMode ResampleReplicateSgix;
	static const PixelStoreResampleMode ResampleZeroFillSgix;
	static const PixelStoreResampleMode ResampleDecimateSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(PixelStoreSubsampleRate)
	static const PixelStoreSubsampleRate PixelSubsample4444Sgix;
	static const PixelStoreSubsampleRate PixelSubsample2424Sgix;
	static const PixelStoreSubsampleRate PixelSubsample4242Sgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(PixelTexGenMode)
	static const PixelTexGenMode None;
	static const PixelTexGenMode Rgb;
	static const PixelTexGenMode Rgba;
	static const PixelTexGenMode Luminance;
	static const PixelTexGenMode LuminanceAlpha;
	static const PixelTexGenMode PixelTexGenAlphaReplaceSgix;
	static const PixelTexGenMode PixelTexGenAlphaNoReplaceSgix;
	static const PixelTexGenMode PixelTexGenAlphaLsSgix;
	static const PixelTexGenMode PixelTexGenAlphaMsSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(PixelTexGenParameterNameSgis)
	static const PixelTexGenParameterNameSgis PixelFragmentRgbSourceSgis;
	static const PixelTexGenParameterNameSgis PixelFragmentAlphaSourceSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(PixelTransferParameter)
	static const PixelTransferParameter MapColor;
	static const PixelTransferParameter MapStencil;
	static const PixelTransferParameter IndexShift;
	static const PixelTransferParameter IndexOffset;
	static const PixelTransferParameter RedScale;
	static const PixelTransferParameter RedBias;
	static const PixelTransferParameter GreenScale;
	static const PixelTransferParameter GreenBias;
	static const PixelTransferParameter BlueScale;
	static const PixelTransferParameter BlueBias;
	static const PixelTransferParameter AlphaScale;
	static const PixelTransferParameter AlphaBias;
	static const PixelTransferParameter DepthScale;
	static const PixelTransferParameter DepthBias;
	static const PixelTransferParameter PostConvolutionRedScale;
	static const PixelTransferParameter PostConvolutionRedScaleExt;
	static const PixelTransferParameter PostConvolutionGreenScale;
	static const PixelTransferParameter PostConvolutionGreenScaleExt;
	static const PixelTransferParameter PostConvolutionBlueScale;
	static const PixelTransferParameter PostConvolutionBlueScaleExt;
	static const PixelTransferParameter PostConvolutionAlphaScale;
	static const PixelTransferParameter PostConvolutionAlphaScaleExt;
	static const PixelTransferParameter PostConvolutionRedBias;
	static const PixelTransferParameter PostConvolutionRedBiasExt;
	static const PixelTransferParameter PostConvolutionGreenBias;
	static const PixelTransferParameter PostConvolutionGreenBiasExt;
	static const PixelTransferParameter PostConvolutionBlueBias;
	static const PixelTransferParameter PostConvolutionBlueBiasExt;
	static const PixelTransferParameter PostConvolutionAlphaBias;
	static const PixelTransferParameter PostConvolutionAlphaBiasExt;
	static const PixelTransferParameter PostColorMatrixRedScale;
	static const PixelTransferParameter PostColorMatrixRedScaleSgi;
	static const PixelTransferParameter PostColorMatrixGreenScale;
	static const PixelTransferParameter PostColorMatrixGreenScaleSgi;
	static const PixelTransferParameter PostColorMatrixBlueScale;
	static const PixelTransferParameter PostColorMatrixBlueScaleSgi;
	static const PixelTransferParameter PostColorMatrixAlphaScale;
	static const PixelTransferParameter PostColorMatrixAlphaScaleSgi;
	static const PixelTransferParameter PostColorMatrixRedBias;
	static const PixelTransferParameter PostColorMatrixRedBiasSgi;
	static const PixelTransferParameter PostColorMatrixGreenBias;
	static const PixelTransferParameter PostColorMatrixGreenBiasSgi;
	static const PixelTransferParameter PostColorMatrixBlueBias;
	static const PixelTransferParameter PostColorMatrixBlueBiasSgi;
	static const PixelTransferParameter PostColorMatrixAlphaBias;
	static const PixelTransferParameter PostColorMatrixAlphaBiasSgi;
OPENGL_ENUM_END

OPENGL_ENUM_START(PixelType)
	static const PixelType Byte;
	static const PixelType UnsignedByte;
	static const PixelType Short;
	static const PixelType UnsignedShort;
	static const PixelType Int;
	static const PixelType UnsignedInt;
	static const PixelType Float;
	static const PixelType HalfFloat;
	static const PixelType Bitmap;
	static const PixelType UnsignedByte332;
	static const PixelType UnsignedByte332Ext;
	static const PixelType UnsignedShort4444;
	static const PixelType UnsignedShort4444Ext;
	static const PixelType UnsignedShort5551;
	static const PixelType UnsignedShort5551Ext;
	static const PixelType UnsignedInt8888;
	static const PixelType UnsignedInt8888Ext;
	static const PixelType UnsignedInt1010102;
	static const PixelType UnsignedInt1010102Ext;
	static const PixelType UnsignedByte233Reversed;
	static const PixelType UnsignedShort565;
	static const PixelType UnsignedShort565Reversed;
	static const PixelType UnsignedShort4444Reversed;
	static const PixelType UnsignedShort1555Reversed;
	static const PixelType UnsignedInt8888Reversed;
	static const PixelType UnsignedInt2101010Reversed;
	static const PixelType UnsignedInt248;
	static const PixelType UnsignedInt10F11F11FRev;
	static const PixelType UnsignedInt5999Rev;
	static const PixelType Float32UnsignedInt248Rev;
OPENGL_ENUM_END

OPENGL_ENUM_START(PointParameterName)
	static const PointParameterName PointSizeMin;
	static const PointParameterName PointSizeMax;
	static const PointParameterName PointFadeThresholdSize;
	static const PointParameterName PointDistanceAttenuation;
	static const PointParameterName PointSpriteCoordOrigin;
OPENGL_ENUM_END

OPENGL_ENUM_START(PointParameterNameSgis)
	static const PointParameterNameSgis PointSizeMin;
	static const PointParameterNameSgis PointSizeMinArb;
	static const PointParameterNameSgis PointSizeMinExt;
	static const PointParameterNameSgis PointSizeMinSgis;
	static const PointParameterNameSgis PointSizeMax;
	static const PointParameterNameSgis PointSizeMaxArb;
	static const PointParameterNameSgis PointSizeMaxExt;
	static const PointParameterNameSgis PointSizeMaxSgis;
	static const PointParameterNameSgis PointFadeThresholdSize;
	static const PointParameterNameSgis PointFadeThresholdSizeArb;
	static const PointParameterNameSgis PointFadeThresholdSizeExt;
	static const PointParameterNameSgis PointFadeThresholdSizeSgis;
	static const PointParameterNameSgis DistanceAttenuationExt;
	static const PointParameterNameSgis DistanceAttenuationSgis;
	static const PointParameterNameSgis PointDistanceAttenuation;
	static const PointParameterNameSgis PointDistanceAttenuationArb;
OPENGL_ENUM_END

OPENGL_ENUM_START(PointSpriteCoordOriginParameter)
	static const PointSpriteCoordOriginParameter LowerLeft;
	static const PointSpriteCoordOriginParameter UpperLeft;
OPENGL_ENUM_END

OPENGL_ENUM_START(PolygonMode)
	static const PolygonMode Point;
	static const PolygonMode Line;
	static const PolygonMode Fill;
OPENGL_ENUM_END

OPENGL_ENUM_START(PrimitiveType)
	static const PrimitiveType Points;
	static const PrimitiveType Lines;
	static const PrimitiveType LineLoop;
	static const PrimitiveType LineStrip;
	static const PrimitiveType Triangles;
	static const PrimitiveType TriangleStrip;
	static const PrimitiveType TriangleFan;
	static const PrimitiveType Quads;
	static const PrimitiveType QuadsExt;
	static const PrimitiveType QuadStrip;
	static const PrimitiveType Polygon;
	static const PrimitiveType LinesAdjacency;
	static const PrimitiveType LinesAdjacencyArb;
	static const PrimitiveType LinesAdjacencyExt;
	static const PrimitiveType LineStripAdjacency;
	static const PrimitiveType LineStripAdjacencyArb;
	static const PrimitiveType LineStripAdjacencyExt;
	static const PrimitiveType TrianglesAdjacency;
	static const PrimitiveType TrianglesAdjacencyArb;
	static const PrimitiveType TrianglesAdjacencyExt;
	static const PrimitiveType TriangleStripAdjacency;
	static const PrimitiveType TriangleStripAdjacencyArb;
	static const PrimitiveType TriangleStripAdjacencyExt;
	static const PrimitiveType Patches;
	static const PrimitiveType PatchesExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ProgramInterface)
	static const ProgramInterface TransformFeedbackBuffer;
	static const ProgramInterface AtomicCounterBuffer;
	static const ProgramInterface Uniform;
	static const ProgramInterface UniformBlock;
	static const ProgramInterface ProgramInput;
	static const ProgramInterface ProgramOutput;
	static const ProgramInterface BufferVariable;
	static const ProgramInterface ShaderStorageBlock;
	static const ProgramInterface VertexSubroutine;
	static const ProgramInterface TessControlSubroutine;
	static const ProgramInterface TessEvaluationSubroutine;
	static const ProgramInterface GeometrySubroutine;
	static const ProgramInterface FragmentSubroutine;
	static const ProgramInterface ComputeSubroutine;
	static const ProgramInterface VertexSubroutineUniform;
	static const ProgramInterface TessControlSubroutineUniform;
	static const ProgramInterface TessEvaluationSubroutineUniform;
	static const ProgramInterface GeometrySubroutineUniform;
	static const ProgramInterface FragmentSubroutineUniform;
	static const ProgramInterface ComputeSubroutineUniform;
	static const ProgramInterface TransformFeedbackVarying;
OPENGL_ENUM_END

OPENGL_ENUM_START(ProgramInterfaceParameter)
	static const ProgramInterfaceParameter ActiveResources;
	static const ProgramInterfaceParameter MaxNameLength;
	static const ProgramInterfaceParameter MaxNumActiveVariables;
	static const ProgramInterfaceParameter MaxNumCompatibleSubroutines;
OPENGL_ENUM_END

OPENGL_ENUM_START(ProgramParameter)
	static const ProgramParameter ProgramBinaryRetrievableHint;
	static const ProgramParameter ProgramSeparable;
	static const ProgramParameter GeometryShaderInvocations;
	static const ProgramParameter GeometryVerticesOut;
	static const ProgramParameter GeometryInputType;
	static const ProgramParameter GeometryOutputType;
	static const ProgramParameter ActiveUniformBlockMaxNameLength;
	static const ProgramParameter ActiveUniformBlocks;
	static const ProgramParameter DeleteStatus;
	static const ProgramParameter LinkStatus;
	static const ProgramParameter ValidateStatus;
	static const ProgramParameter InfoLogLength;
	static const ProgramParameter AttachedShaders;
	static const ProgramParameter ActiveUniforms;
	static const ProgramParameter ActiveUniformMaxLength;
	static const ProgramParameter ActiveAttributes;
	static const ProgramParameter ActiveAttributeMaxLength;
	static const ProgramParameter TransformFeedbackVaryingMaxLength;
	static const ProgramParameter TransformFeedbackBufferMode;
	static const ProgramParameter TransformFeedbackVaryings;
	static const ProgramParameter TessControlOutputVertices;
	static const ProgramParameter TessGenMode;
	static const ProgramParameter TessGenSpacing;
	static const ProgramParameter TessGenVertexOrder;
	static const ProgramParameter TessGenPointMode;
	static const ProgramParameter MaxComputeWorkGroupSize;
	static const ProgramParameter ActiveAtomicCounterBuffers;
OPENGL_ENUM_END

OPENGL_ENUM_START(ProgramParameterName)
	static const ProgramParameterName ProgramBinaryRetrievableHint;
	static const ProgramParameterName ProgramSeparable;
OPENGL_ENUM_END

OPENGL_ENUM_START(ProgramParameterPName)
	static const ProgramParameterPName ProgramBinaryRetrievableHint;
	static const ProgramParameterPName ProgramSeparable;
OPENGL_ENUM_END

OPENGL_ENUM_START(ProgramPipelineParameter)
	static const ProgramPipelineParameter ActiveProgram;
	static const ProgramPipelineParameter FragmentShader;
	static const ProgramPipelineParameter VertexShader;
	static const ProgramPipelineParameter ValidateStatus;
	static const ProgramPipelineParameter InfoLogLength;
	static const ProgramPipelineParameter GeometryShader;
	static const ProgramPipelineParameter TessEvaluationShader;
	static const ProgramPipelineParameter TessControlShader;
	static const ProgramPipelineParameter ComputeShader;
OPENGL_ENUM_END

OPENGL_ENUM_START(ProgramProperty)
	static const ProgramProperty NumCompatibleSubroutines;
	static const ProgramProperty CompatibleSubroutines;
	static const ProgramProperty IsPerPatch;
	static const ProgramProperty NameLength;
	static const ProgramProperty Type;
	static const ProgramProperty ArraySize;
	static const ProgramProperty Offset;
	static const ProgramProperty BlockIndex;
	static const ProgramProperty ArrayStride;
	static const ProgramProperty MatrixStride;
	static const ProgramProperty IsRowMajor;
	static const ProgramProperty AtomicCounterBufferIndex;
	static const ProgramProperty BufferBinding;
	static const ProgramProperty BufferDataSize;
	static const ProgramProperty NumActiveVariables;
	static const ProgramProperty ActiveVariables;
	static const ProgramProperty ReferencedByVertexShader;
	static const ProgramProperty ReferencedByTessControlShader;
	static const ProgramProperty ReferencedByTessEvaluationShader;
	static const ProgramProperty ReferencedByGeometryShader;
	static const ProgramProperty ReferencedByFragmentShader;
	static const ProgramProperty TopLevelArraySize;
	static const ProgramProperty TopLevelArrayStride;
	static const ProgramProperty Location;
	static const ProgramProperty LocationIndex;
	static const ProgramProperty LocationComponent;
	static const ProgramProperty TransformFeedbackBufferIndex;
	static const ProgramProperty TransformFeedbackBufferStride;
OPENGL_ENUM_END

OPENGL_ENUM_START(ProgramStageMask)
	static const ProgramStageMask VertexShaderBit;
	static const ProgramStageMask FragmentShaderBit;
	static const ProgramStageMask GeometryShaderBit;
	static const ProgramStageMask TessControlShaderBit;
	static const ProgramStageMask TessEvaluationShaderBit;
	static const ProgramStageMask ComputeShaderBit;
	static const ProgramStageMask AllShaderBits;
OPENGL_ENUM_END

OPENGL_ENUM_START(ProgramStageParameter)
	static const ProgramStageParameter ActiveSubroutines;
	static const ProgramStageParameter ActiveSubroutineUniforms;
	static const ProgramStageParameter ActiveSubroutineUniformLocations;
	static const ProgramStageParameter ActiveSubroutineMaxLength;
	static const ProgramStageParameter ActiveSubroutineUniformMaxLength;
OPENGL_ENUM_END

OPENGL_ENUM_START(ProvokingVertexMode)
	static const ProvokingVertexMode FirstVertexConvention;
	static const ProvokingVertexMode LastVertexConvention;
OPENGL_ENUM_END

OPENGL_ENUM_START(QueryCounterTarget)
	static const QueryCounterTarget Timestamp;
OPENGL_ENUM_END

OPENGL_ENUM_START(QueryTarget)
	static const QueryTarget TimeElapsed;
	static const QueryTarget SamplesPassed;
	static const QueryTarget AnySamplesPassed;
	static const QueryTarget PrimitivesGenerated;
	static const QueryTarget TransformFeedbackPrimitivesWritten;
	static const QueryTarget AnySamplesPassedConservative;
	static const QueryTarget Timestamp;
OPENGL_ENUM_END

OPENGL_ENUM_START(ReadBufferMode)
	static const ReadBufferMode None;
	static const ReadBufferMode FrontLeft;
	static const ReadBufferMode FrontRight;
	static const ReadBufferMode BackLeft;
	static const ReadBufferMode BackRight;
	static const ReadBufferMode Front;
	static const ReadBufferMode Back;
	static const ReadBufferMode Left;
	static const ReadBufferMode Right;
	static const ReadBufferMode FrontAndBack;
	static const ReadBufferMode Aux0;
	static const ReadBufferMode Aux1;
	static const ReadBufferMode Aux2;
	static const ReadBufferMode Aux3;
	static const ReadBufferMode ColorAttachment0;
	static const ReadBufferMode ColorAttachment1;
	static const ReadBufferMode ColorAttachment2;
	static const ReadBufferMode ColorAttachment3;
	static const ReadBufferMode ColorAttachment4;
	static const ReadBufferMode ColorAttachment5;
	static const ReadBufferMode ColorAttachment6;
	static const ReadBufferMode ColorAttachment7;
	static const ReadBufferMode ColorAttachment8;
	static const ReadBufferMode ColorAttachment9;
	static const ReadBufferMode ColorAttachment10;
	static const ReadBufferMode ColorAttachment11;
	static const ReadBufferMode ColorAttachment12;
	static const ReadBufferMode ColorAttachment13;
	static const ReadBufferMode ColorAttachment14;
	static const ReadBufferMode ColorAttachment15;
OPENGL_ENUM_END

OPENGL_ENUM_START(RenderbufferParameterName)
	static const RenderbufferParameterName RenderbufferSamples;
	static const RenderbufferParameterName RenderbufferWidth;
	static const RenderbufferParameterName RenderbufferWidthExt;
	static const RenderbufferParameterName RenderbufferHeight;
	static const RenderbufferParameterName RenderbufferHeightExt;
	static const RenderbufferParameterName RenderbufferInternalFormat;
	static const RenderbufferParameterName RenderbufferInternalFormatExt;
	static const RenderbufferParameterName RenderbufferRedSize;
	static const RenderbufferParameterName RenderbufferRedSizeExt;
	static const RenderbufferParameterName RenderbufferGreenSize;
	static const RenderbufferParameterName RenderbufferGreenSizeExt;
	static const RenderbufferParameterName RenderbufferBlueSize;
	static const RenderbufferParameterName RenderbufferBlueSizeExt;
	static const RenderbufferParameterName RenderbufferAlphaSize;
	static const RenderbufferParameterName RenderbufferAlphaSizeExt;
	static const RenderbufferParameterName RenderbufferDepthSize;
	static const RenderbufferParameterName RenderbufferDepthSizeExt;
	static const RenderbufferParameterName RenderbufferStencilSize;
	static const RenderbufferParameterName RenderbufferStencilSizeExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(RenderbufferStorage)
	static const RenderbufferStorage DepthComponent;
	static const RenderbufferStorage R3G3B2;
	static const RenderbufferStorage Alpha4;
	static const RenderbufferStorage Alpha8;
	static const RenderbufferStorage Alpha12;
	static const RenderbufferStorage Alpha16;
	static const RenderbufferStorage Rgb4;
	static const RenderbufferStorage Rgb5;
	static const RenderbufferStorage Rgb8;
	static const RenderbufferStorage Rgb10;
	static const RenderbufferStorage Rgb12;
	static const RenderbufferStorage Rgb16;
	static const RenderbufferStorage Rgba2;
	static const RenderbufferStorage Rgba4;
	static const RenderbufferStorage Rgba8;
	static const RenderbufferStorage Rgb10A2;
	static const RenderbufferStorage Rgba12;
	static const RenderbufferStorage Rgba16;
	static const RenderbufferStorage DepthComponent16;
	static const RenderbufferStorage DepthComponent24;
	static const RenderbufferStorage DepthComponent32;
	static const RenderbufferStorage R8;
	static const RenderbufferStorage R16;
	static const RenderbufferStorage Rg8;
	static const RenderbufferStorage Rg16;
	static const RenderbufferStorage R16f;
	static const RenderbufferStorage R32f;
	static const RenderbufferStorage Rg16f;
	static const RenderbufferStorage Rg32f;
	static const RenderbufferStorage R8i;
	static const RenderbufferStorage R8ui;
	static const RenderbufferStorage R16i;
	static const RenderbufferStorage R16ui;
	static const RenderbufferStorage R32i;
	static const RenderbufferStorage R32ui;
	static const RenderbufferStorage Rg8i;
	static const RenderbufferStorage Rg8ui;
	static const RenderbufferStorage Rg16i;
	static const RenderbufferStorage Rg16ui;
	static const RenderbufferStorage Rg32i;
	static const RenderbufferStorage Rg32ui;
	static const RenderbufferStorage DepthStencil;
	static const RenderbufferStorage Rgba32f;
	static const RenderbufferStorage Rgb32f;
	static const RenderbufferStorage Rgba16f;
	static const RenderbufferStorage Rgb16f;
	static const RenderbufferStorage Depth24Stencil8;
	static const RenderbufferStorage R11fG11fB10f;
	static const RenderbufferStorage Rgb9E5;
	static const RenderbufferStorage Srgb8;
	static const RenderbufferStorage Srgb8Alpha8;
	static const RenderbufferStorage DepthComponent32f;
	static const RenderbufferStorage Depth32fStencil8;
	static const RenderbufferStorage StencilIndex1;
	static const RenderbufferStorage StencilIndex1Ext;
	static const RenderbufferStorage StencilIndex4;
	static const RenderbufferStorage StencilIndex4Ext;
	static const RenderbufferStorage StencilIndex8;
	static const RenderbufferStorage StencilIndex8Ext;
	static const RenderbufferStorage StencilIndex16;
	static const RenderbufferStorage StencilIndex16Ext;
	static const RenderbufferStorage Rgba32ui;
	static const RenderbufferStorage Rgb32ui;
	static const RenderbufferStorage Rgba16ui;
	static const RenderbufferStorage Rgb16ui;
	static const RenderbufferStorage Rgba8ui;
	static const RenderbufferStorage Rgb8ui;
	static const RenderbufferStorage Rgba32i;
	static const RenderbufferStorage Rgb32i;
	static const RenderbufferStorage Rgba16i;
	static const RenderbufferStorage Rgb16i;
	static const RenderbufferStorage Rgba8i;
	static const RenderbufferStorage Rgb8i;
	static const RenderbufferStorage Rgb10A2ui;
OPENGL_ENUM_END

OPENGL_ENUM_START(RenderbufferTarget)
	static const RenderbufferTarget Renderbuffer;
	static const RenderbufferTarget RenderbufferExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(RenderingMode)
	static const RenderingMode Render;
	static const RenderingMode Feedback;
	static const RenderingMode Select;
OPENGL_ENUM_END

OPENGL_ENUM_START(RendScreenCoordinates)
	static const RendScreenCoordinates ScreenCoordinatesRend;
	static const RendScreenCoordinates InvertedScreenWRend;
OPENGL_ENUM_END

OPENGL_ENUM_START(ResetStatus)
	static const ResetStatus NoError;
	static const ResetStatus GuiltyContextReset;
	static const ResetStatus InnocentContextReset;
	static const ResetStatus UnknownContextReset;
OPENGL_ENUM_END

OPENGL_ENUM_START(S3S3tc)
	static const S3S3tc RgbS3tc;
	static const S3S3tc Rgb4S3tc;
	static const S3S3tc RgbaS3tc;
	static const S3S3tc Rgba4S3tc;
	static const S3S3tc RgbaDxt5S3tc;
	static const S3S3tc Rgba4Dxt5S3tc;
OPENGL_ENUM_END

OPENGL_ENUM_START(SamplePatternSgis)
	static const SamplePatternSgis Gl1PassExt;
	static const SamplePatternSgis Gl1PassSgis;
	static const SamplePatternSgis Gl2Pass0Ext;
	static const SamplePatternSgis Gl2Pass0Sgis;
	static const SamplePatternSgis Gl2Pass1Ext;
	static const SamplePatternSgis Gl2Pass1Sgis;
	static const SamplePatternSgis Gl4Pass0Ext;
	static const SamplePatternSgis Gl4Pass0Sgis;
	static const SamplePatternSgis Gl4Pass1Ext;
	static const SamplePatternSgis Gl4Pass1Sgis;
	static const SamplePatternSgis Gl4Pass2Ext;
	static const SamplePatternSgis Gl4Pass2Sgis;
	static const SamplePatternSgis Gl4Pass3Ext;
	static const SamplePatternSgis Gl4Pass3Sgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SamplerParameter)
	static const SamplerParameter TextureBorderColor;
	static const SamplerParameter TextureMagFilter;
	static const SamplerParameter TextureMinFilter;
	static const SamplerParameter TextureWrapS;
	static const SamplerParameter TextureWrapT;
	static const SamplerParameter TextureWrapR;
	static const SamplerParameter TextureMinLod;
	static const SamplerParameter TextureMaxLod;
	static const SamplerParameter TextureMaxAnisotropyExt;
	static const SamplerParameter TextureLodBias;
	static const SamplerParameter TextureCompareMode;
	static const SamplerParameter TextureCompareFunc;
OPENGL_ENUM_END

OPENGL_ENUM_START(SamplerParameterName)
	static const SamplerParameterName TextureBorderColor;
	static const SamplerParameterName TextureMagFilter;
	static const SamplerParameterName TextureMinFilter;
	static const SamplerParameterName TextureWrapS;
	static const SamplerParameterName TextureWrapT;
	static const SamplerParameterName TextureWrapR;
	static const SamplerParameterName TextureMinLod;
	static const SamplerParameterName TextureMaxLod;
	static const SamplerParameterName TextureMaxAnisotropyExt;
	static const SamplerParameterName TextureLodBias;
	static const SamplerParameterName TextureCompareMode;
	static const SamplerParameterName TextureCompareFunc;
OPENGL_ENUM_END

OPENGL_ENUM_START(SeparableTarget)
	static const SeparableTarget Separable2D;
OPENGL_ENUM_END

OPENGL_ENUM_START(SeparableTargetExt)
	static const SeparableTargetExt Separable2D;
	static const SeparableTargetExt Separable2DExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgiColorMatrix)
	static const SgiColorMatrix ColorMatrixSgi;
	static const SgiColorMatrix ColorMatrixStackDepthSgi;
	static const SgiColorMatrix MaxColorMatrixStackDepthSgi;
	static const SgiColorMatrix PostColorMatrixRedScaleSgi;
	static const SgiColorMatrix PostColorMatrixGreenScaleSgi;
	static const SgiColorMatrix PostColorMatrixBlueScaleSgi;
	static const SgiColorMatrix PostColorMatrixAlphaScaleSgi;
	static const SgiColorMatrix PostColorMatrixRedBiasSgi;
	static const SgiColorMatrix PostColorMatrixGreenBiasSgi;
	static const SgiColorMatrix PostColorMatrixBlueBiasSgi;
	static const SgiColorMatrix PostColorMatrixAlphaBiasSgi;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgiColorTable)
	static const SgiColorTable ColorTableSgi;
	static const SgiColorTable PostConvolutionColorTableSgi;
	static const SgiColorTable PostColorMatrixColorTableSgi;
	static const SgiColorTable ProxyColorTableSgi;
	static const SgiColorTable ProxyPostConvolutionColorTableSgi;
	static const SgiColorTable ProxyPostColorMatrixColorTableSgi;
	static const SgiColorTable ColorTableScaleSgi;
	static const SgiColorTable ColorTableBiasSgi;
	static const SgiColorTable ColorTableFormatSgi;
	static const SgiColorTable ColorTableWidthSgi;
	static const SgiColorTable ColorTableRedSizeSgi;
	static const SgiColorTable ColorTableGreenSizeSgi;
	static const SgiColorTable ColorTableBlueSizeSgi;
	static const SgiColorTable ColorTableAlphaSizeSgi;
	static const SgiColorTable ColorTableLuminanceSizeSgi;
	static const SgiColorTable ColorTableIntensitySizeSgi;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisDetailTexture)
	static const SgisDetailTexture DetailTexture2DSgis;
	static const SgisDetailTexture DetailTexture2DBindingSgis;
	static const SgisDetailTexture LinearDetailSgis;
	static const SgisDetailTexture LinearDetailAlphaSgis;
	static const SgisDetailTexture LinearDetailColorSgis;
	static const SgisDetailTexture DetailTextureLevelSgis;
	static const SgisDetailTexture DetailTextureModeSgis;
	static const SgisDetailTexture DetailTextureFuncPointsSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisFogFunction)
	static const SgisFogFunction FogFuncSgis;
	static const SgisFogFunction FogFuncPointsSgis;
	static const SgisFogFunction MaxFogFuncPointsSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisGenerateMipmap)
	static const SgisGenerateMipmap GenerateMipmapSgis;
	static const SgisGenerateMipmap GenerateMipmapHintSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisMultisample)
	static const SgisMultisample MultisampleSgis;
	static const SgisMultisample SampleAlphaToMaskSgis;
	static const SgisMultisample SampleAlphaToOneSgis;
	static const SgisMultisample SampleMaskSgis;
	static const SgisMultisample Gl1PassSgis;
	static const SgisMultisample Gl2Pass0Sgis;
	static const SgisMultisample Gl2Pass1Sgis;
	static const SgisMultisample Gl4Pass0Sgis;
	static const SgisMultisample Gl4Pass1Sgis;
	static const SgisMultisample Gl4Pass2Sgis;
	static const SgisMultisample Gl4Pass3Sgis;
	static const SgisMultisample SampleBuffersSgis;
	static const SgisMultisample SamplesSgis;
	static const SgisMultisample SampleMaskValueSgis;
	static const SgisMultisample SampleMaskInvertSgis;
	static const SgisMultisample SamplePatternSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisPixelTexture)
	static const SgisPixelTexture PixelTextureSgis;
	static const SgisPixelTexture PixelFragmentRgbSourceSgis;
	static const SgisPixelTexture PixelFragmentAlphaSourceSgis;
	static const SgisPixelTexture PixelGroupColorSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisPointLineTexgen)
	static const SgisPointLineTexgen EyeDistanceToPointSgis;
	static const SgisPointLineTexgen ObjectDistanceToPointSgis;
	static const SgisPointLineTexgen EyeDistanceToLineSgis;
	static const SgisPointLineTexgen ObjectDistanceToLineSgis;
	static const SgisPointLineTexgen EyePointSgis;
	static const SgisPointLineTexgen ObjectPointSgis;
	static const SgisPointLineTexgen EyeLineSgis;
	static const SgisPointLineTexgen ObjectLineSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisPointParameters)
	static const SgisPointParameters PointSizeMinSgis;
	static const SgisPointParameters PointSizeMaxSgis;
	static const SgisPointParameters PointFadeThresholdSizeSgis;
	static const SgisPointParameters DistanceAttenuationSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisSharpenTexture)
	static const SgisSharpenTexture LinearSharpenSgis;
	static const SgisSharpenTexture LinearSharpenAlphaSgis;
	static const SgisSharpenTexture LinearSharpenColorSgis;
	static const SgisSharpenTexture SharpenTextureFuncPointsSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisTexture4D)
	static const SgisTexture4D PackSkipVolumesSgis;
	static const SgisTexture4D PackImageDepthSgis;
	static const SgisTexture4D UnpackSkipVolumesSgis;
	static const SgisTexture4D UnpackImageDepthSgis;
	static const SgisTexture4D Texture4DSgis;
	static const SgisTexture4D ProxyTexture4DSgis;
	static const SgisTexture4D Texture4DsizeSgis;
	static const SgisTexture4D TextureWrapQSgis;
	static const SgisTexture4D Max4DTextureSizeSgis;
	static const SgisTexture4D Texture4DBindingSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisTextureBorderClamp)
	static const SgisTextureBorderClamp ClampToBorderSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisTextureColorMask)
	static const SgisTextureColorMask TextureColorWritemaskSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisTextureEdgeClamp)
	static const SgisTextureEdgeClamp ClampToEdgeSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisTextureFilter4)
	static const SgisTextureFilter4 Filter4Sgis;
	static const SgisTextureFilter4 TextureFilter4SizeSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisTextureLod)
	static const SgisTextureLod TextureMinLodSgis;
	static const SgisTextureLod TextureMaxLodSgis;
	static const SgisTextureLod TextureBaseLevelSgis;
	static const SgisTextureLod TextureMaxLevelSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgisTextureSelect)
	static const SgisTextureSelect DualAlpha4Sgis;
	static const SgisTextureSelect DualAlpha8Sgis;
	static const SgisTextureSelect DualAlpha12Sgis;
	static const SgisTextureSelect DualAlpha16Sgis;
	static const SgisTextureSelect DualLuminance4Sgis;
	static const SgisTextureSelect DualLuminance8Sgis;
	static const SgisTextureSelect DualLuminance12Sgis;
	static const SgisTextureSelect DualLuminance16Sgis;
	static const SgisTextureSelect DualIntensity4Sgis;
	static const SgisTextureSelect DualIntensity8Sgis;
	static const SgisTextureSelect DualIntensity12Sgis;
	static const SgisTextureSelect DualIntensity16Sgis;
	static const SgisTextureSelect DualLuminanceAlpha4Sgis;
	static const SgisTextureSelect DualLuminanceAlpha8Sgis;
	static const SgisTextureSelect QuadAlpha4Sgis;
	static const SgisTextureSelect QuadAlpha8Sgis;
	static const SgisTextureSelect QuadLuminance4Sgis;
	static const SgisTextureSelect QuadLuminance8Sgis;
	static const SgisTextureSelect QuadIntensity4Sgis;
	static const SgisTextureSelect QuadIntensity8Sgis;
	static const SgisTextureSelect DualTextureSelectSgis;
	static const SgisTextureSelect QuadTextureSelectSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgiTextureColorTable)
	static const SgiTextureColorTable TextureColorTableSgi;
	static const SgiTextureColorTable ProxyTextureColorTableSgi;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixAsync)
	static const SgixAsync AsyncMarkerSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixAsyncHistogram)
	static const SgixAsyncHistogram AsyncHistogramSgix;
	static const SgixAsyncHistogram MaxAsyncHistogramSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixAsyncPixel)
	static const SgixAsyncPixel AsyncTexImageSgix;
	static const SgixAsyncPixel AsyncDrawPixelsSgix;
	static const SgixAsyncPixel AsyncReadPixelsSgix;
	static const SgixAsyncPixel MaxAsyncTexImageSgix;
	static const SgixAsyncPixel MaxAsyncDrawPixelsSgix;
	static const SgixAsyncPixel MaxAsyncReadPixelsSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixBlendAlphaMinmax)
	static const SgixBlendAlphaMinmax AlphaMinSgix;
	static const SgixBlendAlphaMinmax AlphaMaxSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixCalligraphicFragment)
	static const SgixCalligraphicFragment CalligraphicFragmentSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixClipmap)
	static const SgixClipmap LinearClipmapLinearSgix;
	static const SgixClipmap TextureClipmapCenterSgix;
	static const SgixClipmap TextureClipmapFrameSgix;
	static const SgixClipmap TextureClipmapOffsetSgix;
	static const SgixClipmap TextureClipmapVirtualDepthSgix;
	static const SgixClipmap TextureClipmapLodOffsetSgix;
	static const SgixClipmap TextureClipmapDepthSgix;
	static const SgixClipmap MaxClipmapDepthSgix;
	static const SgixClipmap MaxClipmapVirtualDepthSgix;
	static const SgixClipmap NearestClipmapNearestSgix;
	static const SgixClipmap NearestClipmapLinearSgix;
	static const SgixClipmap LinearClipmapNearestSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixConvolutionAccuracy)
	static const SgixConvolutionAccuracy ConvolutionHintSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixDepthPassInstrument)
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixDepthTexture)
	static const SgixDepthTexture DepthComponent16Sgix;
	static const SgixDepthTexture DepthComponent24Sgix;
	static const SgixDepthTexture DepthComponent32Sgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixFlushRaster)
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixFogOffset)
	static const SgixFogOffset FogOffsetSgix;
	static const SgixFogOffset FogOffsetValueSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixFragmentLighting)
	static const SgixFragmentLighting FragmentLightingSgix;
	static const SgixFragmentLighting FragmentColorMaterialSgix;
	static const SgixFragmentLighting FragmentColorMaterialFaceSgix;
	static const SgixFragmentLighting FragmentColorMaterialParameterSgix;
	static const SgixFragmentLighting MaxFragmentLightsSgix;
	static const SgixFragmentLighting MaxActiveLightsSgix;
	static const SgixFragmentLighting CurrentRasterNormalSgix;
	static const SgixFragmentLighting LightEnvModeSgix;
	static const SgixFragmentLighting FragmentLightModelLocalViewerSgix;
	static const SgixFragmentLighting FragmentLightModelTwoSideSgix;
	static const SgixFragmentLighting FragmentLightModelAmbientSgix;
	static const SgixFragmentLighting FragmentLightModelNormalInterpolationSgix;
	static const SgixFragmentLighting FragmentLight0Sgix;
	static const SgixFragmentLighting FragmentLight1Sgix;
	static const SgixFragmentLighting FragmentLight2Sgix;
	static const SgixFragmentLighting FragmentLight3Sgix;
	static const SgixFragmentLighting FragmentLight4Sgix;
	static const SgixFragmentLighting FragmentLight5Sgix;
	static const SgixFragmentLighting FragmentLight6Sgix;
	static const SgixFragmentLighting FragmentLight7Sgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixFramezoom)
	static const SgixFramezoom FramezoomSgix;
	static const SgixFramezoom FramezoomFactorSgix;
	static const SgixFramezoom MaxFramezoomFactorSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixIccTexture)
	static const SgixIccTexture RgbIccSgix;
	static const SgixIccTexture RgbaIccSgix;
	static const SgixIccTexture AlphaIccSgix;
	static const SgixIccTexture LuminanceIccSgix;
	static const SgixIccTexture IntensityIccSgix;
	static const SgixIccTexture LuminanceAlphaIccSgix;
	static const SgixIccTexture R5G6B5IccSgix;
	static const SgixIccTexture R5G6B5A8IccSgix;
	static const SgixIccTexture Alpha16IccSgix;
	static const SgixIccTexture Luminance16IccSgix;
	static const SgixIccTexture Intensity16IccSgix;
	static const SgixIccTexture Luminance16Alpha8IccSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixIglooInterface)
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixInstruments)
	static const SgixInstruments InstrumentBufferPointerSgix;
	static const SgixInstruments InstrumentMeasurementsSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixInterlace)
	static const SgixInterlace InterlaceSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixIrInstrument1)
	static const SgixIrInstrument1 IrInstrument1Sgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixListPriority)
	static const SgixListPriority ListPrioritySgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixPixelTexture)
	static const SgixPixelTexture PixelTexGenSgix;
	static const SgixPixelTexture PixelTexGenModeSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixPixelTiles)
	static const SgixPixelTiles PixelTileBestAlignmentSgix;
	static const SgixPixelTiles PixelTileCacheIncrementSgix;
	static const SgixPixelTiles PixelTileWidthSgix;
	static const SgixPixelTiles PixelTileHeightSgix;
	static const SgixPixelTiles PixelTileGridWidthSgix;
	static const SgixPixelTiles PixelTileGridHeightSgix;
	static const SgixPixelTiles PixelTileGridDepthSgix;
	static const SgixPixelTiles PixelTileCacheSizeSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixPolynomialFfd)
	static const SgixPolynomialFfd TextureDeformationBitSgix;
	static const SgixPolynomialFfd GeometryDeformationBitSgix;
	static const SgixPolynomialFfd GeometryDeformationSgix;
	static const SgixPolynomialFfd TextureDeformationSgix;
	static const SgixPolynomialFfd DeformationsMaskSgix;
	static const SgixPolynomialFfd MaxDeformationOrderSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixReferencePlane)
	static const SgixReferencePlane ReferencePlaneSgix;
	static const SgixReferencePlane ReferencePlaneEquationSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixResample)
	static const SgixResample PackResampleSgix;
	static const SgixResample UnpackResampleSgix;
	static const SgixResample ResampleReplicateSgix;
	static const SgixResample ResampleZeroFillSgix;
	static const SgixResample ResampleDecimateSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixScalebiasHint)
	static const SgixScalebiasHint ScalebiasHintSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixShadow)
	static const SgixShadow TextureCompareSgix;
	static const SgixShadow TextureCompareOperatorSgix;
	static const SgixShadow TextureLequalRSgix;
	static const SgixShadow TextureGequalRSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixShadowAmbient)
	static const SgixShadowAmbient ShadowAmbientSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixSprite)
	static const SgixSprite SpriteSgix;
	static const SgixSprite SpriteModeSgix;
	static const SgixSprite SpriteAxisSgix;
	static const SgixSprite SpriteTranslationSgix;
	static const SgixSprite SpriteAxialSgix;
	static const SgixSprite SpriteObjectAlignedSgix;
	static const SgixSprite SpriteEyeAlignedSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixSubsample)
	static const SgixSubsample PackSubsampleRateSgix;
	static const SgixSubsample UnpackSubsampleRateSgix;
	static const SgixSubsample PixelSubsample4444Sgix;
	static const SgixSubsample PixelSubsample2424Sgix;
	static const SgixSubsample PixelSubsample4242Sgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixTagSampleBuffer)
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixTextureAddEnv)
	static const SgixTextureAddEnv TextureEnvBiasSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixTextureCoordinateClamp)
	static const SgixTextureCoordinateClamp TextureMaxClampSSgix;
	static const SgixTextureCoordinateClamp TextureMaxClampTSgix;
	static const SgixTextureCoordinateClamp TextureMaxClampRSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixTextureLodBias)
	static const SgixTextureLodBias TextureLodBiasSSgix;
	static const SgixTextureLodBias TextureLodBiasTSgix;
	static const SgixTextureLodBias TextureLodBiasRSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixTextureMultiBuffer)
	static const SgixTextureMultiBuffer TextureMultiBufferHintSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixTextureScaleBias)
	static const SgixTextureScaleBias PostTextureFilterBiasSgix;
	static const SgixTextureScaleBias PostTextureFilterScaleSgix;
	static const SgixTextureScaleBias PostTextureFilterBiasRangeSgix;
	static const SgixTextureScaleBias PostTextureFilterScaleRangeSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixVertexPreclip)
	static const SgixVertexPreclip VertexPreclipSgix;
	static const SgixVertexPreclip VertexPreclipHintSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixYcrcb)
	static const SgixYcrcb Ycrcb422Sgix;
	static const SgixYcrcb Ycrcb444Sgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixYcrcba)
	static const SgixYcrcba YcrcbSgix;
	static const SgixYcrcba YcrcbaSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(SgixYcrcbSubsample)
OPENGL_ENUM_END

OPENGL_ENUM_START(ShaderParameter)
	static const ShaderParameter ShaderType;
	static const ShaderParameter DeleteStatus;
	static const ShaderParameter CompileStatus;
	static const ShaderParameter InfoLogLength;
	static const ShaderParameter ShaderSourceLength;
OPENGL_ENUM_END

OPENGL_ENUM_START(ShaderPrecision)
	static const ShaderPrecision LowFloat;
	static const ShaderPrecision MediumFloat;
	static const ShaderPrecision HighFloat;
	static const ShaderPrecision LowInt;
	static const ShaderPrecision MediumInt;
	static const ShaderPrecision HighInt;
OPENGL_ENUM_END

OPENGL_ENUM_START(ShaderType)
	static const ShaderType FragmentShader;
	static const ShaderType VertexShader;
	static const ShaderType GeometryShader;
	static const ShaderType GeometryShaderExt;
	static const ShaderType TessEvaluationShader;
	static const ShaderType TessControlShader;
	static const ShaderType ComputeShader;
OPENGL_ENUM_END

OPENGL_ENUM_START(ShadingModel)
	static const ShadingModel Flat;
	static const ShadingModel Smooth;
OPENGL_ENUM_END

OPENGL_ENUM_START(SizedInternalFormat)
	static const SizedInternalFormat Rgba8;
	static const SizedInternalFormat Rgba16;
	static const SizedInternalFormat R8;
	static const SizedInternalFormat R16;
	static const SizedInternalFormat Rg8;
	static const SizedInternalFormat Rg16;
	static const SizedInternalFormat R16f;
	static const SizedInternalFormat R32f;
	static const SizedInternalFormat Rg16f;
	static const SizedInternalFormat Rg32f;
	static const SizedInternalFormat R8i;
	static const SizedInternalFormat R8ui;
	static const SizedInternalFormat R16i;
	static const SizedInternalFormat R16ui;
	static const SizedInternalFormat R32i;
	static const SizedInternalFormat R32ui;
	static const SizedInternalFormat Rg8i;
	static const SizedInternalFormat Rg8ui;
	static const SizedInternalFormat Rg16i;
	static const SizedInternalFormat Rg16ui;
	static const SizedInternalFormat Rg32i;
	static const SizedInternalFormat Rg32ui;
	static const SizedInternalFormat Rgba32f;
	static const SizedInternalFormat Rgba16f;
	static const SizedInternalFormat Rgba32ui;
	static const SizedInternalFormat Rgba16ui;
	static const SizedInternalFormat Rgba8ui;
	static const SizedInternalFormat Rgba32i;
	static const SizedInternalFormat Rgba16i;
	static const SizedInternalFormat Rgba8i;
OPENGL_ENUM_END

OPENGL_ENUM_START(StencilFace)
	static const StencilFace Front;
	static const StencilFace Back;
	static const StencilFace FrontAndBack;
OPENGL_ENUM_END

OPENGL_ENUM_START(StencilFunction)
	static const StencilFunction Never;
	static const StencilFunction Less;
	static const StencilFunction Equal;
	static const StencilFunction Lequal;
	static const StencilFunction Greater;
	static const StencilFunction Notequal;
	static const StencilFunction Gequal;
	static const StencilFunction Always;
OPENGL_ENUM_END

OPENGL_ENUM_START(StencilOp)
	static const StencilOp Zero;
	static const StencilOp Invert;
	static const StencilOp Keep;
	static const StencilOp Replace;
	static const StencilOp Incr;
	static const StencilOp Decr;
	static const StencilOp IncrWrap;
	static const StencilOp DecrWrap;
OPENGL_ENUM_END

OPENGL_ENUM_START(StringName)
	static const StringName Vendor;
	static const StringName Renderer;
	static const StringName Version;
	static const StringName Extensions;
	static const StringName ShadingLanguageVersion;
OPENGL_ENUM_END

OPENGL_ENUM_START(StringNameIndexed)
	static const StringNameIndexed Extensions;
	static const StringNameIndexed ShadingLanguageVersion;
OPENGL_ENUM_END

OPENGL_ENUM_START(SunConvolutionBorderModes)
	static const SunConvolutionBorderModes WrapBorderSun;
OPENGL_ENUM_END

OPENGL_ENUM_START(SunGlobalAlpha)
	static const SunGlobalAlpha GlobalAlphaSun;
	static const SunGlobalAlpha GlobalAlphaFactorSun;
OPENGL_ENUM_END

OPENGL_ENUM_START(SunMeshArray)
	static const SunMeshArray QuadMeshSun;
	static const SunMeshArray TriangleMeshSun;
OPENGL_ENUM_END

OPENGL_ENUM_START(SunSliceAccum)
	static const SunSliceAccum SliceAccumSun;
OPENGL_ENUM_END

OPENGL_ENUM_START(SunTriangleList)
	static const SunTriangleList RestartSun;
	static const SunTriangleList ReplaceMiddleSun;
	static const SunTriangleList ReplaceOldestSun;
	static const SunTriangleList TriangleListSun;
	static const SunTriangleList ReplacementCodeSun;
	static const SunTriangleList ReplacementCodeArraySun;
	static const SunTriangleList ReplacementCodeArrayTypeSun;
	static const SunTriangleList ReplacementCodeArrayStrideSun;
	static const SunTriangleList ReplacementCodeArrayPointerSun;
	static const SunTriangleList R1uiV3fSun;
	static const SunTriangleList R1uiC4ubV3fSun;
	static const SunTriangleList R1uiC3fV3fSun;
	static const SunTriangleList R1uiN3fV3fSun;
	static const SunTriangleList R1uiC4fN3fV3fSun;
	static const SunTriangleList R1uiT2fV3fSun;
	static const SunTriangleList R1uiT2fN3fV3fSun;
	static const SunTriangleList R1uiT2fC4fN3fV3fSun;
OPENGL_ENUM_END

OPENGL_ENUM_START(SunVertex)
OPENGL_ENUM_END

OPENGL_ENUM_START(SunxConstantData)
	static const SunxConstantData UnpackConstantDataSunx;
	static const SunxConstantData TextureConstantDataSunx;
OPENGL_ENUM_END

OPENGL_ENUM_START(SyncCondition)
	static const SyncCondition SyncGpuCommandsComplete;
OPENGL_ENUM_END

OPENGL_ENUM_START(SyncParameterName)
	static const SyncParameterName ObjectType;
	static const SyncParameterName SyncCondition;
	static const SyncParameterName SyncStatus;
	static const SyncParameterName SyncFlags;
OPENGL_ENUM_END

OPENGL_ENUM_START(TexCoordPointerType)
	static const TexCoordPointerType Short;
	static const TexCoordPointerType Int;
	static const TexCoordPointerType Float;
	static const TexCoordPointerType Double;
	static const TexCoordPointerType HalfFloat;
	static const TexCoordPointerType UnsignedInt2101010Rev;
	static const TexCoordPointerType Int2101010Rev;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureAccess)
	static const TextureAccess ReadOnly;
	static const TextureAccess WriteOnly;
	static const TextureAccess ReadWrite;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureBufferTarget)
	static const TextureBufferTarget TextureBuffer;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureCompareMode)
	static const TextureCompareMode None;
	static const TextureCompareMode CompareRefToTexture;
	static const TextureCompareMode CompareRToTexture;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureCoordName)
	static const TextureCoordName S;
	static const TextureCoordName T;
	static const TextureCoordName R;
	static const TextureCoordName Q;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureEnvMode)
	static const TextureEnvMode Add;
	static const TextureEnvMode Blend;
	static const TextureEnvMode Replace;
	static const TextureEnvMode Modulate;
	static const TextureEnvMode Decal;
	static const TextureEnvMode ReplaceExt;
	static const TextureEnvMode TextureEnvBiasSgix;
	static const TextureEnvMode Combine;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureEnvModeCombine)
	static const TextureEnvModeCombine Add;
	static const TextureEnvModeCombine Replace;
	static const TextureEnvModeCombine Modulate;
	static const TextureEnvModeCombine Subtract;
	static const TextureEnvModeCombine AddSigned;
	static const TextureEnvModeCombine Interpolate;
	static const TextureEnvModeCombine Dot3Rgb;
	static const TextureEnvModeCombine Dot3Rgba;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureEnvModeOperandAlpha)
	static const TextureEnvModeOperandAlpha SrcAlpha;
	static const TextureEnvModeOperandAlpha OneMinusSrcAlpha;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureEnvModeOperandRgb)
	static const TextureEnvModeOperandRgb SrcColor;
	static const TextureEnvModeOperandRgb OneMinusSrcColor;
	static const TextureEnvModeOperandRgb SrcAlpha;
	static const TextureEnvModeOperandRgb OneMinusSrcAlpha;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureEnvModePointSprite)
	static const TextureEnvModePointSprite False;
	static const TextureEnvModePointSprite True;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureEnvModeScale)
	static const TextureEnvModeScale One;
	static const TextureEnvModeScale Two;
	static const TextureEnvModeScale Four;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureEnvModeSource)
	static const TextureEnvModeSource Texture;
	static const TextureEnvModeSource Texture0;
	static const TextureEnvModeSource Texture1;
	static const TextureEnvModeSource Texture2;
	static const TextureEnvModeSource Texture3;
	static const TextureEnvModeSource Texture4;
	static const TextureEnvModeSource Texture5;
	static const TextureEnvModeSource Texture6;
	static const TextureEnvModeSource Texture7;
	static const TextureEnvModeSource Texture8;
	static const TextureEnvModeSource Texture9;
	static const TextureEnvModeSource Texture10;
	static const TextureEnvModeSource Texture11;
	static const TextureEnvModeSource Texture12;
	static const TextureEnvModeSource Texture13;
	static const TextureEnvModeSource Texture14;
	static const TextureEnvModeSource Texture15;
	static const TextureEnvModeSource Texture16;
	static const TextureEnvModeSource Texture17;
	static const TextureEnvModeSource Texture18;
	static const TextureEnvModeSource Texture19;
	static const TextureEnvModeSource Texture20;
	static const TextureEnvModeSource Texture21;
	static const TextureEnvModeSource Texture22;
	static const TextureEnvModeSource Texture23;
	static const TextureEnvModeSource Texture24;
	static const TextureEnvModeSource Texture25;
	static const TextureEnvModeSource Texture26;
	static const TextureEnvModeSource Texture27;
	static const TextureEnvModeSource Texture28;
	static const TextureEnvModeSource Texture29;
	static const TextureEnvModeSource Texture30;
	static const TextureEnvModeSource Texture31;
	static const TextureEnvModeSource Constant;
	static const TextureEnvModeSource PrimaryColor;
	static const TextureEnvModeSource Previous;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureEnvParameter)
	static const TextureEnvParameter AlphaScale;
	static const TextureEnvParameter TextureEnvMode;
	static const TextureEnvParameter TextureEnvColor;
	static const TextureEnvParameter TextureLodBias;
	static const TextureEnvParameter CombineRgb;
	static const TextureEnvParameter CombineAlpha;
	static const TextureEnvParameter RgbScale;
	static const TextureEnvParameter Source0Rgb;
	static const TextureEnvParameter Src1Rgb;
	static const TextureEnvParameter Src2Rgb;
	static const TextureEnvParameter Src0Alpha;
	static const TextureEnvParameter Src1Alpha;
	static const TextureEnvParameter Src2Alpha;
	static const TextureEnvParameter Operand0Rgb;
	static const TextureEnvParameter Operand1Rgb;
	static const TextureEnvParameter Operand2Rgb;
	static const TextureEnvParameter Operand0Alpha;
	static const TextureEnvParameter Operand1Alpha;
	static const TextureEnvParameter Operand2Alpha;
	static const TextureEnvParameter CoordReplace;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureEnvTarget)
	static const TextureEnvTarget TextureEnv;
	static const TextureEnvTarget TextureFilterControl;
	static const TextureEnvTarget PointSprite;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureFilterFuncSgis)
	static const TextureFilterFuncSgis Filter4Sgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureGenMode)
	static const TextureGenMode EyeLinear;
	static const TextureGenMode ObjectLinear;
	static const TextureGenMode SphereMap;
	static const TextureGenMode EyeDistanceToPointSgis;
	static const TextureGenMode ObjectDistanceToPointSgis;
	static const TextureGenMode EyeDistanceToLineSgis;
	static const TextureGenMode ObjectDistanceToLineSgis;
	static const TextureGenMode NormalMap;
	static const TextureGenMode ReflectionMap;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureGenParameter)
	static const TextureGenParameter TextureGenMode;
	static const TextureGenParameter ObjectPlane;
	static const TextureGenParameter EyePlane;
	static const TextureGenParameter EyePointSgis;
	static const TextureGenParameter ObjectPointSgis;
	static const TextureGenParameter EyeLineSgis;
	static const TextureGenParameter ObjectLineSgis;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureMagFilter)
	static const TextureMagFilter Nearest;
	static const TextureMagFilter Linear;
	static const TextureMagFilter LinearDetailSgis;
	static const TextureMagFilter LinearDetailAlphaSgis;
	static const TextureMagFilter LinearDetailColorSgis;
	static const TextureMagFilter LinearSharpenSgis;
	static const TextureMagFilter LinearSharpenAlphaSgis;
	static const TextureMagFilter LinearSharpenColorSgis;
	static const TextureMagFilter Filter4Sgis;
	static const TextureMagFilter PixelTexGenQCeilingSgix;
	static const TextureMagFilter PixelTexGenQRoundSgix;
	static const TextureMagFilter PixelTexGenQFloorSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureMinFilter)
	static const TextureMinFilter Nearest;
	static const TextureMinFilter Linear;
	static const TextureMinFilter NearestMipmapNearest;
	static const TextureMinFilter LinearMipmapNearest;
	static const TextureMinFilter NearestMipmapLinear;
	static const TextureMinFilter LinearMipmapLinear;
	static const TextureMinFilter Filter4Sgis;
	static const TextureMinFilter LinearClipmapLinearSgix;
	static const TextureMinFilter PixelTexGenQCeilingSgix;
	static const TextureMinFilter PixelTexGenQRoundSgix;
	static const TextureMinFilter PixelTexGenQFloorSgix;
	static const TextureMinFilter NearestClipmapNearestSgix;
	static const TextureMinFilter NearestClipmapLinearSgix;
	static const TextureMinFilter LinearClipmapNearestSgix;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureParameterName)
	static const TextureParameterName TextureBorderColor;
	static const TextureParameterName TextureMagFilter;
	static const TextureParameterName TextureMinFilter;
	static const TextureParameterName TextureWrapS;
	static const TextureParameterName TextureWrapT;
	static const TextureParameterName TexturePriority;
	static const TextureParameterName TexturePriorityExt;
	static const TextureParameterName TextureDepth;
	static const TextureParameterName TextureWrapR;
	static const TextureParameterName TextureWrapRExt;
	static const TextureParameterName TextureWrapROes;
	static const TextureParameterName DetailTextureLevelSgis;
	static const TextureParameterName DetailTextureModeSgis;
	static const TextureParameterName ShadowAmbientSgix;
	static const TextureParameterName TextureCompareFailValue;
	static const TextureParameterName DualTextureSelectSgis;
	static const TextureParameterName QuadTextureSelectSgis;
	static const TextureParameterName ClampToBorder;
	static const TextureParameterName ClampToEdge;
	static const TextureParameterName TextureWrapQSgis;
	static const TextureParameterName TextureMinLod;
	static const TextureParameterName TextureMaxLod;
	static const TextureParameterName TextureBaseLevel;
	static const TextureParameterName TextureMaxLevel;
	static const TextureParameterName TextureClipmapCenterSgix;
	static const TextureParameterName TextureClipmapFrameSgix;
	static const TextureParameterName TextureClipmapOffsetSgix;
	static const TextureParameterName TextureClipmapVirtualDepthSgix;
	static const TextureParameterName TextureClipmapLodOffsetSgix;
	static const TextureParameterName TextureClipmapDepthSgix;
	static const TextureParameterName PostTextureFilterBiasSgix;
	static const TextureParameterName PostTextureFilterScaleSgix;
	static const TextureParameterName TextureLodBiasSSgix;
	static const TextureParameterName TextureLodBiasTSgix;
	static const TextureParameterName TextureLodBiasRSgix;
	static const TextureParameterName GenerateMipmap;
	static const TextureParameterName GenerateMipmapSgis;
	static const TextureParameterName TextureCompareSgix;
	static const TextureParameterName TextureMaxClampSSgix;
	static const TextureParameterName TextureMaxClampTSgix;
	static const TextureParameterName TextureMaxClampRSgix;
	static const TextureParameterName TextureLodBias;
	static const TextureParameterName DepthTextureMode;
	static const TextureParameterName TextureCompareMode;
	static const TextureParameterName TextureCompareFunc;
	static const TextureParameterName TextureSwizzleR;
	static const TextureParameterName TextureSwizzleG;
	static const TextureParameterName TextureSwizzleB;
	static const TextureParameterName TextureSwizzleA;
	static const TextureParameterName TextureSwizzleRgba;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureTarget)
	static const TextureTarget Texture1D;
	static const TextureTarget Texture2D;
	static const TextureTarget ProxyTexture1D;
	static const TextureTarget ProxyTexture1DExt;
	static const TextureTarget ProxyTexture2D;
	static const TextureTarget ProxyTexture2DExt;
	static const TextureTarget Texture3D;
	static const TextureTarget Texture3DExt;
	static const TextureTarget Texture3DOes;
	static const TextureTarget ProxyTexture3D;
	static const TextureTarget ProxyTexture3DExt;
	static const TextureTarget DetailTexture2DSgis;
	static const TextureTarget Texture4DSgis;
	static const TextureTarget ProxyTexture4DSgis;
	static const TextureTarget TextureMinLod;
	static const TextureTarget TextureMinLodSgis;
	static const TextureTarget TextureMaxLod;
	static const TextureTarget TextureMaxLodSgis;
	static const TextureTarget TextureBaseLevel;
	static const TextureTarget TextureBaseLevelSgis;
	static const TextureTarget TextureMaxLevel;
	static const TextureTarget TextureMaxLevelSgis;
	static const TextureTarget TextureRectangle;
	static const TextureTarget TextureRectangleArb;
	static const TextureTarget TextureRectangleNv;
	static const TextureTarget ProxyTextureRectangle;
	static const TextureTarget TextureCubeMap;
	static const TextureTarget TextureBindingCubeMap;
	static const TextureTarget TextureCubeMapPositiveX;
	static const TextureTarget TextureCubeMapNegativeX;
	static const TextureTarget TextureCubeMapPositiveY;
	static const TextureTarget TextureCubeMapNegativeY;
	static const TextureTarget TextureCubeMapPositiveZ;
	static const TextureTarget TextureCubeMapNegativeZ;
	static const TextureTarget ProxyTextureCubeMap;
	static const TextureTarget Texture1DArray;
	static const TextureTarget ProxyTexture1DArray;
	static const TextureTarget Texture2DArray;
	static const TextureTarget ProxyTexture2DArray;
	static const TextureTarget TextureBuffer;
	static const TextureTarget TextureCubeMapArray;
	static const TextureTarget ProxyTextureCubeMapArray;
	static const TextureTarget Texture2DMultisample;
	static const TextureTarget ProxyTexture2DMultisample;
	static const TextureTarget Texture2DMultisampleArray;
	static const TextureTarget ProxyTexture2DMultisampleArray;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureTarget1d)
	static const TextureTarget1d Texture1D;
	static const TextureTarget1d ProxyTexture1D;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureTarget2d)
	static const TextureTarget2d Texture2D;
	static const TextureTarget2d ProxyTexture2D;
	static const TextureTarget2d TextureRectangle;
	static const TextureTarget2d ProxyTextureRectangle;
	static const TextureTarget2d TextureCubeMap;
	static const TextureTarget2d ProxyTextureCubeMap;
	static const TextureTarget2d Texture1DArray;
	static const TextureTarget2d ProxyTexture1DArray;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureTarget3d)
	static const TextureTarget3d Texture3D;
	static const TextureTarget3d ProxyTexture3D;
	static const TextureTarget3d TextureCubeMap;
	static const TextureTarget3d ProxyTextureCubeMap;
	static const TextureTarget3d Texture2DArray;
	static const TextureTarget3d ProxyTexture2DArray;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureTargetMultisample)
	static const TextureTargetMultisample Texture2DMultisample;
	static const TextureTargetMultisample ProxyTexture2DMultisample;
	static const TextureTargetMultisample Texture2DMultisampleArray;
	static const TextureTargetMultisample ProxyTexture2DMultisampleArray;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureTargetMultisample2d)
	static const TextureTargetMultisample2d Texture2DMultisample;
	static const TextureTargetMultisample2d ProxyTexture2DMultisample;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureTargetMultisample3d)
	static const TextureTargetMultisample3d Texture2DMultisampleArray;
	static const TextureTargetMultisample3d ProxyTexture2DMultisampleArray;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureUnit)
	static const TextureUnit Texture0;
	static const TextureUnit Texture1;
	static const TextureUnit Texture2;
	static const TextureUnit Texture3;
	static const TextureUnit Texture4;
	static const TextureUnit Texture5;
	static const TextureUnit Texture6;
	static const TextureUnit Texture7;
	static const TextureUnit Texture8;
	static const TextureUnit Texture9;
	static const TextureUnit Texture10;
	static const TextureUnit Texture11;
	static const TextureUnit Texture12;
	static const TextureUnit Texture13;
	static const TextureUnit Texture14;
	static const TextureUnit Texture15;
	static const TextureUnit Texture16;
	static const TextureUnit Texture17;
	static const TextureUnit Texture18;
	static const TextureUnit Texture19;
	static const TextureUnit Texture20;
	static const TextureUnit Texture21;
	static const TextureUnit Texture22;
	static const TextureUnit Texture23;
	static const TextureUnit Texture24;
	static const TextureUnit Texture25;
	static const TextureUnit Texture26;
	static const TextureUnit Texture27;
	static const TextureUnit Texture28;
	static const TextureUnit Texture29;
	static const TextureUnit Texture30;
	static const TextureUnit Texture31;
OPENGL_ENUM_END

OPENGL_ENUM_START(TextureWrapMode)
	static const TextureWrapMode Clamp;
	static const TextureWrapMode Repeat;
	static const TextureWrapMode ClampToBorder;
	static const TextureWrapMode ClampToBorderArb;
	static const TextureWrapMode ClampToBorderNv;
	static const TextureWrapMode ClampToBorderSgis;
	static const TextureWrapMode ClampToEdge;
	static const TextureWrapMode ClampToEdgeSgis;
	static const TextureWrapMode MirroredRepeat;
OPENGL_ENUM_END

OPENGL_ENUM_START(TransformFeedbackIndexedParameter)
	static const TransformFeedbackIndexedParameter TransformFeedbackBufferStart;
	static const TransformFeedbackIndexedParameter TransformFeedbackBufferSize;
	static const TransformFeedbackIndexedParameter TransformFeedbackBufferBinding;
OPENGL_ENUM_END

OPENGL_ENUM_START(TransformFeedbackMode)
	static const TransformFeedbackMode InterleavedAttribs;
	static const TransformFeedbackMode SeparateAttribs;
OPENGL_ENUM_END

OPENGL_ENUM_START(TransformFeedbackParameter)
	static const TransformFeedbackParameter TransformFeedbackPaused;
	static const TransformFeedbackParameter TransformFeedbackActive;
OPENGL_ENUM_END

OPENGL_ENUM_START(TransformFeedbackPrimitiveType)
	static const TransformFeedbackPrimitiveType Points;
	static const TransformFeedbackPrimitiveType Lines;
	static const TransformFeedbackPrimitiveType Triangles;
OPENGL_ENUM_END

OPENGL_ENUM_START(TransformFeedbackTarget)
	static const TransformFeedbackTarget TransformFeedback;
OPENGL_ENUM_END

OPENGL_ENUM_START(TransformFeedbackType)
	static const TransformFeedbackType Int;
	static const TransformFeedbackType UnsignedInt;
	static const TransformFeedbackType Float;
	static const TransformFeedbackType Double;
	static const TransformFeedbackType FloatVec2;
	static const TransformFeedbackType FloatVec3;
	static const TransformFeedbackType FloatVec4;
	static const TransformFeedbackType IntVec2;
	static const TransformFeedbackType IntVec3;
	static const TransformFeedbackType IntVec4;
	static const TransformFeedbackType FloatMat2;
	static const TransformFeedbackType FloatMat3;
	static const TransformFeedbackType FloatMat4;
	static const TransformFeedbackType FloatMat2x3;
	static const TransformFeedbackType FloatMat2x4;
	static const TransformFeedbackType FloatMat3x2;
	static const TransformFeedbackType FloatMat3x4;
	static const TransformFeedbackType FloatMat4x2;
	static const TransformFeedbackType FloatMat4x3;
	static const TransformFeedbackType UnsignedIntVec2;
	static const TransformFeedbackType UnsignedIntVec3;
	static const TransformFeedbackType UnsignedIntVec4;
	static const TransformFeedbackType DoubleMat2;
	static const TransformFeedbackType DoubleMat3;
	static const TransformFeedbackType DoubleMat4;
	static const TransformFeedbackType DoubleMat2x3;
	static const TransformFeedbackType DoubleMat2x4;
	static const TransformFeedbackType DoubleMat3x2;
	static const TransformFeedbackType DoubleMat3x4;
	static const TransformFeedbackType DoubleMat4x2;
	static const TransformFeedbackType DoubleMat4x3;
	static const TransformFeedbackType DoubleVec2;
	static const TransformFeedbackType DoubleVec3;
	static const TransformFeedbackType DoubleVec4;
OPENGL_ENUM_END

OPENGL_ENUM_START(UseProgramStageMask)
	static const UseProgramStageMask VertexShaderBit;
	static const UseProgramStageMask VertexShaderBitExt;
	static const UseProgramStageMask FragmentShaderBit;
	static const UseProgramStageMask FragmentShaderBitExt;
	static const UseProgramStageMask GeometryShaderBit;
	static const UseProgramStageMask GeometryShaderBitExt;
	static const UseProgramStageMask TessControlShaderBit;
	static const UseProgramStageMask TessControlShaderBitExt;
	static const UseProgramStageMask TessEvaluationShaderBit;
	static const UseProgramStageMask TessEvaluationShaderBitExt;
	static const UseProgramStageMask ComputeShaderBit;
	static const UseProgramStageMask AllShaderBits;
	static const UseProgramStageMask AllShaderBitsExt;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version10)
OPENGL_ENUM_END

OPENGL_ENUM_START(Version11)
	static const Version11 False;
	static const Version11 NoError;
	static const Version11 None;
	static const Version11 Zero;
	static const Version11 Points;
	static const Version11 ClientPixelStoreBit;
	static const Version11 CurrentBit;
	static const Version11 ClientVertexArrayBit;
	static const Version11 PointBit;
	static const Version11 LineBit;
	static const Version11 PolygonBit;
	static const Version11 PolygonStippleBit;
	static const Version11 PixelModeBit;
	static const Version11 LightingBit;
	static const Version11 FogBit;
	static const Version11 DepthBufferBit;
	static const Version11 AccumBufferBit;
	static const Version11 StencilBufferBit;
	static const Version11 ViewportBit;
	static const Version11 TransformBit;
	static const Version11 EnableBit;
	static const Version11 ColorBufferBit;
	static const Version11 HintBit;
	static const Version11 Lines;
	static const Version11 EvalBit;
	static const Version11 LineLoop;
	static const Version11 ListBit;
	static const Version11 LineStrip;
	static const Version11 Triangles;
	static const Version11 TextureBit;
	static const Version11 TriangleStrip;
	static const Version11 TriangleFan;
	static const Version11 Quads;
	static const Version11 QuadStrip;
	static const Version11 ScissorBit;
	static const Version11 Polygon;
	static const Version11 Accum;
	static const Version11 Load;
	static const Version11 Return;
	static const Version11 Mult;
	static const Version11 Add;
	static const Version11 Never;
	static const Version11 Less;
	static const Version11 Equal;
	static const Version11 Lequal;
	static const Version11 Greater;
	static const Version11 Notequal;
	static const Version11 Gequal;
	static const Version11 Always;
	static const Version11 SrcColor;
	static const Version11 OneMinusSrcColor;
	static const Version11 SrcAlpha;
	static const Version11 OneMinusSrcAlpha;
	static const Version11 DstAlpha;
	static const Version11 OneMinusDstAlpha;
	static const Version11 DstColor;
	static const Version11 OneMinusDstColor;
	static const Version11 SrcAlphaSaturate;
	static const Version11 FrontLeft;
	static const Version11 FrontRight;
	static const Version11 BackLeft;
	static const Version11 BackRight;
	static const Version11 Front;
	static const Version11 Back;
	static const Version11 Left;
	static const Version11 Right;
	static const Version11 FrontAndBack;
	static const Version11 Aux0;
	static const Version11 Aux1;
	static const Version11 Aux2;
	static const Version11 Aux3;
	static const Version11 InvalidEnum;
	static const Version11 InvalidValue;
	static const Version11 InvalidOperation;
	static const Version11 StackOverflow;
	static const Version11 StackUnderflow;
	static const Version11 OutOfMemory;
	static const Version11 Gl2D;
	static const Version11 Gl3D;
	static const Version11 Gl3DColor;
	static const Version11 Gl3DColorTexture;
	static const Version11 Gl4DColorTexture;
	static const Version11 PassThroughToken;
	static const Version11 PointToken;
	static const Version11 LineToken;
	static const Version11 PolygonToken;
	static const Version11 BitmapToken;
	static const Version11 DrawPixelToken;
	static const Version11 CopyPixelToken;
	static const Version11 LineResetToken;
	static const Version11 Exp;
	static const Version11 Exp2;
	static const Version11 Cw;
	static const Version11 Ccw;
	static const Version11 Coeff;
	static const Version11 Order;
	static const Version11 Domain;
	static const Version11 CurrentColor;
	static const Version11 CurrentIndex;
	static const Version11 CurrentNormal;
	static const Version11 CurrentTextureCoords;
	static const Version11 CurrentRasterColor;
	static const Version11 CurrentRasterIndex;
	static const Version11 CurrentRasterTextureCoords;
	static const Version11 CurrentRasterPosition;
	static const Version11 CurrentRasterPositionValid;
	static const Version11 CurrentRasterDistance;
	static const Version11 PointSmooth;
	static const Version11 PointSize;
	static const Version11 PointSizeRange;
	static const Version11 PointSizeGranularity;
	static const Version11 LineSmooth;
	static const Version11 LineWidth;
	static const Version11 LineWidthRange;
	static const Version11 LineWidthGranularity;
	static const Version11 LineStipple;
	static const Version11 LineStipplePattern;
	static const Version11 LineStippleRepeat;
	static const Version11 ListMode;
	static const Version11 MaxListNesting;
	static const Version11 ListBase;
	static const Version11 ListIndex;
	static const Version11 PolygonMode;
	static const Version11 PolygonSmooth;
	static const Version11 PolygonStipple;
	static const Version11 EdgeFlag;
	static const Version11 CullFace;
	static const Version11 CullFaceMode;
	static const Version11 FrontFace;
	static const Version11 Lighting;
	static const Version11 LightModelLocalViewer;
	static const Version11 LightModelTwoSide;
	static const Version11 LightModelAmbient;
	static const Version11 ShadeModel;
	static const Version11 ColorMaterialFace;
	static const Version11 ColorMaterialParameter;
	static const Version11 ColorMaterial;
	static const Version11 Fog;
	static const Version11 FogIndex;
	static const Version11 FogDensity;
	static const Version11 FogStart;
	static const Version11 FogEnd;
	static const Version11 FogMode;
	static const Version11 FogColor;
	static const Version11 DepthRange;
	static const Version11 DepthTest;
	static const Version11 DepthWritemask;
	static const Version11 DepthClearValue;
	static const Version11 DepthFunc;
	static const Version11 AccumClearValue;
	static const Version11 StencilTest;
	static const Version11 StencilClearValue;
	static const Version11 StencilFunc;
	static const Version11 StencilValueMask;
	static const Version11 StencilFail;
	static const Version11 StencilPassDepthFail;
	static const Version11 StencilPassDepthPass;
	static const Version11 StencilRef;
	static const Version11 StencilWritemask;
	static const Version11 MatrixMode;
	static const Version11 Normalize;
	static const Version11 Viewport;
	static const Version11 ModelviewStackDepth;
	static const Version11 ProjectionStackDepth;
	static const Version11 TextureStackDepth;
	static const Version11 ModelviewMatrix;
	static const Version11 ProjectionMatrix;
	static const Version11 TextureMatrix;
	static const Version11 AttribStackDepth;
	static const Version11 ClientAttribStackDepth;
	static const Version11 AlphaTest;
	static const Version11 AlphaTestFunc;
	static const Version11 AlphaTestRef;
	static const Version11 Dither;
	static const Version11 BlendDst;
	static const Version11 BlendSrc;
	static const Version11 Blend;
	static const Version11 LogicOpMode;
	static const Version11 IndexLogicOp;
	static const Version11 LogicOp;
	static const Version11 ColorLogicOp;
	static const Version11 AuxBuffers;
	static const Version11 DrawBuffer;
	static const Version11 ReadBuffer;
	static const Version11 ScissorBox;
	static const Version11 ScissorTest;
	static const Version11 IndexClearValue;
	static const Version11 IndexWritemask;
	static const Version11 ColorClearValue;
	static const Version11 ColorWritemask;
	static const Version11 IndexMode;
	static const Version11 RgbaMode;
	static const Version11 Doublebuffer;
	static const Version11 Stereo;
	static const Version11 RenderMode;
	static const Version11 PerspectiveCorrectionHint;
	static const Version11 PointSmoothHint;
	static const Version11 LineSmoothHint;
	static const Version11 PolygonSmoothHint;
	static const Version11 FogHint;
	static const Version11 TextureGenS;
	static const Version11 TextureGenT;
	static const Version11 TextureGenR;
	static const Version11 TextureGenQ;
	static const Version11 PixelMapIToI;
	static const Version11 PixelMapSToS;
	static const Version11 PixelMapIToR;
	static const Version11 PixelMapIToG;
	static const Version11 PixelMapIToB;
	static const Version11 PixelMapIToA;
	static const Version11 PixelMapRToR;
	static const Version11 PixelMapGToG;
	static const Version11 PixelMapBToB;
	static const Version11 PixelMapAToA;
	static const Version11 PixelMapIToISize;
	static const Version11 PixelMapSToSSize;
	static const Version11 PixelMapIToRSize;
	static const Version11 PixelMapIToGSize;
	static const Version11 PixelMapIToBSize;
	static const Version11 PixelMapIToASize;
	static const Version11 PixelMapRToRSize;
	static const Version11 PixelMapGToGSize;
	static const Version11 PixelMapBToBSize;
	static const Version11 PixelMapAToASize;
	static const Version11 UnpackSwapBytes;
	static const Version11 UnpackLsbFirst;
	static const Version11 UnpackRowLength;
	static const Version11 UnpackSkipRows;
	static const Version11 UnpackSkipPixels;
	static const Version11 UnpackAlignment;
	static const Version11 PackSwapBytes;
	static const Version11 PackLsbFirst;
	static const Version11 PackRowLength;
	static const Version11 PackSkipRows;
	static const Version11 PackSkipPixels;
	static const Version11 PackAlignment;
	static const Version11 MapColor;
	static const Version11 MapStencil;
	static const Version11 IndexShift;
	static const Version11 IndexOffset;
	static const Version11 RedScale;
	static const Version11 RedBias;
	static const Version11 ZoomX;
	static const Version11 ZoomY;
	static const Version11 GreenScale;
	static const Version11 GreenBias;
	static const Version11 BlueScale;
	static const Version11 BlueBias;
	static const Version11 AlphaScale;
	static const Version11 AlphaBias;
	static const Version11 DepthScale;
	static const Version11 DepthBias;
	static const Version11 MaxEvalOrder;
	static const Version11 MaxLights;
	static const Version11 MaxClipPlanes;
	static const Version11 MaxTextureSize;
	static const Version11 MaxPixelMapTable;
	static const Version11 MaxAttribStackDepth;
	static const Version11 MaxModelviewStackDepth;
	static const Version11 MaxNameStackDepth;
	static const Version11 MaxProjectionStackDepth;
	static const Version11 MaxTextureStackDepth;
	static const Version11 MaxViewportDims;
	static const Version11 MaxClientAttribStackDepth;
	static const Version11 SubpixelBits;
	static const Version11 IndexBits;
	static const Version11 RedBits;
	static const Version11 GreenBits;
	static const Version11 BlueBits;
	static const Version11 AlphaBits;
	static const Version11 DepthBits;
	static const Version11 StencilBits;
	static const Version11 AccumRedBits;
	static const Version11 AccumGreenBits;
	static const Version11 AccumBlueBits;
	static const Version11 AccumAlphaBits;
	static const Version11 NameStackDepth;
	static const Version11 AutoNormal;
	static const Version11 Map1Color4;
	static const Version11 Map1Index;
	static const Version11 Map1Normal;
	static const Version11 Map1TextureCoord1;
	static const Version11 Map1TextureCoord2;
	static const Version11 Map1TextureCoord3;
	static const Version11 Map1TextureCoord4;
	static const Version11 Map1Vertex3;
	static const Version11 Map1Vertex4;
	static const Version11 Map2Color4;
	static const Version11 Map2Index;
	static const Version11 Map2Normal;
	static const Version11 Map2TextureCoord1;
	static const Version11 Map2TextureCoord2;
	static const Version11 Map2TextureCoord3;
	static const Version11 Map2TextureCoord4;
	static const Version11 Map2Vertex3;
	static const Version11 Map2Vertex4;
	static const Version11 Map1GridDomain;
	static const Version11 Map1GridSegments;
	static const Version11 Map2GridDomain;
	static const Version11 Map2GridSegments;
	static const Version11 Texture1D;
	static const Version11 Texture2D;
	static const Version11 FeedbackBufferPointer;
	static const Version11 FeedbackBufferSize;
	static const Version11 FeedbackBufferType;
	static const Version11 SelectionBufferPointer;
	static const Version11 SelectionBufferSize;
	static const Version11 TextureWidth;
	static const Version11 TextureHeight;
	static const Version11 TextureComponents;
	static const Version11 TextureInternalFormat;
	static const Version11 TextureBorderColor;
	static const Version11 TextureBorder;
	static const Version11 DontCare;
	static const Version11 Fastest;
	static const Version11 Nicest;
	static const Version11 Ambient;
	static const Version11 Diffuse;
	static const Version11 Specular;
	static const Version11 Position;
	static const Version11 SpotDirection;
	static const Version11 SpotExponent;
	static const Version11 SpotCutoff;
	static const Version11 ConstantAttenuation;
	static const Version11 LinearAttenuation;
	static const Version11 QuadraticAttenuation;
	static const Version11 Compile;
	static const Version11 CompileAndExecute;
	static const Version11 Byte;
	static const Version11 UnsignedByte;
	static const Version11 Short;
	static const Version11 UnsignedShort;
	static const Version11 Int;
	static const Version11 UnsignedInt;
	static const Version11 Float;
	static const Version11 Gl2Bytes;
	static const Version11 Gl3Bytes;
	static const Version11 Gl4Bytes;
	static const Version11 Double;
	static const Version11 Clear;
	static const Version11 And;
	static const Version11 AndReverse;
	static const Version11 Copy;
	static const Version11 AndInverted;
	static const Version11 Noop;
	static const Version11 Xor;
	static const Version11 Or;
	static const Version11 Nor;
	static const Version11 Equiv;
	static const Version11 Invert;
	static const Version11 OrReverse;
	static const Version11 CopyInverted;
	static const Version11 OrInverted;
	static const Version11 Nand;
	static const Version11 Set;
	static const Version11 Emission;
	static const Version11 Shininess;
	static const Version11 AmbientAndDiffuse;
	static const Version11 ColorIndexes;
	static const Version11 Modelview;
	static const Version11 Projection;
	static const Version11 Texture;
	static const Version11 Color;
	static const Version11 Depth;
	static const Version11 Stencil;
	static const Version11 ColorIndex;
	static const Version11 StencilIndex;
	static const Version11 DepthComponent;
	static const Version11 Red;
	static const Version11 Green;
	static const Version11 Blue;
	static const Version11 Alpha;
	static const Version11 Rgb;
	static const Version11 Rgba;
	static const Version11 Luminance;
	static const Version11 LuminanceAlpha;
	static const Version11 Bitmap;
	static const Version11 Point;
	static const Version11 Line;
	static const Version11 Fill;
	static const Version11 Render;
	static const Version11 Feedback;
	static const Version11 Select;
	static const Version11 Flat;
	static const Version11 Smooth;
	static const Version11 Keep;
	static const Version11 Replace;
	static const Version11 Incr;
	static const Version11 Decr;
	static const Version11 Vendor;
	static const Version11 Renderer;
	static const Version11 Version;
	static const Version11 Extensions;
	static const Version11 S;
	static const Version11 T;
	static const Version11 R;
	static const Version11 Q;
	static const Version11 Modulate;
	static const Version11 Decal;
	static const Version11 TextureEnvMode;
	static const Version11 TextureEnvColor;
	static const Version11 TextureEnv;
	static const Version11 EyeLinear;
	static const Version11 ObjectLinear;
	static const Version11 SphereMap;
	static const Version11 TextureGenMode;
	static const Version11 ObjectPlane;
	static const Version11 EyePlane;
	static const Version11 Nearest;
	static const Version11 Linear;
	static const Version11 NearestMipmapNearest;
	static const Version11 LinearMipmapNearest;
	static const Version11 NearestMipmapLinear;
	static const Version11 LinearMipmapLinear;
	static const Version11 TextureMagFilter;
	static const Version11 TextureMinFilter;
	static const Version11 TextureWrapS;
	static const Version11 TextureWrapT;
	static const Version11 Clamp;
	static const Version11 Repeat;
	static const Version11 PolygonOffsetUnits;
	static const Version11 PolygonOffsetPoint;
	static const Version11 PolygonOffsetLine;
	static const Version11 R3G3B2;
	static const Version11 V2f;
	static const Version11 V3f;
	static const Version11 C4ubV2f;
	static const Version11 C4ubV3f;
	static const Version11 C3fV3f;
	static const Version11 N3fV3f;
	static const Version11 C4fN3fV3f;
	static const Version11 T2fV3f;
	static const Version11 T4fV4f;
	static const Version11 T2fC4ubV3f;
	static const Version11 T2fC3fV3f;
	static const Version11 T2fN3fV3f;
	static const Version11 T2fC4fN3fV3f;
	static const Version11 T4fC4fN3fV4f;
	static const Version11 ClipPlane0;
	static const Version11 ClipPlane1;
	static const Version11 ClipPlane2;
	static const Version11 ClipPlane3;
	static const Version11 ClipPlane4;
	static const Version11 ClipPlane5;
	static const Version11 Light0;
	static const Version11 Light1;
	static const Version11 Light2;
	static const Version11 Light3;
	static const Version11 Light4;
	static const Version11 Light5;
	static const Version11 Light6;
	static const Version11 Light7;
	static const Version11 PolygonOffsetFill;
	static const Version11 PolygonOffsetFactor;
	static const Version11 Alpha4;
	static const Version11 Alpha8;
	static const Version11 Alpha12;
	static const Version11 Alpha16;
	static const Version11 Luminance4;
	static const Version11 Luminance8;
	static const Version11 Luminance12;
	static const Version11 Luminance16;
	static const Version11 Luminance4Alpha4;
	static const Version11 Luminance6Alpha2;
	static const Version11 Luminance8Alpha8;
	static const Version11 Luminance12Alpha4;
	static const Version11 Luminance12Alpha12;
	static const Version11 Luminance16Alpha16;
	static const Version11 Intensity;
	static const Version11 Intensity4;
	static const Version11 Intensity8;
	static const Version11 Intensity12;
	static const Version11 Intensity16;
	static const Version11 Rgb4;
	static const Version11 Rgb5;
	static const Version11 Rgb8;
	static const Version11 Rgb10;
	static const Version11 Rgb12;
	static const Version11 Rgb16;
	static const Version11 Rgba2;
	static const Version11 Rgba4;
	static const Version11 Rgb5A1;
	static const Version11 Rgba8;
	static const Version11 Rgb10A2;
	static const Version11 Rgba12;
	static const Version11 Rgba16;
	static const Version11 TextureRedSize;
	static const Version11 TextureGreenSize;
	static const Version11 TextureBlueSize;
	static const Version11 TextureAlphaSize;
	static const Version11 TextureLuminanceSize;
	static const Version11 TextureIntensitySize;
	static const Version11 ProxyTexture1D;
	static const Version11 ProxyTexture2D;
	static const Version11 TexturePriority;
	static const Version11 TextureResident;
	static const Version11 TextureBinding1D;
	static const Version11 TextureBinding2D;
	static const Version11 VertexArray;
	static const Version11 NormalArray;
	static const Version11 ColorArray;
	static const Version11 IndexArray;
	static const Version11 TextureCoordArray;
	static const Version11 EdgeFlagArray;
	static const Version11 VertexArraySize;
	static const Version11 VertexArrayType;
	static const Version11 VertexArrayStride;
	static const Version11 NormalArrayType;
	static const Version11 NormalArrayStride;
	static const Version11 ColorArraySize;
	static const Version11 ColorArrayType;
	static const Version11 ColorArrayStride;
	static const Version11 IndexArrayType;
	static const Version11 IndexArrayStride;
	static const Version11 TextureCoordArraySize;
	static const Version11 TextureCoordArrayType;
	static const Version11 TextureCoordArrayStride;
	static const Version11 EdgeFlagArrayStride;
	static const Version11 VertexArrayPointer;
	static const Version11 NormalArrayPointer;
	static const Version11 ColorArrayPointer;
	static const Version11 IndexArrayPointer;
	static const Version11 TextureCoordArrayPointer;
	static const Version11 EdgeFlagArrayPointer;
	static const Version11 AllAttribBits;
	static const Version11 ClientAllAttribBits;
	static const Version11 One;
	static const Version11 True;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version12)
	static const Version12 SmoothPointSizeRange;
	static const Version12 SmoothPointSizeGranularity;
	static const Version12 SmoothLineWidthRange;
	static const Version12 SmoothLineWidthGranularity;
	static const Version12 UnsignedByte332;
	static const Version12 UnsignedShort4444;
	static const Version12 UnsignedShort5551;
	static const Version12 UnsignedInt8888;
	static const Version12 UnsignedInt1010102;
	static const Version12 RescaleNormal;
	static const Version12 TextureBinding3D;
	static const Version12 PackSkipImages;
	static const Version12 PackImageHeight;
	static const Version12 UnpackSkipImages;
	static const Version12 UnpackImageHeight;
	static const Version12 Texture3D;
	static const Version12 ProxyTexture3D;
	static const Version12 TextureDepth;
	static const Version12 TextureWrapR;
	static const Version12 Max3DTextureSize;
	static const Version12 Bgr;
	static const Version12 Bgra;
	static const Version12 MaxElementsVertices;
	static const Version12 MaxElementsIndices;
	static const Version12 ClampToEdge;
	static const Version12 TextureMinLod;
	static const Version12 TextureMaxLod;
	static const Version12 TextureBaseLevel;
	static const Version12 TextureMaxLevel;
	static const Version12 LightModelColorControl;
	static const Version12 SingleColor;
	static const Version12 SeparateSpecularColor;
	static const Version12 UnsignedByte233Rev;
	static const Version12 UnsignedShort565;
	static const Version12 UnsignedShort565Rev;
	static const Version12 UnsignedShort4444Rev;
	static const Version12 UnsignedShort1555Rev;
	static const Version12 UnsignedInt8888Rev;
	static const Version12 UnsignedInt2101010Rev;
	static const Version12 AliasedPointSizeRange;
	static const Version12 AliasedLineWidthRange;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version13)
	static const Version13 MultisampleBit;
	static const Version13 Multisample;
	static const Version13 SampleAlphaToCoverage;
	static const Version13 SampleAlphaToOne;
	static const Version13 SampleCoverage;
	static const Version13 SampleBuffers;
	static const Version13 Samples;
	static const Version13 SampleCoverageValue;
	static const Version13 SampleCoverageInvert;
	static const Version13 ClampToBorder;
	static const Version13 Texture0;
	static const Version13 Texture1;
	static const Version13 Texture2;
	static const Version13 Texture3;
	static const Version13 Texture4;
	static const Version13 Texture5;
	static const Version13 Texture6;
	static const Version13 Texture7;
	static const Version13 Texture8;
	static const Version13 Texture9;
	static const Version13 Texture10;
	static const Version13 Texture11;
	static const Version13 Texture12;
	static const Version13 Texture13;
	static const Version13 Texture14;
	static const Version13 Texture15;
	static const Version13 Texture16;
	static const Version13 Texture17;
	static const Version13 Texture18;
	static const Version13 Texture19;
	static const Version13 Texture20;
	static const Version13 Texture21;
	static const Version13 Texture22;
	static const Version13 Texture23;
	static const Version13 Texture24;
	static const Version13 Texture25;
	static const Version13 Texture26;
	static const Version13 Texture27;
	static const Version13 Texture28;
	static const Version13 Texture29;
	static const Version13 Texture30;
	static const Version13 Texture31;
	static const Version13 ActiveTexture;
	static const Version13 ClientActiveTexture;
	static const Version13 MaxTextureUnits;
	static const Version13 TransposeModelviewMatrix;
	static const Version13 TransposeProjectionMatrix;
	static const Version13 TransposeTextureMatrix;
	static const Version13 TransposeColorMatrix;
	static const Version13 Subtract;
	static const Version13 CompressedAlpha;
	static const Version13 CompressedLuminance;
	static const Version13 CompressedLuminanceAlpha;
	static const Version13 CompressedIntensity;
	static const Version13 CompressedRgb;
	static const Version13 CompressedRgba;
	static const Version13 TextureCompressionHint;
	static const Version13 NormalMap;
	static const Version13 ReflectionMap;
	static const Version13 TextureCubeMap;
	static const Version13 TextureBindingCubeMap;
	static const Version13 TextureCubeMapPositiveX;
	static const Version13 TextureCubeMapNegativeX;
	static const Version13 TextureCubeMapPositiveY;
	static const Version13 TextureCubeMapNegativeY;
	static const Version13 TextureCubeMapPositiveZ;
	static const Version13 TextureCubeMapNegativeZ;
	static const Version13 ProxyTextureCubeMap;
	static const Version13 MaxCubeMapTextureSize;
	static const Version13 Combine;
	static const Version13 CombineRgb;
	static const Version13 CombineAlpha;
	static const Version13 RgbScale;
	static const Version13 AddSigned;
	static const Version13 Interpolate;
	static const Version13 Constant;
	static const Version13 PrimaryColor;
	static const Version13 Previous;
	static const Version13 Source0Rgb;
	static const Version13 Source1Rgb;
	static const Version13 Source2Rgb;
	static const Version13 Source0Alpha;
	static const Version13 Source1Alpha;
	static const Version13 Source2Alpha;
	static const Version13 Operand0Rgb;
	static const Version13 Operand1Rgb;
	static const Version13 Operand2Rgb;
	static const Version13 Operand0Alpha;
	static const Version13 Operand1Alpha;
	static const Version13 Operand2Alpha;
	static const Version13 TextureCompressedImageSize;
	static const Version13 TextureCompressed;
	static const Version13 NumCompressedTextureFormats;
	static const Version13 CompressedTextureFormats;
	static const Version13 Dot3Rgb;
	static const Version13 Dot3Rgba;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version14)
	static const Version14 ConstantColor;
	static const Version14 OneMinusConstantColor;
	static const Version14 ConstantAlpha;
	static const Version14 OneMinusConstantAlpha;
	static const Version14 FuncAdd;
	static const Version14 Min;
	static const Version14 Max;
	static const Version14 FuncSubtract;
	static const Version14 FuncReverseSubtract;
	static const Version14 BlendDstRgb;
	static const Version14 BlendSrcRgb;
	static const Version14 BlendDstAlpha;
	static const Version14 BlendSrcAlpha;
	static const Version14 PointSizeMin;
	static const Version14 PointSizeMax;
	static const Version14 PointFadeThresholdSize;
	static const Version14 PointDistanceAttenuation;
	static const Version14 GenerateMipmap;
	static const Version14 GenerateMipmapHint;
	static const Version14 DepthComponent16;
	static const Version14 DepthComponent24;
	static const Version14 DepthComponent32;
	static const Version14 MirroredRepeat;
	static const Version14 FogCoordinateSource;
	static const Version14 FogCoordinate;
	static const Version14 FragmentDepth;
	static const Version14 CurrentFogCoordinate;
	static const Version14 FogCoordinateArrayType;
	static const Version14 FogCoordinateArrayStride;
	static const Version14 FogCoordinateArrayPointer;
	static const Version14 FogCoordinateArray;
	static const Version14 ColorSum;
	static const Version14 CurrentSecondaryColor;
	static const Version14 SecondaryColorArraySize;
	static const Version14 SecondaryColorArrayType;
	static const Version14 SecondaryColorArrayStride;
	static const Version14 SecondaryColorArrayPointer;
	static const Version14 SecondaryColorArray;
	static const Version14 MaxTextureLodBias;
	static const Version14 TextureFilterControl;
	static const Version14 TextureLodBias;
	static const Version14 IncrWrap;
	static const Version14 DecrWrap;
	static const Version14 TextureDepthSize;
	static const Version14 DepthTextureMode;
	static const Version14 TextureCompareMode;
	static const Version14 TextureCompareFunc;
	static const Version14 CompareRToTexture;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version15)
	static const Version15 FogCoordSrc;
	static const Version15 FogCoord;
	static const Version15 CurrentFogCoord;
	static const Version15 FogCoordArrayType;
	static const Version15 FogCoordArrayStride;
	static const Version15 FogCoordArrayPointer;
	static const Version15 FogCoordArray;
	static const Version15 Src0Rgb;
	static const Version15 Src1Rgb;
	static const Version15 Src2Rgb;
	static const Version15 Src0Alpha;
	static const Version15 Src1Alpha;
	static const Version15 Src2Alpha;
	static const Version15 BufferSize;
	static const Version15 BufferUsage;
	static const Version15 QueryCounterBits;
	static const Version15 CurrentQuery;
	static const Version15 QueryResult;
	static const Version15 QueryResultAvailable;
	static const Version15 ArrayBuffer;
	static const Version15 ElementArrayBuffer;
	static const Version15 ArrayBufferBinding;
	static const Version15 ElementArrayBufferBinding;
	static const Version15 VertexArrayBufferBinding;
	static const Version15 NormalArrayBufferBinding;
	static const Version15 ColorArrayBufferBinding;
	static const Version15 IndexArrayBufferBinding;
	static const Version15 TextureCoordArrayBufferBinding;
	static const Version15 EdgeFlagArrayBufferBinding;
	static const Version15 SecondaryColorArrayBufferBinding;
	static const Version15 FogCoordArrayBufferBinding;
	static const Version15 FogCoordinateArrayBufferBinding;
	static const Version15 WeightArrayBufferBinding;
	static const Version15 VertexAttribArrayBufferBinding;
	static const Version15 ReadOnly;
	static const Version15 WriteOnly;
	static const Version15 ReadWrite;
	static const Version15 BufferAccess;
	static const Version15 BufferMapped;
	static const Version15 BufferMapPointer;
	static const Version15 StreamDraw;
	static const Version15 StreamRead;
	static const Version15 StreamCopy;
	static const Version15 StaticDraw;
	static const Version15 StaticRead;
	static const Version15 StaticCopy;
	static const Version15 DynamicDraw;
	static const Version15 DynamicRead;
	static const Version15 DynamicCopy;
	static const Version15 SamplesPassed;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version20)
	static const Version20 BlendEquationRgb;
	static const Version20 VertexAttribArrayEnabled;
	static const Version20 VertexAttribArraySize;
	static const Version20 VertexAttribArrayStride;
	static const Version20 VertexAttribArrayType;
	static const Version20 CurrentVertexAttrib;
	static const Version20 VertexProgramPointSize;
	static const Version20 VertexProgramTwoSide;
	static const Version20 VertexAttribArrayPointer;
	static const Version20 StencilBackFunc;
	static const Version20 StencilBackFail;
	static const Version20 StencilBackPassDepthFail;
	static const Version20 StencilBackPassDepthPass;
	static const Version20 MaxDrawBuffers;
	static const Version20 DrawBuffer0;
	static const Version20 DrawBuffer1;
	static const Version20 DrawBuffer2;
	static const Version20 DrawBuffer3;
	static const Version20 DrawBuffer4;
	static const Version20 DrawBuffer5;
	static const Version20 DrawBuffer6;
	static const Version20 DrawBuffer7;
	static const Version20 DrawBuffer8;
	static const Version20 DrawBuffer9;
	static const Version20 DrawBuffer10;
	static const Version20 DrawBuffer11;
	static const Version20 DrawBuffer12;
	static const Version20 DrawBuffer13;
	static const Version20 DrawBuffer14;
	static const Version20 DrawBuffer15;
	static const Version20 BlendEquationAlpha;
	static const Version20 PointSprite;
	static const Version20 CoordReplace;
	static const Version20 MaxVertexAttribs;
	static const Version20 VertexAttribArrayNormalized;
	static const Version20 MaxTextureCoords;
	static const Version20 MaxTextureImageUnits;
	static const Version20 FragmentShader;
	static const Version20 VertexShader;
	static const Version20 MaxFragmentUniformComponents;
	static const Version20 MaxVertexUniformComponents;
	static const Version20 MaxVaryingFloats;
	static const Version20 MaxVertexTextureImageUnits;
	static const Version20 MaxCombinedTextureImageUnits;
	static const Version20 ShaderType;
	static const Version20 FloatVec2;
	static const Version20 FloatVec3;
	static const Version20 FloatVec4;
	static const Version20 IntVec2;
	static const Version20 IntVec3;
	static const Version20 IntVec4;
	static const Version20 Bool;
	static const Version20 BoolVec2;
	static const Version20 BoolVec3;
	static const Version20 BoolVec4;
	static const Version20 FloatMat2;
	static const Version20 FloatMat3;
	static const Version20 FloatMat4;
	static const Version20 Sampler1D;
	static const Version20 Sampler2D;
	static const Version20 Sampler3D;
	static const Version20 SamplerCube;
	static const Version20 Sampler1DShadow;
	static const Version20 Sampler2DShadow;
	static const Version20 DeleteStatus;
	static const Version20 CompileStatus;
	static const Version20 LinkStatus;
	static const Version20 ValidateStatus;
	static const Version20 InfoLogLength;
	static const Version20 AttachedShaders;
	static const Version20 ActiveUniforms;
	static const Version20 ActiveUniformMaxLength;
	static const Version20 ShaderSourceLength;
	static const Version20 ActiveAttributes;
	static const Version20 ActiveAttributeMaxLength;
	static const Version20 FragmentShaderDerivativeHint;
	static const Version20 ShadingLanguageVersion;
	static const Version20 CurrentProgram;
	static const Version20 PointSpriteCoordOrigin;
	static const Version20 LowerLeft;
	static const Version20 UpperLeft;
	static const Version20 StencilBackRef;
	static const Version20 StencilBackValueMask;
	static const Version20 StencilBackWritemask;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version21)
	static const Version21 CurrentRasterSecondaryColor;
	static const Version21 PixelPackBuffer;
	static const Version21 PixelUnpackBuffer;
	static const Version21 PixelPackBufferBinding;
	static const Version21 PixelUnpackBufferBinding;
	static const Version21 FloatMat2x3;
	static const Version21 FloatMat2x4;
	static const Version21 FloatMat3x2;
	static const Version21 FloatMat3x4;
	static const Version21 FloatMat4x2;
	static const Version21 FloatMat4x3;
	static const Version21 Srgb;
	static const Version21 Srgb8;
	static const Version21 SrgbAlpha;
	static const Version21 Srgb8Alpha8;
	static const Version21 SluminanceAlpha;
	static const Version21 Sluminance8Alpha8;
	static const Version21 Sluminance;
	static const Version21 Sluminance8;
	static const Version21 CompressedSrgb;
	static const Version21 CompressedSrgbAlpha;
	static const Version21 CompressedSluminance;
	static const Version21 CompressedSluminanceAlpha;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version30)
	static const Version30 ContextFlagForwardCompatibleBit;
	static const Version30 MapReadBit;
	static const Version30 MapWriteBit;
	static const Version30 MapInvalidateRangeBit;
	static const Version30 MapInvalidateBufferBit;
	static const Version30 MapFlushExplicitBit;
	static const Version30 MapUnsynchronizedBit;
	static const Version30 InvalidFramebufferOperation;
	static const Version30 MaxClipDistances;
	static const Version30 HalfFloat;
	static const Version30 ClipDistance0;
	static const Version30 ClipDistance1;
	static const Version30 ClipDistance2;
	static const Version30 ClipDistance3;
	static const Version30 ClipDistance4;
	static const Version30 ClipDistance5;
	static const Version30 ClipDistance6;
	static const Version30 ClipDistance7;
	static const Version30 FramebufferAttachmentColorEncoding;
	static const Version30 FramebufferAttachmentComponentType;
	static const Version30 FramebufferAttachmentRedSize;
	static const Version30 FramebufferAttachmentGreenSize;
	static const Version30 FramebufferAttachmentBlueSize;
	static const Version30 FramebufferAttachmentAlphaSize;
	static const Version30 FramebufferAttachmentDepthSize;
	static const Version30 FramebufferAttachmentStencilSize;
	static const Version30 FramebufferDefault;
	static const Version30 FramebufferUndefined;
	static const Version30 DepthStencilAttachment;
	static const Version30 MajorVersion;
	static const Version30 MinorVersion;
	static const Version30 NumExtensions;
	static const Version30 ContextFlags;
	static const Version30 Index;
	static const Version30 CompressedRed;
	static const Version30 CompressedRg;
	static const Version30 Rg;
	static const Version30 RgInteger;
	static const Version30 R8;
	static const Version30 R16;
	static const Version30 Rg8;
	static const Version30 Rg16;
	static const Version30 R16f;
	static const Version30 R32f;
	static const Version30 Rg16f;
	static const Version30 Rg32f;
	static const Version30 R8i;
	static const Version30 R8ui;
	static const Version30 R16i;
	static const Version30 R16ui;
	static const Version30 R32i;
	static const Version30 R32ui;
	static const Version30 Rg8i;
	static const Version30 Rg8ui;
	static const Version30 Rg16i;
	static const Version30 Rg16ui;
	static const Version30 Rg32i;
	static const Version30 Rg32ui;
	static const Version30 MaxRenderbufferSize;
	static const Version30 DepthStencil;
	static const Version30 UnsignedInt248;
	static const Version30 VertexArrayBinding;
	static const Version30 Rgba32f;
	static const Version30 Rgb32f;
	static const Version30 Rgba16f;
	static const Version30 Rgb16f;
	static const Version30 CompareRefToTexture;
	static const Version30 Depth24Stencil8;
	static const Version30 TextureStencilSize;
	static const Version30 VertexAttribArrayInteger;
	static const Version30 MaxArrayTextureLayers;
	static const Version30 MinProgramTexelOffset;
	static const Version30 MaxProgramTexelOffset;
	static const Version30 ClampVertexColor;
	static const Version30 ClampFragmentColor;
	static const Version30 ClampReadColor;
	static const Version30 FixedOnly;
	static const Version30 MaxVaryingComponents;
	static const Version30 TextureRedType;
	static const Version30 TextureGreenType;
	static const Version30 TextureBlueType;
	static const Version30 TextureAlphaType;
	static const Version30 TextureLuminanceType;
	static const Version30 TextureIntensityType;
	static const Version30 TextureDepthType;
	static const Version30 UnsignedNormalized;
	static const Version30 Texture1DArray;
	static const Version30 ProxyTexture1DArray;
	static const Version30 Texture2DArray;
	static const Version30 ProxyTexture2DArray;
	static const Version30 TextureBinding1DArray;
	static const Version30 TextureBinding2DArray;
	static const Version30 R11fG11fB10f;
	static const Version30 UnsignedInt10F11F11FRev;
	static const Version30 Rgb9E5;
	static const Version30 UnsignedInt5999Rev;
	static const Version30 TextureSharedSize;
	static const Version30 TransformFeedbackVaryingMaxLength;
	static const Version30 TransformFeedbackBufferMode;
	static const Version30 MaxTransformFeedbackSeparateComponents;
	static const Version30 TransformFeedbackVaryings;
	static const Version30 TransformFeedbackBufferStart;
	static const Version30 TransformFeedbackBufferSize;
	static const Version30 PrimitivesGenerated;
	static const Version30 TransformFeedbackPrimitivesWritten;
	static const Version30 RasterizerDiscard;
	static const Version30 MaxTransformFeedbackInterleavedComponents;
	static const Version30 MaxTransformFeedbackSeparateAttribs;
	static const Version30 InterleavedAttribs;
	static const Version30 SeparateAttribs;
	static const Version30 TransformFeedbackBuffer;
	static const Version30 TransformFeedbackBufferBinding;
	static const Version30 DrawFramebufferBinding;
	static const Version30 FramebufferBinding;
	static const Version30 RenderbufferBinding;
	static const Version30 ReadFramebuffer;
	static const Version30 DrawFramebuffer;
	static const Version30 ReadFramebufferBinding;
	static const Version30 RenderbufferSamples;
	static const Version30 DepthComponent32f;
	static const Version30 Depth32fStencil8;
	static const Version30 FramebufferAttachmentObjectType;
	static const Version30 FramebufferAttachmentObjectName;
	static const Version30 FramebufferAttachmentTextureLevel;
	static const Version30 FramebufferAttachmentTextureCubeMapFace;
	static const Version30 FramebufferAttachmentTextureLayer;
	static const Version30 FramebufferComplete;
	static const Version30 FramebufferIncompleteAttachment;
	static const Version30 FramebufferIncompleteMissingAttachment;
	static const Version30 FramebufferIncompleteDrawBuffer;
	static const Version30 FramebufferIncompleteReadBuffer;
	static const Version30 FramebufferUnsupported;
	static const Version30 MaxColorAttachments;
	static const Version30 ColorAttachment0;
	static const Version30 ColorAttachment1;
	static const Version30 ColorAttachment2;
	static const Version30 ColorAttachment3;
	static const Version30 ColorAttachment4;
	static const Version30 ColorAttachment5;
	static const Version30 ColorAttachment6;
	static const Version30 ColorAttachment7;
	static const Version30 ColorAttachment8;
	static const Version30 ColorAttachment9;
	static const Version30 ColorAttachment10;
	static const Version30 ColorAttachment11;
	static const Version30 ColorAttachment12;
	static const Version30 ColorAttachment13;
	static const Version30 ColorAttachment14;
	static const Version30 ColorAttachment15;
	static const Version30 DepthAttachment;
	static const Version30 StencilAttachment;
	static const Version30 Framebuffer;
	static const Version30 Renderbuffer;
	static const Version30 RenderbufferWidth;
	static const Version30 RenderbufferHeight;
	static const Version30 RenderbufferInternalFormat;
	static const Version30 StencilIndex1;
	static const Version30 StencilIndex4;
	static const Version30 StencilIndex8;
	static const Version30 StencilIndex16;
	static const Version30 RenderbufferRedSize;
	static const Version30 RenderbufferGreenSize;
	static const Version30 RenderbufferBlueSize;
	static const Version30 RenderbufferAlphaSize;
	static const Version30 RenderbufferDepthSize;
	static const Version30 RenderbufferStencilSize;
	static const Version30 FramebufferIncompleteMultisample;
	static const Version30 MaxSamples;
	static const Version30 Rgba32ui;
	static const Version30 Rgb32ui;
	static const Version30 Rgba16ui;
	static const Version30 Rgb16ui;
	static const Version30 Rgba8ui;
	static const Version30 Rgb8ui;
	static const Version30 Rgba32i;
	static const Version30 Rgb32i;
	static const Version30 Rgba16i;
	static const Version30 Rgb16i;
	static const Version30 Rgba8i;
	static const Version30 Rgb8i;
	static const Version30 RedInteger;
	static const Version30 GreenInteger;
	static const Version30 BlueInteger;
	static const Version30 AlphaInteger;
	static const Version30 RgbInteger;
	static const Version30 RgbaInteger;
	static const Version30 BgrInteger;
	static const Version30 BgraInteger;
	static const Version30 Float32UnsignedInt248Rev;
	static const Version30 FramebufferSrgb;
	static const Version30 CompressedRedRgtc1;
	static const Version30 CompressedSignedRedRgtc1;
	static const Version30 CompressedRgRgtc2;
	static const Version30 CompressedSignedRgRgtc2;
	static const Version30 Sampler1DArray;
	static const Version30 Sampler2DArray;
	static const Version30 Sampler1DArrayShadow;
	static const Version30 Sampler2DArrayShadow;
	static const Version30 SamplerCubeShadow;
	static const Version30 UnsignedIntVec2;
	static const Version30 UnsignedIntVec3;
	static const Version30 UnsignedIntVec4;
	static const Version30 IntSampler1D;
	static const Version30 IntSampler2D;
	static const Version30 IntSampler3D;
	static const Version30 IntSamplerCube;
	static const Version30 IntSampler1DArray;
	static const Version30 IntSampler2DArray;
	static const Version30 UnsignedIntSampler1D;
	static const Version30 UnsignedIntSampler2D;
	static const Version30 UnsignedIntSampler3D;
	static const Version30 UnsignedIntSamplerCube;
	static const Version30 UnsignedIntSampler1DArray;
	static const Version30 UnsignedIntSampler2DArray;
	static const Version30 QueryWait;
	static const Version30 QueryNoWait;
	static const Version30 QueryByRegionWait;
	static const Version30 QueryByRegionNoWait;
	static const Version30 BufferAccessFlags;
	static const Version30 BufferMapLength;
	static const Version30 BufferMapOffset;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version31)
	static const Version31 TextureRectangle;
	static const Version31 TextureBindingRectangle;
	static const Version31 ProxyTextureRectangle;
	static const Version31 MaxRectangleTextureSize;
	static const Version31 UniformBuffer;
	static const Version31 UniformBufferBinding;
	static const Version31 UniformBufferStart;
	static const Version31 UniformBufferSize;
	static const Version31 MaxVertexUniformBlocks;
	static const Version31 MaxGeometryUniformBlocks;
	static const Version31 MaxFragmentUniformBlocks;
	static const Version31 MaxCombinedUniformBlocks;
	static const Version31 MaxUniformBufferBindings;
	static const Version31 MaxUniformBlockSize;
	static const Version31 MaxCombinedVertexUniformComponents;
	static const Version31 MaxCombinedGeometryUniformComponents;
	static const Version31 MaxCombinedFragmentUniformComponents;
	static const Version31 UniformBufferOffsetAlignment;
	static const Version31 ActiveUniformBlockMaxNameLength;
	static const Version31 ActiveUniformBlocks;
	static const Version31 UniformType;
	static const Version31 UniformSize;
	static const Version31 UniformNameLength;
	static const Version31 UniformBlockIndex;
	static const Version31 UniformOffset;
	static const Version31 UniformArrayStride;
	static const Version31 UniformMatrixStride;
	static const Version31 UniformIsRowMajor;
	static const Version31 UniformBlockBinding;
	static const Version31 UniformBlockDataSize;
	static const Version31 UniformBlockNameLength;
	static const Version31 UniformBlockActiveUniforms;
	static const Version31 UniformBlockActiveUniformIndices;
	static const Version31 UniformBlockReferencedByVertexShader;
	static const Version31 UniformBlockReferencedByGeometryShader;
	static const Version31 UniformBlockReferencedByFragmentShader;
	static const Version31 Sampler2DRect;
	static const Version31 Sampler2DRectShadow;
	static const Version31 TextureBuffer;
	static const Version31 MaxTextureBufferSize;
	static const Version31 TextureBindingBuffer;
	static const Version31 TextureBufferDataStoreBinding;
	static const Version31 SamplerBuffer;
	static const Version31 IntSampler2DRect;
	static const Version31 IntSamplerBuffer;
	static const Version31 UnsignedIntSampler2DRect;
	static const Version31 UnsignedIntSamplerBuffer;
	static const Version31 CopyReadBuffer;
	static const Version31 CopyWriteBuffer;
	static const Version31 R8Snorm;
	static const Version31 Rg8Snorm;
	static const Version31 Rgb8Snorm;
	static const Version31 Rgba8Snorm;
	static const Version31 R16Snorm;
	static const Version31 Rg16Snorm;
	static const Version31 Rgb16Snorm;
	static const Version31 Rgba16Snorm;
	static const Version31 SignedNormalized;
	static const Version31 PrimitiveRestart;
	static const Version31 PrimitiveRestartIndex;
	static const Version31 InvalidIndex;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version32)
	static const Version32 ContextCoreProfileBit;
	static const Version32 SyncFlushCommandsBit;
	static const Version32 ContextCompatibilityProfileBit;
	static const Version32 LinesAdjacency;
	static const Version32 LineStripAdjacency;
	static const Version32 TrianglesAdjacency;
	static const Version32 TriangleStripAdjacency;
	static const Version32 ProgramPointSize;
	static const Version32 DepthClamp;
	static const Version32 TextureCubeMapSeamless;
	static const Version32 GeometryVerticesOut;
	static const Version32 GeometryInputType;
	static const Version32 GeometryOutputType;
	static const Version32 MaxGeometryTextureImageUnits;
	static const Version32 FramebufferAttachmentLayered;
	static const Version32 FramebufferIncompleteLayerTargets;
	static const Version32 GeometryShader;
	static const Version32 MaxGeometryUniformComponents;
	static const Version32 MaxGeometryOutputVertices;
	static const Version32 MaxGeometryTotalOutputComponents;
	static const Version32 QuadsFollowProvokingVertexConvention;
	static const Version32 FirstVertexConvention;
	static const Version32 LastVertexConvention;
	static const Version32 ProvokingVertex;
	static const Version32 SamplePosition;
	static const Version32 SampleMask;
	static const Version32 SampleMaskValue;
	static const Version32 MaxSampleMaskWords;
	static const Version32 Texture2DMultisample;
	static const Version32 ProxyTexture2DMultisample;
	static const Version32 Texture2DMultisampleArray;
	static const Version32 ProxyTexture2DMultisampleArray;
	static const Version32 TextureBinding2DMultisample;
	static const Version32 TextureBinding2DMultisampleArray;
	static const Version32 TextureSamples;
	static const Version32 TextureFixedSampleLocations;
	static const Version32 Sampler2DMultisample;
	static const Version32 IntSampler2DMultisample;
	static const Version32 UnsignedIntSampler2DMultisample;
	static const Version32 Sampler2DMultisampleArray;
	static const Version32 IntSampler2DMultisampleArray;
	static const Version32 UnsignedIntSampler2DMultisampleArray;
	static const Version32 MaxColorTextureSamples;
	static const Version32 MaxDepthTextureSamples;
	static const Version32 MaxIntegerSamples;
	static const Version32 MaxServerWaitTimeout;
	static const Version32 ObjectType;
	static const Version32 SyncCondition;
	static const Version32 SyncStatus;
	static const Version32 SyncFlags;
	static const Version32 SyncFence;
	static const Version32 SyncGpuCommandsComplete;
	static const Version32 Unsignaled;
	static const Version32 Signaled;
	static const Version32 AlreadySignaled;
	static const Version32 TimeoutExpired;
	static const Version32 ConditionSatisfied;
	static const Version32 WaitFailed;
	static const Version32 MaxVertexOutputComponents;
	static const Version32 MaxGeometryInputComponents;
	static const Version32 MaxGeometryOutputComponents;
	static const Version32 MaxFragmentInputComponents;
	static const Version32 ContextProfileMask;
	static const Version32 TimeoutIgnored;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version33)
	static const Version33 TimeElapsed;
	static const Version33 Src1Color;
	static const Version33 OneMinusSrc1Color;
	static const Version33 OneMinusSrc1Alpha;
	static const Version33 MaxDualSourceDrawBuffers;
	static const Version33 VertexAttribArrayDivisor;
	static const Version33 SamplerBinding;
	static const Version33 AnySamplesPassed;
	static const Version33 Int2101010Rev;
	static const Version33 Timestamp;
	static const Version33 TextureSwizzleR;
	static const Version33 TextureSwizzleG;
	static const Version33 TextureSwizzleB;
	static const Version33 TextureSwizzleA;
	static const Version33 TextureSwizzleRgba;
	static const Version33 Rgb10A2ui;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version40)
	static const Version40 Quads;
	static const Version40 Patches;
	static const Version40 UniformBlockReferencedByTessControlShader;
	static const Version40 UniformBlockReferencedByTessEvaluationShader;
	static const Version40 MaxTessControlInputComponents;
	static const Version40 MaxTessEvaluationInputComponents;
	static const Version40 GeometryShaderInvocations;
	static const Version40 SampleShading;
	static const Version40 MinSampleShadingValue;
	static const Version40 ActiveSubroutines;
	static const Version40 ActiveSubroutineUniforms;
	static const Version40 MaxSubroutines;
	static const Version40 MaxSubroutineUniformLocations;
	static const Version40 MaxCombinedTessControlUniformComponents;
	static const Version40 MaxCombinedTessEvaluationUniformComponents;
	static const Version40 TransformFeedback;
	static const Version40 TransformFeedbackBufferPaused;
	static const Version40 TransformFeedbackBufferActive;
	static const Version40 TransformFeedbackBinding;
	static const Version40 ActiveSubroutineUniformLocations;
	static const Version40 ActiveSubroutineMaxLength;
	static const Version40 ActiveSubroutineUniformMaxLength;
	static const Version40 NumCompatibleSubroutines;
	static const Version40 CompatibleSubroutines;
	static const Version40 MaxGeometryShaderInvocations;
	static const Version40 MinFragmentInterpolationOffset;
	static const Version40 MaxFragmentInterpolationOffset;
	static const Version40 FragmentInterpolationOffsetBits;
	static const Version40 MinProgramTextureGatherOffset;
	static const Version40 MaxProgramTextureGatherOffset;
	static const Version40 MaxTransformFeedbackBuffers;
	static const Version40 MaxVertexStreams;
	static const Version40 PatchVertices;
	static const Version40 PatchDefaultInnerLevel;
	static const Version40 PatchDefaultOuterLevel;
	static const Version40 TessControlOutputVertices;
	static const Version40 TessGenMode;
	static const Version40 TessGenSpacing;
	static const Version40 TessGenVertexOrder;
	static const Version40 TessGenPointMode;
	static const Version40 Isolines;
	static const Version40 FractionalOdd;
	static const Version40 FractionalEven;
	static const Version40 MaxPatchVertices;
	static const Version40 MaxTessGenLevel;
	static const Version40 MaxTessControlUniformComponents;
	static const Version40 MaxTessEvaluationUniformComponents;
	static const Version40 MaxTessControlTextureImageUnits;
	static const Version40 MaxTessEvaluationTextureImageUnits;
	static const Version40 MaxTessControlOutputComponents;
	static const Version40 MaxTessPatchComponents;
	static const Version40 MaxTessControlTotalOutputComponents;
	static const Version40 MaxTessEvaluationOutputComponents;
	static const Version40 TessEvaluationShader;
	static const Version40 TessControlShader;
	static const Version40 MaxTessControlUniformBlocks;
	static const Version40 MaxTessEvaluationUniformBlocks;
	static const Version40 DrawIndirectBuffer;
	static const Version40 DrawIndirectBufferBinding;
	static const Version40 DoubleMat2;
	static const Version40 DoubleMat3;
	static const Version40 DoubleMat4;
	static const Version40 DoubleMat2x3;
	static const Version40 DoubleMat2x4;
	static const Version40 DoubleMat3x2;
	static const Version40 DoubleMat3x4;
	static const Version40 DoubleMat4x2;
	static const Version40 DoubleMat4x3;
	static const Version40 DoubleVec2;
	static const Version40 DoubleVec3;
	static const Version40 DoubleVec4;
	static const Version40 TextureCubeMapArray;
	static const Version40 TextureBindingCubeMapArray;
	static const Version40 ProxyTextureCubeMapArray;
	static const Version40 SamplerCubeMapArray;
	static const Version40 SamplerCubeMapArrayShadow;
	static const Version40 IntSamplerCubeMapArray;
	static const Version40 UnsignedIntSamplerCubeMapArray;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version41)
	static const Version41 VertexShaderBit;
	static const Version41 FragmentShaderBit;
	static const Version41 GeometryShaderBit;
	static const Version41 TessControlShaderBit;
	static const Version41 TessEvaluationShaderBit;
	static const Version41 Fixed;
	static const Version41 ProgramBinaryRetrievableHint;
	static const Version41 ProgramSeparable;
	static const Version41 ActiveProgram;
	static const Version41 ProgramPipelineBinding;
	static const Version41 MaxViewports;
	static const Version41 ViewportSubpixelBits;
	static const Version41 ViewportBoundsRange;
	static const Version41 LayerProvokingVertex;
	static const Version41 ViewportIndexProvokingVertex;
	static const Version41 UndefinedVertex;
	static const Version41 ProgramBinaryLength;
	static const Version41 NumProgramBinaryFormats;
	static const Version41 ProgramBinaryFormats;
	static const Version41 ImplementationColorReadType;
	static const Version41 ImplementationColorReadFormat;
	static const Version41 Rgb565;
	static const Version41 LowFloat;
	static const Version41 MediumFloat;
	static const Version41 HighFloat;
	static const Version41 LowInt;
	static const Version41 MediumInt;
	static const Version41 HighInt;
	static const Version41 ShaderBinaryFormats;
	static const Version41 NumShaderBinaryFormats;
	static const Version41 ShaderCompiler;
	static const Version41 MaxVertexUniformVectors;
	static const Version41 MaxVaryingVectors;
	static const Version41 MaxFragmentUniformVectors;
	static const Version41 AllShaderBits;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version42)
	static const Version42 VertexAttribArrayBarrierBit;
	static const Version42 ElementArrayBarrierBit;
	static const Version42 UniformBarrierBit;
	static const Version42 TextureFetchBarrierBit;
	static const Version42 ShaderImageAccessBarrierBit;
	static const Version42 CommandBarrierBit;
	static const Version42 PixelBufferBarrierBit;
	static const Version42 TextureUpdateBarrierBit;
	static const Version42 BufferUpdateBarrierBit;
	static const Version42 FramebufferBarrierBit;
	static const Version42 TransformFeedbackBarrierBit;
	static const Version42 AtomicCounterBarrierBit;
	static const Version42 CompressedRgbaBptcUnorm;
	static const Version42 CompressedSrgbAlphaBptcUnorm;
	static const Version42 CompressedRgbBptcSignedFloat;
	static const Version42 CompressedRgbBptcUnsignedFloat;
	static const Version42 MaxImageUnits;
	static const Version42 MaxCombinedImageUnitsAndFragmentOutputs;
	static const Version42 ImageBindingName;
	static const Version42 ImageBindingLevel;
	static const Version42 ImageBindingLayered;
	static const Version42 ImageBindingLayer;
	static const Version42 ImageBindingAccess;
	static const Version42 Image1D;
	static const Version42 Image2D;
	static const Version42 Image3D;
	static const Version42 Image2DRect;
	static const Version42 ImageCube;
	static const Version42 ImageBuffer;
	static const Version42 Image1DArray;
	static const Version42 Image2DArray;
	static const Version42 ImageCubeMapArray;
	static const Version42 Image2DMultisample;
	static const Version42 Image2DMultisampleArray;
	static const Version42 IntImage1D;
	static const Version42 IntImage2D;
	static const Version42 IntImage3D;
	static const Version42 IntImage2DRect;
	static const Version42 IntImageCube;
	static const Version42 IntImageBuffer;
	static const Version42 IntImage1DArray;
	static const Version42 IntImage2DArray;
	static const Version42 IntImageCubeMapArray;
	static const Version42 IntImage2DMultisample;
	static const Version42 IntImage2DMultisampleArray;
	static const Version42 UnsignedIntImage1D;
	static const Version42 UnsignedIntImage2D;
	static const Version42 UnsignedIntImage3D;
	static const Version42 UnsignedIntImage2DRect;
	static const Version42 UnsignedIntImageCube;
	static const Version42 UnsignedIntImageBuffer;
	static const Version42 UnsignedIntImage1DArray;
	static const Version42 UnsignedIntImage2DArray;
	static const Version42 UnsignedIntImageCubeMapArray;
	static const Version42 UnsignedIntImage2DMultisample;
	static const Version42 UnsignedIntImage2DMultisampleArray;
	static const Version42 MaxImageSamples;
	static const Version42 ImageBindingFormat;
	static const Version42 MinMapBufferAlignment;
	static const Version42 ImageFormatCompatibilityType;
	static const Version42 ImageFormatCompatibilityBySize;
	static const Version42 ImageFormatCompatibilityByClass;
	static const Version42 MaxVertexImageUniforms;
	static const Version42 MaxTessControlImageUniforms;
	static const Version42 MaxTessEvaluationImageUniforms;
	static const Version42 MaxGeometryImageUniforms;
	static const Version42 MaxFragmentImageUniforms;
	static const Version42 MaxCombinedImageUniforms;
	static const Version42 UnpackCompressedBlockWidth;
	static const Version42 UnpackCompressedBlockHeight;
	static const Version42 UnpackCompressedBlockDepth;
	static const Version42 UnpackCompressedBlockSize;
	static const Version42 PackCompressedBlockWidth;
	static const Version42 PackCompressedBlockHeight;
	static const Version42 PackCompressedBlockDepth;
	static const Version42 PackCompressedBlockSize;
	static const Version42 TextureImmutableFormat;
	static const Version42 AtomicCounterBuffer;
	static const Version42 AtomicCounterBufferBinding;
	static const Version42 AtomicCounterBufferStart;
	static const Version42 AtomicCounterBufferSize;
	static const Version42 AtomicCounterBufferDataSize;
	static const Version42 AtomicCounterBufferActiveAtomicCounters;
	static const Version42 AtomicCounterBufferActiveAtomicCounterIndices;
	static const Version42 AtomicCounterBufferReferencedByVertexShader;
	static const Version42 AtomicCounterBufferReferencedByTessControlShader;
	static const Version42 AtomicCounterBufferReferencedByTessEvaluationShader;
	static const Version42 AtomicCounterBufferReferencedByGeometryShader;
	static const Version42 AtomicCounterBufferReferencedByFragmentShader;
	static const Version42 MaxVertexAtomicCounterBuffers;
	static const Version42 MaxTessControlAtomicCounterBuffers;
	static const Version42 MaxTessEvaluationAtomicCounterBuffers;
	static const Version42 MaxGeometryAtomicCounterBuffers;
	static const Version42 MaxFragmentAtomicCounterBuffers;
	static const Version42 MaxCombinedAtomicCounterBuffers;
	static const Version42 MaxVertexAtomicCounters;
	static const Version42 MaxTessControlAtomicCounters;
	static const Version42 MaxTessEvaluationAtomicCounters;
	static const Version42 MaxGeometryAtomicCounters;
	static const Version42 MaxFragmentAtomicCounters;
	static const Version42 MaxCombinedAtomicCounters;
	static const Version42 MaxAtomicCounterBufferSize;
	static const Version42 ActiveAtomicCounterBuffers;
	static const Version42 UniformAtomicCounterBufferIndex;
	static const Version42 UnsignedIntAtomicCounter;
	static const Version42 MaxAtomicCounterBufferBindings;
	static const Version42 NumSampleCounts;
	static const Version42 AllBarrierBits;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version43)
	static const Version43 ContextFlagDebugBit;
	static const Version43 ComputeShaderBit;
	static const Version43 ShaderStorageBarrierBit;
	static const Version43 StackOverflow;
	static const Version43 StackUnderflow;
	static const Version43 VertexArray;
	static const Version43 DebugOutputSynchronous;
	static const Version43 DebugNextLoggedMessageLength;
	static const Version43 DebugCallbackFunction;
	static const Version43 DebugCallbackUserParam;
	static const Version43 DebugSourceApi;
	static const Version43 DebugSourceWindowSystem;
	static const Version43 DebugSourceShaderCompiler;
	static const Version43 DebugSourceThirdParty;
	static const Version43 DebugSourceApplication;
	static const Version43 DebugSourceOther;
	static const Version43 DebugTypeError;
	static const Version43 DebugTypeDeprecatedBehavior;
	static const Version43 DebugTypeUndefinedBehavior;
	static const Version43 DebugTypePortability;
	static const Version43 DebugTypePerformance;
	static const Version43 DebugTypeOther;
	static const Version43 MaxComputeSharedMemorySize;
	static const Version43 MaxComputeUniformComponents;
	static const Version43 MaxComputeAtomicCounterBuffers;
	static const Version43 MaxComputeAtomicCounters;
	static const Version43 MaxCombinedComputeUniformComponents;
	static const Version43 ComputeWorkGroupSize;
	static const Version43 DebugTypeMarker;
	static const Version43 DebugTypePushGroup;
	static const Version43 DebugTypePopGroup;
	static const Version43 DebugSeverityNotification;
	static const Version43 MaxDebugGroupStackDepth;
	static const Version43 DebugGroupStackDepth;
	static const Version43 MaxUniformLocations;
	static const Version43 InternalformatSupported;
	static const Version43 InternalformatPreferred;
	static const Version43 InternalformatRedSize;
	static const Version43 InternalformatGreenSize;
	static const Version43 InternalformatBlueSize;
	static const Version43 InternalformatAlphaSize;
	static const Version43 InternalformatDepthSize;
	static const Version43 InternalformatStencilSize;
	static const Version43 InternalformatSharedSize;
	static const Version43 InternalformatRedType;
	static const Version43 InternalformatGreenType;
	static const Version43 InternalformatBlueType;
	static const Version43 InternalformatAlphaType;
	static const Version43 InternalformatDepthType;
	static const Version43 InternalformatStencilType;
	static const Version43 MaxWidth;
	static const Version43 MaxHeight;
	static const Version43 MaxDepth;
	static const Version43 MaxLayers;
	static const Version43 MaxCombinedDimensions;
	static const Version43 ColorComponents;
	static const Version43 DepthComponents;
	static const Version43 StencilComponents;
	static const Version43 ColorRenderable;
	static const Version43 DepthRenderable;
	static const Version43 StencilRenderable;
	static const Version43 FramebufferRenderable;
	static const Version43 FramebufferRenderableLayered;
	static const Version43 FramebufferBlend;
	static const Version43 ReadPixels;
	static const Version43 ReadPixelsFormat;
	static const Version43 ReadPixelsType;
	static const Version43 TextureImageFormat;
	static const Version43 TextureImageType;
	static const Version43 GetTextureImageFormat;
	static const Version43 GetTextureImageType;
	static const Version43 Mipmap;
	static const Version43 ManualGenerateMipmap;
	static const Version43 AutoGenerateMipmap;
	static const Version43 ColorEncoding;
	static const Version43 SrgbRead;
	static const Version43 SrgbWrite;
	static const Version43 Filter;
	static const Version43 VertexTexture;
	static const Version43 TessControlTexture;
	static const Version43 TessEvaluationTexture;
	static const Version43 GeometryTexture;
	static const Version43 FragmentTexture;
	static const Version43 ComputeTexture;
	static const Version43 TextureShadow;
	static const Version43 TextureGather;
	static const Version43 TextureGatherShadow;
	static const Version43 ShaderImageLoad;
	static const Version43 ShaderImageStore;
	static const Version43 ShaderImageAtomic;
	static const Version43 ImageTexelSize;
	static const Version43 ImageCompatibilityClass;
	static const Version43 ImagePixelFormat;
	static const Version43 ImagePixelType;
	static const Version43 SimultaneousTextureAndDepthTest;
	static const Version43 SimultaneousTextureAndStencilTest;
	static const Version43 SimultaneousTextureAndDepthWrite;
	static const Version43 SimultaneousTextureAndStencilWrite;
	static const Version43 TextureCompressedBlockWidth;
	static const Version43 TextureCompressedBlockHeight;
	static const Version43 TextureCompressedBlockSize;
	static const Version43 ClearBuffer;
	static const Version43 TextureView;
	static const Version43 ViewCompatibilityClass;
	static const Version43 FullSupport;
	static const Version43 CaveatSupport;
	static const Version43 ImageClass4X32;
	static const Version43 ImageClass2X32;
	static const Version43 ImageClass1X32;
	static const Version43 ImageClass4X16;
	static const Version43 ImageClass2X16;
	static const Version43 ImageClass1X16;
	static const Version43 ImageClass4X8;
	static const Version43 ImageClass2X8;
	static const Version43 ImageClass1X8;
	static const Version43 ImageClass111110;
	static const Version43 ImageClass1010102;
	static const Version43 ViewClass128Bits;
	static const Version43 ViewClass96Bits;
	static const Version43 ViewClass64Bits;
	static const Version43 ViewClass48Bits;
	static const Version43 ViewClass32Bits;
	static const Version43 ViewClass24Bits;
	static const Version43 ViewClass16Bits;
	static const Version43 ViewClass8Bits;
	static const Version43 ViewClassS3tcDxt1Rgb;
	static const Version43 ViewClassS3tcDxt1Rgba;
	static const Version43 ViewClassS3tcDxt3Rgba;
	static const Version43 ViewClassS3tcDxt5Rgba;
	static const Version43 ViewClassRgtc1Red;
	static const Version43 ViewClassRgtc2Rg;
	static const Version43 ViewClassBptcUnorm;
	static const Version43 ViewClassBptcFloat;
	static const Version43 VertexAttribBinding;
	static const Version43 VertexAttribRelativeOffset;
	static const Version43 VertexBindingDivisor;
	static const Version43 VertexBindingOffset;
	static const Version43 VertexBindingStride;
	static const Version43 MaxVertexAttribRelativeOffset;
	static const Version43 MaxVertexAttribBindings;
	static const Version43 TextureViewMinLevel;
	static const Version43 TextureViewNumLevels;
	static const Version43 TextureViewMinLayer;
	static const Version43 TextureViewNumLayers;
	static const Version43 TextureImmutableLevels;
	static const Version43 Buffer;
	static const Version43 Shader;
	static const Version43 Program;
	static const Version43 Query;
	static const Version43 ProgramPipeline;
	static const Version43 Sampler;
	static const Version43 DisplayList;
	static const Version43 MaxLabelLength;
	static const Version43 NumShadingLanguageVersions;
	static const Version43 VertexAttribArrayLong;
	static const Version43 PrimitiveRestartFixedIndex;
	static const Version43 AnySamplesPassedConservative;
	static const Version43 MaxElementIndex;
	static const Version43 MaxCombinedShaderOutputResources;
	static const Version43 VertexBindingBuffer;
	static const Version43 ShaderStorageBuffer;
	static const Version43 ShaderStorageBufferBinding;
	static const Version43 ShaderStorageBufferStart;
	static const Version43 ShaderStorageBufferSize;
	static const Version43 MaxVertexShaderStorageBlocks;
	static const Version43 MaxGeometryShaderStorageBlocks;
	static const Version43 MaxTessControlShaderStorageBlocks;
	static const Version43 MaxTessEvaluationShaderStorageBlocks;
	static const Version43 MaxFragmentShaderStorageBlocks;
	static const Version43 MaxComputeShaderStorageBlocks;
	static const Version43 MaxCombinedShaderStorageBlocks;
	static const Version43 MaxShaderStorageBufferBindings;
	static const Version43 MaxShaderStorageBlockSize;
	static const Version43 ShaderStorageBufferOffsetAlignment;
	static const Version43 DepthStencilTextureMode;
	static const Version43 MaxComputeWorkGroupInvocations;
	static const Version43 UniformBlockReferencedByComputeShader;
	static const Version43 AtomicCounterBufferReferencedByComputeShader;
	static const Version43 DispatchIndirectBuffer;
	static const Version43 DispatchIndirectBufferBinding;
	static const Version43 MaxDebugMessageLength;
	static const Version43 MaxDebugLoggedMessages;
	static const Version43 DebugLoggedMessages;
	static const Version43 DebugSeverityHigh;
	static const Version43 DebugSeverityMedium;
	static const Version43 DebugSeverityLow;
	static const Version43 TextureBufferOffset;
	static const Version43 TextureBufferSize;
	static const Version43 TextureBufferOffsetAlignment;
	static const Version43 ComputeShader;
	static const Version43 MaxComputeUniformBlocks;
	static const Version43 MaxComputeTextureImageUnits;
	static const Version43 MaxComputeImageUniforms;
	static const Version43 MaxComputeWorkGroupCount;
	static const Version43 MaxComputeWorkGroupSize;
	static const Version43 CompressedR11Eac;
	static const Version43 CompressedSignedR11Eac;
	static const Version43 CompressedRg11Eac;
	static const Version43 CompressedSignedRg11Eac;
	static const Version43 CompressedRgb8Etc2;
	static const Version43 CompressedSrgb8Etc2;
	static const Version43 CompressedRgb8PunchthroughAlpha1Etc2;
	static const Version43 CompressedSrgb8PunchthroughAlpha1Etc2;
	static const Version43 CompressedRgba8Etc2Eac;
	static const Version43 CompressedSrgb8Alpha8Etc2Eac;
	static const Version43 DebugOutput;
	static const Version43 Uniform;
	static const Version43 UniformBlock;
	static const Version43 ProgramInput;
	static const Version43 ProgramOutput;
	static const Version43 BufferVariable;
	static const Version43 ShaderStorageBlock;
	static const Version43 IsPerPatch;
	static const Version43 VertexSubroutine;
	static const Version43 TessControlSubroutine;
	static const Version43 TessEvaluationSubroutine;
	static const Version43 GeometrySubroutine;
	static const Version43 FragmentSubroutine;
	static const Version43 ComputeSubroutine;
	static const Version43 VertexSubroutineUniform;
	static const Version43 TessControlSubroutineUniform;
	static const Version43 TessEvaluationSubroutineUniform;
	static const Version43 GeometrySubroutineUniform;
	static const Version43 FragmentSubroutineUniform;
	static const Version43 ComputeSubroutineUniform;
	static const Version43 TransformFeedbackVarying;
	static const Version43 ActiveResources;
	static const Version43 MaxNameLength;
	static const Version43 MaxNumActiveVariables;
	static const Version43 MaxNumCompatibleSubroutines;
	static const Version43 NameLength;
	static const Version43 Type;
	static const Version43 ArraySize;
	static const Version43 Offset;
	static const Version43 BlockIndex;
	static const Version43 ArrayStride;
	static const Version43 MatrixStride;
	static const Version43 IsRowMajor;
	static const Version43 AtomicCounterBufferIndex;
	static const Version43 BufferBinding;
	static const Version43 BufferDataSize;
	static const Version43 NumActiveVariables;
	static const Version43 ActiveVariables;
	static const Version43 ReferencedByVertexShader;
	static const Version43 ReferencedByTessControlShader;
	static const Version43 ReferencedByTessEvaluationShader;
	static const Version43 ReferencedByGeometryShader;
	static const Version43 ReferencedByFragmentShader;
	static const Version43 ReferencedByComputeShader;
	static const Version43 TopLevelArraySize;
	static const Version43 TopLevelArrayStride;
	static const Version43 Location;
	static const Version43 LocationIndex;
	static const Version43 FramebufferDefaultWidth;
	static const Version43 FramebufferDefaultHeight;
	static const Version43 FramebufferDefaultLayers;
	static const Version43 FramebufferDefaultSamples;
	static const Version43 FramebufferDefaultFixedSampleLocations;
	static const Version43 MaxFramebufferWidth;
	static const Version43 MaxFramebufferHeight;
	static const Version43 MaxFramebufferLayers;
	static const Version43 MaxFramebufferSamples;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version44)
	static const Version44 ClientMappedBufferBarrierBit;
	static const Version44 QueryBufferBarrierBit;
	static const Version44 MapReadBit;
	static const Version44 MapWriteBit;
	static const Version44 MapPersistentBit;
	static const Version44 MapCoherentBit;
	static const Version44 DynamicStorageBit;
	static const Version44 ClientStorageBit;
	static const Version44 StencilIndex;
	static const Version44 BufferImmutableStorage;
	static const Version44 BufferStorageFlags;
	static const Version44 PrimitiveRestartForPatchesSupported;
	static const Version44 MaxVertexAttribStride;
	static const Version44 MirrorClampToEdge;
	static const Version44 TextureBufferBinding;
	static const Version44 UnsignedInt10F11F11FRev;
	static const Version44 TransformFeedbackBuffer;
	static const Version44 StencilIndex8;
	static const Version44 QueryBuffer;
	static const Version44 QueryBufferBinding;
	static const Version44 QueryResultNoWait;
	static const Version44 LocationComponent;
	static const Version44 TransformFeedbackBufferIndex;
	static const Version44 TransformFeedbackBufferStride;
	static const Version44 ClearTexture;
OPENGL_ENUM_END

OPENGL_ENUM_START(Version45)
	static const Version45 NoError;
	static const Version45 None;
	static const Version45 ContextFlagRobustAccessBit;
	static const Version45 ContextLost;
	static const Version45 TextureTarget;
	static const Version45 TextureBinding1D;
	static const Version45 TextureBinding2D;
	static const Version45 TextureBinding3D;
	static const Version45 LoseContextOnReset;
	static const Version45 GuiltyContextReset;
	static const Version45 InnocentContextReset;
	static const Version45 UnknownContextReset;
	static const Version45 ResetNotificationStrategy;
	static const Version45 NoResetNotification;
	static const Version45 QueryTarget;
	static const Version45 TextureBinding;
	static const Version45 MaxCullDistances;
	static const Version45 MaxCombinedClipAndCullDistances;
	static const Version45 ContextReleaseBehavior;
	static const Version45 ContextReleaseBehaviorFlush;
	static const Version45 TextureBindingRectangle;
	static const Version45 TextureBindingCubeMap;
	static const Version45 TextureBinding1DArray;
	static const Version45 TextureBinding2DArray;
	static const Version45 TextureBindingBuffer;
	static const Version45 LowerLeft;
	static const Version45 UpperLeft;
	static const Version45 QueryWaitInverted;
	static const Version45 QueryNoWaitInverted;
	static const Version45 QueryByRegionWaitInverted;
	static const Version45 QueryByRegionNoWaitInverted;
	static const Version45 TextureBindingCubeMapArray;
	static const Version45 TextureBinding2DMultisample;
	static const Version45 TextureBinding2DMultisampleArray;
	static const Version45 ClipOrigin;
	static const Version45 ClipDepthMode;
	static const Version45 NegativeOneToOne;
	static const Version45 ZeroToOne;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexArrayIndexed64Parameter)
	static const VertexArrayIndexed64Parameter VertexBindingOffset;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexArrayIndexedParameter)
	static const VertexArrayIndexedParameter VertexAttribRelativeOffset;
	static const VertexArrayIndexedParameter VertexAttribArrayEnabled;
	static const VertexArrayIndexedParameter VertexAttribArraySize;
	static const VertexArrayIndexedParameter VertexAttribArrayStride;
	static const VertexArrayIndexedParameter VertexAttribArrayType;
	static const VertexArrayIndexedParameter VertexAttribArrayLong;
	static const VertexArrayIndexedParameter VertexAttribArrayNormalized;
	static const VertexArrayIndexedParameter VertexAttribArrayInteger;
	static const VertexArrayIndexedParameter VertexAttribArrayDivisor;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexArrayParameter)
	static const VertexArrayParameter ElementArrayBufferBinding;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexAttribDoubleType)
	static const VertexAttribDoubleType Double;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexAttribDPointerType)
	static const VertexAttribDPointerType Double;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexAttribIntegerType)
	static const VertexAttribIntegerType Byte;
	static const VertexAttribIntegerType UnsignedByte;
	static const VertexAttribIntegerType Short;
	static const VertexAttribIntegerType UnsignedShort;
	static const VertexAttribIntegerType Int;
	static const VertexAttribIntegerType UnsignedInt;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexAttribIPointerType)
	static const VertexAttribIPointerType Byte;
	static const VertexAttribIPointerType UnsignedByte;
	static const VertexAttribIPointerType Short;
	static const VertexAttribIPointerType UnsignedShort;
	static const VertexAttribIPointerType Int;
	static const VertexAttribIPointerType UnsignedInt;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexAttribParameter)
	static const VertexAttribParameter ArrayEnabled;
	static const VertexAttribParameter ArraySize;
	static const VertexAttribParameter ArrayStride;
	static const VertexAttribParameter ArrayType;
	static const VertexAttribParameter CurrentVertexAttrib;
	static const VertexAttribParameter ArrayNormalized;
	static const VertexAttribParameter VertexAttribArrayInteger;
	static const VertexAttribParameter VertexAttribArrayDivisor;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexAttribParameterArb)
	static const VertexAttribParameterArb ArrayEnabled;
	static const VertexAttribParameterArb ArraySize;
	static const VertexAttribParameterArb ArrayStride;
	static const VertexAttribParameterArb ArrayType;
	static const VertexAttribParameterArb CurrentVertexAttrib;
	static const VertexAttribParameterArb ArrayNormalized;
	static const VertexAttribParameterArb ArrayDivisor;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexAttribPointerParameter)
	static const VertexAttribPointerParameter ArrayPointer;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexAttribPointerParameterArb)
	static const VertexAttribPointerParameterArb ArrayPointer;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexAttribPointerType)
	static const VertexAttribPointerType Byte;
	static const VertexAttribPointerType UnsignedByte;
	static const VertexAttribPointerType Short;
	static const VertexAttribPointerType UnsignedShort;
	static const VertexAttribPointerType Int;
	static const VertexAttribPointerType UnsignedInt;
	static const VertexAttribPointerType Float;
	static const VertexAttribPointerType Double;
	static const VertexAttribPointerType HalfFloat;
	static const VertexAttribPointerType Fixed;
	static const VertexAttribPointerType UnsignedInt2101010Rev;
	static const VertexAttribPointerType Int2101010Rev;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexAttribPointerTypeArb)
	static const VertexAttribPointerTypeArb Byte;
	static const VertexAttribPointerTypeArb UnsignedByte;
	static const VertexAttribPointerTypeArb Short;
	static const VertexAttribPointerTypeArb UnsignedShort;
	static const VertexAttribPointerTypeArb Int;
	static const VertexAttribPointerTypeArb UnsignedInt;
	static const VertexAttribPointerTypeArb Float;
	static const VertexAttribPointerTypeArb Double;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexAttribType)
	static const VertexAttribType Byte;
	static const VertexAttribType UnsignedByte;
	static const VertexAttribType Short;
	static const VertexAttribType UnsignedShort;
	static const VertexAttribType Int;
	static const VertexAttribType UnsignedInt;
	static const VertexAttribType Float;
	static const VertexAttribType Double;
	static const VertexAttribType HalfFloat;
	static const VertexAttribType Fixed;
	static const VertexAttribType UnsignedInt2101010Rev;
	static const VertexAttribType Int2101010Rev;
OPENGL_ENUM_END

OPENGL_ENUM_START(VertexPointerType)
	static const VertexPointerType Short;
	static const VertexPointerType Int;
	static const VertexPointerType Float;
	static const VertexPointerType Double;
	static const VertexPointerType HalfFloat;
	static const VertexPointerType UnsignedInt2101010Rev;
	static const VertexPointerType Int2101010Rev;
OPENGL_ENUM_END

OPENGL_ENUM_START(WaitSyncFlags)
	static const WaitSyncFlags None;
OPENGL_ENUM_END

OPENGL_ENUM_START(WaitSyncStatus)
	static const WaitSyncStatus AlreadySignaled;
	static const WaitSyncStatus TimeoutExpired;
	static const WaitSyncStatus ConditionSatisfied;
	static const WaitSyncStatus WaitFailed;
OPENGL_ENUM_END

OPENGL_ENUM_START(WinPhongShading)
	static const WinPhongShading PhongWin;
	static const WinPhongShading PhongHintWin;
OPENGL_ENUM_END

OPENGL_ENUM_START(WinSpecularFog)
	static const WinSpecularFog FogSpecularTextureWin;
OPENGL_ENUM_END



extern struct OpenGL
{
/*private:
	bool queried;
public:
	OpenGL() : queried(false) {}
	bool Query(DisplayHandle display, DeviceContext devicectx);*/

	// GL
	void Accum(GLenum op, GLfloat value);
	void AlphaFunc(GLenum func, GLclampf ref);
	GLboolean AreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences);
	void ArrayElement(GLint i);
	void Begin(GLenum mode);
	void BindTexture(TextureTarget target, GLuint texture);
	void Bitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
	void BlendFunc(BlendingFactorSrc sfactor, BlendingFactorDest dfactor);
	void CallList(GLuint list);
	void CallLists(GLsizei n, GLenum type, const GLvoid *lists);
	void Clear(ClearBuffer mask);
	void ClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	void ClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	void ClearDepth(GLclampd depth);
	void ClearIndex(GLfloat c);
	void ClearStencil(GLint s);
	void ClipPlane(GLenum plane, const GLdouble *equation);
	void Color3b(GLbyte red, GLbyte green, GLbyte blue);
	void Color3bv(const GLbyte *v);
	void Color3d(GLdouble red, GLdouble green, GLdouble blue);
	void Color3dv(const GLdouble *v);
	void Color3f(GLfloat red, GLfloat green, GLfloat blue);
	void Color3fv(const GLfloat *v);
	void Color3i(GLint red, GLint green, GLint blue);
	void Color3iv(const GLint *v);
	void Color3s(GLshort red, GLshort green, GLshort blue);
	void Color3sv(const GLshort *v);
	void Color3ub(GLubyte red, GLubyte green, GLubyte blue);
	void Color3ubv(const GLubyte *v);
	void Color3ui(GLuint red, GLuint green, GLuint blue);
	void Color3uiv(const GLuint *v);
	void Color3us(GLushort red, GLushort green, GLushort blue);
	void Color3usv(const GLushort *v);
	void Color4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
	void Color4bv(const GLbyte *v);
	void Color4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
	void Color4dv(const GLdouble *v);
	void Color4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	void Color4fv(const GLfloat *v);
	void Color4i(GLint red, GLint green, GLint blue, GLint alpha);
	void Color4iv(const GLint *v);
	void Color4s(GLshort red, GLshort green, GLshort blue, GLshort alpha);
	void Color4sv(const GLshort *v);
	void Color4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
	void Color4ubv(const GLubyte *v);
	void Color4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha);
	void Color4uiv(const GLuint *v);
	void Color4us(GLushort red, GLushort green, GLushort blue, GLushort alpha);
	void Color4usv(const GLushort *v);
	void ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
	void ColorMaterial(GLenum face, GLenum mode);
	void ColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	void CopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
	void CopyTexImage1D(GLenum target, GLint level, PixelInternalFormat internalFormat, GLint x, GLint y, GLsizei width, GLint border);
	void CopyTexImage2D(GLenum target, GLint level, PixelInternalFormat internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	void CopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	void CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	void CullFace(CullFaceMode mode);
	void DeleteLists(GLuint list, GLsizei range);
	void DeleteTextures(GLsizei n, const GLuint *textures);
	void DeleteTexture(GLuint texture);
	void DepthFunc(GLenum func);
	void DepthMask(GLboolean flag);
	void DepthRange(GLclampd zNear, GLclampd zFar);
	void Disable(EnableCap cap);
	void DisableClientState(ArrayCap array);
	void DrawArrays(PrimitiveType mode, GLint first, GLsizei count);
	void DrawArrays(BeginMode mode, GLint first, GLsizei count);
	void DrawBuffer(DrawBufferMode mode);
	void DrawElements(PrimitiveType mode, GLsizei count, DrawElementsType type, const GLvoid *indices);
	void DrawElements(BeginMode mode, GLsizei count, DrawElementsType type, const GLvoid *indices);
	void DrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
	void EdgeFlag(GLboolean flag);
	void EdgeFlagPointer(GLsizei stride, const GLvoid *pointer);
	void EdgeFlagv(const GLboolean *flag);
	void Enable(EnableCap cap);
	void EnableClientState(ArrayCap array);
	void End(void);
	void EndList(void);
	void EvalCoord1d(GLdouble u);
	void EvalCoord1dv(const GLdouble *u);
	void EvalCoord1f(GLfloat u);
	void EvalCoord1fv(const GLfloat *u);
	void EvalCoord2d(GLdouble u, GLdouble v);
	void EvalCoord2dv(const GLdouble *u);
	void EvalCoord2f(GLfloat u, GLfloat v);
	void EvalCoord2fv(const GLfloat *u);
	void EvalMesh1(GLenum mode, GLint i1, GLint i2);
	void EvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
	void EvalPoint1(GLint i);
	void EvalPoint2(GLint i, GLint j);
	void FeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer);
	void Finish(void);
	void Flush(void);
	void Fogf(GLenum pname, GLfloat param);
	void Fogfv(GLenum pname, const GLfloat *params);
	void Fogi(GLenum pname, GLint param);
	void Fogiv(GLenum pname, const GLint *params);
	void FrontFace(GLenum mode);
	void Frustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
	GLuint GenLists(GLsizei range);
	void GenTextures(GLsizei n, GLuint *textures);
	GLuint GenTexture();
	void GetBooleanv(GLenum pname, GLboolean *params);
	void GetClipPlane(GLenum plane, GLdouble *equation);
	void GetDoublev(GLenum pname, GLdouble *params);
	ErrorCode GetError(void);
	void GetFloatv(GLenum pname, GLfloat *params);
	void GetIntegerv(GLenum pname, GLint *params);
	void GetLightfv(GLenum light, GLenum pname, GLfloat *params);
	void GetLightiv(GLenum light, GLenum pname, GLint *params);
	void GetMapdv(GLenum target, GLenum query, GLdouble *v);
	void GetMapfv(GLenum target, GLenum query, GLfloat *v);
	void GetMapiv(GLenum target, GLenum query, GLint *v);
	void GetMaterialfv(GLenum face, GLenum pname, GLfloat *params);
	void GetMaterialiv(GLenum face, GLenum pname, GLint *params);
	void GetPixelMapfv(GLenum map, GLfloat *values);
	void GetPixelMapuiv(GLenum map, GLuint *values);
	void GetPixelMapusv(GLenum map, GLushort *values);
	void GetPointerv(GLenum pname, GLvoid* *params);
	void GetPolygonStipple(GLubyte *mask);
	GLubyte* GetString(GLenum name);
	void GetTexEnv(TextureEnvTarget target, TextureEnvParameter pname, GLfloat *params);
	void GetTexEnv(TextureEnvTarget target, TextureEnvParameter pname, GLint *params);
	void GetTexGendv(GLenum coord, GLenum pname, GLdouble *params);
	void GetTexGenfv(GLenum coord, GLenum pname, GLfloat *params);
	void GetTexGeniv(GLenum coord, GLenum pname, GLint *params);
	void GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
	void GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params);
	void GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params);
	void GetTexParameterfv(GLenum target, GLenum pname, GLfloat *params);
	void GetTexParameteriv(GLenum target, GLenum pname, GLint *params);
	void Hint(GLenum target, GLenum mode);
	void IndexMask(GLuint mask);
	void IndexPointer(IndexPointerType type, GLsizei stride, const GLvoid *pointer);
	void Indexd(GLdouble c);
	void Indexdv(const GLdouble *c);
	void Indexf(GLfloat c);
	void Indexfv(const GLfloat *c);
	void Indexi(GLint c);
	void Indexiv(const GLint *c);
	void Indexs(GLshort c);
	void Indexsv(const GLshort *c);
	void Indexub(GLubyte c);
	void Indexubv(const GLubyte *c);
	void InitNames(void);
	void InterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer);
	GLboolean IsEnabled(GLenum cap);
	GLboolean IsList(GLuint list);
	GLboolean IsTexture(GLuint texture);
	void LightModelf(GLenum pname, GLfloat param);
	void LightModelfv(GLenum pname, const GLfloat *params);
	void LightModeli(GLenum pname, GLint param);
	void LightModeliv(GLenum pname, const GLint *params);
	void Lightf(GLenum light, GLenum pname, GLfloat param);
	void Lightfv(GLenum light, GLenum pname, const GLfloat *params);
	void Lighti(GLenum light, GLenum pname, GLint param);
	void Lightiv(GLenum light, GLenum pname, const GLint *params);
	void LineStipple(GLint factor, GLushort pattern);
	void LineWidth(GLfloat width);
	void ListBase(GLuint base);
	void LoadIdentity(void);
	void LoadMatrixd(const GLdouble *m);
	void LoadMatrixf(const GLfloat *m);
	void LoadName(GLuint name);
	void LogicOp(GLenum opcode);
	void Map1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
	void Map1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
	void Map2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
	void Map2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
	void MapGrid1d(GLint un, GLdouble u1, GLdouble u2);
	void MapGrid1f(GLint un, GLfloat u1, GLfloat u2);
	void MapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
	void MapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
	void Materialf(GLenum face, GLenum pname, GLfloat param);
	void Materialfv(GLenum face, GLenum pname, const GLfloat *params);
	void Materiali(GLenum face, GLenum pname, GLint param);
	void Materialiv(GLenum face, GLenum pname, const GLint *params);
	void MatrixMode(GLenum mode);
	void MultMatrixd(const GLdouble *m);
	void MultMatrixf(const GLfloat *m);
	void NewList(GLuint list, GLenum mode);
	void Normal3b(GLbyte nx, GLbyte ny, GLbyte nz);
	void Normal3bv(const GLbyte *v);
	void Normal3d(GLdouble nx, GLdouble ny, GLdouble nz);
	void Normal3dv(const GLdouble *v);
	void Normal3f(GLfloat nx, GLfloat ny, GLfloat nz);
	void Normal3fv(const GLfloat *v);
	void Normal3i(GLint nx, GLint ny, GLint nz);
	void Normal3iv(const GLint *v);
	void Normal3s(GLshort nx, GLshort ny, GLshort nz);
	void Normal3sv(const GLshort *v);
	void NormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer);
	void Ortho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
	void PassThrough(GLfloat token);
	void PixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values);
	void PixelMapuiv(GLenum map, GLsizei mapsize, const GLuint *values);
	void PixelMapusv(GLenum map, GLsizei mapsize, const GLushort *values);
	void PixelStoref(GLenum pname, GLfloat param);
	void PixelStorei(GLenum pname, GLint param);
	void PixelTransferf(GLenum pname, GLfloat param);
	void PixelTransferi(GLenum pname, GLint param);
	void PixelZoom(GLfloat xfactor, GLfloat yfactor);
	void PointSize(GLfloat size);
	void PolygonMode(GLenum face, GLenum mode);
	void PolygonOffset(GLfloat factor, GLfloat units);
	void PolygonStipple(const GLubyte *mask);
	void PopAttrib(void);
	void PopClientAttrib(void);
	void PopMatrix(void);
	void PopName(void);
	void PrioritizeTextures(GLsizei n, const GLuint *textures, const GLclampf *priorities);
	void PushAttrib(GLbitfield mask);
	void PushClientAttrib(GLbitfield mask);
	void PushMatrix(void);
	void PushName(GLuint name);
	void RasterPos2d(GLdouble x, GLdouble y);
	void RasterPos2dv(const GLdouble *v);
	void RasterPos2f(GLfloat x, GLfloat y);
	void RasterPos2fv(const GLfloat *v);
	void RasterPos2i(GLint x, GLint y);
	void RasterPos2iv(const GLint *v);
	void RasterPos2s(GLshort x, GLshort y);
	void RasterPos2sv(const GLshort *v);
	void RasterPos3d(GLdouble x, GLdouble y, GLdouble z);
	void RasterPos3dv(const GLdouble *v);
	void RasterPos3f(GLfloat x, GLfloat y, GLfloat z);
	void RasterPos3fv(const GLfloat *v);
	void RasterPos3i(GLint x, GLint y, GLint z);
	void RasterPos3iv(const GLint *v);
	void RasterPos3s(GLshort x, GLshort y, GLshort z);
	void RasterPos3sv(const GLshort *v);
	void RasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void RasterPos4dv(const GLdouble *v);
	void RasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void RasterPos4fv(const GLfloat *v);
	void RasterPos4i(GLint x, GLint y, GLint z, GLint w);
	void RasterPos4iv(const GLint *v);
	void RasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w);
	void RasterPos4sv(const GLshort *v);
	void ReadBuffer(GLenum mode);
	void ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
	void Rectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
	void Rectdv(const GLdouble *v1, const GLdouble *v2);
	void Rectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
	void Rectfv(const GLfloat *v1, const GLfloat *v2);
	void Recti(GLint x1, GLint y1, GLint x2, GLint y2);
	void Rectiv(const GLint *v1, const GLint *v2);
	void Rects(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
	void Rectsv(const GLshort *v1, const GLshort *v2);
	GLint RenderMode(GLenum mode);
	void Rotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
	void Rotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	void Scaled(GLdouble x, GLdouble y, GLdouble z);
	void Scalef(GLfloat x, GLfloat y, GLfloat z);
	void Scissor(GLint x, GLint y, GLsizei width, GLsizei height);
	void SelectBuffer(GLsizei size, GLuint *buffer);
	void ShadeModel(GLenum mode);
	void StencilFunc(GLenum func, GLint ref, GLuint mask);
	void StencilMask(GLuint mask);
	void StencilOp(GLenum fail, GLenum zfail, GLenum zpass);
	void TexCoord1d(GLdouble s);
	void TexCoord1dv(const GLdouble *v);
	void TexCoord1f(GLfloat s);
	void TexCoord1fv(const GLfloat *v);
	void TexCoord1i(GLint s);
	void TexCoord1iv(const GLint *v);
	void TexCoord1s(GLshort s);
	void TexCoord1sv(const GLshort *v);
	void TexCoord2d(GLdouble s, GLdouble t);
	void TexCoord2dv(const GLdouble *v);
	void TexCoord2f(GLfloat s, GLfloat t);
	void TexCoord2fv(const GLfloat *v);
	void TexCoord2i(GLint s, GLint t);
	void TexCoord2iv(const GLint *v);
	void TexCoord2s(GLshort s, GLshort t);
	void TexCoord2sv(const GLshort *v);
	void TexCoord3d(GLdouble s, GLdouble t, GLdouble r);
	void TexCoord3dv(const GLdouble *v);
	void TexCoord3f(GLfloat s, GLfloat t, GLfloat r);
	void TexCoord3fv(const GLfloat *v);
	void TexCoord3i(GLint s, GLint t, GLint r);
	void TexCoord3iv(const GLint *v);
	void TexCoord3s(GLshort s, GLshort t, GLshort r);
	void TexCoord3sv(const GLshort *v);
	void TexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	void TexCoord4dv(const GLdouble *v);
	void TexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	void TexCoord4fv(const GLfloat *v);
	void TexCoord4i(GLint s, GLint t, GLint r, GLint q);
	void TexCoord4iv(const GLint *v);
	void TexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q);
	void TexCoord4sv(const GLshort *v);
	void TexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	void TexEnvf(GLenum target, GLenum pname, GLfloat param);
	void TexEnvfv(GLenum target, GLenum pname, const GLfloat *params);
	void TexEnvi(GLenum target, GLenum pname, GLint param);
	void TexEnviv(GLenum target, GLenum pname, const GLint *params);
	void TexGend(GLenum coord, GLenum pname, GLdouble param);
	void TexGendv(GLenum coord, GLenum pname, const GLdouble *params);
	void TexGenf(GLenum coord, GLenum pname, GLfloat param);
	void TexGenfv(GLenum coord, GLenum pname, const GLfloat *params);
	void TexGeni(GLenum coord, GLenum pname, GLint param);
	void TexGeniv(GLenum coord, GLenum pname, const GLint *params);
	void TexImage1D(TextureTarget target, GLint level, PixelInternalFormat internalformat, GLsizei width, GLint border, PixelFormat format, PixelType type, const GLvoid *pixels);
	void TexImage2D(TextureTarget target, GLint level, PixelInternalFormat internalformat, GLsizei width, GLsizei height, GLint border, PixelFormat format, PixelType type, const GLvoid *pixels);
	void TexParameter(TextureTarget target, TextureParameterName pname, GLfloat param);
	void TexParameter(TextureTarget target, TextureParameterName pname, const GLfloat *params);
	void TexParameter(TextureTarget target, TextureParameterName pname, GLint param);
	void TexParameter(TextureTarget target, TextureParameterName pname, TextureMinFilter param);
	void TexParameter(TextureTarget target, TextureParameterName pname, TextureMagFilter param);
	void TexParameter(TextureTarget target, TextureParameterName pname, TextureWrapMode param);
	void TexParameter(TextureTarget target, TextureParameterName pname, const GLint *params);
	void TexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
	void TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
	void Translated(GLdouble x, GLdouble y, GLdouble z);
	void Translatef(GLfloat x, GLfloat y, GLfloat z);
	void Vertex2d(GLdouble x, GLdouble y);
	void Vertex2dv(const GLdouble *v);
	void Vertex2f(GLfloat x, GLfloat y);
	void Vertex2fv(const GLfloat *v);
	void Vertex2i(GLint x, GLint y);
	void Vertex2iv(const GLint *v);
	void Vertex2s(GLshort x, GLshort y);
	void Vertex2sv(const GLshort *v);
	void Vertex3d(GLdouble x, GLdouble y, GLdouble z);
	void Vertex3dv(const GLdouble *v);
	void Vertex3f(GLfloat x, GLfloat y, GLfloat z);
	void Vertex3fv(const GLfloat *v);
	void Vertex3i(GLint x, GLint y, GLint z);
	void Vertex3iv(const GLint *v);
	void Vertex3s(GLshort x, GLshort y, GLshort z);
	void Vertex3sv(const GLshort *v);
	void Vertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void Vertex4dv(const GLdouble *v);
	void Vertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void Vertex4fv(const GLfloat *v);
	void Vertex4i(GLint x, GLint y, GLint z, GLint w);
	void Vertex4iv(const GLint *v);
	void Vertex4s(GLshort x, GLshort y, GLshort z, GLshort w);
	void Vertex4sv(const GLshort *v);
	void VertexPointer(GLint size, VertexPointerType type, GLsizei stride, const GLvoid* pointer);
	void Viewport(GLint x, GLint y, GLsizei width, GLsizei height);

	// >>> GL EXT

	// GL_VERSION_1_3
	void ActiveTexture(TextureUnit texture);
	void SampleCoverage(GLfloat value, GLboolean invert);
	void CompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
	void CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
	void CompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
	void CompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
	void CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
	void CompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
	void GetCompressedTexImage(GLenum target, GLint level, GLvoid *img);
	void ClientActiveTexture(GLenum texture);
	void MultiTexCoord1d(GLenum target, GLdouble s);
	void MultiTexCoord1dv(GLenum target, const GLdouble *v);
	void MultiTexCoord1f(GLenum target, GLfloat s);
	void MultiTexCoord1fv(GLenum target, const GLfloat *v);
	void MultiTexCoord1i(GLenum target, GLint s);
	void MultiTexCoord1iv(GLenum target, const GLint *v);
	void MultiTexCoord1s(GLenum target, GLshort s);
	void MultiTexCoord1sv(GLenum target, const GLshort *v);
	void MultiTexCoord2d(GLenum target, GLdouble s, GLdouble t);
	void MultiTexCoord2dv(GLenum target, const GLdouble *v);
	void MultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
	void MultiTexCoord2fv(GLenum target, const GLfloat *v);
	void MultiTexCoord2i(GLenum target, GLint s, GLint t);
	void MultiTexCoord2iv(GLenum target, const GLint *v);
	void MultiTexCoord2s(GLenum target, GLshort s, GLshort t);
	void MultiTexCoord2sv(GLenum target, const GLshort *v);
	void MultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r);
	void MultiTexCoord3dv(GLenum target, const GLdouble *v);
	void MultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r);
	void MultiTexCoord3fv(GLenum target, const GLfloat *v);
	void MultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r);
	void MultiTexCoord3iv(GLenum target, const GLint *v);
	void MultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r);
	void MultiTexCoord3sv(GLenum target, const GLshort *v);
	void MultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	void MultiTexCoord4dv(GLenum target, const GLdouble *v);
	void MultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	void MultiTexCoord4fv(GLenum target, const GLfloat *v);
	void MultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q);
	void MultiTexCoord4iv(GLenum target, const GLint *v);
	void MultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
	void MultiTexCoord4sv(GLenum target, const GLshort *v);
	void LoadTransposeMatrixf(const GLfloat *m);
	void LoadTransposeMatrixd(const GLdouble *m);
	void MultTransposeMatrixf(const GLfloat *m);
	void MultTransposeMatrixd(const GLdouble *m);

	// GL_VERSION_1_5
	void GenQueries(GLsizei n, GLuint *ids);
	void DeleteQueries(GLsizei n, const GLuint *ids);
	GLboolean IsQuery(GLuint id);
	void BeginQuery(GLenum target, GLuint id);
	void EndQuery(GLenum target);
	void GetQueryiv(GLenum target, GLenum pname, GLint *params);
	void GetQueryObjectiv(GLuint id, GLenum pname, GLint *params);
	void GetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params);
	void BindBuffer(BufferTarget target, GLuint buffer);
	void DeleteBuffers(GLsizei n, const GLuint *buffers);
	void DeleteBuffer(GLuint buffer) { DeleteBuffers(1, &buffer); }
	void GenBuffers(GLsizei n, GLuint *buffers);
	GLuint GenBuffer() { GLuint buffer; GenBuffers(1, &buffer); return buffer; }
	GLboolean IsBuffer(BufferTarget buffer);
	void BufferData(BufferTarget target, GLsizeiptr size, const GLvoid *data, BufferUsageHint usage);
	void BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
	void GetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data);
	GLvoid* MapBuffer(GLenum target, GLenum access);
	GLboolean UnmapBuffer(GLenum target);
	void GetBufferParameteriv(GLenum target, GLenum pname, GLint *params);
	void GetBufferPointerv(GLenum target, GLenum pname, GLvoid* *params);

	// GL_VERSION_2_0
	void BlendEquationSeparate(BlendEquationMode modeRGB, BlendEquationMode modeAlpha);
	void DrawBuffers(GLsizei n, const DrawBuffersEnum *bufs);
	void StencilOpSeparate(StencilFace face, ::StencilOp sfail, ::StencilOp dpfail, ::StencilOp dppass);
	void StencilFuncSeparate(StencilFace face, StencilFunction func, GLint ref, GLuint mask);
	void StencilMaskSeparate(GLenum face, GLuint mask);
	void AttachShader(GLuint program, GLuint shader);
	void BindAttribLocation(GLuint program, GLuint index, const GLchar *name);
	void CompileShader(GLuint shader);
	GLuint CreateProgram(void);
	GLuint CreateShader(ShaderType type);
	void DeleteProgram(GLuint program);
	void DeleteShader(GLuint shader);
	void DetachShader(GLuint program, GLuint shader);
	void DisableVertexAttribArray(GLuint index);
	void EnableVertexAttribArray(GLuint index);
	void GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	void GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	void GetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *obj);
	GLint GetAttribLocation(GLuint program, const GLchar *name);
	void GetProgramiv(GLuint program, GetProgramParameterName pname, GLint *params);
	void GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	std::string GetProgramInfoLog(GLuint program);
	void GetShaderiv(GLuint shader, ShaderParameter pname, GLint *params);
	void GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	std::string GetShaderInfoLog(GLuint shader);
	void GetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
	GLint GetUniformLocation(GLuint program, const GLchar *name);
	void GetUniformfv(GLuint program, GLint location, GLfloat *params);
	void GetUniformiv(GLuint program, GLint location, GLint *params);
	void GetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params);
	void GetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params);
	void GetVertexAttribiv(GLuint index, GLenum pname, GLint *params);
	void GetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid* *pointer);
	GLboolean IsProgram(GLuint program);
	GLboolean IsShader(GLuint shader);
	void LinkProgram(GLuint program);
	void ShaderSource(GLuint shader, GLsizei count, const GLchar* const *string, const GLint *length);
	void UseProgram(GLuint program);
	void Uniform1f(GLint location, GLfloat v0);
	void Uniform2f(GLint location, GLfloat v0, GLfloat v1);
	void Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	void Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	void Uniform1i(GLint location, GLint v0);
	void Uniform2i(GLint location, GLint v0, GLint v1);
	void Uniform3i(GLint location, GLint v0, GLint v1, GLint v2);
	void Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	void Uniform1fv(GLint location, GLsizei count, const GLfloat *value);
	void Uniform2fv(GLint location, GLsizei count, const GLfloat *value);
	void Uniform3fv(GLint location, GLsizei count, const GLfloat *value);
	void Uniform4fv(GLint location, GLsizei count, const GLfloat *value);
	void Uniform1iv(GLint location, GLsizei count, const GLint *value);
	void Uniform2iv(GLint location, GLsizei count, const GLint *value);
	void Uniform3iv(GLint location, GLsizei count, const GLint *value);
	void Uniform4iv(GLint location, GLsizei count, const GLint *value);
	void UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void ValidateProgram(GLuint program);
	void VertexAttrib1d(GLuint index, GLdouble x);
	void VertexAttrib1dv(GLuint index, const GLdouble *v);
	void VertexAttrib1f(GLuint index, GLfloat x);
	void VertexAttrib1fv(GLuint index, const GLfloat *v);
	void VertexAttrib1s(GLuint index, GLshort x);
	void VertexAttrib1sv(GLuint index, const GLshort *v);
	void VertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
	void VertexAttrib2dv(GLuint index, const GLdouble *v);
	void VertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
	void VertexAttrib2fv(GLuint index, const GLfloat *v);
	void VertexAttrib2s(GLuint index, GLshort x, GLshort y);
	void VertexAttrib2sv(GLuint index, const GLshort *v);
	void VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	void VertexAttrib3dv(GLuint index, const GLdouble *v);
	void VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
	void VertexAttrib3fv(GLuint index, const GLfloat *v);
	void VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
	void VertexAttrib3sv(GLuint index, const GLshort *v);
	void VertexAttrib4Nbv(GLuint index, const GLbyte *v);
	void VertexAttrib4Niv(GLuint index, const GLint *v);
	void VertexAttrib4Nsv(GLuint index, const GLshort *v);
	void VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	void VertexAttrib4Nubv(GLuint index, const GLubyte *v);
	void VertexAttrib4Nuiv(GLuint index, const GLuint *v);
	void VertexAttrib4Nusv(GLuint index, const GLushort *v);
	void VertexAttrib4bv(GLuint index, const GLbyte *v);
	void VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void VertexAttrib4dv(GLuint index, const GLdouble *v);
	void VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void VertexAttrib4fv(GLuint index, const GLfloat *v);
	void VertexAttrib4iv(GLuint index, const GLint *v);
	void VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	void VertexAttrib4sv(GLuint index, const GLshort *v);
	void VertexAttrib4ubv(GLuint index, const GLubyte *v);
	void VertexAttrib4uiv(GLuint index, const GLuint *v);
	void VertexAttrib4usv(GLuint index, const GLushort *v);
	void VertexAttribPointer(GLuint index, GLint size, VertexAttribPointerType type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);

	GLboolean IsRenderbuffer(GLuint renderbuffer);
	void BindRenderbuffer(GLenum target, GLuint renderbuffer);
	void DeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers);
	void GenRenderbuffers(GLsizei n, GLuint *renderbuffers);
	void RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	void GetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params);
	GLboolean IsFramebuffer(GLuint framebuffer);
	void BindFramebuffer(GLenum target, GLuint framebuffer);
	void DeleteFramebuffers(GLsizei n, const GLuint *framebuffers);
	void GenFramebuffers(GLsizei n, GLuint *framebuffers);
	GLuint GenFramebuffer();
	GLenum CheckFramebufferStatus(GLenum target);
	void FramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	void FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	void FramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	void FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	void GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params);
	void GenerateMipmap(GenerateMipmapTarget target);
	void BlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	void RenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	void FramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);

	void GetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary);
	void ProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length);
	void ProgramParameteri(GLuint program, ProgramParameterName pname, GLint value);
} GL;

#endif