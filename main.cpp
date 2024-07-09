#include <iostream>
//#include "GrafoDirigido.cpp"
#include "GrafoNoDirigido.cpp"
int main(){
    GrafoNoDirigido<string> g;
    GrafoNoDirigido<int> g2;
    string nombre1,nombre2;
    list<int> camino;
    list<string> camino2;
    vector<string> ciudades;
    bool band = false;
    int k;
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
    return 0;
}
