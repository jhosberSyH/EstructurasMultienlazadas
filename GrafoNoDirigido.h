#ifndef GrafoNoDirigido_h
#define GrafoNoDirigido_h
#include "Grafo.cpp"

template<class elemento>
class GrafoNoDirigido : public Grafo<elemento>{
    public:
        GrafoNoDirigido();
        GrafoNoDirigido(Grafo<elemento> g);
        list<elemento> vecinos(elemento v);
        void agregarArco(elemento v, elemento w,float peso); //testeada
        void eliminarArco(elemento v, elemento w); //testeada
        void modificarPesoArco(elemento v, elemento w, float peso);
        void arcoMinimo(list<int> inicio, int &v, int &w,int &camin, float &peso, vector<bool> visitados, bool &band);
        float arbolExpandidoMinimoPeso();
        void arbolExpandidoMinimoCamino(list<int> &camino);
        list<elemento> arbolExpandidoMinimoCamino();
        bool esMulticoloreable(int nColores);
        void esMulticoloreable(int inicio, int nColoresGrafo,bool &resultado);
};

#endif 