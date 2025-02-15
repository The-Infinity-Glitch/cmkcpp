#include "lexer.h"
#include <ostream>
#include <string>
#include <iostream>
#include "tokens.h"

static bool is_char_delimiter(char character);
static cmkcpp::Token get_token_from_str(std::string input);

namespace cmkcpp {
    Lexer::Lexer(std::string source) {
        input = source;
        current_position = 0;
        current_char = input[current_position];
    }

    void Lexer::lex() {
        TokenPositon current_token_position;

        for ( ; current_position < input.size(); current_position++) {
            current_char = input[current_position];

            current_token_position.column++;

            if (is_char_delimiter(current_char) && (!current_token_string.empty())) {
                std::cout << "Delimiter = \"" << current_char << "\"" << std::endl;
                std::cout << "Current string = \"" << current_token_string << "\"\n";
                // First get the actual token from the current_token_string
                TokenPositon new_token_position = current_token_position;
                new_token_position.column = (current_token_position.column - 1) - current_token_string.size();

                Token new_token = get_token_from_str(current_token_string);
                std::cout << "Generated = \"" << new_token.value << "\"\n";
                new_token.position = new_token_position;

                tokens.push_back(new_token);
                current_token_string.clear();

                // Now we get the actual token from the current_char after inserting it in current_token_string, but only if it isn't a space or new line
                if (current_char != ' ' && current_char != '\n') {
                    current_token_string.push_back(current_char);
                    new_token_position = current_token_position;
                    new_token_position.column--;

                    new_token = get_token_from_str(current_token_string);
                    std::cout << "Generated = \"" << new_token.value << "\"\n";
                    new_token.position = new_token_position;

                    tokens.push_back(new_token);
                    current_token_string.clear();
                }
            } else {
                if (current_char != ' ' && current_char != '\n') {
                    current_token_string.push_back(current_char);
                }
            }

            if (current_char == '\n') {
                current_token_position.line++;
                current_token_position.column = 0;
            }
        }
    }
}

static bool is_char_delimiter(char character) {
    switch (character) {
        case ' ':
            return true;
        case '\n':
            return true;
        case '#':
            return true;
        case '$':
            return true;
        case ',':
            return true;
        case '.':
            return true;
        case '(':
            return true;
        case ')':
            return true;
        case '{':
            return true;
        case '}':
            return true;
        case '[':
            return true;
        case ']':
            return true;
    }

    return false;
}

static cmkcpp::TokenKind get_special_token_kind(char input) {
    switch (input) {
        case ' ':
            return cmkcpp::TokenKind::SPACE;
        case '\n':
            return cmkcpp::TokenKind::NEW_LINE;
        case '#':
            return cmkcpp::TokenKind::HASHTAG;
        case '$':
            return cmkcpp::TokenKind::DOLLAR;
        case ',':
            return cmkcpp::TokenKind::COMMA;
        case '.':
            return cmkcpp::TokenKind::DOT;
        case '(':
            return cmkcpp::TokenKind::LPAREN;
        case ')':
            return cmkcpp::TokenKind::RPAREN;
        case '{':
            return cmkcpp::TokenKind::LBRACKET;
        case '}':
            return cmkcpp::TokenKind::RBRACKET;
        case '[':
            return cmkcpp::TokenKind::LBRACE;
        case ']':
            return cmkcpp::TokenKind::RBRACE;
        default:
            return cmkcpp::TokenKind::UNKNOWN;
    }
}

static cmkcpp::Token get_token_from_str(std::string input) {
    cmkcpp::Token result_token;
    result_token.value = input;

    if (input.size() == 1 and is_char_delimiter(input[0])) {
        result_token.kind = get_special_token_kind(input[0]);
    } else {
        result_token.kind = cmkcpp::TokenKind::Eof;
    }

    return result_token;
}
