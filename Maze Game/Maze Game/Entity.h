#pragma once

//delcaring class
class Entity
{
	//making entity fuction public so it can be used in other .cpp files
public:
	//delcaring entity function
	Entity();
	Entity(int x, int y) {
		//x below is assigned to the int x above. same with y
		this->x = x;
		this->y = y;
	}
	int x = 0;
	int y = 0;
	//declaring colliding function
	void setXY(int x, int y);
	bool colliding(Entity target);
	bool colliding(int position[2]);

};
