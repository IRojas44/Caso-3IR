//#include "../dispositivo/Dispositivo.h"
#include <iostream>

#ifndef PRIONODE 

#define PRIONODE 1

using namespace std;

template <class T>
class PrioNode {
    private:
        T data;
        PrioNode *next;
        PrioNode *previous;
        int prioridad;
    
    public:
        PrioNode() {
            data = NULL;
            next = NULL;
            previous = NULL;
            prioridad = NULL;
        }

        PrioNode(T pData, int pPrioridad) {
            this->data = pData;
            this->prioridad = pPrioridad;
            next = NULL;
            previous = NULL;
        }

        T getData() {
            return data;
        }

        PrioNode* getNext() {
            return next;
        }

        PrioNode* getPrev() {
            return previous;
        }

        int getPrioridad(){
            return prioridad;
        }

        void setNext(PrioNode *pValue) {
            this->next = pValue;
        }

        void setPrev(PrioNode *pValue) {
            this->previous = pValue;
        }
};

#endif