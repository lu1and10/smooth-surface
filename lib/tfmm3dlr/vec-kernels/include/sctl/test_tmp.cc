#include <math.h> 
#include <iostream>
double my_erf (double a)
{
    double r, s, t, u;

    t = fabs (a);
    s = a * a;
    if (t >= 0.0) {
        // -0x1.9f363bac00b3ap-58, 0x1.17f6b1da05762p-51
        r = fma (-5.6271698458222802e-018, t, 4.8565951833159269e-016);
        // -0x1.66b85b7ea724ep-46, 0x1.22907eeb53bbdp-41
        u = fma (-1.9912968279795284e-014, t, 5.1614612430130285e-013);
        r = fma (r, s, u);
        r = fma (r, t, -9.4934693735334407e-012);  // -0x1.4e0591fcf7297p-37
        r = fma (r, t,  1.3183034417266867e-010);  //  0x1.21e5e2d8345c4p-33
        r = fma (r, t, -1.4354030030124722e-009);  // -0x1.8a8f81b7cd224p-30
        r = fma (r, t,  1.2558925114367386e-008);  //  0x1.af85793b8cf2fp-27
        r = fma (r, t, -8.9719702096026844e-008);  // -0x1.8157db0ed6deap-24
        r = fma (r, t,  5.2832013824236141e-007);  //  0x1.1ba3c45370f62p-21
        r = fma (r, t, -2.5730580226095829e-006);  // -0x1.595999b7e9e12p-19
        r = fma (r, t,  1.0322052949682532e-005);  //  0x1.5a59c27b3c70ep-17
        r = fma (r, t, -3.3555264836704290e-005);  // -0x1.197b61ee3732bp-15
        r = fma (r, t,  8.4667486930270974e-005);  //  0x1.631f0597f6424p-14
        r = fma (r, t, -1.4570926486272249e-004);  // -0x1.319310dfb85f3p-13
        r = fma (r, t,  7.1877160107951816e-005);  //  0x1.2d798353da7c3p-14
        r = fma (r, t,  4.9486959714660115e-004);  //  0x1.037445e25d35dp-11
        r = fma (r, t, -1.6221099717135142e-003);  // -0x1.a939f51db8bcbp-10
        r = fma (r, t,  1.6425707149019371e-004);  //  0x1.5878d80188692p-13
        r = fma (r, t,  1.9148914196620626e-002);  //  0x1.39bc5e0e9e090p-6
        r = fma (r, t, -1.0277918343487556e-001);  // -0x1.a4fbc8f8ff7d7p-4
        r = fma (r, t, -6.3661844223699315e-001);  // -0x1.45f2da3ae06f8p-1
        r = fma (r, t, -1.2837929411398119e-001);  // -0x1.06ebb92d9ffa8p-3
        r = fma (r, t, -t);
        r = 1.0 - exp (r);
        //r = copysign (r, a);
    } else {
        r =            -7.7794684889579207e-10; // -0x1.abae491c43c5cp-31
        r = fma (r, s,  1.3710980398029044e-8); //  0x1.d71b0f1b10b88p-27
        r = fma (r, s, -1.6206313758493333e-7); // -0x1.5c0726f04dd28p-23
        r = fma (r, s,  1.6447131571278885e-6); //  0x1.b97fd3d992901p-20
        r = fma (r, s, -1.4924712302009674e-5); // -0x1.f4ca4d6f3e2a0p-17
        r = fma (r, s,  1.2055293576900647e-4); //  0x1.f9a2baa8fede1p-14
        r = fma (r, s, -8.5483259293145256e-4); // -0x1.c02db03dd71f5p-11
        r = fma (r, s,  5.2239776061184708e-3); //  0x1.565bccf92b2f6p-8
        r = fma (r, s, -2.6866170643111489e-2); // -0x1.b82ce311fa944p-6
        r = fma (r, s,  1.1283791670944184e-1); //  0x1.ce2f21a040d15p-4
        r = fma (r, s, -3.7612638903183515e-1); // -0x1.812746b0379bcp-2
        r = fma (r, s,  1.2837916709551256e-1); //  0x1.06eba8214db68p-3
        r = fma (r, a, a);
    }
    return r;
}

int main(){

    double x0 = 0.01;
    for(int i=1; i<200; i++)
    {
        double x = x0*i;
        std::cout<<"x: "<<x<<", rel error: "<<abs(erf(x)-my_erf(x))/abs(erf(x))<<"\n";
    }
    return 0;
}