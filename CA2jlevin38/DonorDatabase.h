#ifndef DONORDATABASE_H
#define DONORDATABASE_H


#include "Donor.h"

class DonorDatabase{
    private:
        Donor* list;
        void login();
        void add();
        void save();
        void load();
        void report();
        void quit();
    public:
        int max_size;
        int current_size;
        DonorDatabase(int max_size);
        void commands();
};

#endif
