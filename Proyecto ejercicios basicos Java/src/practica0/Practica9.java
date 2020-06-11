/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package practica0;

import java.util.Scanner;
import java.util.Scanner;

/**
 *
 * @author usuario
 */
public class Practica9 {
               public static void main(String[] args) {
                  Figura p;         
        p = new Figura(); 
                   float vol;
                   System.out.println("Ingrese el volumen del cubo");
        Scanner reader = new Scanner(System.in);
        vol  = reader.nextInt();  
        p.lcubo(vol);
    }
}
