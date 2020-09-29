#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
    int a,b,v;
    bool operator < (const edge &ref) const {return v>ref.v;}
    edge(int aa,int bb,int vv):a(aa),b(bb),v(vv){}
};

vector<edge> e;
int f[105];

int uf(int x) {return x==f[x]?x:f[x]=uf(f[x]);}

int main()
{
    int n,r,cnt=1;
    while (scanf("%d %d",&n,&r),n+r)
    {
        e.clear();
        for (int i=1;i<=n;i++) f[i]=i;
        for (int i=0;i<r;i++)
        {
            int a,b,v;
            scanf("%d %d %d",&a,&b,&v);
            e.push_back(edge(a,b,v));
        }

        sort(e.begin(),e.end());

        int s,d,t;
        scanf("%d %d %d",&s,&d,&t);

        int minroad=(1<<31)-1;
        for (int i=0;uf(s)!=uf(d);i++)
        {
            int a=uf(e[i].a),b=uf(e[i].b);
            if (a!=b)
                f[a]=b;
            minroad=min(minroad,e[i].v);
        }

        int ans=t%(minroad-1)?t/(minroad-1)+1:t/(minroad-1);
        printf("Scenario #%d\n",cnt++);
        printf("Minimum Number of Trips = %d\n\n",ans);
    }
    return 0;
}
