#include "FBLUser.h"

FBLUser::FBLUser(std::string u, std::string p, std::string f, std::string l){
    userid = u;
    password = p;
    first = f;
    last = l;
}

void FBLUser::add_post(FBLPost p){
    posts.append(p);
}
