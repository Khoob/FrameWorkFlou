#ifndef ORPLUS_H
#define ORPLUS_H
#include "Or.h"

namespace core {

	template <class T>
	class OrPlus : public Or<T> {
	public:
		T evaluate(Expression<T>* l, Expression<T>* r) const;
	};
	template <class T> T OrPlus<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T left = l->evaluate();
		T right = r->evaluate();
		return left+right;
	}
}

#endif