#include <iostream>
#include <string>
#include "enigmaUI.cpp"

int main(){
    // SETUP //
    bool runProgram = true;

    EnigmaUI::EnigmaWelcome();
    Enigma::EnigmaSettings settings = EnigmaUI::getSettings();

    std::string encryptedText = EnigmaUI::getTextToEncrypt();
    while (runProgram){
        encryptedText = Enigma::EnigmaEncrypt(encryptedText, settings);
        std::cout << "Your encrypted message is: \n" << encryptedText << "\n";
        runProgram = EnigmaUI::IsRepeatRequired();
        if (EnigmaUI::IsSettingsChangeRequired()){
            settings = EnigmaUI::getSettings();
        }
    }
    
    return 0;
}

// AMTAZ (Just a cool sounding name to consider in the future)