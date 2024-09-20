#ifndef EJGL_EJGLShaderProgram_HPP
#define EJGL_EJGLShaderProgram_HPP

//
// Tips:
//

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_BaseObject.hpp"
#include "../utils/EJGL_enum.hpp"
#include "EJGL_Shader.hpp"

#include <unordered_map>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace {
	struct _EJGLShaderProgramElem {
		GLuint _programID;
#ifdef EJGL_KEEP_UNIFORM_LOCATION
		mutable std::unordered_map<std::string, int> _uniformLocation;
#endif // EJGL_KEEP_UNIFORM_LOCATION
	};
}

EJGL_NAMESPACE_BEGIN

class EJGLShaderProgram : public EJGLBaseObject
{
public:
	EJGLShaderProgram(GLuint programID_ = 0) noexcept :
		EJGLBaseObject(),
		_dataPtr(std::make_shared<_EJGLShaderProgramElem>(_EJGLShaderProgramElem{ programID_ }))
	{}
	EJGLShaderProgram(const EJGLShaderProgram& obj_) noexcept :
		EJGLBaseObject(obj_),
		_dataPtr(obj_._dataPtr)
	{}
	EJGLShaderProgram(EJGLShaderProgram&& obj_) noexcept :
		EJGLBaseObject(std::move(obj_)),
		_dataPtr(std::move(obj_._dataPtr))
	{}
	EJGLShaderProgram& operator=(const EJGLShaderProgram& obj_) noexcept;
	virtual ~EJGLShaderProgram() noexcept;

	virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLShaderProgram, *this);

	EJ_INLINE void swap(EJGLShaderProgram& obj_) noexcept;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(bool, isValid, _dataPtr->_programID != 0);

	EJGL_INLINE EJ_M_CONST_GET_FUNC(GLuint, getProgramID, _dataPtr->_programID);

	EJGL_INLINE void setProgramID(GLuint ID_);

	EJGL_INLINE void create();

	EJGLShader attachShaderByFile(const std::string& filepath_, EJGLShaderType shaderType_) const;
	EJGLShader attachShaderBySrc(const char* const src_, const int length_, EJGLShaderType shaderType_) const;
	EJGL_INLINE void attachShader(const EJGLShader& shader_) const;

	void link();

	EJGL_INLINE void deleteProgram();

	EJGL_INLINE void bind() const;
	EJGL_INLINE void bindUniformBlock(GLuint index_, GLuint bindingPoint_) const;

	GLint getUniformLocation(const std::string& name_) const;
	GLuint getUniformBlockIndex(const std::string& name_) const; // TODO add hash to it too
	GLuint getUniformBlockIndexAndBind(const std::string& name, GLuint bindingPoint) const;

	GLint getAttribLocation(const std::string& name_) const;

	template<typename _T, typename... _Ts>
	EJGL_INLINE void setUniform(const std::string& name_, _T v_, _Ts... rv_) const;
	//EJGL_INLINE void setUniform(const std::string& name_, int i_) const;
	//EJGL_INLINE void setUniform(const std::string& name_, unsigned int i_) const;
	//EJGL_INLINE void setUniform(const std::string& name_, float f_) const;
	//EJGL_INLINE void setUniform(const std::string& name_, unsigned int count_, float* fptr_) const;
	//EJGL_INLINE void setUniform(const std::string& name_, const glm::vec2& v2_) const;
	//EJGL_INLINE void setUniform(const std::string& name_, float f1_, float f2_) const;
	//EJGL_INLINE void setUniform(const std::string& name_, const glm::vec3& v3_) const;
	//EJGL_INLINE void setUniform(const std::string& name_, float f1_, float f2_, float f3_) const;
	//EJGL_INLINE void setUniform(const std::string& name_, const glm::vec4& v4_) const;
	//EJGL_INLINE void setUniform(const std::string& name_, float f1_, float f2_, float f3_, float f4_) const;
	//EJGL_INLINE void setUniform(const std::string& name_, const glm::mat4& m44_) const;

private:
	std::shared_ptr<_EJGLShaderProgramElem> _dataPtr;
	//GLuint _programID;
	//mutable std::unordered_map<std::string, int> _uniformLocation;

public:
	EJGL_INLINE static void unbind() {
		glUseProgram(0);
	}

	EJGL_INLINE static void setUniform(GLint location_, int i_);
	EJGL_INLINE static void setUniform(GLint location_, unsigned int i_);
	EJGL_INLINE static void setUniform(GLint location_, float f_);
	EJGL_INLINE static void setUniform(GLint location_, unsigned int count_, float* fptr_);
	EJGL_INLINE static void setUniform(GLint location_, const glm::vec2& v2_);
	EJGL_INLINE static void setUniform(GLint location_, float f1_, float f2_);
	EJGL_INLINE static void setUniform(GLint location_, const glm::vec3& v3_);
	EJGL_INLINE static void setUniform(GLint location_, float f1_, float f2_, float f3_);
	EJGL_INLINE static void setUniform(GLint location_, const glm::vec4& v4_);
	EJGL_INLINE static void setUniform(GLint location_, float f1_, float f2_, float f3_, float f4_);
	EJGL_INLINE static void setUniform(GLint location_, const glm::mat3& m33_);
	EJGL_INLINE static void setUniform(GLint location_, const glm::mat4& m44_);
};

EJGL_NAMESPACE_END

#include "EJGL_ShaderProgram.inl"

#endif // EJGL_EJGLShaderProgram_HPP