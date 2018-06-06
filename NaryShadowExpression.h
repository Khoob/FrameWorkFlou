#ifndef NARYSHADOWEXPRESSION_H
#define NARYSHADOWEXPRESSION_H

#include"NaryExpression.h"

namespace core
{

	template <class T>
	class NaryShadowExpression :public NaryExpression<T>
	{
	public:
		NaryShadowExpression(NaryExpression<T>*);
		T evaluate(std::vector<Expression<T>>) const;
		void takeTarget(NaryExpression<T>*);
	private:
		NaryExpression<T>* target;
	};


	template <class T>
	NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>* _target) :
		target(_target)
	{
	}

	template <class T>
	void NaryShadowExpression<T>::takeTarget(NaryExpression<T>* t)
	{
		target = t;
	}

	template <class T>
	T NaryShadowExpression<T>::evaluate(std::vector<Expression<T>> e) const
	{
		if (target != NULL)
			return target->evaluate(e);
		return NULL;
	}
}

#endif