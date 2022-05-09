//----------------------------------------
// Count form 00 to 99 on HT16K33 Display
// using HT16K33Disp library (Ver 1.0)
// by: Anas Kuzechie (May 03, 2022)
//----------------------------------------
#include <Wire.h>
#include <HT16K33Disp.h>
//-----------------------
HT16K33Disp disp;
byte add = 0x70;
//------------------------------------------------
void setup()
{
  Wire.begin();
  disp.Init(add, 8);
  disp.Clear(add);
  delay(1000);
}
//------------------------------------------------
void loop()
{
  disp.Text(add, "PLAY");
  delay(1000);
  disp.Clear(add);
  delay(1000);
  disp.Text(add, "C=");
  //------------------------------
  for(byte MSD=0; MSD<=9; MSD++)
  {
    disp.Num(add, 2, MSD);
    for(byte LSD=0; LSD<=9; LSD++)
    {
      disp.Num(add, 3, LSD);
      delay(200);
    }
  }
  //------------------------------
  delay(1000);
  disp.Clear(add);
  delay(1000);
}