#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

template <class T> class Nodo{
public:
    T valore;
    Nodo* succ;
    Nodo* prec;
};

template <class T> class Coda{ //eliminare il circolare o il puntatore a coda
Nodo<T>* testa;
Nodo<T>* coda;

public:
    Coda() {testa = nullptr; coda = nullptr;}
    //~Coda();

    Nodo<T>* getTesta() {return testa;}

    void enqueue(T val){
        Nodo<T>* nuovo = new Nodo<T>;
        nuovo->valore = val;
        nuovo->succ = nullptr;
        if(!this->coda){
            this->testa = nuovo;
            this->coda = this->testa;
        }else {
            this->coda->succ = nuovo;
            this->coda = nuovo;
        }
        
    }

    T dequeue(){
        Nodo<T>* nd;
        T val;
        if(this->testa == nullptr){
            cout << "Coda vuota: impossibile eseguire la dequeue."<<endl;
            return -1;
        }
        else {
            if(this->testa == this->coda){
                nd = this->testa;
                val = this->testa->valore;
                this->testa = nullptr;
                this->coda = nullptr;
            }else {
                nd = this->testa;
                val = this->testa->valore;
                this->testa = this->testa->succ;
            }
        }
        delete nd;
        return val;
    }

    friend ostream& operator<<(ostream& out, const Coda<T>& cd){
        Nodo<T>* iter = cd.testa;
        for( ; iter != cd.coda; iter=iter->succ)
            out<< iter->valore <<" --> ";
        if(iter)
            out<< iter->valore << " --> ";

        out<<"NULL";
        return out;
    }
};

/*
Pila::~Pila(){
    Nodo<T>* iter = this->testa;

    while(iter!=nullptr){
        Nodo<T>* temp = iter->succ;
        delete iter;
        iter = temp;
    }
}*/

int main(){

    Coda<int> codai;

    codai.enqueue(10);
    codai.enqueue(13);
    codai.enqueue(15);

    cout << "0: " << codai << endl;

    int tmp=codai.dequeue();

    cout << "1: " << codai << endl;
    tmp=codai.dequeue();
    cout << "2: " << codai << endl;
    tmp=codai.dequeue();
    cout << "3: "<< codai << endl;
    tmp=codai.dequeue();
    cout << codai << endl;

    codai.enqueue(5);
    cout << "Fine: " << endl << codai;

return 0;
}
