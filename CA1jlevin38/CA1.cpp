#include "Donor.h"
#include <string>
#include <iostream>

int main(int argc, char *argv[]){
    Donor d;
    std::string input("");
    while(true){
        std::cout << "Enter a command.\n";
        std::cout << 
            "Choose from [\"Add\" \"Manage\" \"View\" \"Donate\" \"Total\" \"Quit\"]\n";
        std::cout << ":";
        std::cin >> input;
        std::cout << "\n";
        if(input == "Add"){
            std::string last("");
            std::string first("");
            int age = 0;
            std::string street("");
            int house = 0;
            std::string town("");
            std::string zip("");
            std::cout << "Last Name:";
            std::cin >> last;
            std::cout << "First Name:";
            std::cin >> first;
            std::cout << "Age:";
            std::cin >> age;
            std::cout << "House Number:";
            std::cin >> house;
            std::cout << "Street Name:";
            std::cin >> street;
            std::cout << "Town:";
            std::cin >> town;
            std::cout << "Zip Code:";
            std::cin >> zip;
            d.update(last, first, age, house, street, town, zip, 0.0f);
        }
        else if(input == "View"){
            d.view();
            std::cout << "Total amount donated: ";
            d.total();
        }
        else if(input == "Manage"){
            std::string last("");
            std::string first("");
            int age = 0;
            std::string street("");
            int house = 0;
            std::string town("");
            std::string zip("");
            std::cout << "Last Name:";
            std::cin >> last;
            std::cout << "First Name:";
            std::cin >> first;
            std::cout << "Age:";
            std::cin >> age;
            std::cout << "House Number:";
            std::cin >> house;
            std::cout << "Street Name:";
            std::cin >> street;
            std::cout << "Town:";
            std::cin >> town;
            std::cout << "Zip Code:";
            std::cin >> zip;
            d.update2(last, first, age, house, street, town, zip, 0.0f);
        }
        else if(input == "Donate"){
            float value;
            std::cout << "Enter a value to donate\n";
            std::cin >> value;
            d.donate(value);
        }
        else if(input == "Total"){
            d.total();
        }
        else if(input == "Quit"){
            return 0;
        }
        else{
            std::cout << "Invalid Command\n";
        }
    }
    return 0;
}
