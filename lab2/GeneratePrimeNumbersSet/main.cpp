#include "stdafx.h"
#include "GeneratePrimeNumbersSet.h"

const int max = 100000000;
const int min = 2;


int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Russian");

	if ((argc < 2) || (argc > 2))
	{
		cout << "Эта программа выводит все простые числа до заданного числа, который вводит пользователь." << endl;
		cout << "Пожалуйста введите целое число" << endl;
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
		cout << "Вы вышли за придел возможных значений от 2 до 100000000." << endl;
		return 1;
	}

	return 0;
}
