#include "GrafoNoDirigido.h"
template <class elemento>
    GrafoNoDirigido<elemento>::GrafoNoDirigido(){
        this->setPrimero(NULL);
        this->setArcos(0);
        this->setVertices(0);
    }
template <class elemento>
    GrafoNoDirigido<elemento>::GrafoNoDirigido(Grafo<elemento> g){
        cout<<"No esta listo"<<endl;
    }



template <class elemento>
    void GrafoNoDirigido<elemento>::agregarArco(elemento v, elemento w,float peso){
        NodoArco<elemento> *nuevo1 = new (NodoArco<elemento>), *nuevo2 = new(NodoArco<elemento>);
        NodoVertice<elemento> *vertice, *verticeInfo;
        bool estaVertice = false, estaVerticeInfo = false;
        vertice = this->getPrimero();
        verticeInfo = this->buscar(v);
        while ((vertice != NULL) && (!estaVerticeInfo)){
            if(vertice->getInfo() == w){
                estaVerticeInfo = true;
                verticeInfo = vertice;
            }
            vertice = vertice->getSiguiente();
        }
        if(!estaVerticeInfo){
            this->agregarVerticePrimero(w);
            verticeInfo = this->getPrimero();
        }
        vertice = this->getPrimero();
        while((vertice != NULL) && (!estaVertice)){
            if(vertice->getInfo() == v){
                estaVertice = true;
                if(!this->existeArco(vertice->getListaAdy(),w)){
                    nuevo1->setInfo(verticeInfo);
                    nuevo1->setPeso(peso);
                    nuevo1->setSiguiente(vertice->getListaAdy());
                    vertice->setListaAdy(nuevo1);
                    vertice->setGrado(vertice->getGrado() + 1);

                    nuevo2->setInfo(vertice);
                    nuevo2->setPeso(peso);
                    nuevo2->setSiguiente(verticeInfo->getListaAdy());
                    verticeInfo->setListaAdy(nuevo2);
                    verticeInfo->setGrado(verticeInfo->getGrado() + 1);
                }
            }
            vertice = vertice->getSiguiente();
        }
        if(!estaVertice){
            this->agregarVerticePrimero(v);
            vertice = this->getPrimero();
            if(!this->existeArco(vertice->getListaAdy(),w)){
                nuevo1->setInfo(verticeInfo);
                nuevo1->setPeso(peso);
                nuevo1->setSiguiente(vertice->getListaAdy());
                vertice->setListaAdy(nuevo1);
                vertice->setGrado(vertice->getGrado() + 1);

                nuevo2->setInfo(vertice);
                nuevo2->setPeso(peso);
                nuevo2->setSiguiente(verticeInfo->getListaAdy());
                verticeInfo->setListaAdy(nuevo2);
                verticeInfo->setGrado(verticeInfo->getGrado() + 1);
            }
        }
        this->setArcos(this->getArcos() + 1);
    }



template <class elemento>
    void GrafoNoDirigido<elemento>::eliminarArco(elemento v, elemento w){
        NodoArco<elemento> *arco;
        NodoVertice<elemento> *vertice;
        bool esta = false;
        vertice = this->getPrimero();
        while((vertice != NULL) && (!esta)){
            if(vertice->getInfo() == v){
                esta = true;
                arco = vertice->getListaAdy();
                this->eliminarElementoArco(vertice,arco,w);
            }
            vertice = vertice->getSiguiente();
        }
        esta = false;
        vertice = this->getPrimero();
        while((vertice != NULL) && (!esta)){
            if(vertice->getInfo() == w){
                esta = true;
                arco = vertice->getListaAdy();
                this->eliminarElementoArco(vertice,arco,v);
            }
            vertice = vertice->getSiguiente();
        }
        this->setArcos(this->getArcos() + 1); //como se eliminanado dos arcos le sumo 1 para balancearlo
    }


template <class elemento>
    void GrafoNoDirigido<elemento>::modificarPesoArco(elemento v, elemento w, float peso){
        NodoArco<elemento> *arco;
        NodoVertice<elemento> *vertice;
        bool estaVertice = false, estaArco = false;
        vertice = this->getPrimero();
        while((vertice != NULL) && (!estaVertice)){
            if(vertice->getInfo() == v){
                estaVertice = true;
                arco = vertice->getListaAdy();
                while((arco != NULL) && (!estaArco)){
                    if(arco->getInfo()->getInfo() == w){
                        estaArco = true;
                        arco->setPeso(peso);
                    }
                    arco = arco->getSiguiente();
                }
            }
            vertice = vertice->getSiguiente();
        }
        estaVertice = false, estaArco = false;
        vertice = this->getPrimero();
        while((vertice != NULL) && (!estaVertice)){
            if(vertice->getInfo() == w){
                estaVertice = true;
                arco = vertice->getListaAdy();
                while((arco != NULL) && (!estaArco)){
                    if(arco->getInfo()->getInfo() == v){
                        estaArco = true;
                        arco->setPeso(peso);
                    }
                    arco = arco->getSiguiente();
                }
            }
            vertice = vertice->getSiguiente();
        }
        
    }




template <class elemento>
    list<elemento> GrafoNoDirigido<elemento>::vecinos(elemento v){
        list<elemento> vecinos;
        NodoVertice<elemento> *vertice;
        NodoArco<elemento> *arco;
        bool band = false;
        vertice = this->getPrimero();
        while((vertice != NULL) && (!band)){
            if(vertice ->getInfo() == v){
                band = true;
                arco = vertice->getListaAdy();
                while(arco != NULL){
                    vecinos.push_back(arco->getInfo()->getInfo());
                    arco = arco->getSiguiente();
                }
            }
            vertice = vertice->getSiguiente();
        }
        return (vecinos);
    }


    

template<class elmento>
    void GrafoNoDirigido<elmento>::arcoMinimo(list<int> inicio, int &v, int &w,int &camin, float &peso, vector<bool> visitados, bool &band){
        int actual, act;
        list<int> vecinos;
        float pesoArco;
        bool prim = false;

        while(!inicio.empty()){
            actual = inicio.front();
            vecinos = this->vecinos(actual);
            while(!vecinos.empty()){
                act = vecinos.front();
                if (!visitados[act]){
                    pesoArco = this->getPesoArco(actual, act);
                    if((pesoArco < peso) || (!prim)){
                        peso = pesoArco;
                        v = actual;
                        w = act;
                        prim = true;
                        camin = w;
                    }
                }
                vecinos.pop_front();
            }
            inicio.pop_front();
        }
        if(!prim){
            band = true;
        }
    }  
template<class elemento>
float GrafoNoDirigido<elemento>::arbolExpandidoMinimoPeso(){
    vector<bool> visitados;
    bool fin, band=false;
    GrafoNoDirigido<int> g;
    vector<elemento> datos;
    list<int> inicio;
    float p,peso;
    int v,w,camin;
    for(int i=0;i<this->getVertices();i++){
        visitados.push_back(false);
    }

    this->mapear(g,datos);
    datos.clear();

    inicio.push_back(0);
    visitados[0] = true;
    fin = false;
    p = 0;
    peso = 0;
    while(!fin){
        g.arcoMinimo(inicio,v,w,camin,p,visitados,band);
        peso = peso + p;
        inicio.push_back(w);
        visitados[w] = true;
        fin = true;
        if(!band){
            for (int i = 0; i < g.getVertices(); i++){
                if(!visitados[i]){
                    fin = false;
                }
            }
        }else{
            peso = 0;
        }
    }
    return (peso);
}  
template<class elmento>
void GrafoNoDirigido<elmento>::arbolExpandidoMinimoCamino(list<int> &camino){
    vector<bool> visitados;
    bool fin, band=false;
    list<int> inicio;
    float p,peso;
    int v,w,camin;
    for(int i=0;i<this->getVertices();i++){
        visitados.push_back(false);
    }
    camino.push_back(0);
    inicio.push_back(0);
    visitados[0] = true;
    fin = false;
    p = 0;
    peso = 0;
    while(!fin){
        this->arcoMinimo(inicio,v,w,camin,p,visitados,band);
        peso = peso + p;
        inicio.push_back(w);
        visitados[w] = true;
        fin = true;
        if(!band){
            camino.push_back(camin);
            for (int i = 0; i< this->getVertices(); i++){
                if(!visitados[i]){
                    fin = false;
                }
            }
        }else{
            peso = 0;
        }
    }
}
template <class elemento>
    list<elemento> GrafoNoDirigido<elemento>::arbolExpandidoMinimoCamino(){
        list<elemento> result;
        list<int> camino;
        GrafoNoDirigido<int> g;
        vector<elemento> datos;
        this->mapear(g,datos);
        g.arbolExpandidoMinimoCamino(camino);
        result = this->desmapear(camino,datos);
        return (result);
    }




