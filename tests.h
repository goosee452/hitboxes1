#pragma once
#include "CircleHitbox.h"
#include "RectangularHitbox.h"
#include <string>

std::string RectangularHitboxesIntersectionTest(int it) {

	if (it > 11 || it < 0)return "wrong iterator\n";
	int iterCopy = it;

	int numbers[88]{
	/*1*/	0, 0, 5, 5,    10, 10, 5,5,
	/*2*/	5, 4, 9, 2,    7, 5, 15, 284,
	/*3*/	0, 0, 0, 0,    0, 0, 0, 0,
	/*4*/	6, 7, 10, 8,   10, 20, 30, 8,
	/*5*/	9, 3, 8, 2,    1, 0, 8, 2,
	/*6*/	0, 90, 75, 150,   5, 40, 20, 100,
	/*7*/	0, 20, 5, 0,    90, 3, 2, 3,
	/*8*/	20, 45, 60, 75,   40, 50, 55, 60,
	/*9*/	15, 4, 25, 7,    24, 6, 20, 5,
	/*10*/	90, 4, 45, 8,    9, 2, 15, 1,
	/*11*/	4, 4, 4, 4,    5, 5, 5, 5
	};

	bool results[11]{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 };

	it *= 8;

	RectangularHitbox a, b;
	Point c, d;

	c.setCoordinates(numbers[it], numbers[it + 1]);
	d.setCoordinates(numbers[it + 2], numbers[it + 3]);

	a.setPoints(c, d);

	c.setCoordinates(numbers[it + 4], numbers[it + 5]);
	d.setCoordinates(numbers[it + 6], numbers[it + 7]);

	b.setPoints(c, d);

	return ((std::to_string(a.checkForIntersection(b)) + " " + std::to_string(results[iterCopy])) + "\n");
}


std::string CircleHitboxesIntercectionTest(int it) {

	if (it > 8 || it < 0)return "wrong iterator\n";
	int iterCopy = it;

	int numbers[48]{
	/*1*/5, 5, 6,   10, 5, 6,
	/*2*/0, 0, 5,   10, 0, 5,
	/*3*/15, 8, 3,  20, 5, 3,
	/*4*/9, 9, 1,   10, 10, 1,
	/*5*/8, 9, 2,   5, 6, 2,
	/*6*/25, 25, 25,   50, 50, 50,
	/*7*/98, 10, 5,   105, 10, 2,
	/*8*/3, 5, 2,   3, 3, 0
	};

	bool results[8]{ 1, 1, 1, 1, 0, 1, 1, 1 };

	it *= 6;

	CircleHitbox a, b;
	
	a.setBasePoint(numbers[it], numbers[it + 1]);
	a.setRadius(numbers[it + 2]);

	b.setBasePoint(numbers[it + 3], numbers[it + 4]);
	b.setRadius(numbers[it + 5]);


	return ((std::to_string(a.checkForIntersection(b)) + " " + std::to_string(results[iterCopy])) + "\n");

}


std::string  CircleAndRectangularHitboxesIntersectionTest(int it) {

	if (it > 12 || it < 0)return "wrong iterator\n";

	int iterCopy = it;

	int numbers[84]{
		/*1*/0, 0, 5, 5,   2, 2, 2,
		/*2*/5, 7, 10, 2,   14, 14, 3,
		/*3*/24, 32, 10, 9,   7, 6, 9,
		/*4*/0, 0, 0, 0,   0, 0, 999,
		/*5*/2, 2, 4, 4,   6, 3, 2,
		/*6*/72, 0, 24, 50,   50, 25, 10,
		/*7*/7, 0, 2, 5,   5, 2, 1,
		/*8*/5, 4, 3, 2,   7, 6, 3,
		/*9*/10, 10, 20, 20,   5, 5, 7,
		/*10*/5, 5, 7, 7,   6, 6, 2,
		/*11*/54, 25, 37, 15,   45, 20, 40,
		/*12*/5, 7, 9, 10,   12, 8, 3,
	};

	bool results[12]{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 };
    it *= 7;

	CircleHitbox a;
	RectangularHitbox b;

	Point c, d;
	c.setCoordinates(numbers[it], numbers[it + 1]);
	d.setCoordinates(numbers[it + 2], numbers[it + 3]);

	b.setPoints(c, d);
	a.setBasePoint(numbers[it + 4], numbers[it + 5]);
	a.setRadius(numbers[it + 6]);

	return ((std::to_string(a.checkForIntersection(b)) + " " + std::to_string(results[iterCopy])) + " " 
		+ std::to_string(b.checkForIntersection(a)) + " " + std::to_string(results[iterCopy]) + "\n");
}