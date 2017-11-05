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
