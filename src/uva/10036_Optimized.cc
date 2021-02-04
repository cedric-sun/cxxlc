#include <cstdio>
#include <cstring>

bool dp[105],tmp[105];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n,k;
        scanf("%d %d",&n,&k);

        memset(dp,0,sizeof dp);
        dp[0]=1;

        for (int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            for (int j=0;j<k;j++)
                if (dp[j])
                {
                    tmp[((j+a)%k+k)%k]=1;
                    if (i!=1) tmp[((j-a)%k+k)%k]=1;
                }
            memcpy(dp,tmp,sizeof dp);
            memset(tmp,0,sizeof tmp);
        }
        puts(dp[0]?"Divisible":"Not divisible");
    }
    return 0;
}

