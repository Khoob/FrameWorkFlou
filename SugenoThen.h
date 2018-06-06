#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H
#include "Then.h"

namespace core {

	template <class T>
	class SugenoThen : public Then<T> {
		private:
			T _premiseValue;
		public:
			T evaluate(Expression<T>* l, Expression<T>* r) const;
			T premiseValue();
		};
	template <class T> T SugenoThen<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T left = l->evaluate();
		T right = r->evaluate();
		return left * right;
	}

	template<class T> T SugenoThen<T>::premiseValue() {
		return _premiseValue;
	}
}

#endif