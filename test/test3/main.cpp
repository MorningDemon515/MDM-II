#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <mdm.h>
#include <constants.h>

using namespace mdm;
using namespace Common;
using namespace Vector;
using namespace Matrix;

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
    MATRIX m;
    MATRIX m1, m2;
    m1 = IdentityMatrix(); m2 = MATRIX(
        5.0f, 4.0f, 7.0f, 1.0f,
        6.0f, 2.0f, 5.0f, 4.0f, 
        2.0f, 1.0f, 5.0f, 2.0f,
        3.0f, 1.0f, 3.0f, 1.0f
    );
    m = m2 * 0.2f;
    PrintMatrix("Identity Matrix", m2 * InvMatrix(m2));
    m2 *= InvMatrix(m2);
    PrintMatrix("Identity Matrix", m2);
    printf("%d\n", m1 != m2);
    printf("%f\n", DetMatrix(m2));
    //system("pause");
	return 0;
}

	