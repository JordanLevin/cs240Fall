#ifndef FBLCOMMENT_H
#define FBLCOMMENT_H 

#include <string>

class FBLComment {
    public:
        std::string text;
        std::string first;
        std::string last;
        FBLComment() = default;
        FBLComment(const FBLComment& original) = default;
        FBLComment(std::string t, std::string f, std::string l){
            text = t;
            first = f;
            last = l;
        }
};

#endif /* ifndef SYMBOL */
