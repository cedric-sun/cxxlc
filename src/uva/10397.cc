#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using std::sort;
using std::vector;
using std::swap;
const int N=750+5;

struct edge
{
    int u,v;
    double w;
    edge(int uu,int vv,double ww):u(uu),v(vv),w(ww){};
    bool operator < (edge &ref) {return w<ref.w;}
};
struct point
{
    int x,y;
}p[N];

vector<edge> e;
int n,m;
int f[N];

int uf(int x) {return f[x]==x?x:f[x]=uf(f[x]);}

inline double dist(int a,int b)
{
    return sqrt( pow((p[a].x-p[b].x),2) + pow((p[a].y-p[b].y),2) );
}
inline int id(int i,int j)
{
    if (i>j) swap(i,j);
    return (2*n-i)*(i-1)/2 + (j-i)-1;
}

double calc()
{
    double ans=0;
    int cnt=0;
    for (int i=0;cnt<n-1;i++)
    {
        int u=uf(e[i].u),v=uf(e[i].v);
        if (u!=v)
        {
            cnt++;
            ans+=e[i].w;
            f[u]=v;
        }
    }
    return ans;
}

int main()
{
    while (~scanf("%d",&n))
    {
        e.clear();
        for (int i=1;i<=n;i++) {f[i]=i;}
        for (int i=1;i<=n;i++)
            scanf("%d %d",&p[i].x,&p[i].y);
        for (int i=1;i<n;i++)
            for (int j=i+1;j<=n;j++)
                e.push_back(edge(i,j,dist(i,j)));

        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            e[id(a,b)].w=0;
        }
        sort(e.begin(),e.end());

        printf("%.2f\n",calc());
    }
    return 0;
}
