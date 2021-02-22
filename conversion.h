#pragma once
//do not include any other libraries or use strings
//do not use the double/float types, only ints and c-strings

bool characteristic(const char numString[], int& c);
bool mantissa(const char numString[], int& numerator, int& denominator);
bool CheckValidChar(const char numString[]);