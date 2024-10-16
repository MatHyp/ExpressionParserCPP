#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "src/lexer.hpp"

using namespace std;

int main() {
    string myText;

    ifstream file("example.txt");

    if (!file.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    while (getline(file, myText)) {
        cout << myText << endl;
    }

    file.close();

    Lexer lexer(myText);

    vector<Token*> tokens = lexer.tokenize();

    for (int i = 0; i < tokens.size(); i++) {
        cout << tokens[i]->type << "(" << tokens[i]->source << ")" << endl;
    }
    return 0;
}
