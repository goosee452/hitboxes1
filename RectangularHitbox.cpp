#include "RectangularHitbox.h"
#include "CircleHitbox.h"

RectangularHitbox::RectangularHitbox() {

	basePoint.setCoordinates(0, 0);
	pointA.setCoordinates(0, 0);
	pointB.setCoordinates(0, 0);
	pointC.setCoordinates(0, 0);
	pointD.setCoordinates(0, 0);

}

void RectangularHitbox::setPoints(Point initPointA, Point initPointC) {

	pointA.setCoordinates(initPointA.getCoordX(), initPointA.getCoordY());
	pointC.setCoordinates(initPointC.getCoordX(), initPointC.getCoordY());

	if (pointC.getCoordX() < pointA.getCoordX()){
		Point temp;
		temp.setCoordinates(pointA.getCoordX(), pointA.getCoordY());
		pointA.setCoordinates(pointC.getCoordX(), pointC.getCoordY());
		pointC.setCoordinates(temp.getCoordX(), temp.getCoordY());
	}
	if (pointA.getCoordY() < pointC.getCoordY()) {
		pointB.setCoordinates(pointA.getCoordX(), pointC.getCoordY());
		pointD.setCoordinates(pointC.getCoordX(), pointA.getCoordY());
	}
	else if (pointA.getCoordY() > pointC.getCoordY()) {
		pointB.setCoordinates(pointA.getCoordX(), pointC.getCoordY());
		pointD.setCoordinates(pointC.getCoordX(), pointA.getCoordY());
		Point temp;
		temp.setCoordinates(pointA.getCoordX(), pointA.getCoordY());
		pointA.setCoordinates(pointB.getCoordX(), pointB.getCoordY());
		pointB.setCoordinates(temp.getCoordX(), temp.getCoordY());
		temp.setCoordinates(pointC.getCoordX(), pointC.getCoordY());
		pointC.setCoordinates(pointD.getCoordX(), pointD.getCoordY());
		pointD.setCoordinates(temp.getCoordX(), temp.getCoordY());
	}
}


void RectangularHitbox::setBasePoint(Point initBasePoint) {
	basePoint.setCoordinates(initBasePoint.getCoordX(), initBasePoint.getCoordX());
}

Point RectangularHitbox::getBasePoint(){
	return basePoint;
}
Point RectangularHitbox::getPointA(){
	return  pointA;
}
Point RectangularHitbox::getPointB(){
	return pointB;
}
Point RectangularHitbox::getPointC(){
	return pointC;
}
Point RectangularHitbox::getPointD(){
	return pointD;
}


int RectangularHitbox::getPointA_currCoordX(){
	return (basePoint.getCoordX() + pointA.getCoordX());
}

int RectangularHitbox::getPointA_currCoordY() {
	return (basePoint.getCoordY() + pointA.getCoordY());
}
int RectangularHitbox::getPointB_currCoordX() {
	return (basePoint.getCoordX() + pointB.getCoordX());
}
int RectangularHitbox::getPointB_currCoordY() {
	return (basePoint.getCoordY() + pointB.getCoordY());
}
int RectangularHitbox::getPointC_currCoordX() {
	return (basePoint.getCoordX() + pointC.getCoordX());
}
int RectangularHitbox::getPointC_currCoordY() {
	return (basePoint.getCoordY() + pointC.getCoordY());
}
int RectangularHitbox::getPointD_currCoordX() {
	return (basePoint.getCoordX() + pointD.getCoordX());
}
int RectangularHitbox::getPointD_currCoordY() {
	return (basePoint.getCoordY() + pointD.getCoordY());
}



bool RectangularHitbox::checkForIntersection(RectangularHitbox hitbox){

	bool hitboxesHaveSameCoordsX = false;
	bool hitboxesHaveSameCoordsY = false;



	if (getPointA_currCoordX() <= hitbox.getPointA_currCoordX()
		&& getPointD_currCoordX() >= hitbox.getPointA_currCoordX()) {
		hitboxesHaveSameCoordsX = true;
	}
	else if (getPointA_currCoordX() <= hitbox.getPointD_currCoordX()
		&& getPointD_currCoordX() >= hitbox.getPointD_currCoordX()) {
		hitboxesHaveSameCoordsX = true;
	}
	else if (hitbox.getPointA_currCoordX() <= getPointA_currCoordX() &&
		hitbox.getPointD_currCoordX() > getPointD_currCoordX()) {
		hitboxesHaveSameCoordsX = true;
	}


	if (getPointA_currCoordY() <= hitbox.getPointA_currCoordY()
		&& getPointB_currCoordY() >= hitbox.getPointA_currCoordY()) {
		hitboxesHaveSameCoordsY = true;
	}
	else if (getPointA_currCoordY() <= hitbox.getPointB_currCoordY()
		&& getPointB_currCoordY() >= hitbox.getPointB_currCoordY()) {
		hitboxesHaveSameCoordsY = true;
	}
	else if (hitbox.getPointA_currCoordY() <= getPointA_currCoordY() &&
		hitbox.getPointB_currCoordY() >= getPointB_currCoordY()) {
		hitboxesHaveSameCoordsY = true;
	}



	if (hitboxesHaveSameCoordsX == true && hitboxesHaveSameCoordsY == true) {
		return true;
	}
	else {
		return false;
	}

}


bool RectangularHitbox::checkForIntersection(CircleHitbox hitbox) {
	if (sqrt(((hitbox.getBasePoint().getCoordX() - getPointA_currCoordX()) *
		(hitbox.getBasePoint().getCoordX() - getPointA_currCoordX())) +
		((hitbox.getBasePoint().getCoordY() - getPointA_currCoordY()) *
		(hitbox.getBasePoint().getCoordY() - getPointA_currCoordY()))) - hitbox.getRadius() < 0){
		return true;
	}

	if (sqrt(((hitbox.getBasePoint().getCoordX() - getPointB_currCoordX()) *
		(hitbox.getBasePoint().getCoordX() - getPointB_currCoordX())) +
		((hitbox.getBasePoint().getCoordY() - getPointB_currCoordY()) *
			(hitbox.getBasePoint().getCoordY() - getPointB_currCoordY()))) - hitbox.getRadius() < 0) {
		return true;
	}

	if (sqrt(((hitbox.getBasePoint().getCoordX() - getPointC_currCoordX()) *
		(hitbox.getBasePoint().getCoordX() - getPointC_currCoordX())) +
		((hitbox.getBasePoint().getCoordY() - getPointC_currCoordY()) *
			(hitbox.getBasePoint().getCoordY() - getPointC_currCoordY()))) - hitbox.getRadius() < 0) {
		return true;
	}

	if (sqrt(((hitbox.getBasePoint().getCoordX() - getPointC_currCoordX()) *
		(hitbox.getBasePoint().getCoordX() - getPointC_currCoordX())) +
		((hitbox.getBasePoint().getCoordY() - getPointC_currCoordY()) *
			(hitbox.getBasePoint().getCoordY() - getPointC_currCoordY()))) - hitbox.getRadius() < 0) {
		return true;
	}

	if (hitbox.getBasePoint().getCoordX() >= getPointA_currCoordX() && hitbox.getBasePoint().getCoordX() <= getPointC_currCoordX()) {

		if (hitbox.getBasePoint().getCoordY() + hitbox.getRadius() >= getPointA_currCoordY() && 
			hitbox.getBasePoint().getCoordY() + hitbox.getRadius() <= getPointC_currCoordY()) {
			return true;
		}
		if (hitbox.getBasePoint().getCoordY() - hitbox.getRadius() >= getPointA_currCoordY() && 
			hitbox.getBasePoint().getCoordY() - hitbox.getRadius() <= getPointC_currCoordY()) {
			return true;
		}
		if (hitbox.getBasePoint().getCoordY() + hitbox.getRadius() >= getPointA_currCoordY() &&
			hitbox.getBasePoint().getCoordY() - hitbox.getRadius() <= getPointC_currCoordY()) {
			return true;
		}
	}

	if (hitbox.getBasePoint().getCoordY() >= getPointA_currCoordY() && hitbox.getBasePoint().getCoordY() <= getPointC_currCoordY()) {

		if (hitbox.getBasePoint().getCoordX() + hitbox.getRadius() >= getPointA_currCoordX() &&
			hitbox.getBasePoint().getCoordX() + hitbox.getRadius() <= getPointC_currCoordX()) {
			return true;
		}
		if (hitbox.getBasePoint().getCoordX() - hitbox.getRadius() >= getPointA_currCoordX() && 
			hitbox.getBasePoint().getCoordX() - hitbox.getRadius() <= getPointC_currCoordX()) {
			return true;
		}
		if (hitbox.getBasePoint().getCoordX() + hitbox.getRadius() >= getPointA_currCoordX() &&
			hitbox.getBasePoint().getCoordX() - hitbox.getRadius() <= getPointC_currCoordX()) {
			return true;
		}
	}


	return false;
}

