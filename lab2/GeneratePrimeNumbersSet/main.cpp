#include "stdafx.h"
#include "GeneratePrimeNumbersSet.h"

const int max = 100000000;
const int min = 2;


int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Russian");

	if ((argc < 2) || (argc > 2))
	{
		cout << "��� ��������� ������� ��� ������� ����� �� ��������� �����, ������� ������ ������������." << endl;
		cout << "���������� ������� ����� �����" << endl;
		return 1;
	}

	int upperBound;

	upperBound = atoi(argv[1]);

	if ((upperBound > min) || (upperBound < max))
	{
		set <int> primeNumbers;
		primeNumbers = GeneratePrimeNumbersSet(upperBound);
		copy(primeNumbers.begin(), primeNumbers.end(), ostream_iterator<int>(cout, " "));

	}
	else
	{
		cout << "�� ����� �� ������ ��������� �������� �� 2 �� 100000000." << endl;
		return 1;
	}

	return 0;
}
