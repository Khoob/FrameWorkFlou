#ifndef NARYEXPRESSIONMODEL_H
#define NARYEXPRESSIONMODEL_H

#include "NaryExpression.h"
#include <vector>

namespace core {

	template <class T>
	class NaryExpressionModel :public NaryExpression<T>, public Expression<T> {
	private:

		NaryExpression<T>* _operator;
		std::vector<Expression<T>> _operands;

	public:
		NaryExpressionModel(NaryExpression<T>* ope = NULL, std::vector<Expression<T>> operands = NULL);
		T evaluate(std::vector<Expression<T>>) const;
		T evaluate() const;
	};

	template <class T> NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* ope, std::vector<Expression<T>> operands)
		:_operator(ope), _operands(operands)
	{}

	template <class T> T NaryExpressionModel<T>::evaluate() const {
		if (_operator != NULL) return evaluate(_operands);
		std::cout << "m";
		return NULL;
	}

	template <class T> T NaryExpressionModel<T>::evaluate(std::vector<Expression<T>> o) const {
		if (_operator != NULL) return _operator->evaluate(o);
		std::cout << "e";
		return NULL;
	}
}

#endif
