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
cout<<"      |INTEGRANTES:                                                        |"<<endl;
cout<<"      |            JUNIOR                                                  |"<<endl;
cout<<"      |____________________________________________________________________|"<<endl;
}
 
//menu principal
void menu1(void){
	int n1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"              <<<<<<<<<<          PROYECTO FINAL          >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"                                                                    "<<endl;
    cout<<"      (1)COMPILANDO CON WINGW            ||   ||||||    ||||||  "<<endl;
    cout<<"      (2)COMPILANDO CON TINY C           ||   ||        ||   "<<endl;
    cout<<"      (3)COMPILANDO CON BORLAND C++      ||   ||        ||       "<<endl;
    cout<<"      (4)COMPILANDO CON C++              ||   ||        ||    "<<endl;
    cout<<"      (5)SALIR                           ||   ||        ||     "<<endl;
    cout<<"                                         ||   ||||||    ||||||     "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
    cout<<"                                         PROYECTO - PROGRAMACION "<<endl; //SALIR DEL PROGRAMA   
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      Ingrese el numero de la opcion : ";
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}


//MENU PRINCIPAL WINGW
void menu2(void){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"                 <<<<<<<<<<         COMPILANDO CON WINGW       >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"                                        "<<endl;
    cout<<"      (1)VER COMPILACION            "<<endl;
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


//MENU PRINCIPAL TONYC
void menu3(void){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"                 <<<<<<<<<<         COMPILANDO CON TINY C       >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"                                        "<<endl;
    cout<<"      (1)VER COMPILACION            "<<endl;
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

//MENU PRINCIPAL BORLANDC
void menu4(void){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"                 <<<<<<<<<<         COMPILANDO CON BORLAND C++      >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"                                        "<<endl;
    cout<<"      (1)VER COMPILACION            "<<endl;
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


//MENU PRINCIPAL C++
void menu5(void){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout<<"      ---------------------------------------------------------------------\n";
    cout<<"                 <<<<<<<<<<         COMPILANDO CON  C++      >>>>>>>>>>";
    cout<<"\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout<<"                                        "<<endl;
    cout<<"      (1)VER COMPILACION            "<<endl;
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


//Funcion para mostrar mingw
void mostrar_mingw(){  
	ifstream archivo_entra("mingw.txt");
	char car;
	while(archivo_entra.get(car))
	cout<<car;
	archivo_entra.close();
	cout<<"fin de programa"<<endl;
}

//Funcion para mostrar tinyc
void mostrar_tinyc(){  
	ifstream archivo_entra("tonyc.txt");
	char car;
	while(archivo_entra.get(car))
	cout<<car;
	archivo_entra.close();
	cout<<"fin de programa"<<endl;
}

//Funcion para mostrar borlandc
void mostrar_borlandc(){  
	ifstream archivo_entra("borlandc.txt");
	char car;
	while(archivo_entra.get(car))
	cout<<car;
	archivo_entra.close();
	cout<<"fin de programa"<<endl;
}


//Funcion para mostrar c
void mostrar_c(){  
	ifstream archivo_entra("c.txt");
	char car;
	while(archivo_entra.get(car))
	cout<<car;
	archivo_entra.close();
	cout<<"fin de programa"<<endl;
}

//MENU PRINCIPAL
int main (void){
    SetConsoleTitle("PROYECTO");
  
 
    int op,op2,dato;
        do{ titulo();
            menu1();
            cin>>op;
            switch(op){
                //WINGW
                case 1: system("cls");
                        do{
                            titulo();
                            menu2();
                            cin>>op2;
 
                            switch(op2){           
                                   case 1: system("cls");
                                        mostrar_mingw();
                                        break;
 								case 2: break;
                                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
                            }
                            cout<<endl;
                            system("pause");  system("cls");
                        }while(op2!=2);
                        break;
                //TONY C
                case 2: system("cls");
                        do{
                            titulo();
                            menu3();
                            cin>>op2;
 
                            switch(op2){           
                                   case 1: system("cls");
                                        mostrar_tinyc();
                                        break;
 								case 2: break;
                                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
                            }
                            cout<<endl;
                            system("pause");  system("cls");
                        }while(op2!=2);
                        break;
                //BORLAND C++
                case 3: system("cls");
                        do{
                            titulo();
                            menu4();
                            cin>>op2;
 
                            switch(op2){           
                                   case 1: system("cls");
                                        mostrar_borlandc();
                                        break;
 								case 2: break;
                                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
                            }
                            cout<<endl;
                            system("pause");  system("cls");
                        }while(op2!=2);
                        break;
                //C++ 
                case 4: system("cls");
                        do{
                            titulo();
                            menu5();
                            cin>>op2;
 
                            switch(op2){           
                                   case 1: system("cls");
                                        mostrar_c();
                                        break;
 								case 2: break;
                                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
                            }
                            cout<<endl;
                            system("pause");  system("cls");
                        }while(op2!=2);
                        break;
				//SALIR       
                case 5: return 0;
                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
            }
            cout<<endl;
            system("pause");  system("cls");
        }while(op!=4);
        system("pause");
    return 0;
}
