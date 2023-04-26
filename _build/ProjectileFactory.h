#pragma once
#include "Projectile.h"

class ProjectileFactory
{
public:
	ProjectileFactory() {}
	~ProjectileFactory() {}
	Projectile* createProjectile(int posx, int posy)
	{
		return new Projectile(posx, posy);
	}
};