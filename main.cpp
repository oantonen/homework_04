#include "string.h"

int main()
{
	using std::cout;
	using std::endl;

	const char *char_string = "Drum'n'";
	String s(char_string);
	cout << "Constructor from char string\nString s = " << s << "\n\n";
	String s2(s);

	cout << "Copy constructor\nString s2 = " << s2 << "\n\n";
	String s3("Bass");
	String s4 = s3;

	cout << "Assignment operator\nString s3 = " << s3 << "\n\n";

	cout << "Operator += " << s + s3 << "\n\n";


	String s_a1 = ("Peace, Love, ");
	String s_a2 = ("Unity, Respect.");
	cout << "Append string \"Peace, Love, \" && \"Unity, Respect.\"\n";
	cout << "Append function uses operator+\n";
	s_a1.append(s_a2);
	cout << s_a1 << "\n\n";


	String s_c1 = "Kyiv";
	String s_c2 = "Kiev";
	String s_c3 = "Kyiv";
	cout << "Compare 2 strings \"Kyiv\" && \"Kiev\" (using operator ==)\n";
	cout << s_c1.compare(s_c2) << "\n";


	cout << "Compare 2 strings \"Kyiv\" && \"Kyiv\" (using operator ==)\n";

	
	cout << s_c1.compare(s_c3) << "\n";

	cout << "Compare 2 strings \"Kyiv\" && \"Kiev\" (using operator !=)\n";
	cout << (s_c1 != s_c2) << "\n\n";

	cout << "Length of string \"Kyiv\"\n";
	cout << s_c1.length() << "\n\n";


	cout << "Resize string \"Kyiv\"(s_c1) into 42 bytes\n";
	cout << "Starting capacity of string: " <<  s_c1.capacity() << endl;
	s_c1.resize(41);
	cout << "Capacity after resizing: " <<  s_c1.capacity() << "\n\n";


	cout << "String before clearing: " << s_c1 << endl;
	s_c1.clear();
	cout << "String after clearing: " << s_c1 << "\n\n";

	
	cout << "string1: " << s_a1 << endl;
	cout << "string2: " << s_a2 << endl;
	cout << "Swaping strings ..." << endl;
	s_a1.swap(s_a2);
	cout << "string1: " << s_a1 << endl;
	cout << "string2: " << s_a2 << "\n\n";


	cout << "Searching for a substring \"World\" in string:" << endl;
	String s_sub = "C++ has conquered the World, Ha-ha-ha!";
	cout << s_sub << endl;
	cout << s_sub.substr("World") << "\n\n";


	cout << "Inserting string \"_Insertion_\" to the previous string\n";
	s_sub.insert("Insertion", 8);
	cout << s_sub << "\n\n";


	cout << "Operator >> ";
	String input;
	std::cin >> input;
	cout << input << endl;


	return 0;
}	
