#pragma once
class Projectile
{
private:
	int positionX;
	int positionY;
public:
	Projectile(int posX, int posY);
	~Projectile();
	int getPositionX();
	void setPositionX(int newPosX);
	int getPositionY();
	void setPositionY(int newPosY);
};