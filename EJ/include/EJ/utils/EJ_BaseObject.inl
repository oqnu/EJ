EJ_NAMESPACE_BEGIN

std::ostream& operator<<(std::ostream& os, const EJBaseObject& obj) {
	os << "[EJ]" << obj.toString();
	return os;
}

EJ_NAMESPACE_END