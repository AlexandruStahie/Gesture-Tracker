#ifndef OBJECT_H
#define OBJECT_H

#include "Point.h"

#include <iostream>
#include <vector>
#include <string>

class Object
{
public:
	//constructor
	Object() {};
	Object(std::vector<Point> vecPathCoords);
	~Object();

	//copy constructor
	Object(Object &object);
	//operator=
	void operator=(Object &object);

private:
	//points which represent an object
	std::vector<Point> _vecPathCoords;
	//type of an Object ( default = "Unknown")
	std::string type;
};

#endif // !OBJECT_H