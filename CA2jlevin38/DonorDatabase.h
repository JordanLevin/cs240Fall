#include "Donor.h"

class DonorDatabase{
    private:
        int size;
        Donor* list;
        Donor& login();
        void add();
        void save();
        void load();
        void report();
        void quit();
    public:
        DonorDatabase(int size);
};
