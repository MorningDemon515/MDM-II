#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <mdm.h>
#include <constants.h>

using namespace mdm;
using namespace Common;
using namespace Vector;
using namespace Matrix;

void PrintVector3(Vec3 vec)
{
    printf("x: %f\n", vec.x);
    printf("y: %f\n", vec.y);
    printf("z: %f\n", vec.z);
}

void PrintMatrix(std::string text ,MATRIX m)
{
    std::cout << text << std::endl;
    printf("[%f, %f, %f, %f]\n", m._11, m._12, m._13, m._14);
    printf("[%f, %f, %f, %f]\n", m._21, m._22, m._23, m._24);
    printf("[%f, %f, %f, %f]\n", m._31, m._32, m._33, m._34);
    printf("[%f, %f, %f, %f]\n", m._41, m._42, m._43, m._44);
}

int main()
{
    Vec3 x(1.0f, 0.0f, 0.0f);
    Vec3 y(0.0f, 1.0f, 0.0f);
    Vec3 z;
    z = Cross(x, y);
    PrintVector3(z);
    printf("\n");
    PrintVector3(General::Normalize(z));
    printf("\n");
    printf("%f\n", General::Length(z));
    printf("\n");

    Vec3 v(1.0f, 2.0f, 0.0f);
    Vec4 r_v = Matrix::MulVector(Vec4(v.x, v.y, v.z, 1.0f) ,Transform::PerspectiveMatrixLH(
        Common::ToRadian(90.0f), 800.0f / 600.0f, 0.1f, 100.0f
    ) * Transform::ViewMatrixLH(Vec3(0.0f, 0.0f, -1.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f)) * Matrix::Identity());

    PrintVector3(Vec3(r_v.x, r_v.y, r_v.z));


    //system("pause");
	return 0;
}

	