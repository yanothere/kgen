#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include <iomanip>
#include <vector>

class Characters {
public:
    std::string numbers = "0123456789";
    std::string lowers = "abcdefghijklmnopqrstuvwxyz";
    std::string uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string symbols = "!@#$%^&*()";
    std::string allChars = numbers + lowers + uppers + symbols;

    std::string getCharacterSet(
        bool useNumbers = true,
        bool useLowers = true,
        bool useUppers = true,
        bool useSymbols = true
    ) const {
        std::string charset;
        if (useNumbers) charset += numbers;
        if (useLowers) charset += lowers;
        if (useUppers) charset += uppers;
        if (useSymbols) charset += symbols;

        if (charset.empty()) {
            std::cerr << "Warning: No character sets selected!\nTherefore all possible ones will be used!" << std::endl;
            return allChars;
        }
        return charset;
    }
};

struct GenType {
    std::string name;
    std::string description;
};

const std::vector<GenType> genTypes = {
    {"--randkey", "Generate a random key with specified length and character sets"},
};

std::string genRandomKey(
    size_t length,
    const Characters& chars,
    bool useNumbers = true,
    bool useLowers = true,
    bool useUppers = true,
    bool useSymbols = true
) {
    std::string characters = chars.getCharacterSet(useNumbers, useLowers, useUppers, useSymbols);

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<size_t> distribution(0, characters.size() - 1);

    std::string randomString;
    for (size_t i = 0; i < length; ++i) {
        randomString += characters[distribution(generator)];
    }

    return randomString;
}

void printHelp() {
    std::cout << "\nkgen [gentype] [mods]\n" << std::endl;
            
    std::cout << std::left << std::setw(15) << "Type" << "Description\n"
        << std::string(50, '-') << "\n";

    std::cout << "=== Gen Types ===\n";

    for (const auto& genType : genTypes) {
        std::cout << std::left << std::setw(15) << genType.name << genType.description << "\n";
    }

    std::cout << "\n=== Modifiers ===\n"
        << std::left << std::setw(15) << "--length N" << "Specify the length of the key (default: 32)\n"
        << std::left << std::setw(15) << "--no-numbers" << "Allows you to create a key without numbers (has the abbreviation --no-nums)\n"
        << std::left << std::setw(15) << "--no-lowers" << "Allows you to create a key without lowers chars (has the abbreviation --no-lows)\n"
        << std::left << std::setw(15) << "--no-uppers" << "Allows you to create a key without uppers chars (has the abbreviation --no-ups)\n"
        << std::left << std::setw(15) << "--no-symbols" << "Allows you to create a key without symbols (has the abbreviation --no-syms)\n";


    std::cout << "\n=== Commands ===\n"
        << std::left << std::setw(15) << "--help" << "Show this help message\n"
        << std::left << std::setw(15) << "--version" << "Show version information\n"
        << std::left << std::setw(15) << "--cmds" << "Show available commands (same as --help)\n";

    std::cout << "\nExample:\n"
        << "  >> kgen --randkey --length 16\n"
        << "  Key: aB7#kP9mX2nQ5jL8\n"
        << std::endl;
}

int main(int argc, char* argv[]) {
    Characters chars;
    size_t length = 32;
    std::string hashType;

    bool useNumbers = true, useLowers = true, useUppers = true, useSymbols = true;

    if (argc == 1) {
        std::cerr << "\nMe!\nUse: kgen [gentype] [mods]\nExample: kgen --randkey --length 16\nKey: aB7#kP9mX2nQ5jL8\n\nMore: kgen --help || kgen --cmds\n" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--version") {
            std::cerr << "\nkgen v2205251 by Yanothere\nOpen source project using open source libraries OpenSSL\nAuthor: https://github.com/yanothere\nOpenSSL: https://github.com/openssl.\n" << std::endl;
            return 0;
        }
        else if (arg == "--help" || arg == "--cmds") {
            printHelp();
            return 0;
        }
        else if (arg == "--randkey") {
            hashType = "randkey";
        }
        else if (arg == "--no-numbers" || arg == "--wo-numbers" || arg == "--no-nums") {
            useNumbers = false;
        }
        else if (arg == "--no-lowers" || arg == "--wo-lowers" || arg == "--no-lows") {
            useLowers = false;
        }
        else if (arg == "--no-uppers" || arg == "--wo-uppers" || arg == "--no-ups") {
            useUppers = false;
        }
        else if (arg == "--no-symbols" || arg == "--wo-symbols" || arg == "--no-syms") {
            useSymbols = false;
        }
        else if (arg == "--length" && i + 1 < argc) {
            try {
                length = std::stoul(argv[++i]);
                if (length <= 0) {
                    std::cerr << "Error: Length must be greater than 0" << std::endl;
                    return 1;
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Error: Invalid length value" << std::endl;
                return 1;
            }
        }
        else {
            std::cerr << "Invalid argument: " << arg << std::endl;
            return 1;
        }
    }

    if (hashType.empty()) {
        std::cerr << "Error: Must specify a key type (--randkey)" << std::endl;
        return 1;
    }
    else if (hashType == "randkey") {
        std::cout << "Key: " << genRandomKey(length, chars, useNumbers, useLowers, useUppers, useSymbols) << std::endl;
    }

    return 0;
}