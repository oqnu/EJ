#ifndef EJ_CONTAINERBASE_HPP
#define EJ_CONTAINERBASE_HPP

#include "../utils/EJ_BaseObject.hpp"
#include "../utils/EJ_TypeDefines.hpp"
#include "../utils/EJ_BaseObject.hpp"

EJ_NAMESPACE_BEGIN

template<typename _T>
class EJContainerBase : public EJBaseObject {
public:
	EJContainerBase()
	{}
	EJContainerBase(const EJContainerBase& obj_)
	{}
	EJContainerBase(const EJContainerBase&& obj_)
	{}
	virtual ~EJContainerBase()
	{}

	EJContainerBase& operator=(const EJContainerBase& obj_)
	{}

	virtual EJString toString() const noexcept override = 0;

private:

};

EJ_NAMESPACE_END

#endif // EJ_CONTAINERBASE_HPP
