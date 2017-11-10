#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "FBLPost.h"
#include "FBLUser.h"
#include "LinkedList.h"


int menu_three(FBLUser& user, FBLPost& post){
    std::string input;
    std::cout << "Enter a command: LIKE, COMMENT, READ_AZ, READ_ZA, DONE\n";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::vector<std::string> words;
    std::copy(std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(),
            std::back_inserter(words));
    if(words[0] == "LIKE"){
        (*(post.original))++;
        return 1;
    }
    else if(words[0] == "COMMENT"){
        post.comments.append(FBLComment(input.substr(8,input.length()),
            user.first, user.last));
        return 1;
    }
    else if(words[0] == "READ_AZ"){
        for(auto c: post.comments){
            std::cout << c.text << "\nPosted by " << c.first << " " << c.last << "\n";
        }
        return 1;
    }
    else if(words[0] == "READ_ZA"){
        std::vector<FBLComment> temp;
        for(auto c: post.comments){
            temp.push_back(c);
        }
        for(auto c = temp.rbegin(); c != temp.rend(); c++){
            std::cout << c->text << "\nPosted by " << c->first << " " << c->last << "\n";
        }
        return 1;
    }
    else if(words[0] == "DONE"){
        return 0;
    }
    else{
        std::cout << "Bad command\n";
        return -1;
    }
}

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
        //std::cout << "Size: " << user.feed.size << '\n';
        if(user.feed.empty()){
            std::cout << "ERROR: feed empty\n";
            return -1;
        }
        //auto temp = user.feed.pop_front();
        //if(temp == nullptr){}
        auto post_ptr = user.feed.pop_front();
        //std::cout << post_ptr << '\n';
        FBLPost& post = *(post_ptr);
        std::cout << post.text << '\n';
        while(menu_three(user, post)){}
        return 2;
    }
    else if(words[0] == "POST"){
        std::string text = input.substr(5,input.length());
        FBLPost post(text);
        user.add_post(post);
        for(auto& u: user.friends){
            u->feed.append(post);
            std::cout << '\n' << u->feed.size << '\n';
        }
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
        for(const auto& p: user.feed){
            std::cout << p.text << '\n';
        }
    }
    else if(words[0] == "MYWALL"){
        for(const auto& p: user.wall){
            //std::cout << "Likes: " << p.likes << " " << p.text << '\n';
            std::cout << "Likes: " << *(p.original) << " " << p.text << '\n';
        }
    }
    else{
        std::cout << "Bad command\n";
        return -1;
    }
}


int menu_top(LinkedList<FBLUser>& users){
    std::string input;
    std::cout << "Enter a command: CREATE, LOGIN, QUIT, USERS, SORTUSERS\n";
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
    else if(words[0] == "USERS"){
        for(auto& user: users){
            std::cout << user.last << ", " << user.first << " <" << user.userid << ">\n";
        }
        //do the thing
        return 1;
    }
    else if(words[0] == "SORTUSERS"){
        //do the thing
        users.sort();
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
