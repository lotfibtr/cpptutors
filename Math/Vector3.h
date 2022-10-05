#include <cassert>
#include <stdexcept> // To use runtime_error
#include <windows.h>

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{
public:
	Vector3() noexcept = default; // Default constructor
	Vector3(float x, float y, float z) noexcept(false); // Constructor
	~Vector3() = default; // Default destructor

	Vector3(const Vector3&) = default; // Explicit copy constructor
	Vector3& operator= (const Vector3&) = default;// Explicit copy assignment operator
	
	Vector3(Vector3&&) = default; // Explicit move copy constructor
	Vector3& operator= (Vector3&&) = default; // Explicit move assignment operator

	// Unary negation operator
	inline Vector3 operator- ()
	{
		Vector3 vec;
		vec.m_x = -this->m_x;
		vec.m_y = -this->m_y;
		vec.m_z = -this->m_z;

		return vec;
	};

	// Binary negation operator
	inline Vector3 operator- (const Vector3& v)
	{
		Vector3 vec;
		vec.m_x = m_x - v.m_x;
		vec.m_y = m_y - v.m_y;
		vec.m_z = m_z - v.m_z;

		return vec;
	};

	// Binary sum operator
	inline Vector3 operator+ (const Vector3& v) noexcept
	{
		Vector3 vec;
		vec.m_x = this->m_x + v.m_x;
		vec.m_y = this->m_y + v.m_y;
		vec.m_z = this->m_z + v.m_z;

		return vec;
	};

	// (*) operator overloaded
	inline Vector3& operator*= (float S) noexcept
	{
		this->m_x *= S;
		this->m_y *= S;
		this->m_z *= S;

		return *this;
	}

	// (/=) operator overloaded
	inline Vector3& operator/= (float S) noexcept
	{		
		// If denominator is Zero
		// throw runtime_error
		assert(S != 0.0f); // assertion fails

		this->m_x /= S;
		this->m_y /= S;
		this->m_z /= S;

		return *this;
	}

	// (/) operator overloaded
	inline Vector3& operator/ (float S) noexcept
	{
		// If denominator is Zero
		// throw runtime_error
		//assert(S != 0.0f); // assertion fails

		if (S == 0.0f)
		{
			MessageBoxA(NULL, "Error dividing by zero", "Vector : divide by scalar", MB_ICONERROR);

			exit(-1);
		}

		this->m_x /= S;
		this->m_y /= S;
		this->m_z /= S;


		return *this;
	}

	// Vector operations
	void Scale(float scalar) noexcept; // Multiply vector by scalar
	float Length() const noexcept; // Vector norm
	void Normalize() noexcept; // Normalize vector (length = 1)
	float Distance(Vector3& v) noexcept; // Calculate distance between 2 points
	float Dot(const Vector3& V) const noexcept; // Scalar product
	void Cross(const Vector3& V, Vector3& result) const noexcept; // Cross product
	Vector3 Cross(const Vector3& V) const noexcept; // Cross product
	float CrossLength(const Vector3& V) const noexcept; // Calculate norm of cross product vector
	float CrossLength(const Vector3& V, float angle) const noexcept; // Calculate norm of cross product vector

	// Static functions
	static float Length(Vector3& v) noexcept; // Norm of a vector
	static float Distance(const Vector3& v1, const Vector3& v2) noexcept; // Calculate distance between 2 points
	static Vector3 ProjV1OnV2(const Vector3& v1, const Vector3& v2) noexcept; // Return projected vector
	static float* Angle(const Vector3& v1, const Vector3& v2) noexcept; // Calculate angle between 2 vectors
	static void Orthogonalize(Vector3& v1, Vector3& v2, Vector3& v3) noexcept; // Orthogonalize 3 vectors
	static void Orthonormalize(Vector3& v1, Vector3& v2, Vector3& v3) noexcept; // Normalize orthogonalized vectors
	static bool Equals(float value) noexcept; // Test if value is less than epsilon

	// Accessors
	float GetX() { return m_x; };
	float GetY() { return m_y; };
	float GetZ() { return m_z; };

private:
	float m_x {0.0f };
	float m_y{ 0.0f };
	float m_z{ 0.0f };
};

// Overload (*) operator (2 parameters)
inline Vector3 operator* (const Vector3& V, float S) noexcept
{
	Vector3 v1 = V;
	v1 *= S;

	return v1;
}

// Overload (*) operator (2 parameters)
inline Vector3 operator* (float S, const Vector3& V) noexcept
{
	Vector3 v1 = V;
	v1 *= S;

	return v1;
}

#endif
