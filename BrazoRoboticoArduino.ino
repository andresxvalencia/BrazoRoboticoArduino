#include <Servo.h>
#include <SoftwareSerial.h>
#define motorBase 12 //Declaro pin de la base
#define motorDerecha 11 //Declaro pin del motor derecho
#define motorIzquierda 10 //Declaro pin del motor izquierdo
#define motorMano 9 //Declaro motor de la mano


Servo Base; // Declaro el servomotor de la base 
Servo Derecha; //Declaro el servomotor de la derecha
Servo Izquierda; //Declaro el servomotor de la izquierda
Servo Mano; //Declaro el servomotor de la mano
SoftwareSerial miBT(2,3);


int anguloIngresado;
int i = 0, j = 0;
char motor, dato;
int posicionBase;
int posicionDerecha;
int posicionIzquierda;
int posicionMano;
int automatico = 0;

/*
 * Función para retornar el ángulo y dado por el usuario.
 */

 void ingresarDato()
 {
  if(Serial.available() > 0)
  {
    motor = Serial.read();
    anguloIngresado = Serial.parseInt();
  }
 }

 void ingresarDatoBT()
 {
  if(miBT.available() > 0)
  {
  motor = miBT.read();
  anguloIngresado = miBT.parseInt();
  }
 }
 
void setup() {  
  
  Serial.begin(9600); //Velocidad de transmisión de la consola
  miBT.begin(38400); //Velocidad de transmisión del Bluetooh (HC-05)
  Base.attach(motorBase); //Inicializamos el servo de la base
  Derecha.attach(motorDerecha); //Inicializamos el servo de la derecha
  Izquierda.attach(motorIzquierda); //Inicializamos el servo de la izquierda
  Mano.attach(motorMano); //Inicializamos el servo de la mano

  /*
   * Posiciones iniciales.
   */

  Base.write(90);
  delay(500);

  Derecha.write(40);
  delay(500);

  Izquierda.write(140);
  delay(500);
  
  Mano.write(10);
  delay(500);


} 

void loop() {

  /*
   * Movimiento desde consola.
   */

  ingresarDato();

  /*
   * Movimiento desde el Bluetooh.
   */
   
  ingresarDatoBT();

    switch(motor)
    {
     case 'B':
     
     Serial.println("Usted ha ingresado el servo de la base.");

     if(anguloIngresado >= 0 && anguloIngresado <= 180)
     {
     posicionBase = anguloIngresado;
     Base.write(posicionBase);
     }

     else
     {
      Serial.println("Ingrese un ángulo entre 0 y 180 grados.");
     }
     
     break;

     case 'D':
     
     Serial.println("Usted ha ingresado el servo de la derecha.");

     if(anguloIngresado >= 40 && anguloIngresado <= 160)
     {
     posicionDerecha = anguloIngresado;
     Derecha.write(posicionDerecha);
     }

     else
     {
      Serial.println("Ingrese un ángulo entre 40 y 160 grados.");
     }
     
     break;

     case 'I':

      Serial.println("Usted ha ingre el servo de la izquierda.");

     if(anguloIngresado >=  90 && anguloIngresado <= 180)
     {
     posicionIzquierda = anguloIngresado;
     Izquierda.write(posicionIzquierda);
     }

     else
     {
      Serial.println("Ingrese un ángulo entre 90 y 180 grados.");
     }
     break;

     case 'M':
     Serial.println("Usted ha ingresado el servo de la mano.");
     if(anguloIngresado == 0 || anguloIngresado == 30)
     {
     posicionMano = anguloIngresado;
     Mano.write(posicionMano);
     }

     else
     {
      Serial.println("Digite 0 grados para abrir o 30 grados para cerrar.");
     }
     break;
     
     case 'A':

     Serial.println("Usted ha ingresado a forma automática");
     /*restablese pocicion*/ 

       Base.write(90);
       delay(500);

       Derecha.write(40);
       delay(500);

       Izquierda.write(140);
       delay(500);
  
       Mano.write(10);
       delay(500);
       
     /*Movimiento Automatico*/
     
     i=90;
     while (i>87){
     Base.write(i);
     delay(20);
     i--;
     }
     
     i=40;
     while(i<128){
     Derecha.write(i);
     delay(20);
     i++;
     }
     
     i=140;
     while(i>132){
     Izquierda.write(i);
     delay(20);
     i--;
     }
     
     
     Mano.write(30);
     delay(1000);

     while(i > 40)
     {
      Derecha.write(i);
      delay(20);
      i--;
     }

     i = 133;

     while(i < 140)
     {
      Izquierda.write(i);
      delay(20);
      i++;
     }
     
     i=87;
     while(i<180){
      Base.write(i);
     delay(20);
     i++;
     }

      Mano.write(0);
     delay(1000);
     break;
      
     case 'S':

     Serial.println("Restablecer posiciones de inicio");
     
      Base.write(90);
      delay(500);

      Derecha.write(40);
      delay(500);

      Izquierda.write(140);
      delay(500);
  
      Mano.write(10);
      delay(500);
      break;

     
      
    }
}
