DonorDatabase::DonorDatabase(int size){
    list = new Donor[size];
    this->size = size;
}

DonorDatabase::commands(){
    //std::string input, userid, password, last, first, street, town, zip;
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
    else if(){
        std::cout << "Invalid Command\n";
    }

}

Donor& DonorDatabase::login(){
    bool found_user = false, check_pass = false;
    std::string userid, password;
    Donor& ret = NULL; 

    std::cout << "Please login to continue \n";
    std::cout << "Enter userid \n";
    std::cin >> userid;
    std::cout << "Enter password \n";
    std::cin >> password;
    for (i = 0; i < this->size; ++i) {
        if(this->list[i].userid == userid){
            found_user = true;
            //TODO check pass
        } 
    }
    if(!found_user){
        std::cout << "Error: userid does not exist\n";
    }
    else if(!check_pass){
        std::cout << "Error: incorrect password\n";
    }
    return ret;
}

void DonorDatabase::report(){
    //num of donors in db and total money donated
    int count = 0;
    float money = 0.0f;
    for(auto const& account : list){
        ++count;
        money += account.get_donated();
    }
    std::cout << "Donor count: " << count << '\n';
    std::cout << "Total donated" << money << '\n';
}

void DonorDatabase::add(){


}

void DonorDatabase::load(){

}

void DonorDatabase::quit(){

}
