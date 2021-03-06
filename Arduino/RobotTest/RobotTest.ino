#include <IRremote.h>

int receiverPin = 12;

int ENA = 10;
int ENB = 5;

// Right wheels
int IN1 = 9;
int IN2 = 8;

// Left wheels
int IN3 = 7;
int IN4 = 6;

int ABS = 130;

unsigned long RED;

#define A 16736925
#define B 16754775
#define X 16712445
#define C 16720605
#define D 16761405

IRrecv irrecv(receiverPin);
decode_results results;

// move forward
void _mForward()
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  pinMode(IN1, LOW);
  pinMode(IN2, HIGH);

  pinMode(IN3, LOW);
  pinMode(IN4, HIGH);

  Serial.println("go forward!");
}

// move backward
void _mBack()
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  pinMode(IN1, HIGH);
  pinMode(IN2, LOW);

  pinMode(IN3, HIGH);
  pinMode(IN4, LOW);

  Serial.println("go back!");
}

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(receiverPin, INPUT);
  Serial.begin(9600);
  _mStop();
  irrecv.enableIRIn();
  //digitalWrite(ENA,HIGH);
}

void _mStop()
{
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // digitalWrite(IN1,LOW);
  // digitalWrite(IN2,HIGH); // right wheel forward
  // delay(500);

  // digitalWrite(IN1,LOW);
  // digitalWrite(IN2,LOW); // right wheel stop
  // delay(500);

  // digitalWrite(IN1,HIGH);
  // digitalWrite(IN2,LOW); // right wheel back
  // delay(500);
  
  // digitalWrite(IN1,LOW);
  // digitalWrite(IN2,LOW); // right wheel stop 
  // delay(500);

  if(irrecv.decode(&results))
  {
    RED = results.value;
    Serial.println(RED);
    irrecv.resume();
    delay(150);
    
    if(RED == A)
    {
      _mForward();
    }
  
    if(RED == B)
    {
      _mBack();
    }
  
    if(RED == X)
    {
      _mStop();
    }
  }
}

