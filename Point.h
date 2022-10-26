#pragma once
#include <iostream>

class Point {
private:
	unsigned int coordX;
	unsigned int coordY;
	//^coord y
	//|
	//|
	//|
	//|
	//0-----------------> coord x
public:
	Point();

	void setCoordX(int initCoordX);
	void setCoordY(int initCoordY);
	int getCoordX();
	int getCoordY();

	void setCoordinates(int initCoordX, int initCoordY);
};