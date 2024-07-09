#ifndef NodoArco_h
#define NodoArco_h
#include "NodoVertice.h"
template<class elemento>

class NodoArco{
    private:
        float peso;
        NodoVertice<elemento> *info;
        NodoArco<elemento> *sig;

    public:
        NodoArco();
        NodoArco(NodoVertice<elemento> *info);
        NodoVertice<elemento>* getInfo();
        NodoArco<elemento>* getSiguiente();
        float getPeso();
        void setInfo(NodoVertice<elemento> *info);
        void setSiguiente(NodoArco<elemento> *sig);
        void setPeso(float peso);
        void destruir();
};

#endif 