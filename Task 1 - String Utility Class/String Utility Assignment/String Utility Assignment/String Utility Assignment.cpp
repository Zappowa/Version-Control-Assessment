#include "StringClass.h"
#include <iostream>

using namespace std;

int main()
{
	// This Main Function is full of organisation and built to have a clean output to the console
	// Start and End Code Section, headers for each function.

	/*
	To save lines of code and repetitive commenting I will comment on the code generally which will still cover everything.

	At the top of each function I assign new String() to my pointers so I don't have to recreate them and have a huge amount of pointers at the end to delete.
	I use max 3 at once and give them strings or leave blank based on the function.
	Most of the time I will use size_t for numbers because a lot of the code is based around lengths and sizes

	Underneath most of the code is just for show and making it look nice, showing how it works.
	To access the String Variables before I call a function I will use the cStr() or WriteToConsole()
	These access the Variable from the private class and print it out, the value will change if called after a function.

	At the end I delete all the pointers creating and set them to nullptr to prevent any memory leaks.
	*/

	cout << "\nStart of Code!\n";
	cout << "===========================================\n";

	// Main String Pointer Variables 
	String* str01 = new String();
	String* str02 = new String();
	String* aux = new String();

	// ----------- Length() ----------- \\

	str01 = new String("What is my length?");
	size_t out = str01->Length();


	cout << "\n-- Length()";
	cout << "\nThe length of (" << str01->CStr() << ") is " << out << "\n";

	// ----------- CharacterAt(Index) ----------- \\

	str01 = new String("Hello");
	size_t index = 2;

	cout << "\n-- CharacterAt()";
	cout << "\nThe Character at (" << index << ") in '" << str01->CStr() << "' is '";
	cout << str01->CharacterAt(index) << "'\n";

	// ----------- EqualTo(str) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("Hello");

	cout << "\n-- EqualTo()";
	cout << "\nString 1: " << str01->CStr() << ", String 2: " << str02->CStr();
	if (str01->EqualTo(*str02) == true) { cout << "\nIt's a Match!!\n"; }
	else { cout << "\nError! These Strings Don't Match\n"; }

	// ----------- Append(str) ----------- \\
		
	str01 = new String("Hello");
	str02 = new String("World!");

	cout << "\n-- Append()";
	cout << "\nFirst Phrase: " << str01->CStr() << "\nSecond Phrase: " << str02->CStr();
	str01->Append(*str02);
	cout << "\nYour Concatenated String is: " << str01->CStr() << endl;

	// ----------- Prepend(str) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("World!");

	cout << "\n-- Prepend()";
	cout << "\nFirst Phrase: " << str01->CStr() << "\nSecond Phrase: " << str02->CStr();
	str01->Prepend(*str02);
	cout << "\nYour Concatenated String is: " << str01->CStr() << endl;

	// ----------- CStr() ----------- \\
	
	str01 = new String();
	str02 = new String("Hello");

	cout << "\n-- CStr()";
	cout << "\nI am blank: '" << str01->CStr() << "'";
	cout << "\nI am not blank: '" << str02->CStr() << "'\n";

	// ----------- ToLower() ----------- \\

	str01 = new String("I AM LOWERCASE");

	cout << "\n-- ToLower()";
	cout << "\nOriginal: " << str01->CStr() << endl;
	str01->ToLower();

	// ----------- ToUpper() ----------- \\
	
	str01 = new String("i am uppercase");

	cout << "\n-- ToUpper()";
	cout << "\nOriginal: " << str01->CStr() << endl;
	str01->ToUpper();

	// ----------- Find(findString) ----------- \\
	
	str01 = new String("Please Test This String!");
	str02 = new String("T");

	cout << "\n-- Find()";
	cout << "\nIn '" << str01->CStr() << "' we are looking for '" << str02->CStr() << "'";

	size_t location = str01->Find(*str02);
	if (location == -1) { cout << "\nNo Instance of '" << str02->CStr() << "' found!\n"; }
	else { cout << "\n" << "Location - " << location << endl; }

	// ----------- Find(startIndex, findString) ----------- \\
	
	str01 = new String("Please Test This String!");
	str02 = new String("e");
	const int Pos = 6;

	cout << "\n-- Find(w/ Start Index)";
	cout << "\nIn '" << str01->CStr() << "' we are looking for '" << str01->CStr() << "' starting at " << Pos;

	size_t found = str01->Find(Pos, *str02);
	if (Pos < 0 || Pos >= strlen(str01->CStr())) { cout << "\nYou've Exceeded the Range Provided!\n"; }
	else if (found == -1) { cout << "\nNo Instance of '" << str02->CStr() << "' found!\n"; }
	else { cout << "\n" << "Location - " << found << endl; }
	

	// ----------- Replace(findString, replaceString) ----------- \\
	
	str01 = new String("Change Me");
	str02 = new String("e");
	aux = new String("u");

	cout << "\n-- Replace()";
	cout << "\nOriginal: " << str01->CStr();
	cout << "\nReplacing all of '" << str02->CStr() << "' with '" << aux->CStr() << "'";
	str01->Replace(*str02, *aux); 
	cout << "\nReplacement: " << str01->CStr() << endl;

	// ----------- ReadFromConsole() ----------- \\
	
	str01 = new String();

	cout << "\n-- ReadFromConsole()"; cout << "\nInput: ";
	str01->ReadFromConsole();

	// ----------- WriteToConsole() ----------- \\
	
	cout << "\n-- WriteToConsole()";
	cout << "\nYour input was: ";
	str01->WriteToConsole();
	cout << "\n";

	// ----------- Equality Operator(==) ----------- \\
	
	str01 = new String("World");
	str02 = new String("World");

	cout << "\n-- Equality Operator(==)";
	cout << "\nPhrase: " << str01->CStr(); 
	cout << "\nPhrase: " << str02->CStr();
	if (*str01 == *str02) 
	{
		cout << "\nThese Strings are Equal!\n";
	}
	else
	{
		cout << "\nThese String are not Equal!\n";
	}

	// ----------- Equality Operator(!=) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("HelZo");

	cout << "\n-- Equality Operator(!=)";
	cout << "\nPhrase: " << str01->CStr();
	cout << "\nPhrase: " << str02->CStr();
	if (*str01 != *str02) 
	{
		cout << "\nThese String are not Equal!\n";
	}
	else
	{
		cout << "\nThese Strings are Equal!\n";
	}

	// ----------- Assignment Operator(=) ----------- \\
		
	str01 = new String("Right Side");
	str02 = new String("Left Side");
	aux = new String();

	cout << "\n-- Assignment Operator(=)";
	cout << "\nLHS was: "; str01->WriteToConsole();
	cout << "\nRHS was: "; str02->WriteToConsole(); cout << "\n";

	*aux = *str01;
	*str01 = *str02;
	*str02 = *aux;

	cout << "\nLHS is now: "; str01->WriteToConsole();
	cout << "\nRHS is now: "; str02->WriteToConsole();
	cout << "\n";

	// ----------- Subscript Operator([]) ----------- \\

	str01 = new String("Index Me!");
	const size_t SUBINDEX = 2;

	cout << "\n-- Subscript Operator([])";
	cout << "\nBy Looking through '" << str01->CStr() << "' at location '" << SUBINDEX << "'";
	cout << "\nThe Characher is '" << (*str01)[SUBINDEX] << "'.\n";

	// ----------- LessThan Operator(<) ----------- \\
	
	str01 = new String("k");
	str02 = new String("j");

	cout << "\n-- LessThan Operator(<)";
	cout << "\nWe are checking ('" << str01->CStr() << "' < '" << str02->CStr() << "')";

	if (*str01 < *str02)
	{
		cout << "\n'" << str01->CStr() << "' is less than '" << str02->CStr() << "'\n";
	}
	else
	{
		cout << "\n'" << str01->CStr() << "' isn't less than '" << str02->CStr() << "'\n";
	}

	// ----------- Plus Operator(+) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("World!");

	cout << "\n-- Plus Operator(+)\n";
	cout << str01->CStr() << " + " << str02->CStr() << " = ";
	*str01 + *str02;
	cout << str01->CStr() << endl;

	 //----------- Plus Equals Operator (+=) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("World!");
	
	cout << "\n-- Plus Equals Operator (+=)";
	cout << "\nLeft Side = " << str01->CStr() << ", Right Side = " << str02->CStr();
	*str01 += *str02;
	cout << "\nModified Left Side = " << str01->CStr();

	// --- End of Code --- \\	
	cout << "\n\n===========================================";
	cout << "\nEnd of Code!\n";

	// ---- Memory Cleanup ---- \\

	delete str01;
	delete str02;
	delete aux;

	str01 = nullptr;
	str02 = nullptr;
	aux = nullptr;
}
