#include "Point.h"


Point::Point() {
    coordX = 0;
    coordY = 0;
}

void Point::setCoordX(int initCoordX) {
        coordX = initCoordX;
}

void Point::setCoordY(int initCoordY) {  
        coordY = initCoordY;
}

int Point::getCoordX() {
    return coordX;
}

int Point::getCoordY() {
    return coordY;
}

void Point::setCoordinates(int initCoordX, int initCoordY) {  
        coordX = initCoordX;    
        coordY = initCoordY;    
}