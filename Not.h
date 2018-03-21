#ifndef NOT_H
#define NOT_H
#include "UnaryExpression.h"

namespace core {

	template <class T>
	class Not : public UnaryExpression<T> {};

}

#endif