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
	void Normalize()
	{
		TYPE m = std::sqrt((x * x) + (y * y) + (z * z));

		x = x / m;
		y = y / m;
		z = z / m;
	}

};

int main()
{
	

	system("pause");
	return 0;
}