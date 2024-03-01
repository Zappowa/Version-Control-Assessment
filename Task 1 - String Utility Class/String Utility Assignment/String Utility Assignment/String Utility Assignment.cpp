#include "StringClass.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "\nStart of Code!\n";
	cout << "===========================================\n";


	// ----------- Length() ----------- \\

	/*char str_Input[50];

	cout << "Enter: ";
	cin >> str_Input;

	String* fLength = new String();
	int out = fLength->Length(str_Input);
	cout << "Your word has a length of " << out << endl;*/

	// ----------- CharacterAt(Index) ----------- \\

	/*size_t index = 2;

	cout << "Index: ";
	cin >> index;

	String* fChrt = new String();
	fChrt->CharacterAt(index);*/

	// ----------- EqualTo(str) ----------- \\

	/*String* str01 = new String("Helloo");
	String* str02 = new String("Hello");

	cout << "\nI will compare two strings!!\n\n";
	cout << "1: " << str01->CStr() << "\n2: " << str02->CStr() << endl;

	str01->EqualTo(*str02);*/

	// ----------- Append(str) ----------- \\
	
	/*String* phrase01 = new String("Hello");
	String* phrase02 = new String("World!");

	cout << "\nFirst Phrase: " << phrase01->CStr() << "\nSecond Phrase: " << phrase02->CStr() << endl;
	phrase01->Append(*phrase02);*/

	// ----------- Prepend(str) ----------- \\

	/*String* word01 = new String("Hello");
	String* word02 = new String("World!");

	cout << "\nFirst Phrase: " << word01->CStr() << "\nSecond Phrase: " << word02->CStr() << endl;
	word01->Prepend(*word02);*/

	// ----------- CStr() ----------- \\
	
	/*String* blank = new String();
	String* contain = new String("Hello");

	cout << "\nI am blank: (" << blank->CStr() << ")";
	cout << "\nI am not blank: (" << contain->CStr() << ")\n";*/

	// ----------- ToLower() ----------- \\

	/*String* upper = new String("I AM UPPERCASE!");
	
	cout << "\nOriginal: " << upper->CStr() << endl;
	upper->ToLower();*/
	
	// ----------- ToUpper() ----------- \\
	
	/*String* lower = new String("i am lowercase");

	cout << "\nOriginal: " << lower->CStr() << endl;
	lower->ToUpper();*/

	// ----------- Find(findString) ----------- \\
	
	/*String strTest("Please Test This String!");
	String strFind("T");

	cout << "\n" << "Location - " << strTest.Find(strFind);*/

	// ----------- Find(startIndex, findString) ----------- \\
	
	/*String* test = new String("Please Test This String!");

	const int Pos = 0;
	String findStr("T");

	cout << "\n" << "Location - " << test->Find(Pos, findStr);*/

	// ----------- Replace(findString, replaceString) ----------- \\
	
	/*String* testSubject = new String("Replace stuff inside me!");
	String* find = new String("e");
	String* change = new String("M");

	testSubject->Replace(*find, *change);*/

	// ----------- ReadFromConsole() ----------- \\
	
	/*String* input = new String();

	input->ReadFromConsole();
	cout << input->CStr();*/

	// ----------- WriteToConsole() ----------- \\
	
	/*String* output = new String("Hello World!");

	output->WriteToConsole();*/

	// ----------- Equality Operator(==) ----------- \\
	
	/*String* Eq_lhs = new String("World");
	String* Eq_rhs = new String("World");

	Eq_lhs->operator==(*Eq_rhs);
	if (*Eq_lhs == *Eq_rhs) {}*/
	
	// ----------- Equality Operator(!=) ----------- \\
	
	/*String* Su_lhs = new String("Hello");
	String* Su_rhs = new String("HelZo");

	Su_lhs->operator!=(*Su_rhs);
	if (*Su_lhs != *Su_rhs) {}*/

	// ----------- Assignment Operator(=) ----------- \\
		
	/*String* As_lhs = new String("Right Side");
	String* As_rhs = new String("Left Side");
	String* aux_side = new String();
	
	cout << "\nLHS was: "; As_lhs->WriteToConsole();
	cout << "\nRHS was: "; As_rhs->WriteToConsole(); cout << "\n";

	aux_side->operator=(*As_lhs);
	As_lhs->operator=(*As_rhs);
	As_rhs->operator=(*aux_side);

	//*aux_side = *As_lhs;
	//*As_lhs = *As_rhs;
	//*As_rhs = *aux_side;

	cout << "\n\nLHS is now: "; As_lhs->WriteToConsole();
	cout << "\nRHS is now: "; As_rhs->WriteToConsole();*/

	// ----------- Subscript Operator([]) ----------- \\

	/*String* data = new String("Index Me!");
	//String datas("Index MEE");
	size_t index = 2;

	data->operator[](index);
	//(*data)[index];*/

	// ----------- LessThan Operator(<) ----------- \\
	
	/*String* checkWith = new String("k");
	String* chr = new String("k");

	checkWith->operator<(*chr);*/

	// ----------- Plus Operator(+) ----------- \\
	
	/*String* LHS = new String("Hello");
	String* RHS = new String("World!");

	LHS->operator+(*RHS);*/

	// ----------- Plus Equals operator (+=) ----------- \\
	
	/*String* lhs = new String("Hello");
	String* rhs = new String("World!");

	lhs->operator+=(*rhs);*/

	// --- End of Code --- \\	

	cout << "\n\n===========================================";
	cout << "\nEnd of Code!";
}
