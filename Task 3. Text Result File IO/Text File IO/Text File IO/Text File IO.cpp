// Cpp Includes 
#include <iostream>
#include "StringClass.h" // Using our Custom String Class
#include <fstream> // Using and Creating Files
#include <vector>

using namespace std;

void testResults(vector<bool>& vec, vector<string>& name)
{
	ofstream txtIO;
	txtIO.open("Test Results!");

	if (txtIO.is_open())
	{
		int run = 0;
		bool success = false;

		while (run < size(vec) && run < size(name))
		{
			cout << "\n";
			cout << "Test " << run << ": " << name[run] << " ";
			
			if (vec[run] == true)
				cout << "Successful";
			if (vec[run] == false)
				cout << "Failed";

			run++;
		}
		txtIO.close();
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
	String* baux = new String();

	vector<bool> values;
	vector<string> names;

	// ----------- Length() ----------- \\

	str01 = new String("What is my length?");
	size_t out = str01->Length();
	
	names.push_back("Length()");
	if (out == strlen(str01->CStr())) { values.push_back(true); }
	else { values.push_back(false); }
		

	// ----------- CharacterAt(Index) ----------- \\

	str01 = new String("Hello");
	size_t index = 2;

	names.push_back("CharacterAt()");
	if (str01->CharacterAt(index) == str01->CStr()[index]) { values.push_back(true); }
	else { values.push_back(false); }


	// ----------- EqualTo(str) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("Hello");

	names.push_back("EqualTo()");
	if (str01->EqualTo(*str02) == true) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- Append(str) ----------- \\
		
	str01 = new String("Hello");
	str02 = new String("World!");

	names.push_back("Append()");
	if (str01->Append(*str02) == "Hello World!") { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- Prepend(str) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("World!");

	names.push_back("Prepend()");
	if (str01->Prepend(*str02) == "World! Hello") { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- CStr() ----------- \\
	
	str01 = new String();
	str02 = new String("Hello");

	names.push_back("CStr()");
	if (str02->CStr()) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- ToLower() ----------- \\

	str01 = new String("I AM LOWERCASE");

	names.push_back("ToLower()");
	if (str01->ToLower() == "i am lowercase") { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- ToUpper() ----------- \\
	
	str01 = new String("i am uppercase");

	names.push_back("ToUpper()");
	if (str01->ToUpper() == "I AM UPPERCASE") { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- Find(findString) ----------- \\
	
	str01 = new String("Please Test This String!");
	str02 = new String("T");

	names.push_back("Find()");
	if (str01->Find(*str02) == 7) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- Find(startIndex, findString) ----------- \\
	
	str01 = new String("Please Test This String!");
	str02 = new String("e");
	const int Pos = 6;

	names.push_back("Find(w/ index)");
	if (str01->Find(Pos, *str02) == 8) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- Replace(findString, replaceString) ----------- \\
	
	str01 = new String("Change Me");
	str02 = new String("e");
	aux = new String("u");

	names.push_back("Replace()");
	if (str01->Replace(*str02, *aux) == "Changu Mu") { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- ReadFromConsole() ----------- \\
	
	str01 = new String();

	cout << "\nInput: ";
	str01->ReadFromConsole();
	names.push_back("ReadFromConsole()");
	if (str01->CStr()) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- WriteToConsole() ----------- \\
	
	names.push_back("WriteToConsole()");
	if (str01->CStr()) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- Equality Operator(==) ----------- \\
	
	str01 = new String("World");
	str02 = new String("World");

	if (*str01 == *str02) { values.push_back(true); }
	else { values.push_back(false); }
	
	// ----------- Equality Operator(!=) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("HelZo");

	if (*str01 != *str02) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- Assignment Operator(=) ----------- \\
		
	str01 = new String("Right Side");
	str02 = new String("Left Side");
	aux = new String();

	*aux = *str01;
	*str01 = *str02;
	*str02 = *aux;

	/*names.push_back("Assignment Operator(=)");
	if (str01->CStr() == "Left Side" && str02->CStr() == "Right Side") { values.push_back(true); }
	else { values.push_back(false); }*/

	// ----------- Subscript Operator([]) ----------- \\

	str01 = new String("Index Me!");
	const size_t SUBINDEX = 2;

	if ((*str01)[SUBINDEX] == str01->CStr()[2]) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- LessThan Operator(<) ----------- \\
	
	str01 = new String("k");
	str02 = new String("j");

	names.push_back("LessThan Operator(<)");
	if (*str01 < *str02 && str01->CStr() < str02->CStr()) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- Plus Operator(+) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("World!");

	*str01 + *str02;

	if (str01->CStr() == "Hello World!") { values.push_back(true); }
	else { values.push_back(false); }

	//----------- Plus Equals Operator (+=) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("World!");

	*str01 += *str02;

	names.push_back("Plus Equals Operator(+=)");
	if (str01->CStr() == "Hello World!") { values.push_back(true); }
	else { values.push_back(false); }

	// ---- TXT File IO ---- \\

	testResults(values, names);



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
