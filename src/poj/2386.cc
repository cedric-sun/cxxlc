#include <cstdio>
#include <cstring>

const int N=105;

int n,m;
char g[N][N];
bool vis[N][N];

void dfs(int i,int j)
{
    vis[i][j]=1;
    for (int di=-1; di<=1; di++)
        for (int dj=-1; dj<=1; dj++)
            if (di||dj)
            {
                int ni=i+di,nj=j+dj;
                if (g[ni][nj]=='W' && !vis[ni][nj] && ni>=0 && ni<n &&nj>=0 &&nj<m)
                    dfs(i+di,j+dj);
            }
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++)
        scanf("%s",g[i]);

    int ans=0;
    memset(vis,0,sizeof vis);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (g[i][j]=='W' && !vis[i][j])
            {
                dfs(i,j);
                ans++;
            }
    printf("%d\n",ans);
    return 0;
}
