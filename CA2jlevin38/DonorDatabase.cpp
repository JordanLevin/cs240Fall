#include "DonorDatabase.h"
#include <string>
#include <iostream>
#include <fstream>


DonorDatabase::DonorDatabase(int max_size){
    list = new Donor[max_size];
    this->max_size = max_size;
    this->current_size = 0;
}

void DonorDatabase::commands(){
    std::string input;

    std::cout << "Enter a command.\n";
    std::cout << 
        "Choose from [\"Add\" \"Login\" \"Save\" \"Load\" \"Report\" \"Quit\"]\n";
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
        this->load("");
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

    std::cout << "Please login to continue \n";
    std::cout << "Enter userid \n";
    std::cin >> userid;
    std::cout << "Enter password \n";
    std::cin >> password;
    for (int i = 0; i < this->max_size; ++i) {
        if(this->list[i].get_id() == userid){
            found_user = true;
            if(this->list[i].get_pass() == password){
                check_pass = true;
            }
            else{
                check_pass = false;
                break;
            }
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
}

void DonorDatabase::report(){
    //num of donors in db and total money donated
    int count = 0;
    float money = 0.0f;
    for(int i = 0; i < max_size; ++i){
        if(list[i].get_id() != "")
            ++count;
        money += list[i].donated;
    }
    std::cout << '\n';
    std::cout << "Donor count: " << count << "\n";
    std::cout << "Total donated: " << money << "$\n";
    std::cout << '\n';
}

void DonorDatabase::add(){
    if(current_size == max_size){
        std::cout << "Max size already reached\n";
        return;
    }
    Donor d(true);
    for (int i = 0; i < this->max_size; ++i) {
        if(this->list[i].get_id() == d.get_id()){
            std::cout << "User id already in use\n";
            return;
        }        
    }
    list[current_size] = d;
    current_size++;

}

void DonorDatabase::load(std::string file_name){
    float donated;
    int current_size, max_size, age, street_num, count=0;
    std::string last, first, password, street, town, userid, zip, temp, state;

    if(file_name == ""){
        std::cout << "\nEnter name of file to read from\n";
        std::cin >> file_name;
    }
    std::ifstream read(file_name);

    read >> max_size;
    read >> current_size;

    this->max_size = max_size;
    this->current_size = current_size;

    while(read.good()){
        //this is so it doesn't read extra data
        if(count == current_size)
            break;
        //reads all data into variables,
        //temp is used to read things which should be ints or floats
        //because getline only reads strings. then they get converted later
        std::getline(read, last, ',');
        std::getline(read, first, ',');
        std::getline(read, password, ',');
        std::getline(read, temp, ',');
        age = std::stoi(temp);
        std::getline(read, temp, ',');
        street_num = std::stoi(temp);
        std::getline(read, street, ',');
        std::getline(read, town, ',');
        std::getline(read, state, ',');
        std::getline(read, zip, ',');
        std::getline(read, temp, ',');
        donated = std::stof(temp);
        std::getline(read, userid, '\n');

        Donor d(last, first, password, age, street_num, street,
                town, donated, zip, userid, state);
        this->list[count] = d;
        count++;
    }
}

//TODO: ask user if they want to overwrite
void DonorDatabase::save(){
    std::string file_name;
    std::string input = "n";
    while(input == "n"){
        std::cout << "What file name should be saved?\n";
        std::cin >> file_name;

        if (std::ifstream(file_name)){
            std::cout << "File already exists, should it be overwritten (y/n)?\n";
            std::cin >> input;
        }
        else
            break;
    }
    std::ofstream write(file_name);
    write << this->max_size << "\n";
    write << this->current_size << "\n";
    for(int i = 0; i < this->max_size; i++){
        list[i].write_donor(write);
    }
}

void DonorDatabase::quit(){
    std::string input;
    std::cout << "Would you like to save the database (y/n)\n";
    std::cin >> input;
    if(input == "y")
        this->save();
    //add save to file thing later
    exit(EXIT_SUCCESS);
}
