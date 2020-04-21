void setup() 
{
  GD.begin();

   IDEMCU();

  pinMode(led0, OUTPUT);  digitalWrite(led0, HIGH);
  pinMode(led1, OUTPUT);  digitalWrite(led1, HIGH);
  pinMode(led2, OUTPUT);  digitalWrite(led2, HIGH);
  
  dht.begin();  LecturaDTH11();
  MP();
}

void loop(){}
