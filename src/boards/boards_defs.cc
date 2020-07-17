
#include "boards_defs.h"
#include"../picsimlab1.h"

//#ifdef _EXPERIMENTAL_
const char boards_list[BOARDS_LAST][30]={"Breadboard","McLab1","K16F","McLab2", "PICGenios","Arduino Uno","MPLAB Xpress","Curiosity","Curiosity HPC","Board X"};
//#else
//const char boards_list[BOARDS_LAST][30]={"Breadboard","McLab1","K16F","McLab2", "PICGenios","Arduino Uno",};
//#endif

//boards object creation
board * create_board(int *lab,int *lab_)
{
   board * pboard=NULL;

        switch(*lab)
        {
          case 0:
            pboard= new cboard_0();
            break;  
          case 1:
            pboard= new cboard_1();
            break;
          case 2:
            pboard= new cboard_2();
            break;
          case 3:
            pboard= new cboard_3();
            break;
          case 4:
            pboard= new cboard_4();
            break;    
          case 5:
            pboard= new cboard_5();
            break;  
//#ifdef _EXPERIMENTAL_          
          case 6:
            pboard= new cboard_6();
            break;     
          case 7:
            pboard= new cboard_7();
            break;  
          case 8:
            pboard= new cboard_8();
            break; 
          case 9:
            pboard= new cboard_x();
            break;             
//#endif	    
          default:
            mprint(lxT("Invalid Board! Using Default!\n"));
            *lab=1;//default  
            *lab_=1;//default  
            pboard= new cboard_1();
          break;
        }

    return pboard; 
}
