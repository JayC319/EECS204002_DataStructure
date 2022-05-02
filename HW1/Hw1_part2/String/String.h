#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;

class String{
private:
    string str;
    int len;
    int *f;
public:
    String(char* init, int m) {
        str = init;
        len = m;
        f = new int[m];
        FailureFunction();
    }

    virtual ~String(){}

    //1
    bool operator==(String t);
    //2
    bool operator!();
    //3
    int Length() {return len;}
    //4
    String Concat(String t);
    //5
    String Substr(int, int );
    //6 
    int Find(String pat);
    //7
    String Delete(int start, int length);
    //8
    String CharDelete(char c);
    //9 
    int Compare(String y);
    //10
    void FailureFunction();
    //11
    string showString() { return str; }

    void showFailureFunction();
    


};




#endif