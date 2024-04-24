//On root
// . setup.sh

//On root
// . setup.sh

//In openrct2 run
//cmake --build build
//cd into build
//afl-fuzz -m none -Q -i in -o out -t 20000 -- ./test/tests/HarnessExecutable @@

#include <iostream>
#include <gtest/gtest.h>
#include <openrct2/core/Path.hpp>
#include <openrct2/drawing/ImageImporter.h>
#include <string_view>
#include <string>
#include <assert.h>
#include <fstream>

using namespace OpenRCT2::Drawing;
using namespace std;

int main(int argc, char* argv[]) {
    ImageImporter importer;
    auto image = Imaging::ReadFromFile(argv[1], IMAGE_FORMAT::PNG_32);
    auto meta = ImageImportMeta{ .offset = { 3, 5 } };
    auto result = importer.Import(image, meta);
    result.Buffer.data();
    int x = result.Element.width;
    int y = result.Element.height;
    (void)x;
    (void)y;
    return 0;
}