# CMake generated Testfile for 
# Source directory: C:/Lobovikov/Programming/labs/OOP/lab2
# Build directory: C:/Lobovikov/Programming/labs/OOP/lab2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(FourTests "C:/Lobovikov/Programming/labs/OOP/lab2/build/Debug/runTests.exe")
  set_tests_properties(FourTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Lobovikov/Programming/labs/OOP/lab2/CMakeLists.txt;41;add_test;C:/Lobovikov/Programming/labs/OOP/lab2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(FourTests "C:/Lobovikov/Programming/labs/OOP/lab2/build/Release/runTests.exe")
  set_tests_properties(FourTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Lobovikov/Programming/labs/OOP/lab2/CMakeLists.txt;41;add_test;C:/Lobovikov/Programming/labs/OOP/lab2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(FourTests "C:/Lobovikov/Programming/labs/OOP/lab2/build/MinSizeRel/runTests.exe")
  set_tests_properties(FourTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Lobovikov/Programming/labs/OOP/lab2/CMakeLists.txt;41;add_test;C:/Lobovikov/Programming/labs/OOP/lab2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(FourTests "C:/Lobovikov/Programming/labs/OOP/lab2/build/RelWithDebInfo/runTests.exe")
  set_tests_properties(FourTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Lobovikov/Programming/labs/OOP/lab2/CMakeLists.txt;41;add_test;C:/Lobovikov/Programming/labs/OOP/lab2/CMakeLists.txt;0;")
else()
  add_test(FourTests NOT_AVAILABLE)
endif()
subdirs("_deps/googletest-build")
