#include <iostream>
#include "carrots.h"
#include "field.h"
using namespace std;
int main(){
    Field player1;
    Field player2;
    int rabbit;                 // the player's sequence
    int cell;                   // position which rabbit chooses to eat
    char ans;                   // identifies random or regular place of beds
    cout << "Rimma Niyazova. The smart rabbits." << endl << endl;
    //asks to choose the beds placing method. If the player will enter 'Y' or
    //'y'. The program will call randomInput() function otherwise it will call
    //manual input function input()
    cout << "Would you like to set beds randomly? (Y/N) ";
    cin >> ans;
    cout << "The first rabbit's empty field!" << endl;
    //prints the field
    player1.Display();
    cout << endl << "The first rabbit sets his beds with the carrots!" << endl << endl;

    if(ans == 'Y' || ans == 'y')
        player1.randomInput();
    else
        player1.input();
    //sets beds with carrots
    player1.carrots();
    player1.Display();
    cout << endl << "The second rabbit's empty field!" << endl;
    player2.Display();
    cout << endl << "The second rabbit sets his beds with the carrots!" << endl << endl;
    if(ans == 'Y' || ans == 'y')
        player2.randomInput();
    else
        player2.input();
    player2.carrots();
    player2.coverDisplay();
    cout << endl;
    //game will be stopped when one of the players will eat all carrots
    //on the opposite player's beds
    while(player1.finishGame()!=5 && player2.finishGame()!=5){
        rabbit=1;               //the first player's turn
        cout << "It's " << rabbit << " rabbit turn." << endl << endl;
        player2.Display();
        cout << endl << "Choose the cell 0 to 63: ";
        cin >> cell;
        //checks that input is valid if it is not valid
        //functions will ask and return a new valid input
        cell=player2.validCell(cell);
        cell=player2.usedCell(cell);
        //it's the first player's turn. He will enter a value while missing or
        // all beds ate
        while(player2.checkBed(cell) && player2.finishGame()!=5){
            cout << endl;
            player2.Display();
            cout << endl;
            cout << "Choose one more cell: ";
            cin >> cell;
            cell=player2.validCell(cell);
            cell=player2.usedCell(cell);
        }
        //if the first player missed then it is the second player's turn
        //if the first player found all beds program will skip the second
        //player's turn and finish the game
        if(player2.finishGame()!=5){
            cout << endl;
            player2.Display();
            cout << endl;
            rabbit=2;                //the second player's turn
            cout << "It's " << rabbit << " rabbit turn." << endl << endl;
            player1.Display();
            cout << endl << "Choose the cell 0 to 63: ";
            cin >> cell;
            cell=player1.validCell(cell);
            cell=player1.usedCell(cell);
            //it's the second player's turn. He will enter input while missing or finding all beds
            while(player1.checkBed(cell) && player1.finishGame()!=5){
                cout << endl;
                player1.Display();
                cout << endl;
                cout << "Choose one more cell: ";
                cin >> cell;
                cell=player1.validCell(cell);
                cell=player1.usedCell(cell);
            }
            cout << endl;
            player1.Display();
            cout << endl;
        }
    }
    player2.Display();
    //when one of the players wins the program will print an appropriate message
    cout << "The rabbit " << rabbit << " won!!!!" << endl;
    return 0;
}
