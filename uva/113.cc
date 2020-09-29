#include <cstdio>
#include <cmath>
int main()
{
    int a;
    double b;
    while (scanf("%d %lf",&a,&b)!=EOF)
        printf("%.0lf\n",pow(b,1.0/a));
    return 0;
}
