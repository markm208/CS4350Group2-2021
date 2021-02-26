#pragma once
//do not include any other libraries or use strings
//do not use the double/float types, only ints and c-strings

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);

int count_digits(int numberToCount);
bool mantissaToArray(int numerator, int denominator, int maxLength, int mantissaArray[]);
void intToDigitArray(int number, int digitArray[]);