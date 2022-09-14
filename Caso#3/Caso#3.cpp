#include <string>
#include <iostream>
#include <regex>
#include <vector>
#include "Pilas/Pila2.h"
#include "Cola Con Dos Pilas/Cola2Pilas.h"
#include "Pilas/Pila.h"
#include "../../Quizes/Quiz#6/Flight.h"
#include "Cola Con Prioridad/ColaPrioridad.h"

using namespace std;

//EJERCICIO #1
int obtPrecedencia(char x, char y){
        int prece1, prece2;

        switch (x){
        case '+': 
            prece1 = 1;break;
        case '-': 
            prece1 = 1;break;
        case '*': 
            prece1 = 2;break;
        case '/': 
            prece1 = 2;break;
        case '%': 
            prece1 = 3;
        }

        switch (y){
        case '+': 
            prece2 = 1;break;
        case '-': 
            prece2 = 1;break;
        case '*': 
            prece2 = 2;break;
        case '/': 
            prece2 = 2;break;
        case '%': 
            prece2 = 3;
        }
        if (x =='('||x ==')'||y =='('||y ==')'){
            return 10;
        }
        if (x==' '||y==' '){
            return 10;
        }
        return prece1-prece2;
    }

string infAPost(string pString){
    Pila<string>* numeros = new Pila<string>();
    Pila<char>* operadores = new Pila<char>();
    string parentesis[] = {"(",")"};
    int index=0;
    string result;

    for (int i=0; i<pString.size(); i++){
        if (pString[i]!='.'&&!isdigit(pString[i])){
            numeros->push(new string(pString.substr(index,i-index)));
            result+=pString.substr(index,i-index);
            string str(1,pString[i]);

            if (str == parentesis[1]){
                string end;
                end = *operadores->pop();

                while (end!=parentesis[0]){
                    if (operadores->isEmpty()){
                        cout<<"Error en la sintaxis"<<endl;
                        return "ERROR";
                    }
                    result+=end;
                    end = *operadores->pop();
                }
                
            }
            char exTop = ' ';
            if (!operadores->isEmpty()){
                exTop = *operadores->getTop();
            }
            operadores->push(new char(pString[i]));

            int prece = obtPrecedencia(exTop,*operadores->getTop());
            char temp = ' ';
            if(prece == 0){
                temp = *operadores->pop();
                result += *operadores->pop();
                operadores->push(new char(temp));
            }
            if (prece>0&&prece<10){
                temp = *operadores->getTop();
                result += *operadores->pop();
                operadores->push(new char(temp));
            }
            if (prece<0){
                result += *operadores->pop();
                result += *operadores->pop();
                result += *operadores->pop();
            }
            index = i+1;
        }
        if (i+1==pString.size()&&!isdigit(pString[pString.size()])){
            numeros->push(new string(pString.substr(index,pString.size())));

            result+= pString.substr(index,i-pString.size());
        }        
    }
    while (!operadores->isEmpty()){
        string str (1,*operadores->getTop());
        if (str!=")"){
            result+= *operadores->pop();
        }else{
            *operadores->pop();   
        }
    }
    return result;
}

bool validarStr(string pString){
    int resultado=pString.size();
    char parentesis[] = {'(',')'};
        for (int i=0; i<pString.size(); i++){
            if(isdigit(pString[i])||pString[i]=='+'||pString[i]=='-'||pString[i]=='*'||pString[i]=='/'||pString[i]=='%'||pString[i]==parentesis[0]||pString[i]==parentesis[1]){
                resultado--;
            }    
        }
    if (resultado==0){
        return true;
    } else{
        return false;
    }
}

//EJERCICIO #3
List<Flight>* lisVuelos = new List<Flight>();

void fillFlights(int pCantidad, int pStartHour, int pEndHour) {
    
    int hora, minutos, retraso, index, cantPasa;
    //vector<string> aerolineas = {"Aeromexico","American Airlines","British Airways","Avianca","Air Transat","Iberia"};
    srand(time(NULL));
    for (int i = 0; i < pCantidad; i++){
        hora = pStartHour + rand()%(pEndHour+1-pStartHour);
        minutos = 0 + rand()%(42+1-0);
        retraso = 0 + rand()%(17+1-0);
        //index = 0 + rand()%(aerolineas.size()+1-0);
        cantPasa = 150 + rand()%(550+1-150);
        minutos=minutos+retraso;
        Flight *vuelo = new Flight(hora,minutos,"Avianca",i+1,cantPasa);
        lisVuelos->add(vuelo);
    }
    
} 
int main(){  
    //EJERCICIO #1
    //string op = "10*4+(9/3*8)";

    string op = "10+(5-12)-4";
    
    if(validarStr(op)==true){
        cout<<infAPost(op)<<endl;
    } else{
        cout<<"La operación no cumple con el formato válido"<<endl;
    }
    
   //EJERCICIO #2
   cout<<"-----------------------------------------------------------\n"<<endl;
    Queue2<int>* cola = new Queue2<int>();
    
    cola->enqueue(new int(1));
    cola->enqueue(new int(2));
    cola->enqueue(new int(3));
    cola->enqueue(new int(4));
    
    cout<<*cola->front()<<endl; //Front=1
    cout<<cola->isEmpty()<<endl;//false

    cout<<*cola->dequeue()<<endl;//2
    cout<<*cola->dequeue()<<endl;//3
    
    cout<<*cola->front()<<endl; //Front=4
    cout<<cola->isEmpty()<<endl;//true

    //EJERCICIO #3
    cout<<"-----------------------------------------------------------\n"<<endl;

    
    fillFlights(10,8,11); //Creacion de vuelos aleatorios en un rango de horas definidas
    
    for (int i = 0; i < lisVuelos->getSize(); i++){
        cout<<"El vuelo numero "<<lisVuelos->find(i)->getNumVuelo()<<" su entero es: " <<lisVuelos->find(i)->getIntTimeValue() << endl;
    }
    
    PrioQueue<int>* colaVuelos1 = new PrioQueue<int>();
    colaVuelos1->enqueue(lisVuelos->find(0)->getNumVuelo(),lisVuelos->find(0)->getIntTimeValue());
    colaVuelos1->enqueue(lisVuelos->find(1)->getNumVuelo(),lisVuelos->find(1)->getIntTimeValue());
    colaVuelos1->enqueue(lisVuelos->find(2)->getNumVuelo(),lisVuelos->find(2)->getIntTimeValue());
    colaVuelos1->enqueue(lisVuelos->find(3)->getNumVuelo(),lisVuelos->find(3)->getIntTimeValue());

    cout<<"-----------------------------------------------------------\n"<<endl;
    while (!colaVuelos1->isEmpty()){
        cout<<"Vuelo numero "<<colaVuelos1->dequeue()<<endl;
    }
    
    PrioQueue<int>* colaVuelos2 = new PrioQueue<int>();
    colaVuelos2->enqueue(lisVuelos->find(4)->getNumVuelo(),lisVuelos->find(4)->getIntTimeValue());
    colaVuelos2->enqueue(lisVuelos->find(5)->getNumVuelo(),lisVuelos->find(5)->getIntTimeValue());
    colaVuelos2->enqueue(lisVuelos->find(6)->getNumVuelo(),lisVuelos->find(6)->getIntTimeValue());

    cout<<"-----------------------------------------------------------\n"<<endl;
    while (!colaVuelos2->isEmpty()){
        cout<<"Vuelo numero "<<colaVuelos2->dequeue()<<endl;
    }

    PrioQueue<int>* colaVuelos3 = new PrioQueue<int>();
    colaVuelos3->enqueue(lisVuelos->find(7)->getNumVuelo(),lisVuelos->find(7)->getIntTimeValue());
    colaVuelos3->enqueue(lisVuelos->find(8)->getNumVuelo(),lisVuelos->find(8)->getIntTimeValue());
    colaVuelos3->enqueue(lisVuelos->find(9)->getNumVuelo(),lisVuelos->find(9)->getIntTimeValue());

    cout<<"-----------------------------------------------------------\n"<<endl;
    while (!colaVuelos3->isEmpty()){
        cout<<"Vuelo numero "<<colaVuelos3->dequeue()<<endl;
    }
    
    

    return 0;
}



	
    
   
