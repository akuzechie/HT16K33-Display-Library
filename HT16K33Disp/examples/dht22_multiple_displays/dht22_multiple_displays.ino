//--------------------------------------------
// DHT22 Temp & Humidity on 2 HT16K33 Displays
// using HT16K33Disp library (Ver 1.0)
// by: Anas Kuzechie (May 03, 2022)
//--------------------------------------------
#include <Wire.h>
#include <DHT.h>
#include <HT16K33Disp.h>
//-----------------------
HT16K33Disp disp;
DHT dht(8, DHT22);
//-----------------------
byte a1 = 0x70, a2 = 0x71;
float temp; int humidity;
int temp_LSD, temp_MSD, temp_fraction, hum_LSD, hum_MSD;
unsigned long millisCapture = millis(), myDelay = 30000;
//------------------------------------------------------
void setup()
{
  Wire.begin();
  dht.begin();
  disp.Init(a1, 8);
  disp.Init(a2, 8);
  //-------------------------------------------
  disp.Clear(a1); disp.Clear(a2);
  delay(1000);
  disp.Text(a1, "DHT1"); disp.Text(a2, "1/22");
  delay(2000);
  disp.Clear(a1); disp.Clear(a2);
}
//------------------------------------------------------
void loop()
{
  delay(2000);
  disp_temp(); disp_hum();
  //----------------------------------------------------
  if(millis() - millisCapture > myDelay) disp_message();
}
//------------------------------------------------------
void disp_temp()
{
  temp = dht.readTemperature();
  temp_MSD = int(temp)/10;
  temp_LSD = int(temp)%10;
  temp_fraction = (temp - int(temp))*10;
  //------------------------------------
  disp.Num(a1, 0, temp_MSD);
  disp.Numdp(a1, 1, temp_LSD);
  disp.Num(a1, 2, temp_fraction);
  disp.Char(0x70, 3, 'C');
}
//------------------------------------------------------
void disp_hum()
{
  humidity = dht.readHumidity();
  hum_MSD = humidity/10;
  hum_LSD = humidity%10;
  //----------------------------
  disp.Char(a2, 0, 'H');
  disp.Num(a2, 1, hum_MSD);
  disp.Num(a2, 2, hum_LSD);
  disp.Char(a2, 3, 'P');
}
//------------------------------------------------------
void disp_message()
{
  disp.Clear(a1); disp.Clear(a2);
  delay(1000);
  disp.Text(a1, "TEMP"); disp.Text(a2, " AND");
  delay(2000);
  disp.Clear(a1); disp.Clear(a2);
  delay(1000);
  disp.Text(a1, "HUMI"); disp.Text(a2, "DITY");
  delay(2000);
  disp.Clear(a1); disp.Clear(a2);
  //-------------------------------------------
  millisCapture = millis();
}