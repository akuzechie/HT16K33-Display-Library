//---------------------------------
// Header File
// by: Anas Kuzechie (May 03, 2022)
//---------------------------------
#include <Wire.h>
//--------------------
//header guards
//prevents header files from multiple inclusion
#ifndef HT16K33Disp_h
#define HT16K33Disp_h

//class definition, which has public and/or private sections
class HT16K33Disp
{
    public:
        //constructor
        HT16K33Disp();
        //methods
        void Init(byte address, byte brightLevel);
        void Clear(byte address);
        void Char(byte address, byte digit, char c1);
        void Text(byte address, String text1);
        void Num(byte address, byte digit, int n);
        void Numdp(byte address, byte digit, int n);
};

#endif