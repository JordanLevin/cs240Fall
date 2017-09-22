#include "Donor.h"
#include "DonorDatabase.h"
#include <string>
#include <iostream>

int main(int argc, char *argv[]){
    
    DonorDatabase db(std::stoi(argv[1]));
    std::cerr << "TEST";
    Donor d;
    
    std::string input;

    //login info
    bool login = false;
    std::string userid, password;
    
    //donor info for add and manage
    std::string last, first, street, town, zip;
    int age, house;
    while(true){
        if(login){
            if(d.commands())
                continue;
            else{
                login = false;
                continue;
            }
        }
        else{
            db.commands();
        }
    }
    return 0;
}
