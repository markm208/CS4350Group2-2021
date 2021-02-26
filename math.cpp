#include "math.h"

//HELPER FUNCTIONS
//Counts the number of digits in a given int
//Zero is counted as 1 digit


int count_Digits(int numberToCount)
{
  int totalCount = 1;

  if(numberToCount < 0)
  {
    numberToCount *= -1; // checking if number to count is negative or not. we need the positive in our calculation. 
  }

  while(numberToCount > 9)
  {
    numberToCount /= 10;  // for calculation of the number of the digits, each time we divide our number by 10 and each time, we count one of the digits.
    totalCount++;             // for example, if our number is 150, first the 'totalCount' is equal to 1 then when we divide our number we get 15, and the 'totalCount" will be 
                          // 2 and then our number is 1.5 and the totalCount will be 3. so the number of digits will be equal to 3.
  }

  return totalCount;
}


//Converts a mantissa (given as a fraction) into a int array with
//only one digit per index
bool mantissaToArray(int numerator, int denominator, int maxLength, int mantissaArray[])
{
  int index = 0;

  if(numerator >= denominator) // we check if we define mantissa correctly. because mantissa should between 0 to 1.
  {
    return false;
  }

  while((numerator % denominator) > 0 && index < maxLength - 2) //we calculate our index of our array one by one in this loop and we will put '\0' at the end of our array
  {

    numerator *= 10;
    mantissaArray[index] = numerator / denominator;
    numerator %= denominator;
    index++;

  }

    mantissaArray[index] = numerator / denominator;
    mantissaArray[index + 1] = (int) '\0';

  return true;

}


//Converts a given int to a array with each index containing only one digit


void intToDigitArray(int number, int digitArray[])   
{
  int totalCountOfDigits = count_Digits(number);
  int place = 1;
  int power = 0;
  int index = 0;

  while(power < totalCountOfDigits - 1)
  {
    place *= 10;
    power++;
  }

  while(index < totalCountOfDigits)
  {
    digitArray[index] = number / place;
    place /= 10;
    index++;
  }

}

//takes in two sets of mantissa and characteristic, a char array to store
//result in and the length of the array.

//c = characteristic
//n & d = numerator and denominator of characteristic
//Ex: 0.352 -> c = 0, n = 351 & d = 1000

//Note: result data will be lost if array is passed in anonymously
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{

  int index = 0;
  bool Verbose = false;
  int charResult = c1 + c2;
  int charLen = count_Digits(charResult);
  int characteristic[charLen];
  intToDigitArray(charResult, characteristic);
  int mantissaResult;
  int mantissaSpace = len - count_Digits(charResult) + 1;
  int mantissa1[mantissaSpace];
  int mantissa2[mantissaSpace];
  mantissaResult = mantissaToArray(n1, d1, mantissaSpace, mantissa1) ||
                   mantissaToArray(n2, d2, mantissaSpace, mantissa2);


  //base case, not enough to store characteristic
  if(len <= charLen || !mantissaResult)  
  {
    return false;
  }

  while(index < charLen)
  {
    result[index] = (char) characteristic[index];
    index++;
  }

  if(index < mantissaSpace) // we add "." between the characteristic and the mantissa in our array.
  {
    result[index] = '.';
    index++;

    while(index < mantissaSpace)
    {
      mantissaResult = 0;

      if(mantissa1[index] != (int) '\0') // we check if we reach to last digit of the first number
      {
        mantissaResult += mantissa1[index];
      }

      if(mantissa2[index] != (int) '\0') // we check if we reach to last digit of the second number
      {
        mantissaResult += mantissa2[index];
      }

      if(Verbose)
      {
        mantissaResult++;
        Verbose = false;
      }

      if(mantissaResult > 9)
      {
        mantissaResult %= 10;
        Verbose = true;
      }

      result[index] = (char) mantissaResult;

      index++;
    }

  }

  result[index] = '\0';

  return true;

}
//--
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	return true;
}
//--
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	return true;
}
//--
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	return true;
}
