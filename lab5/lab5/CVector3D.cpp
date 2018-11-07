#include "stdafx.h"
#include "CVector3D.h"
#include <iostream>
#include <cmath>

using namespace std;

// Методы

CVector3D::CVector3D()
{
	x = 0;
	y = 0;
	z = 0;
}

CVector3D::CVector3D(double x0, double y0, double z0)
	:x(x0)
	,y(y0)
	,z(z0)
{
}

double CVector3D::GetLength() const
{
	return sqrt(x * x + y * y + z * z);
}

void  CVector3D::Normalize()
{
	double len = GetLength();
	x /= len;
	y /= len;
	z /= len;
}

double CVector3D::DotProduct(CVector3D const& v1, CVector3D const& v2)
{
	return (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
}

CVector3D CVector3D::CrossProduct(CVector3D const& v1, CVector3D const& v2)
{
	double newX = v1.y*v2.z - v1.z*v2.y ;
	double newY = -(v1.x*v2.z - v1.z*v2.x);
	double newZ = v1.x*v2.y - v1.y*v2.x;
	return CVector3D(newX, newY, newZ);
}

CVector3D CVector3D::Normalize(CVector3D const& v)
{
	double len = v.GetLength();
	x = v.x / len;
	y = v.y / len;
	z = v.z / len;
	return CVector3D(x, y, z);
}

// Операции

CVector3D const CVector3D::operator +(CVector3D const & vector) const
{
	return CVector3D(x + vector.x, y + vector.y, z + vector.z);
}

CVector3D const CVector3D::operator -(CVector3D const & vector) const
{
	return CVector3D(x - vector.x, y - vector.y, z - vector.z);
}

CVector3D const CVector3D::operator +() const
{
	return CVector3D(x, y, z);
}

CVector3D const CVector3D::operator -() const
{
	return CVector3D(-x, -y, -z);
}

CVector3D const CVector3D::operator +=(CVector3D const & vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

CVector3D const CVector3D::operator -=(CVector3D const & vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}

CVector3D const CVector3D::operator *(double & scolar) const
{
	return CVector3D(x * scolar, y * scolar, z * scolar);
}

CVector3D const operator *(double & scolar, CVector3D const & vector)
{
	return CVector3D(vector.x * scolar, vector.y * scolar, vector.z * scolar);
}

CVector3D const CVector3D::operator /(double & scolar) const
{
	if(scolar < e)
	{
		throw invalid_argument("Число меньше нуля");
	}
	return CVector3D(x / scolar, y / scolar, z / scolar);
}

CVector3D const CVector3D::operator *=(double & scolar) 
{
	x *= scolar;
	y *= scolar;
	z *= scolar;

	return *this;
}

CVector3D const CVector3D::operator /=(double & scolar)
{
	if (scolar < e)
	{
		throw invalid_argument("Число меньше нуля");
	}
	x /= scolar;
	y /= scolar;
	z /= scolar;

	return *this;
}

bool  CVector3D::operator ==(CVector3D const & vector) const
{
	bool trueX = (abs(x - vector.x) < e);
	bool trueY = (abs(y - vector.y) < e);
	bool trueZ = (abs(z - vector.z) < e);

	return (trueX && trueY && trueZ);
}

bool  CVector3D::operator !=(CVector3D const & vector) const
{
	bool trueX = (abs(x - vector.x) > e);
	bool trueY = (abs(y - vector.y) > e);
	bool trueZ = (abs(z - vector.z) > e);

	return (trueX || trueY || trueZ);
}
