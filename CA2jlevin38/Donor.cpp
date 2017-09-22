#include "Donor.h"
#include <iostream>
#include <string>
#include <iomanip>

Donor::Donor(bool notdefault){
    int age, house;
    std::string input, userid, password, last, first, street, town, zip;
    std::cout << "Last Name: ";
    std::cin >> last;
    std::cout << "First Name: ";
    std::cin >> first;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "House Number: ";
    std::cin >> house;
    std::cout << "Street Name: ";
    std::cin >> street;
    std::cout << "Town: ";
    std::cin >> town;
    std::cout << "Zip Code: ";
    std::cin >> zip;
    std::cout << "User Id: ";
    std::cin >> userid;
    std::cout << "Password: ";
    std::cin >> password;
    this->last = last;
    this->first = first;
    this->age = age;
    this->street_num = street_num;
    this->street = street;
    this->town = town;
    this->zip = zip;
    this->userid = userid;
    this->password = password;
    this->donated = 0.0f;
}

Donor::Donor(){
    this->last = "";
    this->first = "";
    this->age = 0;
    this->street_num = 0;
    this->street = "";
    this->town = "";
    this->zip = "";
    this->userid = "";
    this->password = "";
    this->donated = 0.0f;
}

void Donor::view(){
    std::cout << this->first << " " << this->last << ": Age " << this->age << "\n";
    std::cout << this->street_num << " " << this->street << "\n";
    std::cout << "Town: "<< this->town << ", NY, " << this->zip << "\n";
}

//Displayed the last name and money donated formatted nicely
void Donor::total(){
    std::cout << last << " $" << std::fixed << std::setprecision(2) << donated << "\n";
}

//Requests a value from the user and donates that value
void Donor::donate(){
    float n;
    std::cout << "Enter an amount to donate\n";
    std::cin >> n;
    this->donated += n;
}

//needs work
void Donor::manage(){
    int age, house;
    float donated;
    std::string input, userid, password, last, first, street, town, zip;
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
    std::cout << "Amount donated";
    std::cin >> donated;
    this->last = last;
    this->first = first;
    this->age = age;
    this->street_num = street_num;
    this->street = street;
    this->town = town;
    this->zip = zip;
    this->donated = donated;
}

bool Donor::passwd(){

}

bool Donor::commands(){
    std::string input;

    std::cout << "Enter a command.\n";
    std::cout << 
        "Choose from [\"Manage\" \"Passwd\" \"View\" \"Donate\" \"Total\" \"Logout\"]\n";
    std::cin >> input;
    if(input == "View"){
        this->view();
        std::cout << "Total amount donated: ";
        this->total();
        return true;
    }
    else if(input == "Manage"){
        this->manage();
        return true;
    }
    else if(input == "Donate"){
        this->donate();
        return true;
    }
    else if(input == "Total"){
        this->total();
        return true;
    }
    else if(input == "Passwd"){
        this->passwd();
        return true;
    }
    else if(input == "Logout"){
        return false;
    }
    else{
        std::cout << "Invalid Command\n";
        return true;
    }
}
