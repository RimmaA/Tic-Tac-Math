/*This file includes all information about beds with carrots(constructor, destructor, functions which checks health of beds, etc.)*/

     1	//Rimma Niyazova 
     2	//carrots.h -- Carrots class specification file
     3	#ifndef CARROTS_H
     4	#define CARROTS_H       
     5	class Carrots
     6	{
     7	 private:
     8	  int *carrots;
     9	 public:
    10	  Carrots(int, int);
    11	  ~Carrots();
    12	  void checkCell(int, int);
    13	  void checkHealth(int);
    14	  bool finishBeds(int);
    15	};         
    16	#endif
