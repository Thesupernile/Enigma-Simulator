#include <iostream>
#include <string>
#include "enigma.cpp"

int main(){
    // SETUP //
    Enigma::EnigmaSettings settings;

    settings.rightRotor = Enigma::rotor1String;
    settings.midRotor = Enigma::rotor2String;
    settings.leftRotor = Enigma::rotor3String;

    settings.reflector = Enigma::ukwB;

    settings.ringSettingLeft = 0;
    settings.ringSettingMiddle = 0;
    settings.ringSettingRight = 0;

    settings.turnoverRight = Enigma::rotor1Turnover;
    settings.turnoverMiddle = Enigma::rotor2Turnover;
    settings.turnoverLeft = Enigma::rotor3Turnover;

    settings.positionLeft = 0;
    settings.positionMid = 0;
    settings.positionRight = 0;

    settings.plugboard = {"", "", "", "", "", "", "", "", "", ""};

    // TEST SCRIPT //

    std::string encryptedText = "HELLO WORLD";
    encryptedText = Enigma::EnigmaEncrypt(encryptedText, settings);
    std::cout << encryptedText << "\n";
    std::cout << "ILBM QKNGR" << "\n";
    encryptedText = Enigma::EnigmaEncrypt(encryptedText, settings);
    std::cout << encryptedText << "\n";

    return 0;
}