#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include "CipherMode.hpp"
#include <string>
#include <vector>

class CaesarCipher {
    public:
    explicit CaesarCipher(const std::size_t& key);

    explicit CaesarCipher(const std::string& key);

    std::string applyCipher (const std::string& inputText, const CipherMode encrypt) const;

    private:

    std::size_t key_ ;
    const std::vector<char> alphabet_;


};
#endif    // MPAGSCIPHER_CAESARCIPHER_HPP