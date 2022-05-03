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
        void dispInit(byte address, byte brightLevel);
        void dispClear(byte address);
        void dispChar(byte address, byte digit, char c1);
        void dispString(byte address, String text1);
        void dispNum(byte address, byte digit, int n);
        void dispNumdp(byte address, byte digit, int n);
};

#endif