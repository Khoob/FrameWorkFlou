// FrameWorkFlou.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "ValueModel.h"
#include "AndMin.h"
#include "AndMult.h"
#include "OrMax.h"
#include "OrPlus.h"
#include "AggMax.h"
#include "CogDefuzz.h"
#include "IsTriangle.h"
#include "NotMinus1.h"
#include "ThenMin.h"
#include "FuzzyFactory.h"
#include <iostream>

using namespace core;
using namespace fuzz;

int main()
{	/*
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
	
	//mamd.buildShape().printShape();
	*/
	NotMinus1<float> opNot;
	AndMin<float> opAnd;
	OrMax<float> opOr;
	ThenMin<float> opThen;
	AggMax<float> opAgg;
	CogDefuzz<float> opDefuzz(0,25,1);
	//fuzzy expession factory
	FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);

	//membership function
	IsTriangle<float> poor(-5, 0, 5);
	IsTriangle<float> good(0, 5, 10);
	IsTriangle<float> excellent(5, 10, 15);

	IsTriangle<float> rancid(-5, 0, 5);
	IsTriangle<float> delicious(5, 10, 15);

	IsTriangle<float> cheap(0, 5, 10);
	IsTriangle<float> average(10, 15, 20);
	IsTriangle<float> generous(20, 25, 30);
	//values
	ValueModel<float> service(0);
	ValueModel<float> food(0);
	ValueModel<float> tips(0);
	Expression<float> *r =
		f.newAgg(
			f.newAgg(
				f.newThen(
					f.newOr(
						f.newIs(&poor, &service),
						f.newIs(&rancid,&food)
						),
					f.newIs(&cheap, &tips)
				),
				f.newThen(
					f.newIs(&good, &service),
					f.newIs(&average, &tips )
				)
			),
			f.newThen(
				f.newOr(
					f.newIs(&excellent, &service),
					f.newIs(&delicious, &food)
				),
				f.newIs(&generous, &tips)
			)
		);
	//defuzzification
	Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);
	//apply input
	float s;
	while (true)
	{
		std::cout << "service : "; std::cin >> s;
		service.setValue(s);
		std::cout << "food : "; std::cin >> s;
		food.setValue(s);
		std::cout << "tips -> " << system->evaluate() << std::endl;
	}


}




