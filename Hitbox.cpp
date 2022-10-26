#include "Hitbox.h"


Hitbox::Hitbox() {
	circleHitboxesQuant = 0;
    circleHitboxes = NULL;
	rectangularHitboxesQuant = 0;
	rectangularHitboxes = NULL;
}


void Hitbox::setBasePoint(int initCoordX, int initCoordY) {
	basePoint.setCoordinates(initCoordX, initCoordY);
	for (int iter = 0; iter < rectangularHitboxesQuant; iter++) {
		rectangularHitboxes[iter].setBasePoint(basePoint);
	}
	for (int iter = 0; iter < circleHitboxesQuant; iter++) {
		circleHitboxes[iter].setBasePoint(basePoint.getCoordX(), basePoint.getCoordY());
	}
}


Point Hitbox::getBasePoint() {
	return basePoint;
}


int Hitbox::getRectangularHitboxesQuantity() {
	return rectangularHitboxesQuant;
}


RectangularHitbox Hitbox::getRectangularHitbox(int number) {
	return rectangularHitboxes[number];
}


int Hitbox::getCircleHitboxesQuantity() {
	return circleHitboxesQuant;
}


CircleHitbox Hitbox::getCircleHitbox(int number) {
	return circleHitboxes[number];
}


void Hitbox::setHitbox(int circleHitboxesQuant, CircleHitbox* circleHitboxes, int rectangularHitboxesQuant, RectangularHitbox* rectangularHitboxes) {
	this->circleHitboxes = circleHitboxes;
	this->circleHitboxesQuant = circleHitboxesQuant;
	this->rectangularHitboxes = rectangularHitboxes;
	this->rectangularHitboxesQuant = rectangularHitboxesQuant;
}


bool Hitbox::checkForCollision(Hitbox hitbox) {
	for (int iter = 0; iter < rectangularHitboxesQuant; iter++) {
		for (int hitbox_iter = 0; hitbox_iter < hitbox.getRectangularHitboxesQuantity(); hitbox_iter++) {
			if (rectangularHitboxes[iter].checkForIntersection(hitbox.getRectangularHitbox(hitbox_iter)) == true) {
				return true;
			}
		}
	}
	for (int iter = 0; iter < rectangularHitboxesQuant; iter++) {
		for (int hitbox_iter = 0; hitbox_iter < hitbox.getCircleHitboxesQuantity(); hitbox_iter++) {
			if (rectangularHitboxes[iter].checkForIntersection(hitbox.getCircleHitbox(hitbox_iter)) == true) {
				return true;
			}
		}
	}
	for (int iter = 0; iter < circleHitboxesQuant; iter++) {
		for (int hitbox_iter = 0; hitbox_iter < hitbox.getRectangularHitboxesQuantity(); hitbox_iter++) {
			if (circleHitboxes[iter].checkForIntersection(hitbox.getRectangularHitbox(hitbox_iter)) == true) {
				return true;
			}
		}
	}
	for (int iter = 0; iter < circleHitboxesQuant; iter++) {
		for (int hitbox_iter = 0; hitbox_iter < hitbox.getCircleHitboxesQuantity(); hitbox_iter++) {
			if (circleHitboxes[iter].checkForIntersection(hitbox.getCircleHitbox(hitbox_iter)) == true) {
				return true;
			}
		}
	}

	return false;
}


Hitbox::~Hitbox() {
    if(rectangularHitboxesQuant == 0 ) delete[] rectangularHitboxes;
	if(circleHitboxesQuant == 0) delete[] circleHitboxes;

	rectangularHitboxesQuant = 0;
	circleHitboxesQuant = 0;
	
}