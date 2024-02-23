// Global Includes
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "StringClass.h"

using namespace std;



// Constructor & Destructor Definitions
String::String() 
{ 
	cout << "-- Constructor Active --\n\n";
	mStr = new char[1];
	mStr[0] = '\0';
}

String::~String() { cout << "-- Destructor Active --\n\n"; }

// Overloaded Constructor Definitions 
String::String(const char* _str) 
{
	cout << "-- Overloaded Constructor --";
	size_t size = strlen(_str);
	mStr = new char[size + 1];
	strcpy(mStr, _str);
}

String::String(const String& _other)
{
	cout << "-- Overloaded Constructor --"; 
	mStr = new char[Length(_other.mStr) + 1];
	strcpy(mStr, _other.mStr);
}

// String Utility Class //


// ---- Length() ---- \\

size_t String::Length(char* _str) const
{
	size_t chtr = strlen(_str);
	//cout << "Your word has a length of " << chtr << endl;
	return chtr;
}

// ---- CharacterAt() ---- \\

const char& String::CharacterAt(size_t _index)
{
	char locate[8] = "Morning";
	cout << "At index " << _index << ", char = " << locate[_index];
	return locate[_index];
}

// ---- EqualTo() ---- \\

bool String::EqualTo(const String& _other)
{ 
	if (Length(mStr) != Length(_other.mStr))
	{
		cout << "Error! Different Lengths\n";
		return false;
	}

	for (int i = 0; i < Length(mStr); i++)
	{
		if (mStr[i] != _other.mStr[i])
		{
			cout << "\nError! These Strings Don't Match\n";
			return false;
		}
	}
	cout << "\nIt's a Match!!\n";
	return true;
}

String& String::Append(const String& _str)
{
	strcat(mStr, " ");
	strcat(mStr, _str.mStr);

	cout << "\nYou're Concatenated Word is: " << mStr << endl;
	return *this;
}

String& String::Prepend(const String& _str)
{
	strcat(_str.mStr, " ");
	strcat(_str.mStr, mStr);

	cout << "\nYour Chosen Phrase is: " << _str.mStr << endl;
	return *this;
}

const char* String::CStr() const
{
	return mStr;
}

String& String::ToLower()
{
	cout << "\nInput: " << mStr;
	for (int i = 0; i < strlen(mStr); i++)
	{
		mStr[i] = tolower(mStr[i]);
	}
	cout << "\nLowered: " << mStr;
	return *this;
}

String& String::ToUpper()
{
	return *this;
}

/*


size_t String::Find(const String& _str)
{
	return size_t();
}

size_t String::Find(size_t _startIndex, const String& _str)
{
	return size_t();
}

String& String::Replace(const String& _find, const String& _replace)
{
	// TODO: insert return statement here
}

String& String::ReadFromConsole()
{
	// TODO: insert return statement here
}

String& String::WriteToConsole()
{
	// TODO: insert return statement here
}

bool String::operator==(const String& _other)
{
	return false;
}

bool String::operator!=(const String& _other)
{
	return false;
}

String& String::operator=(const String& _str)
{
	// TODO: insert return statement here
}

char& String::operator[](size_t _index)
{
	// TODO: insert return statement here
}

const char& String::operator[](size_t _index) const
{
	// TODO: insert return statement here
}
*/

