#ifndef THENMIN_H
#define THENMIN_H
#include "Then.h"

namespace core {

	template <class T>
	class ThenMin : public Then<T> {
	public:
		T evaluate(Expression<T>* l, Expression<T>* r) const;
	};
	template <class T> T ThenMin<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T val;
		if (l->evaluate() < r->evaluate()) {
			val = l->evaluate();
		}
		else val = r->evaluate();
		return val;
	}
}

#endif