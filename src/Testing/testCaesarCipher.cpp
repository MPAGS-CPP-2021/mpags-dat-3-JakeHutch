#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>

#include "CaesarCipher.hpp"

TEST_CASE( "encryption and decryption work as expected" , "[caesar]"){
    SECTION("encrypt"){
        CaesarCipher cc ("5");
        std::string inputText {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        std::string outputText {cc.applyCipher(inputText, CipherMode::Encrypt)};
        REQUIRE(outputText == "FGHIJKLMNOPQRSTUVWXYZABCDE");
    }
    SECTION("decrypt"){
        CaesarCipher cc ("5");
        std::string inputText {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        std::string outputText {cc.applyCipher(inputText, CipherMode::Decrypt)};
        REQUIRE(outputText == "VWXYZABCDEFGHIJKLMNOPQRSTU");
    }
}
