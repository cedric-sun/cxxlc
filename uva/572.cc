#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N=105;

char g[N][N];
bool vis[N][N];

int main()
{
    int n,m;
    while (scanf("%d %d",&n,&m),n)
    {
        memset(vis,0,sizeof vis);
        for (int i=0; i<n; i++)
            scanf("%s",g[i]);
        int ans=0;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (g[i][j]=='@' && !vis[i][j])
                {
                    ans++;
                    queue<int> q;
                    q.push((i<<8)+j);
                    while (!q.empty())
                    {
                        int cur=q.front(),cj=cur&0xFF,ci=cur>>8;
                        q.pop();
                        vis[ci][cj]=1;
                        for (int di=-1; di<=1; di++)
                            for(int dj=-1; dj<=1; dj++)
                            {
                                int ni=ci+di,nj=cj+dj;
                                if ( ni>=0 && ni<n && nj>=0 && nj<m && g[ni][nj]=='@' && !vis[ni][nj] && (di||dj))
                                    q.push((ni<<8)+nj);
                            }
                    }
                }
        printf("%d\n",ans);
    }
    return 0;
}
