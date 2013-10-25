#include <Wire.h>

#define I2C_ADDRESS 16
void setup()
{
  byte error;
  
  Wire.begin();

  Serial.begin(9600);
  Serial.println("\ni2c Acc test");
  
  delay(100);

   // send wake up signal
  Wire.beginTransmission(I2C_ADDRESS); 
  Wire.write(0);
  Wire.write(0);
  error = Wire.endTransmission();
    
  if (error==4) 
    {
      Serial.print("Connection error");
    }     
    
  // allow time to start
  delay(200);

}


void loop()
{
  byte error;
 
    //set mode
    
    Wire.beginTransmission(I2C_ADDRESS); 
    Wire.write(1);
    error = Wire.endTransmission();

    // now get data 
    
    Wire.requestFrom(I2C_ADDRESS, 4); // read a byte
    while(Wire.available())
      {
      byte c = Wire.read(); 
      
      Serial.print(" :");
      Serial.print(c,HEX);         
      }
  Serial.println("");
  
  delay(1000);           
}
