#ifndef EJGL_TEXTURE2D_HPP
#define EJGL_TEXTURE2D_HPP

#include "../Utils/EJGL_config.hpp"
#include "../Utils/EJGL_enum.hpp"
#include "../../Helper/EJ_EasyStructs.hpp"

#include <memory>
#include <string>

EJGL_NAMESPACE_BEGIN

struct TextureOptions {
	TextureWarpOption wrapsS;
	TextureWarpOption wrapsT;
	TextureMinFilterOption minFilter;
	TextureMagFilterOption magFilter;
};

class Texture2D
{
private:
	class _Texture2DImpl;

public:
	// construct empty
	Texture2D();
	// construct with image
	Texture2D(const SimpleImage& image_, TexturePixelDataFormat imageDataFormat_, DataType imageDataType_,
		TextureOptions options_, TextureInternalFormat internalFormat_);
	// construct with id
	Texture2D(GLuint id_);
	Texture2D(const Texture2D& obj_) = default;
	Texture2D& operator=(const Texture2D& obj_) = default;
	~Texture2D() = default;

	operator GLuint() const;
	bool isValid() const;

	GLuint getTextureID() const;
	GLuint getBindingUnitID() const;

	void setTextureID(GLuint id_);

	void create(const SimpleImage& image_, TexturePixelDataFormat imageDataFormat_, DataType imageDataType_,
		TextureOptions options_, TextureInternalFormat internalFormat_, GLint level_ = 0);
	void generateMipMap();

	void bind() const;
	void bindToUnitID(GLuint unitID_);

	void deleteTexture2D();

private:
	_STD shared_ptr<_Texture2DImpl> _impl;

public:
	static void unbind();

};

EJGL_NAMESPACE_END

#endif // EJGL_TEXTURE2D_HPP