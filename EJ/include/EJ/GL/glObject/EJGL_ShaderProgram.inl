EJGL_NAMESPACE_BEGIN

EJ_INLINE void EJGLShaderProgram::swap(EJGLShaderProgram& obj_) noexcept {
	::std::swap(_dataPtr, obj_._dataPtr);
}

EJGL_INLINE void EJGLShaderProgram::setProgramID(GLuint ID_) {
	_dataPtr->_programID = ID_;
}

EJGL_INLINE void EJGLShaderProgram::create() {
	_dataPtr->_programID = glCreateProgram();
}

EJGL_INLINE void EJGLShaderProgram::attachShader(const EJGLShader& shader_) const {
	EJGL_ASSERT(isValid() && "Have you create()?");
	EJGL_ASSERT(shader_.isValid());
	glAttachShader(_dataPtr->_programID, shader_.getShaderID());
}

EJGL_INLINE void EJGLShaderProgram::bind() const {
	EJGL_ASSERT(isValid() && "Have you create()?");
	glUseProgram(_dataPtr->_programID);
}

EJGL_INLINE void EJGLShaderProgram::bindUniformBlock(GLuint index_, GLuint bindingPoint_) const {
	glUniformBlockBinding(_dataPtr->_programID, index_, bindingPoint_);
}

template<typename _T, typename... _Ts>
EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, _T v_, _Ts... rv_) const {
	EJGLShaderProgram::setUniform(getUniformLocation(name_), v_, rv_...);
}
//EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, int i_) const {
//	EJGLShaderProgram::setUniform(getUniformLocation(name_), i_);
//}
//EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, unsigned int i_) const {
//	EJGLShaderProgram::setUniform(getUniformLocation(name_), i_);
//}
//EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, float f_) const {
//	EJGLShaderProgram::setUniform(getUniformLocation(name_), f_);
//}
//EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, unsigned int count_, float* fptr_) const {
//	EJGLShaderProgram::setUniform(getUniformLocation(name_), count_, fptr_);
//}
//EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, const glm::vec2& v2_) const {
//	EJGLShaderProgram::setUniform(getUniformLocation(name_), v2_);
//}
//EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, float f1_, float f2_) const {
//	EJGLShaderProgram::setUniform(getUniformLocation(name_), f1_, f2_);
//}
//EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, const glm::vec3& v3_) const {
//	EJGLShaderProgram::setUniform(getUniformLocation(name_), v3_);
//}
//EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, float f1_, float f2_, float f3_) const {
//	EJGLShaderProgram::setUniform(getUniformLocation(name_), f1_, f2_, f3_);
//}
//EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, const glm::vec4& v4_) const {
//	EJGLShaderProgram::setUniform(getUniformLocation(name_), v4_);
//}
//EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, float f1_, float f2_, float f3_, float f4_) const {
//	EJGLShaderProgram::setUniform(getUniformLocation(name_), f1_, f2_, f3_, f4_);
//}
//EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, const glm::mat3& m33_) {
//	EJGLShaderProgram::setUniform(getUniformLocation(name_), m33_);
//}
//EJGL_INLINE void EJGLShaderProgram::setUniform(const std::string& name_, const glm::mat4& m44_) const {
//	EJGLShaderProgram::setUniform(getUniformLocation(name_), m44_);
//}

EJGL_INLINE void EJGLShaderProgram::setUniform(GLint location_, int i_) {
	glUniform1i(location_, i_);
}
EJGL_INLINE void EJGLShaderProgram::setUniform(GLint location_, unsigned int i_) {
	glUniform1ui(location_, i_);
}
EJGL_INLINE void EJGLShaderProgram::setUniform(GLint location_, float f_) {
	glUniform1f(location_, f_);
}
EJGL_INLINE void EJGLShaderProgram::setUniform(GLint location_, unsigned int count_, float* fptr_) {
	glUniform1fv(location_, count_, fptr_);
}
EJGL_INLINE void EJGLShaderProgram::setUniform(GLint location_, const glm::vec2& v2_) {
	glUniform2fv(location_, 1, glm::value_ptr(v2_));
}
EJGL_INLINE void EJGLShaderProgram::setUniform(GLint location_, float f1_, float f2_) {
	glUniform2f(location_, f1_, f2_);
}
EJGL_INLINE void EJGLShaderProgram::setUniform(GLint location_, const glm::vec3& v3_) {
	glUniform3fv(location_, 1, glm::value_ptr(v3_));
}
EJGL_INLINE void EJGLShaderProgram::setUniform(GLint location_, float f1_, float f2_, float f3_) {
	glUniform3f(location_, f1_, f2_, f3_);
}
EJGL_INLINE void EJGLShaderProgram::setUniform(GLint location_, const glm::vec4& v4_) {
	glUniform4fv(location_, 1, glm::value_ptr(v4_));
}
EJGL_INLINE void EJGLShaderProgram::setUniform(GLint location_, float f1_, float f2_, float f3_, float f4_) {
	glUniform4f(location_, f1_, f2_, f3_, f4_);
}
EJGL_INLINE void EJGLShaderProgram::setUniform(GLint location_, const glm::mat3& m33_) {
	glUniformMatrix3fv(location_, 1, GL_FALSE, glm::value_ptr(m33_));
}
EJGL_INLINE void EJGLShaderProgram::setUniform(GLint location_, const glm::mat4& m44_) {
	glUniformMatrix4fv(location_, 1, GL_FALSE, glm::value_ptr(m44_));
}

EJGL_NAMESPACE_END