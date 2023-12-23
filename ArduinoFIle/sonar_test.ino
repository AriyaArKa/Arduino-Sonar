const int echo = A1;
const int trig = A3;

long duration;
int distance;

void setup()
{
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);

  distance = (duration*0.034)/2;

  Serial.print("Distance is : ");
  Serial.print(distance);
  Serial.println("cm");
  delay(500);
 }
