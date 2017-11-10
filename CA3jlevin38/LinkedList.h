#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>
#include <iostream>

template<class T> class LinkedList;

template<class T2>
class Node{
    private:
        //give linked list access to node internals
        friend class LinkedList<T2>;
        std::shared_ptr<Node<T2>> next;
        std::shared_ptr<Node<T2>> prev; //doubly linked
    public:
        T2 value;
        Node() = default;
        Node(T2 val){
            value = val;
        }
        Node(const Node<T2>& original){
            value = original.value;
            next = original.next;
            prev = original.prev; //doubly linked
        }
        ~Node() = default;
};

template<class T>
class LinkedList{
    private:
        std::shared_ptr<Node<T>> head;
    public:
        int size = 0;
        LinkedList() = default;
        LinkedList(T val){
            head = std::make_shared<Node<T>>(val);
            size = 1;
        }
        LinkedList(const LinkedList<T>& original){
            size = original.size;
            head = original.head;
        }
        void sort(){
            bool fix_head = false;
            auto largest = head; /* Find highest address in list */
            auto sorted = head; /* Node for which list is sorted until */
            std::shared_ptr<Node<T>> ret = nullptr;
            std::shared_ptr<Node<T>> t1, t2; /* for random misc temp node stuff */
            while(!this->is_sorted()){
                //std::cout << "Sorting\n";
                /* find largest and save its address, next, and prev */
                largest = this->find_max(sorted);
                if(largest->next == nullptr && sorted == largest)
                    break;
                if(!fix_head){
                    head = largest;
                    fix_head = true;
                }
                t1 = largest->prev;
                t2 = largest->next;

                if(sorted->next == largest){
                    largest->next = sorted;
                    largest->prev = sorted->prev;
                    if(largest->prev)
                        largest->prev->next = largest;
                    sorted->prev = largest;
                    sorted->next = t2;
                    continue;
                }

                /* put node 'largest' into list where sorted was */
                largest->prev = sorted->prev;
                largest->next = sorted->next;
                if(largest->next)
                    largest->next->prev = largest;
                if(largest->prev)
                    largest->prev->next = largest;

                /* put node 'sorted' back into list where largest was */
                if(t1)
                    t1->next = sorted;
                if(t2)
                    t2->prev = sorted;
                sorted->prev = t1;
                sorted->next = t2;

                sorted = largest->next;

            }
        }
        
        std::shared_ptr<Node<T>> find_max(std::shared_ptr<Node<T>> start){
            std::shared_ptr<Node<T>> largest = start; /* Find highest address in list */
            std::shared_ptr<Node<T>> curr = start;
            while(curr){
                if(curr->value.last < largest->value.last)
                    largest = curr;
                curr = curr->next;
            }
            return largest;
        }

        bool is_sorted(){
            auto curr = head;
            while(curr){
                if(curr->next->value.last >= curr->value.last)
                    return false;
                curr = curr->next;
            }
            return true;
        }

        void append(T val){
            auto current = head;
            if(current == nullptr){
                head = std::make_shared<Node<T>>(val);
                ++size;
                return;
            }
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = std::make_shared<Node<T>>(val);
            current->next->prev = current; //doubly linked
            ++size;
        }

        std::shared_ptr<T> pop_front(){
            if(head == nullptr){
                std::cout << "Error: popped from empty list\n";
                return nullptr;
            }
            auto ret = std::make_shared<T>(head->value);
            head = head->next;
            if(head != nullptr){
                head->prev = nullptr; //doubly linked
            }
            --size;
            return ret;
        }

        void print(){
            auto current = head;
            while(current != nullptr){
                std::cout << current->value << " -> ";
                current = current->next;
            }
            std::cout << "\n";
        }
        
        class Iterator {
            private:
                Node<T>* current;
            public:
                Iterator(Node<T>* init): 
                    current(init){}
                bool operator!=(const LinkedList<T>::Iterator& rhs){
                    return current != rhs.current;
                }
                bool operator==(const LinkedList<T>::Iterator& rhs){
                    return current == rhs.current;
                }
                void operator++(){
                    current = (current->next).get();
                }
                T& operator*(){
                    return current->value;
                }
        };
        
        LinkedList<T>::Iterator begin(){
            return LinkedList<T>::Iterator(head.get());
        }

        LinkedList<T>::Iterator end(){
            auto current = head.get();
            while(current != nullptr){
                current = (current->next).get();
            }
            return LinkedList<T>::Iterator(current);
        }

        bool empty(){
            return size == 0;
        }


        ~LinkedList() = default;
};



#endif
