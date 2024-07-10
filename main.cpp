#include <iostream>
//#include "GrafoDirigido.cpp"
#include "GrafoNoDirigido.cpp"
int main(){
    GrafoNoDirigido<string> g;
    GrafoNoDirigido<int> g2;
    string nombre1,nombre2;
    list<int> camino;
    list<string> camino2,retrinciones;
    vector<string> ciudades;
    bool band = false;
    int k,n;
    float peso;
    cin>>k;
    while(!cin.eof()){
        cin>>nombre1;
        g.agregarVertice(nombre1);
        cin>>nombre2;
        g.agregarVertice(nombre2);
        cin>>peso;
        g.agregarArco(nombre1,nombre2,peso);
    }
    g.imprimir();
    camino2 = g.caminoMasCaro();
    cout<<"camino: ";
    while(!camino2.empty()){
        cout<<camino2.front()<<" ";
        camino2.pop_front();
    }
    cout<<endl;
    camino2 = g.arbolExpandidoMinimoCamino();
    cout<<"camino Arbol expancion Minima con peso "<<g.arbolExpandidoMinimoPeso()<<": ";
    while(!camino2.empty()){
        cout<<camino2.front()<<" ";
        camino2.pop_front();
    }
    cout<<endl;
    camino2 = g.hamitoniano(6);
    cout<<"Hamitoniano: ";
    while(!camino2.empty()){
        cout<<camino2.front()<<" ";
        camino2.pop_front();
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Dijkstra:"<<endl;
    //camino2 = g.dijkstra("Washington","Frankfurt");
    cout<<"camino dijkstra: ";
    while(!camino2.empty()){
        cout<<camino2.front()<<" ";
        camino2.pop_front();
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"camino con obstaculos"<<endl;
    retrinciones.push_back("Washington");
    retrinciones.push_back("Dallas");
    //camino2 = g.caminoObstaculos("Caracas","Oregon",retrinciones);
    while(!camino2.empty()){
        cout<<camino2.front()<<" ";
        camino2.pop_front();
    }
    cout<<endl;
    n = 2; //cantidad de colores;
    if (g.esMulticoloreable(n) ){
        cout<<"si se puede colorear con "<<n<<" colores el grafo"<<endl;
    }else{
        cout<<"no se puede colorear con "<<n<<" colores el grafo"<<endl;
    }
    return 0;
}
