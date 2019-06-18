#include <Servo.h>
#define motorBase 12 //Declaro pin de la base
#define motorDerecha 11 //Declaro pin del motor derecho
#define motorIzquierda 10 //Declaro pin del motor izquierdo
#define motorMano 9 //Declaro motor de la mano


Servo Base; // Declaro el servomotor de la base 
Servo Derecha; //Declaro el servomotor de la derecha
Servo Izquierda; //Declaro el servomotor de la izquierda
Servo Mano; //Declaro el servomotor de la mano
int i = 0;
void setup() {
    
  Base.attach(motorBase); //Inicializamos el servo de la base
  Derecha.attach(motorDerecha); //Inicializamos el servo de la derecha
  Izquierda.attach(motorIzquierda); //Inicializamos el servo de la izquierda
  Mano.attach(motorMano); //Inicializamos el servo de la mano

 
  //Movimiento del motor de la base

 while(i != 90)
 {
  
  Base.write(i);
  delay(20);
  i++;
 }


 while (i >= 0)
 {

  Base.write(i);
  delay(20);
  i--;
 }

 while(i != 180)
 {

  Base.write(i);
  delay(20);
  i++;
 }

 while(i != 90)
 {

  Base.write(i);
  delay(20);
  i--;
 }
 

  //Movimiento del motor derecho
  i=90;
  while(i>=40)
  {
  Derecha.write(i);
  delay(15);
  i--;
  }
  
  while(i<=140){
  Derecha.write(i);
  delay(15);
  i++;
  }
while(i>=90)
{
  Derecha.write(i);
delay(15);
i--;
}
  //Movimiento del motor izquierdo

  i =90;
  
  while(i <= 180)
  {
  Izquierda.write(i);
  delay(20);
  i++;
  }
  
  i=180;
  while(i >= 90 )
  {
  Izquierda.write(i);
  delay(20);
  i--;
  }
  

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
