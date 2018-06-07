#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H
#include "NaryExpression.h"

using namespace core;
namespace fuzz {

	template <class T>
	class SugenoConclusion : public NaryExpression<T> {
	private:
		std::vector<T> coeff;
	public:
		SugenoConclusion(std::vector<T>);
		T evaluate(std::vector<Expression<T>*>) const;
	};

	template<class T>
	SugenoConclusion<T>::SugenoConclusion(std::vector<T> _coeff): coeff(_coeff)
	{
	}

	template<class T>
	T SugenoConclusion<T>::evaluate(std::vector<Expression<T>*> operands) const
	{
		if (coeff.size() - 1 == operands.size()) {
			T conclusion = 0;
			for (unsigned int i = 0; i < (operands.size() - 1); i++) {
				T x = operands.at(i)->evaluate();
				T y = coeff.at(i);
				conclusion += x * y;
			}
			conclusion += coeff.back();
			return conclusion;
		}
		std::cout << "Mauvais nombre de coefficients ou d'operandes";
		return NULL;
	}
}

#endif