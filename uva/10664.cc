#include <cstdio>
#include <cstring>

int sum,a[20+5];
bool dp[20*200+5];

void zoknap(int w)
{
    for (int j=sum;j>=w;j--)
        if (dp[j-w]) dp[j]=1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        sum=0;
        int n=0;
        do
        {
            scanf("%d",a+n);
            sum+=a[n++];
        }while (getchar()!='\n');

        memset(dp,0,sizeof dp);dp[0]=1;

        for (int i=0;i<n;i++) zoknap(a[i]);

        puts((sum&1 || !dp[sum>>1])?"NO":"YES");
    }
    return 0;
}
