#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
namespace core {

	template <class T>
	class UnaryExpressionModel : UnaryExpression, Expression {
	private:

		UnaryExpression<T> operator;
		Expression<T> operand;

	public:
		T evaluate(Expression* o) const;
		T evaluate() const;
	};

	template <class T> T UnaryExpressionModel<T>::evaluate() const {
		if (operator != null) return evaluate(operand);
	}

	template <class T> T UnaryExpressionModel<T>::evaluate(Expression* o) const {
		if (operator != null) return operator.evaluate(o);
	}
}

#endif
