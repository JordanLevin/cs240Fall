#include <cctype>
#include "CheckInput.h"

//returns true if there are only letters in the input
bool check_letters_only(std::string input){
    return std::find_if(input.begin(), input.end(), 
            [](char c){ return !std::isalpha(c);}) == input.end();
}

//returns true if id is between 5 and 10 characters inclusive and alpha numeric
bool check_userid(std::string input){
    if(input.size() > 10 || input.size() < 5)
        return false;
    return std::find_if(input.begin(), input.end(), 
            [](char c){ return !std::isalnum(c);}) == input.end();
}

//returns true if length >= 6 and has >= 1 num and >= 1 non alpha numeric value
bool check_pass(std::string input){
    if(input.size() < 6)
        return false;
    bool has_non_alpha_num = std::find_if(input.begin(), input.end(), 
            [](char c){ return !std::isalnum(c);}) != input.end();
    bool has_num = std::find_if(input.begin(), input.end(), 
            [](char c){ return std::isdigit(c);}) != input.end();
    return has_num && has_non_alpha_num;
    
}

//checks age > 18
bool check_age(int input){
    return input > 18;
}

//check it is a positive int
bool check_street_num(int input){
    return input > 0;
}

//checks zip is 5 digits
bool check_zip(std::string input){
    bool ret = true;
    if(input.size() != 5)
        return false;
    for(char c: input){
        if(!std::isdigit(c))
            ret = false;
    }
    return ret;
}

//checks amount donated is positive
bool check_donated(float input){
    return input > 0;
}
