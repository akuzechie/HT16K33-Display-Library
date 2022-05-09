//------------------------------------------
// Alphanumeric Character on HT16K33 Display
// using HT16K33Disp library (Ver 1.0)
// by: Anas Kuzechie (May 03, 2022)
//------------------------------------------
#include <Wire.h>
#include <HT16K33Disp.h>
//---------------------------------------
HT16K33Disp disp; //declare object
//-------------------------------------------------------------
void setup()
{
    Wire.begin();
    //-------------------------------------
    //initialize HT16K33 of address 0x70
    //and set brightness level (0 --> 15)
    disp.Init(0x70, 8);
    //-------------------------------------
    //clear 4-digit display of address 0x70
    disp.Clear(0x70);
    //-------------------------------------
    delay(2000);
}
//-------------------------------------------------------------
void loop()
{
  disp.Text(0x70, "TIME");
  delay(1000);
  disp.Clear(0x70);
  //------------------------------------------------
  disp.Text(0x70, "FROM");
  delay(1000);
  disp.Clear(0x70);

  disp.Text(0x70, "0TO9");
  delay(2000);
  disp.Clear(0x70);
  //------------------------------------------------
  disp.Text(0x70, "T= S");
  for(byte i=0; i<=9; i++)
  {
    disp.Num(0x70, 2, i);
    delay(1000);
  }
  //------------------------------------------------
  delay(2000);
  disp.Clear(0x70);
  delay(2000);
}