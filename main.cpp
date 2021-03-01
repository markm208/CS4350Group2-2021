//do not include any other libraries or use strings
//do not use the double/float types, only ints and c-strings
#include <iostream>
#include "conversion.h"
#include "math.h"

using namespace std;

int main()
{
    //the parts of a fractional number
    int characteristicValue;
    int numerator;
    int denominator;

    //create a c-string, an array of 100 characters (99 plus a null terminating character '\0')
    const int lengthOfResult = 100;
    char result[lengthOfResult];

    //test the two conversion functions
    if(characteristic("123.456", characteristicValue))
    {
        //123
        cout<<"The characteristic is "<<characteristicValue<<endl;
    }
    if(mantissa("123.456", numerator, denominator))
    {
        //456/1000
        cout<<"The mantissa is numerator: "<<numerator<<", denominator: "<<denominator<<endl;
    }

    //test the math functions
    if(add(characteristicValue, numerator, denominator, characteristicValue, numerator, denominator, result, lengthOfResult))
    {
        //"246.912"
        cout<<"Result: "<<result<<endl;
    }
    if(subtract(characteristicValue, numerator, denominator, characteristicValue, numerator, denominator, result, lengthOfResult))
    {
        //"0"
        cout<<"Result: "<<result<<endl;
    }
    if(multiply(characteristicValue, numerator, denominator, characteristicValue, numerator, denominator, result, lengthOfResult))
    {
        //"15241.383936"
        cout<<"Result: "<<result<<endl;
    }
   /* if(divide(characteristicValue, numerator, denominator, characteristicValue, numerator, denominator, result, lengthOfResult))
    {
        //"1"
        cout<<"Result: "<<result<<endl;
    }
    */

    divide(-500,5,10,7,3,10,result,10);
    
    cout << "Result: " << result << endl;

    cout << "test: " << result[5] << endl;
    
    int i =0;
    while(i < 11){
        cout << result[i];
        i++;
    }
    cout << endl;
    cout << result << endl;
    
   

    return 0;
}
