#include <iostream>
#include <string>
#include "enigmaUI.cpp"

int main(){
    // SETUP //
    EnigmaUI::EnigmaWelcome();
    Enigma::EnigmaSettings settings = EnigmaUI::getSettings();

    std::string encryptedText = EnigmaUI::getTextToEncrypt();
    encryptedText = Enigma::EnigmaEncrypt(encryptedText, settings);
    std::cout << encryptedText << "\n";

    return 0;
}

// AMTAZ (Just a cool sounding name to consider in the future)