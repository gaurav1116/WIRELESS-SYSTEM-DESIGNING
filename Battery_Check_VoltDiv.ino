float A1_voltage; //Voltage at Voltage Divider network
float battery_voltage; //Battery Voltage

void setup()
{
    Serial.begin(9600);
    pinMode(A1, INPUT); //LM35_Working at 3.3V_Should have been 4V+
    Serial.println("DBIT WSD 2020: BATTERY VOLTAGE CHECK: RESISTOR DIVIDER NETWORK");
}
 
void loop()
{
    A1_voltage = (analogRead(A1) * 3.3 / 1024); //WILL DEPEND ON VCC, EITHER 3.3 OR 5V
    Serial.print("A1_voltage: ");
    Serial.println(A1_voltage);

    battery_voltage = ((A1_voltage * 3) / (1)); //WILL DEPEND ON RESISTOR VALUES
    Serial.print("Battery_Voltage: ");
    Serial.println(battery_voltage);

    uint32_t batteryV = battery_voltage * 100;
    
    byte payload[2];
    payload[0] = highByte(batteryV);
    payload[1] = lowByte(batteryV);

    Serial.println(payload[0]);
    Serial.println(payload[1]);
    
    delay(1000);
}
