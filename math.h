#pragma once
//do not include any other libraries or use strings
//do not use the double/float types, only ints and c-strings

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool multiply(int characteristic1, int numerator1, int denominator1, int characteristic2, int numerator2, int denominator2, char result[], int len);
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
int lengthSoFar(char array[], int len);
int greatestCommonDivisor(int numerator, int denominator);
bool isOverflow(int value1, int value2);
