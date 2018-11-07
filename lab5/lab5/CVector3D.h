#pragma once
class CVector3D
{
public:
	//������������ ������� ������
	CVector3D();
	//������������ ������ � ��������� ������������
	CVector3D(double x0, double y0, double z0);
	//���������� ����� �������
	double GetLength()const;
	//����������� ������ (�������� ��� � ��������� �����)
	void Normalize();
	//��������� ��������� ���������� ������������ ���� ���������� ��������
	double DotProduct(CVector3D const& v1, CVector3D const& v2);
	//��������� ��������� ���������� ������������ ���� ���������� ��������
	CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2);

	CVector3D Normalize(CVector3D const& v);

	double x, y, z;
	const double e = 0.001;

	// ��������

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

