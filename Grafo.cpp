#include "Grafo.h"
template <class elemento>
    NodoVertice<elemento>* Grafo<elemento>::getPrimero(){
        return (this->primero);
    }
template <class elemento>
    void Grafo<elemento>::setPrimero(NodoVertice<elemento> *primero){
        this->primero = primero;
    }



template <class elemento>
    Grafo<elemento>::Grafo(){
        this->primero = NULL;
        this->nArcos = 0;
        this->nVertices = 0;
    }
template <class elemento>
    Grafo<elemento>::Grafo(NodoVertice<elemento> *primero){
        this->primero = primero;
        this->nArcos = 0;
        this->nVertices = 0;
    }



template <class elemento>
    int Grafo<elemento>::getGrafo(int pos){
        int i = 0;
        NodoVertice<elemento> *vertice;
        vertice = this->primero;
        while(i < pos){
            vertice = vertice->getSiguiente();
            i++;
        }
        return (vertice->getGrado());
    }
template <class elemento>
    elemento Grafo<elemento>::getInfo(){
        return (this->info);
    }
template <class elemento>
    int Grafo<elemento>::getVertices(){
        return (this->nVertices);
    }
template <class elemento>
    int Grafo<elemento>::getArcos(){
        return (this->nArcos);
    }
template <class elemento>
    float Grafo<elemento>::getPesoArco(elemento v, elemento w){
        bool bandArco = false,bandVertice = false;
        NodoVertice<elemento> *vertice;
        NodoArco<elemento> *arco;
        float result = -1;
        vertice = this->primero;
        while((vertice != NULL) && (!bandVertice)){
            if(vertice->getInfo() == v ){
                bandVertice = true;
                arco = vertice->getListaAdy();
                while((arco != NULL) && (!bandArco)){
                    if(arco->getInfo()->getInfo() == w){
                        bandArco = true;
                        result = arco->getPeso();
                    }
                    arco = arco->getSiguiente();
                }
            }
            vertice = vertice->getSiguiente();
        }
        return (result);
    }



template <class elemento>
    void Grafo<elemento>::setInfo(elemento info){
        this->info = info;
    }
template <class elemento>
    void Grafo<elemento>::setVertices(int nVertices){
        this->nVertices = nVertices; 
    }
template <class elemento>
    void Grafo<elemento>::setArcos(int nArcos){
        this->nArcos = nArcos;
    }



template <class elemento>
    void Grafo<elemento>::destruir(){
        this->destruirVertices(this->primero);
        this->primero = NULL;
    }
template <class elemento>
    void Grafo<elemento>::destruirVertices(NodoVertice<elemento> *vertice){
        NodoVertice<elemento> *actual;
        while(vertice != NULL){
            actual = vertice;
            this->destruirArcos(vertice->getListaAdy());
            vertice = vertice->getSiguiente();
            actual->destruir();
        }
        this->primero = NULL;
        this->nVertices = 0;
    }
template <class elemento>
    void Grafo<elemento>::destruirArcos(NodoArco<elemento> *arco){
        NodoArco<elemento> *actual;
        while(arco != NULL){
            actual = arco;
            arco = arco->getSiguiente();
            actual->destruir();
            this->nArcos = this->nArcos - 1;
        }
    }



template <class elemento>
    list<int> Grafo<elemento>::grados(){
        NodoVertice<elemento> *vertice;
        list<int> grados;
        vertice = this->primero;
        while(vertice != NULL){
            grados.push_back(vertice->getGrado());
            vertice = vertice->getSiguiente();
        }
        return (grados);
    }
template <class elemento>
    list<elemento> Grafo<elemento>::sucesores(elemento v){
        list<elemento> sucesores;
        NodoVertice<elemento> *vertice;
        NodoArco<elemento> *arco;
        bool band = false;
        vertice = this->primero;
        while((vertice != NULL) && (!band)){
            if(vertice ->getInfo() == v){
                band = true;
                arco = vertice->getListaAdy();
                while(arco != NULL){
                    sucesores.push_back(arco->getInfo()->getInfo());
                    arco = arco->getSiguiente();
                }
            }
            vertice = vertice->getSiguiente();
        }
        return (sucesores);
    }
template <class elemento>
    list<elemento> Grafo<elemento>::predecesores(elemento v){
        list<elemento> predecesores;
        NodoVertice<elemento> *vertice;
        NodoArco<elemento> *arco;
        bool band = false;
        vertice = this->primero;
        while(vertice != NULL){
            arco = vertice->getListaAdy();
            while((arco != NULL) && (!band)){
                if(arco->getInfo()->getInfo() == v){
                    band = true;
                    predecesores.push_back(vertice->getInfo());
                }
                arco = arco->getSiguiente();
            }
            vertice = vertice->getSiguiente();
        }
        return (predecesores);
    }
template <class elemento>
    list<elemento> Grafo<elemento>::vertices(){
        list<elemento> result;
        NodoVertice<elemento> *vertice;
        vertice = this->primero;
        while(vertice != NULL){
            result.push_back(vertice->getInfo());
            vertice = vertice->getSiguiente();
        }
        return (result);
    }



template <class elemento>
    bool Grafo<elemento>::esConexo(){
        queue<int> cola;
        list<int> sucesores;
        int v,w,i;
        vector<bool> visitados;
        bool result = true;
        for (i = 0; i < this->getVertices(); i++){
            visitados.push_back(false);
        }
        cola.push(0);
        visitados[0] = true;
        while(!cola.empty()){
            v = cola.front();
            sucesores = this->sucesores(v);
            while(!sucesores.empty()){
                w = sucesores.front();
                if(!visitados[w]){
                    visitados[w] = true;
                    cola.push(w);
                }
                sucesores.pop_front();
            }
            cola.pop();
        }
        i = 0;
        while((i < this->getVertices()) && (result)){
            if(!visitados[i]){
                result = false;
            }
            i++;
        }
        return (result);
    }
template<class elemento>
    bool Grafo<elemento>::existeArco(elemento v,elemento w){
        bool result = false,band = false;
        NodoVertice<elemento> *vertice;
        NodoArco<elemento> *arco;
        vertice = this->primero;
        while((vertice != NULL) && (!band)){
            if(vertice->getInfo() == v ){
                band = true;
                arco = vertice->getListaAdy();
                while((arco != NULL) && (!result)){
                    if(arco->getInfo()->getInfo() == w){
                        result = true;
                    }
                    arco = arco->getSiguiente();
                }
            }
            vertice = vertice->getSiguiente();
        }
        return (result);
    }
template <class elemento>
    bool Grafo<elemento>::existeVertice(elemento v){
        bool result = false;
        NodoVertice<elemento> *vertice;
        vertice = this->primero;
        while((vertice != NULL) && (!result)){
            if(vertice->getInfo() == v ){
                result = true;
            }
            vertice = vertice->getSiguiente();
        }
        return (result);
    }
template <class elemento>
    bool Grafo<elemento>::existeArco(NodoArco<elemento> *arco,elemento w){
        bool result = false;
        while((arco != NULL) && (!result)){
            if(arco->getInfo()->getInfo() == w){
                result = true;
            }
            arco = arco->getSiguiente();;
        }
        return (result);
    }



template <class elemento>
    void Grafo<elemento>::agregarVertice(elemento v){
        bool esta = false;
        esta = this->existeVertice(v); 
        if(!esta){
            this->agregarVerticePrimero(v);
        }
    }
template <class elemento>
    void Grafo<elemento>::agregarVerticePrimero(elemento v){
        NodoVertice<elemento> *nuevo = new NodoVertice<elemento>(v);
        nuevo->setSiguiente(this->primero);
        this->primero = nuevo;
        this->nVertices = this->nVertices + 1;
        
    }



template <class elemento>
    void Grafo<elemento>::eliminarElementoArco(NodoVertice<elemento> *vertice,NodoArco<elemento> *arco, elemento v){
        NodoArco<elemento> *anterior, *actual;
        bool band = false;
        if(arco != NULL){
            if(arco->getInfo()->getInfo() == v ){
                band = true;
                anterior = arco;
                vertice->setListaAdy(anterior->getSiguiente());
            }else{
                actual = arco;
                anterior = NULL;
                while((actual != NULL) && (!band)){
                    if(actual->getInfo()->getInfo() == v){
                        band = true;
                        anterior->setSiguiente(actual->getSiguiente());
                    }
                    anterior = actual;
                    actual = actual->getSiguiente();
                }
            }
            if(band){
                anterior->destruir();
                delete anterior;
                this->nArcos = this->nArcos - 1;
                vertice->setGrado(vertice->getGrado - 1);
            }

        }
    }
template <class elemento>
    void Grafo<elemento>::eliminarVertice(elemento v){
        NodoVertice<elemento> *vertice, *anterior;
        NodoArco<elemento> *arco;
        bool band = false;
        if(this->primero != NULL){
            vertice = this->primero;
            if(this->primero->getInfo() == v){
                band = true;
                anterior = vertice;
                vertice = vertice->getSiguiente();
                this->destruirArcos(this->primero->getListaAdy());
                this->primero = vertice;
            }else{
                anterior = NULL;
                while(vertice != NULL){
                    if(vertice->getInfo() == v ){
                        band = true;
                        this->destruirArcos(vertice->getListaAdy());
                        anterior->setSiguiente(vertice->getSiguiente());
                    }else{
                        arco = vertice->getListaAdy();
                        this->eliminarElementoArco(vertice,arco,v);  
                    }
                    anterior = vertice;
                    vertice = vertice->getSiguiente();
                }
                
            }
            if(band){
                anterior->destruir();
                anterior = NULL;
                this->nVertices = this->nVertices -1;
            }
        }
    }




template <class elemento>
    NodoVertice<elemento>* Grafo<elemento>::buscar(elemento v){
        NodoVertice<elemento> *result = NULL, *vertice;
        bool esta = false;
        vertice = this->primero;
        while((vertice != NULL) && (!esta)){
            if(vertice->getInfo() == v){
                result = vertice;
                esta = true;
            }
            vertice = vertice->getSiguiente();
        }
        return (result);
    }



template <class elemento>
    list<int> Grafo<elemento>::bfs(){
        queue<int> cola;
        list<int> result,sucesores;
        int v,w;
        vector<bool> visitados;
        for (int i = 0; i < this->getVertices(); i++){
            visitados.push_back(false);
        }
        cola.push(0);
        visitados[0] = true;
        while(!cola.empty()){
            v = cola.front();
            sucesores = this->sucesores(v);
            while(!sucesores.empty()){
                w = sucesores.front();
                if(!visitados[w]){
                    visitados[w] = true;
                    cola.push(w);
                }
                sucesores.pop_front();
            }
            result.push_back(v);
            cola.pop();
        }
        return (result);
    }
template <class elemento>
    void Grafo<elemento>::dfs(int v,list<int> &result,vector<bool> &visitados){
        list<int> sucesores;
        int w;
        result.push_back(v);
        visitados[v] = true;
        sucesores = this->sucesores(v);
        while(!sucesores.empty()){
            w = sucesores.front();
            if(!visitados[w]){
                this->dfs(w,result,visitados);
            }
            sucesores.pop_front();
        }

    }
template <class elemento>
    list<int> Grafo<elemento>::dfs(){
        vector<bool> visitados;
        list<int> result;
        int v = 0;
        for(int i = 0; i < this->getVertices(); i++){
            visitados.push_back(false);
        }
        this->dfs(v,result,visitados);
        return (result);
    }



template <class elemento>
    void Grafo<elemento>::agregarArquito(elemento v, elemento w,float peso){
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
    void Grafo<elemento>::mapear(Grafo<int> &g,vector<elemento> &elementos){
        NodoVertice<elemento> *vertice;
        NodoArco<elemento> *arco;
        list<int> subArcos;
        int v = 0, w; 
        vertice = this->getPrimero();
        while(vertice != NULL){
            elementos.push_back(vertice->getInfo());
            g.agregarVertice(v);
            vertice = vertice->getSiguiente();
            v++;
        }
        v = 0;
        vertice = this->getPrimero();
        while(vertice != NULL){
            arco = vertice->getListaAdy();
            while(arco != NULL){
                auto it = find(elementos.begin(),elementos.end(),arco->getInfo()->getInfo());
                w = distance(elementos.begin(),it);
                g.agregarArquito(v,w,arco->getPeso());
                arco = arco->getSiguiente();
            }
            vertice = vertice->getSiguiente();
            v++;
        }
    }



template <class elemento>
    void Grafo<elemento>::imprimir() {
        NodoVertice<elemento> *vertice;
        NodoArco<elemento> *arco;
        vertice = this->primero;
        while(vertice != NULL){
            cout<<"Lista de adyacencia del vertice "<<vertice->getInfo()<<"con Grado: "<<vertice->getGrado()<<"\n";
            arco = vertice->getListaAdy();
            while (arco != NULL){
                cout<<"-> "<<arco->getInfo()->getInfo();
                arco = arco->getSiguiente();
            }
            cout<<endl<<endl;
            vertice = vertice->getSiguiente();
        }
    }


template <class elemento>
list<elemento> Grafo<elemento>::desmapear(list<int> elementos,vector<elemento> mapeados){
    list<elemento> result;
    while (!elementos.empty()){
        result.push_back(mapeados[elementos.front()]);
        elementos.pop_front();
    }
    return(result);
}


template <class elemento>
    void Grafo<elemento>::caminoMasCaro(int v,float &costo,float peso,list<int> &result,list<int> camino,vector<bool> &visitados){
        list<int> sucesores;
        int w;

        sucesores = this->sucesores(v);
        while(!sucesores.empty()){
            w = sucesores.front();
            if(!visitados[w]){
                //procesar datos
                visitados[w] = true;
                peso += this->getPesoArco(v,w);
                camino.push_back(w);
                //fin de procesar datos
                if(camino.size() == visitados.size()){
                    if(peso > costo){
                        result = camino;
                        costo = peso;
                    }
                }else{
                    this->caminoMasCaro(w,costo,peso,result,camino,visitados);
                }
                //eliminar datos
                visitados[w] = false;
                peso -= this->getPesoArco(v,w);
                camino.pop_back();
                //fin de eliminar datos
            }
            sucesores.pop_front();
        }
    }
template <class elemento>
    list<elemento> Grafo<elemento>::caminoMasCaro(){
        int v = 0;
        Grafo<int> g;
        float costo = -1,peso = 0;
        vector<bool> visitados;
        list<int> camino,mejorCamino;
        list<elemento> result;
        vector<elemento> datos;

        this->mapear(g,datos);

        for(int i = 0;i < this->getVertices(); i++){
            visitados.push_back(false);
        }

        visitados[v] = true;
        camino.push_back(v);
        g.caminoMasCaro(v,costo,peso,mejorCamino,camino,visitados);

        result = this->desmapear(mejorCamino,datos);

        return (result);
    }




template <class elemento>
    void Grafo<elemento>::hamitoniano(int v,int vf,float &costo,float peso,list<int> &result,list<int> camino,vector<bool> &visitados){
        list<int> sucesores;
        int w;

        sucesores = this->sucesores(v);
        while(!sucesores.empty()){
            w = sucesores.front();
            if(!visitados[w]){
                //procesar datos
                visitados[w] = true;
                peso += this->getPesoArco(v,w);
                camino.push_back(w);
                //fin de procesar datos
                if((w == vf) && (camino.size() == visitados.size())){
                    if(peso < costo){
                        result = camino;
                        costo = peso;
                    }
                }else{
                    this->hamitoniano(w,vf,costo,peso,result,camino,visitados);
                }
                //eliminar datos
                visitados[w] = false;
                peso -= this->getPesoArco(v,w);
                camino.pop_back();
                //fin de eliminar datos
            }
            sucesores.pop_front();
        }
    }
template <class elemento>
    list<elemento> Grafo<elemento>::hamitoniano(int vf){
        int v = 0;
        Grafo<int> g;
        float costo = 100000 ,peso = 0;
        vector<bool> visitados;
        list<int> camino,mejorCamino;
        list<elemento> result;
        vector<elemento> datos;

        this->mapear(g,datos);

        for(int i = 0;i < this->getVertices(); i++){
            visitados.push_back(false);
        }

        visitados[v] = true;
        camino.push_back(v);
        g.hamitoniano(v,vf,costo,peso,mejorCamino,camino,visitados);

        result = this->desmapear(mejorCamino,datos);

        return (result);
    }



template <class elemento>
    void Grafo<elemento>::dijkstra(int inicio,int fin,list<int> &camino,float &pesoFinal) {
        list<int> sucesores;
        queue<int> cola;
        vector<int> anteriores;
        vector<float> distancia;
        int v,w;
        float peso;
        for(int i = 0; i < this->getVertices();i++){
            distancia.push_back(9999999);
            anteriores.push_back(-1);
        }
        cola.push(inicio);
        distancia[inicio] = 0;
        while (!cola.empty()) {
            v = cola.front();
            sucesores = this->sucesores(v);
            while(!sucesores.empty()){
                w = sucesores.front();
                peso = this->getPesoArco(v,w);
                if (distancia[v] + peso < distancia[w]) {
                    distancia[w] = distancia[v] + peso;
                    anteriores[w] = v;
                    cola.push(w);
                }
                sucesores.pop_front();
            }
            cola.pop();
        }
        pesoFinal = distancia[fin];
        if( anteriores[fin] != -1){
            camino.push_back(fin);
            v = fin;
            while((v != inicio) && (v != -1)){
                v = anteriores[v];
                camino.push_front(v);
            }
        }
    }
template <class elemento>
    list<elemento> Grafo<elemento>::dijkstra(elemento inicio,elemento fin){
        int v = 0,w = 0;
        Grafo<int> g;
        list<int> camino;
        list<elemento> result;
        vector<elemento> datos;
        float peso = 0;

        this->mapear(g,datos);

        auto it = find(datos.begin(),datos.end(),inicio);
        v = distance(datos.begin(),it);
        it = find(datos.begin(),datos.end(),fin);
        w = distance(datos.begin(),it);
        
        g.dijkstra(v,w,camino,peso);

        result = this->desmapear(camino,datos);
        cout<<peso<<endl;
        return (result);
    }





template <class elemento>
    void Grafo<elemento>::obstaculos(int inicio,int fin,list<int> &camino,float &pesoFinal,vector<bool> restrincion) {
        list<int> sucesores;
        queue<int> cola;
        vector<int> anteriores;
        vector<float> distancia;
        int v,w;
        float peso;
        for(int i = 0; i < this->getVertices();i++){
            distancia.push_back(9999999);
            anteriores.push_back(-1);
        }
        cola.push(inicio);
        distancia[inicio] = 0;
        while (!cola.empty()) {
            v = cola.front();
            sucesores = this->sucesores(v);
            while(!sucesores.empty()){
                w = sucesores.front();
                if(!restrincion[w]){
                    peso = this->getPesoArco(v,w);
                    if (distancia[v] + peso < distancia[w]) {
                        distancia[w] = distancia[v] + peso;
                        anteriores[w] = v;
                        cola.push(w);
                    }
                }
                sucesores.pop_front();
            }
            cola.pop();
        }
        pesoFinal = distancia[fin];
        if( anteriores[fin] != -1){
            camino.push_back(fin);
            v = fin;
            while((v != inicio) && (v != -1)){
                v = anteriores[v];
                camino.push_front(v);
            }
        }
    }
template <class elemento>
    list<elemento> Grafo<elemento>::caminoObstaculos(elemento inicio,elemento fin,list<elemento> obstaculos){
        int v = 0,w = 0;
        Grafo<int> g;
        vector<bool> restrinciones;
        list<int> camino;
        list<elemento> result;
        vector<elemento> datos;
        float peso = 0;
        for(int i = 0;i < this->getVertices(); i++){
            restrinciones.push_back(false);
        }

        this->mapear(g,datos);
        
        auto it = find(datos.begin(),datos.end(),inicio);
        v = distance(datos.begin(),it);
        it = find(datos.begin(),datos.end(),fin);
        w = distance(datos.begin(),it);

        while(!obstaculos.empty()){
            it = find(datos.begin(),datos.end(),obstaculos.front());
            restrinciones[distance(datos.begin(),it)] = true;
            obstaculos.pop_front();
        }
        
        g.dijkstra(v,w,camino,peso);

        result = this->desmapear(camino,datos);
        cout<<peso<<endl;
        return (result);
    }