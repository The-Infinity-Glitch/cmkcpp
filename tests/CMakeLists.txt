cmake_minimum_required(VERSION 3.5)

# For Code::Blocks generator
set(CMAKE_CODEBLOCKS_EXCLUDE_EXTERNAL_FILES ON)

# For other code editors
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Main application name
set(EXE "tests")

# Main application source and hearders
file(GLOB Source CONFIGURE_DEPENDS *.cpp ../*.cpp)
file(GLOB Headers CONFIGURE_DEPENDS *.h ../*.h)

# Main application
project(${EXE})

add_executable(${EXE} ${Source} ${Headers})

target_include_directories(${EXE} PRIVATE ../)
