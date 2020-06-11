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
public class Practica7 {
               public static void main(String[] args) {
//int valor = 0;
        int num = 0;
        
        Numero p;         
        p = new Numero();  

        System.out.println("Ingrese un numero ");
        Scanner reader = new Scanner(System.in);
        num  = reader.nextInt();  
         p.mayor99(num);
        while(num>10){
                num=num/10;
        }
        if(num%2==0)p.fib(num);
        else System.out.println("Es impar");
        
    }
}
