cmake_minimum_required(VERSION 3.7)

set(This AllTests)

set(Sources 
    Trie_tree_test.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    program
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
