#include "EJ/GL/GlObject/EJGL_ShaderProgram.hpp"
#include "EJ/Utils/EJ_Utils.hpp"
#include "EJ/GL/GlObject/EJGL_Shader.hpp"

#include <unordered_map>

EJGL_NAMESPACE_BEGIN

#pragma region Impl

class ShaderProgram::_ShaderProgramImpl {
public:
	// construct empty
	_ShaderProgramImpl() noexcept
	{}
	// call create() after construct
	_ShaderProgramImpl(default_create) noexcept
	{
		create();
	}
	// construct with id
	_ShaderProgramImpl(GLuint id_) noexcept :
		_programID(id_)
	{}
	_ShaderProgramImpl(const _ShaderProgramImpl& obj_) = delete;
	_ShaderProgramImpl(_ShaderProgramImpl&& obj_) noexcept = delete;
	_ShaderProgramImpl& operator=(const _ShaderProgramImpl& obj_) = delete;
	_ShaderProgramImpl& operator=(_ShaderProgramImpl&& obj_) noexcept = delete;
	~_ShaderProgramImpl() noexcept {
		deleteProgram();
	}

	_STD string toStringNoHeader() const noexcept {
		return _STD string("{ ID: ") + _EJ toString(_programID) + " }";
	}

	void create() {
		_programID = glCreateProgram();
	}

	Shader attachShaderByFile(_STD string_view filepath_, ShaderType shaderType_) const {
		Shader rShader;
		if (rShader.createShaderByFile(filepath_, shaderType_)) {
			glAttachShader(_programID, rShader.getShaderID());
		}
		return rShader;
	}
	Shader attachShaderBySrc(_STD string_view src_, const int length_, ShaderType shaderType_) const {
		Shader rShader;
		if (rShader.createShaderBySrc(src_, length_, shaderType_)) {
			glAttachShader(_programID, rShader.getShaderID());
		}
		return rShader;
	}
	void attachShader(const Shader& shader_) const {
		EJ_ASSERT(shader_.isValid());
		glAttachShader(_programID, shader_.getShaderID());
	}

	void link() {
		glLinkProgram(_programID);

		int result;
		glGetProgramiv(_programID, GL_LINK_STATUS, &result);
		if (result == GL_FALSE) {
			int length;
			glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)malloc((length + 1) * sizeof(char));
			glGetProgramInfoLog(_programID, length, &length, message);
			EJ_ERR_STREAM << "[EJ][Error] Failed to link program: " << message << std::endl;
			glDeleteProgram(_programID);
			_programID = 0;
		}
	}

	void deleteProgram() {
		glDeleteProgram(_programID);
		_programID = 0;
	}

	void bind() const {
		glUseProgram(_programID);
	}
	void bindUniformBlock(GLuint index_, GLuint bindingPoint_) const {
		glUniformBlockBinding(_programID, index_, bindingPoint_);
	}

	GLint getUniformLocation(const _STD string& name_) const {
#ifdef EJGL_KEEP_UNIFORM_LOCATION
		if (_uniformLocation.find(name_) != _uniformLocation.end()) {
			return _uniformLocation[name_];
		}
#endif
		int location = glGetUniformLocation(_programID, name_.c_str());
		if (location == -1) {
			std::cout << "[EJ][Warning] ShaderProgram: uniform \"" << name_ << "\" doesn't exist!" << std::endl;
		}
#ifdef EJGL_KEEP_UNIFORM_LOCATION
		_uniformLocation[name_] = location;
#endif
		return location;
	}

	GLuint getUniformBlockIndex(_STD string_view name_) const {
		return glGetUniformBlockIndex(_programID, name_.data());
	}

	GLuint getUniformBlockIndexAndBind(_STD string_view name_, GLuint bindingPoint_) const {
		GLuint index = getUniformBlockIndex(name_);
		bindUniformBlock(index, bindingPoint_);
		return index;
	}

	GLint getAttribLocation(_STD string_view name_) const {
		return glGetAttribLocation(_programID, name_.data());
	}

public:
	GLuint _programID = 0;
#ifdef EJGL_KEEP_UNIFORM_LOCATION
	mutable _STD unordered_map<_STD string, int> _uniformLocation;
#endif // EJGL_KEEP_UNIFORM_LOCATION

};

#pragma endregion

#pragma region ShaderProgram
// construct empty
ShaderProgram::ShaderProgram() noexcept :
	_impl{ _STD make_shared<_ShaderProgramImpl>() }
{}
// call create() after construct
ShaderProgram::ShaderProgram(default_create) noexcept :
	_impl{ _STD make_shared<_ShaderProgramImpl>(default_create{}) }
{}
// construct with id
ShaderProgram::ShaderProgram(GLuint id_) noexcept :
	_impl{ _STD make_shared<_ShaderProgramImpl>(id_) }
{}

_STD string ShaderProgram::toStringNoHeader() const noexcept {
	return _impl->toStringNoHeader();
}

_STD string ShaderProgram::toString() const noexcept {
	return _STD string("[EJ][ShaderProgram]") + _impl->toStringNoHeader();
}

void ShaderProgram::swap(ShaderProgram& obj_) noexcept {
	_STD swap(_impl, obj_._impl);
}

bool ShaderProgram::isValid() const {
	return _impl->_programID != 0;
}
GLuint ShaderProgram::getProgramID() const {
	return _impl->_programID;
}

void ShaderProgram::setProgramID(GLuint id_) {
	_impl->_programID = id_;
}

void ShaderProgram::create() {
	return _impl->create();
}

Shader ShaderProgram::attachShaderByFile(_STD string_view filepath_, ShaderType shaderType_) const {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->attachShaderByFile(filepath_, shaderType_);
}
Shader ShaderProgram::attachShaderBySrc(_STD string_view src_, const int length_, ShaderType shaderType_) const {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->attachShaderBySrc(src_, length_, shaderType_);
}

void ShaderProgram::attachShader(const Shader& shader_) const {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->attachShader(shader_);
}

void ShaderProgram::link() {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->link();
}

void ShaderProgram::deleteProgram() {
	_impl->deleteProgram();
}

void ShaderProgram::bind() const {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->bind();
}
void ShaderProgram::bindUniformBlock(GLuint index_, GLuint bindingPoint_) const {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->bindUniformBlock(index_, bindingPoint_);
}

GLint ShaderProgram::getUniformLocation(_STD string_view name_) const {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->getUniformLocation(_STD string(name_));
}
GLuint ShaderProgram::getUniformBlockIndex(_STD string_view name_) const {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->getUniformBlockIndex(name_);
}

GLuint ShaderProgram::getUniformBlockIndexAndBind(_STD string_view name_, GLuint bindingPoint_) const {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->getUniformBlockIndexAndBind(name_, bindingPoint_);
}

GLint ShaderProgram::getAttribLocation(_STD string_view name_) const {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->getAttribLocation(name_);
}

#pragma endregion

EJGL_NAMESPACE_END