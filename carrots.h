/*This file includes all information about beds with carrots(constructor, destructor, functions which checks health of beds, etc.)*/

//Rimma Niyazova 
//carrots.h -- Carrots class specification file
#ifndef CARROTS_H
#define CARROTS_H       
class Carrots{
private:
	int *carrots;
public:
	Carrots(int, int);
	~Carrots();
	void checkCell(int, int);
	void checkHealth(int);
	bool finishBeds(int);
};         
#endif
