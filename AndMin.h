#ifndef ANDMIN_H
#define ANDMIN_H
#include "And.h"

namespace core {

	template <class T>
	class AndMin : public And<T> {
	public:
		T evaluate(Expression<T>* l, Expression<T>* r) const;
	};
	template <class T> T AndMin<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T val;
		if (l->evaluate() < r->evaluate()) {
			val = l->evaluate();
		}
		else val = r->evaluate();
		return val;
	}
}

#endif