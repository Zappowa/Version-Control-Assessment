// Global Includes
#include <iostream>
#include <string>
#include "StringClass.h"

using namespace std; // Remove need for std::

// Constructor & Destructor Definitions

String::String() // Constructor
{ 
	cout << "\n-- Constructor Active --\n"; // Prints when Active
	mStr = new char[1]; // Initialising a new array 
	mStr[0] = '\0'; // Confirms an Empty Array with Null Terminator
}

String::~String() // Destructor
{ 
	cout << "\n\n-- Destructor Active --"; // Prints when Active
	delete[] mStr; // Deleting the Array (Prevents Memory Leak)
}

// Overloaded Constructor Definitions 
String::String(const char* _str) 
{
	cout << "\n-- Overloaded Constructor --\n";
	size_t size = strlen(_str);
	mStr = new char[size + 1];
	strcpy(mStr, _str);
}

String::String(const String& _other)
{
	cout << "\n-- Overloaded Constructor --\n"; 
	mStr = new char[Length(_other.mStr) + 1];
	strcpy(mStr, _other.mStr);
}


// ---------- String Utility Class ---------- //


// ---- Length() ---- \\

size_t String::Length(char* _str) const
{
	size_t chtr = strlen(_str);
	return chtr;
}

// ---- Const CharacterAt() ---- \\

const char& String::CharacterAt(size_t _index) const
{
	char locate[8] = "Morning";
	cout << "At index " << _index << ", char = " << locate[_index];
	return locate[_index];
}

// ---- CharacterAt() ---- \\

char& String::CharacterAt(size_t _index)
{
	char locate[8] = "Morning";
	cout << "At indexs " << _index << ", char = " << locate[_index];
	return locate[_index];
}

// ---- EqualTo() ---- \\

bool String::EqualTo(const String& _other)
{ 
	if (strcmp(mStr, _other.mStr) == 0)
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
	strcat(mStr, " ");
	strcat(mStr, _str.mStr);

	cout << "\nYou're Concatenated Word is: " << mStr << endl;
	return *this;
}

// ---- Prepend() ---- \\

String& String::Prepend(const String& _str)
{
	strcat(_str.mStr, " ");
	strcat(_str.mStr, mStr);

	cout << "\nYou're Concatenated Word is: " << _str.mStr << endl;
	return *this;
}

// ---- CStr() ---- \\

const char* String::CStr() const
{
	return mStr;
}

// ---- ToLower() ---- \\

String& String::ToLower()
{
	for (int i = 0; i < strlen(mStr); i++)
	{
		mStr[i] = tolower(mStr[i]);
	}
	cout << "Lowered: " << mStr << endl;
	return *this;
}

// ---- ToUpper() ---- \\

String& String::ToUpper()
{
	for (int i = 0; i < strlen(mStr); i++)
	{
		mStr[i] = toupper(mStr[i]);
	}
	cout << "Uppered: " << mStr << endl;
	return *this;
}

// ---- Find() ---- \\

size_t String::Find(const String& _str)
{
	char* founds = strstr(mStr, _str.mStr);

	if (founds == nullptr)
	{
		cout << "\nNo Instance of '" << _str.mStr << "' found!";
		return -1;
	}
	return founds - mStr;
}

// ---- Find(w/ Start Index) ---- \\

size_t String::Find(size_t _startIndex, const String& _str)
{
	if (_startIndex < 0 || _startIndex >= Length(mStr))
	{
		cout << "You've Exceeded the Range Provided! ";
		return -1;
	}

	char* found = strstr(mStr + _startIndex, _str.mStr);
	if (found == nullptr)
	{
		//cout << "\nNo Instance of '" << _str.mStr << "' found!";
		return -1;
	}
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
	cin >> mStr;
	return *this;
}

// ---- WriteToConsole() ---- \\

String& String::WriteToConsole()
{
	cout << mStr;
	return *this;
}

// ---- Operator =() ---- \\

String& String::operator=(const String& _str)
{
	cout << "\nLHS: '" << mStr << "' is now equal to RHS: '" << _str.mStr << "'";
	strcpy(mStr, _str.mStr);
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
	cout << mStr;

	strcat(mStr, " ");
	string cat = strcat(mStr, _str.mStr);

	cout << " + " << _str.mStr << " = " << cat;
	return *this;
}

// ---- Operator +=() ---- \\

String& String::operator+=(const String& _str)
{
	cout << mStr << " += " << _str.mStr;

	size_t mSize = Length(mStr) + Length(_str.mStr);
	char* new_mStr = new char[mSize + 1];
	
	strcpy(new_mStr, mStr);
	delete[] mStr;

	strcat(new_mStr, " ");
	strcat(new_mStr, _str.mStr);
	
	mStr = new_mStr;
	cout << " becomes: " << mStr;
	return *this;
}