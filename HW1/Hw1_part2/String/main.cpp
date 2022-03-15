#include <iostream>

#include "string.h"
using namespace std;

int main() 
{
    
    String s((char*)"Fakeraka", 8),
           p((char*)"Fakez", 5),
           t((char*)"Fakeraka", 8),
           empty((char*)"", 0);
        
    
    // testbench
    //////////////////////////////////////////////////
    // test for operator ==
    cout << "[Test for the operator==]" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "String s: "  << s.showString() << endl;
    cout << "String p: " << p.showString() << endl;
    cout << "String t: " << t.showString() << endl;
    cout << "s == p :" << (s == p) << endl;
    cout << "s == t: " << (s == t) << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

    //test for operator!
    cout << "[Test for the operator!]" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "string s: " << s.showString() << endl;
    cout << "string empty: " << empty.showString() << endl;
    cout << "Is string S empty ? : " << !s << endl;
    cout << "Is string empty empty ? : " << !empty << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

    //test for Length()
    cout << "[Test for the Length() function]" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "String s: " << s.showString() << endl;
    cout << "Length of String s is " << s.Length() << endl; 
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

    //test for Concat() function
    cout << "[Test for the Concat() function]" << endl;
    cout << "-----------------------------------------------------" << endl;

    cout << "-----------------------------------------------------" << endl;
    cout << endl;

    //test for the Substr() function
    cout << "[Test for the Substr() function]" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "String : "<< s.showString() << endl;
    cout << "we are looking for s.Substr(3, 7) which returns string[3]~string[6]" << endl;
    String newString = s.Substr(3,7);
    cout << "newstring: " << newString.showString() << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

    //test for Find() function
    cout << "[Test for the Find() function]" << endl;
    cout << "-----------------------------------------------------" << endl;
    
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

    //test for the Delete function()
    cout << "[Test for the Delete() function]" << endl;
    cout << "-----------------------------------------------------" << endl;
    
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

    //test for the CharDelete() function
    cout << "[Test for the CharDelete() function]" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "String s: " <<  s.showString() << endl;
    String newName = s.CharDelete('a');
    cout << "String after deleting character 'a'\n:" << newName.showString() << endl;
    cout << newName.Length() << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;
    
    
    //test for the Compare() function
    cout << "[Test for the Compare() function]" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << s.Compare(p) << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

}