#include "stdafx.h"
#include "replace.h"

string FindAndReplace(std::string const& line, std::string const& search, std::string  const& replace)
{
	string input(line);
	string replacedString;
	size_t found;
	found = input.find(search);

	while (found != std::string::npos)
	{
		replacedString = input.replace(found, search.size(), replace);
		found = input.find(search, found);
	}
	return replacedString;
}