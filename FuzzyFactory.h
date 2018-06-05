#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H
#include "Is.h"
#include "Expression.h"
#include "ExpressionFactory.h"
#include <vector>
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include "UnaryShadowExpression.h"
#include "BinaryShadowExpression.h"

namespace fuzz {

	/*
changeAnd(o:And):void 
changeOr(o:Or):void 
changeThen(o: Then): void*/

	template <class T>
	class FuzzyFactory :public ExpressionFactory<T> {
	private:

		BinaryShadowExpression<T>* and;
		BinaryShadowExpression<T>* or;
		BinaryShadowExpression<T>* then;
		BinaryShadowExpression<T>* agg;
		BinaryShadowExpression<T>* defuzz;
		UnaryShadowExpression<T>* not;

	public:
		FuzzyFactory(UnaryExpression<T> *opNot, BinaryExpression<T> *opAnd, BinaryExpression<T> *opOr, BinaryExpression<T> *opThen, BinaryExpression<T> *opAgg, BinaryExpression<T> *opDefuzz);
		//DO THE DESTRUCTOR

		//BinaryExp
		BinaryExpressionModel<T>* newAnd(Expression<T>*, Expression<T>*);
		BinaryExpressionModel<T>* newOr(Expression<T>*, Expression<T>*);
		BinaryExpressionModel<T>* newThen(Expression<T>*, Expression<T>*);
		BinaryExpressionModel<T>* newAgg(Expression<T>*, Expression<T>*);
		BinaryExpressionModel<T>* newDefuzz(Expression<T>*, Expression<T>*,T,T,T);

		//UnaryExp
		UnaryExpressionModel<T>* newNot(Expression<T>*);
		UnaryExpressionModel<T>* newIs(Is<T>*, Expression<T>*);

		//changeExp
		
	};

	template <class T> FuzzyFactory<T>::FuzzyFactory(UnaryExpression<T> *opNot, BinaryExpression<T> *opAnd, BinaryExpression<T> *opOr, BinaryExpression<T> *opThen, BinaryExpression<T> *opAgg, BinaryExpression<T> *opDefuzz)
		:not(new UnaryShadowExpression<T>(opNot)), and(new BinaryShadowExpression<T>(opAnd)),
		or(new BinaryShadowExpression<T>(opOr)), then(new BinaryShadowExpression<T>(opThen)),
		agg(new BinaryShadowExpression<T>(opAgg)), defuzz(new BinaryShadowExpression<T>(opDefuzz))
	{
	}
	//DO THE DESTRUCTOR

	//BinaryExp
	template <class T> BinaryExpressionModel<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r) {
		return newBinary(and, l, r);
	}
	template <class T> BinaryExpressionModel<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r) {
		return newBinary(or, l, r);
	}
	template <class T> BinaryExpressionModel<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r) {
		return newBinary(then, l, r);
	}
	template <class T> BinaryExpressionModel<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r) {
		return newBinary(agg, l, r);
	}
	template <class T> BinaryExpressionModel<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r, T max, T min, T step) {
		return newBinary(defuzz, l, r);
	}

	//UnaryExp
	template <class T> UnaryExpressionModel<T>* FuzzyFactory<T>::newNot(Expression<T>* o) {
		return newUnary(not, o);
	}
	template <class T> UnaryExpressionModel<T>* FuzzyFactory<T>::newIs(Is<T>* s,Expression<T>* o) {
		return newUnary(s, o);
	};
}
#endif