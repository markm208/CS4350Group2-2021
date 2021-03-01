#include "math.h"
#include <iostream>

using namespace std;


bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
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
//1,5,10,2,2,10
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    
    if((c1 == 0) & (n1 == 0)){
        char achar = '0' + c1;
        result[0] = achar;
        return true;
    }
    
    
    int divisor = d1 * d2; 
    bool neg = false; //checks if we are using negative values.

    
    

    if(c1 < 0){
        neg = true;
        c1= -c1;
    }
    if(c2 < 0){
        neg = true;
        c2 = -c2;
    }

    if((c2 & n2) == 0){
        cerr << "Cannot Divide by 0" << endl;
    }

    int decimal1 = (c1 * divisor) + (n1 * (divisor/d1));
    
    int decimal2 = (c2 * divisor) + (n2 * (divisor/d2));

    int frontint = decimal1 / decimal2; 
    
    int checker = 0; //current position at our integer

    result[len] = '\0';

   
    
    
   
    if((frontint > 9) & (neg == false)){
        int copy = frontint;
        int lengthofint = 0;
        while(copy > 0){
            copy = copy/10;
            lengthofint++;
        }
        
        
        int divisor = 10;
        for (int i = 0; i < lengthofint - 2; i++){
            divisor = divisor * 10;
        }

        //cout << "first div: " << divisor << endl;
        for (checker = 0; checker < lengthofint; checker++){
            /*if (result[checker] == '\0'){
                return true;
            */
            int toadd = frontint/divisor;
            //if 351, toadd is equal to 3
            char achar = '0' + toadd;
            result[checker] = achar;
            //need to now do 351 % 300
            //left with 51, now do 51 / 10 to get 5
            //51 mod 10 now to get 1
            frontint = frontint % (toadd * divisor);
            divisor = divisor/10;
        }
        //cout << "checker: " << checker << endl;
    }
    else if ((frontint > 9) & (neg == true)){
        result[0] = '-';
        int copy = frontint;
        int lengthofint = 0;
        while(copy > 0){
            copy = copy/10;
            lengthofint++;
        }
        int divisor = 10;
        for (int i = 0; i < lengthofint - 2; i++){
            divisor = divisor * 10;
        }
        for (checker=1; checker < lengthofint+1; checker++){
            /*if (result[checker] == '\0'){
                return true;
            */
            int toadd = frontint/divisor;
            //if 351, toadd is equal to 3
            char achar = '0' + toadd;
            result[checker] = achar;
            //need to now do 351 % 300
            //left with 51, now do 51 / 10 to get 5
            //51 mod 10 now to get 1
            frontint = frontint % (toadd * divisor);
            divisor = divisor/10;
        }


    }
    else if (neg == true){
        result[0] = '-';
        char bchar = '0' + frontint;
        result[1] = bchar;
        checker = 1;
    }
    else{
        char bchar = '0' + frontint;
        result[0] = bchar;
        checker = 0;
    }
    
    result[checker+1] = '.';


    cout << "checker: " << checker << endl;
    checker += 2 ;
    
    
    //decimal1 = decimal1 * 10;

    //cout << "dec: " << decimal1 << endl;

    int newadd = 0;
    
    
    
    
    
    if(decimal1 < 0){
        decimal1 = -decimal1;
    }


    int divmod = decimal1 / decimal2;

    while(divmod == 0){ //Function for if our first dividing number starts with a 0
        decimal1 = decimal1 * 10;
        divmod = decimal1 / decimal2;
        char cchar = '0' + divmod;
        result[checker] = cchar;
        checker++;
    }


    long long newdec = decimal1;

    
    while(checker < len){
        
        newdec = newdec * 10;
        //cout << "decimal1: " << newdec << endl;
        //cout << "decimal2: " << decimal2 << endl;
        newadd = newdec / decimal2;

        divmod = divmod * 10;

        //cout << "newadd: " << newadd << endl;
        //cout << "divmod: " << divmod << endl;
        
        int toadd = newadd % divmod;

        divmod = divmod + toadd;
        cout << "toadd: " << toadd << endl;
        //cout << "toadd: " << toadd << endl;
        char bchar = '0' + toadd;
        result[checker] = bchar;
        checker++;
    }
        
    
    
    
    
    
    
    
    //cout << (achar) << endl;
    

    //cout << "decy: " << result[0] << endl;
    //result[checker] = '\0';
    return true;
}


//5.5/2.3 = 2.3913
//multiply 5 and 5/10 by 10 to get 50 + 5
//5/2 = 2
//5/10 and 3/10
//
//55/23

//5.5/2.09 = 2.63157895
//550/209 = 
//209 * 2 = 418
//550 - 418 = 132


//25 and (5/7)/2 and (8/9)
//25.7143 + 2.88888 = 8.9011

//550 % 209 = 132
//550 / 209 = 2.132 
//front int = 2
//5500 = dec1copy
//dec1copy / dec2copy = 26
//decresult = 26
//26 % 20 gets next decimal. 

//2.351 / .0125 = 188.08
//2 and (351/1000) / 0 and (125/10000)
//2(1000) + (351) / 125

//23,510,000 / 0 + (125,000)

//2.351 / 1.5 = 1.567333
//2 and (351/1000) / 1 and (5/10)
//23,351 / 15,000

