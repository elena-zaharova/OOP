#include "stdafx.h"
#include "..\GeneratePrimeNumbersSet\GeneratePrimeNumbersSet.h"

set<int> exampleFirst = GeneratePrimeNumbersSet(14);
set<int> exampleSecond = GeneratePrimeNumbersSet(14);
set<int> exampleThird = GeneratePrimeNumbersSet(14);
set<int> exampleForth = GeneratePrimeNumbersSet(14);


TEST_CASE("GeneratePrimeNumbersSet Test")
{
	CHECK(exampleFirst.size() == 5);
	

}

