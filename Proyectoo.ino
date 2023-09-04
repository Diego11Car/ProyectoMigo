#include <WiFi.h>
#include <ESP32Servo.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

//Servos
Servo CodoD;
Servo CodoI;
Servo Cabeza;
Servo ManoD;
Servo ManoI;
int pinMD=12,pinMI=14,pinCD=27,pinCI=33,pinCA=32;
int pos2;
//Motores
int MotorD=0,MotorI=0;
int pinMD1=15,pinMD2=16,pwmMD=4,pinMI1=25,pinMI2=26,pwmMI=13;
int f=1000,canal1=10,canal2=11,res=8;

//Pantalla
int pinCS = 5;
int matrices=3;
Max72xxPanel matrix = Max72xxPanel(pinCS, matrices, 1);
void feli();
void sorprendido();
void fudioso();
void amor();
void tiste();
void diego();
void diego2();
void yad();
void guino();
void mimido();

const char* ssid     = "MIGO";//
const char* password = "jzxm9663";//
WiFiServer server(80);
int value = 0;
int modo=0;

int pin2 = 2;
void setup()
{
    matrix.setIntensity(4);
    CodoD.attach(pinCD,500,2500);
    CodoI.attach(pinCI,500,2500);
    Cabeza.attach(pinCA,500,2500);
    ManoD.attach(pinMD,500,2500);
    ManoI.attach(pinMI,500,2500);
    ledcSetup(canal1,f,res);
    ledcSetup(canal2,f,res);
    ledcAttachPin(pwmMD,canal1);
    ledcAttachPin(pwmMI,canal2);
    pinMode(pinMD1,OUTPUT);
    pinMode(pinMD2,OUTPUT);
    pinMode(pinMI1,OUTPUT);
    pinMode(pinMI2,OUTPUT);
    
    Serial.begin(115200);

    //Estos pines solo uso pa probar el codigo
    pinMode(12, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(27, OUTPUT);

    //Enciendo el pin2 pa comprobar que se establecio la conexion WiFi
    pinMode(pin2, OUTPUT);
    digitalWrite(pin2, LOW);
    delay(10);
    // Conexión a la red WiFi
    Serial.println();
    Serial.println();
    Serial.print("Conectando a ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Conectado a red Wifi.");
    Serial.println("Dirección IP ");
    Serial.println(WiFi.localIP());   
    server.begin();
    digitalWrite(pin2, HIGH);

    digitalWrite(pinMD1,LOW);
    digitalWrite(pinMD2,LOW);
    ledcWrite(canal1,150);  
    digitalWrite(pinMI1,LOW);
    digitalWrite(pinMI2,LOW);
    ledcWrite(canal2,190); 
    CodoD.write(5);
    CodoI.write(5);
    ManoD.write(5);
    ManoI.write(70);
    Cabeza.write(75);
    diego();
}

void loop(){
 
    leerBoton(); 
    delay(300);

    switch (modo){
    case 1:
      Serial.println("Up");
      digitalWrite(pinMD2,HIGH);
      digitalWrite(pinMD1,LOW);
      digitalWrite(pinMI2,HIGH);
      digitalWrite(pinMI1,LOW);
    break;
    case 2:
      Serial.println("Dowm");
      digitalWrite(pinMD2,LOW);
      digitalWrite(pinMD1,HIGH);
      digitalWrite(pinMI2,LOW);
      digitalWrite(pinMI1,HIGH);
    break;
    case 20:
      Serial.println("Derecha");
      digitalWrite(pinMD2,LOW);
      digitalWrite(pinMD1,HIGH);
      digitalWrite(pinMI2,HIGH);
      digitalWrite(pinMI1,LOW);
    break;
    case 21:
      Serial.println("Izquierda");
      digitalWrite(pinMD2,HIGH);
      digitalWrite(pinMD1,LOW);
      digitalWrite(pinMI2,LOW);
      digitalWrite(pinMI1,HIGH);
    break;
    case 22:
      Serial.println("Detener");
      digitalWrite(pinMD2,LOW);
      digitalWrite(pinMD1,LOW);
      digitalWrite(pinMI1,LOW);
      digitalWrite(pinMI2,LOW); 
    modo=9;
    break;
    case 4:
      Serial.println("saludar");
      feli();
      CodoD.write(5);
      CodoI.write(5);
      ManoI.write(70);
      Cabeza.write(75);
      
      for(int pos=5;pos<70;pos++){
        ManoD.write(pos);
        delay(10);
      }  
      for(int i=0;i<4;i++){
        for(int pos=70;pos>50;pos--){
          ManoD.write(pos);
          delay(15);
        }
        for(int pos=50;pos<70;pos++){
          ManoD.write(pos);
          delay(15);
        }  
      }
      for(int pos=70;pos>5;pos--){
        ManoD.write(pos);
        delay(10);
      }    
    modo=9; 
    break;

    case 5:
      Serial.println("bailar");
      feli();
      CodoD.write(5);
      CodoI.write(5);
      Cabeza.write(75); 
      delay(5000);
      guino();
      for(int pos=70;pos>5;pos--){
        ManoI.write(pos);
        delay(10);
      }    
      for(int i=0;i<5;i++){
        digitalWrite(pinMD1,HIGH);
        digitalWrite(pinMI2,HIGH);
        for(int pos=5;pos<70;pos++){
          ManoD.write(pos);
          ManoI.write(pos);
          delay(10);
          
        }
        digitalWrite(pinMD1,LOW);
        digitalWrite(pinMI2,LOW);
        digitalWrite(pinMD2,HIGH);
        digitalWrite(pinMI1,HIGH);
        for(int pos=70;pos>5;pos--){
          ManoD.write(pos);
          ManoI.write(pos);
          delay(10);
        }
        digitalWrite(pinMD2,LOW);
        digitalWrite(pinMI1,LOW);
      }
      diego();
      for(int pos=5;pos<90;pos++){
        CodoD.write(pos);
        CodoI.write(pos);
        delay(10);
      }  
      for(int i=0;i<5;i++){
        digitalWrite(pinMD2,HIGH);
        digitalWrite(pinMI2,HIGH);
        for(int pos=5;pos<70;pos++){
          ManoD.write(pos);
          ManoI.write(pos);
          delay(10);
          
        }
        digitalWrite(pinMD2,LOW);
        digitalWrite(pinMI2,LOW);
        digitalWrite(pinMD1,HIGH);
        digitalWrite(pinMI1,HIGH);
        for(int pos=70;pos>5;pos--){
          ManoD.write(pos);
          ManoI.write(pos);
          delay(10);
        }
        digitalWrite(pinMD1,LOW);
        digitalWrite(pinMI1,LOW);        
      }
      for(int pos=5;pos<70;pos++){
          ManoI.write(pos);
          delay(10);
      }
      for(int pos=90;pos>5;pos--){
        CodoD.write(pos);
        CodoI.write(pos);
        delay(10);
      }  
      amor();
      for(int i=0;i<5;i++){
        for(int pos=5;pos<70;pos++){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(10);
        }  
        for(int pos=70;pos>5;pos--){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(10);
        }
      }
      for(int i=0;i<3;i++){
        for(int pos=5;pos<70;pos++){
          ManoD.write(pos);
          delay(10);
        } 
        digitalWrite(pinMD1,HIGH);
        digitalWrite(pinMI2,HIGH);
        delay(1000);
        digitalWrite(pinMD1,LOW);
        digitalWrite(pinMI2,LOW);
        for(int pos=70;pos>5;pos--){
          ManoD.write(pos);
          ManoI.write(pos);
          delay(10);
        }
        digitalWrite(pinMD2,HIGH);
        digitalWrite(pinMI1,HIGH);     
        delay(1000);
        digitalWrite(pinMD2,LOW);
        digitalWrite(pinMI1,LOW);
        for(int pos=5;pos<70;pos++){
          ManoI.write(pos);
          delay(10);
        }
      guino();
      for(int pos=70;pos>5;pos--){
        ManoI.write(pos);
        delay(10);
      }    
      for(int i=0;i<5;i++){
        digitalWrite(pinMD1,HIGH);
        digitalWrite(pinMI2,HIGH);
        for(int pos=5;pos<70;pos++){
          ManoD.write(pos);
          ManoI.write(pos);
          delay(10);
        }
        digitalWrite(pinMD1,LOW);
        digitalWrite(pinMI2,LOW);
        digitalWrite(pinMD2,HIGH);
        digitalWrite(pinMI1,HIGH);
        for(int pos=70;pos>5;pos--){
          ManoD.write(pos);
          ManoI.write(pos);
          delay(10);
        }
        digitalWrite(pinMD2,LOW);
        digitalWrite(pinMI1,LOW);
      }
      }
    modo=9;     
    break;

    case 6:
      Serial.println("cantar");
      cantar1();
      for(int pos=65;pos<85;pos++){
        Cabeza.write(pos);
        delay(15);
      }  
      cantar2();
      for(int pos=85;pos>65;pos--){
        Cabeza.write(pos);
        delay(15);
      }
    break;

    case 7:
      Serial.println("juego");
    break;

    case 8:
      Serial.println("despedirse");
      tiste();
      CodoD.write(5);
      CodoI.write(5);
      Cabeza.write(75);
      for(int pos=5;pos<70;pos++){
        ManoD.write(pos);
        pos2=75-pos;
        ManoI.write(pos2);
        delay(10);
      }  
      for(int i=0;i<8;i++){
        for(int pos=70;pos>50;pos--){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }
        for(int pos=50;pos<70;pos++){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }  
      }
      for(int pos=70;pos>5;pos--){
        ManoD.write(pos);
        pos2=75-pos;
        ManoI.write(pos2);
        delay(10);
      }
      digitalWrite(pinMD2,HIGH);
      digitalWrite(pinMD1,LOW);
      digitalWrite(pinMI2,LOW);
      digitalWrite(pinMI1,HIGH);
      delay(500);
      digitalWrite(pinMD2,HIGH);
      digitalWrite(pinMD1,LOW);
      digitalWrite(pinMI2,HIGH);
      digitalWrite(pinMI1,LOW);
            for(int pos=5;pos<70;pos++){
        ManoD.write(pos);
        pos2=75-pos;
        ManoI.write(pos2);
        delay(10);
      }  
      for(int i=0;i<8;i++){
        for(int pos=70;pos>50;pos--){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }
        for(int pos=50;pos<70;pos++){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }  
      }
      for(int pos=70;pos>5;pos--){
        ManoD.write(pos);
        pos2=75-pos;
        ManoI.write(pos2);
        delay(10);
      }
      digitalWrite(pinMD2,LOW);
      digitalWrite(pinMD1,LOW);
      digitalWrite(pinMI1,LOW);
      digitalWrite(pinMI2,LOW); 
    modo=9;    
    break;

    case 9:
      Serial.println("parar");
      mimido();
      digitalWrite(pinMD1,LOW);
      digitalWrite(pinMD2,LOW);
      ledcWrite(canal1,170);  
      digitalWrite(pinMI1,LOW);
      digitalWrite(pinMI2,LOW);
      ledcWrite(canal2,170); 
      CodoD.write(5);
      CodoI.write(5);
      ManoD.write(5);
      ManoI.write(70);
      Cabeza.write(75);
    break;

    case 10:
      Serial.println("juego1");
      amor();
      delay(3000);
      for(int pos=5;pos<70;pos++){
        ManoD.write(pos);
        pos2=75-pos;
        ManoI.write(pos2);
        delay(10);
      }  
      for(int i=0;i<3;i++){
        for(int pos=70;pos>50;pos--){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }
        for(int pos=50;pos<70;pos++){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }  
      }
      for(int pos=70;pos>5;pos--){
        ManoD.write(pos);
        pos2=75-pos;
        ManoI.write(pos2);
        delay(10);
      }  
    modo=9;
    break;

    case 11:
      Serial.println("juego2");
      diego2();
      delay(3000);
      for(int i=0;i<4;i++){
        for(int pos=5;pos<25;pos++){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }         
        for(int pos=25;pos>5;pos--){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        } 
      }
    modo=9; 
    break;

    case 12:
      Serial.println("juego3");
      diego();
      delay(3000);
      for(int pos=5;pos<70;pos++){
        ManoD.write(pos);
        pos2=75-pos;
        ManoI.write(pos2);
        delay(10);
      }  
      for(int pos=5;pos<90;pos++){
        CodoD.write(pos);
        CodoI.write(pos+10);
        delay(10);
      }  
      for(int i=0;i<3;i++){
        for(int pos=70;pos>50;pos--){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }
        for(int pos=50;pos<70;pos++){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }  
      }
      for(int pos=90;pos>5;pos--){
        CodoD.write(pos);
        CodoI.write(pos+10);
        delay(10);
      }  
      for(int pos=70;pos>5;pos--){
        ManoD.write(pos);
        pos2=75-pos;
        ManoI.write(pos2);
        delay(10);
      }
    modo=9; 
    break;

    case 13:
      Serial.println("juego4");
      guino();
      delay(3000);
      for(int pos=5;pos<90;pos++){
        CodoD.write(pos);
        CodoI.write(pos+10);
        delay(10);
      }  
      for(int i=0;i<3;i++){
        for(int pos=5;pos<25;pos++){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }        
        for(int pos=25;pos>5;pos--){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }
      }
      for(int pos=90;pos>5;pos--){
        CodoD.write(pos);
        CodoI.write(pos+10);
        delay(10);
      }  
    modo=9;  
    break;

    case 14:
      Serial.println("juego5");
      delay(3000);
      digitalWrite(pinMD2,HIGH);
      digitalWrite(pinMI2,HIGH);
      delay(1000);
      digitalWrite(pinMD2,LOW);
      digitalWrite(pinMI2,LOW);
    modo=9; 
    break;

    case 15:
      Serial.println("juego6");
      delay(3000);
      digitalWrite(pinMD1,HIGH);
      digitalWrite(pinMI1,HIGH);
      delay(1000);
      digitalWrite(pinMD1,LOW);
      digitalWrite(pinMI1,LOW);  
    modo=9; 
    break;

    case 16:
      Serial.println("juego7");
      feli();
      delay(3000);
      for(int pos=5;pos<70;pos++){
        ManoD.write(pos);
        pos2=75-pos;
        ManoI.write(pos2);
        delay(10);
      }  
      for(int i=0;i<5;i++){
        for(int pos=70;pos>50;pos--){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }
        for(int pos=50;pos<70;pos++){
          ManoD.write(pos);
          pos2=75-pos;
          ManoI.write(pos2);
          delay(15);
        }  
      }
      for(int pos=70;pos>5;pos--){
        ManoD.write(pos);
        pos2=75-pos;
        ManoI.write(pos2);
        delay(10);
      }  
    modo=9;
    break;

    case 17:
      Serial.println("juego8");
      cantar2();
      delay(5000);
      cantar1();
      delay(5000);
    modo=9; 
    break;


    default:
      Serial.println("no has presionado nada");
    break;

  }
}
void leerBoton(){
 WiFiClient client = server.available();   // Escuchando a los clientes entrantes
  if (client) {                             // Si hay un cliente,
    //Serial.println("Nuevo cliente");        // Imprime un mensaje en el puerto serie
    String currentLine = "";                // String para contener datos entrantes del cliente
    while (client.connected()) {            // Bucle mientras el cliente está conectado
      if (client.available()) {             // Si hay bytes para leer del cliente,
        char c = client.read();             // Lee un caracter
        //Serial.write(c);                    // Lo imprimimos en el monitor serial
        if (c == '\n') {                    // Si el byte es un carácter de nueva línea        
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            // Salir del ciclo while:
            break;
          } else {    // si tienes una nueva línea, borra currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }

              //Aqui van las lecturas de los botones 
          //El robot avanza hacia adelante (MODO 1)
        if (currentLine.endsWith("GET /up")) {
          modo=1;
        }
        //El robot va hacia atras (MODO 2)
        if (currentLine.endsWith("GET /down")) {
          modo=2;
        }
        if (currentLine.endsWith("GET /right")) {
          modo=20;
        }
        if (currentLine.endsWith("GET /left")) {
          modo=21;
        }
        //El robot se detiene (apaga los motores) (MODO 3)
        if (currentLine.endsWith("GET /stop")) {
          modo=22;      
        }
        //Aqui va la secuencia del saludo (MODO 4)
        if (currentLine.endsWith("GET /saludar")) {
            modo=4;               
        }
        //Aqui va la secuencia del baile (MODO 5)
        if (currentLine.endsWith("GET /bailar")) {
            modo=5;
        }

        //Aqui va la secuencia del canto (MDOO 6)
        if (currentLine.endsWith("GET /cantar")) {
            modo=6;               
        }

        //Aqui va la secuencia del juego (MODO 7)
        if (currentLine.endsWith("GET /juego")) {
            modo=7;               
        }

        //Aqui va la secuencia para despedirse (MODO 8)
        if (currentLine.endsWith("GET /despedirse")) {
            modo=8;               
        }
        if (currentLine.endsWith("GET /parar")) {
            modo=9;               
        } 
        if (currentLine.endsWith("GET /j1")) {
            modo=10;               
        } 
        if (currentLine.endsWith("GET /j2")) {
            modo=11;               
        } 
        if (currentLine.endsWith("GET /j3")) {
            modo=12;               
        } 
        if (currentLine.endsWith("GET /j4")) {
            modo=13;               
        } 
        if (currentLine.endsWith("GET /j5")) {
            modo=14;               
        } 
        if (currentLine.endsWith("GET /j6")) {
            modo=15;               
        } 
        if (currentLine.endsWith("GET /j7")) {
            modo=16;               
        } 
        if (currentLine.endsWith("GET /j8")) {
            modo=17;               
        } 

        
      }
    }
    // Cierra la conexión
    client.stop();
    //Serial.println("Cliente desconectado");
  }


}
void feli(){
  matrix.fillScreen(0);
  //ojos ^^
  matrix.drawPixel(4, 1, 1);
  matrix.drawLine(3,2,5,2, 1);
  matrix.drawLine(2,3,3,3, 1);
  matrix.drawLine(5,3,6,3, 1);

  matrix.drawPixel(12, 1, 1);
  matrix.drawLine(11,2,13,2, 1);
  matrix.drawLine(10,3,11,3, 1);
  matrix.drawLine(13,3,14,3, 1);
  //boca D
  matrix.drawLine(17,3,22,3, 1);
  matrix.drawLine(18,4,21,4, 1);
  matrix.drawLine(19,5,20,5, 1);
  matrix.write();
}
void sorprendido(){
  matrix.fillScreen(0);
  matrix.fillCircle(4,4,2,1);
  matrix.fillCircle(12,4,2,1);
  //boca
  matrix.drawLine(19,1,20,1, 1);
  matrix.fillRect(18,2,4,4,1);
  matrix.drawLine(19,6,20,6, 1);
  matrix.write();
}
void fudioso(){
  matrix.fillScreen(0);
  matrix.drawLine(3,1,5,3, 1);
  matrix.drawLine(4,1,6,3, 1);
  matrix.drawLine(2,4,4,4, 1);
  matrix.drawLine(1,5,3,5, 1);
  matrix.drawPixel(5, 5, 1);
  matrix.drawLine(2,6,4,6, 1);

  matrix.drawLine(9,3,11,1, 1);
  matrix.drawLine(10,3,12,1, 1);
  matrix.drawLine(11,4,13,4, 1);
  matrix.drawLine(12,5,14,5, 1);
  matrix.drawPixel(10, 5, 1);
  matrix.drawLine(11,6,13,6, 1);
  //boca
  matrix.drawRect(17,4,6,2, 1);
  matrix.write();
}
void amor(){
  matrix.fillScreen(0);
  matrix.drawLine(2,1,3,1, 1);
  matrix.drawLine(5,1,6,1, 1);
  matrix.drawLine(1,2,7,2, 1);
  matrix.fillTriangle(1,3,4,6,7,3,1);

  matrix.drawLine(10,1,11,1, 1);
  matrix.drawLine(13,1,14,1, 1);
  matrix.drawLine(9,2,15,2, 1);
  matrix.fillTriangle(9,3,12,6,15,3,1);
  //boca
  matrix.drawLine(16,4,17,5, 1);
  matrix.drawLine(18,6,21,6, 1);
  matrix.drawLine(22,5,23,4, 1);
  matrix.write();
}
void tiste(){
  matrix.fillScreen(0);
  matrix.drawLine(3,2,4,2, 1);
  matrix.drawLine(2,3,5,3, 1);
  matrix.drawLine(3,4,4,4, 1);
  matrix.drawLine(1,5,1,6, 1);
  matrix.drawLine(0,6,0,7, 1);

  matrix.drawLine(11,2,12,2, 1);
  matrix.drawLine(10,3,13,3, 1);
  matrix.drawLine(11,4,12,4, 1);
  matrix.drawLine(14,5,14,6, 1);
  matrix.drawLine(15,6,15,7, 1);
  //boca
  matrix.drawLine(19,1,20,1, 1);
  matrix.fillRect(18,2,4,5, 1);
  matrix.write();
}
void diego(){
  matrix.fillScreen(0);
  matrix.fillRect(1,2,14,3, 1);
  matrix.fillRect(17,3,6,2, 1);
   matrix.write();
}
void diego2(){
  matrix.fillScreen(0);
  matrix.fillRect(1,2,6,2, 1);
  matrix.fillRect(9,2,6,2, 1);
  matrix.fillRect(17,3,6,2, 1);
   matrix.write();
}
void yad(){
  //aqui empieza el mensaje de te amo
  //Draw Text print on display
  String my_string = "Te Amo Yadi--Eres de David ";   // This text will be displayed, a letter a time
  //Draw scrolling text
 int spacer = 1;                            // This will scroll the string
 int width = 5 + spacer;                    // The font width is 5 pixels
 for ( int i = 0 ; i < width * my_string.length() + width - 1 - spacer; i++ ) {

    matrix.fillScreen(0);

    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2; // center the text vertically

    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < my_string.length()) {
        matrix.drawChar(x-12, y, my_string[letter], 1, 0, 1);
      }

      letter--;
      x -= width;
    }
     
  matrix.drawLine(18,1,19,1, 1);
  matrix.drawLine(21,1,22,1, 1);
  matrix.drawLine(17,2,23,2, 1);
  matrix.fillTriangle(17,3,20,6,23,3,1);
  matrix.write(); // Send bitmap to display
    delay(100);
  }
}
void guino(){
  
  //Circle print on display
  for (int i=2;i>=0;i--)              // This loop produces a circle that
  {                                  // shrinks
  matrix.fillScreen(0);    
  matrix.fillCircle(4,4,i,1);
  matrix.fillCircle(12,4,2,1);
  //boca D
  matrix.drawLine(17,3,22,3, 1);
  matrix.drawLine(18,4,21,4, 1);
  matrix.drawLine(19,5,20,5, 1);
  matrix.write();
  delay(75);
  }
  matrix.fillScreen(0); 
  matrix.drawPixel(4, 3, 1);
  matrix.drawLine(3,4,5,4, 1);
  matrix.drawLine(2,5,3,5, 1);
  matrix.drawLine(5,5,6,5, 1);
  matrix.fillCircle(12,4,2,1);
  //boca D
  matrix.drawLine(17,3,22,3, 1);
  matrix.drawLine(18,4,21,4, 1);
  matrix.drawLine(19,5,20,5, 1);
  matrix.write();
}
void mimido(){
  matrix.fillScreen(0);
  matrix.drawPixel(1, 3, 1);
  matrix.drawLine(2,4,6,4, 1);
  matrix.drawPixel(7, 3, 1);

  matrix.drawPixel(9, 3, 1);
  matrix.drawLine(10,4,14,4, 1);
  matrix.drawPixel(15, 3, 1);

  matrix.drawLine(18,4,21,4, 1);
  matrix.write();
}
void cantar1()
{
  //1
  matrix.fillScreen(0);
  //ojos ^^
  matrix.drawPixel(4, 1, 1);
  matrix.drawLine(3,2,5,2, 1);
  matrix.drawLine(2,3,3,3, 1);
  matrix.drawLine(5,3,6,3, 1);

  matrix.drawPixel(12, 1, 1);
  matrix.drawLine(11,2,13,2, 1);
  matrix.drawLine(10,3,11,3, 1);
  matrix.drawLine(13,3,14,3, 1);
  //boca cantando
  matrix.fillRect(19,2,2,1, 1);
  matrix.fillRect(17,3,6,3, 1);
  matrix.fillRect(19,6,2,1, 1);
  matrix.write();
}void cantar2()
{
  //2
  matrix.fillScreen(0);
  //ojos ^^
  matrix.drawPixel(4, 1, 1);
  matrix.drawLine(3,2,5,2, 1);
  matrix.drawLine(2,3,3,3, 1);
  matrix.drawLine(5,3,6,3, 1);

  matrix.drawPixel(12, 1, 1);
  matrix.drawLine(11,2,13,2, 1);
  matrix.drawLine(10,3,11,3, 1);
  matrix.drawLine(13,3,14,3, 1);
  //boca cantando
  matrix.fillRect(19,3,2,1, 1);
  matrix.fillRect(17,4,6,1, 1);
  matrix.fillRect(19,5,2,1, 1);
  matrix.write();
}


