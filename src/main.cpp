#include <iostream>
#include <string>
#include "enigma.cpp"

int main(){
    // SETUP //
    Enigma::EnigmaSettings settings;

    settings.leftRotor = Enigma::rotor1String;
    settings.midRotor = Enigma::rotor2String;
    settings.rightRotor = Enigma::rotor3String;

    settings.reflector = Enigma::ukwB;

    settings.ringSettingLeft = 10;
    settings.ringSettingMiddle = 4;
    settings.ringSettingRight = 23;

    settings.turnoverLeft = Enigma::rotor1Turnover;
    settings.turnoverMiddle = Enigma::rotor2Turnover;
    settings.turnoverRight = Enigma::rotor3Turnover;

    settings.positionLeft = 7;
    settings.positionMid = 18;
    settings.positionRight = 16;

    settings.plugboard = {"BE", "JF", "UP", "SQ", "TL", "GM", "YZ", "OC", "RD", "IX"};

    // TEST SCRIPT //

    std::string encryptedText = "THIS IS A DEFAULT TEST MESSAGE I CAME UP WITH TO DETERMINE IF MY ENIGMA MACHINE WORKED CORRECTLY WITH ROTOR TURNOVERS OR IF I WAS BEING VERY SILLY";
    encryptedText = Enigma::EnigmaEncrypt(encryptedText, settings);
    std::cout << encryptedText << "\n";
    std::cout << "RXNWP KTKUI KHXKS XLPWC LZZUO BTOVH GJBWF QINCF FDLBB UHFOF IIYBK DITFL XBKUL VGMOS ZRYJR NFXVB EKVIM WIGJZ VRXJJ JYQMC NKVFA PLYHW PUQRX MENN" << "\n";
    encryptedText = Enigma::EnigmaEncrypt(encryptedText, settings);
    std::cout << encryptedText << "\n";

    return 0;
}

// AMTAZ (Just a cool sounding name to consider in the future)