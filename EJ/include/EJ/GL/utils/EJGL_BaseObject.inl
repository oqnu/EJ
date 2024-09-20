EJGL_NAMESPACE_BEGIN

std::ostream& operator<<(std::ostream& os, const EJGLBaseObject& obj) {
	os << "[EJ][GL]" << obj.toString();
	return os;
}

EJGL_NAMESPACE_END