#pragma once
#include "Projectile.h"

class ProjectileFactory
{
public:
	ProjectileFactory() {}
	~ProjectileFactory() {}
	Projectile* createProjectile(int claseDeProjectil, int indice, Vector2 Pos, float rotation, bool _isAnEnemyShoot)
	{
		return new Projectile(claseDeProjectil, indice, Pos, rotation, _isAnEnemyShoot);
	}
};