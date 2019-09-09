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
public class Practica3 {
        public static void main(String[] args) {
        int valor = 0;
        Numero p;         
        p = new Numero();  

        System.out.println("Ingrese valor");
        Scanner reader = new Scanner(System.in);
        
        valor  = reader.nextInt();  
        p.mayor(valor); 
        p.binario(valor);
        
        
     
        }
        
        
        
        
        
        
    }

