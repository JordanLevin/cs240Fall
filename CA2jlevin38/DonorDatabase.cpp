#include "DonorDatabase.h"
#include <string>
#include <iostream>


DonorDatabase::DonorDatabase(int max_size){
    list = new Donor[max_size];
    this->max_size = max_size;
    this->current_size = 0;
}

void DonorDatabase::commands(){
    std::string input;

    std::cout << "Enter a command.\n";
    std::cout << 
        "Choose from [\"Add\" \"Login\" \"Save\" \"Report\" \"Quit\"]\n";
    std::cin >> input;
    if(input == "Login"){
        this->login();
    }
    else if(input == "Add"){
        this->add();
    }
    else if(input == "Save"){
        this->save();
    }
    else if(input == "Load"){
        this->load();
    }
    else if(input == "Report"){
        this->report();
    }
    else if(input == "Quit"){
        this->quit();
    }
    else{
        std::cout << "Invalid Command\n";
    }

}

void DonorDatabase::login(){
    bool found_user = false, check_pass = false;
    std::string userid, password;
    //Donor& ret; 

    std::cout << "Please login to continue \n";
    std::cout << "Enter userid \n";
    std::cin >> userid;
    std::cout << "Enter password \n";
    std::cin >> password;
    for (int i = 0; i < this->max_size; ++i) {
        if(this->list[i].userid == userid){
            found_user = true;
            //TODO check pass
            bool cont = this->list[i].commands();
            while(cont){
                cont = this->list[i].commands();
            }
            break;
        } 
    }
    if(!found_user){
        std::cout << "Error: userid does not exist\n";
    }
    else if(!check_pass){
        std::cout << "Error: incorrect password\n";
    }
    //return ret;
}

void DonorDatabase::report(){
    //num of donors in db and total money donated
    int count = 0;
    float money = 0.0f;
    for(int i = 0; i < max_size; ++i){
        ++count;
        money += list[i].donated;
    }
    std::cout << "Donor count: " << count << '\n';
    std::cout << "Total donated" << money << '\n';
}

void DonorDatabase::add(){
    if(current_size == max_size){
        std::cout << "Max size already reached\n";
        return;
    }
    Donor d(true);
    for (int i = 0; i < this->max_size; ++i) {
        if(this->list[i].userid == d.userid){
            std::cout << "User id already in use\n";
            return;
        }        
    }
    list[current_size] = d;
    current_size++;

}

void DonorDatabase::load(){
    //do this later
}

void DonorDatabase::save(){
    //do this later
}

void DonorDatabase::quit(){
    //add save to file thing later
    exit(EXIT_SUCCESS);
}
