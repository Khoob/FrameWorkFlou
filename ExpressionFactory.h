#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H
#include "Expression.h"
#include <vector>
#include "UnaryExpression.h"
#include "BinaryExpression.h"

namespace core {

	template <class T>
	class ExpressionFactory {
	private:

		std::vector<Expression<T>> memory;

	public:
		ExpressionFactory();
		//DO THE DESTRUCTOR
		Expression<T> Hold(Expression<T>);
		Expression<T> newUnary(UnaryExpression<T>, Expression<T>);
		Expression<T> newBinary(BinaryExpression<T>, Expression<T>, Expression<T>);
	};

	template <class T> ExpressionFactory<T>::ExpressionFactory() {}
	//DO THE DESTRUCTOR
	template <class T> Expression<T> ExpressionFactory<T>::Hold(Expression<T> exp) {
		memory.push_back(exp);
		return exp;
	}
	template <class T> Expression<T> ExpressionFactory<T>::newUnary(UnaryExpression<T> ope, Expression<T> exp) {
		return new UnaryExpressionModel(ope, exp);
	}
	template <class T> Expression<T> ExpressionFactory<T>::newBinary(BinaryExpression<T> ope, Expression<T> expl, Expression<T> expr) {
		return new BinaryExpressionModel(ope, expl, expr);
	}

}
#endif