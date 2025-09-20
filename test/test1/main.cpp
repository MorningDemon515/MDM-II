#include <stdio.h>
#include <stdlib.h>

#include <mdm.h>
#include <constants.h>

using namespace mdm;
using namespace Common;

int main()
{
    printf("Pow(2.0f, 3): \n");
    printf("%f\n", Pow(2.0f, 3));
    printf("\n");

    printf("Factorial(3): \n");
    printf("%d\n", Factorial(3));
    printf("\n");

    printf("Abs(-2.0f): \n");
    printf("%f\n", Abs(-2.0f));
    printf("\n");

    printf("Mod(2.0f, 3.0f): \n");
    printf("%f\n", Mod(2.0f, 3.0f));
    printf("\n");

    printf("Ceil(2.4f): \n");
    printf("%f\n", Ceil(2.4f));
    printf("\n");

    printf("Floor(2.4f): \n");
    printf("%f\n", Floor(2.4f));
    printf("\n");

    printf("Sqrt(2.0f): \n");
    printf("%f\n", Sqrt(2.0f));
    printf("\n");

    printf("Rsqrt(2.0f): \n");
    printf("%f\n", Rsqrt(2.0f));
    printf("\n");
        
    printf("Exp(1.0f): \n");
    printf("%f\n", Exp(1.0f));
    printf("\n");
        
    printf("Ln(MDM_E): \n");
    printf("%f\n", Ln(MDM_E));
    printf("\n");
        
    printf("Log2(2.0f): \n");
    printf("%f\n", Log2(2.0f));
    printf("\n");
        
    printf("Log10(10.0f): \n");
    printf("%f\n", Log10(10.0f));
    printf("\n");
        
    printf("Ldexp(2.0f, 3): \n");
    printf("%f\n", Ldexp(2.0f, 3));
    printf("\n");

    int integer = 0;
    float x = 2.4f, result;
    result = Rexp(x, &integer);
    printf("x = 2.4, Rexp: \n");
    printf("%f = %f * 2 ^ %d\n", x , result, integer);
    printf("\n");
        
    int integer_2 = 0;
    float x2 = 2.4f, r_2;
    r_2 = Decompose(x, &integer_2);    
    printf("x = 2.4f, Decompose: \n");
    printf("%f = %d + %f\n", x, integer_2, r_2);
    printf("\n");
        
    printf("Sin(MDM_2PI): \n");
    printf("%f\n", Sin(MDM_2PI));
    printf("\n");
        
    printf("Cos(MDM_2PI): \n");
    printf("%f\n", Cos(MDM_2PI));
    printf("\n");
        
    printf("ArcSin(0.5f): \n");
    printf("%f\n", ArcSin(0.5f));
    printf("\n");
        
    printf("ArcCos(0.5f): \n");
    printf("%f\n", ArcCos(0.5f));
    printf("\n");
        
    printf("ArcTan(0.5f): \n");
    printf("%f\n", ArcTan(0.5f));
    printf("\n");
        
    printf("ArcTan2(2.0f, 3.0f): \n");
    printf("%f\n", ArcTan2(2.0f, 3.0f));
    printf("\n");
        
    printf("Sinh(5.0f): \n");
    printf("%f\n", Sinh(5.0f));
    printf("\n");
        
    printf("Cosh(5.0f): \n");
    printf("%f\n", Cosh(5.0f));
    printf("\n");
        
    printf("Tanh(5.0f): \n");
    printf("%f\n", Tanh(5.0f));
    printf("\n");

    system("pause");
	return 0;
}

	