#ifndef STRING_H
# define STRING_H

#include <cstring>
#include <iostream>

using std::size_t;
class String 
{

private:
	char	*str;
	size_t	str_len;
	size_t	capacity_;

public:
	String();
	String(const char *s);
	~String();
	String(const String &);
	
	char	*getCharString(void) const;

	String	&operator=(const String &);

	String	&operator+=(const String &);
	
	friend	std::ostream& operator<<(std::ostream& os, const String& obj);
	friend	std::istream& operator>>(std::istream& is, String& obj);
	
	String	append(const String &);
	int		compare(const String &) const;
	size_t	length() const;
	size_t	capacity() const;
	void	resize(size_t new_size);
	void	clear(void);
	void	swap(String &);

	const char *substr(const char * ) const;  //should search for a specified substring into existing one and return position of the 1st character
	void	insert(const char *ins, size_t pos); //means inserting one character or another string into a specified position
};

	inline bool operator==(const String &lhs, const String &rhs)
	{
		return std::equal(lhs.getCharString(), lhs.getCharString()\
		 + lhs.length(), rhs.getCharString());
	}
	inline bool operator!=(const String& lhs, const String& rhs ) 
	{
		return !(operator==(lhs, rhs));
	}
	
	inline String &operator+(String & lhs, const String &rhs)
	{
		lhs += rhs;
		return lhs;
	}

#endif
