#include "StringClass.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "\nStart of Code!\n";
	cout << "===========================================\n";


	// ------------------ Length()
	/*char str_Input[50];

	cout << "Enter: ";
	cin >> str_Input;

	String* fLength = new String();
	int out = fLength->Length(str_Input);
	cout << "Your word has a length of " << out << endl;*/

	// ------------------ CharacterAt(Index)

	/*size_t index;

	cout << "Index: ";
	cin >> index;

	String* fChrt = new String();
	fChrt->CharacterAt(index);*/

	// ------------------ EqualTo(str)

	/*String* str01 = new String("Hello");
	String* str02 = new String("Hello");

	cout << "\nI will compare two strings!!\n\n";
	cout << "1: " << str01->CStr() << "\n2: " << str02->CStr() << endl;

	cout << str01->EqualTo(*str02);*/

	// ------------------ Append(str)
	
	/*String* phrase01 = new String("Hello");
	String* phrase02 = new String("World!");

	cout << "\nFirst Phrase: " << phrase01->CStr() << "\nSecond Phrase: " << phrase02->CStr() << endl;
	phrase01->Append(*phrase02);*/

	// ------------------ Prepend(str)

	/*String* word01 = new String("Hello");
	String* word02 = new String("World!");

	cout << "\nFirst Phrase: " << word01->CStr() << "\nSecond Phrase: " << word02->CStr() << endl;
	word01->Prepend(*word02);*/

	// ------------------ CStr()
	
	/*String blank;
	String contain("Hello");

	cout << "\nI am blank: (" << blank.CStr() << ")";
	cout << "\nI am not blank: (" << contain.CStr() << ")\n";*/

	// ------------------ ToLower()

	/*String upper("I AM UPPERCASE");
	
	cout << "\nOriginal: " << upper.CStr() << endl;
	upper.ToLower();*/
	
	// ------------------ ToUpper()
	
	/*String lower("i am lowercase");

	cout << "\nOriginal: " << lower.CStr() << endl;
	lower.ToUpper();*/

	// ------------------ Find(findString)
	
	/*String strTest("Please Test This String!");
	String strFind("T");

	cout << "\n" << "Location - " << strTest.Find(strFind);*/

	// ------------------ Find(startIndex, findString)
	
	/*String test("Please Test This String!");

	const int Pos = 0;
	String findStr("T");

	cout << "\n" << "Location - " << test.Find(Pos, findStr);*/

	// ------------------ Replace(findString, replaceString)
	
	String testSubject("Replace Stuff Inside Me!");
	String find("l");
	String change("M");

	testSubject.Replace(find, change);

	// ------------------ ReadFromConsole()
	// ------------------ WriteToConsole()
	// ------------------ Equality Operator(==)
	// ------------------ Subscript Operator([])
	// ------------------ Assignment Operator(=)
	// ------------------ LessThan Operator(<)
	// ------------------ Plus Operator(+)
	// ------------------ Plus Equals operator (+=)
	
	
	cout << "\n\n===========================================";
	cout << "\nEnd of Code!";
}
