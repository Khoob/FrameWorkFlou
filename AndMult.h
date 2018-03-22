#ifndef ANDMULT_H
#define ANDMULT_H
#include "And.h"

namespace core {

	template <class T>
	class AndMult : public And<T> {
	public:
		T evaluate(Expression<T>* l, Expression<T>* r) const;
	};
	template <class T> T AndMult<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T left = l->evaluate();
		T right = r->evaluate();
		return left*right;
	}
}

#endif
