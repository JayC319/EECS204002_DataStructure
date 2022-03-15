#include <iostream>

#include "string.h"
using namespace std;

int main() 
{
    
    String s("Fakeraka", 8),
           p("Fakez", 5),
           result("", 0);
           

    cout << s.showString() << endl;
    cout << s.Compare(p) << endl;
    
    // testbench
    //////////////////////////////////////////////////
    // test for operator ==
    cout << "Test for the operator== " << endl;
    cout << (s == p) << endl;
    cout << endl;

    //test for operator!
    cout << "Test for the operator! " << endl;
    cout << !result << endl;
    cout << endl;

    //test for Length()
    cout << "Test for the Length() function " << endl;
    cout << result.Length() << endl;
    cout << endl;

    //test for Concat() function
    cout << "Test for the Concat() function" << endl;
    
    cout << endl;

    //test for the Substr() function
    cout << "Test for the Substr() function" << endl;
    String newString = s.Substr(3,6);
    cout << newString.showString() << endl;
    cout << endl;

    //test for Find() function
    cout << "Test for the Find() function " << endl;

    cout << endl;

    //test for the Delete function()
    cout << "Test for the Delete() function" << endl;

    cout << endl;

    //test for the CharDelete() function
    cout << "Test for the CharDelete() function" << endl;
    cout << s.showString() << endl;
    cout << s.Length() << endl;
    String newName = s.CharDelete('a');
    cout << newName.showString() << endl;
    cout << newName.Length() << endl;
    //test for the Compare() function
    cout << "Test for the Compare() function" << endl;
    cout << s.Compare(p) << endl;
    cout << endl;

}