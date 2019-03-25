# CMake generated Testfile for 
# Source directory: /home/chus/CLionProjects/Scrabble/rapidjson/test/unittest
# Build directory: /home/chus/CLionProjects/Scrabble/cmake-build-debug/rapidjson/test/unittest
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unittest "/home/chus/CLionProjects/Scrabble/cmake-build-debug/bin/unittest")
set_tests_properties(unittest PROPERTIES  WORKING_DIRECTORY "/home/chus/CLionProjects/Scrabble/bin")
add_test(valgrind_unittest "valgrind" "--suppressions=/home/chus/CLionProjects/Scrabble/test/valgrind.supp" "--leak-check=full" "--error-exitcode=1" "/home/chus/CLionProjects/Scrabble/cmake-build-debug/bin/unittest" "--gtest_filter=-SIMD.*")
set_tests_properties(valgrind_unittest PROPERTIES  WORKING_DIRECTORY "/home/chus/CLionProjects/Scrabble/bin")
add_test(symbol_check "sh" "-c" "objdump -t -C libnamespacetest.a | grep rapidjson ; test \$? -ne 0")
set_tests_properties(symbol_check PROPERTIES  WORKING_DIRECTORY "/home/chus/CLionProjects/Scrabble/cmake-build-debug/rapidjson/test/unittest")
