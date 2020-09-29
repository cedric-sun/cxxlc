#include <cstdio>
#include <cstring>

const int N=105,M=500*N;

int sum,a[N];
bool dp[M];

void zoknap(int w)
{
    for (int j=sum; j>=w; j--)
        if (dp[j-w]) dp[j]=1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        sum=0;
        memset(dp,0,sizeof dp);dp[0]=1;
        for (int i=0; i<n; i++){scanf("%d",a+i);sum+=a[i];}

        for (int i=0; i<n; i++) zoknap(a[i]);

        int it=0;
        for (it=sum>>1;it>=0;it--) if (dp[it]) break;
        printf("%d\n",sum-2*it);
    }
    return 0;
}
