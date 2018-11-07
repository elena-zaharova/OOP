#pragma once
#include "stdafx.h"

class CTriangleErrorInvalid : public std::invalid_argument
{
public:
	CTriangleErrorInvalid(std::string const & msg);
};
