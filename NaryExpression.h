#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H
#include "Expression.h"
#include <vector>

namespace core {

	template <class T>
	class NaryExpression {
	public:
		virtual T evaluate(std::vector<Expression<T>*>) const = 0;

	};

}

#endif
