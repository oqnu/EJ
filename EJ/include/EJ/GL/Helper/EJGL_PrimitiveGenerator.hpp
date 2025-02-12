#ifndef EJGL_PRIMITIVEGENERATOR_HPP
#define EJGL_PRIMITIVEGENERATOR_HPP

#include "../Utils/EJGL_config.hpp"

#include <vector>

EJGL_NAMESPACE_BEGIN

struct PrimitiveData {
	_STD vector<float> vertices;
	_STD vector<unsigned int> indices;
};

class PrimitiveGenerator
{
public:
	static PrimitiveData generateSphere(float radiusX_, float radiusY_, float radiusZ_, int stacks_ = 20, int slices_ = 20);
};

EJGL_NAMESPACE_END

#endif // EJGL_PRIMITIVEGENERATOR_HPP