#include <cstdio>

const int N=21,inf=0x7FFFFFFF;
const int di[]={1,0,-1,0},dj[]={0,1,0,-1};

int w,h,si,sj;
int g[N][N],ans;

void dfs(int i,int j,int d)
{
    if (d>=10) return;
    if (d>=ans) return;
    for (int k=0;k<4;k++)
    {
        int ni=i,nj=j;
        while (1)
        {
            ni+=di[k],nj+=dj[k];
            if (ni<0 || ni>=h || nj<0 || nj>=w) break;
            if (g[ni][nj]==3)
            {ans=d;return;}
            if (g[ni][nj]==1)
            {
                if (ni-di[k]!=i || nj-dj[k]!=j)
                {
                g[ni][nj]=0;
                dfs(ni-di[k],nj-dj[k],d+1);
                g[ni][nj]=1;
                }
                break;
            }
        }
    }
}
int main()
{
    while (scanf("%d %d",&w,&h),w)
    {
        for (int i=0;i<h;i++)
            for (int j=0;j<w;j++)
            {
                scanf("%d",&g[i][j]);
                if (g[i][j]==2) si=i,sj=j;
            }

        ans=inf;
        dfs(si,sj,0);
        if (ans==inf)
            printf("-1\n");
        else
            printf("%d\n",ans+1);
    }
    return 0;
}
