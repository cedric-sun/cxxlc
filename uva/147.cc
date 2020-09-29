#include <cstdio>

const int N=30000,coin[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long ans[N+5];

void init()
{
    ans[0]=1;
    for (int i=0;i<11;i++)
        for (int j=coin[i];j<=N;j++)
            ans[j]+=ans[j-coin[i]];
}
int main()
{
    init();
    double n;
    while (scanf("%lf",&n),n) printf("%6.2f%17lld\n",n,ans[(int)(n*100+0.5)]);
    return 0;
}
