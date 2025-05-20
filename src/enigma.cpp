#include <string>
#include <vector>
#include <map>

namespace Enigma {
    // ROTORS HAVE TO SWITCH (so A maps to E on the first time through and E maps to A on the second time through) OTHERWISE
    // ENCRYPTION IS NOT SYMETRIC


    // DEFINE ROTORS //

    const std::string rotor1 = { "AE-BK-CM-DF-EL-FG-GD-HQ-IV-JZ-KN-LT-MO-NW-OY-PH-QX-RU-SS-TP-UA-VI-WB-XR-YC-ZJ" };
    const int rotor1Turnover = 16;

    const std::string rotor2 = { "AA-BJ-CD-DK-ES-FI-GR-HU-IX-JB-KL-LH-MW-NT-OM-PC-QQ-RG-SZ-TN-UP-VY-WF-XV-YO-ZE" };
    const int rotor2Turnover = 4;

    const std::string rotor3 = { "AB-BD-CF-DH-EJ-FL-GC-HP-IR-JT-KX-LV-MZ-NN-OY-PE-QI-RW-SG-TA-UK-VM-WU-XS-YQ-ZO" };
    const int rotor3Turnover = 21;

    const std::string rotor4 = { "AE-BS-CO-DV-EP-FZ-GJ-HA-IY-JQ-KU-LI-MR-NH-OX-PL-QN-RF-ST-TG-UK-VD-WC-XM-YW-ZB" };
    const int rotor4Turnover = 9;

    const std::string rotor5 = { "AV-BZ-CB-DR-EG-FI-GT-HY-IU-JP-KS-LD-MN-NH-OL-PX-QA-RW-SM-TJ-UQ-VO-WF-XE-YC-ZK" };
    const int rotor5Turnover = 25;

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
        /*std::map<char, char> leftRotor;
        std::map<char, char> midRotor;
        std::map<char, char> rightRotor;*/
        std::string leftRotor = rotor1;
        std::string midRotor = rotor2;
        std::string rightRotor = rotor3;

        int turnoverLeft = rotor1Turnover;
        int turnoverMiddle = rotor2Turnover;
        int turnoverRight = rotor3Turnover;

        std::map<char, char> reflector = ukwB;

        int ringSettingLeft = 0;
        int ringSettingMiddle = 0;
        int ringSettingRight = 0;

        int positionLeft = 0;
        int positionMid = 0;
        int positionRight = 0;

        bool autoFormat = true;

        std::string plugboard = "";

    };

    // ENIGMA PROCESSING //

    std::map<char, char> generatePlugboard(std::string plugboardSettings) {
        std::map<char, char> plugboardMap;

        for (size_t i = 1; i < plugboardSettings.size(); i += 3){
            plugboardMap.insert({plugboardSettings[i-1], plugboardSettings[i]});
            plugboardMap.insert({plugboardSettings[i], plugboardSettings[i-1]});
        }

        return plugboardMap;
    }

    char rotorEncrypt(char characterToEncrypt, std::string rotorString, int ringSetting, int position, bool encryptBackwards){
        // Institutes the process for rotor encryption in the enigma machine
        std::string ciphertext = "";
        std::map<char, char> rotor;

        for (size_t i = 0; i < rotorString.size(); i += 3){
            if (!encryptBackwards){
                rotor.insert({rotorString[i], rotorString[i + 1]});
            }
            else{
                rotor.insert({rotorString[i + 1], rotorString[i]});                
            }
        }

        // Add in the ring setting offset into this rotor
        characterToEncrypt = ((characterToEncrypt - 65) + 52 + (position - ringSetting)) % 26 + 65;

        // Encrypt through the rotor
        if(rotor.contains(characterToEncrypt)){
            characterToEncrypt = rotor[characterToEncrypt];
        }

        // Add in the ring setting offset to go to the next rotor
        characterToEncrypt = ((characterToEncrypt - 65) + 52 - (position - ringSetting)) % 26 + 65;
        
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
        int charsEncrypted = 0;

        for (char character : plainText){
            if (character >= 65 && character <= 90){
                charsEncrypted++;
                // Check for turnovers
                if (settings.positionRight == settings.turnoverRight){
                    settings.positionMid = (settings.positionMid + 1) % 26;
                }
                else if (settings.positionMid == settings.turnoverMiddle){
                    settings.positionMid = (settings.positionMid + 1) % 26;
                    settings.positionLeft = (settings.positionLeft + 1) % 26;
                }
                // Move the rotors by one position (enigma moved rotors before encrypting)
                settings.positionRight = (settings.positionRight + 1) % 26;

                // Encrypt through the plugboard
                if (plugboardMap.contains(character)){
                    character = plugboardMap[character];
                }

                // Encrypt through the rotors (right to left)
                character = rotorEncrypt(character, settings.rightRotor, settings.ringSettingRight, settings.positionRight, false);
                character = rotorEncrypt(character, settings.midRotor, settings.ringSettingMiddle, settings.positionMid, false);
                character = rotorEncrypt(character, settings.leftRotor, settings.ringSettingLeft, settings.positionLeft, false);

                // Reflect
                character = reflectorEncrypt(character, settings.reflector);

                // Encrypt back through the rotors (left to right)
                character = rotorEncrypt(character, settings.leftRotor, settings.ringSettingLeft, settings.positionLeft, true);
                character = rotorEncrypt(character, settings.midRotor, settings.ringSettingMiddle, settings.positionMid, true);
                character = rotorEncrypt(character, settings.rightRotor, settings.ringSettingRight, settings.positionRight, true);

                // Re-encrypt through the plugboard
                if (plugboardMap.contains(character)){
                    character = plugboardMap[character];
                }

                cipherText = cipherText + character;

                // Enigma messages were encrypted in the format XXXXX XXXXX XXXXX XXXXX so we add a space after every fifth character
                if (charsEncrypted % 5 == 0 && settings.autoFormat == true){
                    cipherText += " ";
                }
            }
            else if (settings.autoFormat == false && character == ' '){
                cipherText = cipherText + character;
            }
        }

        return cipherText;
    }
}




// Unused rotor code

/*
    const std::map<char, char> rotor1 = {
        {'A', 'E'}, {'B', 'K'}, {'C', 'M'}, {'D', 'F'}, {'E', 'L'},
        {'F', 'G'}, {'G', 'D'}, {'H', 'Q'}, {'I', 'V'}, {'J', 'Z'},
        {'K', 'N'}, {'L', 'T'}, {'M', 'O'}, {'N', 'W'}, {'O', 'Y'},
        {'P', 'H'}, {'Q', 'X'}, {'R', 'U'}, {'S', 'S'}, {'T', 'P'},
        {'U', 'A'}, {'V', 'I'}, {'W', 'B'}, {'X', 'R'}, {'Y', 'C'},
        {'Z', 'J'}
    };

    const std::map<char, char> rotor2 = {
        {'A', 'A'}, {'B', 'J'}, {'C', 'D'}, {'D', 'K'}, {'E', 'S'}, 
        {'F', 'I'}, {'G', 'R'}, {'H', 'U'}, {'I', 'X'}, {'J', 'B'},
        {'K', 'L'}, {'L', 'H'}, {'M', 'W'}, {'N', 'T'}, {'O', 'M'},
        {'P', 'C'}, {'Q', 'Q'}, {'R', 'G'}, {'S', 'Z'}, {'T', 'N'},
        {'U', 'P'}, {'V', 'Y'}, {'W', 'F'}, {'X', 'V'}, {'Y', 'O'},
        {'Z', 'E'}
    };

    std::map<char, char> rotor3 = {
        {'A', 'B'}, {'B', 'D'}, {'C', 'F'}, {'D', 'H'}, {'E', 'J'},
        {'F', 'L'}, {'G', 'C'}, {'H', 'P'}, {'I', 'R'}, {'J', 'T'},
        {'K', 'X'}, {'L', 'V'}, {'M', 'Z'}, {'N', 'N'}, {'O', 'Y'},
        {'P', 'E'}, {'Q', 'I'}, {'R', 'W'}, {'S', 'G'}, {'T', 'A'},
        {'U', 'K'}, {'V', 'M'}, {'W', 'U'}, {'X', 'S'}, {'Y', 'Q'},
        {'Z', 'O'}
    };

    std::map<char, char> rotor4 = {
        {'A', 'E'}, {'B', 'S'}, {'C', 'O'}, {'D', 'V'}, {'E', 'P'},
        {'F', 'Z'}, {'G', 'J'}, {'H', 'A'}, {'I', 'Y'}, {'J', 'Q'},
        {'K', 'U'}, {'L', 'I'}, {'M', 'R'}, {'N', 'H'}, {'O', 'X'},
        {'P', 'L'}, {'Q', 'N'}, {'R', 'F'}, {'S', 'T'}, {'T', 'G'},
        {'U', 'K'}, {'V', 'D'}, {'W', 'C'}, {'X', 'M'}, {'Y', 'W'},
        {'Z', 'B'}
    };

    std::map<char, char> rotor5 = {
        {'A', 'V'}, {'B', 'Z'}, {'C', 'B'}, {'D', 'R'}, {'E', 'G'},
        {'F', 'I'}, {'G', 'T'}, {'H', 'Y'}, {'I', 'U'}, {'J', 'P'},
        {'K', 'S'}, {'L', 'D'}, {'M', 'N'}, {'N', 'H'}, {'O', 'L'},
        {'P', 'X'}, {'Q', 'A'}, {'R', 'W'}, {'S', 'M'}, {'T', 'J'},
        {'U', 'Q'}, {'V', 'O'}, {'W', 'F'}, {'X', 'E'}, {'Y', 'C'},
        {'Z', 'K'}
    };



*/