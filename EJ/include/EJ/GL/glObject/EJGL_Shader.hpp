#ifndef EJGL_SHADER_HPP
#define EJGL_SHADER_HPP

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_BaseObject.hpp"
#include "../utils/EJGL_enum.hpp"

#include <memory>
#include <string>

namespace {
	struct _EJGLShaderElem {
		GLuint _shaderID;
		_EJGL EJGLShaderType _shaderType;
#ifdef EJGL_KEEP_SHADER_SRC
		std::string _shaderSrc;
#endif // EJGL_KEEP_SHADER_SRC
	};
}

EJGL_NAMESPACE_BEGIN

class EJGLShader : public EJGLBaseObject
{
public:
#ifdef EJGL_KEEP_SHADER_SRC
	EJGLShader(GLuint shaderID_ = 0, EJGLShaderType shaderType_ = EJGLShaderType::VERTEX, std::string&& shaderSrc_ = std::string()) :
		EJGLBaseObject(),
		_dataPtr(std::make_shared<_EJGLShaderElem>(_EJGLShaderElem{ shaderID_, shaderType_, std::move(shaderSrc_) }))
	{}
#else // EJGL_KEEP_SHADER_SRC
	EJGLShader(GLuint shaderID_ = 0, EJGLShaderType shaderType_ = EJGLShaderType::VERTEX) :
		EJGLBaseObject(),
		_dataPtr(std::make_shared<_EJGLShaderElem>(_EJGLShaderElem{ shaderID_, shaderType_ }))
	{}
#endif // EJGL_KEEP_SHADER_SRC
	EJGLShader(EJGLShaderType shaderType_) :
		EJGLShader(0, shaderType_)
	{}
	EJGLShader(const EJGLShader& obj_) :
		EJGLBaseObject(obj_),
		_dataPtr(obj_._dataPtr)
	{}
	EJGLShader(EJGLShader&& obj_) noexcept :
		EJGLBaseObject(std::move(obj_)),
		_dataPtr(std::move(obj_._dataPtr))
	{}
	virtual ~EJGLShader();

	EJGLShader& operator=(const EJGLShader& obj_);

	virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLShader, *this);

	EJ_INLINE void swap(EJGLShader& obj_) noexcept;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(bool, isValid, _dataPtr->_shaderID != 0);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(GLuint, getShaderID, _dataPtr->_shaderID);

	EJGL_INLINE void setShaderID(GLuint ID_);

	bool createShaderByFile(const std::string& filepath_, EJGLShaderType shaderType_);
	bool createShaderBySrc(const char* const src_, const int length_, EJGLShaderType shaderType_);

	void deleteShader();

private:
	std::shared_ptr<_EJGLShaderElem> _dataPtr;

	GLuint _createShader(const char* src_, const int length_) const;
};

EJGL_NAMESPACE_END

#include "EJGL_Shader.inl"

#endif // EJGL_SHADER_HPP