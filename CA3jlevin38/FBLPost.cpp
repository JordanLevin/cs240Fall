#include "FBLPost.h"

FBLPost::FBLPost(std::string t){
    text = t;
    likes = 0;
    original = &likes;
}

FBLPost::FBLPost(const FBLPost& other){
    likes = other.likes;
    text = other.text;
    original = const_cast<int*>(other.original);
}

FBLPost::FBLPost(){
    likes = 0;
    original = &likes;
}
