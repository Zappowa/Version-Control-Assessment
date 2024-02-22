#include "StringClass.h"
#include <iostream>

using namespace std;

int main()
{
	// ------------------ Length()
	/*char str_Input[50];

	cout << "Enter: ";
	cin >> str_Input;

	String* fLength = new String();
	fLength->Length(str_Input);*/

	// ------------------ CharacterAt(Index)

	/*size_t index;

	cout << "Index: ";
	cin >> index;

	String* fChrt = new String();
	fChrt->CharacterAt(index);*/

	// ------------------ EqualTo(str)

	String* str01 = new String();
	String* str02 = new String();
	
	char inp01[12];
	char inp02[12];

	cout << "I will compare two strings!!\n" << "1: ";
	cin >> str01->cStr;
	cout << "2: ";
	cin >> str02->cStr;
	cout << "\n";

	cout << str01->EqualTo(*str02);



	// ------------------ Append(str)
	// ------------------ Prepend(str)
	// ------------------ CStr()
	// ------------------ ToLower()
	// ------------------ ToUpper()
	// ------------------ Find(findString)
	// ------------------ Find(startIndex, findString)
	// ------------------ Replace(findString, replaceString)
	// ------------------ ReadFromConsole()
	// ------------------ WriteToConsole()
	// ------------------ Equality Operator(==)
	// ------------------ Subscript Operator([])
	// ------------------ Assignment Operator(=)
	// ------------------ LessThan Operator(<)
	// ------------------ Plus Operator(+)
	// ------------------ Plus Equals operator (+=)
	
}
