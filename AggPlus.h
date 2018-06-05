#ifndef AGGPLUS_H
#define AGGPLUS_H
#include "Agg.h"

namespace core {

	template <class T>
	class AggPlus : public Agg<T> {
	public:
		T evaluate(Expression<T>* l, Expression<T>* r) const;
	};
	template <class T> T AggPlus<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T left = l->evaluate();
		T right = r->evaluate();
		return left + right;
	}
}

#endif