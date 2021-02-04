#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005];
int dp[1005][35];
int main()
{
    int t,w;
    scanf("%d %d",&t,&w);
    for (int i=1;i<=t;i++)
        scanf("%d",a+i);
    for (int i=1;i<=t;i++)
    {
        dp[i][0]=dp[i-1][0]+(a[i]&1);
        for (int j=1;j<=w;j++)
        {
            if (j&1) dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+((a[i]-1)&1);
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+(a[i]&1);
        }
    }

    int m=0;
    for (int i=0;i<=w;i++)
        m=max(m,dp[t][i]);
    printf("%d\n",m);
    return 0;
}
