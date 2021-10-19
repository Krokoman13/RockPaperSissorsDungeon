#include <cmath>
#include "Vec2.hpp"
#define M_PI          3.141592653589793238462643383279502884L /* pi */
//------------------------------------------------------------------------------------------------------------------------
//														+ operator
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Returns the result of adding two vectors(without modifying either of them)
/// </summary>
Vec2 operator +(Vec2 left, Vec2 right)
{
	return Vec2(left.x + right.x, left.y + right.y);
}
Vec2 operator +=(Vec2 left, Vec2 right) {
	left.x += right.x;
	left.y += right.y;
	return left;
}

//------------------------------------------------------------------------------------------------------------------------
//														- operator
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Returns the result of subtracting two vectors(without modifying either of them)
/// </summary>
Vec2 operator -(Vec2 left, Vec2 right)
{
	return Vec2(left.x - right.x, left.y - right.y);
}

Vec2 operator-=(Vec2 left, Vec2 right) {
	left.x -= right.x;
	left.y -= right.y;
	return left;
}


//------------------------------------------------------------------------------------------------------------------------
//														* operator
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Returns the result of multiplying a vector by a float(without modifying either of them)
/// </summary>
Vec2 operator *(Vec2 left, float right)
{
	return Vec2(left.x * right, left.y * right);
}
Vec2 operator *(float left, Vec2 right)
{
	return right * left;
}
Vec2 operator*(Vec2 left, Vec2 right)
{
	return Vec2(left.x * right.x, left.y * right.y);
}
bool operator ==(Vec2 left, Vec2 right)
{
	return left.x == right.x && left.y == right.y;
}
bool operator !=(Vec2 left, Vec2 right)
{
	return left.x != right.x && left.y != right.y;
}

//------------------------------------------------------------------------------------------------------------------------
//														Vec2()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Initializes a new instance of the <see cref="Vec2"/> class.
/// </summary>
Vec2::Vec2(float pX, float pY)
{
	x = pX;
	y = pY;
}

//------------------------------------------------------------------------------------------------------------------------
//														Vec2()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Initializes a new instance of the <see cref="Vec2"/> class.
/// </summary>
Vec2::Vec2(float pX, float pY, bool normalized)
{
	x = pX;
	y = pY;

	if (normalized)
	{
		Normalize();
	}
}

//------------------------------------------------------------------------------------------------------------------------
//														Length()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Returns the length of the current vector
/// </summary>
float Vec2::GetLength()
{
	float _length = sqrt((x * x) + (y * y));     //Using Pythagorean theorem to calculate the length of the vector
	return _length;
}

//------------------------------------------------------------------------------------------------------------------------
//														Normalized()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Returns a normalized version of the current vector without modifying it
/// </summary>
Vec2 Vec2::Normalized()
{
	float pX = x;
	float pY = y;

	float length = GetLength();

	if (length != 0)
	{
		pX /= length;        //Calculate the normalized X value
		pY /= length;        //Calculate the normalized Y value
	}

	Vec2 temp(pX, pY);       //Create a new vector with the normalized X and Y value

	return temp;
}

//------------------------------------------------------------------------------------------------------------------------
//														Normalize()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Normalizes the current vector
/// </summary>
void Vec2::Normalize()
{
	*this = this->Normalized();
}

void Vec2::SetLength(float length)
{
	this->Normalize();
	this->x *= length;
	this->y *= length;
}

//------------------------------------------------------------------------------------------------------------------------
//														SetXY()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Sets the x & y of the current vector to the given two floats
/// </summary>
void Vec2::SetXY(float pX, float pY)
{
	x = pX;
	y = pY;
}

//------------------------------------------------------------------------------------------------------------------------
//														LinInt()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Performs a linear interpolation between two vectors based on the given weighting and returns the result.
/// </summary>
/// <param name='left'>
/// The first vector
/// </param>
/// <param name='right'>
/// The second vector
/// </param>
/// <param name='interpolater'>
/// This number specificifies the percentage of the second(right) vector in the result (If this is 0f: The left vector will be returned. If this is 1f: the right one. If 0.5f it is an average between the two)
/// </param>
Vec2 Vec2::LinInt(Vec2 left, Vec2 right, float interpolater)
{
	return left + interpolater * (right - left);
}

//------------------------------------------------------------------------------------------------------------------------
//														Deg2Rad()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Converts the given degrees to radians
/// </summary>
/// <param name='degree'>
/// The input degree value
/// </param>
float Vec2::Deg2Rad(float degree)
{
	return ((float)M_PI / 180.0f) * degree;
}

//------------------------------------------------------------------------------------------------------------------------
//														Rad2Deg()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Converts the given radians to degrees
/// </summary>	
/// <param name='radians'>
/// The input radians value
/// </param>
float Vec2::Rad2Deg(float radians)
{
	return (180.0f / (float)M_PI) * radians;
}

//------------------------------------------------------------------------------------------------------------------------
//														GetUnitVectorDeg ()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Returns a new vector pointing in the given direction in degrees
/// </summary>
Vec2 Vec2::GetUnitVectorDeg(float degrees)
{
	return GetUnitVectorRad(Vec2::Deg2Rad(degrees));
}

//------------------------------------------------------------------------------------------------------------------------
//														GetUnitVectorRad ()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Returns a new vector pointing in the given direction in radians
/// </summary>
Vec2 Vec2::GetUnitVectorRad(float radians)
{
	float pX = cos(radians);
	float pY = sin(radians);

	return Vec2(pX, pY);
}

//------------------------------------------------------------------------------------------------------------------------
//														SetAngleDegrees ()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Changes the current vector to the given degrees (without changing length)
/// </summary>
void Vec2::SetAngleDegrees(float degrees)
{
	SetAngleRadians(Deg2Rad(degrees));
}

//------------------------------------------------------------------------------------------------------------------------
//														SetAngleRadians ()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Changes the current vector to the given radians (without changing length)
/// </summary>
void Vec2::SetAngleRadians(float radians)
{
	Vec2 temp = Vec2::GetUnitVectorRad(radians);
	temp.SetLength(this->GetLength());

	*this = temp;
}

//------------------------------------------------------------------------------------------------------------------------
//														GetAngleRadians ()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Returns a float calculated to be the current angle of the vector in radians
/// </summary>
float Vec2::GetAngleRadians()
{
	return atan2(y, x);
}

//------------------------------------------------------------------------------------------------------------------------
//														GetAngleDegrees ()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Returns a float calculated to be the current angle of the vector in degrees
/// </summary>
float Vec2::GetAngleDegrees()
{
	return Rad2Deg(GetAngleRadians());
}

//------------------------------------------------------------------------------------------------------------------------
//														RotateRadians ()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Rotate the vector over the given angle in radians
/// </summary>
void Vec2::RotateRadians(float radians)
{
	float pX = x * cos(radians) - y * sin(radians);
	float pY = x * sin(radians) + y * cos(radians);

	*this = Vec2(pX, pY);
}

//------------------------------------------------------------------------------------------------------------------------
//														RotateDegrees ()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Rotate the vector over the given angle in degrees
/// </summary>
void Vec2::RotateDegrees(float degrees)
{
	RotateRadians(Deg2Rad(degrees));
}

//------------------------------------------------------------------------------------------------------------------------
//														RotateAroundDegrees ()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Rotate the vector around the given point over the given angle in degrees
/// </summary>
void Vec2::RotateAroundDegrees(float degrees, Vec2 around)
{
	RotateAroundRadians(Deg2Rad(degrees), around);
}

//------------------------------------------------------------------------------------------------------------------------
//														RotateAroundRadians ()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Rotate the vector around the given point over the given angle in radians
/// </summary>
void Vec2::RotateAroundRadians(float radians, Vec2 around)
{
	*this -= around;
	RotateRadians(radians);
	*this += around;
}

//------------------------------------------------------------------------------------------------------------------------
//														normalizeDeg ()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// The entered degree value is normalized, the returend value cannot be outside (-180, 180) degrees
/// </summary>
float Vec2::normalizeDeg(float degree)
{
	if (degree > 180)
	{
		degree -= 360;
	}
	else if (degree < -180)
	{
		degree += 360;
	}

	return degree;
}

//------------------------------------------------------------------------------------------------------------------------
//														RotateTowardsDegrees()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// The vector will rotate towards the target degrees in given steps
/// </summary>
/// <param name='targetDegrees'>
/// The target degrees for the vector to eventually point too
/// </param>
/// <param name='stepDegrees'>
/// The amount of degrees the vector can turn each time it is called
/// </param>
void Vec2::RotateTowardsDegrees(float targetDegrees, float stepDegrees)
{
	//stepDegrees = Mathf.Abs(stepDegrees);
	float diffrence = targetDegrees - this->GetAngleDegrees();

	diffrence = normalizeDeg(diffrence);

	if (abs(diffrence) <= stepDegrees)
	{
		SetAngleDegrees(targetDegrees);
	}
	else if (diffrence < 0)
	{
		this->RotateDegrees(-stepDegrees);
	}
	else if (diffrence > 0)
	{
		this->RotateDegrees(stepDegrees);
	}
}

//------------------------------------------------------------------------------------------------------------------------
//														Dot()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Will calculate the dot product of a given vector and itself
/// </summary>
float Vec2::Dot(Vec2 other)
{
	return x * other.x + y * other.y; ;
}

//------------------------------------------------------------------------------------------------------------------------
//														VectorDotProduct()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Will calculate the dot product of two given vectors
/// </summary>
float Vec2::VectorDotProduct(Vec2 a, Vec2 b)
{
	return a.Dot(b);
}

//------------------------------------------------------------------------------------------------------------------------
//														Normal()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Returns a normal to this vector
/// </summary>
Vec2 Vec2::Normal()
{
	Vec2 NormalVec = Vec2(-y, x);
	return NormalVec.Normalized();
}

//------------------------------------------------------------------------------------------------------------------------
//														Reflect()
//------------------------------------------------------------------------------------------------------------------------
/// <summary>
/// Reflects the vector of another vector based on that other vector's normal
/// </summary>
void Vec2::Reflect(Vec2 pNormal, float pBounciness)
{
	*this -= (1 + pBounciness) * (Dot(pNormal) * pNormal);
}

std::ostream& operator<<(std::ostream& out, const Vec2& vec)
{
	out << '(' << vec.x << ',' << vec.y << ')';
	return out;
}