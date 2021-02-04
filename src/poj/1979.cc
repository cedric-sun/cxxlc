#include <cstdio>
#include <cstring>

const int N=25,
            di[]= {1,0,-1,0},
            dj[]= {0,1,0,-1};
int ans,n,m;
char g[N][N];
bool vis[N][N];

void dfs(int i,int j)
{
    vis[i][j]=1;
    ans++;
    for (int k=0; k<4; k++)
    {
        int ni=i+di[k],nj=j+dj[k];
        if (g[ni][nj]=='.' && !vis[ni][nj] && ni>=0 && ni<m && nj>=0 && nj<n)
            dfs(ni,nj);
        }
}
int main()
{
    while (scanf("%d %d",&n,&m),n)
    {
        memset(vis,0,sizeof vis);
        for (int i=0; i<m; i++)
            scanf("%s",g[i]);

        bool fs=0;
        int si,sj;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
                if (g[i][j]=='@')
                {
                    si=i;
                    sj=j;
                    fs=1;
                    break;
                }
            if (fs) break;
        }

        ans=0;
        dfs(si,sj);
        printf("%d\n",ans);
    }
    return 0;
}
