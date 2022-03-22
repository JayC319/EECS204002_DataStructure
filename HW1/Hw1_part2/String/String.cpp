#include "String.h"


/*FailureFunction()*/
//********************************************
// find failure array for each String object *
//********************************************
void String::FailureFunction() {
    int lengthP = len;

    f[0] = -1;
    for (int j = 1; j < lengthP; j++) {
        int i = f[j-1];
        while (str[j] != str[i+1] && (i >= 0))
            i = f[i];
        if (str[j] == str[i+1])
            f[j] = i + 1;
        else 
            f[j] = -1;
    }
}


//****************************************************
// equality test by overloading operator==           *
//****************************************************
bool String::operator==(String t){
    if(len != t.len)
        return false;
    else if(str != t.str) 
        return false;
    return true;
}


//************************************************************
// empty test, return true or false by overloading operator! *
//************************************************************
bool String::operator!(){
    if(len != 0) 
        return false;
    else if(str != "")
        return false;
    return true;
}


/* Concat*/
//**************************************
// Concatenation with another string t *
//**************************************
String String::Concat(String t) {
    String temp((char*)"", 0);
    temp.str = str + t.str;
    temp.len = len + t.len;
    delete temp.f;
    temp.f = new int[temp.len];
    return temp;
}


/* Substr */
//*****************************************
//   generate substring i ~ j-1           *
// updated :  generate a substring i~i+j-1*
//*****************************************
String String::Substr(int subPos, int subLen) {
    // try {
    //     if(start >= len || end > len ) 
    //         throw "invalid operation";
    // }

    // catch (const char* error) {
    //     cout << error << endl;
    //     String temp((char*)"", 0);
    //     return temp;
    // }

    try {
        if(subPos + subLen > len) 
            throw "invalid operation";
    }

    catch (const char* error) {
        cout << error << endl;
        String temp((char*)"", 0);
        return temp;
    }

    String temp((char*)"", 0);
    
    

    int count = 0;
    while (count < subLen) {
        temp.str += str[count + subPos];
        count++;
    }

    temp.len = len;
    delete temp.f;
    temp.f = new int[temp.len];
    return temp;
}


/* Find */
//*************************************
//     find the pattern in the string *
// if exists return starting position *
//*************************************
int String::Find(String pat) {
    FailureFunction();
    pat.FailureFunction();

    int posP = 0,
        posS = 0;
    
    int lengthP = pat.Length(),
        lengthS = Length();

    while((posP < lengthP) && (posS < lengthS)) {
        if(pat.str[posP] == str[posS]) {
            posP++;
            posS++;
        }

        else {
            if(posP == 0) 
                posS++;
            else
                posP = pat.f[posP - 1] + 1;
        }
    }

    if(posP < lengthP)
        return -1;
    else 
        return posS - lengthP;
}



/* Delete */
//*********************************************************
//    delete String[start] to String[start + length - 1]  *
//    if invalid operation happens, return empty string   *
//*********************************************************
String String::Delete(int start, int length) {
    try {
        if (start+length > len) 
            throw "invalid operation!";
    }

    catch (const char* error) {
        cout << error << endl;
        String temp((char*)"", 0);
        return temp;
    }

    String temp1((char*)"", 0);
    String temp2((char*)"", 0);
    temp2.str = str.substr(0,start);
    temp1.str += temp2.str;
    temp2.str = str.substr(start + length, len - 1);
    temp1.str += temp2.str;
    temp1.len = len - length;
    delete [] temp1.f;
    temp1.f = new int[temp1.len];
    return temp1;
}


/* CharDelete */
//*********************************************
//  delete all given character in the string  *
//*********************************************
String String::CharDelete(char c) {
    int i = 0,
        count = 0;
    String temp((char*)"", 0);

    while(i < len) {
        char character = str[i];
        if(character == c) 
            count++;
        else 
            temp.str += str[i];
        i++;
    }

    temp.len = len - count;
    delete [] temp.f;
    temp.f = new int[temp.len];
    return temp;
}



/* Compare */
//******************************************************************************************************
//    compare 2 string with specific rule:                                                             *
//                                                                                                     *
// If two strings of letter of alphabet, x = (x0,…,xm-1) and y=(y0,…,yn-1) where xi, yj are letters,   *
// then the Compare member function will decide whether x<y, x=y, or x>y,                              *
// where x < y means if xi=yi for 0≤i<j and xj<yj or if xi=yi for 0≤i≤m and m<n.                       *
// x=y means m=n and xi=yi for 0≤i<n.                                                                  *
// x>y means if xi=yi for 0≤i<j and xj>yj or if xi=yi for 0≤i≤n and m>n.                               *
// The Compare function will return either -1, 0, or +1 if x<y, x=y, or x>y, respectively.             *
//******************************************************************************************************
int String::Compare(String y) {
    
    if(Length() > y.Length())
        return 1;
    if(Length() < y.Length())
        return -1;

    bool different = false;
    int smallerSize = min(len, y.len);
    int i = 0;
    while(i < smallerSize) {
        char a = str[i];
        char b = y.str[i];

        if(a != b){
            different = true;
            break;
        }
        i++;
    }

    if(!different) 
        return 0;

    else {
        char a = str[i];
        char b = y.str[i];
        if(a > b)
            return 1;
        else
            return -1;
    }
}