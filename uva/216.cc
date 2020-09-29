#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct edge
{
    int u,v;
    double d;
    edge(int _u,int _v,double _d):u(_u),v(_v),d(_d){}
    bool operator < (edge &ref) const {return d<ref.d;}
};

struct adj
{
    int to;
    double d;
    adj(int _to,double _d):to(_to),d(_d){}
};
vector<edge> e;
vector<vector<adj> > G;

int xi[8],yi[8],f[10];

/********************/
int uf(int x) {return f[x]<0?x:f[x]=uf(f[x]);}
void join(int a,int b)
{
    if (f[a]<=f[b]) f[a]+=f[b],f[b]=a;
    else f[b]+=f[a],f[a]=b;
}
/********************/

int dfs1(int x,int prev)
{
    if (G[x].size()==1) return x;
    for (auto it=G[x].begin();it!=G[x].end();++it)
    {
        if (it->to==prev) continue;
        return dfs1(it->to,x);
    }
    return 0x80000000;
}

void dfs2(int x,int prev,double &sum)
{
    for (auto it=G[x].begin();it!=G[x].end();++it)
    {
        if (it->to==prev) continue;
        sum+=it->d;
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",xi[x],yi[x],xi[it->to],yi[it->to],it->d);
        dfs2(it->to,x,sum);
    }
}
void output(int head,int cnt)
{
    printf("**********************************************************\n");
    printf("Network #%d\n",cnt);
    double sum=0;
    dfs2(head,-1,sum);
    printf("Number of feet of cable required is %.2f.\n",sum);
    printf("**********************************************************\n");
}
inline double dist(int i,int j)
{
    return sqrt(pow(xi[i]-xi[j],2)+pow(yi[i]-yi[j],2));
}
int main()
{
    int n,cnt=1;
    while (scanf("%d",&n),n)
    {
        memset(f,-1,sizeof f);
        G.clear();G.resize(n);
        for (int i=0;i<n;i++)
            scanf("%d %d",xi+i,yi+i);
        for (int i=0;i<n-1;i++)
            for (int j=i+1;j<n;j++)
                e.push_back(edge(i,j,dist(i,j)));
        sort(e.begin(),e.end());
        int ecnt=0;
        for (auto it=e.begin();ecnt<n-1 && it!=e.end();++it)
        {
            int a=uf(it->u),b=uf(it->v);
            if (a!=b)
            {
                join(a,b);
                G[it->u].push_back(adj(it->v,it->d));
                G[it->v].push_back(adj(it->u,it->d));
                ecnt++;
            }
        }
        output(dfs1(0,-1),cnt++);
    }
    return 0;
}
