#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H
#include"Eval.h"
#include"MamdaniDefuzz.h"

using namespace core;
namespace fuzz {

	template <class T>
	class CogDefuzz :public MamdaniDefuzz<T>
	{
	public:
		CogDefuzz(T,T,T);
		T defuzz(const typename Eval<T>::Shape&)const;
	};

	template <class T> CogDefuzz<T>::CogDefuzz(T _min, T _max, T _step):MamdaniDefuzz<T>(_min,_max,_step)
	{}


	template <class T> T CogDefuzz<T>::defuzz(const typename Eval<T>::Shape &s)const 
	{
		//std::cout << "zut";
		T x, y, num = 0, den = 0;
		for (unsigned int i = 0; i<(s.first.size() - 1); i++)
		{
			x = s.first.at(i);
			y = s.second.at(i);
			num += x*y;
			den += y;
		}
		return num / den;
	}
}

#endif