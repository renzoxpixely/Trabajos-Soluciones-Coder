/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package practica0;

import java.util.*;

/**
 *
 * @author usuario
 */
public class Practica10 {
    public static void main(String[] args) {
                 int valor = 0;
        Numero p;         
        p = new Numero(); 
        /*
        int ci=0;
        int digma=0;
        int digme=9;
        int cont=0;
        char cadena1;
        System.out.println("Ingrese valor");
            
            Scanner reader = new Scanner(System.in);
        ci  = reader.nextInt();  
        String cadena = Integer.toString(ci);
        while(cont<=cadena.length()){
            
                 
         char cadena1 = cadena.charAt(-1);
            
            //cadena1 = cadena.charAt(cont++);
        //int n = Integer.parseInt(cadena1[0]);
                System.out.println(cadena1);
                 cont++;
            }*/
        
        /*
               String s1 = "Este es el método de cadena de caracteres";
 
        // devuelve el valor char en el índice 0
        System.out.println("Carácter en la posición 0 es:" + s1.charAt(0));
 
        // devuelve el valor de char en el quinto índice
 
        System.out.println("Carácter en la 5ta posición es:" + s1.charAt(5));
 
        // devuelve el valor de char en el 22 ° índice
 
        System.out.println("El personaje en la posición 22 es:" + s1.charAt(22));
 
        // devuelve el valor de char en el 23 ° índice
        char resultado = s1.charAt(-1);
        System.out.println("El personaje en la posición 23 es:" + resultado);
      
        */
        
        
        
       // Valores que tiene el array A desordenado.
        Scanner tecla = new Scanner(System.in);
        Scanner key = new Scanner(System.in);
        int tam;
        System.out.println("Ingrese cantidad de digitos de su CI");
        tam = tecla.nextInt();
        String[] A= new String[tam]; 
     
        for(int i=0; i<A.length; i++) 
        {
            System.out.println("Ingrese digito: "+i);
            A[i] = key.nextLine();
        }/*
        int nf = Integer.parseInt(A[(A.length-1)]);
        System.out.println(nf);
        p.factorial(nf);*/
        
        
        // Imprimimos el array A desordenado. 
        System.out.println("array A desordenado: "); 
        for(int i=0; i<A.length; i++) 
        {System.out.println( " A[" + i + "] = " + A[i] ); }
       
        // Inicio del metodo de ordenamiento de la Burbuja
        String aux; 
        for(int i=1; i<=A.length; i++) {  
            for(int j=0; j<A.length-i; j++) { 
                if( A[j].compareTo( A[j+1] ) > 0 ) { 
                    aux   = A[j]; 
                    A[j]  = A[j+1]; 
                    A[j+1]= aux; 
                }    
            } 
        }
        // Fin del metodo de ordenamiento de la Burbuja
     
        // Imprimimos el numero menor y mayor. 
        System.out.println("\n Los numeros MAX y MIn son: "); 
        for(int i=0; i<A.length; i++) 
        {
            if(i==0 || i==(A.length-1)) System.out.println( " A[" + i + "] = " + A[i] ); }
   
                    System.out.println("\n Los cantidad de numeros primos es: "); 
        int cont = 0;
        for(int i=0; i<A.length; i++) 
        {
            if("2".equals(A[i]) || "3".equals(A[i])|| "5".equals(A[i])  || "7".equals(A[i])) cont++; }
        System.out.println(cont);
        
            
        
        
        System.out.println("Nombre de Alumuno");
    }
    }
   
