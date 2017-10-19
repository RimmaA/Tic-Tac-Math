//field.cc -- Field class function implementation file
#include<iostream>
#include<ctime>
#include<cstdlib>
#include "field.h"
#include "carrots.h"
using namespace std;
/***************************************************************************
 *                           Field::Field                                  *
 *        Field default constructor sets empty field with '_'.             *
 **************************************************************************/
Field::Field(){
    for (int i = 0; i < 64; i++)
        field[i]='_';
}
/***************************************************************************
*                            Field::Destructor                             *
*             Frees the memory allocated by input function                 *
***************************************************************************/
Field::~Field(){
    delete bed1;
    bed1=0;
    delete bed2;
    bed2=0;
    delete bed3;
    bed3=0;
    delete bed4;
    bed4=0;
    delete bed5;
    bed5=0;
}
/***************************************************************************
*                           Field :: Display                               *
*                  This function shows the  board                          *
***************************************************************************/
void Field::Display(){
    for (int i = 0; i < 64; i++)
        cout << field[i];
    cout << endl;
}
/***************************************************************************
*                            Field::randomInput                            *
*                    This function does random input                       *
***************************************************************************/
void Field::randomInput(){
    //The busy[] array helps to initialize busy cells on the field.
    //If cell is busy busy[] array will have the value 1 in this cell.
    //Initial value of all the members in the busy[] array is 0
    int busy[64];
    for(int i=0; i < 64; i++)
        busy[i]=0;
    location[0]=randomPlace(busy, 7);
    location[1]=randomPlace(busy, 6);
    location[2]=randomPlace(busy, 5);
    location[3]=randomPlace(busy, 4);
    location[4]=randomPlace(busy, 3);
    cout << endl;
}
/***************************************************************************
*                          Field::randomPlace                              *
*      This function helps to do random input. If the cell is busy         *
*       the function will do random input again while it finds valid       *
*location. When location is valid the function will put 1s in busy[] array *                                                                         *
***************************************************************************/
int Field::randomPlace(int busy[], int size){
    int place;                                    //the location of the bed
    srand((unsigned int)(time(NULL)));
    place=rand () % 64;
    while(place>(64-size) or valid(busy, size, place))
        place=rand () % 64;
    //gives a value of 1 to busy cells, and one cell exactly after bed will have the
    //value 1 because it should be space between two beds
    for(int i=place; i<(place+size); i++)
        busy[i]=1;
    return place;
}
/***************************************************************************
*                               Field::input                               *
*                  This function creates beds on the fields                *
***************************************************************************/
void Field::input(){
    //The busy[] array helps to initialize busy cells on the field.
    //If cell is busy busy[] array will have the value 1 in cell.
    //Initial value of all cells in the busy[] array is 0
    int busy[64];
    for(int i=0; i < 64; i++)
        busy[i]=0;
    location[0]=validPlace(busy, 7);
    location[1]=validPlace(busy, 6);
    location[2]=validPlace(busy, 5);
    location[3]=validPlace(busy, 4);
    location[4]=validPlace(busy, 3);
    cout << endl;
}
/***************************************************************************
*                               Field::validPlace                          *
* This function asks rabbits the location of the beds. If the cell is busy *
* the function will ask again while it is a valid location. When location  *
* is valid the function will put 1s in this location of  busy[] array      *
***************************************************************************/
int Field::validPlace(int busy[], int size){
    int place;                                                     //the location of the bed
    cout << "Enter a number of a cell where will be started your bed with "
       << size-1 << " carrots(from 0 to 63): ";
    cin >> place;
    //the place value can't be more than (64-size) because the number of
    //cells is limited and bed can't be set out of field size
    while(place>(64-size) or valid(busy, size, place)){
        cout << "Invalid input! Enter a number of a cell where will be started\
    your bed with "<< size-1 << " carrots one more time(from 0 to 63): ";
        cin >> place;
    }
    //gives a value of 1 to busy cells, and one cell exactly after bed will have //the value 1 because it should be space between two beds
    for(int i=place; i<(place+size); i++)
        busy[i]=1;
    return place;
}
/***************************************************************************
*                              Field::valid                                *
*     Checks that all beds which you will use to set a new bed are empty   *
***************************************************************************/
bool Field::valid(int busy[], int size, int place){
    bool check;
    for(int i=place; i<(place+size); i++) {
        if(busy[place]!=1)
            check=false;
        else
            check=true;
    }
    return check;
}
/***************************************************************************
*                              Field :: carrots                            *
*     This function allocates the arrays with carrots and puts letter      *
*        'c' to the cells of the field where rabbits put their beds.       *
***************************************************************************/
void Field::carrots(){
    bed5=new Carrots(2, location[4]);
    bed4=new Carrots(3, location[3]);
    bed3=new Carrots(4, location[2]);
    bed2=new Carrots(5, location[1]);
    bed1=new Carrots(6, location[0]);
    for (int i=location[0]; i < (location[0]+6); i++)
        field[i]='c';
    for (int i=location[1]; i < (location[1]+5); i++)
        field[i]='c';
    for (int i=location[2]; i < (location[2]+4); i++)
        field[i]='c';
    for (int i=location[3]; i < (location[3]+3); i++)
        field[i]='c';
    for (int i=location[4]; i < (location[4]+2); i++)
        field[i]='c';
}
/***************************************************************************
*                           Field :: coverDisplay                          *
*      This function shows the display for the second rabbit, to           *
*          avoid confusion with the first  rabbit’s field                  *
***************************************************************************/
void Field::coverDisplay(){
    for (int i = 0; i < 64; i++){
        if(field[i]=='c')
            field[i]='k';
        cout << field[i];
    }
    cout << endl;
}
/***************************************************************************
*                              Field::finishGame                           *
*         This function counts how many beds are left and returns          *
*       the number of eaten beds. If finishBed() returns true the bed      *
*             was eaten if false the bed still has carrots.                *
***************************************************************************/
int Field::finishGame(){
    int check=0;
    if(bed1->finishBeds(6))
        check++;
    if(bed2->finishBeds(5))
        check++;
    if(bed3->finishBeds(4))
        check++;
    if(bed4->finishBeds(3))
        check++;
    if(bed5->finishBeds(2))
        check++;
    return check;
}
/***************************************************************************
*                            Field::validCell                              *
* This function checks that the cell has a value 0 to 63. If it has invalid*
* value the function will ask for a new input while it is not valid and    *
*                       return the valid value                             *
***************************************************************************/
int Field::validCell(int cell){
    while(cell>63 || cell<0){
        cout << endl << "Invalid value of the cell! Choose one more cell from 0\
    to 63:";
        cin >> cell;
    }
    return cell;
}
/***************************************************************************
*                             Field::usedCell                              *
* This function checks that the input value hasn’t been used. If it        *
* has been used the function will ask for a new input while it is not      *
*          valid and return the valid value at the end                     *
***************************************************************************/
int Field::usedCell(int cell){
    for(int i=0; i<64; i++){
        while((i==cell && field[i]=='x') || (field[i]=='.' && i==cell)){
            cout << endl << "Cell was used! Choose another one: ";
            cin >> cell;
            validCell(cell);
        }
    }
    return cell;
}
/***************************************************************************
*                               Field::checkBed                            *
*     This function checks if the rabbit finds the other rabbit’s bed or   *
* not. If it is found the field will change cell’s value to 'x' and return *
*                  true if not to '.' and return false.                    *
***************************************************************************/
bool Field::checkBed(int cell){
    bool check=false;
    for(int i=0; i<64; i++){
        if(cell==i && (field[i]=='c' || field[i]=='k')){
            check=true;
            //checks the first bed
            if(cell>=location[0] && cell<=(location[0]+6)){
                bed1->checkCell(cell, 6);
                field[cell]='x';
            }
            //checks the second bed
            else if(cell>=location[1] && cell<=(location[1]+5)){
                bed2->checkCell(cell, 5);
                field[cell]='x';
            }
            //checks the third bed
            else if(cell>=location[2] && cell<=(location[2]+4)){
                bed3->checkCell(cell, 4);
                field[cell]='x';
            }
            //checks the fourth bed
            else if(cell>=location[3] && cell<=(location[3]+3)){
                bed4->checkCell(cell, 3);
                field[cell]='x';
            }
            //checks the fifth bed
            else if (cell==location[4] || cell==(location[4]+1)){
                bed5->checkCell(cell, 2);
                field[cell]='x';
            }
        }
    }
    if(check==false){
        field[cell]='.';
        cout << endl << "Wide of the target!:(" << endl;
    }
    return check;
}
