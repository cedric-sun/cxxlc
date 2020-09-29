#include <iostream>
#include <cmath>
#include <cstdio>
using std::cin;
int main()
{
    const double pi=3.141592653589793;
    double x1,y1,x2,y2,x3,y3,a,b,c,a2,b2,c2,cosa,sina,zj;
    while (cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
        a2=pow(x2-x1,2)+pow(y2-y1,2);
        b2=pow(x3-x1,2)+pow(y3-y1,2);
        c2=pow(x2-x3,2)+pow(y2-y3,2);
        a=sqrt(a2);
        b=sqrt(b2);
        c=sqrt(c2);
        cosa=(b2+c2-a2)/(2*b*c);
        sina=sqrt(1-pow(cosa,2));
        zj=a/sina;
        printf("%.2lf\n",pi*zj);
    }
    return 0;
}
