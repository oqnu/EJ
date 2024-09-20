#ifndef EJGL_CAMERA_HPP
#define EJGL_CAMERA_HPP

//
// Tips:
//

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_BaseObject.hpp"
#include "../utils/EJGL_enum.hpp"

#include "../matrix/EJGL_ProjectionMatrix.hpp"
#include "../matrix/EJGL_ViewMatrix.hpp"

#include <glfwpp/window.h>
#include <functional>
#include <bitset>

EJGL_NAMESPACE_BEGIN

class EJGLWindow;

class EJGLCamera : public EJGLBaseObject
{
public:
	using WindowSizeCBT = ::std::function<void(EJGLWindow&, int, int)>;

	using KeyCode = ::glfw::KeyCode;
	using KeyState = ::glfw::KeyState;
	using ModifierKeyBit = ::glfw::ModifierKeyBit;
	using MouseButton = ::glfw::MouseButton;
	using MouseButtonState = ::glfw::MouseButtonState;
	using KeyCBT = ::std::function<void(EJGLWindow&, KeyCode, int, KeyState, ModifierKeyBit)>;
	using MouseButtonCBT = ::std::function<void(EJGLWindow&, MouseButton, MouseButtonState, ModifierKeyBit)>;
	using MouseMoveCBT = ::std::function<void(EJGLWindow&, double, double)>;
	using ScrollCBT = ::std::function<void(EJGLWindow&, double, double)>;

public:
	EJGLCamera(EJGLWindow* window_) :
		_window{ window_ },
		_view{ nullptr }, 
		_projection{ nullptr }
	{}
	EJGLCamera(const EJGLCamera& obj_);
	EJGLCamera(EJGLCamera&& obj_) noexcept;
	virtual ~EJGLCamera();

	EJGLCamera& operator=(EJGLCamera obj_);

	virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLCamera, *this);

	EJGL_INLINE void swap(EJGLCamera& obj_) noexcept;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(bool, isWindowValid, _window != nullptr);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(bool, isViewMatrixValid, _view != nullptr);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(bool, isProjectionMatrixValid, _projection != nullptr);

	EJGL_INLINE EJ_M_CONST_GET_FUNC(const EJGLWindow*, getWindow, _window);
	template<typename ViewMatrixType = EJGLViewMatrix>
	EJGL_INLINE EJ_M_CONST_GET_FUNC(const ViewMatrixType*, getViewMatrix, static_cast<ViewMatrixType*>(_view));
	template<typename ProjectionMatrixType = EJGLProjectionMatrix>
	EJGL_INLINE EJ_M_CONST_GET_FUNC(const ProjectionMatrixType*, getProjectionMatrix, static_cast<ProjectionMatrixType*>(_projection));

	EJGL_INLINE EJ_M_GET_FUNC(EJGLWindow*, getWindow, _window);
	template<typename ViewMatrixType = EJGLViewMatrix>
	EJGL_INLINE EJ_M_GET_FUNC(ViewMatrixType*, getViewMatrix, static_cast<ViewMatrixType*>(_view));
	template<typename ProjectionMatrixType = EJGLProjectionMatrix>
	EJGL_INLINE EJ_M_GET_FUNC(ProjectionMatrixType*, getProjectionMatrix, static_cast<ProjectionMatrixType*>(_projection));

	EJGL_INLINE EJ_M_CONST_GET_FUNC(const WindowSizeCBT, getWindowSizeCB, _windowSizeCB);

	EJGL_INLINE EJ_M_CONST_GET_FUNC(const KeyCBT, getKeyCB, _keyCB);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(const MouseButtonCBT, getMouseButtonCB, _mouseButtonCB);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(const MouseMoveCBT, getMouseMoveCB, _mouseMoveCB);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(const ScrollCBT, getScrollCB, _scrollCB);

	virtual EJGL_INLINE void setWindow(EJGLWindow* window_);
	template<typename ViewMatrixType, typename... Args>
	// Description:
	//	Use setViewMatrix<Type>() to set viewMatrix to type.
	//	Type must inherit from EGL::ViewMatrix.
	// Param args_:
	//	to initilize view, which is new Type(args_...)
	EJGL_INLINE void setViewMatrix(Args... args_);
	template<typename ProjectionMatrixType, typename... Args>
	// Description:
	//	Use setProjectionMatrix<Type>() to set projectionMatrix to type.
	//	Type must inherit from EGL::ProjectionMatrix.
	// Param args_:
	//	to initilize projection, which is new Type(args_...)
	EJGL_INLINE void setProjectionMatrix(Args... args_);

	// about camera
	//EJGL_INLINE virtual EJ_M_CONST_GET_FUNC(glm::vec3, getCameraPos, _scrollCB);

	// you need to call update() before this, or it might be wrong
	EJGL_INLINE glm::vec3 screen2World(const glm::vec2& scPos_) const {
		return _view->toGlm() * _projection->toGlm() * glm::vec4(scPos_, 0, 1);
	}

protected:
	WindowSizeCBT _windowSizeCB = nullptr;

	KeyCBT _keyCB = nullptr;
	MouseButtonCBT _mouseButtonCB = nullptr;
	MouseMoveCBT _mouseMoveCB = nullptr;
	ScrollCBT _scrollCB = nullptr;

private:
	EJGLWindow* _window;
	EJGLViewMatrix* _view;
	EJGLProjectionMatrix* _projection;

	EJGL_INLINE void _deleteViewMatrix();
	EJGL_INLINE void _deleteProjectionMatrix();

};

EJGL_NAMESPACE_END

#include "EJGL_Camera.inl"

#endif // EJGL_CAMERA_HPP