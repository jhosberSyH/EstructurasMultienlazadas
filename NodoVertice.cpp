#include "NodoVertice.h"


template <class elemento>
    NodoVertice<elemento>::NodoVertice(){
        this->sig = NULL;
        this->listaAdy = NULL;
        this->grado = 0;
    }
template <class elemento>
    NodoVertice<elemento>::NodoVertice(elemento info){
        this->listaAdy = NULL;
        this->sig = NULL;
        this->info = info;
        this->grado = 0;
    }



template <class elemento>
    int NodoVertice<elemento>::getGrado(){
        return (this->grado);
    }
template <class elemento>
    NodoArco<elemento>* NodoVertice<elemento>::getListaAdy(){
        return (this->listaAdy);
    }
template <class elemento>
    elemento NodoVertice<elemento>::getInfo(){
        return (this->info);
    }
template <class elemento>
    NodoVertice<elemento>* NodoVertice<elemento>::getSiguiente(){
        return (this->sig);
    }



template <class elemento>
    void NodoVertice<elemento>::setGrado(int grado){
        this->grado = grado;
    }
template <class elemento>
    void NodoVertice<elemento>::setInfo(elemento info){
        this->info = info;
    }
template <class elemento>
    void NodoVertice<elemento>::setSiguiente(NodoVertice<elemento> *sig){
        this->sig = sig;
    }
template <class elemento>
    void NodoVertice<elemento>::setListaAdy(NodoArco<elemento> *lis){
        this->listaAdy = lis;
    }



template <class elemento>
    void NodoVertice<elemento>::destruir(){
        this->sig = NULL;
        this->listaAdy = NULL;
        this->grado = 0;
    }  