#include "stdafx.h"
#include <iostream>
#include "CTriangle.h"
#include "CTriangleDomainError.h"
#include "CTriangleErrorInvalid.h"

using namespace std;

const double NotNegativeNumber(const int & value, const string & argName = string())
{
	setlocale(LC_ALL, "Russian");
	if (value >= 0)
	{
		return value;
	}
	throw CTriangleErrorInvalid("Аргумент не может быть отрицательным.");
}


CTriangle::CTriangle(int side1, int side2, int side3)
	: m_side1(NotNegativeNumber(side1, "Side1"))
	, m_side2(NotNegativeNumber(side2, "Side2"))
	, m_side3(NotNegativeNumber(side3, "Side3"))
{
	setlocale(LC_ALL, "Russian");
	if (side1 > side2 + side3)
	{
		throw CTriangleDomainError("Не треугольник");
	}


    if (side2 > side1 + side3)
	{
		throw CTriangleDomainError("Не треугольник");
	}


    if (side3 > side2 + side1)
	{
		throw CTriangleDomainError("Не треугольник");
	} 
}

double CTriangle:: GetSide1()const
{
	return m_side1;
}

double CTriangle::GetSide2()const
{
	return m_side2;
}

double CTriangle::GetSide3()const
{
	return m_side3;
}

double CTriangle::GetPerimeter()const
{
	return(m_side1 + m_side2 + m_side3);
}

double CTriangle::GetArea()const
{
	double halfPerimeter = GetPerimeter() / 2;
	return sqrt(halfPerimeter * (halfPerimeter - m_side1) * (halfPerimeter - m_side2) * (halfPerimeter - m_side3));
}


