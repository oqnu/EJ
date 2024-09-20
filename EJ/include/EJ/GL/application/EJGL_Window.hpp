#ifndef EJGL_EJGLWindow_HPP
#define EJGL_EJGLWindow_HPP

//
// Tips:
//

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_BaseObject.hpp"
#include "../utils/EJGL_enum.hpp"

#include <glm/vec2.hpp>
#include <glfwpp/Window.h>

#include <iostream>

EJGL_NAMESPACE_BEGIN

class EJGLCamera;

// Description:
//	This class help you to call camera callbacks
//	Key Esc is set to close the Window
//	Viewport will automatically change when framebuffer resize
class EJGLWindow : public EJGLBaseObject, public glfw::Window
{
private:
	using KeyCode = ::glfw::KeyCode;
	using KeyState = ::glfw::KeyState;
	using ModifierKeyBit = ::glfw::ModifierKeyBit;
	using MouseButton = ::glfw::MouseButton;
	using MouseButtonState = ::glfw::MouseButtonState;

public:
	EJGLWindow(int width_, int height_, const char* name_,
		const glfw::Monitor* monitor_ = nullptr,
		const glfw::Window* share_ = nullptr);
	EJGLWindow(const EJGLWindow& obj_) = delete;
	EJGLWindow(EJGLWindow&& obj_) = delete;
	virtual ~EJGLWindow();

	EJGLWindow& operator=(const EJGLWindow& obj_) = delete;

	virtual std::string toString() const noexcept override;

	EJ_INLINE virtual EJGLBaseObject* clone() const noexcept override;

	EJGL_INLINE void swap(EJGLWindow& obj_) noexcept;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(bool, isCameraValid, _camera != nullptr);

	template<typename CameraType = EJGLCamera>
	EJGL_INLINE EJ_M_CONST_GET_FUNC(const CameraType*, getCamera, static_cast<CameraType*>(_camera));

	template<typename CameraType = EJGLCamera>
	EJGL_INLINE EJ_M_GET_FUNC(CameraType*, getCamera, static_cast<CameraType*>(_camera));

	// Description:
	//	Use setCamera<Type>() to set camera to type.
	//	Type must inherit from EGL::Camera.
	// Param args_:
	//	to initilize camera, which is new Type(args_...)
	template<typename CameraType, typename... Args>
	EJGL_INLINE void setCamera(Args&... args_);

	EJGL_INLINE int getWidth() const;
	EJGL_INLINE int getHeight() const;
	EJGL_INLINE glm::ivec2 getSize() const;
	// get size before resize
	EJGL_INLINE EJ_M_CONST_GET_FUNC(const glm::ivec2&, getLastSize, _lastSize);

	EJGL_INLINE glm::vec2 getCursorPos() const;
	EJGL_INLINE glm::vec2 getReverseYCursorPos() const;
	// this function is for camera
	// reverse x and move to make x = [-w/2, w/2], y = [-h/2, h/2]
	EJGL_INLINE glm::vec2 getReverseXCenteredCursorPos() const;
	EJGL_INLINE glm::vec2 getNDCCursorPos() const;
	EJGL_INLINE glm::vec2 getNDCCursorPos(glm::ivec2&& size_) const;
	EJGL_INLINE glm::vec2 getReverseYNDCCursorPos() const;

	EJGL_INLINE glm::vec2 reversePosY(const glm::vec2& pos_) const;

private:
	EJGLCamera* _camera = nullptr;
	glm::ivec2 _lastSize;

	void _deleteCamera();

	// static
public:
	static EJGLWindow& GetWrapperFromHandle(GLFWwindow* handle_);

	static void onPosEvent(Window&, int, int);
	static void onSizeEvent(Window&, int, int);
	static void onCloseEvent(Window&);
	static void onRefreshEvent(Window&);
	static void onFocusEvent(Window&, bool);
	static void onIconifyEvent(Window&, bool);
	static void onMaximizeEvent(Window&, bool);
	static void onFramebufferSizeEvent(Window&, int, int);
	static void onContentScaleEvent(Window&, float, float);
	static void onKeyEvent(Window&, KeyCode, int, KeyState, ModifierKeyBit);
	static void onCharEvent(Window&, unsigned int);
	static void onMouseEvent(Window&, MouseButton, MouseButtonState, ModifierKeyBit);
	static void onCursorPosEvent(Window&, double, double);
	static void onCursorEnterEvent(Window&, bool);
	static void onScrollEvent(Window&, double, double);
	static void onDropEvent(Window&, std::vector<const char*>);

};

EJGL_NAMESPACE_END

#include "EJGL_Window.inl"

#endif // EJGL_Window_HPP
