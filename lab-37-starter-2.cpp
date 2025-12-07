// COMSC210 | Lab 37 | Majd Bohsali
// IDE Used: Visual Studio Code
#include <iostream>
#include <fstream>
#include <string> 
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string); 
void searchKey(map<int, list<string>>, string); 
void addKey(map<int, list<string>>&, string); 
void removeKey(map<int, list<string>>&, string);
void modifyKey(map<int, list<string>>&, string, string);

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
            string searchCode; 
            cout << "Enter a code to search for: "; 
            cin >> searchCode; 
            searchKey(hashTable, searchCode);
        } else if (selection == 3) { 
            string newCode; 
            cout << "Enter a new code to add: "; 
            cin >> newCode; 
            addKey(hashTable, newCode);
        } else if (selection == 4) { 
            string delCode; 
            cout << "Enter a code to remove: "; 
            cin >> delCode; 
            removeKey(hashTable, delCode); 
        } else if (selection == 5) { 
            string originalCode, newCode; 
            cout << "Enter the original code: "; 
            cin >> originalCode; 
            cout << "Enter the new code: "; 
            cin >> newCode; 
            modifyKey(hashTable, originalCode, newCode); 
        } else if (selection == 6) { 
            break; 
        }

        cout << endl;
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

void searchKey(map<int, list<string>> hashTable, string searchCode) { 
    int searchKey = gen_hash_index(searchCode);
    auto it = hashTable.find(searchKey); 
    if(it == hashTable.end()) { 
        cout << "Search Code not in hash table" << endl;
    } else {
        for(string code : it->second) { 
            if(code == searchCode) { 
                cout << "Search Code Found" << endl; 
                return; 
            }
        }
        cout << "Search Code not in hash table" << endl;
    }
}

void addKey(map<int, list<string>>& hashTable, string newCode) { 
    int newKey = gen_hash_index(newCode);
    hashTable[newKey].push_back(newCode); 
    cout << "New Code Added to HashTable" << endl;
}

void removeKey(map<int, list<string>>& hashTable, string delCode) { 
    int delKey = gen_hash_index(delCode);
    auto it = hashTable.find(delKey); 
    if(it == hashTable.end()) { 
        cout << "Search Code not in hash table" << endl;
    } else {
        for(auto l = it->second.begin(); l != it->second.end(); l++) { 
            if(*l == delCode) { 
                it->second.erase(l); 
                cout << "Code Removed" << endl; 
                return; 
            }
        }
        cout << "Search Code not in hash table" << endl;
    }
}

void modifyKey(map<int, list<string>>& hashTable, string originalCode, string newCode) { 
    int originalKey = gen_hash_index(originalCode); 
    int newKey =  gen_hash_index(newCode); 

    auto it = hashTable.find(originalKey); 
    if(it == hashTable.end()) { 
        cout << "Original Key not in hash table" << endl;
    } else {
        for(auto l = it->second.begin(); l != it->second.end(); l++) { 
            if(*l == originalCode) { 
                it->second.erase(l); 
                cout << "Original Code Removed" << endl; 
                hashTable[newKey].push_back(newCode);
                cout << "New Code Added" << endl; 
                return; 
            }
        }
        cout << "Original Code not in hash table" << endl;
    }
}