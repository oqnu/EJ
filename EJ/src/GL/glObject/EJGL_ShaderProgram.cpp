#include "EJ/GL/glObject/EJGL_ShaderProgram.hpp"
#include "EJ/GL/glObject/EJGL_Shader.hpp"

EJGL_NAMESPACE_BEGIN

// shader program
EJGLShaderProgram& EJGLShaderProgram::operator=(const EJGLShaderProgram& obj_) noexcept {
	_dataPtr = obj_._dataPtr;
	return *this;
}

EJGLShaderProgram::~EJGLShaderProgram() noexcept {
	deleteProgram();
}

std::string EJGLShaderProgram::toString() const noexcept {
	return std::string("[ShaderProgram]{ ID: ") + std::to_string(_dataPtr->_programID) + " }";
}

EJGLShader EJGLShaderProgram::attachShaderByFile(const std::string& filepath_, EJGLShaderType shaderType_) const {
	EJGL_ASSERT(isValid() && "Have you create()?");
	EJGLShader rShader;
	if (rShader.createShaderByFile(filepath_, shaderType_)) {
		glAttachShader(_dataPtr->_programID, rShader.getShaderID());
	}
	return rShader;
}
EJGLShader EJGLShaderProgram::attachShaderBySrc(const char* const src, const int length_, EJGLShaderType shaderType_) const {
	EJGL_ASSERT(isValid() && "Have you create()?");
	EJGLShader rShader;
	if (rShader.createShaderBySrc(src, length_, shaderType_)) {
		glAttachShader(_dataPtr->_programID, rShader.getShaderID());
	}
	return rShader;
}

void EJGLShaderProgram::link() {
	EJGL_ASSERT(isValid() && "Have you create()?");
	glLinkProgram(_dataPtr->_programID);

	int result;
	glGetProgramiv(_dataPtr->_programID, GL_LINK_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetProgramiv(_dataPtr->_programID, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)malloc((length + 1) * sizeof(char));
		glGetProgramInfoLog(_dataPtr->_programID, length, &length, message);
		EJGL_ERR_STREAM << "Failed to link program: " << message << std::endl;
		glDeleteProgram(_dataPtr->_programID);
		_dataPtr->_programID = 0;
	}
}

void EJGLShaderProgram::deleteProgram() {
	glDeleteProgram(_dataPtr->_programID);
	_dataPtr->_programID = 0;
}

GLint EJGLShaderProgram::getUniformLocation(const std::string& name_) const {
	EJGL_ASSERT(_dataPtr->_programID);
#ifdef EJGL_KEEP_UNIFORM_LOCATION
	if (_dataPtr->_uniformLocation.find(name_) != _dataPtr->_uniformLocation.end()) {
		return _dataPtr->_uniformLocation[name_];
	}
#endif

	int location = glGetUniformLocation(_dataPtr->_programID, name_.c_str());
	if (location == -1) {
		std::cout << "[EJ][GL][ShaderProgram] Warning: uniform \"" << name_ << "\" doesn't exist!" << std::endl;
	}

#ifdef EJGL_KEEP_UNIFORM_LOCATION
	_dataPtr->_uniformLocation[name_] = location;
#endif
	return location;
}
GLuint EJGLShaderProgram::getUniformBlockIndex(const std::string& name_) const {
	EJGL_ASSERT(isValid() && "Have you create()?");
	return glGetUniformBlockIndex(_dataPtr->_programID, name_.c_str());
}

GLuint EJGLShaderProgram::getUniformBlockIndexAndBind(const std::string& name_, GLuint bindingPoint_) const {
	EJGL_ASSERT(isValid() && "Have you create()?");
	GLuint index = getUniformBlockIndex(name_);
	bindUniformBlock(index, bindingPoint_);
	return index;
}

GLint EJGLShaderProgram::getAttribLocation(const std::string& name_) const {
	return glGetAttribLocation(_dataPtr->_programID, name_.c_str());
}

EJGL_NAMESPACE_END