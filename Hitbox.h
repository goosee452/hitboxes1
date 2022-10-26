#pragma once
#include "RectangularHitbox.h"
#include "CircleHitbox.h"
#include "Point.h"

class Hitbox {
private:
	Point basePoint;
	int circleHitboxesQuant;
	CircleHitbox* circleHitboxes;
	int rectangularHitboxesQuant;
	RectangularHitbox* rectangularHitboxes;

public:
	Hitbox();
	void setBasePoint(int initCoordX, int initCoordY);
	Point getBasePoint();
	int getRectangularHitboxesQuantity();
	RectangularHitbox getRectangularHitbox(int number);
	int getCircleHitboxesQuantity();
	CircleHitbox getCircleHitbox(int number);
	void setHitbox(int circleHitboxesQuant, CircleHitbox* circleHitboxes, int rectangularHitboxesQuant, RectangularHitbox* rectangularHitboxes);
	bool checkForCollision(Hitbox hitbox);
	~Hitbox();
};