//carrots.cc -- Carrots class function implementation file
#include<iostream>
#include "carrots.h"
using namespace std;
/******************************************************************************
*                          Carrots::Constructor                               *
*   The size value indicates the  number of carrots in the bed. The array     *
*  holds the values where carrots are located in the field. The start value   *
*      indicates the value of the cell where a  carrots bed is started        *
******************************************************************************/
Carrots::Carrots(int size, int start){
    carrots=new int[size];
    for(int i=0; i<size; i++){
        carrots[i]=start;
        start++;
    }
}
/******************************************************************************
*                           Carrots::Destructor                               *
*              Frees the memory allocated by the constructor                  *
******************************************************************************/
Carrots::~Carrots(){
    delete [ ] carrots;
    carrots=0;
}
/******************************************************************************
*                          Carrots::finishBeds                                *
*    This function checks how many carrots left on each bed. If all numbers   *
*               are 0s it will send true otherwise false.                     *
******************************************************************************/
bool Carrots::finishBeds(int size){
    bool check=false;
    int count=0;
    for(int i=0; i<size; i++){
        if(carrots[i]==0)
            count++;
    }
    if(count==size)
        check=true;
    return check;
}
/******************************************************************************
*                                 Carrots::checkCell                          *
*      This function gives the value 0 to cell if rabbit finds a carrot.      *
*  Sends size of the array to the function checkHealth() which checks if the  *
*                   rabbit ate all carrots in this bed or not.                *
******************************************************************************/
void Carrots::checkCell(int cell, int size){
    for(int i=0; i<size; i++){
        if(carrots[i]==cell){
            carrots[i]=0;
            checkHealth(size);
        }
    }
}
/******************************************************************************
*                         Carrots::checkHealth                                *
* This function checks how many carrots left on a bed. If all numbers are 0s  *
*  the bed was eaten and the function will print a message. If not the        *
*             function will ask to finish this bed.                           *
******************************************************************************/
void Carrots::checkHealth(int size){
    int count=0;
    for(int i=0; i<size; i++){
        if(carrots[i]==0)
            count++;
    }
    if(count==size)
        cout << endl << "Minus one bed!!!" << endl;
    else if(count>=1 && count < size)
        cout << endl << "You found the bed but didn't eat it all! Finish it!" << endl;
}
