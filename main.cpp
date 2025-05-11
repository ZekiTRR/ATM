#include <iostream>
#include <ctime>
#include "functions/Card_check.cpp"
int main(int argc, char const *argv[])
{
    std::cout << "YOKO ATM" << std::endl;
    std::time_t now = std::time(nullptr);

    char* data_now = std::ctime(&now);
    std::cout << data_now << std::endl;

    card_check();

    std::cin.get();
    return 0;
}
