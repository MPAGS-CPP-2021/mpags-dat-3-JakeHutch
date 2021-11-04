#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("Test help request", "[help]") {
    ProgramSettings CmdSettings {false , false , "" , "" , "" , CipherMode::Encrypt};

    bool statush {processCommandLine(std::vector<std::string> {"", "-h"},  CmdSettings)};
    REQUIRE( (CmdSettings.helpRequested && statush) ); 

    bool statushelp {processCommandLine(std::vector<std::string> {"", "--help"},  CmdSettings)};
    REQUIRE( (CmdSettings.helpRequested && statushelp) ); 
}

TEST_CASE("Test version request", "[version]") {
    ProgramSettings CmdSettings {false , false , "" , "" , "" , CipherMode::Encrypt};

    bool status {processCommandLine(std::vector<std::string> {"", "--version"},  CmdSettings)};
    REQUIRE( (CmdSettings.versionRequested && status) ); 
}

TEST_CASE("Test input and output file", "[IO}") {
    ProgramSettings CmdSettings {false , false , "" , "" , "" , CipherMode::Encrypt};

    bool status {processCommandLine(std::vector<std::string> {"", "-i", "in", "-o", "out"},  CmdSettings)};
    REQUIRE( CmdSettings.inputFile == "in");
    REQUIRE( CmdSettings.outputFile == "out");
    REQUIRE(status);
}

TEST_CASE("Test key input", "[key]") {
    ProgramSettings CmdSettings {false , false , "" , "" , "" , CipherMode::Encrypt};

    bool status {processCommandLine(std::vector<std::string> {"", "-k", "5"},  CmdSettings)};
    REQUIRE( (CmdSettings.cipherKey=="5" && status) );
}

TEST_CASE("Test decrypt command", "[decrypt]") {
    ProgramSettings CmdSettings {false , false , "" , "" , "" , CipherMode::Encrypt};

    bool status {processCommandLine(std::vector<std::string> {"", "--decrypt"},  CmdSettings)};
    REQUIRE( (CmdSettings.mode==CipherMode::Decrypt && status) );
}