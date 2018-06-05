#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H
#include "BinaryExpression.h"

using namespace core;
namespace fuzz {

	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> {
	private:
		T min, max, step;
	public:
		MamdaniDefuzz(T _min, T _max, T _step);
		T evaluate(Expression<T>* l, Expression<T>* r) const;
		virtual T defuzz(const typename Eval<T>::Shape&) const = 0;
	};

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz(T _min, T _max, T _step):min(_min), max(_max), step(_step)
	{
	}

	template<class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		return defuzz(Eval<T>::BuildShape(min, max, step, (ValueModel<T>*)l, r));
	}
}

#endif