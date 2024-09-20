#ifndef EJGL_EJGLAPPLICATION_HPP
#define EJGL_EJGLAPPLICATION_HPP

//
// Tips:
//

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_BaseObject.hpp"

#include <glfwpp/glfwpp.h>

EJGL_NAMESPACE_BEGIN

class EJGLApplication: public EJGLBaseObject
{
public:
	EJGLApplication(const EJGLApplication& obj_) = delete;
	EJGLApplication(EJGLApplication&& obj_) = delete;
	virtual ~EJGLApplication()
	{}

	EJGLApplication& operator=(const EJGLApplication& obj_) = delete;

	EJGL_INLINE virtual std::string toString() const noexcept;

	EJGL_INLINE virtual EJGLBaseObject* clone() const noexcept override;

	EJGL_INLINE void swap(EJGLApplication& obj_) noexcept;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(const glfw::GlfwLibrary&, getLibrary, _library);

	// call this after bind context
	EJGL_INLINE void loadGlad() const;

protected:
	EJGLApplication() :
		EJGLBaseObject(),
		_library{ glfw::init() }
	{}

private:
	glfw::GlfwLibrary _library;

	// static
public:
	EJGL_INLINE static EJGLApplication& getInstance();

	EJGL_INLINE static glfw::WindowHints getDefaultHint();

};

EJGL_NAMESPACE_END

#include "EJGL_Application.inl"

#endif // EJGL_EJGLAPPLICATION_HPP
