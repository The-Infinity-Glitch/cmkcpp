#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>
#include "tokens.h"

namespace cmkcpp {
    class Lexer {
        public:
            Lexer(std::string source);
            void lex();
        private:
            // The cmake code input
            std::string input;

            // Some lexing variables
            char current_char;                  // Current code character, this generaly will be appended in current_token_string
            int current_position;               // The current character index in input
            std::string current_token_string;   // The current token value, this will be verified when a delimiter character is reached

            // The resultant token vector
            std::vector<Token> tokens;
    };
}

#endif // LEXER_H
