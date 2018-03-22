#ifndef ORMAX_H
#define ORMAX_H
#include "Or.h"

namespace core {

	template <class T>
	class OrMax : public Or<T> {
	public:
		T evaluate(Expression<T>* l, Expression<T>* r) const;
	};
	template <class T> T OrMax<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T val;
		if (l->evaluate() > r->evaluate()) {
			val = l->evaluate();
		}
		else val = r->evaluate();
		return val;
	}
}

#endif