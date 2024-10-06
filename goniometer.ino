/* 
 * CÓDIGO ARDUINO
 * GONIOMETRO:
 *    OBJETIVO:  MEDIR AL POTENCIOMETRO COMO UN ANGULO DE ABERTURA DE 0 A 180 GRADOS
 *               CALCULAR VELOCIDAD ANGULAR
 *               CALCULAR ACELERACIÓN ANGULAR
 * 
 * CONTROL DE MOTOR DE DC:
 *    OBJETIVO:  QUE UN MOTOR FUNCIONE DEPENDIENDO EL ANGULO DE ABERTURA.
 */

int pot=A3;    //POTENCIOMETRO EN PIN: A3
int x;         //VARIABLE QUE ALAMACENA: POSICIÓN DE POTENTENCIOMETRO, VARÍA DE 0 - 1024
int g;         //GRADOS
int w;         //VARIABLE QUE ALMACENA: VELOCIDAD ANGULAR

int i=0, j=0, k=0;  //VARIABLES CONTADORAS

int mot1=11, mot2=10; //PUENTE H
 
void setup() {
  Serial.begin(9600);   //COMUNICARSE CON MONITOR SERIAL
  pinMode(pot, INPUT);  
  pinMode(mot1, OUTPUT);
  pinMode(mot2, OUTPUT);
}

void loop() {
  
  x=analogRead(pot);    //ALMACENA POSICIÓN DE POTENCIMETRO
  motor();
  g= map(x, 0, 1024, 0, 270);
  Serial.println(g);    //ENVIA DATOS (SOLO DIGITOS NUMERICOS) AL MONITOR SERIE7
  Serial.flush();
}
/*
//****FUNCION DE VELOCIDAD ANGULAR****
int velocidad_angular_grados() { 
  int y, z;        //y, z: ALMACENAN VALOR DEL POTENCIOMETRO
  int g1, g2, s;   //g: grados, s: SEGUNDOS
  y=analogRead(pot);              //ALMACENA POSICIÓN DE POTENCIMETRO
  g2= map(y, 0, 1024, 0, 270);    //CALCULA GRADOS DE ABERTURA
  delay(999);                     //APROXIMA TIEMPO DE ESPERA A UN SEGUNDO
  z=analogRead(pot);              //ALMACENA POSICIÓN DE POTENCIMETRO
  g1= map(z, 0, 1024, 0, 270);   //CALCULA GRADOS DE ABERTURA

  i++;                  //SEGUNDOS QUE HAN PASADO 
  return abs(g1-g2);    //REGRESO VELOCIDAD ANGULAR POR SEGUNDO 
}

int velocidad_angular_radianes() {
  int y, z;
  int r1, r2, s;   //r: radianes, s: SEGUNDOS
  
  y=analogRead(pot);    //ALMACENA POSICIÓN DE POTENCIMETRO
  g2= (y)/1024;         //CALCULA FRACCIÓN QUE MULTIPLICA A PI
  delay(999);           //APROXIMA TIEMPO DE ESPERA A UN SEGUNDO
  z=analogRead(pot);    //ALMACENA POSICIÓN DE POTENCIMETRO
  g1= (z)/1024;         //CALCULA FRACCIÓN QUE MULTIPLICA A PI

  j++;                  //SEGUNDOS QUE HAN PASADO 
  return abs(g1-g2);   //REGRESO VELOCIDAD ANGULAR POR SEGUNDO 
}
*/
//****TERMINA FUNCION DE VELOCIDAD ANGULAR****

//****FUNCION DE ACELERACION ANGULAR****


//****TERMIANA FUNCION DE ACELERACION ANGULAR****

//****FUNCION DE MOTOR****
int motor(){
  int g;          //g: ALMACENA VALOR DE CONVERSION A GRADOS
  int vm1;        //vm1-"VELOCIDAD DE MOTOR-1": GIRO A LA IZQUIERDA
  int vm2;        //vm2-"VELOCIDAD DE MOTOR-2": GIRO A LA DERECHA
    
  g=map(x, 0, 1024, 0, 270); 
  vm1 = map(g, 90, 180, 0, 255);
  vm2 = map(g, 90, 0, 0, 255);
  
  if(g==90){
    analogWrite(mot1,0);
    analogWrite(mot2,0);
  } else {
    if (g>180){
      analogWrite(mot1,255);
    } else {
      if(g>90 && g<=180){ 
        analogWrite(mot1,vm1);
      } else {
         if(g<90){
            analogWrite(mot2,vm2);
         } 
      }
    }
  }
}
//****TERMINA FUNCION DE MOTOR****
/*
 * NOTAS:
 * FORUMULA DE VELOCIDAD ANGULAR:
 *    OBTENER EL ÁNGULO GIRADO POR UNIDAD DE TIEMPO. SE DA EN RADIANES O GRADOS 
 *    POR SEGUNDO.
 *    SE UTILIZARA "W" (UNIDAD == grado/seg || rad/s) 
 *           ( g2 - g1)
 *    w = abs(--------)  ABS == VALOR ABSOLUTO
 *           (   1s   )
 *       
 * FORMULA DE ACELERACIÓN ANGULAR:
 *    OBTENER CAMBIO QUE EXPERIMENTA LA VELOCIDAD ANGULAR POR UNIDAD DE TIEMPO. 
 *    SE EXPRESA EN RADIANES POR SEGUNDO AL CUADRADO
 *    SE UTILIZA "a" (UNIDAD == rad/s^2)
 *        vf - v°
 *    a = -------
 *           t
 * COMANDOS:
 * MAP: REGLA DE TRES
 */          
