
#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{
public:
	Vector3() noexcept = default;// { std::cout << "Default constructor\n"; };
	Vector3(float x, float y, float z) noexcept(false);
	~Vector3() = default;

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
		vec.m_x = m_x + v.m_x;
		vec.m_y = m_y + v.m_y;
		vec.m_z = m_z + v.m_z;

		return vec;
	};

	inline Vector3& operator*= (float S) noexcept
	{
		Vector3 v1 = Vector3(this->m_x, this->m_y, this->m_z);
		v1.m_x *= S;
		v1.m_y *= S;
		v1.m_z *= S;
		this->m_x = v1.m_x;
		this->m_y = v1.m_y;
		this->m_z = v1.m_z;

		return *this;
	}

	inline Vector3& operator/= (float S) noexcept
	{
		Vector3 v1 = Vector3(this->m_x, this->m_y, this->m_z);
		v1.m_x /= S;
		v1.m_y /= S;
		v1.m_z /= S;
		this->m_x = v1.m_x;
		this->m_y = v1.m_y;
		this->m_z = v1.m_z;

		return *this;
	}

	inline Vector3& operator/ (float S) noexcept
	{
		Vector3 v1 = Vector3(this->m_x, this->m_y, this->m_z);
		v1.m_x /= S;
		v1.m_y /= S;
		v1.m_z /= S;
		this->m_x = v1.m_x;
		this->m_y = v1.m_y;
		this->m_z = v1.m_z;

		return *this;
	}	

	// Vector operations
	void Scale(float scalar) noexcept; // Multiply vector by scalar
	float Length() const noexcept;
	void Normalize() noexcept;
	float Distance(Vector3& v) noexcept;
	float Dot(const Vector3& V) const noexcept;
	void Cross(const Vector3& V, Vector3& result) const noexcept;
	Vector3 Cross(const Vector3& V) const noexcept;
	float CrossLength(const Vector3& V) const noexcept;
	float CrossLength(const Vector3& V, float angle) const noexcept;
	// Static functions
	static float Length(Vector3& v) noexcept;
	static float Distance(const Vector3& v1, const Vector3& v2) noexcept;
	static Vector3 ProjV1OnV2(const Vector3& v1, const Vector3& v2) noexcept;
	static float* Angle(const Vector3& v1, const Vector3& v2) noexcept;
	static void Orthogonalize(Vector3& v1, Vector3& v2, Vector3& v3) noexcept;
	static void Orthonormalize(Vector3& v1, Vector3& v2, Vector3& v3) noexcept;
	static bool Equals(float value) noexcept;


	float GetX() { return m_x; };
	float GetY() { return m_y; };
	float GetZ() { return m_z; };

private:
	float m_x {0.0f };
	float m_y{ 0.0f };
	float m_z{ 0.0f };
	//std::unique_ptr<float[2]> m_Angles;
};

inline Vector3 operator* (const Vector3& V, float S) noexcept
{
	Vector3 v1 = V;
	v1 *= S;

	return v1;
}

inline Vector3 operator* (float S, const Vector3& V) noexcept
{
	Vector3 v1 = V;
	v1 *= S;

	return v1;
}

#endif
