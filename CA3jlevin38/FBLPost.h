#ifndef FBLPOST_H
#define FBLPOST_H

#include <string>

class FBLPost{
    private:

    public:
        std::string text;
        FBLPost() = default;
        FBLPost(std::string t);
        FBLPost(const FBLPost& other) = default;

        ~FBLPost() = default;
};

#endif
