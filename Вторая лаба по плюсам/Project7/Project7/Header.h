#pragma once
#include<iostream>
#include<cstring>



#pragma warning(disable : 4996)

using namespace std;

class String
{

protected:
	char* arr;
	int bitsize;

public:
	int a;
	String();
	String(char sim);
	String(char* str);
	String(const String& str);

	char* clear(char* str);
	int dlina(char* str);
	int operator == (String& str);
	char* Getarr();

};


class Bit_String : public String {


public:
	Bit_String();
	Bit_String(char* str);
	Bit_String(const Bit_String& str);
	const Bit_String& operator = (const Bit_String& str);
	friend Bit_String& operator+(Bit_String& str1, Bit_String& str2);
	void proverka();

};
