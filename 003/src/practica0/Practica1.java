/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package practica0;
import java.util.Scanner;
import java.lang.*;
/**
 *
 * @author usuario
 */

public class Practica1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int valor = 0;
        Numero p;         
        p = new Numero();  

        System.out.println("Ingrese valor");
        Scanner reader = new Scanner(System.in);
        
        valor  = reader.nextInt();  
        p.positivo(valor);
        String cadena = Integer.toString(valor);
        
     cadena = cadena.substring(1, cadena.length()-(cadena.length()-2));
        int n = Integer.parseInt(cadena);
        System.out.println(n);
        p.factorial(n);

    }
    }
    

