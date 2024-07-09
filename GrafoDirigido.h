#ifndef GrafoDirigido_h
#define GrafoDirigido_h
#include "Grafo.cpp"

template<class elemento>

class GrafoDirigido : public Grafo<elemento>{
    public:
        GrafoDirigido();
        GrafoDirigido(Grafo<elemento> g);
        void agregarArco(elemento v, elemento w,float peso);
        void eliminarArco(elemento v, elemento w);
        void modificarPesoArco(elemento v, elemento w, float peso);
        
};

#endif 