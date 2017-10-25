#include <iostream>
#include "ExpandableList.h"

int main(int argc, char *argv[])
{
    //ExpandableList<int> list;
    ExpandableList<float> list;
    while(true){
        std::cin >> list;
        std::cout << list;
    }
    return 0;
}
