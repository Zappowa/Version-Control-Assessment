#include "StringClass.h"
#include <iostream>

using namespace std;

int main()
{
	string next;

	cout << "\nStart of Code!\n";
	cout << "===========================================\n";
	
	// ----------- Length() ----------- \\

	/*char str_input[20] = "What is my length";
	String* fLength = new String();

	size_t out = fLength->Length(str_input);
	cout << "\n-- Length()";
	cout << "\nThe length of (" << str_input << ") is " << out << "\n";*/
		
	// ----------- CharacterAt(Index) ----------- \\

	/*String* fChrt = new String();
	size_t index = 2;

	cout << "\n-- CharacterAt()";
	cout << "\nThe Character at (" << index << ") is '";
	cout << fChrt->CharacterAt(index) << "'\n";*/

		// ----------- EqualTo(str) ----------- \\

	/*String* str01 = new String("Hello");
	String* str02 = new String("Hello");

	cout << "\n-- EqualTo()";
	cout << "\nString 1: " << str01->CStr() << ", String 2: " << str02->CStr();
	str01->EqualTo(*str02);*/

	// ----------- Append(str) ----------- \\
		
	/*String* aWord01 = new String("Hello");
	String* aWord02 = new String("World!");

	cout << "\n-- Append()";
	cout << "\nFirst Phrase: " << aWord01->CStr() << "\nSecond Phrase: " << aWord02->CStr();
	aWord01->Append(*aWord02);
	cout << "\nYour Concatenated String is: " << aWord01->CStr() << endl;*/

	// ----------- Prepend(str) ----------- \\

	/*String* pWord01 = new String("Hello");
	String* pWord02 = new String("World!");

	cout << "\n-- Prepend()";
	cout << "\nFirst Phrase: " << pWord01->CStr() << "\nSecond Phrase: " << pWord02->CStr();
	pWord01->Prepend(*pWord02);
	cout << "\nYour Concatenated String is: " << pWord01->CStr() << endl;*/

	// ----------- CStr() ----------- \\
	
	/*String* blank = new String();
	String* contain = new String("Hello");

	cout << "\n-- CStr()";
	cout << "\nI am blank: '" << blank->CStr() << "'";
	cout << "\nI am not blank: '" << contain->CStr() << "'\n";*/

	// ----------- ToLower() ----------- \\

	/*String* upper = new String("I AM LOWERCASE");

	cout << "\n-- ToLower()";
	cout << "\nOriginal: " << upper->CStr() << endl;
	upper->ToLower();*/

	// ----------- ToUpper() ----------- \\
	
	/*String* lower = new String("i am uppercase");

	cout << "\n-- ToUpper()";
	cout << "\nOriginal: " << lower->CStr() << endl;
	lower->ToUpper();*/

	// ----------- Find(findString) ----------- \\
	
	String* strTest = new String("Please Test This String!");
	String* strFind = new String("T");

	cout << "\n-- Find()";
	cout << "\nIn '" << strTest->CStr() << "' we are looking for '" << strFind->CStr() << "'";
	cout << "\n" << "Location - " << strTest->Find(*strFind) << endl;

	//// ----------- Find(startIndex, findString) ----------- \\
	
	String* testStr = new String("Please Test This String!");
	String* findStr = new String("T");
	const int Pos = 0;
	
	cout << "\n-- Find(w/ Start Index)";
	cout << "\nIn '" << testStr->CStr() << "' we are looking for '" << findStr->CStr() << "' starting at " << Pos;
	cout << "\n" << "Location - " << testStr->Find(Pos, *findStr) << endl;

	// ----------- Replace(findString, replaceString) ----------- \\
	
	//String* testSubject = new String("Change Me");
	//String* find = new String("e");
	//String* change = new String("u");

	//cout << "\nReplacing all of '" << find->CStr() << "' with '" << change->CStr() << "'";
	//cout << "\nOriginal: " << testSubject->CStr();
	//testSubject->Replace(*find, *change); 
	//cout << "\nReplacement: " << testSubject->CStr();
	////goNext(next);

	// ----------- ReadFromConsole() ----------- \\
	
	/*String* input = new String();

	cout << "\n-- ReadFromConsole()"; cout << "\nInput: ";
	input->ReadFromConsole();*/

	// ----------- WriteToConsole() ----------- \\
	
	/*cout << "\n-- WriteToConsole()";
	cout << "\nYour input was: ";
	input->WriteToConsole();
	cout << "\n";*/

	// ----------- Equality Operator(==) ----------- \\
	
	/*String* Eq_lhs = new String("World");
	String* Eq_rhs = new String("World");

	cout << "\n-- Equality Operator(==)";
	cout << "\nPhrase: " << Eq_lhs->CStr(); 
	cout << "\nPhrase: " << Eq_rhs->CStr();
	if (*Eq_lhs == *Eq_rhs) 
	{
		cout << "\nThese Strings are Equal!\n";
	}
	else
	{
		cout << "\nThese String are not Equal!\n";
	}*/

	// ----------- Equality Operator(!=) ----------- \\
	
	/*String* NEq_lhs = new String("Hello");
	String* NEq_rhs = new String("HelZo");

	cout << "\n-- Equality Operator(!=)";
	cout << "\nPhrase: " << NEq_lhs->CStr();
	cout << "\nPhrase: " << NEq_rhs->CStr();
	if (*NEq_lhs != *NEq_rhs) 
	{
		cout << "\nThese String are not Equal!\n";
	}
	else
	{
		cout << "\nThese Strings are Equal!\n";
	}*/

	// ----------- Assignment Operator(=) ----------- \\
		
	/*String* As_lhs = new String("Right Side");
	String* As_rhs = new String("Left Side");
	String* aux_side = new String();

	cout << "\n-- Assignment Operator(=)";
	cout << "\nLHS was: "; As_lhs->WriteToConsole();
	cout << "\nRHS was: "; As_rhs->WriteToConsole(); cout << "\n";

	*aux_side = *As_lhs;
	*As_lhs = *As_rhs;
	*As_rhs = *aux_side;

	cout << "\n\nLHS is now: "; As_lhs->WriteToConsole();
	cout << "\nRHS is now: "; As_rhs->WriteToConsole();
	cout << "\n";*/

	// ----------- Subscript Operator([]) ----------- \\

	/*String* data = new String("Index Me!");
	const size_t SUBINDEX = 2;

	cout << "\n-- Subscript Operator([])";
	cout << "\nBy Looking through '" << data->CStr() << "' at location '" << SUBINDEX << "'";
	cout << "\nThe Characher is '" << (*data)[index] << "'.\n";*/

	// ----------- LessThan Operator(<) ----------- \\
	
	/*String* checkWith = new String("k");
	String* chr = new String("l");

	cout << "\n-- LessThan Operator(<)";
	cout << "\nWe are checking ('" << checkWith->CStr() << "' < '" << chr->CStr() << "')";

	if (*checkWith < *chr)
	{
		cout << "\n'" << checkWith->CStr() << "' is less than '" << chr->CStr() << "'\n";
	}
	else
	{
		cout << "\n'" << checkWith->CStr() << "' isn't less than '" << chr->CStr() << "'\n";
	}*/

	// ----------- Plus Operator(+) ----------- \\
	
	/*String* LHS = new String("Hello");
	String* RHS = new String("World!");

	LHS->operator+(*RHS);*/

	 //----------- Plus Equals operator (+=) ----------- \\
	
	/*String* lhs = new String("Hello");
	String* rhs = new String("World!");

	lhs->operator+=(*rhs);*/
	

	// --- End of Code --- \\	

	cout << "\n\n===========================================";
	cout << "\nEnd of Code!\n\n";
}
