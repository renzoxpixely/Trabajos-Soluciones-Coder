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
public class Practica6 {
            public static void main(String[] args) {
  //int valor = 0;
        float volumen = 0;
        float radio = 0;
        Figura p;         
        p = new Figura();  

        System.out.println("Ingrese valor del radio");
        Scanner reader = new Scanner(System.in);
        radio  = reader.nextFloat();  
        
        System.out.println("Ingrese volumen");
        volumen  = reader.nextFloat();  
        p.hcil(volumen, radio);
        
        
    }
    
}
