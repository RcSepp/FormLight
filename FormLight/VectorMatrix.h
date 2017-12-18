#pragma once
#ifndef __VECTORMATRIX_H
#define __VECTORMATRIX_H

//-----------------------------------------------------------------------------
// MACROS
//-----------------------------------------------------------------------------
#define FLOAT_INFINITY 1e20f
#define FLOAT_TOLERANCE 1e-6f
#ifndef PI
#define PI 3.141592654f
#endif


//-----------------------------------------------------------------------------
// FUNCTIONS
//-----------------------------------------------------------------------------

struct Vector2;
struct Vector3;
struct Vector4;
struct Quaternion;
struct Color4;
struct Color3;
struct Plane;
struct Matrix3;
struct Matrix4;

float saturate(float val);
Vector2* Vec2Set(Vector2* vout, float x, float y);
Vector2* Vec2Set(Vector2* vout, const float* xy);
Vector3* Vec3Set(Vector3* vout, float x, float y, float z);
Vector3* Vec3Set(Vector3* vout, const float* xyz);
Vector4* Vec4Set(Vector4* vout, float x, float y, float z, float w);
Vector4* Vec4Set(Vector4* vout, const float* xyzw);
Matrix3* Mat3Set(Matrix3* mout, float _11, float _12, float _13, float _21, float _22, float _23, float _31, float _32, float _33);
Matrix3* Mat3Set(Matrix3* mout, const float* elements);
Matrix4* Mat4Set(Matrix4* mout, float _11, float _12, float _13, float _14, float _21, float _22, float _23, float _24, float _31, float _32, float _33, float _34, float _41, float _42, float _43, float _44);
Matrix4* Mat4Set(Matrix4* mout, const float* elements);
Color4* ClrSet(Color4* cout, float r, float g, float b, float a = 1.0f);
Color4* ClrSet(Color4* cout, const float* rgba);
Color3* ClrSet(Color3* cout, float r, float g, float b);
Color3* ClrSet(Color3* cout, const float* rgb);
Quaternion* QuaternionSet(Quaternion* qout, float x, float y, float z, float w);
Quaternion* QuaternionSet(Quaternion* qout, const float* xyzw);
Color4* ClrClone(Color4* cout, const Color4* c0);
Color3* ClrClone(Color3* cout, const Color3* c0);
float Vec2Dot(const Vector2 *v0, const Vector2 *v1);
float Vec3Dot(const Vector3 *v0, const Vector3 *v1);
float Vec4Dot(const Vector4 *v0, const Vector4 *v1);
Vector3* Vec3Cross(Vector3 *vResult, const Vector3 *v0, const Vector3 *v1);
Vector3* Vec3Reflect(Vector3 *vResult, const Vector3 *n, const Vector3 *v);
Vector3* Vec3Refract(Vector3 *vResult, const Vector3 *n, const Vector3 *v, float ratio);
Vector2* GetUV(Vector2 t0, Vector2 t1, Vector2 t2, Vector2 tP, Vector2 *uv);
float Vec2Length(const Vector2 *v0);
float Vec2Length(const float x, const float y);
float Vec3Length(const Vector3 *v0);
float Vec3Length(const float x, const float y, const float z);
float Vec4Length(const Vector4 *v0);
float Vec4Length(const float x, const float y, const float z, const float w);
float Vec2LengthSq(const Vector2 *v0);
float Vec2LengthSq(const float x, const float y);
float Vec3LengthSq(const Vector3 *v0);
float Vec3LengthSq(const float x, const float y, const float z);
float Vec4LengthSq(const Vector4 *v0);
float Vec4LengthSq(const float x, const float y, const float z, const float w);
Vector2* Vec2Inverse(Vector2* vResult, const Vector2* v0);
Vector3* Vec3Inverse(Vector3* vResult, const Vector3* v0);
Vector4* Vec4Inverse(Vector4* vResult, const Vector4* v0);
Vector2* Vec2Invert(Vector2* v0);
Vector3* Vec3Invert(Vector3* v0);
Vector4* Vec4Invert(Vector4* v0);
Vector2* Vec2Normalize(Vector2 *vResult, const Vector2 *v0);
Vector2* Vec2Normalize(Vector2 *v0);
Vector3* Vec3Normalize(Vector3 *vResult, const Vector3 *v0);
Vector3* Vec3Normalize(Vector3 *v0);
Vector4* Vec4Normalize(Vector4 *vResult, const Vector4 *v0);
Vector4* Vec4Normalize(Vector4 *v0);
Vector4* Vec3Transform(Vector4 *vResult, const Vector3 *v0, const Matrix4 *m0);
Vector3* Vec3TransformCoord(Vector3 *vResult, const Vector3 *v0, const Matrix4 *m0);
Vector3* Vec3TransformNormal(Vector3 *vResult, const Vector3 *v0, const Matrix4 *m0);
Vector4* Vec4Transform(Vector4 *vResult, const Vector4 *v0, const Matrix4 *m0);
//Vector3* Vec3Unproject(Vector3 *vResult, const Vector3* v, const Matrix4* worldviewproj);
Vector2* Vec2Lerp(Vector2 *vResult, const Vector2 *v0, const Vector2 *v1, float f);
Vector3* Vec3Lerp(Vector3 *vResult, const Vector3 *v0, const Vector3 *v1, float f);
Color4* ClrLerp(Color4* cResult, const Color4* c0, const Color4* c1, float f);
Color3* ClrLerp(Color3* cResult, const Color3* c0, const Color3* c1, float f);
Vector2* Vec2BaryCentric(Vector2* vResult, const Vector2* v0, const Vector2* v1, const Vector2* v2, const Vector2* uv);
Vector3* Vec3BaryCentric(Vector3* vResult, const Vector3* v0, const Vector3* v1, const Vector3* v2, const Vector2* uv);
Vector2* Vec2InvBaryCentric(Vector2* vResult, const Vector2* v0, const Vector2* v1, const Vector2* v2, const Vector2* uv);
Vector3* Vec3Min(Vector3 *vResult, const Vector3 *v0, const Vector3 *v1);
Vector3* Vec3Max(Vector3 *vResult, const Vector3 *v0, const Vector3 *v1);
Quaternion* QuaternionIdentity(Quaternion *qResult);
Quaternion* QuaternionMultiply(Quaternion *qResult, const Quaternion *q0, const Quaternion *q1);
Quaternion* QuaternionMultiply(Quaternion *qResult, const Quaternion *q1);
Quaternion* QuaternionInverse(Quaternion *qResult, const Quaternion *q0);
Quaternion* QuaternionInvert(Quaternion *q0);
Quaternion* QuaternionNormalize(Quaternion *qResult, const Quaternion *q0);
Quaternion* QuaternionNormalize(Quaternion *q0);
Quaternion* QuaternionRotationX(Quaternion *qResult, float pitch);
Quaternion* QuaternionRotationY(Quaternion *qResult, float yaw);
Quaternion* QuaternionRotationZ(Quaternion *qResult, float roll);
Quaternion* QuaternionRotationAxis(Quaternion *qResult, const Vector3* axis, float angle);
Quaternion* QuaternionSlerp(Quaternion *qResult, const Quaternion *q0, const Quaternion *q1, float f);
void QuaternionToAxisAngle(const Quaternion *q0, Vector3* axis, float* angle);
Plane* PlaneFromPointNormal(Plane *pResult, const Vector3 *vPt, const Vector3 *vNml);
Plane* PlaneNormalize(Plane *pResult, const Plane *p0);
Plane* PlaneNormalize(Plane *pResult);
float PlaneDotCoord(const Plane *p0, const Vector3 *v0);
Vector3* PlaneIntersectLine(Vector3 *vResult, const Plane *p0, const Vector3 *v0, const Vector3 *v1);
Matrix3* Mat3Identity(Matrix3 *mResult);
Matrix3* Mat3Translation(Matrix3 *mResult, float x, float y);
Matrix3* Mat3Translation(Matrix3 *mResult, const Vector2 *v0);
Matrix3* Mat3Translate(Matrix3 *mResult, const Matrix3 *m0, float x, float y);
Matrix3* Mat3Translate(Matrix3 *mResult, const Matrix3 *m0, const Vector2 *v0);
Matrix3* Mat3Scaling(Matrix3 *mResult, float x, float y);
Matrix3* Mat3Scaling(Matrix3 *mResult, const Vector2 *v0);
Matrix3* Mat3Scale(Matrix3 *mResult, const Matrix3 *m0, float x, float y);
Matrix3* Mat3Scale(Matrix3 *mResult, const Matrix3 *m0, const Vector2 *v0);
Matrix4* Mat4Identity(Matrix4 *mResult);
Matrix4* Mat4Translation(Matrix4 *mResult, float x, float y, float z);
Matrix4* Mat4Translation(Matrix4 *mResult, const Vector3 *v0);
Matrix4* Mat4Translate(Matrix4 *mResult, const Matrix4 *m0, float x, float y, float z);
Matrix4* Mat4Translate(Matrix4 *mResult, const Matrix4 *m0, const Vector3 *v0);
Matrix4* Mat4Scaling(Matrix4 *mResult, float x, float y, float z);
Matrix4* Mat4Scaling(Matrix4 *mResult, const Vector3 *v0);
Matrix4* Mat4Scale(Matrix4 *mResult, const Matrix4 *m0, float x, float y, float z);
Matrix4* Mat4Scale(Matrix4 *mResult, const Matrix4 *m0, const Vector3 *v0);
Matrix4* Mat4Transpose(Matrix4 *mResult, const Matrix4 *m0);
Matrix4* Mat4InverseTranspose(Matrix4 *mResult, const Matrix4 *m0);
float Mat4Determinant(const Matrix4 *m0);
//Matrix4* Mat4Inverse(Matrix4 *mResult, float *det, const Matrix4 *m0);
Matrix4* Mat4Inverse(Matrix4 *mResult, const Matrix4 *m0);
Matrix4* Mat4PerspectiveLH(Matrix4 *mResult, float width, float height, float zn, float zf);
Matrix4* Mat4PerspectiveRH(Matrix4 *mResult, float width, float height, float zn, float zf);
Matrix4* Mat4PerspectiveFovLH(Matrix4 *mResult, float fovy, float aspect, float zn, float zf);
Matrix4* Mat4PerspectiveFovRH(Matrix4 *mResult, float fovy, float aspect, float zn, float zf);
Matrix4* Mat4OrthographicLH(Matrix4 *mResult, float width, float height, float zn, float zf);
Matrix4* Mat4OrthographicRH(Matrix4 *mResult, float width, float height, float zn, float zf);
Matrix4* Mat4RotationX(Matrix4 *mResult, float angle);
Matrix4* Mat4RotateX(Matrix4* mResult, const Matrix4* m0, float angle);
Matrix4* Mat4RotationY(Matrix4 *mResult, float angle);
Matrix4* Mat4RotateY(Matrix4* mResult, const Matrix4* m0, float angle);
Matrix4* Mat4RotationZ(Matrix4 *mResult, float angle);
Matrix4* Mat4RotateZ(Matrix4* mResult, const Matrix4* m0, float angle);
Matrix4* Mat4RotationYawPitchRoll(Matrix4 *mResult, float yaw, float pitch, float roll);
Matrix4* Mat4RotationQuaternion(Matrix4 *mResult, const Quaternion* qrot);
Matrix4* Mat4LookAtLH(Matrix4 *mResult, const Vector3* pos, const Vector3* target, const Vector3* up);
Matrix4* Mat4LookAtRH(Matrix4 *mResult, const Vector3* pos, const Vector3* target, const Vector3* up);
Matrix4* Mat4InvLookAtLH(Matrix4 *mResult, const Vector3* pos, const Vector3* target, const Vector3* up);
Matrix4* Mat4InvLookAtRH(Matrix4 *mResult, const Vector3* pos, const Vector3* target, const Vector3* up);
bool RayIntersectsBox(const Vector3* raypos, const Vector3* raydir, const Vector3* boxmin, const Vector3* boxmax);


//-----------------------------------------------------------------------------
// CLASSES
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Name: Vector2
// Desc: Two component vector class
//-----------------------------------------------------------------------------
struct Vector2
{
public:
	float x, y;
	Vector2() {};
	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	};
	Vector2(const float* xy)
	{
		this->x = xy[0];
		this->y = xy[1];
	};
	operator float*() { return &x; }
	operator const float* () const { return &x; }
	// Binary operators
	Vector2 operator+(const Vector2& summand) const
	{
		return Vector2(x + summand.x, y + summand.y);
	};
	Vector2 operator-(const Vector2& subtrahend) const
	{
		return Vector2(x - subtrahend.x, y - subtrahend.y);
	};
	Vector2 operator*(const Vector2& factor) const
	{
		return Vector2(x * factor.x, y * factor.y);
	};
	Vector2 operator*(float factor) const
	{
		return Vector2(x * factor, y * factor);
	};
	Vector2 operator/(const Vector2& divisor) const
	{
		return Vector2(x / divisor.x, y / divisor.y);
	};
	Vector2 operator/(float divisor) const
	{
		float invdiv = 1.0f / divisor;
		return Vector2(x * invdiv, y * invdiv);
	};
	// Assignment operators
	/*Vector2& operator=(const Vector2 &reference)
	{
	if(this == &reference)
	return *this;
	this->x = reference.x;
	this->y = reference.y;
	return *this;
	};*/
	Vector2& operator+=(const Vector2& summand)
	{
		x += summand.x; y += summand.y;
		return *this;
	};
	Vector2& operator+=(float summand)
	{
		x += summand; y += summand;
		return *this;
	};
	Vector2& operator-=(const Vector2& subtrahend)
	{
		x -= subtrahend.x; y -= subtrahend.y;
		return *this;
	};
	Vector2& operator-=(float subtrahend)
	{
		x -= subtrahend; y -= subtrahend;
		return *this;
	};
	Vector2& operator*=(const Vector2& factor)
	{
		x *= factor.x; y *= factor.y;
		return *this;
	};
	Vector2& operator*=(float factor)
	{
		x *= factor; y *= factor;
		return *this;
	};
	Vector2& operator/=(const Vector2& divisor)
	{
		x /= divisor.x; y /= divisor.y;
		return *this;
	};
	Vector2& operator/=(float divisor)
	{
		float invdiv = 1.0f / divisor;
		x *= invdiv; y *= invdiv;
		return *this;
	};
	// Comparison operators
	bool operator==(const Vector2& reference) const
	{
		return x == reference.x && y == reference.y;
	};
	bool operator!=(const Vector2& reference) const
	{
		return x != reference.x || y != reference.y;
	};
	bool operator<(const Vector2& reference) const
	{
		return x*x + y*y < reference.x*reference.x + reference.y*reference.y;
	};
	bool operator>(const Vector2& reference) const
	{
		return x*x + y*y > reference.x*reference.x + reference.y*reference.y;
	};
	bool operator<=(const Vector2& reference) const
	{
		return x*x + y*y <= reference.x*reference.x + reference.y*reference.y;
	};
	bool operator>=(const Vector2& reference) const
	{
		return x*x + y*y >= reference.x*reference.x + reference.y*reference.y;
	};
};
Vector2* Vec2Add(Vector2* vout, const Vector2* v0, const Vector2* v1);
Vector2* Vec2Sub(Vector2* vout, const Vector2* v0, const Vector2* v1);
Vector2* Vec2Scale(Vector2* vout, const Vector2* vin, float scale);
Vector2* Vec2AddScaled(Vector2* vout, const Vector2* v0, const Vector2* v1, float v1scale);

//-----------------------------------------------------------------------------
// Name: Vector3
// Desc: Three component vector class
//-----------------------------------------------------------------------------
class hkVector4;
struct Vector3
{
public:
	float x, y, z;
	Vector3() {};
	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	};
	Vector3(const float* xyz)
	{
		this->x = xyz[0];
		this->y = xyz[1];
		this->z = xyz[2];
	};
	operator float*() { return &x; }
	operator const float* () const { return &x; }
	Vector3(const hkVector4& hkvec);
	operator hkVector4() const;
	// Binary operators
	Vector3 operator+(const Vector3& summand) const
	{
		return Vector3(x + summand.x, y + summand.y, z + summand.z);
	};
	Vector3 operator-(const Vector3& subtrahend) const
	{
		return Vector3(x - subtrahend.x, y - subtrahend.y, z - subtrahend.z);
	};
	Vector3 operator*(const Vector3& factor) const
	{
		return Vector3(x * factor.x, y * factor.y, z * factor.z);
	};
	Vector3 operator*(float factor) const
	{
		return Vector3(x * factor, y * factor, z * factor);
	};
	Vector3 operator/(const Vector3& divisor) const
	{
		return Vector3(x / divisor.x, y / divisor.y, z / divisor.z);
	};
	Vector3 operator/(float divisor) const
	{
		float invdiv = 1.0f / divisor;
		return Vector3(x * invdiv, y * invdiv, z * invdiv);
	};
	// Assignment operators
	/*Vector3& operator=(const Vector3& reference)
	{
	if(this == &reference)
	return *this;
	this->x = reference.x;
	this->y = reference.y;
	this->z = reference.z;
	return *this;
	};*/
	Vector3& operator+=(const Vector3& summand)
	{
		x += summand.x; y += summand.y; z += summand.z;
		return *this;
	};
	Vector3& operator+=(float summand)
	{
		x += summand; y += summand; z += summand;
		return *this;
	};
	Vector3& operator-=(const Vector3& subtrahend)
	{
		x -= subtrahend.x; y -= subtrahend.y; z -= subtrahend.z;
		return *this;
	};
	Vector3& operator-=(float subtrahend)
	{
		x -= subtrahend; y -= subtrahend; z -= subtrahend;
		return *this;
	};
	Vector3& operator*=(const Vector3& factor)
	{
		x *= factor.x; y *= factor.y; z *= factor.z;
		return *this;
	};
	Vector3& operator*=(float factor)
	{
		x *= factor; y *= factor; z *= factor;
		return *this;
	};
	Vector3& operator/=(const Vector3& divisor)
	{
		x /= divisor.x; y /= divisor.y; z /= divisor.z;
		return *this;
	};
	Vector3& operator/=(float divisor)
	{
		float invdiv = 1.0f / divisor;
		x *= invdiv; y *= invdiv; z *= invdiv;
		return *this;
	};
	// Comparison operators
	bool operator==(const Vector3& reference) const
	{
		return x == reference.x && y == reference.y && z == reference.z;
	};
	bool operator!=(const Vector3& reference) const
	{
		return x != reference.x || y != reference.y || z != reference.z;
	};
	bool operator<(const Vector3& reference) const
	{
		return x*x + y*y + z*z < reference.x*reference.x + reference.y*reference.y +
			reference.z*reference.z;
	};
	bool operator>(const Vector3& reference) const
	{
		return x*x + y*y + z*z > reference.x*reference.x + reference.y*reference.y +
			reference.z*reference.z;
	};
	bool operator<=(const Vector3& reference) const
	{
		return x*x + y*y + z*z <= reference.x*reference.x + reference.y*reference.y +
			reference.z*reference.z;
	};
	bool operator>=(const Vector3& reference) const
	{
		return x*x + y*y + z*z >= reference.x*reference.x + reference.y*reference.y +
			reference.z*reference.z;
	};

	static Vector3 TransformPerspective(const Vector3& vec, const Matrix4& mat) { Vector3 result; return *Vec3TransformCoord(&result, &vec, &mat); }
};
Vector3* Vec3Add(Vector3* vout, const Vector3* v0, const Vector3* v1);
Vector3* Vec3Sub(Vector3* vout, const Vector3* v0, const Vector3* v1);
Vector3* Vec3Scale(Vector3* vout, const Vector3* vin, float scale);
Vector3* Vec3AddScaled(Vector3* vout, const Vector3* v0, const Vector3* v1, float v1scale);

//-----------------------------------------------------------------------------
// Name: Vector4
// Desc: Four component vector class
//-----------------------------------------------------------------------------
struct Vector4
{
public:
	float x, y, z, w;
	Vector4() {};
	Vector4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	};
	Vector4(const float* xyzw)
	{
		this->x = xyzw[0];
		this->y = xyzw[1];
		this->z = xyzw[2];
		this->w = xyzw[3];
	};
	Vector4(const Vector3* v0, float w)
	{
		this->x = v0->x;
		this->y = v0->y;
		this->z = v0->z;
		this->w = w;
	};
	operator float*() { return &x; }
	operator const float* () const { return &x; }
	// Binary operators
	Vector4 operator+(const Vector4& summand) const
	{
		return Vector4(x + summand.x, y + summand.y, z + summand.z, w + summand.w);
	};
	Vector4 operator-(const Vector4& subtrahend) const
	{
		return Vector4(x - subtrahend.x, y - subtrahend.y, z - subtrahend.z, w - subtrahend.w);
	};
	Vector4 operator*(const Vector4& factor) const
	{
		return Vector4(x * factor.x, y * factor.y, z * factor.z, w * factor.w);
	};
	Vector4 operator*(float factor) const
	{
		return Vector4(x * factor, y * factor, z * factor, w * factor);
	};
	Vector4 operator/(const Vector4& divisor) const
	{
		return Vector4(x / divisor.x, y / divisor.y, z / divisor.z, w / divisor.w);
	};
	Vector4 operator/(float divisor) const
	{
		float invdiv = 1.0f / divisor;
		return Vector4(x * invdiv, y * invdiv, z * invdiv, w * invdiv);
	};
	// Assignment operators
	/*Vector4& operator=(const Vector4& reference)
	{
	if(this == &reference)
	return *this;
	this->x = reference.x;
	this->y = reference.y;
	this->z = reference.z;
	this->w = reference.w;
	return *this;
	};*/
	Vector4& operator+=(const Vector4& summand)
	{
		x += summand.x; y += summand.y; z += summand.z; w += summand.w;
		return *this;
	};
	Vector4& operator+=(float summand)
	{
		x += summand; y += summand; z += summand; w += summand;
		return *this;
	};
	Vector4& operator-=(const Vector4& subtrahend)
	{
		x -= subtrahend.x; y -= subtrahend.y; z -= subtrahend.z; w -= subtrahend.w;
		return *this;
	};
	Vector4& operator-=(float subtrahend)
	{
		x -= subtrahend; y -= subtrahend; z -= subtrahend; w -= subtrahend;
		return *this;
	};
	Vector4& operator*=(const Vector4& factor)
	{
		x *= factor.x; y *= factor.y; z *= factor.z; w *= factor.w;
		return *this;
	};
	Vector4& operator*=(float factor)
	{
		x *= factor; y *= factor; z *= factor; w *= factor;
		return *this;
	};
	Vector4& operator/=(const Vector4& divisor)
	{
		x /= divisor.x; y /= divisor.y; z /= divisor.z; w /= divisor.w;
		return *this;
	};
	Vector4& operator/=(float divisor)
	{
		float invdiv = 1.0f / divisor;
		x *= invdiv; y *= invdiv; z *= invdiv; w *= invdiv;
		return *this;
	};
	// Comparison operators
	bool operator==(const Vector4& reference) const
	{
		return x == reference.x && y == reference.y && z == reference.z && w == reference.w;
	};
	bool operator!=(const Vector4& reference) const
	{
		return x != reference.x || y != reference.y || z != reference.z || w != reference.w;
	};
	bool operator<(const Vector4& reference) const
	{
		return x*x + y*y + z*z + w*w < reference.x*reference.x + reference.y*reference.y +
			reference.z*reference.z + reference.w*reference.w;
	};
	bool operator>(const Vector4& reference) const
	{
		return x*x + y*y + z*z + w*w > reference.x*reference.x + reference.y*reference.y +
			reference.z*reference.z + reference.w*reference.w;
	};
	bool operator<=(const Vector4& reference) const
	{
		return x*x + y*y + z*z + w*w <= reference.x*reference.x + reference.y*reference.y +
			reference.z*reference.z + reference.w*reference.w;
	};
	bool operator>=(const Vector4& reference) const
	{
		return x*x + y*y + z*z + w*w >= reference.x*reference.x + reference.y*reference.y +
			reference.z*reference.z + reference.w*reference.w;
	};
};

//-----------------------------------------------------------------------------
// Name: Quaternion
// Desc: Four component quaternion class
//-----------------------------------------------------------------------------
class hkQuaternion;
struct Quaternion
{
public:
	float x, y, z, w;
	Quaternion() {};
	Quaternion(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	};
	Quaternion(const float* xyzw)
	{
		this->x = xyzw[0];
		this->y = xyzw[1];
		this->z = xyzw[2];
		this->w = xyzw[3];
	};
	operator float*() { return &x; }
	operator const float* () const { return &x; }
	Quaternion(const hkQuaternion& hkquat);
	operator hkQuaternion() const;
	// Binary operators
	Quaternion operator+(const Quaternion& summand) const
	{
		return Quaternion(x + summand.x, y + summand.y, z + summand.z, w + summand.w);
	};
	Quaternion operator-(const Quaternion& subtrahend) const
	{
		return Quaternion(x - subtrahend.x, y - subtrahend.y, z - subtrahend.z, w - subtrahend.w);
	};
	Quaternion operator*(const Quaternion& factor) const
	{
		Quaternion qResult;
		QuaternionMultiply(&qResult, this, &factor);
		return qResult;
	};
	Quaternion operator*(float factor) const
	{
		return Quaternion(x * factor, y * factor, z * factor, w * factor);
	};
	Quaternion operator/(float divisor) const
	{
		float invdiv = 1.0f / divisor;
		return Quaternion(x * invdiv, y * invdiv, z * invdiv, w * invdiv);
	};
	// Assignment operators
	/*Quaternion& operator=(const Quaternion& reference)
	{
	if(this == &reference)
	return *this;
	this->x = reference.x;
	this->y = reference.y;
	this->z = reference.z;
	this->w = reference.w;
	return *this;
	};*/
	Quaternion& operator+=(const Quaternion& summand)
	{
		x += summand.x; y += summand.y; z += summand.z; w += summand.w;
		return *this;
	};
	Quaternion& operator-=(const Quaternion& subtrahend)
	{
		x -= subtrahend.x; y -= subtrahend.y; z -= subtrahend.z; w -= subtrahend.w;
		return *this;
	};
	Quaternion& operator*=(const Quaternion& factor)
	{
		QuaternionMultiply(this, &factor);
		return *this;
	};
	Quaternion& operator*=(float factor)
	{
		x *= factor; y *= factor; z *= factor; w *= factor;
		return *this;
	};
	Quaternion& operator/=(float divisor)
	{
		float invdiv = 1.0f / divisor;
		x *= invdiv; y *= invdiv; z *= invdiv; w *= invdiv;
		return *this;
	};
	// Comparison operators
	bool operator==(const Quaternion& reference) const
	{
		return x == reference.x && y == reference.y && z == reference.z && w == reference.w;
	};
	bool operator!=(const Quaternion& reference) const
	{
		return x != reference.x || y != reference.y || z != reference.z || w != reference.w;
	};

	Vector3* ComputeAxisWrapper() const;
	float ComputeAngleWrapper() const;
};

//-----------------------------------------------------------------------------
// Name: Color4
// Desc: Four component color class
//-----------------------------------------------------------------------------
struct Color4
{
public:
	float r, g, b, a;
	Color4() {};
	Color4(float r, float g, float b, float a = 1.0f)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	};
	Color4(const float* rgba)
	{
		this->r = rgba[0];
		this->g = rgba[1];
		this->b = rgba[2];
		this->a = rgba[3];
	};
	Color4(unsigned int argb)
	{
		this->r = ((argb >> 16) & 0xFF) / 255.0f;
		this->g = ((argb >> 8) & 0xFF) / 255.0f;
		this->b = ((argb >> 0) & 0xFF) / 255.0f;
		this->a = ((argb >> 24) & 0xFF) / 255.0f;
	};
	operator unsigned int() const
	{
		return ((unsigned int)(saturate(r) * 255.0f)) | ((unsigned int)(saturate(g) * 255.0f) << 8) | ((unsigned int)(saturate(b) * 255.0f) << 16) | ((unsigned int)(saturate(a) * 255.0f) << 24);
	}
	operator float*() { return &r; }
	operator const float* () const { return &r; }

	unsigned int ToDWORD() const
	{
		return (unsigned int)(saturate(r) * 255.0f) | ((unsigned int)(saturate(g) * 255.0f) << 8) | ((unsigned int)(saturate(b) * 255.0f) << 16);
	}
	unsigned int ToDWORD(float blendfactor) const
	{
		blendfactor = saturate(blendfactor);
		return (unsigned int)(saturate(r) * 255.0f * blendfactor) | ((unsigned int)(saturate(g) * 255.0f * blendfactor) << 8) | ((unsigned int)(saturate(b) * 255.0f * blendfactor) << 16);
	}

	bool operator==(const Color4& other) const
	{
		return this->r == other.r && this->g == other.g && this->b == other.b && this->a == other.a;
	}
	bool operator!=(const Color4& other) const
	{
		return this->r != other.r || this->g != other.g || this->b != other.b || this->a != other.a;
	}

	const static Color4 White, Black;
};
Color4* ClrAdd(Color4* cout, const Color4* c0, const Color4* c1);
Color4* ClrSub(Color4* cout, const Color4* c0, const Color4* c1);
Color4* ClrMul(Color4* cout, const Color4* c0, const Color4* c1);
Color4* ClrScale(Color4* cout, const Color4* cin, float scale);
Color4* ClrAddScaled(Color4* cout, const Color4* c0, const Color4* c1, float c1scale);
Color4* ClrAddScaled(Color4* cout, const Color4* c0, const Color4* c1, const Color4* c1scale0, float c1scale1);
Color4* ClrAddScaled(Color4* cout, const Color4* c0, const Color4* c1, const Color4* c1scale0, const Color4* c1scale1, float c1scale2);

//-----------------------------------------------------------------------------
// Name: Color3
// Desc: Three component color class
//-----------------------------------------------------------------------------
struct Color3
{
public:
	float r, g, b;
	Color3() {};
	Color3(float r, float g, float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	};
	Color3(const float* rgb)
	{
		this->r = rgb[0];
		this->g = rgb[1];
		this->b = rgb[2];
	};
	Color3(unsigned int rgb)
	{
		this->r = ((rgb >> 16) & 0xFF) / 255.0f;
		this->g = ((rgb >> 8) & 0xFF) / 255.0f;
		this->b = ((rgb >> 0) & 0xFF) / 255.0f;
	};
	operator unsigned int() const
	{
		return ((unsigned int)(saturate(r) * 255.0f)) | ((unsigned int)(saturate(g) * 255.0f) << 8) | ((unsigned int)(saturate(b) * 255.0f) << 16);
	}
	operator float*() { return &r; }
	operator const float* () const { return &r; }

	unsigned int ToDWORD() const
	{
		return (unsigned int)(saturate(r) * 255.0f) | ((unsigned int)(saturate(g) * 255.0f) << 8) | ((unsigned int)(saturate(b) * 255.0f) << 16);
	}
	unsigned int ToDWORD(float blendfactor) const
	{
		blendfactor = saturate(blendfactor);
		return (unsigned int)(saturate(r) * 255.0f * blendfactor) | ((unsigned int)(saturate(g) * 255.0f * blendfactor) << 8) | ((unsigned int)(saturate(b) * 255.0f * blendfactor) << 16);
	}
};
Color3* ClrAdd(Color3* cout, const Color3* c0, const Color3* c1);
Color3* ClrSub(Color3* cout, const Color3* c0, const Color3* c1);
Color3* ClrMul(Color3* cout, const Color3* c0, const Color3* c1);
Color3* ClrScale(Color3* cout, const Color3* cin, float scale);
Color3* ClrAddScaled(Color3* cout, const Color3* c0, const Color3* c1, float c1scale);
Color3* ClrAddScaled(Color3* cout, const Color3* c0, const Color3* c1, const Color3* c1scale0, float c1scale1);
Color3* ClrAddScaled(Color3* cout, const Color3* c0, const Color3* c1, const Color3* c1scale0, const Color3* c1scale1, float c1scale2);

//-----------------------------------------------------------------------------
// Name: Plane
// Desc: Four component plane class
//-----------------------------------------------------------------------------
struct Plane
{
public:
	float a, b, c, d;
	Plane() {}
	Plane(float a, float b, float c, float d)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	};

	/*Plane( CONST FLOAT* );
	Plane( CONST D3DXFLOAT16* );

	// casting
	operator FLOAT* ();
	operator CONST FLOAT* () const;

	// assignment operators
	D3DXPLANE& operator *= ( FLOAT );
	D3DXPLANE& operator /= ( FLOAT );

	// unary operators
	D3DXPLANE operator + () const;
	D3DXPLANE operator - () const;

	// binary operators
	D3DXPLANE operator * ( FLOAT ) const;
	D3DXPLANE operator / ( FLOAT ) const;

	friend D3DXPLANE operator * ( FLOAT, CONST D3DXPLANE& );

	BOOL operator == ( CONST D3DXPLANE& ) const;
	BOOL operator != ( CONST D3DXPLANE& ) const;*/
};


//-----------------------------------------------------------------------------
// Name: Matrix4
// Desc: Four component square matrix
//-----------------------------------------------------------------------------
struct Matrix4
{
public:
	float _11, _12, _13, _14, _21, _22, _23, _24, _31, _32, _33, _34, _41, _42, _43, _44;
	Matrix4(float _11, float _12, float _13, float _14, float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34, float _41, float _42, float _43, float _44)
	{
		this->_11 = _11; this->_12 = _12; this->_13 = _13; this->_14 = _14;
		this->_21 = _21; this->_22 = _22; this->_23 = _23; this->_24 = _24;
		this->_31 = _31; this->_32 = _32; this->_33 = _33; this->_34 = _34;
		this->_41 = _41; this->_42 = _42; this->_43 = _43; this->_44 = _44;
	};
	Matrix4() {};
	operator float*() { return &_11; }
	operator const float* () const { return &_11; }
	Matrix4 operator+(const Matrix4 &summand) const
	{
		return Matrix4(_11 + summand._11, _12 + summand._12, _13 + summand._13, _14 + summand._14,
			_21 + summand._21, _22 + summand._22, _23 + summand._23, _24 + summand._24,
			_31 + summand._31, _32 + summand._32, _33 + summand._33, _34 + summand._34,
			_41 + summand._41, _42 + summand._42, _43 + summand._43, _44 + summand._44);
	};
	Matrix4 operator-(const Matrix4 &subtrahend) const
	{
		return Matrix4(_11 - subtrahend._11, _12 - subtrahend._12, _13 - subtrahend._13, _14 - subtrahend._14,
			_21 - subtrahend._21, _22 - subtrahend._22, _23 - subtrahend._23, _24 - subtrahend._24,
			_31 - subtrahend._31, _32 - subtrahend._32, _33 - subtrahend._33, _34 - subtrahend._34,
			_41 - subtrahend._41, _42 - subtrahend._42, _43 - subtrahend._43, _44 - subtrahend._44);
	};
	Matrix4 operator*(const Matrix4 &factor) const
	{
		return Matrix4(_11 * factor._11 + _12 * factor._21 + _13 * factor._31 + _14 * factor._41,
			_11 * factor._12 + _12 * factor._22 + _13 * factor._32 + _14 * factor._42,
			_11 * factor._13 + _12 * factor._23 + _13 * factor._33 + _14 * factor._43,
			_11 * factor._14 + _12 * factor._24 + _13 * factor._34 + _14 * factor._44,
			_21 * factor._11 + _22 * factor._21 + _23 * factor._31 + _24 * factor._41,
			_21 * factor._12 + _22 * factor._22 + _23 * factor._32 + _24 * factor._42,
			_21 * factor._13 + _22 * factor._23 + _23 * factor._33 + _24 * factor._43,
			_21 * factor._14 + _22 * factor._24 + _23 * factor._34 + _24 * factor._44,
			_31 * factor._11 + _32 * factor._21 + _33 * factor._31 + _34 * factor._41,
			_31 * factor._12 + _32 * factor._22 + _33 * factor._32 + _34 * factor._42,
			_31 * factor._13 + _32 * factor._23 + _33 * factor._33 + _34 * factor._43,
			_31 * factor._14 + _32 * factor._24 + _33 * factor._34 + _34 * factor._44,
			_41 * factor._11 + _42 * factor._21 + _43 * factor._31 + _44 * factor._41,
			_41 * factor._12 + _42 * factor._22 + _43 * factor._32 + _44 * factor._42,
			_41 * factor._13 + _42 * factor._23 + _43 * factor._33 + _44 * factor._43,
			_41 * factor._14 + _42 * factor._24 + _43 * factor._34 + _44 * factor._44);
	};
	Matrix4 operator*=(const Matrix4 &factor)
	{
		const float m[] = {
			_11 * factor._11 + _12 * factor._21 + _13 * factor._31 + _14 * factor._41,
			_11 * factor._12 + _12 * factor._22 + _13 * factor._32 + _14 * factor._42,
			_11 * factor._13 + _12 * factor._23 + _13 * factor._33 + _14 * factor._43,
			_11 * factor._14 + _12 * factor._24 + _13 * factor._34 + _14 * factor._44,
			_21 * factor._11 + _22 * factor._21 + _23 * factor._31 + _24 * factor._41,
			_21 * factor._12 + _22 * factor._22 + _23 * factor._32 + _24 * factor._42,
			_21 * factor._13 + _22 * factor._23 + _23 * factor._33 + _24 * factor._43,
			_21 * factor._14 + _22 * factor._24 + _23 * factor._34 + _24 * factor._44,
			_31 * factor._11 + _32 * factor._21 + _33 * factor._31 + _34 * factor._41,
			_31 * factor._12 + _32 * factor._22 + _33 * factor._32 + _34 * factor._42,
			_31 * factor._13 + _32 * factor._23 + _33 * factor._33 + _34 * factor._43,
			_31 * factor._14 + _32 * factor._24 + _33 * factor._34 + _34 * factor._44,
			_41 * factor._11 + _42 * factor._21 + _43 * factor._31 + _44 * factor._41,
			_41 * factor._12 + _42 * factor._22 + _43 * factor._32 + _44 * factor._42,
			_41 * factor._13 + _42 * factor._23 + _43 * factor._33 + _44 * factor._43,
			_41 * factor._14 + _42 * factor._24 + _43 * factor._34 + _44 * factor._44
		};
		return *Mat4Set(this, m);
	};
	Vector4 operator*(const Vector4 &factor) const
	{
		return Vector4(_11 * factor.x + _12 * factor.y + _13 * factor.z + _14 * factor.w,
			_21 * factor.x + _22 * factor.y + _23 * factor.z + _24 * factor.w,
			_31 * factor.x + _32 * factor.y + _33 * factor.z + _34 * factor.w,
			_41 * factor.x + _42 * factor.y + _43 * factor.z + _44 * factor.w);
	};

	Matrix4 Inverted() const { Matrix4 minv; return *Mat4Inverse(&minv, this); }
	void Invert() { Mat4Inverse(this, this); }
	static Matrix4 Invert(Matrix4 m) { Matrix4 minv; return *Mat4Inverse(&minv, &m); }

	static const Matrix4 Identity;

	static Matrix4 CreateTranslation(float px, float py, float pz) { Matrix4 m; return *Mat4Translation(&m, px, py, pz); }
	static Matrix4 CreateTranslation(const Vector3& pos) { Matrix4 m; return *Mat4Translation(&m, &pos); }
	static Matrix4 CreateScale(float sx, float sy, float sz) { Matrix4 m; return *Mat4Scaling(&m, sx, sy, sz); }
	static Matrix4 CreateScale(const Vector3& scl) { Matrix4 m; return *Mat4Scaling(&m, &scl); }
};


//-----------------------------------------------------------------------------
// Name: Matrix3
// Desc: Three component square matrix
//-----------------------------------------------------------------------------
struct Matrix3
{
public:
	float _11, _12, _13, _21, _22, _23, _31, _32, _33;
	Matrix3(float _11, float _12, float _13, float _21, float _22, float _23, float _31, float _32, float _33)
	{
		this->_11 = _11; this->_12 = _12; this->_13 = _13;
		this->_21 = _21; this->_22 = _22; this->_23 = _23;
		this->_31 = _31; this->_32 = _32; this->_33 = _33;
	};
	Matrix3() {};
	operator float*() { return &_11; }
	operator const float* () const { return &_11; }
	Matrix3 operator+(const Matrix3 &summand) const
	{
		return Matrix3(_11 + summand._11, _12 + summand._12, _13 + summand._13,
			_21 + summand._21, _22 + summand._22, _23 + summand._23,
			_31 + summand._31, _32 + summand._32, _33 + summand._33);
	};
	Matrix3 operator-(const Matrix3 &subtrahend) const
	{
		return Matrix3(_11 - subtrahend._11, _12 - subtrahend._12, _13 - subtrahend._13,
			_21 - subtrahend._21, _22 - subtrahend._22, _23 - subtrahend._23,
			_31 - subtrahend._31, _32 - subtrahend._32, _33 - subtrahend._33);
	};
	Matrix3 operator*(const Matrix3 &factor) const
	{
		return Matrix3(_11 * factor._11 + _12 * factor._21 + _13 * factor._31,
			_11 * factor._12 + _12 * factor._22 + _13 * factor._32,
			_11 * factor._13 + _12 * factor._23 + _13 * factor._33,
			_21 * factor._11 + _22 * factor._21 + _23 * factor._31,
			_21 * factor._12 + _22 * factor._22 + _23 * factor._32,
			_21 * factor._13 + _22 * factor._23 + _23 * factor._33,
			_31 * factor._11 + _32 * factor._21 + _33 * factor._31,
			_31 * factor._12 + _32 * factor._22 + _33 * factor._32,
			_31 * factor._13 + _32 * factor._23 + _33 * factor._33);
	};
	Matrix3 operator*=(const Matrix3 &factor)
	{
		const float m[] = {
			_11 * factor._11 + _12 * factor._21 + _13 * factor._31,
			_11 * factor._12 + _12 * factor._22 + _13 * factor._32,
			_11 * factor._13 + _12 * factor._23 + _13 * factor._33,
			_21 * factor._11 + _22 * factor._21 + _23 * factor._31,
			_21 * factor._12 + _22 * factor._22 + _23 * factor._32,
			_21 * factor._13 + _22 * factor._23 + _23 * factor._33,
			_31 * factor._11 + _32 * factor._21 + _33 * factor._31,
			_31 * factor._12 + _32 * factor._22 + _33 * factor._32,
			_31 * factor._13 + _32 * factor._23 + _33 * factor._33
		};
		return *Mat3Set(this, m);
	};
	Vector3 operator*(const Vector4 &factor) const
	{
		return Vector3(_11 * factor.x + _12 * factor.y + _13 * factor.z,
			_21 * factor.x + _22 * factor.y + _23 * factor.z,
			_31 * factor.x + _32 * factor.y + _33 * factor.z);
	};

	/*Matrix3 Inverted() const { Matrix3 minv; return *Mat3Inverse(&minv, this); }
	void Invert() { Mat3Inverse(this, this); }
	static Matrix3 Invert(Matrix3 m) { Matrix3 minv; return *Mat3Inverse(&minv, &m); }*/

	static const Matrix3 Identity;

	static Matrix3 CreateTranslation(float px, float py) { Matrix3 m; return *Mat3Translation(&m, px, py); }
	static Matrix3 CreateTranslation(const Vector2& pos) { Matrix3 m; return *Mat3Translation(&m, &pos); }
	static Matrix3 CreateScale(float sx, float sy) { Matrix3 m; return *Mat3Scaling(&m, sx, sy); }
	static Matrix3 CreateScale(const Vector2& scl) { Matrix3 m; return *Mat3Scaling(&m, &scl); }
};


namespace Intersection
{
	typedef float(*RAY_TRIANGLE_INTERSECTION_FUNCTION)(const Vector3* raypos, const Vector3* raydir, const Vector3* v0, const Vector3* v1, const Vector3* v2, Vector2* uv);
	extern RAY_TRIANGLE_INTERSECTION_FUNCTION RayTriangle;
	float RayTriangleNC(const Vector3* raypos, const Vector3* raydir, const Vector3* v0, const Vector3* v1, const Vector3* v2, Vector2* uv);
	float RayTriangleBFC(const Vector3* raypos, const Vector3* raydir, const Vector3* v0, const Vector3* v1, const Vector3* v2, Vector2* uv);
	float RayTriangleFFC(const Vector3* raypos, const Vector3* raydir, const Vector3* v0, const Vector3* v1, const Vector3* v2, Vector2* uv);
	typedef float(*RAY_SPHERE_INTERSECTION_FUNCTION)(const Vector3* raypos, const Vector3* raydir, const Vector3* spherecenter, float sphereradius);
	extern RAY_SPHERE_INTERSECTION_FUNCTION RaySphere;
	float RaySphereBFC(const Vector3* raypos, const Vector3* raydir, const Vector3* spherecenter, float sphereradius);
	float RaySphereFFC(const Vector3* raypos, const Vector3* raydir, const Vector3* spherecenter, float sphereradius);
	float RayMovingSphereBFC(const Vector3* raypos, const Vector3* raydir, const Vector3* spherecenter, float sphereradius, const Vector3* spherevelocity);

	enum CullMode
	{
		_CM_NONE, CM_FRONT, CM_BACK
	};
	void SetCullMode(CullMode cm);
	CullMode GetCullMode();
	bool IsCullingDisabled();
	bool IsFrontFaceCullingEnabled();
	bool IsBackFaceCullingEnabled();
	void FlipCullMode();
}

#endif