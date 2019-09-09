#ifndef PILA
#define PILA
struct caja{
    int valor;
    caja *siguiente;
};

class Pila{
    caja *principio;
    int cuantos;
public:
    Pila();
    ~Pila();
    void push(int a);
    int pop();
    void pintar();
    int get_cuantos();
};

Pila::Pila(){
    principio = NULL;
    cuantos = 0;
}

Pila:: ~Pila(){
    caja *p, *q;
    p = principio;
    while(p){
        q = p;
        p = p -> siguiente;
        delete q;
    }

    cuantos = 0;
}

void Pila::push(int a){
    caja *p;

    p = new caja;
    p -> valor = a;

    p -> siguiente = principio;
    principio = p;

    cuantos++;
}

void Pila::pintar(){
    caja *p;
    p = principio;

    while(p){
        std::cout << " " << p->valor << " ";
        p = p -> siguiente;
    }
    std::cout<<"\n";
}

int Pila::get_cuantos(){
    return cuantos;
}

int Pila::pop(){
    caja *p;
    int valor_caja;

    p = principio;
    if (p == NULL) return -31212012; //3 12 12 0 12 = E R R O R. Si, esta feo, pero no importa :)

    valor_caja = p -> valor;
    principio = principio -> siguiente;

    delete p;
    cuantos --;

    return valor_caja;
}
#endif
