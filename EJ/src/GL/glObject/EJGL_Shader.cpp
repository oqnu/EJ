#include "EJ/GL/glObject/EJGL_Shader.hpp"
#include <fstream>
#include <sstream>

EJGL_NAMESPACE_BEGIN

// EJGLShader
EJGLShader::~EJGLShader() {
	deleteShader();
}

EJGLShader& EJGLShader::operator=(const EJGLShader& obj_) {
	_dataPtr = obj_._dataPtr;
	return *this;
}

std::string EJGLShader::toString() const noexcept {
	return std::string("[Shader]{ ID: ") + std::to_string(_dataPtr->_shaderID) + ", Type: " + shaderEnumToStr(_dataPtr->_shaderType) + " }";
}

bool EJGLShader::createShaderByFile(const std::string& filepath_, EJGLShaderType shaderType_) {
	// read file
	std::ifstream ifs(filepath_);
	if (!ifs.is_open()) {
		_dataPtr->_shaderID = 0;
		EJGL_ERR_STREAM << "Cannot open file " << filepath_ << std::endl;
		return false;
	}
	std::stringstream ss;
	ss << ifs.rdbuf();

	// creat EJGLShader
	int length = static_cast<int>(ss.str().size());
	_dataPtr->_shaderType = shaderType_;
	_dataPtr->_shaderID = _createShader(ss.str().c_str(), length);
	if (!_dataPtr->_shaderID) {
		EJGL_ERR_STREAM << "FilePath: " << filepath_ << std::endl;
	}
	return _dataPtr->_shaderID;
}
bool EJGLShader::createShaderBySrc(const char* const src_, const int length_, EJGLShaderType shaderType_) {
	_dataPtr->_shaderType = shaderType_;
	_dataPtr->_shaderID = _createShader(src_, length_);
	return _dataPtr->_shaderID;
}

void EJGLShader::deleteShader() {
	glDeleteShader(_dataPtr->_shaderID);
	_dataPtr->_shaderID = 0;
}

GLuint EJGLShader::_createShader(const char* src_, const int length_) const {
	GLuint EJGLShaderID = glCreateShader(_dataPtr->_shaderType);
	glShaderSource(EJGLShaderID, 1, &src_, &length_);
	glCompileShader(EJGLShaderID);

	int result;
	glGetShaderiv(EJGLShaderID, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(EJGLShaderID, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)malloc(length * sizeof(char));
		glGetShaderInfoLog(EJGLShaderID, length, &length, message);
		EJGL_ERR_STREAM << "Failed to compile " << shaderEnumToStr(_dataPtr->_shaderType) << " EJGLShader!" << std::endl;
		EJGL_ERR_STREAM << message << std::endl;
		glDeleteShader(EJGLShaderID);
		free(message);

		return 0;
	}
	return EJGLShaderID;
}

EJGL_NAMESPACE_END