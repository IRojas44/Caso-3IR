#include "../../Caso#2/lista/NodoD.h"

using namespace std;

template <class T>
class Pila {
    private:
        Node<T> *top;
        int quantity;
        bool empty;

    public:
        Pila() {
            top = NULL;
            quantity = 0;
            empty = true;
        }
        
        T* getTop(){
            T* result = NULL;
            if(top==NULL){
                return NULL;
            }
            //Node<T>* search = top->getData(); 
            //result = top->getData();  
            return top->getData();  
        }
        
        void push(T *pData){
            Node<T> *newNode = new Node<T>(pData);
            newNode->setNext(top);
            this->top = newNode;
            empty = false;
            quantity++;
        }

        bool isEmpty() {
            return !quantity;
        }

        T* pop(){
            T* result = NULL;
            if(top!=NULL){
                Node<T> *search = top;
                top=search->getNext();
                result = search->getData();
                delete search;
                quantity--;
                return result;
            }else{
                return NULL;
            }
            //result = true;
            return result;

        }
};