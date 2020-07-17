/* ########################################################################

   PICsimLab - PIC laboratory simulator

   ########################################################################

   Copyright (c) : 2015-2018  Luis Claudio Gambôa Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */

#ifndef BOARD_8_H
#define BOARD_8_H

#include<lxrad.h>

#include "board_pic.h"

//New board Class derived from board class defined in board.h
class cboard_8:public board_pic
{
    private:
        int p_BT1; // Button S1
        int p_BT2;  // Button S2
        
        int jmp[1];  //jumper

         //controls to be added in simulator window
        CScroll *scroll1; //scroll for analog input AN0    
        CGauge *gauge1;   //gauge to show mean value of RA4
        CGauge *gauge2;   //gauge to show mean value of RA5
        CGauge *gauge3;   //gauge to show mean value of RA6
        CGauge *gauge4;   //gauge to show mean value of RA7
        CLabel *label1;   //label of scroll AN4
        CLabel *label2;   //label of gauge RA4
        CLabel *label3;   //label of gauge RA5
        CLabel *label4;   //label of gauge RA6
        CLabel *label5;   //label of gauge RA7


    public:
      //Constructor called once on board creation 
      cboard_8(void);
      //Destructor called once on board destruction 
      ~cboard_8(void); 
      //Called ever 100ms to draw board
      void Draw(CDraw *draw,double scale);
      void Run_CPU(void);
      //Return a list of board supported microcontrollers
      String GetSupportedDevices(void){return lxT("PIC16F1619,PIC18F27K40,");};
      //Return the filename of board picture 
      String GetPictureFileName(void){return lxT("Curiosity_HPC.png");};
      //Return the filename of board picture input map 
      String GetInputMapFile(void){return lxT("input_Curiosity_HPC.map");};
      //Return the filename of board picture output map 
      String GetOutputMapFile(void){return lxT("output_Curiosity_HPC.map");};
      //Reset board status
      void Reset(void);
      //Event on the board
      void EvMouseButtonPress(uint button, uint x, uint y,uint state);
      //Event on the board
      void EvMouseButtonRelease(uint button, uint x, uint y,uint state);
      //Event on the board
      void EvKeyPress(uint key, uint mask);
      //Event on the board
      void EvKeyRelease(uint key, uint mask);
      void EvOnShow(void){};
      //Called ever 1s to refresh status
      void RefreshStatus(void);
      //Called to save board preferences in configuration file
      void WritePreferences(void);
      //Called whe configuration file load  preferences 
      void ReadPreferences(char *name,char *value);
      //return the input ids numbers of names used in input map
      unsigned short get_in_id(char * name);
      //return the output ids numbers of names used in output map
      unsigned short get_out_id(char * name);
};

#endif  /* BOARD_8_H */