#include "Donor.h"
#include "DonorDatabase.h"
#include <string>
#include <iostream>

int main(int argc, char *argv[]){
    
    DonorDatabase db(std::stoi(argv[1]));
    //a file was passed in
    if(argc == 3){
        db.load(argv[2]);
    }
    Donor d;
    
    std::string input;

    //login info
    bool login = false;
    std::string userid, password;
    
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
