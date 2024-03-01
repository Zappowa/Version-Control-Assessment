// Global Includes
#include <iostream>
#include <string>
#include "StringClass.h"

using namespace std; // Remove need for std::

// Constructor & Destructor Definitions

String::String() // Constructor
{ 
	// << "\n-- Constructor Active --\n"; // Prints when Active

	mStr = new char[1]; // Initialising a new array 
	mStr[0] = '\0'; // Confirms an Empty Array with Null Terminator
}

String::~String() // Destructor
{ 
	cout << "\n\n-- Destructor Active --"; // Prints when Active
	delete[] mStr; // Deleting the Array (Prevents Memory Leak)
}

// Overloaded/Copy Constructor Definitions 

String::String(const char* _str)
{
	//cout << "\n-- Overloaded Constructor --\n";
	size_t size = strlen(_str);
	// Creating an Array of Length(What was passed through)
	mStr = new char[size + 1];
	// Copying the Passthrough onto the Char Array
	strcpy_s(mStr, Length(mStr), _str); // strcpy_s() Makes the function safe (Has defined storage)
	
}

String::String(const String& _other)
{
	//cout << "\n-- Overloaded Constructor --\n";
	size_t size = strlen(_other.mStr);
	// Creating an Array of Length(What was passed through)
	mStr = new char[size + 1];
	// Copying the Passthrough onto the Char Array
	strcpy_s(mStr, Length(mStr), _other.mStr); // strcpy_s() Makes the function safe (Has defined storage)
}


// ---------- String Utility Class ---------- //


// ---- Length() ---- \\

size_t String::Length(char* _str) const
{
	// Strlen() to find the length, then returning it
	size_t chtr = strlen(_str);
	return chtr;
}

// ---- Const CharacterAt() ---- \\

const char& String::CharacterAt(size_t _index) const
{
	// Creating text to locate an index from
	char locate[8] = "Morning";
	// Finding the Char by the using the given index in []
	return locate[_index]; // Sending the value back
}

// ---- CharacterAt() ---- \\

char& String::CharacterAt(size_t _index)
{
	// Creating text to locate an index from
	char locate[8] = "Morning";
	// Finding the Char by the using the given index in []
	return locate[_index]; // Sending the value back
}

// ---- EqualTo() ---- \\

bool String::EqualTo(const String& _other) const
{ 
	// Strcmp() will take both inputs and determine if they are equal or not
	if (strcmp(mStr, _other.mStr) == 0) // If '0' then return true, Else '1' and return false
	{
		cout << "\nIt's a Match!!\n";
		return true;
	}
	cout << "\nError! These Strings Don't Match\n";
	return false;
}

// ---- Append() ---- \\

String& String::Append(const String& _str)
{
	size_t safeSize = Length(mStr) + Length(_str.mStr) + 2;

	// Strcat() Concatenates a space ontop of the first word, then the second word on top of the space.
	strcat_s(mStr, safeSize, " ");
	strcat_s(mStr, safeSize + 1, _str.mStr);

	cout << "\nYou're Concatenated Word is: " << mStr << endl; // Printing newly Appended Word
	return *this;
}

// ---- Prepend() ---- \\

String& String::Prepend(const String& _str)
{
	// Creating a length to ensure a null terminator in the array
	size_t safeSize = Length(mStr) + Length(_str.mStr);

	// Strcat() adds a space on the second word, then the first one on top of it
	strcat_s(_str.mStr, safeSize,  " ");
	strcat_s(_str.mStr, safeSize, mStr);

	cout << "\nYou're Concatenated Word is: " << _str.mStr << endl; // Printing the newly prepended word
	return *this;
}

// ---- CStr() ---- \\

const char* String::CStr() const
{
	// Sending back the private pointer to the char array
	return mStr;
}

// ---- ToLower() ---- \\

String& String::ToLower()
{
	// Iterates for the length of the Array
	for (int i = 0; i < strlen(mStr); i++)
	{
		// For each letter in the Array, it'll set them to a lowered version 
		mStr[i] = tolower(mStr[i]);
	}
	cout << "Lowered: " << mStr << endl; // Print out the lowered Array
	return *this;
}

// ---- ToUpper() ---- \\

String& String::ToUpper()
{
	// Iterates for the length of the array
	for (int i = 0; i < strlen(mStr); i++)
	{
		// For each letter in the array, it'll set them to a uppered version 
		mStr[i] = toupper(mStr[i]);
	}
	cout << "Uppered: " << mStr << endl; // Print out the lowered array
	return *this;
}

// ---- Find() ---- \\

size_t String::Find(const String& _str)
{
	// strstrr() Finds the first occurance of what we pass through in the Array
	char* founds = strstr(mStr, _str.mStr); // Assigns the first occurance to "founds"

	// Checks no occurances were found
	if (founds == nullptr)
	{
		cout << "\nNo Instance of '" << _str.mStr << "' found!";
		return -1;
	}
	// If there is an occurance, print it minus the rest of the Array (Only the char)
	return founds - mStr;
}

// ---- Find(w/ Start Index) ---- \\

size_t String::Find(size_t _startIndex, const String& _str)
{
	// Checks if the start index isn't in range of what we are looking through
	if (_startIndex < 0 || _startIndex >= Length(mStr))
	{
		cout << "You've Exceeded the Range Provided! ";
		return -1;
	}

	// strstr() Will start at the given index and skip anything before
	char* found = strstr(mStr + _startIndex, _str.mStr);

	if (found == nullptr)
	{
		//cout << "\nNo Instance of '" << _str.mStr << "' found!";
		return -1;
	}
	// If there is an occurance, print it minus the rest of the array (Only the char)
	return found - mStr;
}

// ---- Replace() ---- \\

String& String::Replace(const String& _find, const String& _replace)
{
	size_t sPos = 0;
	while (sPos != -1)
	{
		sPos = Find(sPos, _find.mStr);
		mStr[sPos] = *_replace.mStr;
	}
	cout << "\n\n" << mStr;
	return *this;
}

// ---- ReadFromConsole() ---- \\

String& String::ReadFromConsole()
{
	// Take an input straight into the Array
	cin >> mStr;
	return *this;
}

// ---- WriteToConsole() ---- \\

String& String::WriteToConsole()
{
	// Send the Array straight to the console
	cout << mStr;
	return *this;
}


// ---------- Operator Utility Class ---------- //


// ---- Operator =() ---- \\

String& String::operator=(const String& _str)
{
	cout << "\nLHS: '" << mStr << "' is now equal to RHS: '" << _str.mStr << "'";
	memcpy(mStr, _str.mStr, Length(_str.mStr));
	return *this;
}

// ---- Operator ==() ---- \\

bool String::operator==(const String& _other)
{
	if (strcmp(mStr, _other.mStr) == 0)
	{
		cout << "\nTrue";
		return true;
	}
	cout << "\nFalse";
	return false;
}

// ---- Operator !=() ---- \\

bool String::operator!=(const String& _other)
{
	if (strcmp(mStr, _other.mStr) == 1)
	{
		cout << "\nTrue";
		return true;
	}
	cout << "\nFalse";
	return false;
}

// ---- Operator <() ---- \\

bool String::operator<(const String& _other)
{
	if (strcmp(mStr, _other.mStr) < 0)
	{
		cout << "\n'" << mStr << "' is less than '" << _other.mStr << "'\n";
		return true;
	}
	cout << "\n'" << mStr << "' isn't less than '" << _other.mStr << "'\n";
	return false;
}

// ---- Operator []() ---- \\

char& String::operator[](size_t _index)
{
	cout << "\nAt Location '" << _index << "' the char is '" << mStr[_index] << "'\n";
	return mStr[_index];
}

const char& String::operator[](size_t _index) const
{
	cout << "At Location '" << _index << "' the char is '" << mStr[_index] << "'\n";
	return mStr[_index];
}

// ------ Optional Functionality ------ \\


// ---- Operator +() ---- \\

String& String::operator+(const String& _str)
{
	size_t safeSize = Length(mStr) + Length(_str.mStr);
	cout << mStr;

	strcat_s(mStr, safeSize, " ");
	strcat_s(mStr, safeSize, _str.mStr);

	cout << " + " << _str.mStr << " = " << mStr;
	return *this;
}

// ---- Operator +=() ---- \\

String& String::operator+=(const String& _str)
{
	cout << mStr << " += " << _str.mStr;

	size_t mSize = Length(mStr) + Length(_str.mStr);
	char* new_mStr = new char[mSize + 1];
	
	memcpy(new_mStr, mStr, mSize);
	delete[] mStr;

	strcat_s(new_mStr, mSize, " ");
	strcat_s(new_mStr, mSize, _str.mStr);
	
	mStr = new_mStr;
	cout << " becomes: " << mStr;
	return *this;
}