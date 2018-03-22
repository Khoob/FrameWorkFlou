#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H
#include "Expression.h"
#include <vector>
#include "UnaryExpression.h"
#include "BinaryExpression.h"

namespace fuzz {

	/*
changeAnd(o:And):void 
changeOr(o:Or):void 
changeThen(o: Then): void*/

	template <class T>
	class FuzzyFactory : ExpressionFactory {
	private:

		BinaryExpression<T> and, or , then, agg, deffuzz;
		UnaryExpression<T> not;

	public:
		FuzzyFactory();
		//DO THE DESTRUCTOR

		//BinaryExp
		ExpressionModel<T> newAnd(Expression<T>, Expression<T>);
		ExpressionModel<T> newOr(Expression<T>, Expression<T>);
		//ExpressionModel<T> newThen(Expression<T>, Expression<T>);
		//ExpressionModel<T> newAgg(Expression<T>, Expression<T>);
		ExpressionModel<T> newDefuzz(Expression<T>, Expression<T>);

		//UnaryExp
		ExpressionModel<T> newNot(Expression<T>);
		ExpressionModel<T> newIs(Is<T>, Expression<T>);

		//changeExp
		
	};

	template <class T> FuzzyFactory<T>::FuzzyFactory() {}
	//DO THE DESTRUCTOR

	//BinaryExp
	template <class T> ExpressionModel<T> FuzzyFactory::newAnd(Expression<T> l, Expression<T> r) {
		return newBinary(and, l, r);
	}
	template <class T> ExpressionModel<T> FuzzyFactory::newOr(Expression<T> l, Expression<T> r) {
		return newBinary(or, l, r);
	}
	/*template <class T> ExpressionModel<T> FuzzyFactory::newThen(Expression<T> l, Expression<T> r) {
		return newBinary(then, l, r);
	}
	template <class T> ExpressionModel<T> FuzzyFactory::newAgg(Expression<T> l, Expression<T> r) {
		return newBinary(agg, l, r);
	}*/
	template <class T> ExpressionModel<T> FuzzyFactory::newDefuzz(Expression<T> l, Expression<T> r) {
		return newBinary(defuzz, l, r);
	}

	//UnaryExp
	template <class T> ExpressionModel<T> FuzzyFactory::newNot(Expression<T> o) {
		return newUnary(not, o);
	}
	template <class T> ExpressionModel<T> FuzzyFactory::newIs(Is s,Expression<T> o) {
		return newUnary(s, o);
	};
}
#endif