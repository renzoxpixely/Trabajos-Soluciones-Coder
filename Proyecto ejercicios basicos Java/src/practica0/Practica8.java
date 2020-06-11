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
public class Practica8 {
               public static void main(String[] args) {
        int num = 0;
        int a,b,n;
        Numero p;         
        p = new Numero();  

        System.out.println("Ingrese un numero ");
        Scanner reader = new Scanner(System.in);
        num  = reader.nextInt();  
         p.mayor99(num);
        
        a=num; b=num;
        while(num>100){
                num=num/10;
                a=num;
        }
        while(num>10){
                num=num/10;
                b=num;
        }
        num=a-(b*10);
        n=num;
        if(num%2==0)System.out.println("Es par");
        else p.primo(num);
         
    }
}
