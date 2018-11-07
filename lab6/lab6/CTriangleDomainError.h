#pragma once
#include "stdafx.h"

class CTriangleDomainError : public std::domain_error
{
public:
	CTriangleDomainError(std::string const & msg);
};
