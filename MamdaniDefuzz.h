#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H
#include "BinaryExpression.h"
#include <iostream>

using namespace core;
namespace fuzz {

	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> {
	private:
		class Shape
		{
		private:
			const T min;
			const T max;
			const T step;
			const T size = (max - min) / step;
			T values[];
		public:
			Shape() : min(0), max(10), step(1), values(T[100]){
				for (int i = 0; i < size; i++)
				{
					values[i] = 0;
				}
			};
			void printShape() const
			{
				std::cout << '[';
				for (int i = 0; i < size; i++)
				{
					std::cout << values[i];
				}
				std::cout << ']';
			}
		};
	public:
		MamdaniDefuzz();
		T evaluate(Expression<T>* l, Expression<T>* r) const;
		//Shape buildShape(Expression<T>* result, Expression<T>* rule);
		Shape buildShape();
		//virtual T Defuzz(Shape forme) = 0;
	};

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz()
	{
	}

	template<class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		return 0;
	}

	template<class T>
	typename MamdaniDefuzz<T>::Shape MamdaniDefuzz<T>::buildShape()
	{
		Shape forme = Shape();
		return forme;
	}

}

#endif