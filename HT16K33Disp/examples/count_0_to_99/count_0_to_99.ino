//----------------------------------------
// Count form 00 to 99 on HT16K33 Display
// using HT16K33Disp library (Ver 1.0)
// by: Anas Kuzechie (May 03, 2022)
//-----------------------------------------
#include <Wire.h>
#include <HT16K33Disp.h>
//-----------------------
HT16K33Disp d;
byte add = 0x70;
//------------------------------------------------
void setup()
{
  Wire.begin();
  d.dispInit(add, 8);
  d.dispClear(add);
  delay(1000);
}
//------------------------------------------------
void loop()
{
  d.dispString(add, "PLAY");
  delay(1000);
  d.dispClear(add);
  delay(1000);
  d.dispString(add, "C=");
  //------------------------------
  for(byte MSD=0; MSD<=9; MSD++)
  {
    d.dispNum(add, 2, MSD);
    for(byte LSD=0; LSD<=9; LSD++)
    {
      d.dispNum(add, 3, LSD);
      delay(200);
    }
  }
  //------------------------------
  delay(1000);
  d.dispClear(add);
  delay(1000);
}