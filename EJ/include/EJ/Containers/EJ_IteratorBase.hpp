#ifndef EJ_ITERATORBASE_HPP
#define EJ_ITERATORBASE_HPP

#include "../utils/EJ_BaseObject.hpp"
#include "../utils/EJ_TypeDefines.hpp"
#include "../utils/EJ_BaseObject.hpp"

EJ_NAMESPACE_BEGIN

class EJIteratorBase : public EJBaseObject {
public:
	EJIteratorBase()
	{}
	EJIteratorBase(const EJIteratorBase& obj_)
	{}
	EJIteratorBase(const EJIteratorBase&& obj_)
	{}
	virtual ~EJIteratorBase()
	{}

	EJIteratorBase& operator=(const EJIteratorBase& obj_)
	{}

	virtual EJString toString() const noexcept override = 0;

private:

};

EJ_NAMESPACE_END

#endif // EJ_ITERATORBASE_HPP
