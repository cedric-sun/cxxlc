#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int coin[]={5,10,20,50,100,200};

int p,num[6],maxv;

void zoknap(int dp[],int w)
{
    for (int j=maxv;j>=w;j--)
        if (~dp[j-w] && (dp[j]==-1 || dp[j]>dp[j-w]+1))
            dp[j]=dp[j-w]+1;
}

void comknap(int dp[],int w)
{
    for (int j=w;j<=maxv;j++)
        if (~dp[j-w] && (dp[j]==-1 || dp[j]>dp[j-w]+1))
            dp[j]=dp[j-w]+1;
}

void multiknap(int dp[])
{
    for (int i=0;i<6;i++)
    {
        if (coin[i]*num[i]>=maxv) comknap(dp,coin[i]);
        else while (num[i]--) zoknap(dp,coin[i]);
    }
}

bool read()
{
    maxv=0;
    bool flag=0;
    for (int i=0;i<6;i++)
    {
        scanf("%d",num+i);
        maxv+=num[i]*coin[i];
        if (num[i]) flag=1;
    }
    if (!flag) return 0;
    double tmp;scanf("%lf",&tmp);
    p=(int)(tmp*100+0.5);
    return 1;
}
int main()
{
    //freopen("out.txt","w",stdout);
    while (read())
    {
        int *dp1=new int[maxv+5],*dp2=new int[maxv+5];
        memset(dp1,-1,sizeof(int)*(maxv+5));dp1[0]=0;
        memset(dp2,-1,sizeof(int)*(maxv+5));dp2[0]=0;
        multiknap(dp1);
        for (int i=0;i<6;i++) comknap(dp2,coin[i]);
        int ans=0x7fffffff;
        for (int i=p;i<=maxv;i++)
            if (~dp1[i] && ~dp2[i-p])
                ans=min(ans,dp1[i]+dp2[i-p]);
        printf("%3d\n",ans);
        delete dp1;delete dp2;
    }
    return 0;
}
