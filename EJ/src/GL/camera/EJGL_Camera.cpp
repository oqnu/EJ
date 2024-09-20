#include "EJ/GL/camera/EJGL_Camera.hpp"

EJGL_NAMESPACE_BEGIN

EJGLCamera::EJGLCamera(const EJGLCamera& obj_) :
	_window{ obj_._window },
	_view{ obj_._view != nullptr ?
		static_cast<EJGLViewMatrix*>(obj_._view->clone()) : nullptr },
	_projection{ obj_._projection != nullptr ?
		static_cast<EJGLProjectionMatrix*>(obj_._projection->clone()) : nullptr }
{}
EJGLCamera::EJGLCamera(EJGLCamera&& obj_) noexcept :
	_window{ obj_._window },
	_view{ obj_._view },
	_projection{ obj_._projection }
{
	_view = nullptr;
	_projection = nullptr;
}
EJGLCamera::~EJGLCamera() {
	_deleteProjectionMatrix();
	_deleteViewMatrix();
}

EJGLCamera& EJGLCamera::operator=(EJGLCamera obj_) {
	swap(obj_);
	return *this;
}

std::string EJGLCamera::toString() const noexcept {
	return "[Camera]{ view: " + _view->toString() + ", projection: " + _projection->toString() + "}";
}

EJGL_NAMESPACE_END