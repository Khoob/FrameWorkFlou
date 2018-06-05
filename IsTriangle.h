#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H
#include "Is.h"

namespace core {

	template <class T>
	class IsTriangle : public Is<T> 
	{
	private:
		T min;
		T mid;
		T max;
	public:
		IsTriangle(T _min, T _mid, T _max);
		T evaluate(Expression<T>* o) const;
	};

	template<class T>
	IsTriangle<T>::IsTriangle(T _min, T _mid, T _max): min(_min), mid(_mid), max(_max)
	{
	}

	template<class T> T IsTriangle<T>::evaluate(Expression<T>* o) const
	{
		T ev = o->evaluate();
		if (ev <= min || ev >= max)
			return 0;
		else if (ev > min && ev <= mid)
			return (ev - min) * 100 / (mid - min);
		else if (ev > mid && ev <= max)
			return (ev - mid) * 100 / (max - mid);
		else
			return 0;
	}

}

#endif