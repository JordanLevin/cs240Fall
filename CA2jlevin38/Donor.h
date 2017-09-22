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
        enum State state; 
        std::string zip;
        float donated;
    public:
        std::string userid;
        Donor();
        Donor(std::string last, std::string first, int age, int street_num,
                std::string street, std::string town, std::string zip, float donated);
        void view();
        void total();
        float get_donated();
        void donate(float n);
        void update(std::string last, std::string first, int age, 
                int street_num, std::string street, std::string town, 
                std::string zip, float donated);
        void commands();  
        bool operator==(Donor other);

};
