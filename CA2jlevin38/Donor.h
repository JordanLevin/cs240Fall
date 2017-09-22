#ifndef DONOR_H
#define DONOR_H

#include <string>

class Donor{
    private:
        std::string last;
        std::string first;
        std::string password;
        int age;
        int street_num;
        std::string street;
        std::string town;
        //enum State state; 
        std::string zip;
    public:
        float donated;
        std::string userid;
        Donor(bool notdefault);
        Donor();
        void view();
        void total();
        void donate();
        void manage();
        bool commands();  
        bool operator==(Donor other);

};

#endif
