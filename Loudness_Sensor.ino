int val;
void setup()
{
  Serial.begin(9600);
  Serial.println("DBIT WSD 2020: LOUDNESS SENSOR");
}
void loop()
{
   analogRead(A0);
   delay(10);
   val = analogRead(A0);
   Serial.println(val);
   delay(200);
}
