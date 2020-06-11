/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package practica0;

import java.util.Scanner;

/**
 *
 * @author usuario
 */
public class Practica2 {
    
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
  //int valor = 0;
        Numero p;         
        p = new Numero();  

          Scanner teclado = new Scanner(System.in);

    System.out.println("Escriba un numero");
    String x = teclado.next();  
        p.pares(x);
        
        int n = Integer.parseInt(x);
        p.positivo(n);

        
        
        
        
        
        
    }
    
    
}
