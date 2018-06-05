#ifndef AGGMAX_H
#define AGGMAX_H

#include"Agg.h"

namespace core {

	template <class T>
	class AggMax : public Agg<T>
	{
	public:
		T evaluate(Expression<T>*, Expression<T>*) const;
	};

	template <class T>
	T AggMax<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T val;
		if (l->evaluate() > r->evaluate()) {
			val = l->evaluate();
		}
		else val = r->evaluate();
		return val;
	}
}

#endif