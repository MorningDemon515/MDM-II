#ifndef MDM_H
#define MDM_H

namespace mdm{
   namespace Common
   {
      //First Part
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
      
      //Second Part
        float Max(float a, float b);
        float Min(float a, float b);
        float Hypot(float x, float y);

        float Cbrt(float x);
        float Expml(float x);
        float Lnlp(float x);

        float ArSinh(float x);
        float ArCosh(float x);
        float ArTanh(float x);

        int Trunc(float x);
        int Round(float x);

        float PosInf();
        float NegInf();

        bool Isfinite(float x);
        bool IsInf(float x);
        bool IsNaN(float x);
        bool IsNormal(float x);
        bool Signbit(float x);

        bool Equal(float a, float b);
        float ToRadian(float angle);
        float ToAngle(float radian);
   }
}

#endif