#include "Projectile.h"

void Projectile::GetDamageType(int dmgValue)
{
	std::cout << "Dmg is Int" << std::endl;
	InflictDamage(dmgValue);
}
void Projectile::GetDamageType(float dmgValue)
{
	std::cout << "Dmg is Float" << std::endl;
	InflictDamage(dmgValue, dmgValue);
}

void Projectile::Update() 
{
	Move();
}

void Projectile::Move() 
{
	while (positionX != directionX && positionY != directionY)
	{
		if (positionX < directionX)
		{
			positionX += speed;
		}
		else
		{
			positionX -= speed;
		}
		if (positionY < directionY)
		{
			positionY += speed;
		}
	}
}

void Projectile::InflictDamage(int dmg) 
{
	if (positionX == directionX && positionY == directionY) 
	{
		std::cout << "Ennemy Touched ! -" << dmg << "hp" << std::endl;
	}
	std::cout << "Ennemy Touched ! -" << dmg << "hp" << std::endl;
}
void Projectile::InflictDamage(float dmg, float radius)
{
	if (positionX == directionX && positionY == directionY)
	{
		std::cout << "Ennemy Explosed ! -" <<dmg << "hp on a surface of " << dmg*5 << std::endl;
	}
	std::cout << "Ennemy Explosed ! -" << dmg << "hp on a surface of " << dmg * 5 << std::endl;
}