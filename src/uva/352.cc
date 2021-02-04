#include <cstdio>
#include <cstring>

const int N=30;

int n;
char g[N][N];
bool vis[N][N];

void dfs(int i,int j)
{
    vis[i][j]=1;
    for (int di=-1; di<=1; di++)
        for (int dj=-1; dj<=1; dj++)
        {
            if (!(di||dj)) continue;
            int ni=i+di,nj=j+dj;
            if (ni<0 || ni>=n || nj<0 || nj>=n || vis[ni][nj] || g[ni][nj]!='1') continue;
            dfs(ni,nj);
        }
}
int main()
{
    int cnt=1;
    while (~scanf("%d",&n))
    {
        for (int i=0; i<n; i++)
            scanf("%s",g[i]);
        memset(vis,0,sizeof vis);
        int ans=0;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (g[i][j]=='1' && !vis[i][j])
                {
                    ans++;
                    dfs(i,j);
                }
        printf("Image number %d contains %d war eagles.\n",cnt++,ans);
    }
    return 0;
}
