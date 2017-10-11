#ifndef FBLUSER_H
#define FBLUSER_H

#include <string>
#include "LinkedList.h"
#include "FBLPost.h"

class FBLUser{
    private:
        std::string password;
        std::string first;
        std::string last;
    public:
        LinkedList<FBLPost> posts; 
        std::string userid;
        FBLUser() = default;
        FBLUser(std::string u, std::string p, std::string f, std::string l);
        FBLUser(const FBLUser& original) = default;
        void add_post(FBLPost p);

        ~FBLUser() = default;


};

#endif
