#pragma once
//do not include any other libraries or use strings
//do not use the double/float types, only ints and c-strings

bool characteristic(const char numString[], int& c);
bool mantissa(const char numString[], int& numerator, int& denominator);


char[] getMantissaString(char numString[]);
int convertCharToInt(char number);
int getNumerator(char mantissaString[]);
int getDenominator(int numerator);