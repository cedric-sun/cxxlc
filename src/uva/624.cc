#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=20,M=N*100;

int s,n,p;
int a[N],dp[M],ans[N];
bool decision[N][M];

void backtrack(int i,int j)
{
    if (i<0) return;
    if (decision[i][j])
    {
        backtrack(i-1,j-a[i]);
        ans[p++]=a[i];
    }
    else
    {
        backtrack(i-1,j);
    }
}

int main()
{
    while (~scanf("%d %d",&s,&n))
    {
        int sum=0;
        for (int i=0;i<n;i++) {scanf("%d",a+i);sum+=a[i];}
        if (s>sum) s=sum;
        memset(dp,0,sizeof dp);
        memset(decision,0,sizeof decision);
        for (int i=0;i<n;i++)
        {
            for (int j=s,w=a[i];j>=w;j--)
            {
                dp[j]=max(dp[j],dp[j-w]+w);
                if (dp[j]==dp[j-w]+w) decision[i][j]=1;
            }
        }

        p=0;
        backtrack(n-1,s);

        sum=0;
        for (int i=0;i<p;i++)
        {
            printf("%d ",ans[i]);
            sum+=ans[i];
        }
        printf("sum:%d\n",sum);
    }
    return 0;
}
