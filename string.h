#ifndef STRING_H
# define STRING_H

#include <cstring>

using std::size_t;
class String 
{

private:
	char *str;
	size_t str_len;
public:
	String();
	String(const char *s);
	~String();
	String(const String &);
	
	const char *getCharString(void) const;

	String &operator=(const String &);

	String &operator+(const String &) const;
	String &operator+=(const String &);
	
	String &operator==(const String &);
	String &operator!=(const String &);

	String &operator<<(const String &);
	String &operator>>(const String &);

	String &append(const String &);
	int 	compare(const String &) const;
	size_t	length() const;
	void	resize(size_t new_size);
	void	clear(void);
	String &swap(const String &);

	const char *substr(const char *);  //should search for a specified substring into existing one and return position of the 1st character
	void	insert(const char *ins, size_t pos); //means inserting one character or another string into a specified position
};

#endif
