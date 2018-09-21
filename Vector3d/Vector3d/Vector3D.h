#ifndef __Vector3D_H__
#define __Vector3D_H__

template<class TYPE>
class Vector3D
{
public:
	TYPE x, y, z;

public:

	// Constructors
	Vector3D()
	{}

	Vector3D(const TYPE& x, const TYPE& y, const TYPE& z) :
		x(x),
		y(y),
		z(z) {}
	
	Vector3D(const Vector3D& v) :
		x(v.x),
		y(v.y),
		z(v.z) {}
	
	// Operator overloading
	Vector3D operator+(const Vector3D& v) const
	{
		return (Vector3D)(x + v.x, y + v,y, z + v.z);
	}

	Vector3D operator-(const Vector3D& v) const
	{
		return (Vector3D)(x - v.x, y - v, y, z - v.z);
	}

	Vector3D& operator+=(const Vector3D& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return (*this);
	}

	Vector3D& operator-=(const Vector3D& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return (*this);
	}

	Vector3D& operator=(const Vector3D& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return (*this);
	}

	bool operator==(const Vector3D& v) const
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
		TYPE disX = x - v.x;
		TYPE disY = y - v.y;
		TYPE disZ = z - v.z;

		return (TYPE)sqrt(disX * disX + disY * disY + disZ * disZ);
	}

	TYPE DistanceSquared(const Vector3D& v) const
	{
		TYPE disX = x - v.x;
		TYPE disY = y - v.y;
		TYPE disZ = z - v.z;

		return (TYPE)(disX * disX + disY * disY + disZ * disZ);
	}
};

#endif // __Vector3D_H__