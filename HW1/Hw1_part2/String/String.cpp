#include "String.h"

//*********************************
//
//*********************************
void String::FailureFunction() {
    int lengthP = len;

    f[0] = -1;
    for (int j = 1; j < lengthP; j++) {
        int i = f[i-1];
        while (str[j] != str[i+1] && (i >= 0))
            i = f[i];
        if (str[j] == str[i+1])
            f[j] = i + 1;
        else 
            f[j] = -1;
    }
}

//**************************
// equality test           *
//**************************
bool String::operator==(String t){
    if(len != t.len)
        return false;
    else if(str != t.str) 
        return false;
    return true;
}

//***********************************
// empty test, return true or false *
//***********************************
bool String::operator!(){
    if(len != 0) 
        return false;
    else if(str != "")
        return false;
    return true;
}

//**************************************
// Concatenation with another string t *
//**************************************
String String::Concat(String t) {
    String temp("", 0);
    temp.str = str + t.str;
    temp.len = len + t.len;
    delete temp.f;
    temp.f = new int[temp.len];
    return temp;
}

//*********************************
//   generate substring i ~ j-1   *
//*********************************
String String::Substr(int start, int end) {
    try {
        if(start >= len || end >= len ) 
            throw "invalid operation";
    }

    catch (const char* error) {
        cout << error << endl;
    }

    String temp("", 0);
    
    int count = start;
    while (count < end) {
        temp.str += str[count];
        count++;
    }

    temp.len = (end - start);
    delete temp.f;
    temp.f = new int[temp.len];
    return temp;
}


//6
//*********************************
//
//*********************************
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


//7
//*********************************
//
//*********************************
String String::Delete(int start, int length) {
    try {
        if (start+length >= len) 
            throw "invalid operation!";
    }

    catch (const char* error) {
        cout << error << endl;
    }

    String temp1("", 0);
    String temp2("", 0);
    temp2.str = str.substr(0,start);
    temp1.str += temp2.str;
    temp2.str = str.substr(start + length, len - 1);
    temp1.str += temp2.str;
    temp1.len = len - length;
    delete [] temp1.f;
    temp1.f = new int[temp1.len];
    return temp1;
}


//8
//*********************************
//
//*********************************
String String::CharDelete(char c) {
    int i = 0,
        count = 0;
    String temp("", 0);

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


//9
//*********************************
//
//*********************************
int String::Compare(String y) {
    
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