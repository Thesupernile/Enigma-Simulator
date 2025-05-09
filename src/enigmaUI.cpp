#include <string>
#include <iostream>
#include "enigma.cpp"

namespace EnigmaUI{
    std::string convertToUpper(std::string inputString){
        std::string outputString = "";
        for (char character : inputString){
            if (character >= 97 && character <= 122){
                character = character - 32;
            }
            outputString += character;
        }

        return outputString;
    }


    Enigma::EnigmaSettings getSettings(){
        Enigma::EnigmaSettings settings;

        // Rotors //
        /*settings.leftRotor = Enigma::rotor3;
        settings.midRotor = Enigma::rotor5;
        settings.rightRotor = Enigma::rotor4;

        settings.turnoverLeft = Enigma::rotor3Turnover;
        settings.turnoverMiddle = Enigma::rotor5Turnover;
        settings.turnoverRight = Enigma::rotor4Turnover;*/

        // Reflector //
        /*settings.reflector = Enigma::ukwB;*/

        // Ring Settings //
        /*settings.ringSettingLeft = 10;
        settings.ringSettingMiddle = 4;
        settings.ringSettingRight = 23;*/

        // Start Position // 
        /*settings.positionLeft = 0;
        settings.positionMid = 0;
        settings.positionRight = 0;*/

        // Plugboard //
        /*settings.plugboard = {"BE", "JF", "UP", "SQ", "TL", "GM", "YZ", "OC", "RD", "IX"};*/
        std::string rotorLeft = "I";
        std::string rotorMid = "II";
        std::string rotorRight = "III";
        std::string reflector = "ukw B";

        std::cout << "\n<---------------------------------->\n";
        std::cout << "Current Settings:\n\n";
        std::cout << "Rotors: " << rotorLeft << " " << rotorMid << " " << rotorRight << "\n";
        std::cout << "Reflector: " << reflector << "\n";
        std::cout << "Ring Settings: " << settings.ringSettingLeft << ", " << settings.ringSettingMiddle << ", " << settings.ringSettingRight << "\n";
        std::cout << "Plugboard Settings: " << settings.plugboard << "\n";

        return settings;
    }

    std::string getTextToEncrypt(){
        std::string inputText;

        std::cout << "Please enter the text you would like to encypt/decypt: \n";
        getline(std::cin >> std::ws, inputText);
        inputText = convertToUpper(inputText);

        return inputText;
    }
}