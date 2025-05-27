#include <iostream>
#include <string>
#include "enigmaUI.cpp"

int main(){
    // SETUP //
    EnigmaUI::EnigmaWelcome();
    Enigma::EnigmaSettings settings = EnigmaUI::getSettings();

    std::string encryptedText = EnigmaUI::getTextToEncrypt();
    encryptedText = Enigma::EnigmaEncrypt(encryptedText, settings);
    std::cout << "Your encrypted message is: \n" << encryptedText << "\n";
    std::cout << "Type anything then press enter to exit the program\n";
    std::cin >> encryptedText;

    return 0;
}

// AMTAZ (Just a cool sounding name to consider in the future)