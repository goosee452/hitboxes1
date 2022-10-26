#pragma once
#include "Point.h"

class CircleHitbox;


class RectangularHitbox{
private:

	Point pointA;
	Point pointB;
	Point pointC;
	Point pointD;
	Point basePoint;     

public:

	RectangularHitbox();
	void setPoints(Point initPointA, Point initPointC);
	void setBasePoint(Point initBasePoint);
	
	Point getBasePoint();
	Point getPointA();
	Point getPointB(); 
	Point getPointC();
	Point getPointD();


	int getPointA_currCoordX();
	int getPointA_currCoordY();
	int getPointB_currCoordX();
	int getPointB_currCoordY();
	int getPointC_currCoordX();
	int getPointC_currCoordY();
	int getPointD_currCoordX();
	int getPointD_currCoordY();


	bool checkForIntersection(RectangularHitbox hitbox);
	bool checkForIntersection(CircleHitbox hitbox);
};