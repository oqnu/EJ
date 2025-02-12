#ifndef EJGL_EJGLShaderProgram_HPP
#define EJGL_EJGLShaderProgram_HPP

//
// Tips:
//

#include "../Utils/EJGL_config.hpp"
#include "../../Utils/EJ_Macros.hpp"
#include "../Utils/EJGL_enum.hpp"
#include "../Utils/EJGL_Traits.hpp"
#include "EJGL_Shader.hpp"

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <memory>
#include <string>

EJGL_NAMESPACE_BEGIN

class ShaderProgram
{
private:
	class _ShaderProgramImpl;

public:
    // construct empty
	ShaderProgram() noexcept;
    // call create() after construct
	ShaderProgram(default_create) noexcept;
    // construct with id
	ShaderProgram(GLuint id_) noexcept;
	ShaderProgram(const ShaderProgram& obj_) noexcept = default;
	ShaderProgram& operator=(const ShaderProgram& obj_) noexcept = default;
	virtual ~ShaderProgram() noexcept = default;

	_STD string toStringNoHeader() const noexcept;
	_STD string toString() const noexcept;

	void swap(ShaderProgram& obj_) noexcept;

	bool isValid() const;
	GLuint getProgramID() const;

	void setProgramID(GLuint id_);

	void create();

	Shader attachShaderByFile(_STD string_view filepath_, ShaderType shaderType_) const;
	Shader attachShaderBySrc(_STD string_view src_, const int length_, ShaderType shaderType_) const;
	void attachShader(const Shader& shader_) const;

	void link();

	void deleteProgram();

	void bind() const;
	void bindUniformBlock(GLuint index_, GLuint bindingPoint_) const;

	GLint getUniformLocation(_STD string_view name_) const;
	GLuint getUniformBlockIndex(_STD string_view name_) const;
	GLuint getUniformBlockIndexAndBind(_STD string_view name, GLuint bindingPoint) const;

	EJ_INLINE GLint getAttribLocation(_STD string_view name_) const;

	template<typename T_, typename... Ts_>
	void setUniform(_STD string_view name_, T_ v_, const Ts_&&... vs_) const {
		setUniform(getUniformLocation(name_), _STD forward<T_>(v_), _STD forward<Ts_>(vs_)...);
	}

private:
	_STD shared_ptr<_ShaderProgramImpl> _impl;

public:
	static void unbind() {
		glUseProgram(0);
	}

#define __M_UNIFORM_FUNC_BY_TYPE(TYPE_, TID_) \
    static void setUniform(GLint location_, TYPE_ v0_) { \
        glUniform1##TID_(location_, v0_); \
    } \
    static void setUniform(GLint location_, TYPE_ v0_, TYPE_ v1_) { \
        glUniform2##TID_(location_, v0_, v1_); \
    } \
    static void setUniform(GLint location_, TYPE_ v0_, TYPE_ v1_, TYPE_ v2_) { \
        glUniform3##TID_(location_, v0_, v1_, v2_); \
    } \
    static void setUniform(GLint location_, TYPE_ v0_, TYPE_ v1_, TYPE_ v2_, TYPE_ v3_) { \
        glUniform4##TID_(location_, v0_, v1_, v2_, v3_); \
    } \
    static void setUniform(GLint location_, const ::glm::vec<2, TYPE_>& vec_) { \
        glUniform2##TID_(location_, vec_.x, vec_.y); \
    } \
    static void setUniform(GLint location_, const ::glm::vec<3, TYPE_>& vec_) { \
        glUniform3##TID_(location_, vec_.x, vec_.y, vec_.z); \
    } \
    static void setUniform(GLint location_, const ::glm::vec<4, TYPE_>& vec_) { \
        glUniform4##TID_(location_, vec_.x, vec_.y, vec_.z, vec_.w); \
    }
    __M_UNIFORM_FUNC_BY_TYPE(GLint, i);
    __M_UNIFORM_FUNC_BY_TYPE(GLuint, ui);
    __M_UNIFORM_FUNC_BY_TYPE(GLfloat, f);
#undef __M_UNIFORM_FUNC_BY_TYPE
    static void setUniform(GLint location_, const glm::mat2& m_, bool transpose_ = GL_FALSE) {
        glUniformMatrix2fv(location_, 1, transpose_, &m_[0][0]);
    }
    static void setUniform(GLint location_, const glm::mat3& m_, bool transpose_ = GL_FALSE) {
        glUniformMatrix3fv(location_, 1, transpose_, &m_[0][0]);
    }
    static void setUniform(GLint location_, const glm::mat4& m_, bool transpose_ = GL_FALSE) {
        glUniformMatrix4fv(location_, 1, transpose_, &m_[0][0]);
    }
    static void setUniform(GLint location_, const glm::mat2x3& m_, bool transpose_ = GL_FALSE) {
        glUniformMatrix2x3fv(location_, 1, transpose_, &m_[0][0]);
    }
    static void setUniform(GLint location_, const glm::mat3x2& m_, bool transpose_ = GL_FALSE) {
        glUniformMatrix3x2fv(location_, 1, transpose_, &m_[0][0]);
    }
    static void setUniform(GLint location_, const glm::mat2x4& m_, bool transpose_ = GL_FALSE) {
        glUniformMatrix2x4fv(location_, 1, transpose_, &m_[0][0]);
    }
    static void setUniform(GLint location_, const glm::mat4x2& m_, bool transpose_ = GL_FALSE) {
        glUniformMatrix4x2fv(location_, 1, transpose_, &m_[0][0]);
    }
    static void setUniform(GLint location_, const glm::mat3x4& m_, bool transpose_ = GL_FALSE) {
        glUniformMatrix3x4fv(location_, 1, transpose_, &m_[0][0]);
    }
    static void setUniform(GLint location_, const glm::mat4x3& m_, bool transpose_ = GL_FALSE) {
        glUniformMatrix4x3fv(location_, 1, transpose_, &m_[0][0]);
    }

};

EJGL_NAMESPACE_END

#endif // EJGL_EJGLShaderProgram_HPP