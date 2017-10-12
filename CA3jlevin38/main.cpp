#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "FBLPost.h"
#include "FBLUser.h"
#include "LinkedList.h"



int menu_two(FBLUser& user){
    std::string input;
    std::cout << "Enter a command: LOGOUT, POST, READ\n";
    std::getline(std::cin, input);
    
    std::istringstream iss(input);
    std::vector<std::string> words;
    std::copy(std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(),
            std::back_inserter(words));
    if(words[0] == "READ"){
        std::cout << user.posts.pop_front().text << '\n';
        return 2;
    }
    else if(words[0] == "POST"){
        std::string text = words[1];
        FBLPost post(text);
        user.add_post(post);
        return 1;
    }
    else if(words[0] == "LOGOUT"){
        return 0;
    }
    return -1;
}


int menu_top(LinkedList<FBLUser>& users){
    std::string input;
    std::cout << "Enter a command: CREATE, LOGIN, QUIT\n";
    std::getline(std::cin, input);

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
        FBLUser user(id, pass, first, last);
        users.append(user);
        return 2;
    }
    else if(words[0] == "LOGIN"){
        std::string id = words[1];
        LinkedList<FBLUser>::Iterator user = users.begin();
        for(auto user: users){
            if(user.userid == id){
                break;
            }
        }
        //check login
        int cont = menu_two(*user);
        while(cont){
            cont = menu_two(*user);
        }
        return 1;
    }
    else if(words[0] == "QUIT"){
        return 0;
    }
    return -1;
}

int main(){
    LinkedList<FBLUser> users; 
    int cont = menu_top(users);
    while(cont != 0){
        cont = menu_top(users);
    } 
    return 0;
}
