#include <iostream>
#include <string>
#include "enigma.cpp"

int main(){
    // SETUP //
    Enigma::EnigmaSettings settings;

    settings.leftRotor = Enigma::rotor1;
    settings.midRotor = Enigma::rotor2;
    settings.rightRotor = Enigma::rotor3;

    settings.reflector = Enigma::ukwB;

    settings.ringSettingLeft = 0;
    settings.ringSettingMiddle = 0;
    settings.ringSettingRight = 0;

    settings.turnoverLeft = Enigma::rotor1Turnover;
    settings.turnoverMiddle = Enigma::rotor2Turnover;
    settings.turnoverRight = Enigma::rotor3Turnover;

    settings.positionLeft = 0;
    settings.positionMid = 0;
    settings.positionRight = 0;

    settings.plugboard = {"", "", "", "", "", "", "", "", "", ""};

    // TEST SCRIPT //

    std::cout << "HELLO WORLD\n";
    std::string encryptedText = "HELLO WORLD";
    encryptedText = Enigma::EnigmaEncrypt(encryptedText, settings);
    std::cout << encryptedText << "\n";
    std::cout << "iladb bmtbz" << "\n";

    return 0;
}