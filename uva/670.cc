#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100+20;
vector<vector<int> > g;

struct point
{
    int x,y;
};

point bob[N],dog[N];
int lnk[N],map[N];
bool vis[N];

inline double dist(int x1,int y1,int x2,int y2)
{
    return sqrt( pow(x1-x2,2) + pow(y1-y2,2) );
}

int dfs(int u)
{
    for (vector<int>::iterator it=g[u].begin();it!=g[u].end();it++)
        if (!vis[*it])
        {
            vis[*it]=1;
            if (lnk[*it]==-1 || dfs(lnk[*it]))
            {
                lnk[*it]=u;
                return 1;
            }
        }
    return 0;
}
int main()
{
    int L;
    scanf("%d",&L);
    for (int k=0;k<L;k++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
            scanf("%d %d",&bob[i].x,&bob[i].y);
        for (int i=0;i<m;i++)
            scanf("%d %d",&dog[i].x,&dog[i].y);

        g.clear();g.resize(n-1);

        for (int i=0;i<n-1;i++)
        {
            double len=dist(bob[i].x,bob[i].y,bob[i+1].x,bob[i+1].y);
            for (int j=0;j<m;j++)
                if (dist(bob[i].x,bob[i].y,dog[j].x,dog[j].y)+dist(bob[i+1].x,bob[i+1].y,dog[j].x,dog[j].y)<=2*len)
                    g[i].push_back(j);
        }

        memset(lnk,-1,sizeof lnk);

        int ans=0;
        for (int i=0;i<n-1;i++)
        {
            memset(vis,0,sizeof vis);
            ans+=dfs(i);
        }

        if (k) putchar('\n');
        printf("%d\n",ans+n);

        memset(map,-1,sizeof map);
        for (int i=0;i<m;i++)
            if (~lnk[i])
                map[lnk[i]]=i;

        for (int i=0;i<n;i++)
        {
            if (i) putchar(' ');
            printf("%d %d",bob[i].x,bob[i].y);
            if (~map[i])
                printf(" %d %d",dog[map[i]].x,dog[map[i]].y);
        }
        putchar('\n');
    }
}
