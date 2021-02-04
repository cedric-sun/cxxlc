#include <cstdio>

const int N=30000,coin[]={1,5,10,25,50};
long long ans[N+5];

void init()
{
    ans[0]=1;
    for (int i=0;i<5;i++)
        for (int j=coin[i];j<=N;j++)
            ans[j]+=ans[j-coin[i]];
}

int main()
{
    init();
    int n;
    while (~scanf("%d",&n))
    {
        if (ans[n]==1) printf("There is only 1 way to produce %d cents change.\n",n);
        else printf("There are %lld ways to produce %d cents change.\n",ans[n],n);
    }
    return 0;
}

