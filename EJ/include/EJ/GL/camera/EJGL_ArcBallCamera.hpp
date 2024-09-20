#ifndef EJGL_ARCBALLCAMERA_HPP
#define EJGL_ARCBALLCAMERA_HPP

//
// Tips:
//	- mouse wheel to resize
//	- right click and drag to move
//	- mouse middle to return center
//	1. in defalut this camera has a ratio that 1px = 1 in world position
//	2. the ratio will change after you resize
//	3. (0, 0) will be the center of window before you move
//	4. ortho projection's center(l/2+r/2, t/2+b/2) always equal (0, 0)
//

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_BaseObject.hpp"
#include "../utils/EJGL_enum.hpp"

#include "EJGL_Camera.hpp"

#include <glm/vec2.hpp>

EJGL_NAMESPACE_BEGIN

class EJGLArcBallCamera : public EJGLCamera
{
public:
	EJGLArcBallCamera(EJGLWindow* window_);
	EJGLArcBallCamera(const EJGLArcBallCamera& obj_) = default;
	EJGLArcBallCamera(EJGLArcBallCamera&& obj_) noexcept = default;
	virtual ~EJGLArcBallCamera() = default;

	EJGLArcBallCamera& operator=(const EJGLArcBallCamera&) = default;

	virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLArcBallCamera, *this);

	// TODO set virtual to this
	//EJGL_INLINE void swap(EJGLCamera& obj_) noexcept;

private:
	bool _isMoving = false;
	glm::vec2 _lastMouse = glm::vec2{};

private:
	glm::vec3 _screenToArcball(const glm::vec2& point) const;

	// static
private:
	static void s_mouseButtonCB(EJGLWindow& window_, MouseButton button_, MouseButtonState action_, ModifierKeyBit mods_);
	static void s_mouseMoveCB(EJGLWindow& window_, double x_, double y_);
	static void s_scrollCB(EJGLWindow& window_, double x_, double y_);

};

EJGL_NAMESPACE_END

#endif EJGL_ARCBALLCAMERA_HPP