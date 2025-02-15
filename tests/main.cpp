#include <fstream>
#include <string>
#include "cmkcpp.h"

int main() {
    std::string cmake_source;
    std::string my_line;
    std::fstream MyReadFile("../CMakeLists.txt");

    while (std::getline(MyReadFile, my_line)) {
        cmake_source.append(my_line+'\n');
    }

    MyReadFile.close();

    cmkcpp::CMakeProject cmake(cmake_source);

    return 0;
}
