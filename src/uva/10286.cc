#include <cstdio>
#include <cmath>

const double pi=acos(-1.0);
const double k=sin(108.0/180*pi)/sin(63.0/180*pi);

int main()
{
    double t;
    while (~scanf("%lf",&t)) printf("%.10f\n",t*k);
    return 0;
}
