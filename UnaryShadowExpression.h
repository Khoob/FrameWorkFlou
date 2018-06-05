#ifndef UNARYSHADOWEXPRESSION_H
#define UNARYSHADOWEXPRESSION_H

#include"UnaryExpression.h"

namespace core
{

	template <class T>
	class UnaryShadowExpression :public UnaryExpression<T>
	{
	public:
		UnaryShadowExpression(UnaryExpression<T>*);
		T evaluate(Expression<T>*) const;
		void takeTarget(UnaryExpression<T>*);
	private:
		UnaryExpression<T>* target;
	};


	template <class T>
	UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* _target) :
		target(_target)
	{
	}

	template <class T>
	void UnaryShadowExpression<T>::takeTarget(UnaryExpression<T>* t)
	{
		target = t;
	}

	template <class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T>* e) const
	{
		if (target != NULL)
			return target->evaluate(e);
		return NULL;
	}
}

#endif