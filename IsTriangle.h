#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H
#include "UnaryExpression.h"

namespace core {

	template <class T>
	class IsTriangle : public UnaryExpression<T> 
	{
	private:
		T min;
		T mid;
		T max;
	public:
		T evaluate(Expression* o);
	};

	template<class T> T IsTriangle<T>::evaluate(Expression * o)
	{
		if (o <= min || o >= max)
		{
			return 0;
		}
		else if (o > min && o <= mid) {
			return (o - min) / (mid - min);
		}
		else if (o > mid && o <= max) {
			return (o - mid) / (max - mid);
		}
		else
		{
			return 0;
		}
	}

}

#endif