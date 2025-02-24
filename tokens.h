#pragma once
#include <string>

namespace cmkcpp {
    enum class TokenKind {
        // Special symbols
        SPACE,
        NEW_LINE,
        Eof,
        HASHTAG,
        DOLLAR,

        // Punctuation
        DOT,
        COMMA,
        COLON,

        // Delimiters
        SINGLE_QUOTE,
        DOUBLE_QUOTES,
        LPAREN,
        RPAREN,
        LBRACE,
        RBRACE,
        LBRACKET,
        RBRACKET,

        // Literals
        BOOLEAN,
        PATH,
        STRING,
        NUMBER,
        IDENTIFIER,
        COMMENT,

        // If something goes wrong
        UNKNOWN
    };

    struct TokenPositon {
        int line = 0;
        int column = 0;
    };

    struct Token {
        std::string value;
        TokenKind kind;
        TokenPositon position;
    };
}
