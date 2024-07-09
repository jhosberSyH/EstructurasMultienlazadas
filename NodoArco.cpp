#include "NodoArco.h"


template <class elemento>
    NodoArco<elemento>::NodoArco(){
        this->info = NULL;
        this->sig = NULL;
        this->peso = 0;
    }
template <class elemento>
    NodoArco<elemento>::NodoArco(NodoVertice<elemento> *info){
        this->info = info;
        this->sig = NULL;
        this->peso = 0;
    }



template <class elemento>
    float NodoArco<elemento>::getPeso(){
        return (this->peso);
    }
template <class elemento>
    NodoVertice<elemento>* NodoArco<elemento>::getInfo(){
        return (this->info);
    }
template <class elemento>
    NodoArco<elemento>* NodoArco<elemento>::getSiguiente(){
        return (this->sig);
    }



template <class elemento>
    void NodoArco<elemento>::setInfo(NodoVertice<elemento> *info){
        this->info = info;
    }
template <class elemento>
    void NodoArco<elemento>::setSiguiente(NodoArco<elemento> *sig){
        this->sig = sig;
    }
template <class elemento>
    void NodoArco<elemento>::setPeso(float peso){
        this->peso = peso;
    }



template <class elemento>
    void NodoArco<elemento>::destruir(){
        this->peso = 0;
        this->sig = NULL;
        this->info = NULL;
    }           
