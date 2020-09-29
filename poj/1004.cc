#include <cstdio>

int main()
{
    int cnt;
    double tmp,sum=0;
    while (~scanf("%lf",&tmp))
    {sum+=tmp;cnt++;}
    printf("$%.2f\n",sum/cnt);
    return 0;
}
