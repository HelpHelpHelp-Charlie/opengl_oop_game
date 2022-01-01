#include "Vec2.h"

Vec2 Vec2::operator+(const Vec2 & v)
{
	Vec2 ans(this->x + v.x, this->y + v.y);
	return ans;
}

std::ostream & operator<<(std::ostream &s, const Vec2 &p)
{
		s << "(" << p.x << "," << p.y << ")";
		return s;
	
}
