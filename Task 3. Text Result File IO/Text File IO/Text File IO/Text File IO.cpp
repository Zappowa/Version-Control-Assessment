// Cpp Includes 
#include <iostream>
#include "StringClass.h" // Using our Custom String Class
#include <fstream> // Using and Creating Files
#include <vector> // Allows usage of vectors
#include <chrono> // Allows us to access time and date
using namespace std;

// Function we can call and print to the text file
void testResults(vector<bool>& vec, vector<string>& name)
{
	int run = 0;
	int Success = 0;
	int Failure = 0;

	// Open a file (txtIO) for writing test results
	ofstream txtIO;
	txtIO.open("String Utility Results");

	if (txtIO.is_open())
	{
		// Find the Local Date and Time
		auto now = chrono::system_clock::now();
		auto now_c = chrono::system_clock::to_time_t(now); // Converting to time_t
		
		// Organised Output of the Date/Time
		struct tm timeInfo; // 
		localtime_s(&timeInfo, &now_c); // Conversion to Local Time

		char Date[15]; // Buffer
		strftime(Date, sizeof(Date), "%m/%d/%Y", &timeInfo);

		char Time[15]; // Buffer
		strftime(Time, sizeof(Time), "%H:%M:%S", &timeInfo);

		// Calculating Success Percentage
		for (int i = 0; i < size(vec); i++)
		{
			if (vec[i] == true) { Success += 1; }
			else { Failure += 1; }
		}

		int successRate = (Success * 100) / size(vec);


		// Printing out the Date and Time
		txtIO << "Date: " << Date << ", Time: " << Time << ", Success Rate: " << successRate << "%";

		while (run < size(vec) && run < size(name))
		{
			txtIO << "\nTest " << run << ": " << name[run] << " ";

			if (vec[run] == true) { txtIO << "Successful"; }
			else { txtIO << "Failed"; }

			run++;
		}
		txtIO.close();
	}
	else { cout << "Error! Text File Broken"; }
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
	str02 = new String("Hellz");

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
	if (strcmp(str02->CStr(), "") != 0 && strcmp(str01->CStr(), "") == 0) { values.push_back(true); }
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
	if (strcmp(str01->CStr(), "") != 0) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- Equality Operator(==) ----------- \\
	
	str01 = new String("World");
	str02 = new String("World");

	names.push_back("Equality Operator(==)");
	if (*str01 == *str02) { values.push_back(true); }
	else { values.push_back(false); }
	
	// ----------- Equality Operator(!=) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("HelZo");

	names.push_back("Equality Operator(!=)");
	if (*str01 != *str02) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- Assignment Operator(=) ----------- \\
		
	str01 = new String("Right Side");
	str02 = new String("Left Side");
	
	
	String temp = *str01;
	*str01 = *str02;
	*str02 = temp;

	names.push_back("Assignment Operator(=)");
	if (strcmp(str01->CStr(), "Left Side") == 0 
		&& strcmp(str02->CStr(), "Right Side") == 0) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- Subscript Operator([]) ----------- \\

	str01 = new String("Index Me!");
	const size_t SUBINDEX = 2;

	names.push_back("Subscript([])");
	if ((*str01)[SUBINDEX] == str01->CStr()[2]) { values.push_back(true); }
	else { values.push_back(false); }

	// ----------- LessThan Operator(<) ----------- \\
	
	str01 = new String("k");
	str02 = new String("l");

	names.push_back("LessThan Operator(<)");
	if (*str01 < *str02 && strcmp(str01->CStr(), str02->CStr()) < 0) { values.push_back(true); }
	else { values.push_back(false); }


	// ----------- Plus Operator(+) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("World!");

	String result = *str01 + *str02;

	names.push_back("Plus Operator(+)");
	if (result == "Hello World!") { values.push_back(true); }
	else { values.push_back(false); }

	//----------- Plus Equals Operator (+=) ----------- \\
	
	str01 = new String("Hello");
	str02 = new String("World!");

	String assign = *str01;
	assign += *str02;

	names.push_back("Plus Equals Operator(+=)");
	if (strcmp(assign.CStr(), "Hello World!") == 0) { values.push_back(true); }
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