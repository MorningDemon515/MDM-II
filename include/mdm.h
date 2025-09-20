#ifndef MDM_H
#define MDM_H

namespace mdm{
   namespace Common
   {
        float Pow(float x, int n);
        int Factorial(int x);
        float Abs(float x);
        float Mod(float x, float y);

        float Ceil(float x);
        float Floor(float x);

        float Sqrt(float x);
        float Rsqrt(float x);

        float Exp(float x);
        float Ln(float x);
        float Log2(float x);
        float Log10(float x);
        float Ldexp(float x, int exponent);

        float Decompose(float x, int* integer);
        float Rexp(float x, int* exponent);
        
        float Sin(float x);
        float Cos(float x);
        float ArcSin(float x);
        float ArcCos(float x);
        float ArcTan(float x);
        float ArcTan2(float y, float x);
        float Sinh(float x);
        float Cosh(float x);
        float Tanh(float x);
   }
}

#endif