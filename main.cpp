#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>

using namespace std;

inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

int main() {
    string fileName = "words.txt";
    ifstream file(fileName);
    string row;
    vector<string> words, definitions;

    while (getline(file, row)) {
        size_t equation = row.find('=');
        if (equation != string::npos) {
            string left = row.substr(0, equation);
            rtrim(left);
            words.push_back(left);
            string right = row.substr(equation + 1);
            ltrim(right);
            definitions.push_back(right);
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
            if (words[i] == searchword || definitions[i] == words[i]) {
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
