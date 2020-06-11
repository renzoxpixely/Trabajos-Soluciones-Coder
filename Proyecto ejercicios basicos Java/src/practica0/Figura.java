/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package practica0;
import java.io.*;
/**
 *
 * @author usuario
 */
public class Figura {
      public float radio;
      public float lado;
      public float vol;
        
     public void aesfera(int radio) {
        int area = (int) (4 * Math.PI * radio * radio);
        System.out.println("El area de una esfera es: "+area);
    }
     
     public void dcircun(int radio){
        int diam = (int) (2*radio);
        System.out.println("El diametro de la circunferencia es: "+diam);
    }
     
    public void hcil(float vol, float radio){
        float h = (float) ((vol)/ (Math.PI *radio * radio));
        System.out.println("La altura del cilindro es: "+h);
    }
    
    public void lcubo(float vol){
            System.out.println("El valor del lado es: "+Math.cbrt(vol)); 
             }
 }
