#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <mdm.h>
#include <constants.h>

using namespace mdm;
using namespace Common;

int main()
{
    std::cout<<"Max(2.0f, 3.0f): \n";
    std::cout<<"Result: " << Max(2.0f, 3.0f) << std::endl;
    std::cout<<"\n";

    std::cout<<"Min(2.0f, 3.0f): \n";
    std::cout<<"Result: " << Min(2.0f, 3.0f) << std::endl;
    std::cout<<"\n";
    
    std::cout<<"Hypot(4.0f, 3.0f): \n";
    std::cout<<"Result: " << Hypot(4.0f, 3.0f) << std::endl;
    std::cout<<"\n";
    
    std::cout<<"Cbrt(27.0f): \n";
    std::cout<<"Result: " << Cbrt(27.0f) << std::endl;
    std::cout<<"\n";
    
    std::cout<<"Expml(1.0f): \n";
    std::cout<<"Result: " << Expml(1.0f) << std::endl;
    std::cout<<"\n";
    
    std::cout<<"Lnlp(2.0f): \n";
    std::cout<<"Result: " << Lnlp(2.0f) << std::endl;
    std::cout<<"\n";
    
    std::cout<<"ArSinh(0.5f): \n";
    std::cout<<"Result: " << ArSinh(0.5f) << std::endl;
    std::cout<<"\n";
    
    std::cout<<"ArCosh(0.5f): \n";
    std::cout<<"Result: " << ArCosh(0.5f) << std::endl;
    std::cout<<"\n";
    
    std::cout<<"ArTanh(0.5f): \n";
    std::cout<<"Result: " << ArTanh(0.5f) << std::endl;
    std::cout<<"\n";
    
    std::cout<<"Trunc(2.23f): \n";
    std::cout<<"Result: " << Trunc(2.23f) << std::endl;
    std::cout<<"\n";
    
    std::cout<<"Round(2.6f): \n";
    std::cout<<"Result: " << Round(2.6f) << std::endl;
    std::cout<<"\n";

    std::cout<<"Equal(2.0f, 2.00000001f): \n";
    std::cout<<"Bool Value: " << Equal(2.0f, 2.00000001f) << std::endl;
    std::cout<<"\n";
    
    std::cout<<"Sin(ToRadian(30.0f)): \n";
    std::cout<<"Result: " << Sin(ToRadian(30.0f)) << std::endl;
    std::cout<<"\n";
    
    std::cout<<"ToAngle(MDM_PI_2): \n";
    std::cout<<"Result: " << ToAngle(MDM_PI_2) << std::endl;
    std::cout<<"\n";

    system("pause");
	return 0;
}

	