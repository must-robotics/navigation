const int LEFT=3;
const int MIDR=4;
const int RIGHT=5 ;


int val1=0,val2=0,val3=0;
int count=0;
int currentcount=0;
int previouscount=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LEFT,INPUT);

pinMode(MIDR,INPUT);



pinMode(RIGHT,INPUT);

}

void loop() {
val1=digitalRead(LEFT);

val2=digitalRead(MIDR);

val3=digitalRead(RIGHT);
 
  if ((val1==LOW)&&(val2==LOW)&&( val3==LOW))
{
currentcount=1;
}
 
else {
  currentcount=0;
  }

if (currentcount != previouscount)
{
  
  if (currentcount == 1)
  {
    count=count+1;
    Serial.println(count);
  }

previouscount=currentcount;
delay(100);
}



 if (count==1)
 {   Serial.println("foward");
  }
 if (count==2)
 {  //turnright();
   Serial.println("right");
 }
  if (count==3)
 { 
 //turnright();
   Serial.println("left");
 }
 if (count==4)
 { 
//turnright();
   Serial.println("back");
 }
 if (count==5)
 { 

  //turnright();
   Serial.println("five");
 }
}
  
   

  // put your main code here, to run repeatedly:


