/********************************************
*											*
*	Nombre: Dijkstra's Shortest Path		*
*	Autor:	Francisco Manuel Valle Ruiz		*
*	Fecha:	Abril 2013						*
*											*
*********************************************/

#ifndef GRAFICA_H
#define GRAFICA_H
using namespace std;

struct Arco;
struct Nodo;
struct NodoRuta;
class Lista_arcos;
class Lista_nodos;
class Lista_ruta;

struct Arco{
    int longitud;
    Arco* siguiente;
    Nodo* nodo_apuntado;
};

struct Nodo{
    int num_nodo;
    Nodo* siguiente;
    Lista_arcos *salientes;
    int bandera;
    int ruta_corta;
    Nodo *antecesor;
    NodoRuta *direccion_en_lista_ruta;
};

struct NodoRuta{
    int ruta_corta;
    Nodo *direccion;
    NodoRuta *siguiente;
};


//////////////////////////////////////
//                                  //
//                                  //
//                                  //
//                                  //
//       Comienza Lista_arcos       //
//                                  //
//                                  //
//                                  //
//                                  //
//////////////////////////////////////

class Lista_arcos{
    Arco *principio; // Primer elemento de la lista
    Arco *anterior;  // Para la funcion buscar
    Arco *visitando; // Para la funcion dijkstra
    int cuantos;
    bool encontrado;
    enum donde_enum{VACIO, PRINCIPIO, ENMEDIO, FINAL};
    donde_enum donde;
public:
    Lista_arcos();
    ~Lista_arcos(); // ~: alt 126
    bool buscar(int a);
    bool agregar(Nodo* n, int l);
    bool borrar(int a);
    void pintar();
     int pop();         // Not needed
     int get_cuantos(); // Not needed

    void iniciar_recorrido();
    Arco* recorrer();
    void nuevo();
    void limpiar();

    friend Lista_nodos;
};

void Lista_arcos::nuevo(){
    principio = NULL;
    anterior = NULL;
    visitando = NULL;
    cuantos = 0;
    encontrado = false;
    donde = VACIO;
}

void Lista_arcos::limpiar(){
    Arco *p, *q;
    p = principio;
    while(p){
        q = p;
        p = p -> siguiente;
        delete q;
    }
    visitando = NULL;
    cuantos = 0;
}

Lista_arcos::Lista_arcos(){
    nuevo();
}

Lista_arcos::~Lista_arcos(){
    limpiar();
}


bool Lista_arcos::buscar(int a){
    Arco *p;
    p = principio;
    if (!p){
        donde = VACIO;
        return false;
    }

    while (p){
        if (p -> nodo_apuntado -> num_nodo == a){
            if(p == principio){
                donde = PRINCIPIO;
            }else{
                donde = ENMEDIO;
            }
            return true;
        }else if (p -> nodo_apuntado -> num_nodo > a){
            if(p == principio){
                donde = PRINCIPIO;
            }else{
                donde = ENMEDIO;
            }
            return false;
        }else{
            anterior = p;
            p = p -> siguiente;
        }
    }
    donde = FINAL;
    return false;
}

bool Lista_arcos::agregar(Nodo* n, int l){
    Arco *p;
    if (buscar(n -> num_nodo))
        return false;

    p = new Arco;
    p -> nodo_apuntado = n;
    p -> longitud = l;

    if (donde == VACIO){
        p -> siguiente = NULL;
        principio = p;
    }else if (donde == PRINCIPIO){
        p -> siguiente = principio;
        principio = p;
    }else{
        p -> siguiente = anterior -> siguiente;
        anterior -> siguiente = p;
    }
    cuantos++;
    return true;
}

void Lista_arcos::pintar(){
    Arco *p;
    p = principio;
    if(p){ // Imprimir primer elemento (sin coma antes)
        cout << "[" << p -> nodo_apuntado -> num_nodo << "]";
        p = (p -> siguiente);
    }
    while (p){ // Imprimir elementos restantes (con comas antes)
        cout << ", [" << p -> nodo_apuntado -> num_nodo << "]";
        p = (p -> siguiente);
    }
    cout<<"\n";
}

bool Lista_arcos::borrar(int a){
    Arco *p;

    if (buscar(a))
        return false;

    if (donde == PRINCIPIO){
        p = principio;
        principio = p -> siguiente;
    }else if (donde == ENMEDIO){

        p = anterior -> siguiente;
        anterior -> siguiente = p -> siguiente;
    }else{
        p = anterior -> siguiente;
        anterior -> siguiente = NULL;
    }

    delete p;
    cuantos --;
    return true;
}

int Lista_arcos::pop(){
    int num_nodo;
    num_nodo = principio -> nodo_apuntado -> num_nodo;

    principio = principio -> siguiente;
    cuantos --;
    return num_nodo;
}

int Lista_arcos::get_cuantos(){
    return cuantos;
}

void Lista_arcos::iniciar_recorrido(){
    visitando = principio;
}

Arco* Lista_arcos::recorrer(){
    Arco *a = visitando;
    if(!a) return NULL;

    visitando = (visitando -> siguiente);
    return a;
}


//////////////////////////////////////
//                                  //
//                                  //
//                                  //
//                                  //
//      Comienza Lista_nodos        //
//                                  //
//                                  //
//                                  //
//                                  //
//////////////////////////////////////

class Lista_nodos{
    Nodo *principio, *anterior;
    int cuantos;
    bool encontrado;
    enum donde_enum{VACIO, PRINCIPIO, ENMEDIO, FINAL};
    donde_enum donde;
public:
    Lista_nodos();
    ~Lista_nodos(); // ~: alt 126
    Nodo* buscar(int a);
    bool agregar(int a);
    bool borrar(int a);
    int pop();
    int get_cuantos();

    void nuevo();
    void limpiar();
    void pintar_nodos();
    void pintar_arcos();
    void pintar_todo();
};

void Lista_nodos::nuevo(){
    principio = NULL;
    anterior = NULL;
    cuantos = 0;
    donde = VACIO;
}

void Lista_nodos::limpiar(){
    Nodo *p, *q;
    p = principio;
    while(p){
        q = p;
        p = p -> siguiente;
        delete q;
    }
    cuantos = 0;
}

Lista_nodos::Lista_nodos(){
    nuevo();
}

Lista_nodos::~Lista_nodos(){
    limpiar();
}


Nodo* Lista_nodos::buscar(int a){
    Nodo *p;
    p = principio;
    if (!p){
        donde = VACIO;
        return NULL;
    }

    while (p){
        if (p -> num_nodo == a){
            if(p == principio){
                donde = PRINCIPIO;
            }else{
                donde = ENMEDIO;
            }
            return p;
        }else if (p -> num_nodo > a){
            if(p == principio){
                donde = PRINCIPIO;
            }else{
                donde = ENMEDIO;
            }
            return NULL;
        }else{
            anterior = p;
            p = p -> siguiente;
        }
    }
    donde = FINAL;
    return NULL;
}

bool Lista_nodos::agregar(int a){
    Nodo *n;
    if (buscar(a))
        return false;

    n = new Nodo;
    n -> num_nodo = a;

    if (donde == VACIO){
        n -> siguiente = NULL;
        principio = n;
    }else if (donde == PRINCIPIO){
        n -> siguiente = principio;
        principio = n;
    }else{
        n -> siguiente = anterior -> siguiente;
        anterior -> siguiente = n;
    }
    (n -> salientes) = new Lista_arcos;
    (n -> salientes) -> nuevo();

    cuantos++;
    return true;
}

void Lista_nodos::pintar_nodos(){
    Nodo *n;
    n = principio;
    if(n){ // Imprimir primer elemento (sin coma antes)
        cout << "[" << n -> num_nodo << "]";
        n = (n -> siguiente);
    }
    while (n){ // Imprimir elementos restantes (con comas antes)
        cout << ", [" << n -> num_nodo << "]";
        n = (n -> siguiente);
    }
    cout<<"\n";
}

void Lista_nodos::pintar_arcos(){
    Nodo *n;
    n = principio;

    if(!n){
        cout << "No hay ningun nodo!" ;
        return;
    }

    Arco *arco;
    while (n){
        arco = (n -> salientes) -> principio;

        while(arco){
            cout << "\t[" << (n -> num_nodo) << "]";
            cout << " ----" << (arco -> longitud) << "---->";
            cout << " [" << (arco -> nodo_apuntado -> num_nodo) << "]\n";
            arco = (arco -> siguiente);
        }
        n = n -> siguiente;
    }
}

void Lista_nodos::pintar_todo(){
Nodo *n;
    n = principio;
    if(!n){
        cout << "No hay ningun nodo!" ;
        return;
    }

    while (n){
        cout << "[" << (n -> num_nodo) << "]:\n ";
        cout << "   --> "; // Imprimir salientes
        if (n -> salientes -> principio){
            (n -> salientes) -> pintar();
            cout << "\n";
        }else{
            cout << "No tiene arcos salientes\n";
        }
        /*
        cout << "   <-- "; // Imprimir entrantes
        if (n -> entrantes -> principio){
            (n -> entrantes) -> pintar();
            cout << "\n";
        }else{
            cout << " No tiene arcos entrantes.\n";
        }
        */
        cout<<"\n";
        n = n -> siguiente;
    }
}

bool Lista_nodos::borrar(int a){
    Nodo *p;

    if (buscar(a))
        return false;

    if (donde == PRINCIPIO){
        p = principio;
        principio = p -> siguiente;
    }else if (donde == ENMEDIO){

        p = anterior -> siguiente;
        anterior -> siguiente = p -> siguiente;
    }else{
        p = anterior -> siguiente;
        anterior -> siguiente = NULL;
    }

    delete p;
    cuantos --;
    return true;
}

int Lista_nodos::pop(){
    int num_nodo;
    num_nodo = principio -> num_nodo;

    principio = principio -> siguiente;
    cuantos --;
    return num_nodo;
}

int Lista_nodos::get_cuantos(){
    return cuantos;
}



//////////////////////////////////////
//                                  //
//                                  //
//                                  //
//                                  //
//    Comienza clase Lista_ruta     //
//                                  //
//                                  //
//                                  //
//                                  //
//////////////////////////////////////

class Lista_ruta{
    NodoRuta *principio, *final;
  public:
    Lista_ruta();
    ~Lista_ruta();
    void ajustar(NodoRuta*, int);
    NodoRuta* agregar(Nodo*, int);
    Nodo* sacar();
    void pintar();

    void nuevo();
    void limpiar();
    friend class Grafica;
};

void Lista_ruta::nuevo(){
    principio = NULL;
    final = NULL;
}

void Lista_ruta::limpiar(){
    NodoRuta *p, *q;
    p = principio;
    while(p){
        q = p;
        p = (p -> siguiente);
        delete q;
    }
    principio = final = NULL;
}

Lista_ruta::Lista_ruta(){
    nuevo();
}

Lista_ruta::~Lista_ruta(){
    limpiar();
}

Nodo* Lista_ruta::sacar(){
    Nodo *n;
    NodoRuta *p;
    p = principio;
    n = (p -> direccion);

    if (!principio)
        return NULL;
    if (principio == final)
        final = NULL;

    principio = (principio -> siguiente);

    delete p;
    return n;
}

void Lista_ruta::ajustar(NodoRuta* nodo_ruta, int nueva_longitud){
    NodoRuta* n = principio;
    while(n && n!= nodo_ruta){
        n = n->siguiente;
    }
    if(n)
    (n -> ruta_corta) = nueva_longitud;
}

NodoRuta* Lista_ruta::agregar(Nodo* nodo_apuntado, int longitud_ruta){
    NodoRuta* n;
    n = new NodoRuta;
    (n -> ruta_corta) = longitud_ruta;
    (n -> direccion) = nodo_apuntado;
    (n -> siguiente) = NULL;

    if (!principio){
        principio = n;
    }else{
        (final -> siguiente) = n;
    }
    final = n;
    return n;
}

/*
    Lista_ruta::pintar()
    Lista_ruta tiene los valores del camino mas corto de A a B, pero los tiene en orden inverso.
    La siguiente funcion los imprime en el orden correcto: primero ingresa los caracteres a un
    flujo en orden inverso, luego transforma ese flujo a cadena y finalmente voltea la cadena.

    There must be a better way.
    Perdon.
*/
#include <string.h>
#include <sstream>
void Lista_ruta::pintar(){
    string str_lista, str_aux;
    stringstream ss;

    NodoRuta *n = principio;
    while(n){
        ss << "  ]" << n -> direccion -> num_nodo << "[";
        n = (n -> siguiente);
    }

    str_lista = ss.str();
    str_aux = "";
    for (int i = str_lista.size(); i >= 0 ; i--)
         str_aux += str_lista[i];
    cout << str_aux;
    cout << endl;
}

//////////////////////////////////////
//                                  //
//                                  //
//                                  //
//                                  //
//      Comienza clase Grafo        //
//                                  //
//                                  //
//                                  //
//                                  //
//////////////////////////////////////

class Grafica{
    Lista_nodos N;
    Lista_ruta R;
public:
    Grafica();
    ~Grafica();
    void agregar_nodo(int a);
    void agregar_arco(int a,int b,int l);
    bool ruta_corta(int a,int b);

    void pintar();
    void pintar_nodos();
    void pintar_arcos();
    void pintar_ruta();
};

Grafica::Grafica(){
    N.nuevo();
    R.nuevo();
}

Grafica::~Grafica(){
    N.limpiar();
    R.limpiar();
}

void Grafica::agregar_nodo(int a){
    N.agregar(a);
}

void Grafica::agregar_arco(int a,int b,int l){
    Nodo *arc_ini, *arc_fin;
    arc_ini = N.buscar(a);
    arc_fin = N.buscar(b);
    if( !arc_ini || !arc_fin ){
        cout << "El arco no fue agregado :)";
        return;
    }
    (arc_ini -> salientes) -> agregar(arc_fin, l);
}

bool Grafica::ruta_corta(int inicio_ruta, int fin_ruta){
    Nodo *n; // Nodo en revision
    Arco *a; // Arco del nodo en revision
    Nodo *adyacente_de_n; // Nodo al que apunta el nodo 'n' mediante el arco 'a'
    n = N.buscar(inicio_ruta);
    if(!n || !N.buscar(fin_ruta)){ // Si alguno de los dos nodos no existe,
        if (!n){
            cout << "El nodo [" << inicio_ruta << "] ";
        }else{
            cout << "El nodo [" << fin_ruta << "] ";
        }
        cout << "no existe y por lo tanto no existe ninguna ruta.\n";
        return false;
    }

    n -> ruta_corta = 0;
    while(n){ // Mientras hayan nodos por recorrer
        n -> bandera = 2; // 2: Marca permanente
        if((n -> num_nodo) != fin_ruta){
            (n -> salientes) -> iniciar_recorrido();
            a = n -> salientes -> recorrer();
            while(a){
                adyacente_de_n = (a -> nodo_apuntado);
                if(adyacente_de_n -> bandera == 0){ // 0 = No marcado (no 'tocado')
                    (adyacente_de_n -> bandera) = 1;  // 1 = Marca temporal
                    (adyacente_de_n -> ruta_corta) = (n -> ruta_corta) + (a -> longitud);
                    (adyacente_de_n -> antecesor) = n;
                    (adyacente_de_n -> direccion_en_lista_ruta) = R.agregar(adyacente_de_n, (adyacente_de_n -> ruta_corta));
                }else if( (n -> ruta_corta + a -> longitud) < (adyacente_de_n -> ruta_corta)){
                    (adyacente_de_n -> ruta_corta) = (n -> ruta_corta) + (a -> longitud);
                    (adyacente_de_n -> antecesor) = n;
                    R.ajustar((adyacente_de_n -> direccion_en_lista_ruta), (n -> ruta_corta + a -> longitud));
                }
                a = (n -> salientes) -> recorrer();
            }
            n = R.sacar();
        }else{ // Ruta encontrada
          R.limpiar();
          while(n){
            R.agregar(n, n -> ruta_corta);
            n = (n -> antecesor);
          }
          cout << "La ruta mas corta es la que pasa por los siguientes nodos: \n\t";
          R.pintar();
          cout << "Y tiene una longitud de " << R.principio -> ruta_corta << "\n";
          R.limpiar();
          return true;
        }
    }
    cout << "No se encontro ninguna ruta :(\n";
    return false;
}

void Grafica::pintar(){
    N.pintar_todo();
}
void Grafica::pintar_nodos(){
    N.pintar_nodos();
}

void Grafica::pintar_arcos(){
    N.pintar_arcos();
}

void Grafica::pintar_ruta(){
    R.pintar();
}

#endif
