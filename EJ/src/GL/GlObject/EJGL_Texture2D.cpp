#include "EJ/GL/GlObject/EJGL_Texture2D.hpp"

EJGL_NAMESPACE_BEGIN

class Texture2D::_Texture2DImpl {
public:
	_Texture2DImpl()
	{}
	_Texture2DImpl(const SimpleImage& image_, TexturePixelDataFormat imageDataFormat_, DataType imageDataType_,
		TextureOptions options_, TextureInternalFormat internalFormat_) {
		create(image_, imageDataFormat_, imageDataType_, options_, internalFormat_, 0);
	}
	_Texture2DImpl(GLuint id_) :
		_textureID(id_)
	{}
	_Texture2DImpl(const _Texture2DImpl& obj_) = delete;
	_Texture2DImpl& operator=(const _Texture2DImpl& obj_) = delete;
	~_Texture2DImpl() {
		deleteTexture2D();
	}

	void create(const SimpleImage& image_, TexturePixelDataFormat imageDataFormat_, DataType imageDataType_,
		TextureOptions options_, TextureInternalFormat internalFormat_, GLint level_) {
		glGenTextures(1, &_textureID);
		bind();
		glTexImage2D(TextureType::_2D, 0, internalFormat_, image_.width, image_.height, 0, imageDataFormat_, imageDataType_, image_.data.get());

		glTexParameteri(TextureType::_2D, TextureParameter::WRAP_S, options_.wrapsS);
		glTexParameteri(TextureType::_2D, TextureParameter::WRAP_T, options_.wrapsT);
		glTexParameteri(TextureType::_2D, TextureParameter::MIN_FILTER, options_.minFilter);
		glTexParameteri(TextureType::_2D, TextureParameter::MAG_FILTER, options_.magFilter);
	}
	void generateMipMap() {
		glGenerateMipmap(TextureType::_2D);
	}

	void bind() const {
		glBindTexture(TextureType::_2D, _textureID);
	}
	void bindToUnitID(GLuint unitID_) {
		_bindingUnitID = unitID_;
		glActiveTexture(GL_TEXTURE0 + unitID_);
		bind();
		glActiveTexture(GL_TEXTURE0);
	}

	void deleteTexture2D() {
		glDeleteTextures(1, &_textureID);
	}

public:
	GLuint _textureID = 0;
	GLuint _bindingUnitID = 0;

public:
	static void unbind() {
		glBindTexture(TextureType::_2D, 0);
	}

};

// construct empty
Texture2D::Texture2D() :
	_impl{ _STD make_shared<_Texture2DImpl>() }
{}
// construct with image
Texture2D::Texture2D(const SimpleImage& image_, TexturePixelDataFormat imageDataFormat_, DataType imageDataType_,
	TextureOptions options_, TextureInternalFormat internalFormat_) :
	_impl{ _STD make_shared<_Texture2DImpl>(image_, imageDataFormat_, imageDataType_, options_, internalFormat_) }
{}
// construct with id
Texture2D::Texture2D(GLuint id_) :
	_impl{ _STD make_shared<_Texture2DImpl>(id_) }
{}

Texture2D::operator GLuint() const {
	return _impl->_textureID;
}
bool Texture2D::isValid() const {
	return _impl->_textureID != 0;
}

GLuint Texture2D::getTextureID() const {
	return _impl->_textureID;
}
GLuint Texture2D::getBindingUnitID() const {
	return _impl->_bindingUnitID;
}

void Texture2D::setTextureID(GLuint id_) {
	_impl->_textureID = id_;
}

void Texture2D::create(const SimpleImage& image_, TexturePixelDataFormat imageDataFormat_, DataType imageDataType_,
	TextureOptions options_, TextureInternalFormat internalFormat_, GLint level_) {
	return _impl->create(image_, imageDataFormat_, imageDataType_, options_, internalFormat_, level_);
}
void Texture2D::generateMipMap() {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->generateMipMap();
}

void Texture2D::bind() const {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->bind();
}
void Texture2D::bindToUnitID(GLuint unitID_) {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->bindToUnitID(unitID_);
}

void Texture2D::deleteTexture2D() {
	_impl->deleteTexture2D();
}

void Texture2D::unbind() {
	_Texture2DImpl::unbind();
}

EJGL_NAMESPACE_END
