#ifndef DONOR_H
#define DONOR_H

#include <string>

enum State {NY, PA, RI, NH, VT, MA, CT, ME};

class Donor{
    private:
        std::string last;
        std::string first;
        std::string password;
        int age;
        int street_num;
        std::string street;
        std::string town;
        enum State state; 
        std::string zip;
        std::string userid;
        //public starts here eventually
    public:
        float donated;
        Donor(std::string last, std::string first, std::string password, int age, 
                int street_num, std::string street, std::string town, 
                float donated, std::string zip, std::string userid, std::string state);
        Donor(bool notdefault);
        Donor();
        void passwd();
        void view();
        void total();
        void donate();
        void manage();
        bool commands();  
        State get_state(std::string state);
        std::string state_to_string(State st);
        void write_donor(std::ofstream& write);
        std::string get_pass(){return password;}
        std::string get_id(){return userid;}

};

#endif
