#ifndef EJGL_CONFIG_HPP
#define EJGL_CONFIG_HPP

#include "../../utils/EJ_Config.hpp"

// include opengl header here
#include <glad/glad.h>
#include <cassert>
#include <iostream>

#define EJGL_NAMESPACE_BEGIN EJ_NAMESPACE_BEGIN namespace GL {
#define EJGL_NAMESPACE_END EJ_NAMESPACE_END }
#define _EJGL _EJ GL::

#define EJGL_INLINE EJ_INLINE

// -------------------------------------------------
// options
// -------------------------------------------------
// if you want enum to be enum class, change this to "#define ENUM_STRONG_TYPE_DECLAR class"
#define EJGL_ENUM_STRONG_TYPE_DECLAR 

#define EJGL_ERR_STREAM std::cerr

// -------------------------------------------------
// debug
// -------------------------------------------------
#ifdef EJ_DEBUG
#define EJGL_DEBUG
#endif

// to use EJGL_CALL
#ifdef EJGL_DEBUG
#define EJGL_USE_GLCALL
#endif // EJGL_DEBUG

// assert
#ifdef EJGL_DEBUG
#define EJGL_ASSERT(expression) \
	assert(expression)
#else
#define EJGL_ASSERT(expression)
#endif // EJGL_DEBUG

EJGL_NAMESPACE_BEGIN
static void EJGLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool EJGLLogCall(const char* function, const char* program, int line)
{
	while (GLenum error = glGetError())
	{
		EJGL_ERR_STREAM << "[OpenGL Error] (" << error << ") : " << program << " : " << line << std::endl;
		return false;
	}
	return true;
}
EJGL_NAMESPACE_END

#ifdef EJGL_USE_GLCALL
#define EJGL_CALL(x) \
	EJGLClearError();\
	x;\
	EJGL_ASSERT(EJGLLogCall(#x, __FILE__, __LINE__))
#else
#define EJGL_CALL(x) \
	x;
#endif // USE_EJGL_CALL

//
// define this to enable asserts that help you to check whether the binding object is you are useing now
//
#define EJGL_USE_DEBUG_HELPER

//
// define this to keep source code of shader
//
#define EJGL_KEEP_SHADER_SRC

//
// define this to that shader program save uniform variable location for better performance
//
#define EJGL_KEEP_UNIFORM_LOCATION

#endif