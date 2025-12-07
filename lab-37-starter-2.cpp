// COMSC210 | Lab 37 | Majd Bohsali
// IDE Used: Visual Studio Code
#include <iostream>
#include <fstream>
#include <string> 
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string); 

int main() {
    string code; 
    int hashKey = 0;
    ifstream inputFile("lab-37-data-2.txt"); 
    map<int, list<string>> hashTable; 

    if(inputFile.is_open()) { 
        while(getline(inputFile, code)) { 
            hashKey = gen_hash_index(code); 
            hashTable[hashKey].push_back(code); 
        }
        inputFile.close(); 
    } else { 
        cout << "File could not open"; 
    }

    int selection = 0;
    do { 
        cout << "Choose an option: " << endl; 
        cout << "1. Print first 100 entries" << endl; 
        cout << "2. Search for a Key" << endl; 
        cout << "3. Add a Key" << endl; 
        cout << "4. Remove a Key" << endl; 
        cout << "5. Modify a Key" << endl; 
        cout << "6. Exit" << endl; 
        cout << "Selection -> "; 
        cin >> selection; 

        if(selection == 1) { 
            int indexCount = 0; 
            for(auto it = hashTable.begin(); it != hashTable.end() && indexCount < 100 ; it++) { 
                cout << "Key: " << it->first << endl;
                for(string codeV : it->second) { 
                    cout << "    " << codeV << endl;
                }
                indexCount++;
            }
        } else if (selection == 2) { 
            // search for a key
        } else if (selection == 3) { 
            // add a key
        } else if (selection == 4) { 
            // remove a key
        } else if (selection == 5) { 
            // Modify a key
        } else if (selection == 6) { 
            break; 
        }

    } while (selection != 6);



    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

int gen_hash_index(string str) {
    int total = 0;
    for(int i = 0; i < str.length(); i++) { 
        total += (int) str.at(i); 
    }
    return total; 
}