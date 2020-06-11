/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package practica0;
import java.lang.*;
import java.util.Scanner;
/**
 *
 * @author usuario
 */
public class Numero {
        // Atributo o variable miembro 
    public int num;
    public int x;
    // Metodos 
        public void primo(int x){
            int desde = 2;
        int hasta = x;
        boolean esPrimo;
            System.out.println("Los numeros primos son: ");
        for (int i = desde; i <= hasta; i++) {
            esPrimo = true;

            for (int j = 2; j <= Math.sqrt(i) && esPrimo; j++) {
                if (i % j == 0) {
                    esPrimo = false;
                }
            }

            if (esPrimo) {
                System.out.println(i);
            }
        }
           }        
                
                
    
        public void fib(int x){
        int fibo1=1;
        int fibo2=1; 

        System.out.print(fibo1 + " ");
        for(int i=2;i<=(x+1);i++){
             System.out.print(fibo2 + " ");
             fibo2 = fibo1 + fibo2;
             fibo1 = fibo2 - fibo1;
        }
        System.out.println();
        }
        
        public void mayor99(int x){
            if(x>99)System.out.println("El numero es mayor a 99");
            else System.out.println("El numero es menor igual a 99");
        }
    
        public void binario(int x) {
        int numero, exp, digito;
        double binario;
        

        exp=0;
        binario=0;
        while(x!=0){
                digito = x % 2;            
                binario = binario + digito * Math.pow(10, exp);   
                exp++;
                x = x/2;
        }
        System.out.printf("Binario: %.0f %n", binario);
 
    }
    
    public void mayor(int x) {
        if(x>9) System.out.println("Numero mayor a 9");
        else System.out.println("Numero menor igual a 9");
 
    }
    
        public void pares(String x) {
        
            int s = x.length();
    char k=' ';
        System.out.println("Los numeros pares son: ");
        for (int i = 0; i < s; i++) {
            k = x.charAt(i);

            if ((k == '2') || (k == '4') || (k=='6') || (k=='8') || (k=='0')) {

                  System.out.println(k);
            }

        }  
    }
    
    public void factorial(int n) {
        
        num=1;
        while ( n!=0) {
         num=num*n;
         n--;
         
        }
        System.out.println("El factorial del segundo digito es: ");
        System.out.println(num);
    }
 
    
    public void positivo(int x) {
        this.num = x;
        if(x>=0 && x>9999) System.out.println("Positivo y mayor a 9999");
        
        else System.out.println("Negativo y menor igual a 9999");
    }
    

}
