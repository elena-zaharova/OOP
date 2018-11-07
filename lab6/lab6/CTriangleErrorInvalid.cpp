#include "stdafx.h"
#include "CTriangleErrorInvalid.h"
using namespace std;

CTriangleErrorInvalid::CTriangleErrorInvalid(string const & msg)
	: invalid_argument(msg)
{
}

