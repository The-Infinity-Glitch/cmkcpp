#ifndef CMKCPP_H
#define CMKCPP_H

#include <vector>
#include <string>

namespace cmkcpp {
    enum class CMakeTargetKind {
        EXECUTABLE,
        STATIC_LIBRARY,
        DYNAMIC_LIBRARY
    };

    class CMakeTarget {
        public:
            CMakeTargetKind target_kind;
    };

    enum class CMakeType {
        FILE_PATH,
        PATH,
        STRING,
        BOOL,
        INTERNAL
    };

    class CMakeVariable {
        public:
            std::string name;
        private:
            CMakeType variable_type;
            std::string value;
    };

    class CMakeProject {
        public:
            float cmake_version;
            std::vector<CMakeVariable> variables;
            std::vector<CMakeTarget> targets;

            CMakeProject(std::string cmake_source);
    };
}

#endif // CMKCPP_H
