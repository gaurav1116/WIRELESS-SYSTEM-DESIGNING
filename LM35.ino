float A0_voltage; //LM35
float tempc; //Temp in Celcius

void setup()
{
    Serial.begin(9600);
    pinMode(A0, INPUT); //LM35_Working at 3.3V_Should have been 4V+
    Serial.println("DBIT WSD 2020: LM35 TEMPERATURE SENSOR");
}
 
void loop()
{
    A0_voltage = analogRead(A0); //Reading the value from LM35 sensor
    A0_voltage = (A0_voltage * 500) / 1023;
    tempc = A0_voltage; // Storing value in Degree Celsius
    Serial.print("Temp in DegreeC= ");
    Serial.println(tempc);

    uint32_t temp = tempc * 100;
    byte payload[4];
    payload[0] = highByte(temp);
    payload[1] = lowByte(temp);

    Serial.println(payload[0]);
    Serial.println(payload[1]);
    
    delay(1000);
}
