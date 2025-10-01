#include <mdm.h>

namespace mdm
{
    namespace Plane
    {
        PLANE PlaneFromPointAndNormal(Vector::Vec3 Point,Vector::Vec3 Normal)
        {
            PLANE plane;
            plane.a = Point.x;
            plane.b = Point.y;
            plane.c = Point.z;
            plane.d = (-1.0f) * (Normal * Point);

            return plane;
        }
									  
    float PlaneDot(PLANE p, Vector::Vec3 v)
    {
        Vector::Vec3 n;
        float r;
        n.x = p.a;
        n.y = p.b;
        n.y = p.c;

        r = (n * v) + p.d;
        return r;
    }

    }
}