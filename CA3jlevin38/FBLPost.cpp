#include "FBLPost.h"

FBLPost::FBLPost(std::string t){
    text = t;
    likes = 0;
    original = std::shared_ptr<int>(new int(0));
}

FBLPost::FBLPost(const FBLPost& other){
    likes = other.likes;
    text = other.text;
    original = other.original;
}

FBLPost::FBLPost(){
    likes = 0;
    original = std::shared_ptr<int>(new int(0));
}
