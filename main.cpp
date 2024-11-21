#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string fileName = "words.txt";
    ifstream file(fileName);
    string row;
    vector<string> words, definitions;

    while (getline(file, row)) {
        size_t equation = row.find('=');
        if (equation != string::npos) {
            words.push_back(row.substr(0, equation));
            definitions.push_back(row.substr(equation + 1));
        }
    }
    file.close();

    string searchword;
    while (true) {
        cout << "Give a word or a definiton (finish by typing 'end'): ";
        getline(cin, searchword);
        if (searchword == "end") {
            break;
        }

        bool found = false;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == searchword || definitions[i] == words) {
                cout << "Answer: " << (words[i] == searchword ? definitions[i] : words[i]) << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Word or definition is wrong." << endl;
        }
    }

    return 0;
}