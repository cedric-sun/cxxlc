#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int N=100+5;
int n,m,s,v;
struct coor
{
    double x,y;
};
coor l[N],r[N];
int lnk[N];
bool vis[N];
vector< vector<int> > G;

inline double dist(int a,int b)
{
    return sqrt( pow((l[a].x-r[b].x),2) + pow((l[a].y-r[b].y),2) );
}

int dfs(int u)
{
    for (vector<int>::iterator it=G[u].begin();it!=G[u].end();it++)
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
    while (~scanf("%d %d %d %d",&n,&m,&s,&v))
    {
        int lim=s*v;
        for (int i=0;i<n;i++)
            scanf("%lf %lf",&l[i].x,&l[i].y);
        for (int i=0;i<m;i++)
            scanf("%lf %lf",&r[i].x,&r[i].y);

        G.clear();
        G.resize(n);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (dist(i,j)<=lim)
                    G[i].push_back(j);

        int ans=0;
        memset(lnk,-1,sizeof lnk);
        for (int i=0;i<n;i++)
        {
            memset(vis,0,sizeof vis);
            ans+=dfs(i);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
