#include "GrafoDirigido.h"
template <class elemento>
    GrafoDirigido<elemento>::GrafoDirigido(){
        this->setPrimero(NULL);
        this->setArcos(0);
        this->setVertices(0);
    }
template <class elemento>
    GrafoDirigido<elemento>::GrafoDirigido(Grafo<elemento> g){
        cout<<"No esta listo"<<endl;
    }



template <class elemento>
    void GrafoDirigido<elemento>::agregarArco(elemento v, elemento w,float peso){
        NodoArco<elemento> *nuevo = new (NodoArco<elemento>);
        NodoVertice<elemento> *vertice, *verticeInfo;
        bool estaVertice = false, estaVerticeInfo = false;
        vertice = this->getPrimero();
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
                nuevo->setInfo(verticeInfo);
                nuevo->setPeso(peso);
                nuevo->setSiguiente(vertice->getListaAdy());
                vertice->setListaAdy(nuevo);
                vertice->setGrado(vertice->getGrado() + 1);
            }
            vertice = vertice->getSiguiente();
        }
        if(!estaVertice){
            this->agregarVerticePrimero(v);
            vertice = this->getPrimero();
            nuevo->setInfo(verticeInfo);
            nuevo->setPeso(peso);
            nuevo->setSiguiente(vertice->getListaAdy());
            vertice->setListaAdy(nuevo);
            vertice->setGrado(vertice->getGrado() + 1);
        }
        this->setArcos(this->getArcos() + 1);
    }



template <class elemento>
    void GrafoDirigido<elemento>::eliminarArco(elemento v, elemento w){
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
    }


template <class elemento>
    void GrafoDirigido<elemento>::modificarPesoArco(elemento v, elemento w, float peso){
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
    }




