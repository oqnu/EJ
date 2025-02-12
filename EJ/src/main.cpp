#pragma warning( disable: 4267 )

#include "EJ/GL/EJGL_include.hpp"
#include "EJ/Helper/EJ_ImageLoader.hpp"
#include "EJ/GL/Helper/EJGL_ImGuiHelper.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image/stb_image.h>
#include <glm/gtx/euler_angles.hpp>

#include <glfwpp/glfw.hpp>

using namespace EJ;

constexpr const char* vert = R"(
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;

uniform VPMat{
	uniform mat4x4 u_viewMat;
	uniform mat4x4 u_projectionMat;
};
uniform mat4x4 u_transformationMat;

out vec2 v_texCoord;

void main() {
	gl_Position = u_projectionMat * u_viewMat * u_transformationMat * vec4(aPos, 1);
	v_texCoord = aTexCoord;
})";
constexpr const char* frag = R"(
#version 330 core

in vec2 v_texCoord;

uniform sampler2D u_tex;

out vec4 FragColor;

void main() {
	FragColor = texture(u_tex, v_texCoord) + vec4(0.2, 0.2, 0.2, 0);
	//FragColor = vec4(0.7f, 0.2f, 0.4f, 1.f);
})";

using namespace EJ;

int main() {
	Application::initialize();
	constexpr int initWidth = 1000, initHeight = 1000;

	Application::getDefaultHint().apply();

	Window window{ initWidth, initHeight, "EJ" };
	window.makeContextCurrent();

	Application::getInstance().loadGlad();

	window.setCamera<ArcBallCamera>();

	ImGuiHelper::ImGuiLifeHandler imguiLife = ImGuiHelper::init(window, "#version 460");

	UniformBuffer vpMatUbo;
	{
		struct VPMat {
			glm::mat4 v;
			glm::mat4 p;
		};
		vpMatUbo.create(sizeof(VPMat));
		BindingGuard guard(vpMatUbo);
		vpMatUbo.subData(0, sizeof(glm::mat4), glm::value_ptr(glm::mat4(1)));
		vpMatUbo.subData(sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(glm::mat4(1)));
		vpMatUbo.bindToBindingPoint(0);
	}

	ShaderProgram shaderProgram;
	shaderProgram.create();
	shaderProgram.attachShaderBySrc(vert, strlen(vert), ShaderType::VERTEX);
	shaderProgram.attachShaderBySrc(frag, strlen(frag), ShaderType::FRAGEMENT);
	shaderProgram.link();
	{
		BindingGuard guard(shaderProgram);
		shaderProgram.setUniform("u_transformationMat", glm::mat4(1));
		shaderProgram.getUniformBlockIndexAndBind("VPMat", vpMatUbo.getBindingPoint());
	}

	VertexArray vao{ default_create{} };
	{
		BindingGuard guard(vao);
		VertexBufferLayout layout;
		layout.add(DataType::FLOAT, 2);
		layout.add(DataType::FLOAT, 2);
		constexpr float __size = 1.0f;
		vao.addBufferLayout(ArrayBuffer(std::vector<float>{
			-__size, -__size, 0.0f, 0.0f,
			__size, -__size, 1.0f, 0.0f,
			__size, __size, 1.0f, 1.0f,
			-__size, __size, 0.0f, 1.0f,
		}), layout);
		vao.addBuffer(ElementBuffer(std::vector<unsigned int>({
			0, 1, 2,
			2, 3, 0,
			})));
	}

	Texture2D texture1;
	if (auto img = ImageLoader::stbiLoad("tmp.png", 4)) {
		texture1.create(img.value(), TexturePixelDataFormat::RGBA, DataType::UNSIGNED_BYTE,
			TextureOptions{ .wrapsS = TextureWarpOption::CLAMP_TO_BORDER, .wrapsT = TextureWarpOption::CLAMP_TO_BORDER,
			.minFilter = TextureMinFilterOption::NEAREST, .magFilter = TextureMagFilterOption::NEAREST },
			TextureInternalFormat::RGBA);
		texture1.bindToUnitID(1);
	}
	else {
		std::cout << "Failed to load texture" << std::endl;
	}

	{
		BindingGuard guard(shaderProgram);
		shaderProgram.setUniform("u_tex", (int)1);
	}

	double _prevTime = glfw::getTime();
	double _fps = 0;
	int _frameCnt = 0;

	glEnable(EnableOption::DEPTH_TEST);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	while (!window.shouldClose()) {
		glfw::pollEvents();

		glClear(ClearBit::COLOR | ClearBit::DEPTH);

		imguiLife.newFrame();

		{
			double currentTime = glfw::getTime();
			_frameCnt++;

			if (currentTime - _prevTime >= 1.0) {
				_fps = double(_frameCnt) / (currentTime - _prevTime);
				_frameCnt = 0;
				_prevTime = currentTime;
			}
		}

		{
			ImGuiHelper::ImGuiWindowLifeHandler imWindow = ImGuiHelper::createWindow("Test");
			ImGui::Text("FPS: %.2lf", _fps);
			ImGuiHelper::CameraRotation("Camera Rotation", window.getCamera<ArcBallCamera>()->getViewMatrix()->rotation());
		}

		{
			BindingGuard uboGuard(vpMatUbo);
			if (window.getCamera()->getViewMatrix()->hasChange()) {
				window.getCamera()->getViewMatrix()->update();
				vpMatUbo.subData(0, sizeof(glm::mat4), glm::value_ptr(window.getCamera()->getViewMatrix()->toGlm()));
			}
			if (window.getCamera()->getProjectionMatrix()->hasChange()) {
				window.getCamera()->getProjectionMatrix()->update();
				vpMatUbo.subData(sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(window.getCamera()->getProjectionMatrix()->toGlm()));
			}
		}

		{
			BindingGuard programGuard(shaderProgram);
			BindingGuard vaoGuard(vao);
			vao.drawElement(DrawOption::TRIANGLES, 0, 6);
		}

		imguiLife.render();

		window.swapBuffers();
	}
}