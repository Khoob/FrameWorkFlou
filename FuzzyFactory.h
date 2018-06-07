#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H
#include "Is.h"
#include "Expression.h"
#include "ExpressionFactory.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include "NaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include "NaryExpressionModel.h"
#include "UnaryShadowExpression.h"
#include "BinaryShadowExpression.h"
#include "NaryShadowExpression.h"
#include <vector>

namespace fuzz {

	template <class T>
	class FuzzyFactory :public ExpressionFactory<T> {
	private:

		BinaryShadowExpression<T>* _or;
		BinaryShadowExpression<T>* _and;
		BinaryShadowExpression<T>* _then;
		BinaryShadowExpression<T>* _agg;
		BinaryShadowExpression<T>* _defuzz;
		NaryShadowExpression<T>* _sugeno;
		UnaryShadowExpression<T>* _not;

	public:
		FuzzyFactory(UnaryExpression<T> *opNot, BinaryExpression<T> *opAnd, BinaryExpression<T> *opOr, BinaryExpression<T> *opThen, BinaryExpression<T> *opAgg, BinaryExpression<T> *opDefuzz = NULL,NaryExpression<T> *opSugeno = NULL);
		//DO THE DESTRUCTOR

		ValueModel<T>* newValue(T);

		//NaryExp
		NaryExpressionModel<T>* newSugeno(std::vector<Expression<T>*>);

		//BinaryExp
		BinaryExpressionModel<T>* newAnd(Expression<T>*, Expression<T>*);
		BinaryExpressionModel<T>* newOr(Expression<T>*, Expression<T>*);
		BinaryExpressionModel<T>* newThen(Expression<T>*, Expression<T>*);
		BinaryExpressionModel<T>* newAgg(Expression<T>*, Expression<T>*);
		BinaryExpressionModel<T>* newDefuzz(Expression<T>*, Expression<T>*,T,T,T); //triple T ne sert à rien pour le moment

		//UnaryExp
		UnaryExpressionModel<T>* newNot(Expression<T>*);
		UnaryExpressionModel<T>* newIs(Is<T>*, Expression<T>*);

		//changeExp
		void changeOr(BinaryExpression<T>*);
		void changeAnd(BinaryExpression<T>*);
		void changeThen(BinaryExpression<T>*);
		void changeAgg(BinaryExpression<T>*);
		void changeDefuzz(BinaryExpression<T>*);
		void changeSugeno(NaryExpression<T>*);
		void changeNot(UnaryExpression<T>*);
		
	};

	template <class T> FuzzyFactory<T>::FuzzyFactory(UnaryExpression<T> *opNot, BinaryExpression<T> *opAnd, BinaryExpression<T> *opOr, BinaryExpression<T> *opThen, BinaryExpression<T> *opAgg, BinaryExpression<T> *opDefuzz, NaryExpression<T> *opSugeno)
		:_not(new UnaryShadowExpression<T>(opNot)), _and(new BinaryShadowExpression<T>(opAnd)),
		_or(new BinaryShadowExpression<T>(opOr)), _then(new BinaryShadowExpression<T>(opThen)),
		_agg(new BinaryShadowExpression<T>(opAgg)), _defuzz(new BinaryShadowExpression<T>(opDefuzz)),
		_sugeno(new NaryShadowExpression<T>(opSugeno))
	{
	}
	//DO THE DESTRUCTOR

	template <class T> ValueModel<T>* FuzzyFactory<T>::newValue(T val) {
		return new ValueModel<T>(val);
	}

	//NaryExp
	template <class T> NaryExpressionModel<T>* FuzzyFactory<T>::newSugeno(std::vector<Expression<T>*> exp) {
		return FuzzyFactory<T>::newNary(_sugeno, exp);
	}

	//BinaryExp
	template <class T> BinaryExpressionModel<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r) {
		return FuzzyFactory<T>::newBinary(_and, l, r);
	}
	template <class T> BinaryExpressionModel<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r) {
		return FuzzyFactory<T>::newBinary(_or, l, r);
	}
	template <class T> BinaryExpressionModel<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r) {
		return FuzzyFactory<T>::newBinary(_then, l, r);
	}
	template <class T> BinaryExpressionModel<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r) {
		return FuzzyFactory<T>::newBinary(_agg, l, r);
	}
	template <class T> BinaryExpressionModel<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r, T max, T min, T step) {
		return FuzzyFactory<T>::newBinary(_defuzz, l, r);
	}

	//UnaryExp
	template <class T> UnaryExpressionModel<T>* FuzzyFactory<T>::newNot(Expression<T>* o) {
		return FuzzyFactory<T>::newUnary(_not, o);
	}
	template <class T> UnaryExpressionModel<T>* FuzzyFactory<T>::newIs(Is<T>* s,Expression<T>* o) {
		return FuzzyFactory<T>::newUnary(s, o);
	}

	template <class T> void FuzzyFactory<T>::changeOr(BinaryExpression<T>* opOr) {
		_or->takeTarget(opOr);
	}
	template <class T> void FuzzyFactory<T>::changeAnd(BinaryExpression<T>* opAnd) {
		_and->takeTarget(opAnd);
	}
	template <class T> void FuzzyFactory<T>::changeThen(BinaryExpression<T>* opThen) {
		_then->takeTarget(opThen);
	}
	template <class T> void FuzzyFactory<T>::changeAgg(BinaryExpression<T>* opAgg) {
		_agg->takeTarget(opAgg);
	}
	template <class T> void FuzzyFactory<T>::changeDefuzz(BinaryExpression<T>* opDefuzz) {
		_defuzz->takeTarget(opDefuzz);
	}
	template <class T> void FuzzyFactory<T>::changeNot(UnaryExpression<T>* opNot) {
		_not->takeTarget(opNot);
	}
	template <class T> void FuzzyFactory<T>::changeSugeno(NaryExpression<T>* opSugeno) {
		_sugeno->takeTarget(opSugeno);
	}


}
#endif