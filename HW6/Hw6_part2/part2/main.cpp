#include <iostream>
#include "Hash.h"
using namespace std;


int main() {
    string message[10] = {"hashing", "encrypt", "turing", "hack", "data", 
    "espionage", "logistic", "capture", "the", "flag"};

    string search_list[6] = {"hashing", "alan", "decrypt", "espioanage", "logistic", "flag"};

    ProbingHash PH1;
    for(int i = 0; i < 10; i++) {
        PH1.insert(message[i]);
    }

    cout << "Probing Hash table:" << endl;
    PH1.display();
    for(int i = 0; i < 6; i++) {
        cout << "Is" << "\"" << search_list[i] << "\"" << "in the table ?";
        if(PH1.search(search_list[i]))
            cout << "Yes --> " << PH1.search(search_list[i]) << "." << endl; 
        else 
            cout << "NO." << endl;
    }

    ChainingHash CH1;
    for(int i = 0; i < 10; i++) {
        CH1.insert(message[i]);
    }
    cout << "\n\nChaining Hash table:" << endl;
    CH1.display();
    for(int i = 0; i < 6; i++) {
        cout << "Is" << "\"" << search_list[i] << "\"" << "in the table ?";
        if(CH1.search(search_list[i]))
            cout << "Yes --> " << CH1.search(search_list[i]) << "." << endl;
        else 
            cout << "NO." << endl;
    }

}