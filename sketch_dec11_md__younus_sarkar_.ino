#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define sw1 15
#define sw2 16
#define sw3 17
#define sw4 18
#define sw5 19
int vote1=0;
int vote2=0;
int vote3=0;
int vote4=0;
void setup()
{
  pinMode(sw1, INPUT);
  pinMode(sw2,INPUT);
  pinMode(sw3,INPUT);
  pinMode(sw4,INPUT);
  pinMode(sw5,INPUT);
  lcd.begin(16, 2);
  lcd.print("CSE323 PROJECT");
  lcd.setCursor(0,1);
  lcd.print("SECTION:08");
  delay(3000);
  lcd.begin(16, 2);
  lcd.print("Electrical Voting ");
  lcd.setCursor(0,1);
  lcd.print("Machine");
  delay(3000);
  lcd.begin(16, 2);
  lcd.print("Please Vote...");
  delay(3000);
  digitalWrite(sw1, HIGH);
  digitalWrite(sw2, HIGH);
  digitalWrite(sw3, HIGH);
  digitalWrite(sw4, HIGH);
  digitalWrite(sw5, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("G1");
  lcd.setCursor(4,0);
  lcd.print("G2");
  lcd.setCursor(8,0);
  lcd.print("G3");
  lcd.setCursor(12,0);
  lcd.print("G4");
}
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("G1");
  lcd.setCursor(1,1);
  lcd.print(vote1);
  lcd.setCursor(4,0);
  lcd.print("G2");
  lcd.setCursor(5,1);
  lcd.print(vote2);
  lcd.setCursor(8,0);
  lcd.print("G3");
   lcd.setCursor(9,1);
  lcd.print(vote3);
  lcd.setCursor(12,0);
  lcd.print("G4"); 
  lcd.setCursor(13,1);
  lcd.print(vote4);
  if(digitalRead(sw1)==0)
    vote1++;
    while(digitalRead(sw1)==0);
  if(digitalRead(sw2)==0)
    vote2++;
    while(digitalRead(sw2)==0);
  if(digitalRead(sw3)==0)
    vote3++;
    while(digitalRead(sw3)==0);
   if(digitalRead(sw4)==0)
    vote4++;
    while(digitalRead(sw4)==0);
   if(digitalRead(sw5)==0)
   {
     int vote=vote1+vote2+vote3+vote4;
     if(vote)
     {
      if((vote1 > vote2 && vote1 > vote3 && vote1 > vote4))
      {
       lcd.clear();
       lcd.print("G1 Wins");
       lcd.setCursor(0,1);
       lcd.print("Congratulation!!");
       delay(2000);
       lcd.clear();
      }
      else if((vote2 > vote1 && vote2 > vote3 && vote2 > vote4))
      {
       lcd.clear();
       lcd.print("G2 Wins");
       lcd.setCursor(0,1);
       lcd.print("Congratulation!!");
       delay(2000);
       lcd.clear();
      }
      else if((vote3 > vote1 && vote3 > vote2 && vote3 > vote4))
      {
       lcd.clear();
       lcd.print("G3 Wins");
       lcd.setCursor(0,1);
       lcd.print("Congratulation!!");
       delay(2000);
       lcd.clear();
      }
     else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
     {
       lcd.setCursor(0,0);
       lcd.clear();
       lcd.print("G4 Wins");
       lcd.setCursor(0,1);
       lcd.print("Congratulation!!");
       delay(2000);
       lcd.clear();
     }
     
      else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
     {
       lcd.setCursor(0,0);
       lcd.clear();
       lcd.print("G4 Wins");
       lcd.setCursor(0,1);
       lcd.print("Congratulation!!");
       delay(2000);
       lcd.clear();
     }
     
     else
     {
       lcd.clear();
       lcd.print("   Tie Up Or   ");
       lcd.setCursor(0,1);
       lcd.print("   No Result   ");
       delay(3000);
       lcd.clear();
     }
     
    }      
     else 
     {
       lcd.clear();
       lcd.print("No Voting....");
       delay(3000);
       lcd.clear();
     }
     vote1=0;vote2=0;vote3=0;vote4=0,vote=0;
     lcd.clear();
   }
   
}
   
