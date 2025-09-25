cmake_minimum_required(VERSION 3.20)
project(cpp_chat_server VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PostgreSQL REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

include_directories(include)
include_directories(${PostgreSQL_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp")

# Exclude CMake generated files
list(FILTER SOURCES EXCLUDE REGEX "CMakeFiles.*\\.cpp$")

add_executable(cpp_chat_server ${SOURCES})

target_link_libraries(cpp_chat_server
    ${PostgreSQL_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    Threads::Threads
)
