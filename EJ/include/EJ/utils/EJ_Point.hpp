//#ifndef EJ_POINT_HPP
//#define EJ_POINT_HPP
//
//#include "EJ_config.hpp"
//#include "EJ_BaseObject.hpp"
//
//EJ_NAMESPACE_BEGIN
//
//template<typename T, EJSizeType Dim>
//class EJPoint : public EJBaseObject {
//public:
//	EJPoint() = default;
//	EJPoint(EJInitializerList<T> list) {
//		std::copy(list.begin(), list.end(), data.begin());
//	}
//	EJPoint(const EJPoint& obj_) = default;
//	~EJPoint() = default;
//
//	EJ_INLINE const T& operator[](EJSizeType idx_) const;
//	EJ_INLINE T& operator[](EJSizeType idx_);
//
//	EJ_INLINE const T* data() const;
//	EJ_INLINE T* data();
//
//private:
//	EJStaticArray<T, Dim> _data;
//
//};
//
//template<typename T, EJSizeType Dim>
//EJPoint<T, Dim>::EJPoint(EJInitializerList<T> list) {
//	std::copy(list.begin(), list.end(), _data.begin());
//}
//
//template<typename T, EJSizeType Dim>
//EJ_INLINE const T& EJPoint<T, Dim>::operator[](EJSizeType idx_) const {
//	EJ_ASSERT(idx_ < Dim);
//	return _data[idx_];
//}
//template<typename T, EJSizeType Dim>
//EJ_INLINE T& EJPoint<T, Dim>::operator[](EJSizeType idx_) {
//	EJ_ASSERT(idx_ < Dim);
//	return _data[idx_];
//}
//
//template<typename T, EJSizeType Dim>
//EJ_INLINE const T* EJPoint<T, Dim>::data() const {
//	return _data.data();
//}
//template<typename T, EJSizeType Dim>
//EJ_INLINE T* EJPoint<T, Dim>::data() {
//	return _data.data();
//}
//
//EJ_NAMESPACE_END
//
//#endif // EJ_POINT_HPP
