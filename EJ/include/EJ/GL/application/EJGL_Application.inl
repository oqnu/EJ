EJGL_NAMESPACE_BEGIN

EJGL_INLINE std::string EJGLApplication::toString() const noexcept {
	return std::string("[Application]");
}

EJ_INLINE EJGLBaseObject* EJGLApplication::clone() const noexcept {
	EJGL_ASSERT(false && "You shouldn't clone application");
	return nullptr;
};

EJGL_INLINE void EJGLApplication::swap(EJGLApplication& obj_) noexcept {
	EJGL_ASSERT(false);
}

EJGL_INLINE void EJGLApplication::loadGlad() const {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(-1);
	}
}

EJGL_INLINE EJGLApplication& EJGLApplication::getInstance() {
	static EJGLApplication s_instance;
	return s_instance;
}

EJGL_INLINE glfw::WindowHints EJGLApplication::getDefaultHint() {
	return glfw::WindowHints{
		.resizable				= true,
		.visible				= true,
		.decorated				= true,
		.focused				= true,
		.autoIconify			= true,
		.floating				= false,
		.maximized				= false,
		.centerCursor			= true,
		.transparentFramebuffer	= false,//
		.focusOnShow			= true,
		.scaleToMonitor			= false,

		.redBits		= 8,
		.greenBits		= 8,
		.blueBits		= 8,
		.alphaBits		= 8,
		.depthBits		= 24,
		.stencilBits	= 8,
		.accumRedBits	= 0,
		.accumGreenBits	= 0,
		.accumBlueBits	= 0,
		.accumAlphaBits	= 0,

		.auxBuffers		= 0,
		.samples		= 0,
		.refreshRate	= glfw::dontCare,
		.stereo			= false,
		.srgbCapable	= false,
		.doubleBuffer	= true,

		.clientApi				= glfw::ClientApi::OpenGl,
		.contextCreationApi		= glfw::ContextCreationApi::Native,
		.contextVersionMajor	= 4,//
		.contextVersionMinor	= 6,//
		.contextRobustness		= glfw::ContextRobustness::NoRobustness,
		.contextReleaseBehavior = glfw::ContextReleaseBehavior::Any,
		.openglForwardCompat	= true,//
		.openglDebugContext		= false,
		.openglProfile			= glfw::OpenGlProfile::Core,//

		.cocoaRetinaFramebuffer = true,
		.cocoaFrameName			= "",
		.cocoaGraphicsSwitching = false,

		.x11ClassName		= "",
		.x11InstanceName	= "",
	};
}

EJGL_NAMESPACE_END
