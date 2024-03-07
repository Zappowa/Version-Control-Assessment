// Cpp Includes 
#include <iostream>
#include "StringClass.h" // Using our Custom String Class
#include <fstream> // Using and Creating Files
#include <vector>

using namespace std;

void testResults(vector<bool>& vec, /*string& name*/)
{
	ofstream txtIO;
	txtIO.open("Test Results!");
	

	if (txtIO.is_open())
	{
		int run = 0;
		bool success = false;

		while (run < size(vec))
		{
			cout << "Test " << run << ": " << name << " ";
			
			if (vec[run] == true)
				cout << "Successful";
			cout << "Failed";

			run++;
		}
	}
	else
	{
		cout << "Error! File 'txtIO' is not opened.";
	}
}

//Main Function
int main()
{
	cout << "\nStart of Code!\n";
	cout << "===========================================\n";

	//Main String Pointer Variables 
	String* str01 = new String();
	String* str02 = new String();
	String* aux = new String();

	vector<bool> values;
	vector<string> names;

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
	str01->EqualTo(*str02);

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
	cout << "\n" << "Location - " << str01->Find(*str02) << endl;

	// ----------- Find(startIndex, findString) ----------- \\
	
	str01 = new String("Please Test This String!");
	str02 = new String("e");
	const int Pos = 6;

	cout << "\n-- Find(w/ Start Index)";
	cout << "\nIn '" << str01->CStr() << "' we are looking for '" << str01->CStr() << "' starting at " << Pos;
	cout << "\n" << "Location - " << str01->Find(Pos, *str02) << endl;

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

	cout << "\n\nLHS is now: "; str01->WriteToConsole();
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

	// ---- TXT File IO ---- \\

	testResults(values);

	// ---- Memory Cleanup ---- \\

	delete str01;
	delete str02;
	delete aux;

	str01 = nullptr;
	str02 = nullptr;
	aux = nullptr;
}
