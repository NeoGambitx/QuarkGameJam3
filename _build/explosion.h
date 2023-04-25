#pragma once
#include <raylib.h>

class Explosion {

private:
	Texture2D sprite;
	Vector2 position;
	Rectangle rec;
	int frame;
	bool done;
public:
	Explosion(Vector2 pos, bool tipo);
	~Explosion();
	void mostrarExplosion();
	void animar();
	bool isItDone();
};