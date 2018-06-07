#ifndef BINARYSHADOWEXPRESSION_H
#define BINARYSHADOWEXPRESSION_H

#include"BinaryExpression.h"

namespace core
{

	template <class T>
	class BinaryShadowExpression :public BinaryExpression<T>
	{
	public:
		BinaryShadowExpression(BinaryExpression<T>*);
		T evaluate(Expression<T>*, Expression<T>*) const;
		void takeTarget(BinaryExpression<T>*);
	private:
		BinaryExpression<T>* target;
	};

	template <class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* _target) :
		target(_target)
	{}



	template <class T>
	T BinaryShadowExpression<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		if (target != NULL)
			return target->evaluate(l, r);
		return NULL;
	}

	template <class T>
	void BinaryShadowExpression<T>::takeTarget(BinaryExpression<T>* t) {
		target = t;
	}

}
#endif