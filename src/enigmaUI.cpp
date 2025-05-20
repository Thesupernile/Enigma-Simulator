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

    int takeIntInput(){
        std::string userResponse;
        bool intInputted = false;
        while (!intInputted){
            std::cin >> userResponse;

            intInputted = true;
            for (char character : userResponse){
                if (!(character >= 48 && character <= 57)){
                    intInputted = false;
                }
            }
            if (intInputted == false){
                std::cout << "Please enter a valid integer number (eg. 3 or 17)";
            }
        }
        return stoi(userResponse);
    }

    std::string convertInputToRotor(std::string inputString){
        inputString = convertToUpper(inputString);

        if (inputString == "1" || inputString == "I"){
            return "I";
        }
        if (inputString == "2" || inputString == "II"){
            return "II";
        }
        if (inputString == "3" || inputString == "III"){
            return "III";
        }
        if (inputString == "4" || inputString == "IV"){
            return "IV";
        }
        if (inputString == "5" || inputString == "V"){
            return "V";
        }
        else {
            return "INVALID";
        }
    }

    void EnigmaWelcome(){
        std::string userResponse;
        std::cout << "Welcome to the enigma machine simulator, would you like to see the instructions? (Y/N)";
        std::cin >> userResponse;
        userResponse = convertToUpper(userResponse);
        if (userResponse == "Y"){
            std::cout << "To use the enigma machine, you first need to set up the machine. This means chosing which rotors ";
            std::cout << "you want to use, what ring setting they are on, what reflector you are using and how to set up the ";
            std::cout << "plugboard. Each message also needs a three letter passcode, which the program will ask for at the ";
            std::cout << "start of the decryption process. All of these elements must be known to decrypt the message that you ";
            std::cout << "encrypt using the machine. To decrypt, simply set the machine up exactly as it was when you encrypted the ";
            std::cout << "message and enter the encrypted message. This will recover the message so the intended recipient can read it. \n";
        }
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
        std::string userResponse;
        bool settingsConfirmed = false;

        while (!settingsConfirmed){
            std::cout << "\n<---------------------------------->\n";
            std::cout << "Current Settings:\n\n";
            std::cout << "1) Rotors: " << rotorLeft << ", " << rotorMid << ", " << rotorRight << "\n";
            std::cout << "2) Reflector: " << reflector << "\n";
            std::cout << "3) Ring Settings: " << settings.ringSettingLeft << ", " << settings.ringSettingMiddle << ", " << settings.ringSettingRight << "\n";
            std::cout << "4) Plugboard Pairings: " << settings.plugboard << "\n";
            if (settings.autoFormat){ std::cout << "5) Auto Formatting: Enabled \n"; }
            else { std::cout << "5) Auto Formatting: Disabled \n"; }
            std::cout << "<---------------------------------->\n";

            std::cout << "Would you like to change the enigma setup? Y/N\n";
            std::cin >> userResponse;
            userResponse = convertToUpper(userResponse);

            if (userResponse == "N"){
                settingsConfirmed = true;
            }
            else{
                std::cout << "Which setting would you like to change (1-5)? ";
                std::cin >> userResponse;
                if (userResponse == "1"){
                    std::string newRotor1;
                    std::string newRotor2;
                    std::string newRotor3;
                    bool rotorsChosen = false;

                    while (!rotorsChosen){
                        // Asks the user to give new rotors for each position
                        std::cout << "Please enter the rotor you would like to place in the leftmost slot (I, II, III, IV or V): \n";
                        std::cin >> newRotor1;
                        std::cout << "Please enter the rotor you would like to place in the middle slot (I, II, III, IV or V): \n";
                        std::cin >> newRotor2;
                        std::cout << "Please enter the rotor you would like to place in the rightmost slot (I, II, III, IV or V): \n";
                        std::cin >> newRotor3;

                        newRotor1 = convertInputToRotor(newRotor1);
                        newRotor2 = convertInputToRotor(newRotor2);
                        newRotor3 = convertInputToRotor(newRotor3);

                        if (newRotor1 != "INVALID" && newRotor2 != "INVALID" && newRotor3 != "INVALID"){
                            // Set the rotors in the machine to the rotors that the user has input
                            if (newRotor1 == "I") { settings.leftRotor = Enigma::rotor1; }
                            if (newRotor1 == "II") { settings.leftRotor = Enigma::rotor2; }
                            if (newRotor1 == "III") { settings.leftRotor = Enigma::rotor3; }
                            if (newRotor1 == "IV") { settings.leftRotor = Enigma::rotor4; }
                            if (newRotor1 == "V") { settings.leftRotor = Enigma::rotor5; }

                            if (newRotor2 == "I") { settings.midRotor = Enigma::rotor1; }
                            if (newRotor2 == "II") { settings.midRotor = Enigma::rotor2; }
                            if (newRotor2 == "III") { settings.midRotor = Enigma::rotor3; }
                            if (newRotor2 == "IV") { settings.midRotor = Enigma::rotor4; }
                            if (newRotor2 == "V") { settings.midRotor = Enigma::rotor5; }

                            if (newRotor3 == "I") { settings.rightRotor = Enigma::rotor1; }
                            if (newRotor3 == "II") { settings.rightRotor = Enigma::rotor2; }
                            if (newRotor3 == "III") { settings.rightRotor = Enigma::rotor3; }
                            if (newRotor3 == "IV") { settings.rightRotor = Enigma::rotor4; }
                            if (newRotor3 == "V") { settings.rightRotor = Enigma::rotor5; }

                            rotorLeft = newRotor1;
                            rotorMid = newRotor2;
                            rotorRight = newRotor3;

                            rotorsChosen = true;
                        }
                        else{
                            // Inform the user which rotor has been inputted incorrectly
                            if (newRotor1 != "INVALID"){ std::cout << "Unrecognised input for rotor 1\n"; }
                            if (newRotor2 != "INVALID"){ std::cout << "Unrecognised input for rotor 2\n"; }
                            if (newRotor3 != "INVALID"){ std::cout << "Unrecognised input for rotor 3\n"; }
                        }
                    }
                }
                else if (userResponse == "2"){
                    bool reflectorSelected = false;
                    while(!reflectorSelected){
                        std::cout << "Which reflector would you like to use? (B or C)";
                        std::cin >> userResponse;
                        userResponse = convertToUpper(userResponse);
                        if (userResponse == "B" || userResponse == "UKWB" || userResponse == "UKW B"){
                            settings.reflector = Enigma::ukwB;
                            reflector = "ukw B";
                            reflectorSelected = true;
                        }
                        else if (userResponse == "C" || userResponse == "UKWC" || userResponse == "UKW C"){
                            settings.reflector = Enigma::ukwB;
                            reflector = "ukw C";
                            reflectorSelected = true;
                        }
                    }
                }
                else if (userResponse == "3"){
                    std::cout << "What would you like to set the ring setting of the leftmost rotor to?\n";
                    settings.ringSettingLeft = takeIntInput() % 26;
                    std::cout << "What would you like to set the ring setting of the middle rotor to?\n";
                    settings.ringSettingMiddle = takeIntInput() % 26;
                    std::cout << "What would you like to set the ring setting of the rightmost to?\n";
                    settings.ringSettingRight = takeIntInput() % 26;
                }
                else if (userResponse == "4"){
                    settings.plugboard = "";
                    std::cout << "Plugboard Cleared \n";

                    std::string pairing = "";
                    while (pairing != "EXIT"){
                        std::cout << "Enter a pairing in the format AH or JG to add it to the plugboard (or \"exit\" to stop adding pairs): \n";
                        std::cin >> pairing;
                        pairing = convertToUpper(pairing);
                        if (pairing.length() == 2){
                            if (pairing[0] >= 65 && pairing[0] <= 90 && pairing[1] >= 65 && pairing[1] <= 90){
                                bool validPairing = true;
                                // Check if any of the letters is already plugged in
                                for (char character : settings.plugboard){
                                    if (character == pairing[0] || character == pairing[1]){
                                        validPairing = false;
                                        // Return Error to User
                                        if (character == pairing[0]){
                                            std::cout << "Error: " <<  pairing[0] << " already used in pairing\n";
                                        }
                                        if (character == pairing[1]){
                                            std::cout << "Error: " <<  pairing[1] << " already used in pairing\n";
                                        }
                                    }
                                }
                                if (validPairing){
                                    settings.plugboard = settings.plugboard + pairing[0] + pairing[1] + "-";
                                }
                            }
                        }
                        if (pairing == "EXIT" || settings.plugboard.length() >= 30){
                            pairing = "EXIT";
                            std::cout << "Exiting plugboard interface...\n";
                        }
                    }
                }
                else if (userResponse == "5"){
                    std::cout << "Would you like to auto format the output in the format XXXX XXXXX XXXXX? (Y/N): ";
                    std::cin >> userResponse;
                    userResponse = convertToUpper(userResponse);
                    if (userResponse == "Y"){
                        settings.autoFormat = true;
                    }
                    else if (userResponse == "N"){
                        settings.autoFormat = false;
                    }
                }
                else{
                    std::cout << "Unrecognised Input";
                }
            }
        }
        std::cout << "Machine setup complete \n";
        std::cout << "Please enter the message passcode in the format XXX : \n";
        bool validPasscodeEntered = false;

        while (validPasscodeEntered == false){
            std::cin >> userResponse;
            userResponse = convertToUpper(userResponse);
            if (userResponse.length() == 3 && (userResponse[0] >= 65 && userResponse[0] <= 90) && (userResponse[1] >= 65 && userResponse[1] <= 90) && (userResponse[2] >= 65 && userResponse[2] <= 90)){
                settings.positionLeft = userResponse[0] - 65;
                settings.positionMid = userResponse[1] - 65;
                settings.positionRight = userResponse[2] - 65;
                std::cout << "Input Accepted \n\n<---------------------------------->\n";
                validPasscodeEntered = true;
            }
            else{
                std::cout << "Unrecognised Input\n";
                std::cout << "Please enter a message passcode in the format XXX (eg. ADT, IHP or QXR)";
            }
        }

        return settings;
    }

    std::string getTextToEncrypt(){
        std::string inputText;

        std::cout << "Please enter the text you would like to encypt or decypt: \n";
        getline(std::cin >> std::ws, inputText);
        inputText = convertToUpper(inputText);

        return inputText;
    }
}