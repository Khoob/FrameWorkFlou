#ifndef AGG_H
#define AGG_H
#include "BinaryExpression.h"

namespace core {

	template <class T>
	class Agg : public BinaryExpression<T> {};

}

#endif