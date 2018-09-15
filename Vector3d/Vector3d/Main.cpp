#include <iostream>

template<class TYPE>
class Vector3D
{
public:
	TYPE x, y, z;

public:

	// Constructors
	Vector3D() {}

	Vector3D(const TYPE& _x, const TYPE& _y, const TYPE& _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3D(const Vector3D& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	// Operator overloading
	Vector3D operator+(const Vector3D& v) const
	{
		Vector3D u;
		u.x = x + v.x;
		u.y = y + v.y;
		u.z = z + v.z;

		return u;
	}
	
	Vector3D operator-(const Vector3D& v) const
	{
		Vector3D u;
		u.x = x - v.x;
		u.y = y - v.y;
		u.z = z - v.z;

		return u;
	}

	Vector3D& operator+=(const Vector3D& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return(*this);
	}

	Vector3D& operator-=(const Vector3D& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return(*this);
	}

	Vector3D& operator=(const Vector3D& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return (*this);
	}

	bool operator==(const Vector3D v) const
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

	bool IsZero() const
	{
		return (x == 0 && y == 0 && z == 0);
	}

	TYPE DistanceTo(const Vector3D& v) const
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
	Vector3D<int> v1(1, 2, 3);
	std::cout << "v1: (" << v1.x << ", " << v1.y << ", " << v1.z << ")" << std::endl;
	Vector3D<int> v2(2, 3, 4);
	std::cout << "v2: (" << v2.x << ", " << v2.y << ", " << v2.z << ")" << std::endl;
	Vector3D<int> r = v1 + v2;
	std::cout << "v1 + v2 = (" << r.x << ", " << r.y << ", " << r.z << ")" << std::endl;
	r = v1 - v2;
	std::cout << "v1 - v2 = (" << r.x << ", " << r.y << ", " << r.z << ")" << std::endl;
	
	v1 += v2;
	std::cout << "v1 += v2 = (" << v1.x << ", " << v1.y << ", " << v1.z << ")" << std::endl;
	v1.x = 1; v1.y = 2; v1.z = 3;
	v1 -= v2;
	std::cout << "v1 -= v2 = (" << v1.x << ", " << v1.y << ", " << v1.z << ")" << std::endl;

	v1 = v2;
	std::cout << "v1 = v2: (" << v1.x << ", " << v1.y << ", " << v1.z << ")" << std::endl;

	system("pause");
	return 0;
}