#include <iostream>
#include <fstream>
#include <string>
#include "Card_check.cpp"

void view()
{
if(is_valid == true)
    {
        std::ifstream card_value("card_value.txt");
        std::string line;
        while(getline(card_value, line))
        {
            std::cout << "Your balance: " << line << std::endl;
        }
        card_value.close();
    }
}   