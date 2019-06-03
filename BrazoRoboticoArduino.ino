#include <Servo.h>
#define motorBase 12 //Declaro pin de la base
#define motorDerecha 11 //Declaro pin del motor derecho
#define motorIzquierda 10 //Declaro pin del motor izquierdo
#define motorMano 9 //Declaro motor de la mano


Servo Base; // Declaro el servomotor de la base 
Servo Derecha; //Declaro el servomotor de la derecha
Servo Izquierda; //Declaro el servomotor de la izquierda
Servo Mano; //Declaro el servomotor de la mano
void setup() {
    
  Base.attach(motorBase); //Inicializamos el servo de la base
  Derecha.attach(motorDerecha); //Inicializamos el servo de la derecha
  Izquierda.attach(motorIzquierda); //Inicializamos el servo de la izquierda
  Mano.attach(motorMano); //Inicializamos el servo de la mano

 
  //Movimiento del motor de la base
  
  Base.write(90);
  delay(2000);

  Base.write(0);
  delay(2000);

  Base.write(180);
  delay(2000);
  

  //Movimiento del motor derecho


  Derecha.write(90);
  delay(1000);

  Derecha.write(0);
  delay(1000);

  Derecha.write(80);
  delay(1000);

  //Movimiento del motor izquierdo

  Izquierda.write(90);
  delay(2000);

  Izquierda.write(0);
  delay(2000);

  Izquierda.write(180);
  delay(2000);

  //Movimiento del motor de la mano

  Mano.write(90);
  delay(2000);

  Mano.write(0);
  delay(2000);

  Mano.write(180);
  delay(2000);
  

  

  
 

}

void loop() {
  // put your main code here, to run repeatedly:

}
