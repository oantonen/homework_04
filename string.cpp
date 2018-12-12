#include "string.h"
#include <iostream>

String::String() : str(new char[1] {'\0'}), str_len(0) {}

String::~String()
{
	if (str_len > 0)
		delete [] str;
}

String::String(const char *init)
{
	if (init == nullptr)
		throw std::logic_error("invalid data for initialization");
	str_len = strlen(init);
	str = new char [str_len + 1];
	std::copy(init, init+str_len, str);
	str[str_len] = '\0';
}

String::String(const String & rObj) : str_len(0)
{
	if (this != &rObj)
		*this = rObj;		
}

const char *String::getCharString(void) const {	return str; }

String & String::operator=(String const & rObj)
{
	std::cout << "operator+\n";
	if (this != &rObj)
	{

	std::cout << "operator+\n";
	std::cout << "str_len = " << str_len << '\n';
		if (rObj.length() != str_len) {
			if (str_len > 0)
				delete [] str;
			str_len = rObj.length();
			str = new char[str_len + 1];
		}
	std::cout << "operator+\n";
		const char *src = rObj.getCharString();
		//strncpy(str, src, str_len);
		std::copy(src, src + str_len, str);
		str[str_len] = '\0';	
	}
	std::cout << "operator+\n";
	return *this;
}

size_t 	String::length() const { return str_len; }

void	String::resize(size_t new_size)
{
	if (new_size < 0)
		throw std::logic_error("Size cannot be negative");
	if (new_size == 0)
	{
		delete [] str;
		str = new char[1] {'\0'};
	}
	else if (new_size != str_len)
	{
		str_len = new_size;
		char *new_str = new char[str_len + 1];
		std::copy(str, str + str_len, new_str);
		new_str[str_len] = '\0';
		delete [] str;
		str = new_str;
	}
}		
		

String &String::operator+(const String &ref) const
{
	char *new_str = new char[str_len + ref.length()];
	std::copy(str, str + str_len, new_str);
	const char *str_ref = ref.getCharString(); 
	std::copy(str_ref, str_ref + ref.length(), new_str + str_len);
	String ret;
			

}

int main()
{

	String s = {"Barcelona"};
	String s2(s);
	String s3("Madrid");
		
	std::cout << s.getCharString() << std::endl;
	std::cout << s2.getCharString() << std::endl;
	std::cout << s3.getCharString() << std::endl;
	
	s.resize(5);
	std::cout << s.getCharString() << std::endl;
	
	return 0;
}	
