#include "Donor.h"
#include <iostream>
#include <string>
#include <iomanip>

Donor::Donor(){
    this->last = std::string("");
    this->first = std::string("");
    this->age = 0;
    this->street_num = 0;
    this->street = std::string("");
    this->town = std::string("");
    this->zip = std::string("");
    this->donated = 0.0f;
}
Donor::Donor(std::string last, std::string first, int age, int street_num,
        std::string street, std::string town, std::string zip, float donated){
    this->last = std::string(last);
    this->first = std::string(first);
    this->age = age;
    this->street_num = street_num;
    this->street = std::string(street);
    this->town = std::string(town);
    this->zip = std::string(zip);
    this->donated = donated;
}
void Donor::view(){
    std::cout << this->first << " " << this->last << ": Age " << this->age << "\n";
    std::cout << this->street_num << " " << this->street << "\n";
    std::cout << "Town: "<< this->town << ", NY, " << this->zip << "\n";
}
void Donor::total(){
    std::cout << "$" << std::fixed << std::setprecision(2) << this->donated << "\n";
}
void Donor::donate(float n){
    this->donated += n;
}
void Donor::update(std::string last="", std::string first="", int age=0, 
        int street_num=0, std::string street="", std::string town="", 
        std::string zip="", float donated=0.0f){
    if(last != "")
        this->last = std::string(last);
    if(first != "")
        this->first = std::string(first);
    if(age != 0)
        this->age = age;
    if(street_num != 0)
        this->street_num = street_num;
    if(street != "")
        this->street = std::string(street);
    if(town != "")
        this->town = std::string(town);
    if(zip != "")
        this->zip = std::string(zip);
    if(donated != 0.0)
        this->donated = donated;

}

float Donor::get_donated(){
    return this->donated;
}
        
bool Donor::operator==(const Donor& other){
    return this->userid == other.userid;
}

void Donor::commands(){
    std::cout << "Enter a command.\n";
    std::cout << 
        "Choose from [\"Add\" \"Manage\" \"View\" \"Donate\" \"Total\" \"Quit\"]\n";
    std::cout << ":";
    std::cin >> input;
    std::cout << "\n";
    if(input == "Add"){
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
        this->update(last, first, age, house, street, town, zip, 0.0f);
    }
    else if(input == "View"){
        this->view();
        std::cout << "Total amount donated: ";
        this->total();
    }
    else if(input == "Manage"){
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
        this->update(last, first, age, house, street, town, zip, 0.0f);
    }
    else if(input == "Donate"){
        float value;
        std::cout << "Enter a value to donate\n";
        std::cin >> value;
        this->donate(value);
    }
    else if(input == "Total"){
        this->total();
    }
    else if(input == "Quit"){
        return 0;
    }
    else{
        std::cout << "Invalid Command\n";
    }
}
