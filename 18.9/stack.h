#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template<typename T>
class stack {
    private:
        T data[20];
        int size;
    
    public:
        stack() {
            size = 0;
        }
        void push(T val) {
            if (size == 20) {
                throw std::overflow_error("Called push on full stack.");
            }
            else {
                data[size] = val;
                size = size + 1;
                
            }
        }
        void pop() {
            if (size == 0) {
                throw std::out_of_range("Called pop on empty stack.");
            }
            else {
                size = size - 1;
            }
        }
        T top() {
            if (size == 0) {
                throw std::underflow_error("Called top on empty stack.");
            }
            else {
                return data[size - 1];
            }
        }
        bool empty() {
            if (size == 0) {
                return true;
            }
            return false;
        }
};

#endif