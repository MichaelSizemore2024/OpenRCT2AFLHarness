//On root
// . setup.sh

//In openrct2 run
//cmake --build build
//cd into build
//afl-fuzz -m none -Q -i in -o out -t 20000 -- ./test/tests/HarnessExecutable @@

#include <iostream>
#include <gtest/gtest.h>
#include <openrct2/Context.h>
#include <openrct2/Game.h>
#include <openrct2/GameState.h>
#include <openrct2/OpenRCT2.h>
#include <openrct2/ParkImporter.h>
#include <openrct2/audio/AudioContext.h>
#include <openrct2/core/File.h>
#include <openrct2/core/Path.hpp>
#include <openrct2/core/String.hpp>
#include <openrct2/platform/Platform.h>
#include <openrct2/ride/Ride.h>
#include <string>
#include <assert.h>
#include <fstream>

using namespace OpenRCT2;
using namespace std;

int main(int argc, char* argv[]) {
    gOpenRCT2Headless = true;
    gOpenRCT2NoGraphics = true;

    
    auto context = CreateContext();
    if (!context){
        exit(EXIT_FAILURE);
    }

    bool initialized = context->Initialise();
    if (initialized == false){
        exit(EXIT_FAILURE);
    }

    bool loaded = GetContext()->LoadParkFromFile(argv[1]);
    if (loaded == false){
        exit(EXIT_FAILURE);
    }
    
    GameLoadInit();

    RideGetCount();
    auto& date = GetGameState().Date;
    date.GetMonthTicks();
}