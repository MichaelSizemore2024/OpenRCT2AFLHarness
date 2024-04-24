# OpenRCT2AFLHarness
An AFL++ Harness to fuzz test some of the functions used in OpenRCT2
Currently just tests the LoadParkFromFile and ReadFromFile functions used in OpenRCT2

# Usage
-Clone OpenRCT2 Repository

-Install Linux prerequisites

-cmake -S . -B build -DWITH_TESTS=on

-cmake --build build

-. setup.sh

-copy all files into test/tests

-copy in folder into build

-cd build

-afl-fuzz -m none -Q -i in -o out -t 20000 -- ./test/tests/HarnessExecutable @@
