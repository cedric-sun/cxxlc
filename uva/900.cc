#include <cstdio>

long long ans[51];

void init()
{
    ans[1]=1;
    ans[2]=2;
    for (int i=3;i<=50;i++)
        ans[i]=ans[i-1]+ans[i-2];
}

int main()
{
    int n;
    init();
    while (scanf("%d",&n),n)
        printf("%lld\n",ans[n]);
    return 0;
}
