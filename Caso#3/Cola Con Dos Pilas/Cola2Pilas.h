#include "../Pilas/Pila2.h"
using namespace std;

#ifndef QUEUE

#define QUEUE 1

template <class T>
class Queue2 {
    private:
        Stack<T>* pila1;
        Stack<T>* pila2;
    public:
        Queue2() {
            pila1 = new Stack<T>;
            pila2 = new Stack<T>;
        }

        void enqueue(T* pValue) {
            pila1->push(pValue);
        }

        T* dequeue() {
            if (pila2->isEmpty()){
                while (!pila1->isEmpty()){
                    pila2->push(pila1->top());
                } 
            }
            return pila2->pop();       
        }

        T* front() {
            T* result = NULL;
            if(pila1->isEmpty()&&pila2->isEmpty()){
                return result;
            }else{
                if (pila1->isEmpty()){
                return pila2->top();
                }else{
                    return pila1->top();
                }
            }
            return result;
        }

        bool isEmpty() {
            bool result=false;
            if(pila1->isEmpty()&&pila2->isEmpty()){
                result=true;
                return result;
            }
            return result;
        }
};

#endif