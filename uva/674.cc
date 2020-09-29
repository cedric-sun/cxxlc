#include <cstdio>

const int N=7489,coin[]={1,5,10,25,50};
int ans[N+5];

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
    while (~scanf("%d",&n)) printf("%d\n",ans[n]);
    return 0;
}
