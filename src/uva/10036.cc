#include <cstdio>
#include <cstring>

int a[10005];
bool dp[10005][105];//前i个数组成的表达式的结果，被k除可能余j

int main()
{
    int T;
    scanf("%d" , &T);
    while (T--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%d",a+i);

        memset(dp,0,sizeof dp);
        dp[0][0]=1;

        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<k;j++)
            if (dp[i-1][j])
            {
                dp[i][((j+a[i])%k+k)%k]=1;
                if (i!=1) dp[i][((j-a[i])%k+k)%k]=1;
            }
        }

        puts(dp[n][0]?"Divisible":"Not divisible");
    }
    return 0;
}
