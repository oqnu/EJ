#ifndef EJGL_ENUM_HPP
#define EJGL_ENUM_HPP

#include "EJGL_config.hpp"

EJGL_NAMESPACE_BEGIN

// Type
namespace EJGLShaderTypeN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLShaderTypeT : GLenum {
		VERTEX          = GL_VERTEX_SHADER,
		FRAGEMENT       = GL_FRAGMENT_SHADER,
		GEOMETRY        = GL_GEOMETRY_SHADER,
		TESS_CONTROL    = GL_TESS_CONTROL_SHADER,
		TESS_EVALUATION = GL_TESS_EVALUATION_SHADER,
		COMPUTE         = GL_COMPUTE_SHADER
	};
}
using EJGLShaderType = EJGLShaderTypeN::EJGLShaderTypeT;

namespace EJGLDataTypeN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLDataTypeT : GLenum {
		BYTE           = GL_BYTE,
		UNSIGNED_BYTE  = GL_UNSIGNED_BYTE,
		SHORT          = GL_SHORT,
		UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
		INT            = GL_INT,
		UNSIGNED_INT   = GL_UNSIGNED_INT,
		FLOAT          = GL_FLOAT,
		DOUBLE         = GL_DOUBLE
	};
}
using EJGLDataType = EJGLDataTypeN::EJGLDataTypeT;

namespace EJGLBufferTypeN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLBufferTypeT : GLenum {
		ARRAY   = GL_ARRAY_BUFFER,
		ELEMENT = GL_ELEMENT_ARRAY_BUFFER,
		UNIFORM = GL_UNIFORM_BUFFER,
		FRAME   = GL_FRAMEBUFFER,
		RENDER  = GL_RENDERBUFFER,
	};
}
using EJGLBufferType = EJGLBufferTypeN::EJGLBufferTypeT;

namespace EJGLTextureTypeN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLTextureTypeT : GLenum {
		_1D                   = GL_TEXTURE_1D,
		_1D_ARRAY             = GL_TEXTURE_1D_ARRAY,
		_2D                   = GL_TEXTURE_2D,
		_2D_ARRAY             = GL_TEXTURE_2D_ARRAY,
		_2D_MULTISAMPLE       = GL_TEXTURE_2D_MULTISAMPLE,
		_2D_MULTISAMPLE_ARRAY = GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
		_3D                   = GL_TEXTURE_3D,
		CUBE_MAP              = GL_TEXTURE_CUBE_MAP,
		CUBE_MAP_ARRAY        = GL_TEXTURE_CUBE_MAP_ARRAY,
		RECTANGLE             = GL_TEXTURE_RECTANGLE
	};
}
using EJGLTextureType = EJGLTextureTypeN::EJGLTextureTypeT;

// Usage
namespace EJGLDataUsageN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLDataUsageT : GLenum {
		STREAM_DRAW  = GL_STREAM_DRAW,
		STREAM_READ  = GL_STREAM_READ,
		STREAM_COPY  = GL_STREAM_COPY,
		STATIC_DRAW  = GL_STATIC_DRAW,
		STATIC_READ  = GL_STATIC_READ,
		STATIC_COPY  = GL_STATIC_COPY,
		DYNAMIC_DRAW = GL_DYNAMIC_DRAW,
		DYNAMIC_READ = GL_DYNAMIC_READ,
		DYNAMIC_COPY = GL_DYNAMIC_COPY
	};
}
using EJGLDataUsage = EJGLDataUsageN::EJGLDataUsageT;

// Option
namespace EJGLEnableOptionN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLEnableOptionT : GLenum {
		DEPTH_TEST                = GL_DEPTH_TEST,
		CULL_FACE                 = GL_CULL_FACE,
		BLEND                     = GL_BLEND,
		VERTEX_PROGRAM_POINT_SIZE = GL_VERTEX_PROGRAM_POINT_SIZE,
		CLIP_DISTANCE0            = GL_CLIP_DISTANCE0,
	};
}
using EJGLEnableOption = EJGLEnableOptionN::EJGLEnableOptionT;

namespace EJGLDrawOptionN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLDrawOptionT : GLenum {
		POINTS         = GL_POINTS,
		LINES          = GL_LINES,
		LINE_LOOP      = GL_LINE_LOOP,
		LINE_STRIP     = GL_LINE_STRIP,
		TRIANGLES      = GL_TRIANGLES,
		TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
		TRIANGLE_FAN   = GL_TRIANGLE_FAN,
		PATCHES        = GL_PATCHES
	};
}
using EJGLDrawOption = EJGLDrawOptionN::EJGLDrawOptionT;

namespace EJGLFaceOptionN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLFaceOptionT : GLenum {
		FRONT_LEFT     = GL_FRONT_LEFT,
		FRONT_RIGHT    = GL_FRONT_RIGHT,
		BACK_LEFT      = GL_BACK_LEFT,
		BACK_RIGHT     = GL_BACK_RIGHT,
		FRONT          = GL_FRONT,
		BACK           = GL_BACK,
		LEFT           = GL_LEFT,
		RIGHT          = GL_RIGHT,
		FRONT_AND_BACK = GL_FRONT_AND_BACK
	};
}
using EJGLFaceOption = EJGLFaceOptionN::EJGLFaceOptionT;

namespace EJGLTextureMinFilterOptionN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLTextureMinFilterOptionT : GLenum {
		NEAREST				   = GL_NEAREST,
		LINEAR				   = GL_LINEAR,
		NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST,
		LINEAR_MIPMAP_NEAREST  = GL_LINEAR_MIPMAP_NEAREST,
		NEAREST_MIPMAP_LINEAR  = GL_NEAREST_MIPMAP_LINEAR,
		LINEAR_MIPMAP_LINEAR   = GL_LINEAR_MIPMAP_LINEAR
	};
}
using EJGLTextureMinFilterOption = EJGLTextureMinFilterOptionN::EJGLTextureMinFilterOptionT;

namespace EJGLTextureMagFilterOptionN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLTextureMagFilterOptionT : GLenum {
		NEAREST				   = GL_NEAREST,
		LINEAR				   = GL_LINEAR,
	};
}
using EJGLTextureMagFilterOption = EJGLTextureMagFilterOptionN::EJGLTextureMagFilterOptionT;

namespace EJGLTextureWarpOptionN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLTextureWarpOptionT : GLenum {
		CLAMP_TO_EDGE		 = GL_CLAMP_TO_EDGE,
		CLAMP_TO_BORDER		 = GL_CLAMP_TO_BORDER,
		MIRRORED_REPEAT		 = GL_MIRRORED_REPEAT,
		REPEAT				 = GL_REPEAT,
		MIRROR_CLAMP_TO_EDGE = GL_MIRROR_CLAMP_TO_EDGE
	};
}
using EJGLTextureWarpOption = EJGLTextureWarpOptionN::EJGLTextureWarpOptionT;

// Mode
namespace EJGLPolygonModeN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLPolygonModeT : GLenum {
		POINT = GL_POINT,
		LINE  = GL_LINE,
		FILL  = GL_FILL,
	};
}
using EJGLPolygonMode = EJGLPolygonModeN::EJGLPolygonModeT;

// Bit
namespace EJGLClearBitN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLClearBitT : GLbitfield {
		DEPTH   = GL_DEPTH_BUFFER_BIT,
		STENCIL = GL_STENCIL_BUFFER_BIT,
		COLOR   = GL_COLOR_BUFFER_BIT
	};
}
using EJGLClearBit = EJGLClearBitN::EJGLClearBitT;

namespace EJGLMapAccessBitN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLMapAccessBitT : GLbitfield {
		READ              = GL_MAP_READ_BIT,
		WRITE             = GL_MAP_WRITE_BIT,
		INVALIDATE_RANGE  = GL_MAP_INVALIDATE_RANGE_BIT,
		INVALIDATE_BUFFER = GL_MAP_INVALIDATE_BUFFER_BIT,
		FLUSH_EXPLICIT    = GL_MAP_FLUSH_EXPLICIT_BIT,
		UNSYNCHRONIZED    = GL_MAP_UNSYNCHRONIZED_BIT
	};
}
using EJGLMapAccessBit = EJGLMapAccessBitN::EJGLMapAccessBitT;

//// Formate
//enum EJGL_ENUM_STRONG_TYPE_DECLAR TextureInternalFormatT : int {
//	// Base
//	DEPTH_COMPONENT = _DEPTH_COMPONENT,
//	DEPTH_STENCIL   = _DEPTH_STENCIL,
//	RED			   	= _RED,  
//	RG			   	= _RG,
//	RGB			   	= _RGB,  
//	RGBA			= _RGBA,
//	// Sized
//	// Compressed
//};
//
//enum EJGL_ENUM_STRONG_TYPE_DECLAR TextureDataFormatT : enum {
//	RED             = _RED,
//	RG              = _RG,
//	RGB             = _RGB,
//	BGR             = _BGR,
//	RGBA            = _RGBA,
//	BGRA            = _BGRA,
//	RED_INTEGER     = _RED_INTEGER,
//	RG_INTEGER      = _RG_INTEGER,
//	RGB_INTEGER     = _RGB_INTEGER,
//	BGR_INTEGER     = _BGR_INTEGER,
//	RGBA_INTEGER    = _RGBA_INTEGER,
//	BGRA_INTEGER    = _BGRA_INTEGER,
//	STENCIL_INDEX   = _STENCIL_INDEX,
//	DEPTH_COMPONENT = _DEPTH_COMPONENT,
//	DEPTH_STENCIL   = _DEPTH_STENCIL,
//};

// Function
namespace EJGLDepthFuncN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLDepthFuncT : GLenum {
		NEVER    = GL_NEVER,
		LESS     = GL_LESS,
		EQUAL    = GL_EQUAL,
		LEQUAL   = GL_LEQUAL,
		GREATER  = GL_GREATER,
		NOTEQUAL = GL_NOTEQUAL,
		GEQUAL   = GL_GEQUAL,
		ALWAYS   = GL_ALWAYS,
	};
}
using EJGLDepthFunc = EJGLDepthFuncN::EJGLDepthFuncT;

// Parameter
namespace EJGLTextureParameterN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EJGLTextureParameterT : GLenum {
		DEPTH_STENCIL_MODE = GL_DEPTH_STENCIL_TEXTURE_MODE,
		BASE_LEVEL		   = GL_TEXTURE_BASE_LEVEL,
		COMPARE_FUNC	   = GL_TEXTURE_COMPARE_FUNC,
		COMPARE_MODE	   = GL_TEXTURE_COMPARE_MODE,
		LOD_BIAS		   = GL_TEXTURE_LOD_BIAS,
		MIN_FILTER		   = GL_TEXTURE_MIN_FILTER,
		MAG_FILTER		   = GL_TEXTURE_MAG_FILTER,
		MIN_LOD			   = GL_TEXTURE_MIN_LOD,
		MAX_LOD			   = GL_TEXTURE_MAX_LOD,
		MAX_LEVEL		   = GL_TEXTURE_MAX_LEVEL,
		SWIZZLE_R		   = GL_TEXTURE_SWIZZLE_R,
		SWIZZLE_G		   = GL_TEXTURE_SWIZZLE_G,
		SWIZZLE_B		   = GL_TEXTURE_SWIZZLE_B,
		SWIZZLE_A		   = GL_TEXTURE_SWIZZLE_A,
		WRAP_S			   = GL_TEXTURE_WRAP_S,
		WRAP_T			   = GL_TEXTURE_WRAP_T,
		WRAP_R			   = GL_TEXTURE_WRAP_R
	};
}
using EJGLTextureParameter = EJGLTextureParameterN::EJGLTextureParameterT;

// Functions
constexpr unsigned int sizeofGLType(EJGLDataType type_) {
	switch (type_)
	{
	case EJGLDataType::BYTE:
		return sizeof(GLbyte);
	case EJGLDataType::UNSIGNED_BYTE:
		return sizeof(GLubyte);
	case EJGLDataType::SHORT:
		return sizeof(GLshort);
	case EJGLDataType::UNSIGNED_SHORT:
		return sizeof(GLushort);
	case EJGLDataType::INT:
		return sizeof(GLint);
	case EJGLDataType::UNSIGNED_INT:
		return sizeof(GLuint);
	case EJGLDataType::FLOAT:
		return sizeof(GLfloat);
	case EJGLDataType::DOUBLE:
		return sizeof(GLdouble);
	default:
		return 0;
	}
}

constexpr std::string shaderEnumToStr(const EJGLShaderType shaderType) {
	switch (shaderType) {
	case EJGLShaderType::VERTEX:
		return "vertex";
	case EJGLShaderType::FRAGEMENT:
		return "fragment";
	case EJGLShaderType::GEOMETRY:
		return "geometry";
	case EJGLShaderType::TESS_CONTROL:
		return "tess control";
	case EJGLShaderType::TESS_EVALUATION:
		return "tess evalution";
	case EJGLShaderType::COMPUTE:
		return "compute";
	}
	return "unknown shader type";
}


	//enum EJGL_ENUM_STRONG_TYPE_DECLAR PixelDataTypeT : enum {
	//	UNSIGNED_BYTE               = _UNSIGNED_BYTE,
	//	BYTE                        = _BYTE,
	//	UNSIGNED_SHORT              = _UNSIGNED_SHORT,
	//	SHORT                       = _SHORT,
	//	UNSIGNED_INT                = _UNSIGNED_INT,
	//	INT                         = _INT,
	//	FLOAT                       = _FLOAT,
	//	UNSIGNED_BYTE_3_3_2         = _UNSIGNED_BYTE_3_3_2,
	//	UNSIGNED_BYTE_2_3_3_REV     = _UNSIGNED_BYTE_2_3_3_REV,
	//	UNSIGNED_SHORT_5_6_5        = _UNSIGNED_SHORT_5_6_5,
	//	UNSIGNED_SHORT_5_6_5_REV    = _UNSIGNED_SHORT_5_6_5_REV,
	//	UNSIGNED_SHORT_4_4_4_4      = _UNSIGNED_SHORT_4_4_4_4,
	//	UNSIGNED_SHORT_4_4_4_4_REV  = _UNSIGNED_SHORT_4_4_4_4_REV,
	//	UNSIGNED_SHORT_5_5_5_1      = _UNSIGNED_SHORT_5_5_5_1,
	//	UNSIGNED_SHORT_1_5_5_5_REV  = _UNSIGNED_SHORT_1_5_5_5_REV,
	//	UNSIGNED_INT_8_8_8_8        = _UNSIGNED_INT_8_8_8_8,
	//	UNSIGNED_INT_8_8_8_8_REV    = _UNSIGNED_INT_8_8_8_8_REV,
	//	UNSIGNED_INT_10_10_10_2     = _UNSIGNED_INT_10_10_10_2,
	//	UNSIGNED_INT_2_10_10_10_REV = _UNSIGNED_INT_2_10_10_10_REV,
	//};



EJGL_NAMESPACE_END

#endif