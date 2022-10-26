#include "CircleHitbox.h"
#include <cmath>

CircleHitbox::CircleHitbox() {
	basePoint.setCoordinates(0, 0);
}

void CircleHitbox::setBasePoint(int coordX, int coordY) {
	basePoint.setCoordinates(coordX, coordY);
}
void CircleHitbox::setRadius(int initRadius) {
	radius = initRadius;
}

Point CircleHitbox::getBasePoint() {
	return basePoint;
}
int CircleHitbox::getRadius() {
	return radius;
}



bool CircleHitbox::checkForIntersection(CircleHitbox hitbox) {

	if (sqrt((basePoint.getCoordX() - hitbox.getBasePoint().getCoordX()) * (basePoint.getCoordX() - hitbox.getBasePoint().getCoordX()) +
		(basePoint.getCoordY() - hitbox.getBasePoint().getCoordY()) * (basePoint.getCoordY() - hitbox.getBasePoint().getCoordY())) -
		hitbox.getRadius() - radius <= 0
		) {
		return true;
	}

	return false;
}

bool CircleHitbox::checkForIntersection(RectangularHitbox hitbox) {

	if(sqrt(((basePoint.getCoordX() - hitbox.getPointA_currCoordX()) * 
		 (basePoint.getCoordX() - hitbox.getPointA_currCoordX())) +
		 ((basePoint.getCoordY() - hitbox.getPointA_currCoordY()) *
		 (basePoint.getCoordY() - hitbox.getPointA_currCoordY()))) - radius < 0	
		) {
		return true;
	}

	if (sqrt(((basePoint.getCoordX() - hitbox.getPointB_currCoordX()) *
		(basePoint.getCoordX() - hitbox.getPointB_currCoordX())) +
		((basePoint.getCoordY() - hitbox.getPointB_currCoordY()) *
			(basePoint.getCoordY() - hitbox.getPointB_currCoordY()))) - radius < 0
		) {
		return true;
	}

	if (sqrt(((basePoint.getCoordX() - hitbox.getPointC_currCoordX()) *
		(basePoint.getCoordX() - hitbox.getPointC_currCoordX())) +
		((basePoint.getCoordY() - hitbox.getPointC_currCoordY()) *
			(basePoint.getCoordY() - hitbox.getPointC_currCoordY()))) - radius < 0
		) {
		return true;
	}

	if (sqrt(((basePoint.getCoordX() - hitbox.getPointD_currCoordX()) *
		(basePoint.getCoordX() - hitbox.getPointD_currCoordX())) +
		((basePoint.getCoordY() - hitbox.getPointD_currCoordY()) *
			(basePoint.getCoordY() - hitbox.getPointD_currCoordY()))) - radius < 0
		) {
		return true;
	}

	if (basePoint.getCoordX() >= hitbox.getPointA_currCoordX() && basePoint.getCoordX() <= hitbox.getPointC_currCoordX()) {
		if (basePoint.getCoordY() + radius >= hitbox.getPointA_currCoordY() && basePoint.getCoordY() + radius <= hitbox.getPointC_currCoordY()) {
			return true;
		}
		if (basePoint.getCoordY() - radius >= hitbox.getPointA_currCoordY() && basePoint.getCoordY() - radius <= hitbox.getPointC_currCoordY()) {
			return true;
		}
		if (basePoint.getCoordY() + radius >= hitbox.getPointA_currCoordY() && basePoint.getCoordY() - radius <= hitbox.getPointC_currCoordY()) {
			return true;
		}
	}
	
	if (basePoint.getCoordY() >= hitbox.getPointA_currCoordY() && basePoint.getCoordY() <= hitbox.getPointC_currCoordY()) {
		if (basePoint.getCoordX() + radius >= hitbox.getPointA_currCoordX() && basePoint.getCoordX() + radius <= hitbox.getPointC_currCoordX()) {
			return true;
		}
		if (basePoint.getCoordX() - radius >= hitbox.getPointA_currCoordX() && basePoint.getCoordX() - radius <= hitbox.getPointC_currCoordX()) {
			return true;
		}
		if (basePoint.getCoordX() + radius >= hitbox.getPointA_currCoordX() && basePoint.getCoordX() - radius <= hitbox.getPointC_currCoordX()) {
			return true;
		}
	}


	return false;
}