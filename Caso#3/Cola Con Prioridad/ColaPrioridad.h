#include "Node.h"

#ifndef PRIOQUEUE

#define PRIOQUEUE 1

template <class T>
class PrioQueue {
    private:
        PrioNode<T> *first;
        PrioNode<T> *last;
        int quantity;
        bool empty;
        PrioNode<T> *searchPosition = NULL;
    
    public:
        PrioQueue() {
            first=NULL;
            last=NULL;
            quantity=0;
            empty=true;
        }

        void enqueue(T pValue, int pPrioridad = 0) {
            PrioNode<T> *newNode = new PrioNode<T>(pValue,pPrioridad);
            if (this->quantity>0){
                if (pPrioridad<this->first->getPrioridad()){
                    this->first->setNext(newNode);
                    newNode->setPrev(this->first);
                    this->first=newNode;
                } else if (pPrioridad>=first->getPrioridad()){
                    newNode->setNext(last);
                    this->last->setPrev(newNode);
                    this->last=newNode;
                }else {
                    searchPosition=this->first->getPrev();

                    while(searchPosition!=NULL){
                        if (searchPosition->getPrioridad()>pPrioridad){
                            newNode->setNext(searchPosition->getNext());
                            newNode->setPrev(searchPosition);
                            searchPosition->getNext()->setPrev(newNode);
                            searchPosition->setNext(newNode);
                            break;
                        } else{
                            searchPosition = searchPosition->getPrev(); 
                        }
                    }
                }
            } else{
                this->first=newNode;
                this->last=newNode;
            }
            quantity++;
            empty=false;
        }
        
        T dequeue() {
            if (!this->isEmpty()){
                T data = this->first->getData();
                if(this->first!=this->last){
                    this->first=this->first->getPrev();
                    this->first->getNext()->setNext(NULL);
                } else{
                    this->first=NULL;
                    this->last=NULL;
                }
                this->quantity--;
                return data;
            }
        }
        
        T front() {
            //T result = NULL;
            if (!this->isEmpty()) {
                return first->getData();
            }
            return 0;
            //return result;
        }
        
        bool isEmpty() {
            return !quantity;
        }

        int getQuantity(){
            return quantity;
        }
        
};

#endif