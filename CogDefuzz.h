#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H
#include "MamdaniDefuzz.h"

namespace fuzz
{
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {};
}


#endif