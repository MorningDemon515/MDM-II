#include <mdm.h>

namespace mdm{
    namespace Quaternion
    {
        QUATERNION::QUATERNION(float _x, float _y, float _z, float _w) 
        : x(_x), y(_y), z(_z), w(_w) 
    {}

    QUATERNION QUATERNION::operator + (const QUATERNION& q) const {
        return QUATERNION(x + q.x, y + q.y, z + q.z, w + q.w);
    }

    void QUATERNION::operator += (const QUATERNION& q) {
        x += q.x;
        y += q.y;
        z += q.z;
        w += q.w;
    }

    QUATERNION QUATERNION::operator - (const QUATERNION& q) const {
        return QUATERNION(x - q.x, y - q.y, z - q.z, w - q.w);
    }

    void QUATERNION::operator -= (const QUATERNION& q) {
        x -= q.x;
        y -= q.y;
        z -= q.z;
        w -= q.w;
    }

    //Hamilton Dot
    QUATERNION QUATERNION::operator * (const QUATERNION& q) const {
        return QUATERNION(
            w * q.x + x * q.w + y * q.z - z * q.y,
            w * q.y - x * q.z + y * q.w + z * q.x,
            w * q.z + x * q.y - y * q.x + z * q.w,
            w * q.w - x * q.x - y * q.y - z * q.z
        );
    }

    void QUATERNION::operator *= (const QUATERNION& q) {
        *this = *this * q;
    }

    QUATERNION QUATERNION::operator * (float scalar) const {
        return QUATERNION(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    void QUATERNION::operator *= (float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
    }

    QUATERNION QUATERNION::operator / (float scalar) const {
        float invScalar = 1.0f / scalar;
        return QUATERNION(x * invScalar, y * invScalar, z * invScalar, w * invScalar);
    }

    void QUATERNION::operator /= (float scalar) {
        float invScalar = 1.0f / scalar;
        x *= invScalar;
        y *= invScalar;
        z *= invScalar;
        w *= invScalar;
    }

    bool QUATERNION::operator == (const QUATERNION& q) const {
        return Common::Equal(x, q.x) &&
               Common::Equal(y, q.y) &&
               Common::Equal(z, q.z) &&
               Common::Equal(w, q.w);
    }

    bool QUATERNION::operator != (const QUATERNION& q) const {
        return !(*this == q);
    }

    QUATERNION QUATERNION::operator - () const {
        return QUATERNION(-x, -y, -z, -w);
    }
    }
}