/* 
 * ARDUINO CODE
 * GONIOMETER:
 *    PURPOSE:  MEASURE THE POTENTIOMETER AS AN ANGLE FROM 0 TO 180 DEGREES,
 *              CALCULATE ANGULAR VELOCITY,
 *              CALCULATE ANGULAR ACCELERATION
 *
 * DC MOTOR CONTROL:
 *    PURPOSE:  OPERATE A MOTOR BASED ON THE OPENING ANGLE.
 */

int pot = A3;      // POTENTIOMETER PIN: A3
int x;             // VARIABLE THAT STORES THE POTENTIOMETER POSITION (0 - 1024)
int g;             // ANGLE IN DEGREES
int w;             // VARIABLE THAT STORES THE ANGULAR VELOCITY

int i = 0, j = 0, k = 0;  // COUNTER VARIABLES

int mot1 = 11, mot2 = 10; // H-BRIDGE PINS

void setup() {
  Serial.begin(9600);   // INITIALIZE SERIAL COMMUNICATION
  pinMode(pot, INPUT);
  pinMode(mot1, OUTPUT);
  pinMode(mot2, OUTPUT);
}

void loop() {
  x = analogRead(pot);    // READ THE POTENTIOMETER POSITION
  motor();
  g = map(x, 0, 1024, 0, 270);  // CONVERT THE POTENTIOMETER VALUE TO DEGREES (0 - 270)
  Serial.println(g);      // SEND THE DATA (NUMERIC VALUES ONLY) TO THE SERIAL MONITOR
  Serial.flush();
}

/*
//**** ANGULAR VELOCITY FUNCTION (DEGREES) ****
int velocidad_angular_grados() { 
  int y, z;         // y, z: STORE THE POTENTIOMETER VALUE
  int g1, g2, s;    // g1, g2: ANGLE IN DEGREES; s: SECONDS
  y = analogRead(pot);             // READ THE POTENTIOMETER POSITION
  g2 = map(y, 0, 1024, 0, 270);      // CALCULATE THE OPENING ANGLE
  delay(999);                      // WAIT APPROXIMATELY ONE SECOND
  z = analogRead(pot);             // READ THE POTENTIOMETER POSITION AGAIN
  g1 = map(z, 0, 1024, 0, 270);      // CALCULATE THE OPENING ANGLE AGAIN

  i++;                   // INCREMENT THE SECONDS COUNTER
  return abs(g1 - g2);   // RETURN THE ANGULAR VELOCITY (DEGREES PER SECOND)
}

int velocidad_angular_radianes() {
  int y, z;
  int r1, r2, s;   // r1, r2: ANGLE IN RADIANS; s: SECONDS
  
  y = analogRead(pot);    // READ THE POTENTIOMETER POSITION
  g2 = (y) / 1024;        // CALCULATE THE FRACTION THAT MULTIPLIES PI
  delay(999);             // WAIT APPROXIMATELY ONE SECOND
  z = analogRead(pot);    // READ THE POTENTIOMETER POSITION AGAIN
  g1 = (z) / 1024;        // CALCULATE THE FRACTION THAT MULTIPLIES PI

  j++;                   // INCREMENT THE SECONDS COUNTER
  return abs(g1 - g2);   // RETURN THE ANGULAR VELOCITY (RADIANS PER SECOND)
}
//**** END OF ANGULAR VELOCITY FUNCTIONS ****
*/

//**** ANGULAR ACCELERATION FUNCTION ****


//**** END OF ANGULAR ACCELERATION FUNCTION ****

//**** MOTOR FUNCTION ****
int motor(){
  int g;          // g: STORES THE ANGLE VALUE (IN DEGREES)
  int vm1;        // vm1 - "MOTOR-1 SPEED": ROTATION TO THE LEFT
  int vm2;        // vm2 - "MOTOR-2 SPEED": ROTATION TO THE RIGHT

  g = map(x, 0, 1024, 0, 270);
  vm1 = map(g, 90, 180, 0, 255);
  vm2 = map(g, 90, 0, 0, 255);

  if(g == 90){
    analogWrite(mot1, 0);
    analogWrite(mot2, 0);
  } else {
    if (g > 180){
      analogWrite(mot1, 255);
    } else {
      if(g > 90 && g <= 180){
        analogWrite(mot1, vm1);
      } else {
         if(g < 90){
            analogWrite(mot2, vm2);
         }
      }
    }
  }
}
//**** END OF MOTOR FUNCTION ****

/*
 * NOTES:
 * ANGULAR VELOCITY FORMULA:
 *    OBTAIN THE ANGLE ROTATED PER UNIT OF TIME, GIVEN IN RADIANS OR DEGREES PER SECOND.
 *    WE USE "W" (UNIT == degrees/sec or rad/s)
 *           ( g2 - g1 )
 *    w = abs(--------)  where abs() denotes the ABSOLUTE VALUE
 *           (   1s   )
 *
 * ANGULAR ACCELERATION FORMULA:
 *    OBTAIN THE CHANGE IN ANGULAR VELOCITY PER UNIT OF TIME.
 *    IT IS EXPRESSED IN RADIANS PER SECOND SQUARED.
 *    WE USE "a" (UNIT == rad/s^2)
 *        vf - v0
 *    a = -------
 *           t
 *
 * COMMANDS:
 * MAP: (PERFORMS A LINEAR MAPPING, AKA THE RULE OF THREE)
 */
