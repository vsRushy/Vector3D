#include <iostream>

template<class TYPE>
class Vector3D
{
public:
	TYPE x, y, z;

public:

	// Constructors
	Vector3D() {}

	Vector3D(TYPE _x, TYPE _y, TYPE _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3D(Vector3D& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	// Operator overloading
	Vector3D operator+(Vector3D& v)
	{
		Vector3D u;
		u.x = x + v.x;
		u.y = y + v.y;
		u.z = z + v.z;

		return u;
	}
	
	Vector3D operator-(Vector3D& v)
	{
		Vector3D u;
		u.x = x - v.x;
		u.y = y - v.y;
		u.z = z - v.z;

		return u;
	}

	Vector3D operator+=(Vector3D& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return(*this);
	}

	Vector3D operator-=(Vector3D& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return(*this);
	}

	Vector3D operator=(Vector3D& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return (*this);
	}

	bool operator==(Vector3D v)
	{
		return (x == v.x && y == v.y && z == v.z);
	}

	// Functions
	Vector3D& Normalize()
	{
		TYPE m = sqrt(x * x + y * y + z * z);

		if (m != 0)
		{
			x /= m;
			y /= m;
			z /= m;
		}
		return (*this);
	}

	Vector3D& Zero()
	{
		x = y = z = 0;

		return (*this);
	}

	bool IsZero()
	{
		return (x == 0 && y == 0 && z == 0);
	}

	TYPE DistanceTo(Vector3D& v) const
	{
		TYPE m;

		TYPE disX = x - v.x;
		TYPE disY = y - v.y;
		TYPE disZ = z - v.z;

		m = sqrt(disX * disX + disY * disY + disZ * disZ);

		return m;
	}
};

int main()
{
	

	system("pause");
	return 0;
}