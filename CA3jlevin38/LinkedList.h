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
    public:
        T2 value;
        Node() = default;
        Node(T2 val){
            value = val;
        }
        Node(const Node<T2>& original){
            value = original.value;
            next = original.next;
        }
        ~Node() = default;
};

template<class T>
class LinkedList{
    private:
        std::shared_ptr<Node<T>> head;
        int size = 0;
        
        class Iterator {
            private:
                std::shared_ptr<Node<T>> current;
            public:
                Iterator(std::shared_ptr<Node<T>> init){
                    current = init;
                }
                bool operator!=(const LinkedList<T>::Iterator& rhs){
                    return this->current != rhs->current;
                }
                LinkedList<T>::Iterator& operator++(){
                    current = current->next;
                    return this->current = this->current->next;
                }
                Node<T>& operator*(){
                    return current->value;
                }
        };

    public:
        LinkedList() = default;
        LinkedList(T val){
            head = std::make_shared<Node<T>>();
            size = 1;
        }
        LinkedList(const LinkedList<T>& original){
            size = original.size;
        }
        void append(T val){
            auto current = head;
            if(current == nullptr){
                head = std::make_shared<Node<T>>(val);
                return;
            }
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = std::make_shared<Node<T>>(val);
            ++size;
        }

        T pop_front(){
            T ret = head->value;
            head = head->next;
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
        
        LinkedList<T>::Iterator begin(){
            return LinkedList<T>::Iterator(head);
        }

        LinkedList<T>::Iterator end(){
            auto current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            return LinkedList<T>::Iterator(current);
        }


        ~LinkedList() = default;
};



#endif
