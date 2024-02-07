#include <SoftwareSerial.h> //Libreria obtenida de repositorio de github. La default produce falla en el sensor sim900A. (a no ser que se actualice firmware)
SoftwareSerial SIM900(7,8); //Configuracion de los pines por software.


//Creamos funcion delay para evitar posibles fallos
void delay_eco(unsigned long milisegundos) {
    unsigned long instanteInicial = millis();             // Guardamos el instante en que se comienza a esperar
    while (millis() - instanteInicial < milisegundos) {   // Mientras no haya transcurrido el tiempo estipulado ...
        if (Serial.available()) {                         // Se mira a ver si se ha recibido algún dato y está pendiente de leer
            Serial.write(Serial.read());                  // Si se ha recibido algún dato, se lee y se manda
        }
    }
}

void setup() {
// put your setup code here, to run once:
    SIM900.begin(19200); // Arduino se comunica con SIM900 a una velocidad de 19200bps
    Serial.begin(19200); // Velocidad del puerto serial de arduino
    delay_eco(2000); //Tiempo prudencial para que el shield inicie sesion de red con el operador. Con buena disponibilidad un delay de 2000 es suficiente. 25000 cuando la cobertura es pobre
    hacerLlamada(); //Llama a la funcion hacerLlamada

}

//Funcion Hacer llamada.
//Hardcodeada para realizar las pruebas pertinentes. 
void hacerLlamada(){
  SIM900.println("AT + CPIN = \"7777\""); //Comando AT para introducir el PIN de la tarjeta. En este caso hardcodeamos el codigo PIN de la SIM
  delay_eco(5000);
  SIM900.print("ATD"); //Comando AT para inciar una llamada
  SIM900.print("6372XXXX6"); //Numero de telefono al cual queremos llamar
  SIM900.print(";"); // El ";" indica llamnada de voz y no llamada de datos ej:(FAX)
  Serial.println("Llamando..."); //Indica que se inicio el llamado
  delay_eco(25000); //Duracion de la llamado antes de cortar
  SIM900.println("ATH"); //Comando AT cortar llamada
  Serial.println("Llamada finalizada"); //Indica que finalizo la llamada
  
}



void loop() {
  // put your main code here, to run repeatedly:

}
