#include "string.h"
#include <iostream>

String::String() : str(new char[100] {'\0'}), str_len(0), capacity(100) {}

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
	capacity = str_len + 1;
	str = new char [capacity];
	std::copy(init, init+str_len, str);
	str[str_len] = '\0';
}

String::String(const String & rObj) : str_len(0), capacity(0)
{
	if (this != &rObj)
		*this = rObj;		
}

 char *String::getCharString(void) const {	return str; }

String & String::operator=(String const & rObj)
{
	if (this != &rObj)
	{
		if (rObj.length() >= capacity) {
			if (str_len > 0)
				delete [] str;
			str_len = rObj.length();
			capacity = str_len + 1;
			str = new char[capacity];
		}
		this->clear();
		str_len = rObj.length();
		char *src = rObj.getCharString();
		std::copy(src, src + str_len, str);
		str[str_len] = '\0';	
	}
	return *this;
}

size_t 	String::length() const { return str_len; }

void	String::resize(size_t new_size)
{
	if (new_size < 0)
		throw std::logic_error("Size cannot be negative");
	if (new_size < str_len)
		throw std::logic_error("New_size can't be less than size of orig string");
	if (new_size == 0)
	{
		delete [] str;
		str = new char[1] {'\0'};
		str_len = 0;
		capacity = 1;
	}
	else if (new_size > capacity)
	{
		capacity = new_size + 1;
		char *new_str = new char[capacity];
		std::copy(str, str + str_len, new_str);
		new_str[str_len] = '\0';
		delete [] str;
		str = new_str;
	}
}		
		

String &String::operator+=(const String &ref) 
{
	size_t new_len = str_len + ref.length();
	capacity = new_len + 1;
	char *new_str = new char[capacity];
	std::copy(str, str + str_len, new_str);
	const char *str_ref = ref.getCharString(); 
	std::copy(str_ref, str_ref + ref.length(), new_str + str_len);
	delete [] str;
	this->str = new_str;
	this->str_len = new_len;
	return *this;
}

/*String operator+(String lhs, const String & rhs)
{
	lhs += rhs;
	return lhs;
}
*/
bool operator==(const String & lhs, const String & rhs)
{
	const char *str_l = lhs.getCharString();
	const char *str_r = rhs.getCharString();
	if (strlen(str_l) != strlen(str_r))
		return 0;
	return std::equal(str_l, str_l + lhs.length(), str_r);
}

int String::compare(const String & obj) const
{
	return operator==(*this, obj);
} 

String	String::append(const String & obj)
{
	return operator+(*this, obj);
}

void	String::clear(void)
{
	for (size_t s = 0; s < str_len; s++)
		str[s] = '\0';
	str_len = 0;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	os << obj.getCharString();
	return os;
}

std::istream& operator>>(std::istream& is, String & obj)
{
	size_t left = obj.capacity - obj.str_len - 1; 
	std::cout << "Type string. Not more than " 
			<< left
			<< " symbols is allowed.\n";
	is >> obj.str;
	
	return is;
}

String&	String::swap(String & obj)
{
	char *tmp = str;
	size_t tmp_len = str_len;
	size_t capacity_tmp = capacity;
	capacity = obj.capacity;
	str_len = obj.length();
	str = obj.getCharString();
	obj.str = tmp;
	obj.str_len = tmp_len;
	obj.capacity = capacity_tmp;
}

const char*	String::substr(const char *find) const
{
	for (size_t i = 0; str[i]; i++)
	{
		if (str[i] == *find)
		{
			for (size_t t = 0; find[t] && str[i + t]; t++)
			{
				if (str[i + t] != find[t])
					break;
				else if (find[t + 1] == '\0')
					return &str[i];
			}
		}
	}
	return nullptr;
}

void	String::insert(const char *ins, size_t pos)
{
	if (pos > str_len)
		throw std::logic_error("String position is out of range!");	
	size_t ins_len = strlen(ins);
	if (ins_len == 0)
		return;
	if (str_len + ins_len >= capacity)
		resize(str_len + ins_len);
	size_t tmp_size = str_len - pos;	
	char tmp[tmp_size + 1];
	char *to_tmp = getCharString();
	std::copy(to_tmp + pos, to_tmp + str_len, tmp);
	tmp[tmp_size] = '\0';
	std::copy(const_cast<char*>(ins), 
const_cast<char*>(ins + ins_len), str + pos);
	std::copy(tmp, tmp + tmp_size, str + pos + ins_len);
}
	
int main()
{
using std::cout;
using std::endl;

	const char *char_string = "Drum'n'";
	String s(char_string);
cout << "Constructor from char string\nString s = " << s << endl;
	String s2(s);
cout << "Copy constructor\nString s2 = " << s2 << endl;
	String s3("Bass");
	String s4 = s3;
cout << "Assignment operator\nString s3 = " << s3 << endl;

cout << "Operator += " << s + s3 << endl;

cout << "Operator >> ";
String input;
std::cin >> input;
cout << input << endl;


	return 0;
}	
