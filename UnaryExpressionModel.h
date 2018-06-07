#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
namespace core {

	template <class T>
	class UnaryExpressionModel :public UnaryExpression<T>, public Expression<T> {
	private:

		UnaryExpression<T>* _operator;
		Expression<T>* operand;

	public:
		UnaryExpressionModel(UnaryExpression<T>* ope = NULL, Expression<T>* exp = NULL);
		T evaluate(Expression<T>* o) const;
		T evaluate() const;
	};

	template <class T> UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* ope, Expression<T>* exp)
		:_operator(ope),operand(exp)
	{}

	template <class T> T UnaryExpressionModel<T>::evaluate() const {
		if (_operator != NULL) return evaluate(operand);
		return NULL;
	}

	template <class T> T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const {
		if (_operator != NULL) return _operator->evaluate(o);
		return NULL;
	}
}

#endif
