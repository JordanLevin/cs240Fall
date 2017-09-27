#include "Donor.h"
#include "CheckInput.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

Donor::Donor(bool notdefault){
    bool check_inputs = false;
    int age, house;
    std::string input, userid, password, last, first, street, town, zip;
    State st;
    while(!check_inputs){
        std::cout << "Last Name: ";
        std::cin >> last;
        std::cout << "First Name: ";
        std::cin >> first;
        std::cout << "Age: ";
        std::cin >> age;
        std::cout << "House Number: ";
        std::cin >> house;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Street Name: ";
        std::getline(std::cin, street);
        std::cout << "Town: ";
        std::getline(std::cin, town);
        st = this->get_state("");
        std::cout << "Zip Code: ";
        std::cin >> zip;
        std::cout << "User Id: ";
        std::cin >> userid;
        std::cout << "Password: ";
        std::cin >> password;
        check_inputs = check_age(age) && check_zip(zip) && check_letters_only(last)
            && check_letters_only(first) && check_pass(password)
            && check_street_num(house) && check_userid(userid);
        if(!check_inputs){
            std::cout << "One or more inputs is bad\n";
            //give more details later
        }
    }
    this->last = last;
    this->first = first;
    this->age = age;
    this->street_num = house;
    this->street = street;
    this->town = town;
    this->state = st;
    this->zip = zip;
    this->userid = userid;
    this->password = password;
    this->donated = 0.0f;
}

Donor::Donor(std::string last, std::string first, std::string password, int age, 
        int street_num, std::string street, std::string town, 
        float donated, std::string zip, std::string userid, std::string state){
    this->last = last;
    this->first = first;
    this->age = age;
    this->street_num = street_num;
    this->street = street;
    this->town = town;
    this->state = get_state(state);
    this->zip = zip;
    this->userid = userid;
    this->password = password;
    this->donated = donated;

}

Donor::Donor() = default;

void Donor::view(){
    std::cout << this->first << " " << this->last << ": Age " << this->age << "\n";
    std::cout << this->street_num << " " << this->street << "\n";
    std::cout << "Town: "<< this->town << ", "<< state_to_string(state) <<", " << this->zip << "\n";
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
    if(n < 0){
        std::cout << "Error: Cant donate negative amount\n";
        return;
    }
    if(n + this->donated > 5000){
        std::cout << "Error: Cant donate over $5,000\n";
    }
    this->donated += n;
}

std::string Donor::state_to_string(State st){
    switch(st){
        case NY: return "NY";
        case RI: return "RI";
        case PA: return "PA";
        case NH: return "NH";
        case VT: return "VT";
        case MA: return "MA";
        case CT: return "CT";
        case ME: return "ME";
    }
    return "ERR";
}

State Donor::get_state(std::string state){
    State st;
    if(state == ""){
        std::cout << "State: ";
        std::cin >> state;
    }
    if(state == "NY")
        st = NY;
    else if(state == "PA")
        st = PA;
    else if(state == "RI")
        st = RI;
    else if(state == "NH")
        st = NH;
    else if(state == "VT")
        st = VT;
    else if(state == "MA")
        st = MA;
    else if(state == "CT")
        st = CT;
    else if(state == "ME")
        st = ME;
    else
        st = NY;
    return st;
}

//Manage values for a donor (needs testing)
void Donor::manage(){
    int age, house;
    float donated;
    std::string input, userid, password, last, first, street, town, zip, change;
    State state;
    std::cout << "Change last name? (y/n)\n";
    std::cin >> change;
    if(change == "y"){
        std::cout << "Last Name: ";
        std::cin >> last;
    }
    else
        last = this->last;
    std::cout << "Change first name? (y/n)\n";
    std::cin >> change;
    if(change == "y"){
        std::cout << "First Name: ";
        std::cin >> first;
    }
    else
        first = this->first;
    std::cout << "Change age? (y/n)\n";
    std::cin >> change;
    if(change == "y"){
        std::cout << "Age: ";
        std::cin >> age;
    }
    else
        age = this->age;
    std::cout << "Change house number? (y/n)\n";
    std::cin >> change;
    if(change == "y"){
        std::cout << "House Number: ";
        std::cin >> house;
    }
    else
        house = this->street_num;
    std::cout << "Change street name? (y/n)\n";
    std::cin >> change;
    if(change == "y"){
        std::cout << "Street Name: ";
        std::getline(std::cin, street);
    }
    else
        street = this->street;
    std::cout << "Change town? (y/n)\n";
    std::cin >> change;
    if(change == "y"){
        std::cout << "Town: ";
        std::getline(std::cin, town);
    }
    else
        town = this->town;
    std::cout << "Change state? (y/n)\n";
    std::cin >> change;
    if(change == "y"){
        state = this->get_state("");
    }
    else
        state = this->state;
    
    std::cout << "Change zip code? (y/n)\n";
    std::cin >> change;
    if(change == "y"){
        std::cout << "Zip Code: ";
        std::cin >> zip;
    }
    else
        zip = this->zip;
    std::cout << "Change amount donated? (y/n)\n";
    std::cin >> change;
    if(change == "y"){
        std::cout << "Amount donated: ";
        std::cin >> donated;
    }
    else
        donated = this->donated;

    this->last = last;
    this->first = first;
    this->age = age;
    this->street_num = house;
    this->street = street;
    this->town = town;
    this->state = state;
    this->zip = zip;
    this->donated = donated;
}

void Donor::passwd(){
    std::string passwd1, passwd2, input;
    std::cout << "Enter old password: ";
    std::cin >> input;
    if(input != this->password){
        std::cout << "Invalid password\n";
        return;
    }
    std::cout << "Enter new password: ";
    std::cin >> passwd1;
    std::cout << "Enter new password again: ";
    std::cin >> passwd2;
    if(passwd1 == passwd2){
        //check passwd requirements here
        if(check_pass(passwd1)){
            std::cout << "Password change successful\n";
            this->password = passwd1;
        }
        else{
            std::cout << "Password change unsuccessful, new password did not\
                meet the requirements\n";
        }
    }
    else{
        std::cout << "Password change unsuccessful, new passwords didnt match\n";
    }
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

void Donor::write_donor(std::ofstream& write){
    //check if the donor here is default
    if(first == "")
        return;
    write << last << ",";
    write << first << ",";
    write << password << ",";
    write << age << ",";
    write << street_num << ",";
    write << street << ",";
    write << town << ",";
    write << state_to_string(state) << ",";
    write << zip << ",";
    write << donated << ",";
    write << userid << "\n";
}

