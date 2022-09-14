#include "../../Caso#2/lista/ListD.h"

#ifndef STACK

#define STACK 1

template <class T>
class Stack {
    private:
        List<T>* stackList;


    public:
        Stack() {
            stackList = new List<T>();
        }

        void push(T* pData) {
            stackList->add(pData);
            //stackList->setEmpty();
        }

        T* pop() {
            T* result = NULL;
            result = stackList->remove(0);
            return result;
        }

        T* top() {
            T* result = NULL;
            result = stackList->find(0);
            stackList->remove(0);
            return result;
        }

        bool isEmpty() {
            return stackList->isEmpty();
        }
};


#endif
