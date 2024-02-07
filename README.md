# alarmaRiego
Para este proyecto necesitaremos de lo siguiente:
  -Tarjeta de arduinoUno o ESP32.
  -Bateria de unos 10.0000mAh con un conversor de voltaje limitado a 6v (en algunas pruebas a 5,7funciona sobradamente, y en otras placas a 6,2).
  -Modulo sim900 (version europea)
    -Debemos soldar el pin C13 para poder iniciar el modulo mediante software. Para ello deberiamos darle voltaje al pin 9, esperar 2 segundos y darle voltaje bajo   
    
    //Encendido placa
    delay(2000);
    digitalWrite(9,HIGH);
    delay(2000);
    digitalWrite(9,LOW);
    delay(10000); //Este delay es para que le de tiempo a iniciarse el modulo antes que el arduino
    //
