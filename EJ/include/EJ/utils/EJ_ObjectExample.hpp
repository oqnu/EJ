#ifndef EJ_EXAMPLE_HPP
#define EJ_EXAMPLE_HPP

#include "../utils/EJ_config.hpp"
#include "../utils/EJ_BaseObject.hpp"

EJ_NAMESPACE_BEGIN

class EJExample : public EJBaseObject {
public:
	EJExample()
	{}
	EJExample(const EJExample& obj_)
	{}
	EJExample(const EJExample&& obj_)
	{}
	virtual ~EJExample()
	{}

	EJExample& operator=(const EJExample& obj_)
	{}

	virtual EJString toString() const noexcept override;

	EJ_INLINE EJ_M_CLONE_FUNC(EJBaseObject, EJExample, *this);

	EJ_INLINE void swap(EJBaseObject& obj_) noexcept;

private:

};

EJ_NAMESPACE_END

#endif // EJ_EXAMPLE_HPP
