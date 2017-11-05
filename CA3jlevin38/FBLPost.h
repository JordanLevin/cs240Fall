#ifndef FBLPOST_H
#define FBLPOST_H

#include <string>
#include "FBLComment.h"
#include "LinkedList.h"

class FBLPost{
    public:
        int likes;
        int* original;
        std::string text;
        LinkedList<FBLComment> comments;
        FBLPost();
        //FBLPost() = default;
        FBLPost(std::string t);
        //FBLPost(const FBLPost& other) = default;
        FBLPost(const FBLPost& other);

        ~FBLPost() = default;
};

#endif
