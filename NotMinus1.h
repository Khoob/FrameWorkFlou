#ifndef NOTMINUS1_H
#define NOTMINUS1_H
#include "Not.h"

namespace core {

	template <class T>
	class NotMinus1 : public Not<T> {
		T evaluate(Expression<T>* o);
	};

	template <class T> T NotMinus1<T>::evaluate(Expression<T>* o) {
		return o->evaluate();
	}
}
#endif