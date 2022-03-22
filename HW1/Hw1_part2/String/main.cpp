#include <iostream>

#include "string.h"
using namespace std;

int main() 
{
    
    String s((char*)"Jordan", 6),
           p((char*)"Lebron", 6),
           t((char*)"Kobe", 4),
           longQuote((char*)"Michael Jordan > Lebron James, it ain't close.", 45),
           empty((char*)"", 0);
        
    

    cout << endl  << endl;
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
    cout << "String s : " << s.showString() << endl;
    cout << "String p : " << p.showString() << endl;
    cout << "performing concatString funciton s.Concat(p)" << endl;
    String concatString = s.Concat(p);
    cout << "String concatString: " << concatString.showString() << endl; 
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

    //test for the Substr() function
    cout << "[Test for the Substr() function]" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "String : "<< s.showString() << endl;
    cout << "we are looking for s.Substr(3, 3) which returns string[3]~string[5]" << endl;
    String newString = s.Substr(3,3);
    cout << "newstring: " << newString.showString() << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

    //test for Find() function
    cout << "[Test for the Find() function]" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "String longQuote : " << longQuote.showString() << endl;
    cout << "String s : " << s.showString() << endl;
    cout << longQuote.Find(s) << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

    //test for the Delete function()
    cout << "[Test for the Delete() function]" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "string s: " << s.showString() << endl;
    cout << "Performing delete(3, 3), delete string[3] to string[5]" << endl;
    String deletedString = s.Delete(3,3);
    cout << "deletedString: " << deletedString.showString() << endl;
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
    cout << "String s : " << s.showString() << endl;
    cout << "String p : " << p.showString() << endl;
    String SS((char*)"Jordon", 6);
    String SSS((char*)"Jordaniel", 9);
    cout << "String SS : " << SS.showString() << endl;
    cout << "String SSS :" << SSS.showString() << endl;
    cout << "compare string s to string p" << endl;
    cout << s.Compare(p) << endl;
    cout << "compare string s to string SS " << endl;
    cout << s.Compare(SS) << endl;
    
    cout << "compare string s to string SSS " << endl;
    cout << s.Compare(SSS) << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

}