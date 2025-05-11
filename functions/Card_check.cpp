#include <iostream>
#include <fstream>
#include <string>
bool is_valid = false;
void card_check()
{

    std::cout << "Enter your card" << std::endl;
    std::ifstream card("card.txt");

    if (!card.is_open())
    {
        std::cout << "Card file not found" << std::endl;
        return;
    }
    
    for(int i = 0; i <= 100; i= i+10){
    _sleep(100);
    std::cout << "Card checking..." <<  i << "%" << std::endl;
    } 
    std::cout << "FINAL CHECKING" << std::endl;

    std::string line;
    while(card)
    {
        std::getline(card, line);
    }
    if(line.find("993MiroHodetAssemlyCCPP") != std::string::npos){
        std::cout << "Card is valid" << std::endl;
        is_valid = true;
        std::ofstream card_value("card_value.txt");
        card_value << "100" << std::endl;
        card_value.close();
    }
    else{
        std::cout << "Card is invalid" << std::endl;
        for(int i = 0; i <= 100; i= i+1)
        std::cout << "YOU SUSPECT FRAUD, RECREATE THE CARD!" << std::endl;

        card.close();
        system("del /F /Q card.txt");
    }
    

}