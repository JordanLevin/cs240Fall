#include "FBLUser.h"

FBLUser::FBLUser(const FBLUser& original){
    wall = original.wall;
    userid = original.userid;
    password = original.password;
    first = original.first;
    last = original.last;
}

FBLUser::FBLUser(std::string u, std::string p, std::string f, std::string l){
    userid = u;
    password = p;
    first = f;
    last = l;
}

void FBLUser::add_post(FBLPost p){
    wall.append(p);
}

bool FBLUser::operator==(const FBLUser& other){
    return userid == other.userid;
}
