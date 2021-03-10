#pragma once
//do not include any other libraries or use strings
//do not use the double/float types, only ints and c-strings

bool characteristic(const char numString[], int& c);
bool mantissa(const char numString[], int& numerator, int& denominator);


bool validNumber(char place);
char[] getNumeratorString(char numString[]);
int getNumerator(char mantissaString[]);
int convertCharToInt(char number);
int getDenominator(int numerator);
int charArraySize(char number[]);
int intArraySize(int arr[]);
int[] reverse(int number[]);

bool checkValidChar(const char numString[]);
bool checkDecimalPoint(const char numString[]);
bool checkSigns(const char numString[]);
int convertToInt(char currentCharacter);

