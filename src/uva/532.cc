#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N=32,
di[6]= {1,-1,0,0,0,0},
dj[6]= {0,0,1,-1,0,0},
dk[6]= {0,0,0,0,1,-1};

int rs,cs,hs;
bool g[N][N][N];
bool vis[N][N][N];
int d[N][N][N];
struct loc
{
    int i,j,k;
    loc(int kk=0,int ii=0,int jj=0):i(ii),j(jj),k(kk){};
    bool operator == (loc &ref) {return i==ref.i && j==ref.j && k==ref.k;}
};

loc start,end;

bool read()
{
    scanf("%d %d %d",&hs,&rs,&cs);
    if (!hs) return 0;

    getchar();
    char t;
    for (int k=0; k<hs; k++)
    {
        for (int i=0; i<rs; i++)
        {
            for (int j=0; j<cs; j++)
            {
                t=getchar();
                switch(t)
                {
                    case 'S':start.i=i;start.j=j;start.k=k;g[k][i][j]=1;break;
                    case 'E':end.i=i;end.j=j;end.k=k;g[k][i][j]=1;break;
                    case '.':g[k][i][j]=1;break;
                    case '#':g[k][i][j]=0;break;
                }
            }
            getchar();
        }
        getchar();
    }
    return 1;
}

int bfs()
{
    queue<loc> q;
    q.push(start);
    vis[start.k][start.i][start.j]=1;
    d[start.k][start.i][start.j]=0;
    while (!q.empty())
    {
        loc cur=q.front();
        q.pop();
        int i=cur.i,j=cur.j,k=cur.k;
        for (int t=0;t<6;t++)
        {
            int ni=cur.i+di[t],nj=cur.j+dj[t],nk=cur.k+dk[t];
            if (g[nk][ni][nj] && ni>=0 && ni<rs && nj>=0 && nj<cs && nk>=0 && nk<hs && !vis[nk][ni][nj])
            {
                vis[nk][ni][nj]=1;
                d[nk][ni][nj]=d[k][i][j]+1;
                loc next(nk,ni,nj);
                if (next==end)
                    return d[nk][ni][nj];
                q.push(next);
            }
        }
    }
    return -1;
}
int main()
{
    while (read())
    {
        memset(vis,0,sizeof vis);
        int ans=bfs();
        if (ans<0)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}
