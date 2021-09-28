
const int LEFT=9;
const int MIDR=10;
const int RIGHT=11;
const int LEFTM=32;
const int MIDRM=34;
const int RIGHTM=36;

int curcounter;
//H1

//M1
const int EA=7;
const int M1=6;
const int M2=5;
//M2
const int EB=2;
const int M3=3;
const int M4=4;


//H-2

//MOTOR 3

const int EC=22;
const int M5=23;
const int M6=24;

//MOTOR4
const int ED=25;
const int M7=26;
const int M8=27;


int val1=0,val2=0,val3=0,val4=0,val5=0,val6=0,val7=0;

int count=0;
int currentcount=0;
int previouscount=0;
void setup(){
  Serial.begin(9600);
pinMode(LEFT,INPUT);
pinMode(MIDR,INPUT);
pinMode(RIGHT,INPUT);
pinMode(LEFTM,INPUT);
pinMode(MIDRM,INPUT);
pinMode(RIGHTM,INPUT);
//H1
pinMode(M1,OUTPUT);
pinMode(M2,OUTPUT);
pinMode(M3,OUTPUT);
pinMode(M4,OUTPUT);
pinMode(EA,OUTPUT);
pinMode(EB,OUTPUT);
//H2
pinMode(M5,OUTPUT);
pinMode(M6,OUTPUT);
pinMode(M7,OUTPUT);
pinMode(M8,OUTPUT);
pinMode(EC,OUTPUT);
pinMode(ED,OUTPUT);

}
//FUNCTIONS

void moveforward()
  {  //H-1
    digitalWrite(M1,HIGH);
    digitalWrite(M2,LOW);   
    digitalWrite(M3,LOW);   
    digitalWrite(M4,HIGH);
    analogWrite(EA,250);
    analogWrite(EB,250);
    //H-2
    digitalWrite(M5,HIGH);
    digitalWrite(M6,LOW);   
    digitalWrite(M7,HIGH);   
    digitalWrite(M8,LOW);
    analogWrite(EC,250);
    analogWrite(ED,250);
    }
      void back()
  {  //H-1
    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);   
    digitalWrite(M3,HIGH);   
    digitalWrite(M4,LOW);
    analogWrite(EA,250);
    analogWrite(EB,250);
    //H-2
    digitalWrite(M5,LOW);
    digitalWrite(M6,HIGH);   
    digitalWrite(M7,LOW);   
    digitalWrite(M8,HIGH);
    analogWrite(EC,250);
    analogWrite(ED,250);
    }
void turnright()
  {  //H-1
    digitalWrite(M1,HIGH);
    digitalWrite(M2,LOW);   
    digitalWrite(M3,LOW);   
    digitalWrite(M4,HIGH);
    analogWrite(EA,250);
    analogWrite(EB,250);
    //H-2
     digitalWrite(M5,LOW);
    digitalWrite(M6,HIGH);   
    digitalWrite(M7,LOW);   
    digitalWrite(M8,HIGH);
    analogWrite(EC,250);
    analogWrite(ED,250);
  }
void turnleft()
  {  //H-1
    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);   
    digitalWrite(M3,HIGH);   
    digitalWrite(M4,LOW);
    analogWrite(EA,250);
    analogWrite(EB,250);
    //H-2
   digitalWrite(M5,HIGH);
    digitalWrite(M6,LOW);   
    digitalWrite(M7,HIGH);   
    digitalWrite(M8,LOW);
    analogWrite(EC,250);
    analogWrite(ED,250);
    }
    void stop1()
  {  //H-1
    digitalWrite(M1,LOW);
    digitalWrite(M2,LOW);   
    digitalWrite(M3,LOW);   
    digitalWrite(M4,LOW);
    analogWrite(EA,0);
    analogWrite(EB,0);
    //H-2
    digitalWrite(M5,LOW);
    digitalWrite(M6,LOW);   
    digitalWrite(M7,LOW);   
    digitalWrite(M8,LOW);
    analogWrite(EC,0);
    analogWrite(ED,0);
    }
    void stop2()
  {  //H-1
    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);   
    digitalWrite(M3,HIGH);   
    digitalWrite(M4,LOW);
    analogWrite(EA,250);
    analogWrite(EB,250);
    //H-2
    digitalWrite(M5,LOW);
    digitalWrite(M6,HIGH);   
    digitalWrite(M7,HIGH);   
    digitalWrite(M8,LOW);
    analogWrite(EC,250);
    analogWrite(ED,250);
    delay(15);
      
//delay(10);
  }
void countrd(){
  val1=digitalRead(LEFT);

val2=digitalRead(MIDR);

val3=digitalRead(RIGHT);
 val4=digitalRead(LEFTM);

val5=digitalRead(MIDRM);

val6=digitalRead(RIGHTM);


  if ((val4==LOW)&&(val5==LOW)&&( val6==LOW))
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
action();
}

track();
 
  }
  void action(){

   if (count==1)
 { 
  moveforward();
Serial.println("one");
    }
  

 if (count==2)
 { 
 turnleft();
   Serial.println("two ");
 }


  /* if (count==3)

 { 
 moveforward();
   Serial.println("three ");}
   

 
  if (count==4)
  { 
moveforward();
   Serial.println("Four");
 }
 if (count==5)
  { 
moveforward();
   Serial.println("Five");
 }
  if (count==6)
  { 
turnright();
   Serial.println("Five");
 }*/
  }
void track()
{
     val1=digitalRead(LEFT);
     val2=digitalRead(MIDR);
     val3=digitalRead(RIGHT);
     

  if ((val1==HIGH) && (val2==LOW)&&(val3==HIGH))
  {
      moveforward();
      Serial.println("moveforward");
  }
if ((val1==HIGH) && (val2==HIGH)&&(val3==LOW))
  {
      turnright();
      Serial.println("right");
  }
  if ((val1==LOW) && (val2==HIGH)&&(val3==HIGH))
  {
     
      turnleft(); 
      Serial.println("left");
  }

   if ((val1==LOW) && (val2==LOW)&&(val3==HIGH))
  {  turnleft();
      Serial.println("left");
   
  }
   if ((val1==HIGH) && (val2==LOW)&&(val3==LOW))
  {     turnright();
      Serial.println("right");  
      
  }
  
  }
void loop() {
  // put your main code here, to run repeatedly/
 // track();
 countrd(); 
 
//moveforward();
//delay(1000);
//turnleft();
//delay(1000);
//turnright();
//delay(1000);
//stop2();


}

