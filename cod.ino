const int dataPin = 34;   // Q7 
const int clockPin = 25;  // CP 
const int latchPin = 26;  // PL

const int numBits = 9;   // Set to 9 * number of shift registers 

#define DATA_PIN  18  // Pin connected to DS of 74HC595
#define LATCH_PIN 19  // Pin connected to STCP of 74HC595
#define CLOCK_PIN 21 // Pin connected to SHCP of 74HC595

// How many of the shift registers
#define NUM_SHIFT_REGS 2

const uint8_t numOfRegisterPins = NUM_SHIFT_REGS * 8;

bool registers[numOfRegisterPins];
void setup() {
  Serial.begin(115200);
  pinMode(dataPin, INPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

   pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  clearRegisters();
  writeRegisters();

  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(22, INPUT_PULLUP);
}
void writeRegisters() {
  // Set and display registers
  digitalWrite(LATCH_PIN, LOW);

  for (int i = numOfRegisterPins - 1; i >= 0; i--) {
    digitalWrite(CLOCK_PIN, LOW);
    digitalWrite(DATA_PIN, registers[i]);
    digitalWrite(CLOCK_PIN, HIGH);
  }

  digitalWrite(LATCH_PIN, HIGH);
}

void setRegisterPin(int index, int value) {
  // Set an individual pin HIGH or LOW
  registers[index] = value;
}

void clearRegisters() {
  // Reset all register pins
  for (int i = numOfRegisterPins - 1; i >= 0; i--) {
    registers[i] = LOW;
  }
}
int a[10];
int nr=0;
void ledurinebune(int i, int nr)
{
  if(nr%2)
     {
       if(i==0) digitalWrite(4, HIGH);
       else
       if(i==1)
           {
             setRegisterPin(0, HIGH);
             writeRegisters();
           }
        else
            if(i==2)
           {
             setRegisterPin(2, HIGH);
             writeRegisters();
           }
        else
            if(i==3)
           {
             setRegisterPin(4, HIGH);
             writeRegisters();
           } 
        else
            if(i==4)
           {
             setRegisterPin(6, HIGH);
             writeRegisters();
           }  
        else
            if(i==5)
           {
             setRegisterPin(8, HIGH);
             writeRegisters();
           }   
        else
            if(i==6)
           {
             setRegisterPin(10, HIGH);
             writeRegisters();
           }
        else
            if(i==7)
           {
             setRegisterPin(12, HIGH);
             writeRegisters();
           }
        else
            if(i==8)
           {
             setRegisterPin(14, HIGH);
             writeRegisters();
           }         
     }
     else
     {
       if(i==0) digitalWrite(2, HIGH);
       else
       if(i==1)
           {
             setRegisterPin(1, HIGH);
             writeRegisters();
           }
        else
            if(i==2)
           {
             setRegisterPin(3, HIGH);
             writeRegisters();
           }
        else
            if(i==3)
           {
             setRegisterPin(5, HIGH);
             writeRegisters();
           } 
        else
            if(i==4)
           {
             setRegisterPin(7, HIGH);
             writeRegisters();
           }  
        else
            if(i==5)
           {
             setRegisterPin(9, HIGH);
             writeRegisters();
           }   
        else
            if(i==6)
           {
             setRegisterPin(11, HIGH);
             writeRegisters();
           }
        else
            if(i==7)
           {
             setRegisterPin(13, HIGH);
             writeRegisters();
           }
        else
            if(i==8)
           {
             setRegisterPin(15, HIGH);
             writeRegisters();
           }         
     }
}

//algoritm x si 0

char t[3][3]={ 'a', 'a', 'a' ,
              'a', 'a', 'a' ,
              'a', 'a', 'a' 
};//initializare tabla joc;
int ok,p1,p2,i,j;
int tabla_plina() //check if there are free position on the board
{
    int k=1;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(t[i][j]=='a') {k=0;break;}
    return k;
}
int sfarsit_joc() //it is checked if one of the players has won
{
    int ok=0;
    {
        for (i = 0; i < 3; i++)
            if (t[i][0] == t[i][1] && t[i][1] == t[i][2] && t[i][0]!='a')
            {
                ok = 1;
                p1 = i;
                p2 = 0;
                break;
            }
        if(ok==0)
        {
            for (j = 0; j < 3; j++)
                if (t[0][j] == t[1][j] && t[1][j] == t[2][j] && t[0][j]!='a')
                {
                    ok = 1;
                    p1 = 0;
                    p2 = j;
                    break;
                }

        }
        if (ok == 0)
        {
            if (t[0][0] == t[1][1] && t[1][1] == t[2][2] && t[0][0]!='a')
            {
                ok = 1;
                p1 = 0;
                p2 = 0;
            } else if (t[0][2] == t[1][1] && t[1][1] ==t[2][0] && t[0][2]!='a')
            {
                ok = 1;
                p1 = 0;
                p2 = 2;
            }
        }
    }
    return ok;
}
void completare(int player,int val) //adding the symbol on the board
{
    if(player==0) {if(val%2!=0) t[0][0]='x';
                    else t[0][0]='0';}
    else
    if(player==1) {if(val%2!=0) t[0][1]='x';
                    else t[0][1]='0';}
    else
    if(player==2) {if(val%2!=0) t[0][2]='x';
                    else t[0][2]='0';}
    else
    if(player==3) {if(val%2!=0) t[1][0]='x';
                    else t[1][0]='0';}
    else
    if(player==4) {if(val%2!=0) t[1][1]='x';
                    else t[1][1]='0';}
    else
    if(player==5) {if(val%2!=0) t[1][2]='x';
                    else t[1][2]='0';}
    else
    if(player==6) {if(val%2!=0) t[2][0]='x';
                    else t[2][0]='0';}
    else
    if(player==7) {if(val%2!=0) t[2][1]='x';
                    else t[2][1]='0';}
    else
    if(player==8) {if(val%2!=0) t[2][2]='x';
                    else t[2][2]='0';}
}
void clipestex()
{
   
        clearRegisters();
        digitalWrite(2, LOW);
        digitalWrite(4, LOW);
        writeRegisters();
delay(1000);
        for(j=0;j<=14;j+=2)
        setRegisterPin(j, HIGH);
        writeRegisters();
        
        digitalWrite(4, HIGH);
  delay(1000);      
      
}
void clipestey()
{
   
        clearRegisters();
        digitalWrite(2, LOW);
        digitalWrite(4, LOW);
        writeRegisters();
delay(1000);
        for(j=1;j<=15;j+=2)
        setRegisterPin(j, HIGH);
        writeRegisters();
        
        digitalWrite(2, HIGH);
delay(1000);       
      
}
int clipit;
void clipit1()
{
   if(t[p1][p2]=='x')
      { if(clipit<3)
      {
        clipestex();
        clipit++;
        
      }
      }
      else
      {
        if(clipit<3)
        {
          clipestey();
        clipit++;
           
        }
      }
}

void joaca()
{
  if(sfarsit_joc()==0)
  for ( i = 0; i < numBits; i++)
   {
    int bit = digitalRead(dataPin);
    if (bit == HIGH) 
      if(a[i]==0) {a[i]=1; nr++;
    ledurinebune(i,nr);
    completare(i,nr);   
    }
   
    digitalWrite(clockPin, HIGH); // Shift out the next bit
    digitalWrite(clockPin, LOW);
    
  }
}

void reset()
{ 
  
       

           for(i=0;i<16;i++)
            setRegisterPin(i,LOW);
             writeRegisters();
          

        digitalWrite(2, LOW);
        digitalWrite(4, LOW);

        for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        t[i][j]='a';

        clipit=0;
        
          for ( i = 0; i < numBits; i++) a[i]=0;
          nr=0;
    
}
void loop() {
  // Step 1: Sample
  digitalWrite(latchPin, LOW);
  digitalWrite(latchPin, HIGH);

  // Step 2: Shift
  //Serial.print("Bits: ");
   bool rstbutton=digitalRead(22);
   if(rstbutton==0)
    {
      //delay(1000);
reset();}
else
 { if(sfarsit_joc()==0 && tabla_plina()==0)
 joaca();
  else
    {
      if(sfarsit_joc()==1)
      clipit1();
    }
 }
}
