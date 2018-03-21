// FrameWorkFlou.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "ValueModel.h"
#include "AndMin.h"
#include "AndMult.h"
#include "OrMax.h"
#include "OrPlus.h"
#include "MamdaniDefuzz.h"
#include <iostream>

using namespace core;
using namespace fuzz;

int main()
{
	ValueModel<int> val1 = ValueModel<int>(5);
	std::cout << val1.evaluate() << "\n";
	ValueModel<int> val2 = ValueModel<int>(24);
	std::cout << val2.evaluate() << "\n";

	AndMin<int> min = AndMin<int>();
	std::cout << min.evaluate(&val1,&val2) << "\n";

	AndMult<int> mult = AndMult<int>();
	std::cout << mult.evaluate(&val1, &val2) << "\n";

	OrMax<int> max = OrMax<int>();
	std::cout << max.evaluate(&val1, &val2) << "\n";

	OrPlus<int> plus = OrPlus<int>();
	std::cout << plus.evaluate(&val1, &val2) << "\n";

	MamdaniDefuzz<int> mamd = MamdaniDefuzz<int>();
	
	mamd.buildShape().printShape();


}




