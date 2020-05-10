#include "Entity.h"

Entity::Entity()
{
}

void Entity::setXY(int x, int y) { this->x = x; this->y = y; }

bool Entity::colliding(Entity target) { return this->x == target.x && this->y == target.y; }
bool Entity::colliding(int position[2]) { return this->x == position[0] && this->y == position[1]; }
