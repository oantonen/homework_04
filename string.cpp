#include "string.h"
#include <iostream>

//String::String() : str(new char[1] {'\0'}), str_len(0) {}

String::~String()
{
	if (str_len > 0)
		delete [] str;
}

String::String(const char *init)
{
	//if (init != nullptr)
	{
		str_len = strlen(init);
		str = new char [str_len + 1];
		strncpy(str, init, str_len);
		str[str_len] = '0';
	}
}

String::String(const String & rObj)
{
	//if (rObj.getCharString() != nullptr)
	{
		delete [] str;
		str_len = rObj.length();
		str = new char[str_len + 1];
		const char *copy = rObj.getCharString();
		str = strncpy(str, copy, str_len);
		str[str_len] = '\0';		
	}
}

const char *String::getCharString(void) const {	return str; }

String & String::operator=(String const & rObj)
{
	if (this != &rObj)
	{
	
	}
	return *this;
}		
size_t 	String::length() const { return str_len; }


int main()
{
	const char *sss = nullptr;
	String s = {sss};
	String s2 = s;
	//std::cout << s2.getCharString();
	return 0;
}	
