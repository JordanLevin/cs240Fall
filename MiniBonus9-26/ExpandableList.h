#ifndef EXPANDABLELIST_H
#define EXPANDABLELIST_H

#include <iostream>

template <class T>
class ExpandableList{
    private:
        int size;
        int max_size;
        T* array;
    public:
        ExpandableList(){
            array = new T[5];
            size = 0;
            max_size = 5;
        }
        ExpandableList(T element){
            array = new T[5];
            size = 1;
            max_size = 5;
            array[0] = element;
        }
        ExpandableList(const ExpandableList<T>& original){
            array = new T[original.size];
            size = original.size;
            max_size = original.max_size;
            for (int i = 0; i < size; ++i) {
                array[i] = original[i];
            }
        }

        void operator=(const ExpandableList<T>& original){
            array = new T[original.size];
            size = original.size;
            max_size = original.max_size;
            for (int i = 0; i < size; ++i) {
                array[i] = original[i];
            }
        }

        friend std::istream& operator>>(std::istream& is, ExpandableList<T>& list){
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
        friend std::ostream& operator<<(std::ostream& os, const ExpandableList<T>& list){
            for (int i = 0; i < list.size; ++i) {
                os << list.array[i] << ", ";
            }
            os << "\n";

        }

        ~ExpandableList(){
            delete[] array;
        }
};

#endif /* ifndef EXPANDABLELIST_H */
