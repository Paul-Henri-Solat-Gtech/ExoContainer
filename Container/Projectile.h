#ifndef projectil_h
#define projectil_h

#include <iostream>

class Projectile
{
public:
	template<typename T>
	Projectile(float projSpeed, T projDamage, float projPosX, float projPosY, float projDirX, float projDirY) :speed(projSpeed), positionX(projPosX), positionY(projPosY), directionX(projDirX), directionY(projDirY)
	{
		GetDamageType(projDamage);
	}

	void GetDamageType(int dmgValue);
	void GetDamageType(float dmgValue);

	void Update();
	void Move();
	void InflictDamage(int dmg);
	void InflictDamage(float dmg, float radius);
private:
	float speed;
	int damage;
	float positionX, positionY;
	float directionX, directionY;
};

#endif




