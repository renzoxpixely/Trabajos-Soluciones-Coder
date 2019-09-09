#include<stdio.h>
#include<conio.h> //permite getch.
#include<string.h> // permite strcmp y strcpy.

int main()
{
    char nombre[10][20];
    char aux[20];//tiene que ser de igual o mayor tamaño que la segunda componente
    //de nombre porque aquí copiaremos esa cadena.
    int i,j,k;
    int l=0;
    printf("Para terminar escriba * \n");
    do
        {
            printf("Introduce un nombre de cancion: ");
            gets(nombre[l]);//lee cadenas y las almacena.
            l++;
        }
    while (strcmp(nombre[l-1],"*")!=0);//permite comparar cadenas.

    // ORDENAR CADENAS DESCENDENTE
        printf("Ordenar forma descendente\n");
    for(i=0; i<l-1; i++)
    {
        k=i;
        strcpy(aux, nombre[i]);
        for(j=i+1; j<l; j++)
        {
            if(strcmp(nombre[j], aux)<0)
            {
                k=j;
                strcpy(aux, nombre[j]);
               //permite hacer una copia auxiliar de la cadena nombre[j];
            }
        }
        strcpy(nombre[k],nombre[i]);
        strcpy(nombre[i],aux);
    }

    for(i=0; i<l; i++)
    {
        printf("%s",nombre[i]);
        printf("\n");
    }
	// ORDENAR CADENAS ASCENDENTE
	printf("Ordenar forma ascendente\n");
    for(i=l; i>0; i--)
    {
        printf("%s",nombre[i]);
        printf("\n");
    }
  return 0;
}
