#pragma once
class CTriangle
{
public:
	CTriangle(int side1, int side2, int side3);
	double GetSide1()const;
	double GetSide2()const;
	double GetSide3()const;
	double GetArea()const;
	double GetPerimeter()const;

private:
	double m_side1, m_side2, m_side3;
};

