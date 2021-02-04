#include <cstdio>

int dp[35][4];

void init()
{
    for (int i=0;i<4;i++) dp[2][i]=1;
    for (int i=3;i<=30;i++)
    {
        dp[i][0]=dp[i-1][2];
        dp[i][1]=dp[i-1][0]+dp[i-1][2];
        dp[i][2]=dp[i-1][1]+dp[i-1][3];
        dp[i][3]=dp[i-1][1]+dp[i-1][3];
    }
}
//UU=0  UL=1  LU=2 LL=3
int main()
{
    int n;
    init();
    while (scanf("%d",&n),n)
        printf("%d\n",n==1?0:(1<<n)-dp[n][0]-dp[n][1]-dp[n][2]-dp[n][3]);
    return 0;
}
