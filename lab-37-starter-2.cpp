// COMSC210 | Lab 37 | Majd Bohsali
// IDE Used: Visual Studio Code
#include <iostream>
using namespace std;

int sum_ascii(string); 

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    
    cout << "Total of ab: " << sum_ascii("ab"); // should equal 195

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