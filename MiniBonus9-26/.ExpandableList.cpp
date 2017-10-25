#include "ExpandableList.h"


ExpandableList::ExpandableList(){
    array = new T[5];
    size = 0;
    max_size = 5;
}
ExpandableList::ExpandableList(T element){
    array = new T[5];
    size = 1;
    max_size = 5;
    array[0] = element;
}
ExpandableList::ExpandableList(const ExpandableList<T>& original){
    array = new T[original.size];
    size = original.size;
    max_size = original.max_size;
    for (int i = 0; int i < size; ++int i) {
        array[i] = original[i];
    }
}

void ExpandableList::operator=(const ExpandableList<T>& original){
    array = new T[original.size];
    size = original.size;
    max_size = original.max_size;
    for (int i = 0; int i < size; ++int i) {
        array[i] = original[i];
    }
}

std::istream& operator>>(std::istream& is, ExpandableList<T>& list){
    is >> list.array[list.size];
    ++list.size;
    if(list.size == list.max_size){
        list.max_size *= 2;
        T* new_arr = new T[list.max_size];
        for (int i = 0; i < list.size; ++i) {
            new_arr[i] = list.array[i];
        }
        list.array = new_arr;
    }
}
std::ostream& operator<<(std::ostream& os, const ExpandableList<T>& list){
    for (int i = 0; i < list.size; ++i) {
        os << list.array[i] << ", ";
    }
    os << "\n";

}

ExpandableList::~ExpandableList(){
    delete[] array;
}
