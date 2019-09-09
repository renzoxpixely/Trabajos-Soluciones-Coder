#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 5
int push(char stack[max][80], int *top, char data[80])
{
      if(*top == max -1)
            return(-1);
      else
      {
            *top = *top + 1;
            strcpy(stack[*top], data);
            return(1);
      }
}
int pop(char stack[max][80], int *top, char data[80])
{
      if(*top == -1)
            return(-1);
      else
      {
            strcpy(data, stack[*top]);
            *top = *top - 1;
            return(1);
      }
}


int main()
{
      char stack[max][80], nm[80];
      int top,ch,reply;
      int i;
      top = -1;  	// Initialize Stack
      printf("\tMENU");
      printf("\n----------------------------\n");
      printf("      1. Extraer un nombre\n");
      printf("      2. Insertar 4 nombres\n");
      printf("      3. Extraer 2 nombres\n");
      printf("      4. Extraer 3 nombres \n");
      printf("      5. Salir\n");
      printf("----------------------------\n");
      while(1)
      {
            printf("Elige una opcion : ");
            scanf("%d", &ch);
            switch (ch)
            {
                  case 1 : // pop
                        reply = pop(stack,  &top,nm);
                        if(reply == -1)
                              printf("\n La pila esta vacia \n");
                        else
                              printf("La cadena desempilada es : %s\n",nm);
                              printf("\n");
                  break;
                  case 2 : // push
                   i=1;
                  	while(i<5){
                        printf("\nIngresa %d nombre : ",i);
                        scanf("%s",nm);
                        reply = push(stack,&top,nm);
                        if(reply == -1)
                              printf("\n La pila está llena.\n");
                        else
                              printf("'%s' es empilada en la pila.\n\n",nm);
                		i++;
						}
                  break;
                  case 3: // pop
                    i=1;
                  	while(i<3){
                        reply = pop(stack,  &top,nm);
                        if(reply == -1)
                              printf("\n La pila esta vacia \n");
                        else
                              printf("La cadena desempilada es : %s\n",nm);
                              printf("\n");
                      i++;        
                          }
                  break;
                  case 4 : // pop
                    i=1;
                  	while(i<4){
                        reply = pop(stack,  &top,nm);
                        if(reply == -1)
                              printf("\n La pila esta vacia \n");
                        else
                              printf("La cadena desempilada es : %s\n",nm);
                              printf("\n");
                    	i++;
                          }
                  break;
                  case 5 :
                        exit(0);
                  break;      
                  default: 
                        printf("Operacion invalida \n");
            } 
      }
      return 0;
}
