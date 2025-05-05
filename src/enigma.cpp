#include <string>
#include <vector>
#include <map>

namespace Enigma {

    // DEFINE ROTORS //
    const std::map<char, char> rotor1 = {
        {'A', 'E'}, {'B', 'K'}, {'C', 'M'}, {'D', 'F'}, {'E', 'L'},
        {'F', 'G'}, {'G', 'D'}, {'H', 'Q'}, {'I', 'V'}, {'J', 'Z'},
        {'K', 'N'}, {'L', 'T'}, {'M', 'O'}, {'N', 'W'}, {'O', 'Y'},
        {'P', 'H'}, {'Q', 'X'}, {'R', 'U'}, {'S', 'S'}, {'T', 'P'},
        {'U', 'A'}, {'V', 'I'}, {'W', 'B'}, {'X', 'R'}, {'Y', 'C'},
        {'Z', 'J'}
    };
    const int rotor1Turnover = 24;

    const std::map<char, char> rotor2 = {
        {'A', 'A'}, {'B', 'J'}, {'C', 'D'}, {'D', 'K'}, {'E', 'S'}, 
        {'F', 'I'}, {'G', 'R'}, {'H', 'U'}, {'I', 'X'}, {'J', 'B'},
        {'K', 'L'}, {'L', 'H'}, {'M', 'W'}, {'N', 'T'}, {'O', 'M'},
        {'P', 'C'}, {'Q', 'Q'}, {'R', 'G'}, {'S', 'Z'}, {'T', 'N'},
        {'U', 'P'}, {'V', 'Y'}, {'W', 'F'}, {'X', 'V'}, {'Y', 'O'},
        {'Z', 'E'}
    };
    const int rotor2Turnover = 12;

    std::map<char, char> rotor3 = {
        {'A', 'B'}, {'B', 'D'}, {'C', 'F'}, {'D', 'H'}, {'E', 'J'},
        {'F', 'L'}, {'G', 'C'}, {'H', 'P'}, {'I', 'R'}, {'J', 'T'},
        {'K', 'X'}, {'L', 'V'}, {'M', 'Z'}, {'N', 'N'}, {'O', 'Y'},
        {'P', 'E'}, {'Q', 'I'}, {'R', 'W'}, {'S', 'G'}, {'T', 'A'},
        {'U', 'K'}, {'V', 'M'}, {'W', 'U'}, {'X', 'S'}, {'Y', 'Q'},
        {'Z', 'O'}
    };
    const int rotor3Turnover = 3;

    std::map<char, char> rotor4 = {
        {'A', 'E'}, {'B', 'S'}, {'C', 'O'}, {'D', 'V'}, {'E', 'P'},
        {'F', 'Z'}, {'G', 'J'}, {'H', 'A'}, {'I', 'Y'}, {'J', 'Q'},
        {'K', 'U'}, {'L', 'I'}, {'M', 'R'}, {'N', 'H'}, {'O', 'X'},
        {'P', 'L'}, {'Q', 'N'}, {'R', 'F'}, {'S', 'T'}, {'T', 'G'},
        {'U', 'K'}, {'V', 'D'}, {'W', 'C'}, {'X', 'M'}, {'Y', 'W'},
        {'Z', 'B'}
    };
    const int rotor4Turnover = 17;

    std::map<char, char> rotor5 = {
        {'A', 'V'}, {'B', 'Z'}, {'C', 'B'}, {'D', 'R'}, {'E', 'G'},
        {'F', 'I'}, {'G', 'T'}, {'H', 'Y'}, {'I', 'U'}, {'J', 'P'},
        {'K', 'S'}, {'L', 'D'}, {'M', 'N'}, {'N', 'H'}, {'O', 'L'},
        {'P', 'X'}, {'Q', 'A'}, {'R', 'W'}, {'S', 'M'}, {'T', 'J'},
        {'U', 'Q'}, {'V', 'O'}, {'W', 'F'}, {'X', 'E'}, {'Y', 'C'},
        {'Z', 'K'}
    };
    const int rotor5Turnover = 7;

    // DEFINE REFLECTORS //
    std::map<char, char> ukwB = {
        {'A', 'Y'}, {'B', 'R'}, {'C', 'U'}, {'D', 'H'}, {'E', 'Q'},
        {'F', 'S'}, {'G', 'L'}, {'H', 'D'}, {'I', 'P'}, {'J', 'X'},
        {'K', 'N'}, {'L', 'G'}, {'M', 'O'}, {'N', 'K'}, {'O', 'M'},
        {'P', 'I'}, {'Q', 'E'}, {'R', 'B'}, {'S', 'F'}, {'T', 'Z'},
        {'U', 'C'}, {'V', 'W'}, {'W', 'V'}, {'X', 'J'}, {'Y', 'A'},
        {'Z', 'T'}
    };

    std::map<char, char> ukwC = {
        {'A', 'F'}, {'B', 'V'}, {'C', 'P'}, {'D', 'J'}, {'E', 'I'},
        {'F', 'A'}, {'G', 'O'}, {'H', 'Y'}, {'I', 'E'}, {'J', 'D'},
        {'K', 'R'}, {'L', 'Z'}, {'M', 'X'}, {'N', 'W'}, {'O', 'G'},
        {'P', 'C'}, {'Q', 'T'}, {'R', 'K'}, {'S', 'U'}, {'T', 'Q'},
        {'U', 'S'}, {'V', 'B'}, {'W', 'N'}, {'X', 'M'}, {'Y', 'H'},
        {'Z', 'L'}
    };

    // ENIGMA SETTINGS STRUCT //

    struct EnigmaSettings{
        std::map<char, char> leftRotor;
        std::map<char, char> midRotor;
        std::map<char, char> rightRotor;

        std::map<char, char> reflector;

        int ringSettingLeft;
        int ringSettingMiddle;
        int ringSettingRight;

        int turnoverLeft;
        int turnoverMiddle;
        int turnoverRight;

        int positionLeft;
        int positionMid;
        int positionRight;

        std::vector<std::string> plugboard = {"", "", "", "", "", "", "", "", "", ""};

    };

    // ENIGMA PROCESSING //

    std::map<char, char> generatePlugboard(std::vector<std::string> plugboardSettings) {
        std::map<char, char> plugboardMap;

        for (std::string& pairing : plugboardSettings){
            if (pairing.length() == 2){
                plugboardMap.insert({pairing[0], pairing[1]});
                plugboardMap.insert({pairing[1], pairing[0]});
            }
        }

        return plugboardMap;
    }

    char rotorEncrypt(char characterToEncrypt, std::map<char, char> rotor, int ringSetting){
        // Institutes the process for rotor encryption in the enigma machine
        std::string ciphertext = "";

        // Add in the ring setting offset
        if (characterToEncrypt >= 65 && characterToEncrypt <= 90){
            characterToEncrypt = ((characterToEncrypt - 65) + ringSetting) % 26 + 65;
        }

        // Encrypt through the rotor
        if(rotor.contains(characterToEncrypt)){
            characterToEncrypt = rotor[characterToEncrypt];
        }
        
        return characterToEncrypt;
    }

    char reflectorEncrypt(char characterToEncrypt, std::map<char, char> reflector){
        // Institutes the process for the enigma reflector
        if(reflector.contains(characterToEncrypt)){
            characterToEncrypt = reflector[characterToEncrypt];
        }
        return characterToEncrypt;
    }

    std::string EnigmaEncrypt(std::string plainText, EnigmaSettings settings){
        std::string cipherText = "";
        std::map<char, char> plugboardMap = generatePlugboard(settings.plugboard);

        for (char character : plainText){
            // Encrypt through the plugboard
            if (plugboardMap.contains(character)){
                character = plugboardMap[character];
            }

            // Encrypt through the rotors (right to left)
            character = rotorEncrypt(character, settings.rightRotor, settings.ringSettingLeft);
            character = rotorEncrypt(character, settings.midRotor, settings.ringSettingMiddle);
            character = rotorEncrypt(character, settings.leftRotor, settings.ringSettingRight);

            // Reflect
            character = reflectorEncrypt(character, settings.reflector);

            // Encrypt back through the rotors (left to right)
            character = rotorEncrypt(character, settings.rightRotor, settings.ringSettingRight);
            character = rotorEncrypt(character, settings.midRotor, settings.ringSettingMiddle);
            character = rotorEncrypt(character, settings.leftRotor, settings.ringSettingLeft);

            // Re-encrypt through the plugboard
            for (size_t i = 0; i < cipherText.length(); i++){
                if (plugboardMap.contains(cipherText[i])){
                    cipherText[i] = plugboardMap[cipherText[i]];
                }
            }

            cipherText = cipherText + character;

            // Move the rotors by one position
            settings.positionLeft = (settings.positionLeft + 1) % 26;
            // Check for turnovers
            if (settings.positionLeft == settings.turnoverLeft){
                settings.positionMid = (settings.positionMid + 1) % 26;
            }
            if (settings.positionMid == settings.turnoverMiddle){
                settings.positionMid = (settings.positionMid + 1) % 26;
                settings.positionRight = (settings.positionRight + 1) % 26;
            }
            
        }

        return cipherText;
    }
}