#include "string.h"

String::String() : str(new char[1] {'\0'}), str_len(0) {}

String::~String()
{
	if (str_len > 0)
		delete [] str;
}

const char *String::getCharString(void) const
{
	return str;
}

String::String(const String & rObj)
{
	delete [] str;
	str_len = rObj.length();
	str = new char[str_len];
	const char *copy = rObj.getCharString();
	str = strncpy(str, copy, str_len);
	str[str_len - 1] = '\0';		
}
	
