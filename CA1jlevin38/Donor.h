#include <string>

class Donor{
    private:
        std::string last;
        std::string first;
        int age;
        int street_num;
        std::string street;
        std::string town;
        std::string zip;
        float donated;
    public:
        Donor();
        Donor(std::string last, std::string first, int age, int street_num,
                std::string street, std::string town, std::string zip, float donated);
        void view();
        void total();
        void donate(float n);
        void update(std::string last, std::string first, int age, 
                int street_num, std::string street, std::string town, 
                std::string zip, float donated);
        void update2(std::string last, std::string first, int age, 
                int street_num, std::string street, std::string town, 
                std::string zip, float donated);
        

};
