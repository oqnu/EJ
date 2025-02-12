#ifndef EJ_EASYSTRUCTS_HPP
#define EJ_EASYSTRUCTS_HPP

#include "../Utils/EJ_config.hpp"

#include <memory>

EJ_NAMESPACE_BEGIN

struct SimpleImage {
	int width;
	int height;
	int channel;
	_STD shared_ptr<void> data;

	static SimpleImage createEmpty(int width_, int height_, int channel_) {
		return SimpleImage{ width_, height_, channel_, nullptr };
	}
};

EJ_NAMESPACE_END

#endif // EJ_EASYSTRUCTS_HPP