/* ########################################################################

   PICsimLab - PIC laboratory simulator

   ########################################################################

   Copyright (c) : 2010-2020  Luis Claudio Gambôa Lopes

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

#ifndef BOARD_H
#define	BOARD_H

#include <lxrad.h>    
#include <picsim/picsim.h>
#include "../devices/lcd_hd44780.h"
#include "../devices/mi2c_24CXXX.h"
#include "../devices/rtc_ds1307.h"
#include "../devices/rtc_pfc8563.h"


    /**
     * @brief input map struct 
     *
     */
typedef struct
{
unsigned int x1; ///< x1 position
unsigned int x2; ///< x2 position
unsigned int y1; ///< y1 position
unsigned int y2; ///< y2 position
char name[10]; ///< region name
unsigned short id; ///< region ID
}input_t;
    
    /**
     * @brief output map struct 
     *
     */
typedef struct
{
unsigned int x1; ///< x1 position
unsigned int x2; ///< x2 position
unsigned int y1; ///< y1 position
unsigned int y2; ///< y2 position
unsigned int r;
char name[10]; ///< region name
unsigned short id; ///<  region ID
}output_t;    

    /**
     * @brief Board class
     *
     * class definition of boards used in picsimlab.
     */
class board
{
  public:
     /**
     * @brief Called ever 100ms to draw board 
     */
      virtual void Draw(CDraw *draw,double scale)=0;
     
     /**
     * @brief Paralle thread called ever 100ms to run cpu code 
     */ 
      virtual void Run_CPU(void)=0; 
           
     /**
     * @brief  Return a list of supported microcontrollers
     */ 
      virtual String GetSupportedDevices(void)=0;
           
     /**
     * @brief Return the filename of board picture  
     */ 
      virtual String GetPictureFileName(void)=0; 
           
     /**
     * @brief  Return the filename of board picture input map
     */ 
      virtual String GetInputMapFile(void)=0;      
           
     /**
     * @brief  Return the filename of board picture output map
     */ 
      virtual String GetOutputMapFile(void)=0;     
           
     /**
     * @brief  Reset board status
     */ 
      virtual void Reset(void)=0;           
           
     /**
     * @brief  Event on the board
     */ 
      virtual void EvMouseButtonPress(uint button, uint x, uint y,uint state)=0;    
           
     /**
     * @brief  Event on the board
     */ 
      virtual void EvMouseButtonRelease(uint button, uint x, uint y,uint state)=0; 
           
     /**
     * @brief  Event on the board
     */ 
      virtual void EvKeyPress(uint key,uint mask)=0;  
           
     /**
     * @brief  Event on the board
     */ 
      virtual void EvKeyRelease(uint key,uint mask)=0;
           
     /**
     * @brief  Event on the board
     */ 
      virtual void EvOnShow(void)=0;
           
     /**
     * @brief  Called ever 1s to refresh status
     */ 
      virtual void RefreshStatus(void);   
           
     /**
     * @brief  Called to save board preferences in configuration file
     */ 
      virtual void WritePreferences(void){};   
           
     /**
     * @brief  Called whe configuration file load  preferences 
     */ 
      virtual void ReadPreferences(char *name,char *value){}; 
           
     /**
     * @brief  return the input ids numbers of names used in input map
     */ 
      virtual unsigned short get_in_id(char * name)=0; 
           
     /**
     * @brief  return the output ids numbers of names used in output map
     */ 
      virtual unsigned short get_out_id(char * name)=0; 
           
     /**
     * @brief  Called when window side controls are activated
     */ 
      virtual void board_Event(CControl * control){};         
           
     /**
     * @brief  Called once on board creation
     */ 
      board(void);           
           
     /**
     * @brief  Called once on board destruction 
     */ 
      virtual ~board(void);  
           
     /**
     * @brief  Enable/disable oscilloscope measurement
     */ 
      void SetUseOscilloscope(int uo);   
           
     /**
     * @brief  Enable/disable spare parts 
     */ 
      void SetUseSpareParts(int sp); 
      
     /**
     * @brief Get if oscilloscope is in use   
     */ 
      int GetUseOscilloscope(void); 
      
     /**
     * @brief Get if spare parts is in use   
     */ 
      int GetUseSpareParts(void);
     
     /**
     * @brief Set board processor   
     */ 
      void  SetProcessorName(String proc);
     
     /**
     * @brief Get board processor in use  
     */ 
      String  GetProcessorName(void);    
      
     /**
     * @brief Start debug support  
     */ 
      virtual int DebugInit(int dtyppe)=0;
        
     /**
     * @brief debug step (pooling)  
     */
      virtual void DebugLoop(void)=0;
        
     /**
     * @brief return true if microcontroller is initialized  
     */
      virtual int CpuInitialized(void)=0;
        
     /**
     * @brief Set serial port name to use  
     */
      virtual void MSetSerial(const char * port)=0;
        
     /**
     * @brief board microcontroller init  
     */
      virtual int MInit(const char* processor, const char * fname, float freq)=0;
        
     /**
     * @brief board microcontroller end   
     */
      virtual void MEnd(void)=0;
        
     /**
     * @brief board microcontroller save non volatile memory to hex file   
     */
      virtual void MDumpMemory(const char * fname)=0;
        
     /**
     * @brief board microcontroller erase flash memory (program)   
     */
      virtual void MEraseFlash(void)=0;
        
     /**
     * @brief board microcontroller set frequency   
     */
      virtual void MSetFreq(float freq)=0;
        
     /**
     * @brief board microcontroller get frequency   
     */
      virtual float MGetFreq(void)=0;
        
     /**
     * @brief board microcontroller get cpu internal clock (in PIC frequency/4)   
     */
      virtual float MGetInstClock(void)=0;
        
     /**
     * @brief board microcontroller pin count   
     */
      virtual int MGetPinCount(void)=0;
        
     /**
     * @brief board microcontroller pin name   
     */
      virtual String MGetPinName(int pin)=0;
        
     /**
     * @brief board microcontroller set digital pin   
     */
      virtual void MSetPin(int pin, unsigned char value)=0;
        
     /**
     * @brief board microcontroller set Default Open Value (external pull)   
     */
      virtual void MSetPinDOV(int pin, unsigned char ovalue)=0;
        
     /**
     * @brief board microcontroller set analog pin   
     */
      virtual void MSetAPin(int pin, float value)=0;
        
     /**
     * @brief board microcontroller get digital pin value   
     */
      virtual unsigned char MGetPin(int pin)=0;  
        
     /**
     * @brief board microcontroller get all pins list struct   
     */
      virtual const picpin * MGetPinsValues(void)=0;  
        
     /**
     * @brief board microcontroller run one step   
     */
      virtual void MStep(void)=0;
        
     /**
     * @brief board microcontroller run one or two steps to resume instruction   
     */
      virtual void MStepResume(void)=0;
        
     /**
     * @brief board microcontroller test if in breakpoint   
     */
      virtual int MTestBP(unsigned int bp)=0;
        
     /**
     * @brief board microcontroller reset   
     */
      virtual void MReset(int flags)=0;
        
     /**
     * @brief board microcontroller get pointer to processor ID   
     */
      virtual unsigned short * MGetProcID_p(void)=0;
        
     /**
     * @brief  board microcontroller get PC  
     */
      virtual unsigned int  MGetPC(void)=0;
        
     /**
     * @brief  board microcontroller set PC
     */
      virtual void MSetPC(unsigned int pc)=0;
        
     /**
     * @brief  board microcontroller get RAM memory pointer  
     */
      virtual unsigned char * MGetRAM_p(void)=0;
        
     /**
     * @brief  board microcontroller get ROM (FLASH) memory pointer 
     */
      virtual unsigned char * MGetROM_p(void)=0;
        
     /**
     * @brief  board microcontroller  get CONFIG memory pointer  
     */
      virtual unsigned char * MGetCONFIG_p(void)=0;
        
     /**
     * @brief  board microcontroller  get internal IDS memory pointer   
     */
      virtual unsigned char * MGetID_p(void)=0;
        
     /**
     * @brief  board microcontroller get data EEPROM memory pointer  
     */
      virtual unsigned char * MGetEEPROM_p(void)=0;
        
     /**
     * @brief  board microcontroller get RAM memory size   
     */
      virtual unsigned int MGetRAMSize(void)=0;
        
     /**
     * @brief  board microcontroller get ROM  (FLASH) memory size  
     */
      virtual unsigned int MGetROMSize(void)=0;
        
     /**
     * @brief board microcontroller get CONFIG memory size   
     */
      virtual unsigned int MGetCONFIGSize(void)=0;
        
     /**
     * @brief board microcontroller get internal IDS memory size   
     */
      virtual unsigned int MGetIDSize(void)=0;
        
     /**
     * @brief  board microcontroller get data EEPROM memory size    
     */
      virtual unsigned int MGetEEPROM_Size(void)=0;
 
protected:      
      String Proc;          ///< Name of processor in use
      input_t  input[100];  ///< input map elements
      output_t output[100]; ///< output map elements 
      int inputc;           ///< input map elements counter 
      int outputc;          ///< output map elements counter   
      int use_oscope;       ///< use oscilloscope window
      int use_spare;        ///< use spare parts window             
      int p_MCLR;           ///< board /RESET pin state
      
     /**
     * @brief  Read maps 
     */
      void ReadMaps(void); 
      
private:      
      
     /**
     * @brief Read the Input Map  
     */
    void ReadInputMap(String fname);  
          
     /**
     * @brief Read the Output Map  
     */  
    void ReadOutputMap(String fname); 

};


#endif	/* BOARD_H */

