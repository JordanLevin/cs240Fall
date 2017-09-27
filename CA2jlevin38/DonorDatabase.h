#ifndef DONORDATABASE_H
#define DONORDATABASE_H

#include <string>
#include "Donor.h"

class DonorDatabase{
    private:
        Donor* list;
        void login();
        void add();
        void save();
        void report();
        void quit();
    public:
        int max_size;
        int current_size;
        DonorDatabase(int max_size);
        void commands();
        void load(std::string file_name);
};

#endif
