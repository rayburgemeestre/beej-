cmake_minimum_required(VERSION 2.6.2)

project(beej++)

add_definitions(-static -O2 -Wall -funsigned-char -std=c++11 -fPIC -pedantic -Wuninitialized)

include_directories("src")

file(GLOB_RECURSE sources "src/*.cpp")
file(GLOB_RECURSE test_server_sources "examples/test_server.cpp")
file(GLOB_RECURSE test_client_sources "examples/test_client.cpp")

add_library(beej++-static STATIC ${sources})
add_library(beej++ SHARED ${sources})

target_link_libraries(beej++-static -static-libgcc -static-libstdc++)
target_link_libraries(beej++ -static-libgcc -static-libstdc++)

install (TARGETS beej++-static DESTINATION lib)
install (TARGETS beej++ DESTINATION lib)
install (FILES src/beej.h DESTINATION include)

add_executable(test_server ${test_server_sources})
add_executable(test_client ${test_client_sources})

target_link_libraries(test_server -static-libgcc -static-libstdc++)
target_link_libraries(test_client -static-libgcc -static-libstdc++)

target_link_libraries(test_server ${CMAKE_CURRENT_BINARY_DIR}/libbeej++-static.a)
target_link_libraries(test_client ${CMAKE_CURRENT_BINARY_DIR}/libbeej++-static.a)

install (TARGETS test_server DESTINATION bin)
install (TARGETS test_client DESTINATION bin)

add_dependencies( test_server beej++-static)
add_dependencies(test_client beej++-static )
