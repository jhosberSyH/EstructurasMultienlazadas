#ifndef Grafo_h
#define Grafo_h
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
#include "NodoArco.cpp"
#include "NodoVertice.cpp"
using namespace std;
template<class elemento>

class Grafo{
    private:
        NodoVertice<elemento> *primero;
        int nVertices,nArcos;

    protected:
        void setPrimero(NodoVertice<elemento> *primero); //testeada
        NodoVertice<elemento>* getPrimero(); //testeada
        void eliminarElementoArco(NodoVertice<elemento> *vertice,NodoArco<elemento> *arco, elemento v); //testeada
        NodoVertice<elemento>* buscar(elemento v); //testeada
        void destruirVertices(NodoVertice<elemento> *vertice); //testeada
        void destruirArcos(NodoArco<elemento> *arco); //testeada
        void dfs(int v,list<int> &result,vector<bool> &visitados);
        bool existeArco(NodoArco<elemento> *arco,elemento w);

    public:
        Grafo(); //testeada
        Grafo(NodoVertice<elemento> *primero);
        elemento getInfo(); //testeada
        void setInfo(elemento info); //testeada
        int getVertices();
        int getArcos();
        int getGrafo(int pos);
        float getPesoArco(elemento v, elemento w);
        void setVertices(int nVertices);
        void setArcos(int nArcos);
        void destruir(); //testeada
        list<int> grados();
        list<elemento> sucesores(elemento v); //testeada
        list<elemento> predecesores(elemento v);
        list<elemento> vertices(); //testeada
        list<int> dfs();
        list<int> bfs();
        bool existeArco(elemento v,elemento w);
        bool esConexo();
        bool existeVertice(elemento v); //testeada
        void agregarVertice(elemento v); //testeada
        void agregarVerticePrimero(elemento v); //testeada
        void eliminarVertice(elemento v); //testeada
        void agregarArquito(elemento v, elemento w,float peso);
        void mapear(Grafo<int> &g,vector<elemento> &elementos);
        void imprimir();
        list<elemento> desmapear(list<int> elementos,vector<elemento> mapeados);
        void caminoMasCaro(int v,float &costo,float peso,list<int> &result,list<int> camino,vector<bool> &visitados);
        list<elemento> caminoMasCaro();
        void hamitoniano(int v,int vf,float &costo,float peso,list<int> &result,list<int> camino,vector<bool> &visitados);
        list<elemento> hamitoniano(int vf);

        

};

#endif 