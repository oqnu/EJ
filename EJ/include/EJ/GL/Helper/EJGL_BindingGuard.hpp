#ifndef EJGL_BINDINGGUARD_HPP
#define EJGL_BINDINGGUARD_HPP

#include "../Utils/EJGL_config.hpp"

EJGL_NAMESPACE_BEGIN

template <typename _ResourceType>
class BindingGuard
{
public:
	using ResourceType = _ResourceType;

public:
	template <typename... Args>
	BindingGuard(const ResourceType& resource_, Args&&... args_) :
		_resource(resource_)
	{
		if (_isBinding) {
			EJ_ERR_STREAM << "[EJ][Error] BindingGuard: Already binding another resource for class " << typeid(ResourceType).name() << ".\n";
		}
		_isBinding = true;
		_resource.bind(_STD forward<Args>(args_)...);
	}

	~BindingGuard() {
		_isBinding = false;
		_resource.unbind();
	}

	BindingGuard(const BindingGuard& obj_) = delete;
	BindingGuard& operator=(const BindingGuard& obj_) = delete;

private:
	const ResourceType& _resource;

private:
	static bool _isBinding;

};

template <typename _ResourceType>
bool BindingGuard<_ResourceType>::_isBinding = false;

EJGL_NAMESPACE_END

#endif // EJGL_BINDINGGUARD_HPP