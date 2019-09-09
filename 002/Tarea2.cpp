// Introducci�n a C++, Nacho Cabanes
// Ejemplo 07.05:
// Array con muchos struct y menu para manejarla
 
#include <iostream>
#include <string>
using namespace std;
 
struct tipoDatos
{
    string nombreFich;        // Nombre del fichero
   
};
 
int numeroFichas=0;  // N�mero de fichas que ya tenemos
int i;               // Para bucles
int opcion;          // La opcion del menu que elija el usuario
 
string textoTemporal; // Para pedir datos al usuario
int numeroTemporal;
 
int main()
{
    tipoDatos *fichas = new tipoDatos[1000];
 
    do
    {
        // Menu principal
        cout << endl;
        cout << "Escoja una opci�n:" << endl;
        cout << "1.- Pila" << endl;
        cout << "2.- Cola" << endl;
        // meni
		cout << "Escoja una opci�n:" << endl;
        cout << "1.- A�adir datos de un nuevo fichero" << endl;
        cout << "2.- Mostrar los nombres de todos los ficheros" << endl;
        cout << "3.- Mostrar ficheros que sean de mas de un cierto tama�o" << endl;
        cout << "4.- Ver datos de un fichero" << endl;
        cout << "5.- Salir" << endl;
 
        cin >> opcion;
 
        // Hacemos una cosa u otra seg�n la opci�n escogida
        switch(opcion)
        {
            case 1: // A�adir un dato nuevo
                if (numeroFichas < 1000)   // Si queda hueco
                {
                    cout << "Introduce el nombre del fichero: ";
                    cin >> fichas[numeroFichas].nombreFich;
                 
                    numeroFichas++;  // Y tenemos una ficha m�s
                }
                else   // Si no hay hueco para m�s fichas, avisamos
                    cout << "M�ximo de fichas alcanzado (1000)!" << endl;
                break;
 
            case 2: // Mostrar todos
                for (i=0; i<numeroFichas; i++)
                    cout << "Nombre: " << fichas[i].nombreFich
                        << endl;
                break;
 
 
 
            case 5: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                break;
 
            default: // Otra opcion: no v�lida
                cout << "Opci�n desconocida!" << endl;
                break;
        }
    } while (opcion != 5);  // Si la opcion es 5, terminamos
 
    return 0;
}
