#include <Wire.h>

#define I2C_ADDRESS 16
void setup()
{
  byte error;
  
  Wire.begin();

  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
  
  delay(100);

    
    // send wake up signal
    Wire.beginTransmission(I2C_ADDRESS); 
    Wire.write(0);
    Wire.write(0);
    error = Wire.endTransmission();
     delay(200);
    
}


void loop()
{
  byte error;
 
    
    //ask for data
    
    Wire.beginTransmission(I2C_ADDRESS); 
    Wire.write(1);
    error = Wire.endTransmission();

    // now receive data 
    Wire.requestFrom(I2C_ADDRESS, 4); // read a byte
    while(Wire.available())
      {
      byte c = Wire.read(); // receive byte as a character
      
      Serial.print(" :");
      Serial.print(c,HEX);         // print the character
      }
  Serial.println("");
  delay(1000);           // wait 5 seconds for next scan
}
