//
// Created by mateuszkubuntu on 10/10/2024.
//

#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

enum TypeOfToken {
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLE_BY,
    DIVID_BY,
    OPEN_BRACKET,
    CLOSE_BRACKET,
};

struct Token {
    string source;
    TypeOfToken type;
};

class Lexer {
    public:
        Lexer(string input) {
            this->_source = input;
            this->_currentPos = 0;
            this->_size = input.length();
            this->_currentCharacter = input.at(_currentPos);

        };
        char advance() {


            while(_currentPos < _size) {

                char temp = _source[_currentPos];
                _currentPos++;
                _currentCharacter = _source[_currentPos];
                return temp;
            };

        };

        void checkAndSkip() {
            while (_currentCharacter == ' ' || _currentCharacter == '\n' || _currentCharacter == '\t' || _currentCharacter == '\r') {
                advance();
            }
        };


        Token* tokenizeINT() {
            stringstream buffer;

            while(isdigit(_currentCharacter)) {
                buffer << advance();
            }

            Token* token = new Token();
            token->source = buffer.str();
            token->type = NUMBER;

            return token;

        }

        Token* tokenizeSPECIAL(enum TypeOfToken type) {
            Token* token = new Token();
            token->source = string(1, advance());
            token->type = type;
            return token;
        };

        vector<Token*> tokenize() {
            std::vector<Token*> tokens;

            while(_currentPos < _size) {
                checkAndSkip();

                if(isdigit(_currentCharacter)) {
                    tokens.push_back(tokenizeINT());
                    continue;
                }

                switch(_currentCharacter) {
                    case '+':
                        tokens.push_back(tokenizeSPECIAL(PLUS));
                        break;
                    case '-':
                        tokens.push_back(tokenizeSPECIAL(MINUS));
                        break;
                    case '*':
                        tokens.push_back(tokenizeSPECIAL(MULTIPLE_BY));
                        break;
                    case '/':
                        tokens.push_back(tokenizeSPECIAL(DIVID_BY));
                        break;
                    case '(':
                        tokens.push_back(tokenizeSPECIAL(OPEN_BRACKET));
                        break;
                    case ')':
                        tokens.push_back(tokenizeSPECIAL(CLOSE_BRACKET));
                        break;
                    default:
                        std::cout << "[1] PARSER ERROR : Unidentified symbol" << std::endl;
                        exit(1);

                }
            };

            return tokens;
        };


    private:
        string _source;
        char _currentCharacter;
        int _currentPos = 0;
        int _size;

};


#endif //LEXER_HPP