#pragma once
#include "Point.h"
#include "RectangularHitbox.h"



class CircleHitbox{
private:
	Point basePoint;
	int radius;
public:
	CircleHitbox();

	void setBasePoint(int coordX, int coordY);
	void setRadius(int initRadius);

	Point getBasePoint();
	int getRadius();

	bool checkForIntersection(CircleHitbox hitbox);
	bool checkForIntersection(RectangularHitbox hitbox);

};