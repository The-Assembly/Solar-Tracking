#include <Servo.h>  
  //defining Servos
  Servo baseservo;
  int servoh = 0;
  int servohLimitHigh = 160;
  int servohLimitLow = 20;
  
  Servo bodyservo;
  int servov = 0;
  int servovLimitHigh = 160;
  int servovLimitLow = 20;
  //Assigning LDRs
  int ldrtopl = 2; // top left 
  int ldrtopr = 1; // top right 
  int ldrbotl = 3; // bottom left 
  int ldrbotr = 0; // bottom right 
  
  void setup ()
  {
  baseservo.attach(10);
  baseservo.write(0);
  bodyservo.attach(9);
  bodyservo.write(0);
  delay(500);
  }
  
  void loop()
  {
  servoh = baseservo.read();//reading the value currently at
  servov = bodyservo.read();
  //capturing analog values of each LDR
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);
  // calculating average
  int avgtop = (topl + topr) / 2; //average of top LDRs
  int avgbot = (botl + botr) / 2; //average of bottom LDRs
  int avgleft = (topl + botl) / 2; //average of left LDRs
  int avgright = (topr + botr) / 2; //average of right LDRs
  
  if (avgtop < avgbot)
  {
  bodyservo.write(servov +1);
  if (servov > servovLimitHigh)
  {
  servov = servovLimitHigh;
  }
  delay(10);
  }
  else if (avgbot < avgtop)
  {
  bodyservo.write(servov -1);
  if (servov < servovLimitLow)
  {
  servov = servovLimitLow;
  }
  delay(10);
  }
  else
  {
  bodyservo.write(servov);
  }
  
  if (avgleft > avgright)
  {
  baseservo.write(servoh +1);
  if (servoh > servohLimitHigh)
  {
  servoh = servohLimitHigh;
  }
  delay(10);
  }
  else if (avgright > avgleft)
  {
  baseservo.write(servoh -1);
  if (servoh < servohLimitLow)
  {
  servoh = servohLimitLow;
  }
  delay(10);
  }
  else
  {
  baseservo.write(servoh);
  }
  delay(50);
  }
