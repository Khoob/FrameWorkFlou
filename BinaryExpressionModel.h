#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"
namespace core {

	template <class T>
	class BinaryExpressionModel :public BinaryExpression<T>, public Expression<T> {
	private:

		BinaryExpression<T>* _operator;
		Expression<T>* left;
		Expression<T>* right;

	public:
		BinaryExpressionModel(BinaryExpression<T>* ope = NULL, Expression<T>* expl = NULL, Expression<T>* expr = NULL);
		T evaluate(Expression<T>* l, Expression<T>* r) const;
		T evaluate() const;
	};

	template <class T> 
	BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* ope, Expression<T>* expl, Expression<T>* expr)
		:_operator(ope), left(expl), right(expr)
	{
	}

	template <class T> 
	T BinaryExpressionModel<T>::evaluate() const 
	{
		if (left != NULL && right != NULL) return evaluate(left, right);
		return NULL;
	}

	template <class T> 
	T BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r) const 
	{
		if (_operator != NULL) return _operator->evaluate(l, r);
		return NULL;
	}
}

#endif
