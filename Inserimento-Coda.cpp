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
            out<< iter->valore <<" ";
        if(iter)
            out<< iter->valore << " ";

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

    string tipo, tmp;
    int n;

    for(int task=0; task<100; task++){
        in >> tipo;
        in >> n;

        if(tipo == "double"){
            Coda<double> codad;
            for(int i=0; i<n; i++){
                in >> tmp;
                codad.enqueue(stod(tmp));
            }
            out << codad << endl;
        }
        else if(tipo == "int"){
            Coda<int> codai;
            for(int i=0; i<n; i++){
                in >> tmp;
                codai.enqueue(stoi(tmp));
            }
            out << codai << endl;
        }
        else if(tipo == "char"){
            Coda<char> codac;
            for(int i=0; i<n; i++){
                in >> tmp;
                codac.enqueue(tmp[0]);
            }
            out << codac << endl;
        }
        else {
            Coda<bool> codab;
            for(int i=0; i<n; i++){
                in >> tmp;
                codab.enqueue(stoi(tmp));
            }
            out << codab << endl;
        }
    }

return 0;
}
