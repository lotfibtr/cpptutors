#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <assert.h>
#include "Vector3.h"
using namespace std;


Vector3::Vector3(float x, float y, float z) noexcept(false) : m_x(x), m_y(y), m_z(z)
{
	//std::cout << "user defined constructor\n";
}

void Vector3::Scale(float scalar) noexcept
{
	m_x *= scalar;
	m_y *= scalar;
	m_z *= scalar;
}

float Vector3::Length() const noexcept
{
	float squared_sum = (m_x * m_x) + (m_y * m_y) + (m_z * m_z);
	float length = sqrtf(squared_sum);

	return length;
}

void Vector3::Normalize() noexcept
{
	float InvLength = 0.0f;
	if (this->Length() == 0)
	{
		InvLength = 0.0f;
		cout << "Length is zero! : ";
	}
	else
	{
		InvLength = 1 / this->Length();
	}
	
	Vector3 v = *this;

	v.m_x *= InvLength;
	v.m_y *= InvLength;
	v.m_z *= InvLength;

	*this = v;
}

float Vector3::Distance(Vector3& v) noexcept
{
	float dx = m_x - v.m_x;
	float dy = m_y - v.m_y;
	float dz = m_z - v.m_z;

	Vector3 d(dx, dy, dz);

	float distance = Length(d);

	return distance;
}

float Vector3::Dot(const Vector3& v) const noexcept
{
	float dot = m_x * v.m_x + m_y * v.m_y + m_z * v.m_z;
	return dot;
}

void Vector3::Cross(const Vector3& V, Vector3& result) const noexcept
{
	const Vector3 v1 = *this;
	const Vector3 v2 = V;
	float nx = v1.m_y * v2.m_z - v1.m_z * v2.m_y;
	float ny = v1.m_z * v2.m_x - v1.m_x * v2.m_z;
	float nz = v1.m_x * v2.m_y - v1.m_y * v2.m_x;
	const Vector3 R = Vector3(nx, ny, nz);

	result = R;
}

Vector3 Vector3::Cross(const Vector3& V) const noexcept
{
	const Vector3 v1 = *this;
	const Vector3 v2 = V;
	float nx = v1.m_y * v2.m_z - v1.m_z * v2.m_y;
	float ny = v1.m_z * v2.m_x - v1.m_x * v2.m_z;
	float nz = v1.m_x * v2.m_y - v1.m_y * v2.m_x;
	const Vector3 R = Vector3(nx, ny, nz);

	return R;
}

float Vector3::CrossLength(const Vector3& V) const noexcept
{
	Vector3 vec = this->Cross(V);
	float length = vec.Length();

	return length;
}

float Vector3::CrossLength(const Vector3& V, float angle) const noexcept
{
	Vector3 v1 = *this;
	float l1 = v1.Length();
	float l2 = V.Length();

	

	float sinVal = sinf(angle);
	if (Equals(sinVal))
		sinVal = floor(fabs(sinf(sinVal)));

	float crossLength = l1 * l2 * sinVal;

	return crossLength;
}

float Vector3::Length(Vector3& v) noexcept
{
	float squared_sum = (v.m_x * v.m_x) + (v.m_y * v.m_y) + (v.m_z * v.m_z);
	float length = sqrtf(squared_sum);

	return length;
}

float Vector3::Distance(const Vector3& v1, const Vector3& v2) noexcept
{
	float dx = v1.m_x - v2.m_x;
	float dy = v1.m_y - v2.m_y;
	float dz = v1.m_z - v2.m_z;

	Vector3 d(dx, dy, dz);

	float distance = Length(d);

	return distance;
}

Vector3 Vector3::ProjV1OnV2(const Vector3& v1, const Vector3& v2) noexcept
{
	float fdot = v1.Dot(v2);
	float fNormV2 = v2.Length();
	assert(fNormV2);
	float fNormV2Squared = fNormV2 * fNormV2;

	Vector3 proj = (fdot / fNormV2Squared) * v2;

	return proj;
}

float* Vector3::Angle(const Vector3& v1, const Vector3& v2) noexcept
{
	float fdot = v1.Dot(v2);
	float l1 = v1.Length();
	float l2 = v2.Length();
	float temp = fdot / (l1 * l2);

	float AngleInRadians = acosf(temp); // in radians
	// Convert to degrees
	float AngleInDegrees = (AngleInRadians * 180.0f) / (float)M_PI;
	
	static float angles[2];	
	angles[0] = AngleInRadians;
	angles[1] = AngleInDegrees;


	return angles;
}

void Vector3::Orthogonalize(Vector3& v1, Vector3& v2, Vector3& v3) noexcept
{
	// Gram - Schmidt Process
	Vector3 w1 = v1;
	Vector3 w2 = v2 - ProjV1OnV2(v2, w1);
	Vector3 w3 = v3 - ProjV1OnV2(v3, w1) - ProjV1OnV2(v3, w2);

	v2 = w2;
	v3 = w3;
}

void Vector3::Orthonormalize(Vector3& v1, Vector3& v2, Vector3& v3) noexcept
{
	// Gram-Schmidt Process
	Orthogonalize(v1, v2, v3);

	//Vector3 w2 = v2 * (1 / v2.Length());
	//Vector3 w3 = v3 * (1 / v3.Length());
	v1.Normalize();
	Vector3 w1 = v1;
	v2.Normalize();
	Vector3 w2 = v2;
	v3.Normalize();
	Vector3 w3 = v3;

	v1 = w1;
	v2 = w2;
	v3 = w3;
}

bool Vector3::Equals(float value) noexcept
{
	const float Epsilon = 0.00001f;
	// Is the distance between lhs and rhs less than EPSILON?
	return fabs(value) < Epsilon ? true : false;
}
