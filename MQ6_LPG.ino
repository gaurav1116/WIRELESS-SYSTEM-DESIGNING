void setup()
{
  Serial.begin(9600);
  Serial.println("DBIT WSD 2020: MQ6 LPG SENSOR");
}
 
void loop()
{
  float sensorVoltage;
  float sensorValue;
 
  sensorValue = analogRead(A0);
  sensorVoltage = sensorValue/1024*5.0;
 
  Serial.print("sensor voltage = ");
  Serial.print(sensorVoltage);
  Serial.println(" V");
  delay(1000);
}
