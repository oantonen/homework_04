#include <iostream>
using std::string;

int main()
{
	string s = {"Barcelona"};
	string s3("Madrid");
	string s2(s);
		
	std::cout << s << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
return 0;
}
