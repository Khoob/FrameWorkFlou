#ifndef VALUEMODEL_H
#define VALUEMODEL_H
#include "Expression.h"

namespace core {

	template <class T>
	class ValueModel : public Expression<T> {
	private:

		T value;

	public:

		ValueModel();
		ValueModel(T val);
		//ValueModel(ValueModel<T>& val);

		T evaluate() const;
		void setValue(T val);
	};
	template <class T> ValueModel<T>::ValueModel() : value(0) {};
	template <class T> ValueModel<T>::ValueModel(T val) : value(val) {}
	//template <class T> ValueModel<T>::ValueModel(ValueModel<T>& val) : value(val.evaluate()) {}
	template <class T> T ValueModel<T>::evaluate() const {
		return value;
	}
	template <class T> void ValueModel<T>::setValue(T val){
		value = val;
	}
}
#endif