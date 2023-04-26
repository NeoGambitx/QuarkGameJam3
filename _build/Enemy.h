#pragma once
class Enemy
{
protected:
	int positionX = 0;
	int positionY = 0;
	int damage = 0;
	int health = 0;
public:
	Enemy() {}
	//virtual ~Enemy() = 0;
	virtual int getPositionX() = 0;
	virtual void setPositionX(int posX) = 0;
	virtual int getPositionY() = 0;
	virtual void setPositionY(int posy) = 0;
	virtual void movementMechanics() = 0;
};