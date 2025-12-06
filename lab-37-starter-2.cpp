// COMSC210 | Lab 37 | Majd Bohsali
// IDE Used: Visual Studio Code
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

int sum_ascii(string); 

int main() {
    string code; 
    int total = 0;
    ifstream inputFile("lab-37-data-2.txt"); 
    cout << "Total of ab: " << sum_ascii("ab") << endl; // should equal 195

    if(inputFile.is_open()) { 
        while(getline(inputFile, code)) { 
            total += sum_ascii(code); 
        }
        inputFile.close(); 
    } else { 
        cout << "File could not open"; 
    }

    cout << "Grand total ASCII sum from file: " << total << endl; 
    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

int sum_ascii(string str) {
    int asciiTotal = 0;
    for(int i = 0; i < str.length(); i++) { 
        asciiTotal += (int) str.at(i); 
    }
    return asciiTotal; 
}