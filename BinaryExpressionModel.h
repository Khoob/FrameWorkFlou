#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"
namespace core {

	template <class T>
	class BinaryExpressionModel : BinaryExpression, Expression {
	private:

		BinaryExpression<T> operator;
		Expression<T> left,right;

	public:
		T evaluate(Expression* l, Expression* r) const;
		T evaluate() const;
	};

	template <class T> T BinaryExpressionModel<T>::evaluate() const {
		if (left != null && right != null) return evaluate(left, right);
	}

	template <class T> T BinaryExpressionModel<T>::evaluate(Expression* l, Expression* r) const {
		if (operator != null) return operator.evaluate(l, r);

	}
}

#endif
