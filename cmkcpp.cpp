#include "cmkcpp.h"
#include <string>
#include "lexer.h"

namespace cmkcpp {
    CMakeProject::CMakeProject(std::string cmake_source) {
        Lexer lexer(cmake_source);
        lexer.lex();
    }
}
