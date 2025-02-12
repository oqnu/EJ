#ifndef EJGL_ENUM_HPP
#define EJGL_ENUM_HPP

#include "EJGL_config.hpp"

EJGL_NAMESPACE_BEGIN

// Type
namespace ShaderTypeN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR ShaderTypeT : GLenum {
		VERTEX          = GL_VERTEX_SHADER,
		FRAGEMENT       = GL_FRAGMENT_SHADER,
		GEOMETRY        = GL_GEOMETRY_SHADER,
		TESS_CONTROL    = GL_TESS_CONTROL_SHADER,
		TESS_EVALUATION = GL_TESS_EVALUATION_SHADER,
		COMPUTE         = GL_COMPUTE_SHADER
	};
}
using ShaderType = ShaderTypeN::ShaderTypeT;

namespace DataTypeN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR DataTypeT : GLenum {
		UNKNOWN		   = 0xffffffff,
		BYTE           = GL_BYTE,
		UNSIGNED_BYTE  = GL_UNSIGNED_BYTE,
		SHORT          = GL_SHORT,
		UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
		INT            = GL_INT,
		UNSIGNED_INT   = GL_UNSIGNED_INT,
		HALF_FLOAT	   = GL_HALF_FLOAT,
		FLOAT          = GL_FLOAT,
		DOUBLE         = GL_DOUBLE
	};
}
using DataType = DataTypeN::DataTypeT;

namespace BufferTypeN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR BufferTypeT : GLenum {
		ARRAY   = GL_ARRAY_BUFFER,
		ELEMENT = GL_ELEMENT_ARRAY_BUFFER,
		UNIFORM = GL_UNIFORM_BUFFER,
		FRAME   = GL_FRAMEBUFFER,
		RENDER  = GL_RENDERBUFFER,
	};
}
using BufferType = BufferTypeN::BufferTypeT;

namespace TextureTypeN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR TextureTypeT : GLenum {
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
using TextureType = TextureTypeN::TextureTypeT;

// Usage
namespace DataUsageN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR DataUsageT : GLenum {
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
using DataUsage = DataUsageN::DataUsageT;

// Option
namespace EnableOptionN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR EnableOptionT : GLenum {
		DEPTH_TEST                = GL_DEPTH_TEST,
		CULL_FACE                 = GL_CULL_FACE,
		BLEND                     = GL_BLEND,
		VERTEX_PROGRAM_POINT_SIZE = GL_VERTEX_PROGRAM_POINT_SIZE,
		CLIP_DISTANCE0            = GL_CLIP_DISTANCE0,
	};
}
using EnableOption = EnableOptionN::EnableOptionT;

namespace DrawOptionN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR DrawOptionT : GLenum {
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
using DrawOption = DrawOptionN::DrawOptionT;

namespace FaceOptionN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR FaceOptionT : GLenum {
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
using FaceOption = FaceOptionN::FaceOptionT;

namespace TextureMinFilterOptionN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR TextureMinFilterOptionT : GLenum {
		NEAREST				   = GL_NEAREST,
		LINEAR				   = GL_LINEAR,
		NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST,
		LINEAR_MIPMAP_NEAREST  = GL_LINEAR_MIPMAP_NEAREST,
		NEAREST_MIPMAP_LINEAR  = GL_NEAREST_MIPMAP_LINEAR,
		LINEAR_MIPMAP_LINEAR   = GL_LINEAR_MIPMAP_LINEAR
	};
}
using TextureMinFilterOption = TextureMinFilterOptionN::TextureMinFilterOptionT;

namespace TextureMagFilterOptionN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR TextureMagFilterOptionT : GLenum {
		NEAREST				   = GL_NEAREST,
		LINEAR				   = GL_LINEAR,
	};
}
using TextureMagFilterOption = TextureMagFilterOptionN::TextureMagFilterOptionT;

namespace TextureWarpOptionN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR TextureWarpOptionT : GLenum {
		CLAMP_TO_EDGE		 = GL_CLAMP_TO_EDGE,
		CLAMP_TO_BORDER		 = GL_CLAMP_TO_BORDER,
		MIRRORED_REPEAT		 = GL_MIRRORED_REPEAT,
		REPEAT				 = GL_REPEAT,
		MIRROR_CLAMP_TO_EDGE = GL_MIRROR_CLAMP_TO_EDGE
	};
}
using TextureWarpOption = TextureWarpOptionN::TextureWarpOptionT;

// Mode
namespace PolygonModeN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR PolygonModeT : GLenum {
		POINT = GL_POINT,
		LINE  = GL_LINE,
		FILL  = GL_FILL,
	};
}
using PolygonMode = PolygonModeN::PolygonModeT;

namespace FrameBufferModeN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR FrameBufferModeT : GLenum {
		NORMAL	  = GL_FRAMEBUFFER,
		DRAW_ONLY = GL_DRAW_FRAMEBUFFER,
		READ_ONLY = GL_READ_FRAMEBUFFER,
	};
}
using FrameBufferMode = FrameBufferModeN::FrameBufferModeT;

// Bit
namespace ClearBitN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR ClearBitT : GLbitfield {
		DEPTH   = GL_DEPTH_BUFFER_BIT,
		STENCIL = GL_STENCIL_BUFFER_BIT,
		COLOR   = GL_COLOR_BUFFER_BIT
	};
}
using ClearBit = ClearBitN::ClearBitT;

namespace MapAccessBitN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR MapAccessBitT : GLbitfield {
		READ              = GL_MAP_READ_BIT,
		WRITE             = GL_MAP_WRITE_BIT,
		INVALIDATE_RANGE  = GL_MAP_INVALIDATE_RANGE_BIT,
		INVALIDATE_BUFFER = GL_MAP_INVALIDATE_BUFFER_BIT,
		FLUSH_EXPLICIT    = GL_MAP_FLUSH_EXPLICIT_BIT,
		UNSYNCHRONIZED    = GL_MAP_UNSYNCHRONIZED_BIT
	};
}
using MapAccessBit = MapAccessBitN::MapAccessBitT;

// Formate
namespace TextureInternalFormatN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR TextureInternalFormatT : GLenum {
		// Base
		DEPTH_COMPONENT = GL_DEPTH_COMPONENT,
		DEPTH_STENCIL   = GL_DEPTH_STENCIL,
		RED             = GL_RED,
		RG              = GL_RG,
		RGB             = GL_RGB,
		RGBA            = GL_RGBA,
		// Sized
		R32F			= GL_R32F,
		// Compressed
	};
}
using TextureInternalFormat = TextureInternalFormatN::TextureInternalFormatT;

namespace TexturePixelDataFormatN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR TexturePixelDataFormatT : GLenum {
		RED             = GL_RED,
		RG              = GL_RG,
		RGB             = GL_RGB,
		BGR             = GL_BGR,
		RGBA            = GL_RGBA,
		BGRA            = GL_BGRA,
		RED_INTEGER     = GL_RED_INTEGER,
		RG_INTEGER      = GL_RG_INTEGER,
		RGB_INTEGER     = GL_RGB_INTEGER,
		BGR_INTEGER     = GL_BGR_INTEGER,
		RGBA_INTEGER    = GL_RGBA_INTEGER,
		BGRA_INTEGER    = GL_BGRA_INTEGER,
		STENCIL_INDEX   = GL_STENCIL_INDEX,
		DEPTH_COMPONENT = GL_DEPTH_COMPONENT,
		DEPTH_STENCIL   = GL_DEPTH_STENCIL,
	};
}
using TexturePixelDataFormat = TexturePixelDataFormatN::TexturePixelDataFormatT;

// Function
namespace DepthFuncN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR DepthFuncT : GLenum {
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
using DepthFunc = DepthFuncN::DepthFuncT;

// Parameter
namespace TextureParameterN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR TextureParameterT : GLenum {
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
using TextureParameter = TextureParameterN::TextureParameterT;

// Factor
namespace BlendFactorN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR BlendFactorT : GLenum {
		ZERO					 = GL_ZERO,
		ONE						 = GL_ONE,
		SRC_COLOR				 = GL_SRC_COLOR,
		ONE_MINUS_SRC_COLOR		 = GL_ONE_MINUS_SRC_COLOR,
		DST_COLOR		   		 = GL_DST_COLOR,
		ONE_MINUS_DST_COLOR		 = GL_ONE_MINUS_DST_COLOR,
		SRC_ALPHA		   		 = GL_SRC_ALPHA,
		ONE_MINUS_SRC_ALPHA		 = GL_ONE_MINUS_SRC_ALPHA,
		DST_ALPHA		   		 = GL_DST_ALPHA,
		ONE_MINUS_DST_ALPHA		 = GL_ONE_MINUS_DST_ALPHA,
		CONSTANT_COLOR			 = GL_CONSTANT_COLOR,
		ONE_MINUS_CONSTANT_COLOR = GL_ONE_MINUS_CONSTANT_COLOR,
		CONSTANT_ALPHA			 = GL_CONSTANT_ALPHA,
		ONE_MINUS_CONSTANT_ALPHA = GL_ONE_MINUS_CONSTANT_ALPHA,
	};
}
using BlendFactor = BlendFactorN::BlendFactorT;

// Status
namespace FrameBufferStatusN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR FrameBufferStatusT : GLenum {
		COMPLETE					  = GL_FRAMEBUFFER_COMPLETE,
		UNDEFINED					  = GL_FRAMEBUFFER_UNDEFINED,
		INCOMPLETE_ATTACHMENT		  = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
		INCOMPLETE_MISSING_ATTACHMENT = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
		INCOMPLETE_DRAW_BUFFER		  = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER,
		INCOMPLETE_READ_BUFFER		  = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER,
		UNSUPPORTED					  = GL_FRAMEBUFFER_UNSUPPORTED,
		INCOMPLETE_MULTISAMPLE		  = GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE,
		INCOMPLETE_LAYER_TARGETS	  = GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS,
	};
}
using FrameBufferStatus = FrameBufferStatusN::FrameBufferStatusT;

// Attachment
namespace FrameBufferAttachmentN {
	enum EJGL_ENUM_STRONG_TYPE_DECLAR FrameBufferAttachmentT : GLenum {
		COLOR0		  = GL_COLOR_ATTACHMENT0,
		COLOR1		  = GL_COLOR_ATTACHMENT1,
		COLOR2		  = GL_COLOR_ATTACHMENT2,
		COLOR3		  = GL_COLOR_ATTACHMENT3,
		COLOR4		  = GL_COLOR_ATTACHMENT4,
		COLOR5		  = GL_COLOR_ATTACHMENT5,
		COLOR6		  = GL_COLOR_ATTACHMENT6,
		COLOR7		  = GL_COLOR_ATTACHMENT7,
		COLOR8		  = GL_COLOR_ATTACHMENT8,
		COLOR9		  = GL_COLOR_ATTACHMENT9,
		COLOR10		  = GL_COLOR_ATTACHMENT10,
		COLOR11		  = GL_COLOR_ATTACHMENT11,
		COLOR12		  = GL_COLOR_ATTACHMENT12,
		COLOR13		  = GL_COLOR_ATTACHMENT13,
		COLOR14		  = GL_COLOR_ATTACHMENT14,
		COLOR15		  = GL_COLOR_ATTACHMENT15,
		DEPTH		  = GL_DEPTH_ATTACHMENT,
		STENCIL		  = GL_STENCIL_ATTACHMENT,
		DEPTH_STENCIL = GL_DEPTH_STENCIL_ATTACHMENT
	};
}
using FrameBufferAttachment = FrameBufferAttachmentN::FrameBufferAttachmentT;

// Functions
constexpr unsigned int sizeofGLType(DataType type_) {
	switch (type_)
	{
	case DataType::BYTE:
		return sizeof(GLbyte);
	case DataType::UNSIGNED_BYTE:
		return sizeof(GLubyte);
	case DataType::SHORT:
		return sizeof(GLshort);
	case DataType::UNSIGNED_SHORT:
		return sizeof(GLushort);
	case DataType::INT:
		return sizeof(GLint);
	case DataType::UNSIGNED_INT:
		return sizeof(GLuint);
	case DataType::FLOAT:
		return sizeof(GLfloat);
	case DataType::DOUBLE:
		return sizeof(GLdouble);
	default:
		return 0;
	}
}

constexpr std::string shaderEnumToStr(const ShaderType shaderType) {
	switch (shaderType) {
	case ShaderType::VERTEX:
		return "vertex";
	case ShaderType::FRAGEMENT:
		return "fragment";
	case ShaderType::GEOMETRY:
		return "geometry";
	case ShaderType::TESS_CONTROL:
		return "tess control";
	case ShaderType::TESS_EVALUATION:
		return "tess evalution";
	case ShaderType::COMPUTE:
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