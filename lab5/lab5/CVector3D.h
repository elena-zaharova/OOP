#pragma once
class CVector3D
{
public:
	//Конструирует нулевой вектор
	CVector3D();
	//Конструирует вектор с заданными координатами
	CVector3D(double x0, double y0, double z0);
	//Возвращает длину вектора
	double GetLength()const;
	//Нормализует вектор (приводит его к единичной длине)
	void Normalize();
	//Вычисляет результат скалярного произведения двух трехмерных векторов
	double DotProduct(CVector3D const& v1, CVector3D const& v2);
	//Вычисляет результат векторного произведения двух трехмерных векторов
	CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2);

	CVector3D Normalize(CVector3D const& v);

	double x, y, z;
	const double e = 0.001;

	// операции

	CVector3D const operator +(CVector3D const & vector) const;
	CVector3D const operator -(CVector3D const & vector) const;
	CVector3D const operator +() const;
	CVector3D const operator -() const;
	CVector3D const operator +=(CVector3D const & vector);
	CVector3D const operator -=(CVector3D const & vector);
	CVector3D const operator *(double & scolar) const;
	CVector3D const operator /(double & scolar) const;
	CVector3D const operator *=(double & scolar);
	CVector3D const operator /=(double & scolar);
	bool operator ==(CVector3D const & vector) const;
	bool operator !=(CVector3D const & vector) const;

};

CVector3D const operator *(double & scolar, CVector3D const & vector);

