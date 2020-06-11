#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<cstring>
#define max_char 30
#define max_doce 12
#define Color_Red 12
#define Color_Def 15
#define Color_Yellow 14
#define Color_Green 10
using namespace std;
/*------ estructura para productos por cada linea ------*/
struct nodoProducto{
    int codProd;
    char nomProd[max_char];
    float precio;
    struct nodoProducto *izq,*der;
};
/*------ estructura para linea ------*/
struct nodoLinea{
 
    int codLinea;
    char descripLinea[max_char];
    struct nodoProducto *enlace;
    struct nodoLinea *izq, *der;
};
/*------ estructura para clientes ------*/
struct nodoCliente{
    int codCliente;
    char nomCliente[max_char];
    char apellCliente[max_char];
    int dniCliente;
    char rucCliente[max_doce];
    char telefono[max_doce];
    char direccion[max_char];
    char email[max_char];
    struct nodoCliente *izq,*der;
};
struct nodoDetalleVenta{
    int codigo;
    int codProd;
    int cantidad;
    int codVenta;
    char marca[max_char];
    float subtotal;
    struct nodoProducto *ptrProducto;
    struct nodoDetalleVenta *sgte;
};
struct nodoVenta{
    int codigo;
    int monto;
    char fecha[max_doce];
    int codCliente;
    struct nodoCliente *ptrCliente;
    struct nodoDetalleVenta *detalle;
    struct nodoVenta *sgte;
};

struct nodoDetallePedido{
    int codigo;
    int codProd;
    int cantidad;
    int codPedido;
    char marca[max_char];
    float subtotal;
    struct nodoProducto *ptrProducto;
    struct nodoDetallePedido *sgte;
};
 
struct nodoPedido{
    int codigo;
    int monto;
    char fecha[max_doce];
    int codAlmacen;
    int codProveedor;
    struct nodoProveedor *ptrProveedor;
    struct nodoDetallePedido *detalle;
    struct nodoPedido *sgte;
};
typedef struct nodoProducto *Producto;
typedef struct nodoLinea *Linea;
typedef struct nodoCliente *Cliente;
typedef struct nodoDetalleVenta *DetalleVenta;
typedef struct nodoVenta *Venta;
typedef struct nodoProveedor *Proveedor;
typedef struct nodoPedido *Pedido;
typedef struct nodoDetallePedido *DetallePedido;
 
 
/*--------------------Funcion gotoxy -------------------*/
void gotoxy(int x,int y){
     HANDLE  hCon;
     hCon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X=x;
     dwPos.Y=y;
     SetConsoleCursorPosition(hCon,dwPos);  }
 
/*-------------------------------  TITULO PRINCIPAL   --------------------------*/
void titulo(void){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
 
cout<<"      _____________________________________________________________________"<<endl;
cout<<"      |                                   ____________________            |"<<endl;
cout<<"      |                                   | NOMBRE1\xA5"<<"         |___________ |"<<endl;
cout<<"      |        ******************         | NOMBRE2          |  EMPRESA  ||"<<endl;
cout<<"      |         SISTEMA DE VENTAS         | NOMBRE3          |           ||"<<endl;
cout<<"      |        ******************         |                  | EMPRESCORP||"<<endl;
cout<<"      |  _________________________________|                  |           ||"<<endl;
cout<<"      |  |  _    _           _    _    _  |   _ _  _ _  _ _  |   ______  ||"<<endl;
cout<<"      |  | | |  | |  _____  | |  | |  | | |       ______     |   |  _ |  ||"<<endl;
cout<<"      |  | |_|  |_|  | | |  |_|  |_|  |_| |       |  | |     |   |  | |  ||"<<endl;
cout<<"      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
}
 
//menu principal
void menu1(void){
	int n1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"              <<<<<<<<<<          SISTEMA DE VENTAS          >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"                                                                    "<<endl;
    cout<<"      (1)COMPRAS                ||    ||    ||||     ||    |||||||||   "<<endl;
    cout<<"      (2)VENTAS                 ||    ||    || ||    ||    ||     ||       "<<endl;
    cout<<"      (3)INVENTARIO             ||    ||    ||  ||   ||    |||||||||       "<<endl;
    cout<<"      (4)SALIR                  ||    ||    ||   ||  ||    ||            "<<endl;
    cout<<"                                ||    ||    ||    || ||    ||         "<<endl;
    cout<<"                                ||||||||    ||     ||||    ||     "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
    cout<<"                                         PROYECTO - PROGRAMACION "<<endl; //SALIR DEL PROGRAMA   
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      Ingrese el numero de la opcion : ";
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

//COMPRAS
void menu2(void){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"                 <<<<<<<<<<         COMPRAS        >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"                                        "<<endl;
    cout<<"      (1)VER LOS PROVEEDORES               "<<endl;
    cout<<"      (2)REGRESAR AL MENU PRINCIPAL             "<<endl;
    cout<<"              					   "<<endl;
    cout<<"               					 "<<endl;
    cout<<"                 			        "<<endl;
    cout<<"                            	       "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
    cout<<"                                         PROYECTO - PROGRAMACION "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      Ingrese el numero de la opcion : ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

//VENTAS
void menu3(void){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"                 <<<<<<<<<<         VENTAS        >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"      (1)VENDER PRODUCTO              "<<endl;
    cout<<"                                        "<<endl;
    cout<<"      (2)VER VENTAS REALIZADAS            "<<endl;
    cout<<"                                      "<<endl;
    cout<<"      (3)SALIR          "<<endl;
    cout<<"                                    "<<endl;
    cout<<"                       "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
    cout<<"                                         PROYECTO - PROGRAMACION "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      Ingrese el numero de la opcion : ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
 
}

//INVENTARIO
void menu4(void){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"                 <<<<<<<<<<         INVENTARIO        >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"      (1)VER CODIGO DEL PRODUCTO              "<<endl;
    cout<<"                                        "<<endl;
    cout<<"      (2)VER PRODUCTO            "<<endl;
    cout<<"                                      "<<endl;
    cout<<"      (3)VER INVENTARIO          "<<endl;
    cout<<"                                    "<<endl;
    cout<<"      (4)SALIR                  "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
    cout<<"                                         PROYECTO - PROGRAMACION "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      Ingrese el numero de la opcion : ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
 
}

void menu_actualizar_cliente(void){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"\n\n      ---------------------------------------------------------------------\n";
    cout<<"              <<<<<<<<<<  CLIENTES -> MODIFICAR DATOS   >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"                                       "<<endl;
    cout<<"      (1)MODIFICAR NOMBRE              "<<endl;
    cout<<"      (2)MODIFICAR APELLIDOS          "<<endl;
    cout<<"      (3)MODIFICAR TELEFONO         "<<endl;
    cout<<"      (4)MODIFICAR E-MAIL           "<<endl;
    cout<<"      (5)MODIFICAR DIRECCION       "<<endl;
    cout<<"      (6)REGRESAR                 "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
    cout<<"                                         PROYECTO - PROGRAMACION "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      Ingrese Opcion : ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

/*-------------------- FUNCION PARA INSERTAR UNA LINEA  --------------------*/
void insertar_linea(Linea &arbol, int x){
 
    if(arbol==NULL){
    arbol=new (struct nodoLinea);
    arbol->codLinea=x;
    cin.ignore();
    cout<<"\n\tingrese descripcion:";
    cin.getline(arbol->descripLinea,max_char);
    arbol->enlace=NULL;
    arbol->izq=NULL;
    arbol->der=NULL;
    }
    else if(x<arbol->codLinea) insertar_linea(arbol->izq,x);
    else if(x>arbol->codLinea) insertar_linea(arbol->der,x);
 
}
 
/*------------------ FUNCION PARA MOSTRAR TODAS LAS LINEAS -----------------*/
void mostrar_linea(Linea arbol){
    if(arbol!=NULL){
        mostrar_linea(arbol->izq);
        cout<<"\n\t"<<arbol->codLinea<<"\t"<<arbol->descripLinea<<endl;
        mostrar_linea(arbol->der);
    }
 
}
 
/*------------ Funcion que inserta un nuevo producto a la linea ---------------------*/
void insertar_producto(Producto &q,int x){
 
    if (q==NULL){
            q=new(struct nodoProducto);
            q->codProd=x;
            cin.ignore();cout<<"\n\tNOMBRE:"; cin.getline(q->nomProd,max_char);
            cout<<"\n\tPRECIO:"; cin>>q->precio;
            q->izq=NULL;
            q->der=NULL;
    }
    else if(x<q->codProd) insertar_producto(q->izq,x);
    else if(x>q->codProd) insertar_producto(q->der,x);
}
 
/*---Funcion que busca el codigo de linea para agregar en el, el producto ingresaro  ----*/
void registrar_producto(Linea arbol, int cod){
    if(arbol!=NULL){
        if(arbol->codLinea==cod){
            int x;
            cout<<"\n\n\t\t[  REGISTRO DE PRODUCTO ]\n";
            cout<<"\t\t------------------------";
            cout<<"\n\tCODIGO:"; cin>>x;
            insertar_producto(arbol->enlace,x);
        }
        else if(cod<arbol->codLinea) registrar_producto(arbol->izq,cod);
        else if(cod>arbol->codLinea) registrar_producto(arbol->der,cod);
    }
}
 
/*--------- Funcion que muestra todos los productos ingresados en una linea   ------*/
void listar_productos(Producto q){
 
    if(q!=NULL){
            listar_productos(q->izq);
            cout<<"\t"<<q->codProd<<"\t"<<q->nomProd<<"\t"<<q->precio<<endl;
            listar_productos(q->der);
        }
 
}
 
/*---------  Funcion que valida de que linea se mostraran los productos ---------*/
void mostrar_producto(Linea arbol, int x){
    if(arbol!=NULL){
        if(arbol->codLinea==x){
            cout<<"Lista de productos con la Linea:"<<arbol->codLinea<<endl;
            cout<<" Cod Prod ||   Nombre   ||  precio"<<endl;
            listar_productos(arbol->enlace);
 
        }
        else if(x<arbol->codLinea) mostrar_producto(arbol->izq,x);
        else if(x>arbol->codLinea) mostrar_producto(arbol->der,x);
    }
 
 
}

/*------- Funcion que retorna true cuando el codigo es valido  --------*/
bool validar_codigo_cliente(Cliente cliente, int cod, Cliente &ptrCliente){
 
    if(cliente!=NULL){
        if(cliente->codCliente==cod){
                ptrCliente=cliente;
            return true;
        }
        else if(cod<cliente->codCliente) validar_codigo_cliente(cliente->izq,cod,ptrCliente);
        else if(cod>cliente->codCliente) validar_codigo_cliente(cliente->der,cod,ptrCliente);
    }
}
 
/*------- Funcion que valida si el codigo del producto es verdadero--------*/
bool validar_cod_producto(Producto producto, int codprod, Producto &puntProducto){
 
    if(producto!=NULL){
        if(producto->codProd==codprod){
            puntProducto=producto;
            return true;
        }
        else if(codprod<producto->codProd) validar_cod_producto(producto->izq,codprod,puntProducto);
        else if(codprod>producto->codProd) validar_cod_producto(producto->der,codprod,puntProducto);
    }
}
 
/*------- Funcion que busca el codigo de linea del producto en el arbol --------*/
bool validar_codigo_producto(Linea arbol,int codlinea, int codprod, Producto &puntProducto){
 
    bool validar;
    validar=false;
    if(arbol!=NULL){
        if(arbol->codLinea==codlinea){
            validar=validar_cod_producto(arbol->enlace,codprod,puntProducto);
            if (validar==true)
                return validar;
 
            }
        else if(codlinea<arbol->codLinea) validar_codigo_producto(arbol->izq,codlinea,codprod,puntProducto);
        else if(codlinea>arbol->codLinea) validar_codigo_producto(arbol->der,codlinea,codprod,puntProducto);
 
        }
 
}

//Funcion para mostrar los proveedores
void mostrar_proveedores(){  
	ifstream archivo_entra("proveedores.txt");
	char car;
	while(archivo_entra.get(car))
	cout<<car;
	archivo_entra.close();
	cout<<"fin de programa"<<endl;
}

//Funcion para el codigo del producto
void codigodelproducto(){  
	ifstream archivo_codigo("codigodelproducto.txt");
	char car1;
	while(archivo_codigo.get(car1))
	cout<<car1;
	archivo_codigo.close();
	cout<<"fin de programa"<<endl;
}

//Funcion de productos
void productos(){  
	ifstream archivo_prod("producto.txt");
	char car2;
	while(archivo_prod.get(car2))
	cout<<car2;
	archivo_prod.close();
	cout<<"fin de programa"<<endl;
}

//Funcion de inventario
void inventario(){  
	ifstream archivo_inv("inventario.txt");
	char car3;
	while(archivo_inv.get(car3))
	cout<<car3;
	archivo_inv.close();
	cout<<"fin de programa"<<endl;
}

//Funcion de ventas
void ventas()
{
	{
	char rpta;
	char bus[20];
	int n;
	int j=0;
	int sum=0;
	int precio;
	int cod;
	int num;
	int total=0;
	char rpta1;
	do{
	cout<<"Ingrese nombre del producto"<<endl;
	cin.getline(bus,20);	
	ifstream archivo_codigo("codigodelproducto.txt");
	char car1;
	while(archivo_codigo.get(car1))
	{cout<<car1;}
	archivo_codigo.close();
	cout<<"Verifique si el producto existe en la lista y vea el precio s o n"<<endl;
	cin>>rpta;
	if(rpta=='n'){break;}
	cout<<"Ingrese el codigo del producto"<<endl;
	cin>>cod;
	//Precios de cada codigo 
	if(cod==1000) {precio=1;}	if(cod==1001) {precio=2;}
	if(cod==1002) {precio=3;}  	if(cod==1003) {precio=4;}
	if(cod==1004) {precio=4;}  	if(cod==1005) {precio=1;}
	if(cod==1006) {precio=2;}	if(cod==1007) {precio=1;}
	if(cod==1008) {precio=4;}   if(cod==1009) {precio=4;}
	if(cod==1010) {precio=9;}	if(cod==1011) {precio=3;}
	if(cod==1012) {precio=7;}	if(cod==1013) {precio=1;}
	if(cod==1014) {precio=9;}	if(cod==1015) {precio=2;}
	if(cod==1016) {precio=1;}	if(cod==1017) {precio=1;}
	if(cod==1018) {precio=1;}	if(cod==1019) {precio=8;}
	if(cod==1020) {precio=3;}	if(cod==1021) {precio=7;}
	if(cod==1022) {precio=2;}	if(cod==1023) {precio=9;}
	cout<<"cuantas unidades comprara?"<<endl;
	cin>>num;
	total=num*precio;
	cout<<"Ingrese (s) si va a comprar otro producto"<<endl;
	cout<<"Ingrese (n) si no va comprar otro producto"<<endl;
	cin>>rpta;
	sum=sum+total;
	if(rpta=='n' || rpta=='N'){j=1;}
	}
	while(j==0);
	cout<<"Precio total= "<<sum<<endl;
	char nom1[20];
	char nom2[20];
	char nom3[20];
	fstream clientes;
	cout<<"Ingrese nombre y apellidos del cliente en cada linea"<<endl;
	cin.getline(nom1,20);
	cin.getline(nom2,20);
	cin.getline(nom3,20);	
	clientes.open("clientes.txt",ios::out|ios::app);
	cout<<setiosflags(ios::showpoint)
	<<setprecision(2);
	clientes.put('\n');
	clientes<<nom1<<" "<<nom2<<" "<<nom3;
	clientes.close();
}	
}

//Funcion clientes
void clientes(){  
	ifstream archivo_inv("clientes.txt");
	char car3;
	while(archivo_inv.get(car3))
	cout<<car3;
	archivo_inv.close();
	cout<<endl;
}

//MENU PRINCIPAL
int main (void){
    SetConsoleTitle("SISTEMA DE VENTAS");
    Linea arbol=NULL;
    Cliente cliente=NULL;
    Venta venta=NULL;
    Proveedor proveedor=NULL;
    Pedido pedido=NULL;
 
 
    int op,op2,dato;
        do{ titulo();
            menu1();
            cin>>op;
            switch(op){
                //COMPRAS
                case 1: system("cls");
                        do{
                            titulo();
                            menu2();
                            cin>>op2;
 
                            switch(op2){           
                                   case 1: system("cls");
                                        mostrar_proveedores();
                                        break;
 								case 2: break;
                                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
                            }
                            cout<<endl;
                            system("pause");  system("cls");
                        }while(op2!=2);
                        break;
                //VENTAS
                case 2: system("cls");
                        do{
                            titulo();
                            menu3();
                            cin>>op2;
 
                            switch(op2){
                               
                                    case 1: system("cls");
                                        ventas();
                                        break;
                                    case 2: system("cls");
                                        clientes();
                                        break; 
                                case 3: break;
                                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
                            }
                            cout<<endl;
                            system("pause");  system("cls");
                        }while(op2!=3);
                        break;
                //INVENTARIO
                case 3: system("cls");
                        do{
                            titulo();
                            menu4();
                            cin>>op2;
                            switch(op2){
                                    case 1: system("cls");
                                        codigodelproducto();
                                        break;
                                    case 2: system("cls");
                                        productos();
                                        break;
                                    case 3: system("cls");
                                        inventario();
                                        break;
                             	   case 4: break;
                                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
                            }
                            cout<<endl;
                            system("pause");  system("cls");
                        }while(op2!=4);
                        break;
                case 4: return 0;
                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
            }
            cout<<endl;
            system("pause");  system("cls");
        }while(op!=4);
        system("pause");
    return 0;
}
