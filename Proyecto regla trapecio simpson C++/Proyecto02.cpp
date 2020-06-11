#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<windows.h>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<math.h>
#define max_char 30
#define max_doce 12
#define Color_Red 12
#define Color_Def 15
#define Color_Yellow 14
#define Color_Green 10

using namespace std;
/*------ estructura para linea ------*/
struct nodoLinea{
 
    int codLinea;
    char descripLinea[max_char];
    struct nodoProducto *enlace;
    struct nodoLinea *izq, *der;
};

typedef struct nodoLinea *Linea;

 
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
cout<<"\n\n                Universidad Técnica Particular de Loja - UTPL ";
cout<<"\n\n                            Integrantes";
cout<<"\n\n                            Integrante 1";
cout<<"\n\n                            Integrante 2";
cout<<"\n\n                            Integrante 3";
cout<<endl;
	//Tiempo de carga del programa
	int i = 0;
    printf("Cargando programa\n");
    printf("El programa terminara de cargar en 15 segundos.\n");
    for(i=1; i<=15; i++){
        Sleep(1000);
        cout<<i<<" ";
    }

    printf("Listo");
    system("cls");
}

 
//menu principal
void menu1(void){
	int n1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"              <<<<<<<<<<          METODOS         >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"(1)La regla del Trapecio      ||    ||    |||||||||    |||||||||   ||         "<<endl;
    cout<<"(2)La Regla de 1/3 de Simpson ||    ||       ||        ||     ||   ||         "<<endl;
    cout<<"(3)La Regla de 3/8 de Simpson ||    ||       ||        |||||||||   ||         "<<endl;
    cout<<"(4)SALIR                      ||    ||       ||        ||          ||         "<<endl;
    cout<<"                              ||    ||       ||        ||          ||         "<<endl;
    cout<<"                              ||||||||       ||        ||          ||||||    "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
    cout<<"                                         PROYECTO - PROGRAMACION "<<endl; //SALIR DEL PROGRAMA   
  
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      Ingrese el numero de la opcion : ";
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

//Metodo de la regla del Trapecio             a^6 + b^5 + c^4 + d^3 + e^2 + f^1 + g  
void menu2(void){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"                 <<<<<<<<<<    Metodo de la regla del Trapecio    >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"                                        "<<endl;
    cout<<"      (1)FUNCION  a^6 + b^5 + c^4 + d^3 + e^2 + f^1 + g   "<<endl;
    cout<<"      Ingresar los valores de a b c d e f g   "<<endl;
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

//Metodo de la Regla de 1/3 de Simpson					a^6 + b^5 + c^4 + d^3 + e^2 + f^1 + g
void menu3(void){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"                 <<<<<<<<<<   Metodo de la Regla de 1/3 de Simpson   >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"                                        "<<endl;
    cout<<"      (1)FUNCION  a^6 + b^5 + c^4 + d^3 + e^2 + f^1 + g   "<<endl;
    cout<<"      Ingresar los valores de a b c d e f g   "<<endl;
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

//	Metodo de la Regla de 3/8 de Simpson    	a^6 + b^5 + c^4 + d^3 + e^2 + f^1 + g
void menu4(void){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"                 <<<<<<<<<<      Metodo de la Regla de 3/8 de Simpson      >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"                                        "<<endl;
    cout<<"      (1)FUNCION  a^6 + b^5 + c^4 + d^3 + e^2 + f^1 + g   "<<endl;
    cout<<"      Ingresar los valores de a b c d e f g   "<<endl;
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
 

//a.	Método de la regla del Trapecio


// Define the function to be integrated here: 
double f(double t1,double t2,double t3,double t4,double t5,double t6,double t7,double x){
  return 	t1*pow(x,6.0)+t2*pow(x,5.0)+t3*pow(x,4.0)+t4*pow(x,3.0)+t5*pow(x,2.0)+(t6*x)+1*t7;;
}
/*
double f(double x){
  return x*x;
}

*/
void m1(){  
/*Program begins*/
  double t1,t2,t3,t4,t5,t6,t7;
  int n,i;
  double a,b,h,x,sum=0,integral;
  cout<<"Ingrese los valores de la funcion a b c d e f g"<<endl;
  cin>>t1>>t2>>t3>>t4>>t5>>t6>>t7;
  /*Ask the user for necessary input */
  printf("\nIngrese el numero de sub-intervalos: ");
  scanf("%d",&n);
  printf("\nIngrese el limite inicial : ");
  scanf("%lf",&a);
  printf("\nIngrese el limite final: ");
  scanf("%lf",&b);
  /*Begin Simpson's 1/3rd Procedure: */
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f( t1,t2, t3, t4,t5, t6, t7, x);
  }
  integral=(h/2)*(f( t1,t2, t3, t4,t5, t6, t7, a)+f( t1,t2, t3, t4,t5, t6, t7, b)+2*sum);
  /*Print the answer */
  printf("\nLa integral es: %lf\n",integral);

}

//Método de la Regla de 1/3 de Simpson
void m2()

{    
 double t1,t2,t3,t4,t5,t6,t7;
 cout<<"Ingrese los valores de la funcion a b c d e f g"<<endl;
  cin>>t1>>t2>>t3>>t4>>t5>>t6>>t7;
cout.precision(4);        //set the precision
    cout.setf(ios::fixed);
    int n,i;            //n is for subintervals and i is for loop
    double a,b,c,h,sum=0,integral;
    cout<<"\nIngrese los limites de la integracion,\n\nLimite inicial,a= ";
    cin>>a;
    cout<<"\nLimite Final, b=";                //get the limits of integration
    cin>>b;
    cout<<"\nIngrese los limites del intervalo(DEBE SER INCLUSO), \nn=";        //get the no. of subintervals
    cin>>n;
    double x[n+1],y[n+1];
    h=(b-a)/n;                        //get the width of the subintervals
    for (i=0;i<n+1;i++)
    {                        //loop to evaluate x0,...xn and y0,...yn
        x[i]=a+i*h;                //and store them in arrays
        y[i]=f(t1,t2, t3, t4,t5, t6, t7, x[i]);
    }
    for (i=1;i<n;i+=2)
    {
        sum=sum+4.0*y[i];                //loop to evaluate 4*(y1+y3+y5+...+yn-1)
    }
    for (i=2;i<n-1;i+=2)
    {
        sum=sum+2.0*y[i];                /*loop to evaluate 4*(y1+y3+y5+...+yn-1)+
                                        2*(y2+y4+y6+...+yn-2)*/ 
    }
    integral=h/3.0*(y[0]+y[n]+sum);    //h/3*[y0+yn+4*(y1+y3+y5+...+yn-1)+2*(y2+y4+y6+...+yn-2)]
    cout<<"\nLa integral definida es: "<<integral<<"\n"<<endl;
    
}

//Método de la Regla de 3/8 de Simpson 
void m3()

{
	double t1,t2,t3,t4,t5,t6,t7;
  int n,i;
  double a,b,h,x,sum=0,integral;
  cout<<"Ingrese los valores de la funcion a b c d e f g"<<endl;
  cin>>t1>>t2>>t3>>t4>>t5>>t6>>t7;
  printf("\nIngrese el numero de sub-intervalos(MULTIPLO DE 3): ");
  scanf("%d",&n);
  printf("\nIngrese el limite incial ");
  scanf("%lf",&a);
  printf("\nIngrese el limite final ");
  scanf("%lf",&b);
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    if(i%3==0){
      sum=sum+2*f(t1,t2, t3, t4,t5, t6, t7, x);
    }
    else{
      sum=sum+3*f(t1,t2, t3, t4,t5, t6, t7, x);
    }
  }
  integral=(3*h/8)*(f(t1,t2, t3, t4,t5, t6, t7, a)+f(t1,t2, t3, t4,t5, t6, t7, b)+sum);
  printf("\nLa integral es: %lf\n",integral);
}
	

//MENU PRINCIPAL
int main (void){
    SetConsoleTitle("PROYECTO");
    
 
    int op,op2,dato;
    titulo();
        do{ 
            menu1();
            cin>>op;
            
            switch(op){
                //Metodo de la regla del Trapecio
                case 1: system("cls");
                        do{       
                            menu2();
                            cin>>op2;
 
                            switch(op2){           
                                   case 1: system("cls");
                                        m1();
                                        break;
 								case 2: break;
                                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
                            }
                            cout<<endl;
                            system("pause");  system("cls");
                        }while(op2!=2);
                        break;
                //Método de la Regla de 1/3 de Simpson 
                case 2: system("cls");
                        do{
                            menu3();
                            cin>>op2;
 							
                            switch(op2){           
                                   case 1: system("cls");
                                       m2();
 								case 2: break;
                                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
                            }
                            cout<<endl;
                            system("pause");  system("cls");
                        }while(op2!=2);
                        break;
                //Método de la Regla de 3/8 de Simpson 
                case 3: system("cls");
                        do{
                            
                            menu4();
                            cin>>op2;
                            switch(op2){           
                                   case 1: system("cls");
                                        m3();
                                       
 								case 2: break;
                                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
                            }
                            cout<<endl;
                            system("pause");  system("cls");
                        }while(op2!=2);
                        break;
            }
            cout<<endl;
            system("pause");  system("cls");
        }while(op!=4);
        system("pause");
    return 0;
}


