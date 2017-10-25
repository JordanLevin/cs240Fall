#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "FBLPost.h"
#include "FBLUser.h"
#include "LinkedList.h"



int menu_two(FBLUser& user, LinkedList<FBLUser>& users){
    std::string input;
    std::cout << "Enter a command: LOGOUT, POST, READ, FRIEND, " <<
        "MYFRIENDS, MYFEED, MYWALL\n";
    std::getline(std::cin, input);
    
    std::istringstream iss(input);
    std::vector<std::string> words;
    std::copy(std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(),
            std::back_inserter(words));
    if(words[0] == "READ"){
        if(user.feed.empty()){
            std::cout << "ERROR: post list empty\n";
            return -1;
        }
        std::cout << user.feed.pop_front().text << '\n';
        return 2;
    }
    else if(words[0] == "POST"){
        std::string text = input.substr(5,input.length());
        FBLPost post(text);
        user.add_post(post);
        for(auto& u: user.friends){
            u->feed.append(post);
        }
        //ill one line it later using std::transform
        //std::transform(user.friends.begin(), user.friends.end(),
                //user.friends.begin(), [&](){
                //}) 
        return 1;
    }
    else if(words[0] == "LOGOUT"){
        return 0;
    }
    else if(words[0] == "FRIEND"){
        std::string id = words[1];
        for(auto& u: users){
            if(u.userid == id){
                //this should really use a function and keep friends private
                user.friends.push_back(&u);
                u.friends.push_back(&user);
                break;
            }
        }

    }
    else if(words[0] == "MYFRIENDS"){
        for(const auto& f: user.friends){
            std::cout << f->first << " " << f->last << '\n';
        }
    }
    else if(words[0] == "MYFEED"){
        for(const auto p: user.feed){
            std::cout << p.text << '\n';
        }
    }
    else if(words[0] == "MYWALL"){
        for(const auto p: user.wall){
            std::cout << p.text << '\n';
        }
    }
    return -1;
}


int menu_top(LinkedList<FBLUser>& users){
    std::string input;
    std::cout << "Enter a command: CREATE, LOGIN, QUIT\n";
    std::getline(std::cin, input);

    //do some string stream magic to split by white space
    std::istringstream iss(input);
    std::vector<std::string> words;
    std::copy(std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(),
            std::back_inserter(words));

    if(words[0] == "CREATE"){
        std::string id = words[1];
        //need to check valid id
        std::string pass = words[2];
        std::string first = words[3];
        std::string last = words[4];
        FBLUser u(id, pass, first, last);
        for(auto user: users){
            if(u == user){
                std::cout << "User id taken\n";
                return -1;
            }
        }
        users.append(u);
        return 2;
    }
    else if(words[0] == "LOGIN"){
        std::string id = words[1];
        std::string password = words[2];
        FBLUser* u = nullptr;
        for(auto& user: users){
            if(user.userid == id){
                if(user.password != password){
                    std::cout << "Wrong password\n";
                    return -1;
                }
                u = &user;
                break;
            }
        }
        if(u == nullptr){
            return -1;
        }
        while(menu_two(*u, users)){}
        return 1;
    }
    else if(words[0] == "QUIT"){
        return 0;
    }
    std::cout << "Bad command\n";
    return -1;
}

int main(){
    LinkedList<FBLUser> users; 
    while(menu_top(users)){} 
    return 0;
}
