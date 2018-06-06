#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H
#include "NaryExpression.h"

using namespace core;
namespace fuzz {

	template <class T>
	class SugenoDefuzz : public NaryExpression<T> {
	private:
		std::vector<T> conclusions;
	public:
		SugenoDefuzz(std::vector<T>);
		T evaluate(std::vector<Expression<T>>) const;
	};

	template<class T>
	SugenoDefuzz<T>::SugenoDefuzz(std::vector<T> _conclusions):conclusions(_conclusions)
	{
	}

	template<class T>
	T SugenoDefuzz<T>::evaluate(std::vector<Expression<T>> operands) const
	{
		T x, y, num = 0, den = 0;
		for (unsigned int i = 0; i < (operands.size() - 1); i++) {
			x = conclusions.at(i);
			y = operands.at(i)
			num += x*y;
			den += y;
			}
		return num / den;
	}
}

#endif