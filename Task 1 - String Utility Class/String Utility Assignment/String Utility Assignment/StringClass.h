// Prevents overlaps in calling the header file
#pragma once

// Creating a class called String
class String
{
public:

	// Constructor & Destructor Initialize
	String();
	~String();

	// Overloaded Constructors
	String(const char* _str);
	String(const String& _other);

public: // Public Area for Initialising the Utilities 

	size_t Length(char* _str) const;
	const char& CharacterAt(size_t _index);
	bool EqualTo(const String& _other);


	/*
	String& Append(const String& _str);
	String& Prepend(const String& _str);

	const char* CStr() const;

	String& ToLower();
	String& ToUpper();

	size_t Find(const String& _str);
	size_t Find(size_t _startIndex, const String& _str);

	String& Replace(const String& _find, const String& _replace);

	String& ReadFromConsole();
	String& WriteToConsole();

public:
	bool operator ==(const String& _other);
	bool operator !=(const String& _other);

	String& operator = (const String& _str);

	char& operator [] (size_t _index);
	const char& operator [] (size_t _index) const;*/

public: // Private Variables

	// Poiner to a Dymanic Array 
	char* mStr = new char[0];
};