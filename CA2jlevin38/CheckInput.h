#ifndef CHECKINPUT_H
#define CHECKINPUT_H 

#include <string>
#include <algorithm>

bool check_userid(std::string input);
bool check_pass(std::string input);
bool check_age(int input);
bool check_street_num(int input);
bool check_zip(std::string input);
bool check_donated(float input);
bool check_userid(std::string input);
bool check_letters_only(std::string input);

#endif
