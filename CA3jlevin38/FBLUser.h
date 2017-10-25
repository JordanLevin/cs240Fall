#ifndef FBLUSER_H
#define FBLUSER_H

#include <string>
#include <vector>
#include "LinkedList.h"
#include "FBLPost.h"

class FBLUser{
    public:
        std::string first;
        std::string last;
        std::string password;
        std::string userid;
        std::vector<FBLUser*> friends;
        LinkedList<FBLPost> feed;
        LinkedList<FBLPost> wall; 

        FBLUser() = default;
        FBLUser(std::string u, std::string p, std::string f, std::string l);
        FBLUser(const FBLUser& original);
        void add_post(FBLPost p);
        void add_friend(FBLUser* u);
        bool operator==(const FBLUser& other);

        ~FBLUser() = default;


};

#endif
