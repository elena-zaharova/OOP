#include "stdafx.h"
#include "CTriangleDomainError.h"
using namespace std;

CTriangleDomainError::CTriangleDomainError(string const & msg)
	: domain_error(msg)
{
}