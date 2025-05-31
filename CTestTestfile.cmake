# CMake generated Testfile for 
# Source directory: /home/kali/workspace/projects/rk2
# Build directory: /home/kali/workspace/projects/rk2/_build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(run_tests "/home/kali/workspace/projects/rk2/_build/run_tests")
set_tests_properties(run_tests PROPERTIES  _BACKTRACE_TRIPLES "/home/kali/workspace/projects/rk2/CMakeLists.txt;40;add_test;/home/kali/workspace/projects/rk2/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
