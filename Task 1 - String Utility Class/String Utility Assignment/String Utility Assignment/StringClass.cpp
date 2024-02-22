// Global Includes
#include <iostream>
#include <string>
#include "StringClass.h"

using namespace std;



// Constructor & Destructor Definitions
String::String() {};
String::~String() {};

String::String(const char* _str) 
{

}

String::String(const String& _other) {}

size_t String::Length(char* _str) const
{
	size_t chtr = strlen(_str);
	cout << "Your word has a length of " << chtr << endl;
	return chtr;
}

const char& String::CharacterAt(size_t _index)
{
	char locate[8] = "Morning";
	cout << "At index " << _index << ", char = " << locate[_index];
	return locate[_index];
}

bool String::EqualTo(const String& _other) const
{
	if (strlen(this->cStr) != strlen(_other.cStr))
	{
		cout << "Error! Different Lengths\n";
		return false;
	}

	for (int i = 0; i < strlen(this->cStr); i++)
	{
		cout << "\n-- " << i << endl;
		cout << "\nThis: " << this->cStr;
		cout << "\nOther: " << _other.cStr;

		if (strcmp(this->cStr, _ot) == 1)
		{
			cout << "Error! These Strings Don't Match\n";
			return false;
		}
	}
	cout << "It's a Match!!\n";
	return true;
}
/*
String& String::Append(const String& _str)
{
	// TODO: insert return statement here
	
}

String& String::Prepend(const String& _str)
{
	// TODO: insert return statement here
}

const char* String::CStr() const
{
	return nullptr;
}

String& String::ToLower()
{
	// TODO: insert return statement here
}

String& String::ToUpper()
{
	// TODO: insert return statement here
}

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

