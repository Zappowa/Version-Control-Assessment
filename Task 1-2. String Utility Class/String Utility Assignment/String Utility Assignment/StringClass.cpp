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
	//cout << "\n-- Destructor Active --"; // Prints when Active
	delete[] mStr; // Deleting the Array (Prevents Memory Leak)
	mStr = nullptr;
}

// Overloaded/Copy Constructor Definitions 

String::String(const char* _str)
{
	//cout << "\n-- Overloaded Constructor --\n";
	size_t safeSize = strlen(_str);
	// Creating an Array of Length(What was passed through)
	mStr = new char[safeSize+1];
	// For Loop to Add Passthrough onto array
	for (int ii = 0; ii < safeSize; ii++)
		mStr[ii] = _str[ii];
	mStr[safeSize] = '\0'; // Set last value to Null Terminator
}

String::String(const String& _other)
{
	//cout << "\n-- Overloaded Constructor --\n";
	size_t safeSize = strlen(_other.mStr);
	// Creating an Array of Length(What was passed through)
	mStr = new char[safeSize];
	// For Loop to Add Passthrough onto array
	for (int ii = 0; ii < safeSize; ii++)
		mStr[ii] = _other[ii];
	mStr[safeSize] = '\0'; // Set last value to Null Terminator
}


// ---------- String Utility Class ---------- //


// ---- Length() ---- \\

size_t String::Length() const
{
	// Strlen() to find the length, then returning it
	return strlen(mStr);
}

// ---- Const CharacterAt() ---- \\

const char& String::CharacterAt(size_t _index) const
{
	// Finding the Char by the using the given index in []
	return mStr[_index];
}

// ---- CharacterAt() ---- \\

char& String::CharacterAt(size_t _index)
{
	// Finding the Char by the using the given index in []
	return mStr[_index];
}

// ---- EqualTo() ---- \\

bool String::EqualTo(const String& _other) const
{ 
	// Strcmp() will take both inputs and determine if they are equal or not
	if (strcmp(mStr, _other.mStr) == 0) // If '0' then return true, Else '1' and return false
	{
		return true;
	}
	return false;
}

// ---- Append() ---- \\

String& String::Append(const String& _str)
{
	// Setting a Safe Size for the Array with +1 to provide a space for the " "
	size_t safeSize = (strlen(mStr) + 1) + (strlen(_str.mStr)) + 1; // Outside + 1 for the Null Terminator '0\'
	// Temporary Storage with Length of Both Strings
	char* new_mStr = new char[safeSize];

	// Copying old data into a new variable with a safe length
	strcpy_s(new_mStr, safeSize, mStr);

	// Appending the space and string onto the Array
	strcat_s(new_mStr, safeSize, " ");
	strcat_s(new_mStr, safeSize, _str.mStr);

	// Returning local variable is a risk so we give the data back
	mStr = new_mStr;
	return *this;
}

// ---- Prepend() ---- \\

String& String::Prepend(const String& _str)
{
	// Setting a Safe Size for the Array with +1 to provide a space for the " "
	size_t safeSize = (strlen(mStr) + 1) + (strlen(_str.mStr)) + 1; // Outside + 1 for the Null Terminator '0\'
	// Temporary Storage with Length of Both Strings
	char* new_mStr = new char[safeSize];

	// Copying old data into a new variable with a safe length
	strcpy_s(new_mStr, safeSize, _str.mStr);

	// Appending the space and string onto the Array
	strcat_s(new_mStr, safeSize, " ");
	strcat_s(new_mStr, safeSize, mStr);

	// Returning local variable is a risk so we give the data back
	mStr = new_mStr;

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
	return *this;
}

// ---- Find() ---- \\

size_t String::Find(const String& _str)
{
	// strstrr() Finds the first occurance of what we pass through in the Array
	char* founds = strstr(mStr, _str.mStr); // Assigns the first occurance to "founds"

	// Checks no occurances were found
	if (founds == nullptr) { return -1; }

	// If there is an occurance, print it minus the rest of the Array (Only the char)
	return founds - mStr;
}

// ---- Find(w/ Start Index) ---- \\

size_t String::Find(size_t _startIndex, const String& _str)
{
	// Checks if the start index isn't in range of what we are looking through
	if (_startIndex < 0 || _startIndex >= strlen(mStr)) { return -1; }

	// strstr() Will start at the given index and skip anything before
	char* found = strstr(mStr + _startIndex, _str.mStr);

	if (found == nullptr) { return -1; }
	// If there is an occurance, print it minus the rest of the array (Only the char)
	return found - mStr;
}

// ---- Replace() ---- \\

String& String::Replace(const String& _find, const String& _replace)
{
	// Variable to update
	size_t cPos = 0;

	while (cPos != -1)
	{
		// Sets cPos to the location of the first occurance
		cPos = Find(cPos, _find.mStr);
		// Replaces at that location in the array then loops with new location as a starting index
		mStr[cPos] = *_replace.mStr;
	}
	return *this;
}

// ---- ReadFromConsole() ---- \\

String& String::ReadFromConsole()
{
	// Initialising a size for the array
	const size_t SIZE = 144;
	char new_mStr[SIZE];

	// Take an input straight into the Array
	cin.getline(new_mStr, SIZE);

	// Free the existing memory to avoid memory leaks
	delete[] mStr;

	// Allocate new memory for the updated string
	mStr = new char[strlen(new_mStr) + 1];

	// Copy the content
	strcpy_s(mStr, strlen(new_mStr) + 1, new_mStr);

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
	// Initialising a safe copy size + the Null Terminator
	const size_t SAFESIZE = strlen(_str.mStr) + 1;

	// Making sure the array is empty before using it
	if (strlen(mStr) > 0)
	{
		delete[] mStr;
		mStr = nullptr;
	}

	// Recreate the array with proper size
	mStr = new char[SAFESIZE];

	// Copying the Second string to the First string
	memcpy(mStr, _str.mStr, SAFESIZE);
	
	return *this;
}

// ---- Operator ==() ---- \\

bool String::operator==(const String& _other)
{
	//strcmp() will output 0 if they are equal strings
	if (strcmp(mStr, _other.mStr) == 0)
	{
		return true;
	}
	// If not 0 then they aren't equal
	return false;
}

// ---- Operator !=() ---- \\

bool String::operator!=(const String& _other)
{
	//strcmp() will output 1 if they aren't equal strings
	if (strcmp(mStr, _other.mStr) == 1)
	{
		return true;
	}
	// If not 1 then they are equal
	return false;
}

// ---- Operator <() ---- \\

bool String::operator<(const String& _other)
{
	// strcmp() will return less than 0 if str1 is less than str 2
	return (strcmp(mStr, _other.mStr) < 0);
}

// ---- Operator []() ---- \\

char& String::operator[](size_t _index)
{
	// Returns the character at _index in the mStr array
	// The Array is already constructed in the constructors
	return mStr[_index];
}

const char& String::operator[](size_t _index) const
{
	// Returns the character at _index in the mStr array
	// The Array is already constructed in the constructors
	return mStr[_index];
}


// ------ Optional Functionality ------ \\


// ---- Operator +() ---- \\

String& String::operator+(const String& _str)
{
	// Creating a safe length to strcat() + 1 for Space, + 1 for Null Terminator
	size_t safeSize = (strlen(mStr)+ 1) + (strlen(_str.mStr)) + 1;

	// Appending the space and string onto the Array
	strcat_s(mStr, safeSize, " ");
	strcat_s(mStr, safeSize, _str.mStr);

	return *this;
} 

// ---- Operator +=() ---- \\

String& String::operator+=(const String& _str)
{
	cout << "\n" << mStr << " += " << _str.mStr;

	// Creating a safe size for a new array 
	size_t safeSize = (strlen(mStr) + 1) + (strlen(_str.mStr)) + 1;
	char* new_mStr = new char[safeSize];
	
	// Copying old data to new array
	memcpy(new_mStr, mStr, safeSize);
	
	// Appending the space and string onto that array
	strcat_s(new_mStr, safeSize, " ");
	strcat_s(new_mStr, safeSize, _str.mStr);

	// Deleteing Old Data
	delete[] mStr;

	// Assgining it back to the normal variable
	mStr = new_mStr;
	return *this;
}