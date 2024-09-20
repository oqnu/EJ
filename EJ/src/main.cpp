#pragma warning( disable: 4267 )

#include "EJ/GL/EJGL_include.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image/stb_image.h>

#include <imgui-docking/imgui.h>
#include <imgui-docking/imgui_impl_glfw.h>
#include <imgui-docking/imgui_impl_opengl3.h>

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

using namespace EJ::GL;

int main() {
	EJGLApplication::getInstance();
	constexpr int initWidth = 1000, initHeight = 987;

	EJGLApplication::getDefaultHint().apply();

	EJGLWindow window{ initWidth, initHeight, "Eyja" };
	glfw::makeContextCurrent(window);

	EJGLApplication::getInstance().loadGlad();

	window.setCamera<EJGLArcBallCamera>();

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 460");

	//	IMGUI_CHECKVERSION();
	//	ImGui::CreateContext();
	//	ImGui_ImplGlfw_InitForOpenGL(*window, true);
	//#ifdef __APPLE__
	//	ImGui_ImplOpenGL3_Init("#version 410");
	//#else
	//	ImGui_ImplOpenGL3_Init("#version 460");
	//#endif // __APPLE__
		// setup window
		//window.setCamera<EJGLEJGLArcBallCamera>();
		//window.getCamera().setViewMatrix<EJGLViewMatrix>();
		//window.getCamera().setProjectionMatrix<EJGLOrthographicMatrix>();

	EJGLUniformBuffer vpMatUbo;
	{
		struct VPMat {
			glm::mat4 v;
			glm::mat4 p;
		};
		vpMatUbo.create(sizeof(VPMat));
		vpMatUbo.bind();
		vpMatUbo.subData(0, sizeof(glm::mat4), glm::value_ptr(glm::mat4(1)));
		vpMatUbo.subData(sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(glm::mat4(1)));
		vpMatUbo.bindToBindingPoint(0);
		vpMatUbo.unbind();
	}

	EJGLShaderProgram shaderProgram;
	shaderProgram.create();
	shaderProgram.attachShaderBySrc(vert, strlen(vert), EJGLShaderType::VERTEX);
	shaderProgram.attachShaderBySrc(frag, strlen(frag), EJGLShaderType::FRAGEMENT);
	shaderProgram.link();
	shaderProgram.bind();
	shaderProgram.setUniform("u_transformationMat", glm::mat4(1));
	shaderProgram.getUniformBlockIndexAndBind("VPMat", vpMatUbo.getBindingPoint());
	shaderProgram.unbind();

	EJGLVertexArray vao;
	{
		vao.create();
		vao.bind();
		EJGLArrayBuffer vbo;
		vbo.create(std::vector<float>({
			-10.0f, -10.0f, 0.0f, 0.0f,
			 10.0f, -10.0f, 1.0f, 0.0f,
			 10.0f,  10.0f, 1.0f, 1.0f,
			-10.0f,  10.0f, 0.0f, 1.0f,
			}));
		EJGLVertexBufferLayout layout;
		layout.add(EJGLDataType::FLOAT, 2);
		layout.add(EJGLDataType::FLOAT, 2);
		vao.addBufferLayout(vbo, layout);
		EJGLElementBuffer ebo;
		ebo.create(std::vector<unsigned int>({
			0, 1, 2,
			2, 3, 0,
			}));
		vao.addBuffer(ebo);
		vao.unbind();
	}

	unsigned int texture1;
	// texture 1
	// ---------
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	// The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
	unsigned char* data = stbi_load("tmp.png", &width, &height, &nrChannels, 4);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	shaderProgram.bind();
	shaderProgram.setUniform("u_tex", (int)0);
	shaderProgram.unbind();

	double _prevTime = glfwGetTime();
	double _fps = 0;
	int _frameCnt = 0;

	glEnable(EJGLEnableOption::DEPTH_TEST);
	glClearColor(0, 0, 0, 1);
	while (!window.shouldClose()) {
		glfw::pollEvents();

		glClear(EJGLClearBit::COLOR | EJGLClearBit::DEPTH);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		{
			double currentTime = glfwGetTime();
			_frameCnt++;

			if (currentTime - _prevTime >= 1.0) { // 每秒刷新一次 FPS
				_fps = double(_frameCnt) / (currentTime - _prevTime);

				_frameCnt = 0;
				_prevTime = currentTime;
			}
		}

		ImGui::Begin("Test");
		ImGui::Text("FPS: %.2lf", _fps);
		ImGui::End();

		vpMatUbo.bind();
		if (window.getCamera()->getViewMatrix()->hasChange()) {
			window.getCamera()->getViewMatrix()->update();
			vpMatUbo.subData(0, sizeof(glm::mat4), glm::value_ptr(window.getCamera()->getViewMatrix()->toGlm()));
		}
		if (window.getCamera()->getProjectionMatrix()->hasChange()) {
			window.getCamera()->getProjectionMatrix()->update();
			vpMatUbo.subData(sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(window.getCamera()->getProjectionMatrix()->toGlm()));
		}
		vpMatUbo.unbind();
		//std::cout << *window.getCamera()->getViewMatrix() << std::endl;
		//std::cout << toString(window.getCamera()->getViewMatrix()->toGlm()) << std::endl;

		shaderProgram.bind();
		vao.bind();
		vao.drawElement(EJGLDrawOption::TRIANGLES, 0, 6);
		vao.unbind();
		shaderProgram.unbind();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		window.swapBuffers();
	}
}