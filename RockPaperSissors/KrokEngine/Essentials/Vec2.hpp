#pragma once
#include <iostream>

/// <summary>
/// 2D Vector. Meant for 2D physics calculations.
/// </summary>
struct Vec2
{
	float x;
	float y;

	Vec2(float pX = 0, float pY = 0);
	Vec2(float pX, float pY, bool normalized);

	Vec2& operator =(const Vec2& other);

	float GetLength();
	Vec2 Normalized();
	void Normalize();

	void SetLength(float length);
	void SetXY(float pX, float pY);

	static Vec2 LinInt(Vec2 left, Vec2 right, float interpolater);
	static float Deg2Rad(float degree);
	static float Rad2Deg(float radians);
	static Vec2 GetUnitVectorDeg(float degrees);
	static Vec2 GetUnitVectorRad(float radians);

	void SetAngleDegrees(float degrees);
	void SetAngleRadians(float radians);

	float GetAngleRadians();
	float GetAngleDegrees();
	void RotateRadians(float radians);
	void RotateDegrees(float degrees);
	void RotateAroundDegrees(float degrees, Vec2 around);
	void RotateAroundRadians(float radians, Vec2 around);

	static float normalizeDeg(float degree);

	void RotateTowardsDegrees(float targetDegrees, float stepDegrees);

	float Dot(Vec2 other);
	static float VectorDotProduct(Vec2 a, Vec2 b);

	Vec2 Normal();
	void Reflect(Vec2 pNormal, float pBounciness = 1);

	friend std::ostream& operator << (std::ostream& out, const Vec2& vec);
};

Vec2 operator +(Vec2 left, Vec2 right);
Vec2 operator +=(Vec2 left, Vec2 right);

Vec2 operator -(Vec2 left, Vec2 right);
Vec2 operator-=(Vec2 left, Vec2 right);

Vec2 operator *(Vec2 left, float right);
Vec2 operator *(float left, Vec2 right);

Vec2 operator *(Vec2 left, Vec2 right);

bool operator ==(Vec2 left, Vec2 right);
bool operator !=(Vec2 left, Vec2 right);
