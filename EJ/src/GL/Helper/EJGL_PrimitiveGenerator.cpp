#include "EJ/GL/Helper/EJGL_PrimitiveGenerator.hpp"
#include "EJ/Utils/EJ_Math.hpp"

EJGL_NAMESPACE_BEGIN

PrimitiveData PrimitiveGenerator::generateSphere(float radiusX_, float radiusY_, float radiusZ_, int stacks_, int slices_) {
    PrimitiveData sphereData;

    // Generate vertices
    for (int stack = 0; stack <= stacks_; ++stack) {
        float phi = PI<float> * stack / stacks_; // Latitude angle [0, PI]
        float cosPhi = std::cos(phi);
        float sinPhi = std::sin(phi);

        for (int slice = 0; slice <= slices_; ++slice) {
            float theta = 2.0f * PI<float> * slice / slices_; // Longitude angle [0, 2PI]
            float cosTheta = std::cos(theta);
            float sinTheta = std::sin(theta);

            // Compute vertex position
            float x = radiusX_ * sinPhi * cosTheta;
            float y = radiusY_ * sinPhi * sinTheta;
            float z = radiusZ_ * cosPhi;

            // Push vertex position
            sphereData.vertices.push_back(x);
            sphereData.vertices.push_back(y);
            sphereData.vertices.push_back(z);
        }
    }

    // Generate indices
    for (int stack = 0; stack < stacks_; ++stack) {
        for (int slice = 0; slice < slices_; ++slice) {
            int first = stack * (slices_ + 1) + slice;
            int second = first + slices_ + 1;

            // Create two triangles for each quad
            sphereData.indices.push_back(first);
            sphereData.indices.push_back(second);
            sphereData.indices.push_back(first + 1);

            sphereData.indices.push_back(second);
            sphereData.indices.push_back(second + 1);
            sphereData.indices.push_back(first + 1);
        }
    }

    return sphereData;
}

EJGL_NAMESPACE_END