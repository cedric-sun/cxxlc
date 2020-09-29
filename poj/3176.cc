#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=355;
int n;
int g[N][N],ans[N][N];

int dp(int i,int j)
{
    if (ans[i][j]>=0) return ans[i][j];
    if (i==n-1)
        return ans[i][j]=g[i][j];
    return ans[i][j]=g[i][j]+max(dp(i+1,j),dp(i+1,j+1));
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        for (int j=0;j<=i;j++)
            scanf("%d",&g[i][j]);
    memset(ans,-1,sizeof ans);

    printf("%d\n",dp(0,0));
    return 0;
}
