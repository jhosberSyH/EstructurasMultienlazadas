#ifndef NodoVertice_h
#define NodoVertice_h
#include <iostream>
template<class elemento>
class NodoArco;
template <class elemento>
class NodoVertice{
    private:
        elemento info;
        int grado;
        NodoVertice<elemento> *sig;
        NodoArco<elemento> *listaAdy;

    public:
        NodoVertice();
        NodoVertice(elemento info);
        elemento getInfo();
        int getGrado();
        NodoVertice<elemento>* getSiguiente();
        NodoArco<elemento>* getListaAdy();
        void setGrado(int grado);
        void setInfo(elemento info);
        void setSiguiente(NodoVertice<elemento> *sig);
        void setListaAdy(NodoArco<elemento> *lis);
        void destruir();
};

#endif 