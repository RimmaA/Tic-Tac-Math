/*This file contains field¿s data such as display fields, who is winner, functions which do manual and random input, etc.*/
     	//Rimma Niyazova
     	//field.h -- Field class specification file
     	#ifndef FIELD_H
     	#define FIELD_H
     	#include "carrots.h"       
     	class Field{
     	private:
     	 	char field[64];
    	 	int location[5];
    	 	Carrots *bed1, *bed2, *bed3, *bed4, *bed5;
    	public:
    	  	Field();
    	  	~Field();
    	  	void input();
    	  	int validPlace(int[], int);
		void randomInput();
   	  	int randomPlace(int[], int);
   	  	void Display();
   	  	void carrots();
    	  	void coverDisplay();
    	  	bool checkBed(int);
    	  	int validCell(int);
    	  	int usedCell(int);
    	  	int finishGame();
    	  	bool valid(int[], int, int);
    	};         
    	#endif
