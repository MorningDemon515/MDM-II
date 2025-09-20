#include <mdm.h>
#include <constants.h>

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

namespace mdm{
   namespace Common
   {
        float Pow(float x, int n)
        {
            float result = 1.0f;
            for (int i = 0; i < n; i++)
            {
                result *= x;
            }
            
            return result;
        }

        int Factorial(int x)
        {
            int result = 1;
            for (int i = 1; i < x; i++)
            {
                result *= i + 1;
            }

            return result;
            
        }

        float Abs(float x)
        {
            return (x > 0.0f)? x : -x;
        }

        float Mod(float x, float y)
        {
            if(y == 0.0f)
                return 0.0f;

            int temp = (int)(x / y);
            return x - (float)temp * y;
        }

///////////////////////////////////////////////////////////////////////////////////////////////////        

        float Ceil(float x)
        {
            return (Mod(x, 2.0f) == 0.0f)? x : (int)x + 1;
        }

        float Floor(float x)
        {
            return (int)x;
        }

///////////////////////////////////////////////////////////////////////////////////////////////////
        //From https://github.com/id-Software/Quake-III-Arena/blob/master/code/game/q_math.c#L552
        float Rsqrt(float x)
        {
            long i;
	        float x2, y;
	        const float threehalfs = 1.5F;

	        x2 = x * 0.5F;
	        y  = x;
    	    i  = * ( long * ) &y;						// evil floating point bit level hacking
    	    i  = 0x5f375a86 - ( i >> 1 );               // what the fuck?
    	    y  = * ( float * ) &i;
    	    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    	    y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    
	        return y;
        }

        float Sqrt(float x)
        {
            long i;
	        float y;

	        y  = x;
	        i  = * ( long * ) &y;						// evil floating point bit level hacking
	        i  = ( i >> 1 ) + 0x1fc00000;               // new magic number
	        y  = * ( float * ) &i;
            y = 0.5f * ( y + x / y);// 1st iteration
            y = 0.5f * ( y + x / y);// 2nd iteration
            //y = 0.5f * ( y + number / y);// 3rd iteration

	        return y;
        }

/////////////////////////////////////////////////////////////////////////////////////////////////
        float Exp(float x)
        {
            float term = 1.0f;
            float result = term;

            for (int i = 0; i < 10; i++)
            {
                term *=  x / (float)(i + 1);
                result += term;
            }
            
            return result;
        }

        float Ln(float x)
        {
            if(x <= 0.0f)
                return 0.0f;

            float temp = (x - 1) / (x + 1);
            float result = 0.0f;
            
            for (int i = 0; i < 43; i++)
            {
                result += (1.0f / (float)(2 * i + 1)) * Pow(temp, 2 * i + 1) ;
            }
            
            return 2.0f * result;    
        }

        float Log2(float x)
        {
            return Ln(x) / MDM_LN2;
        }

        float Log10(float x)
        {
            return Ln(x) / MDM_LN10;
        }

        float Ldexp(float x, int exponent)
        {
            return x * Pow(2.0f, exponent);
        }

////////////////////////////////////////////////////////////////////////////////////////////////        
        //From DeepSeek :-)
        float Rexp(float x, int* exponent)
        {
            unsigned int bits;
            memcpy(&bits, &x, sizeof(bits));

            unsigned int sign_mask = 0x80000000;
            unsigned int exp_mask  = 0x7F800000;
            unsigned int mant_mask = 0x007FFFFF;

            int sign_bit = (bits & sign_mask) != 0;
            int exp_bits = (bits & exp_mask) >> 23;
            unsigned int mant_bits = bits & mant_mask;

            const int bias = 127;

            int real_exp = exp_bits - bias;

            *exponent = real_exp + 1;

            unsigned int new_exp_bits = (bias - 1) << 23;
            unsigned int new_bits = (sign_bit ? sign_mask : 0) | new_exp_bits | mant_bits;

            float result;
            memcpy(&result, &new_bits, sizeof(result));
            return result;
        }

        float Decompose(float x, int* integer)
        {
            *integer = (int)x;
            return x - *integer;
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////

        float Sin(float x)
        {
            x = Mod(x, MDM_2PI);
           if (x > MDM_PI) {
                x -= MDM_2PI;
            } else if (x < -MDM_PI) {
                x += MDM_2PI;
            }

            float term = x;
            float result = term;
 
            for (int n = 1; n < 20; ++n) {
                //(-1)^n * x^(2n+1) / (2n+1)!
                term *= -x * x / ((2 * n) * (2 * n + 1));
                result += term;
            }
    
            return result;
        }

        float Cos(float x)
        {
            x = Mod(x, MDM_2PI);

            if (x > MDM_PI) {
                x -= MDM_2PI;
            } else if (x < -MDM_PI) {
                x += MDM_2PI;
            }

            float term = 1.0f;
            float result = term;
 
            for (int n = 1; n < 20; ++n) {
                //(-1)^n * x^(2n) / (2n)!
                term *= -x * x / ((2 * n) * (2 * n - 1));
                result += term;
            }
    
            return result;
        }

        float ArcSin(float x)
        {
            float result = 0.0f;

            for (int i = 0; i < 8; i++)
            {
                result += ( (float)Factorial(2 * i) / 
                            (Pow(4.0f, i) * (2 * i + 1) * Pow((float)Factorial(i), 2) ) )
                            * Pow(x, 2 * i + 1);
            }
            
            return result;
        }

        float ArcCos(float x)
        {
            return MDM_PI_2 - ArcSin(x);
        }

        float ArcTan(float x)
        {
            float result = 0.0f;

            for (int i = 0; i < 24; i++)
            {
                result += (Pow(-1.0f, i) / (2 * i + 1)) * Pow(x, 2 * i + 1);
            }
            
            return result;
        }

        float ArcTan2(float y, float x)
        {
            return ArcTan(y / x);
        }

        float Sinh(float x)
        {
            float term = x;
            float result = term;

            for (int i = 1; i < 20; i++)
            {
                term *= (x * x) / ((2 * i) * (2 * i + 1));
                result += term;
            }
            
            return result;
        }

        float Cosh(float x)
        {
            float term = 1.0f;
            float result = term;

            for (int i = 1; i < 20; i++)
            {
                term *= (x * x) / ((2 * i) * (2 * i - 1));
                result += term;
            }
            
            return result;
        }

        float Tanh(float x)
        {
            return Sinh(x) / Cosh(x);
        }
   }
}