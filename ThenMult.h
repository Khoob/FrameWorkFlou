#ifndef THENMULT_H
#define THENMULT_H
#include "Then.h"

namespace core {

	template <class T>
	class ThenMult : public Then<T> {
	public:
		T evaluate(Expression<T>* l, Expression<T>* r) const;
	};
	template <class T> T ThenMult<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T left = l->evaluate();
		T right = r->evaluate();
		return left * right;
	}
}

#endif