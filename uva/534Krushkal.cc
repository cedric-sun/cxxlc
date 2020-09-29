#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int x[205],y[205],f[205];

struct edge
{
    int a,b;
    double v;
    bool operator < (const edge &ref) const {return v<ref.v;}
    edge(int aa,int bb):a(aa),b(bb),v(sqrt(pow(x[a]-x[b],2)+pow(y[a]-y[b],2))){}
};


vector<edge> e;

int uf(int x) {return x==f[x]?x:f[x]=uf(f[x]);}

int main()
{
    int n,cnt=1;
    while (scanf("%d",&n),n)
    {
        e.clear();
        for (int i=0;i<n;i++) f[i]=i;
        for (int i=0;i<n;i++)
            scanf("%d %d",x+i,y+i);

        for (int i=0;i<n-1;i++)
            for (int j=i+1;j<n;j++)
                e.push_back(edge(i,j));

        sort(e.begin(),e.end());

        double maxdist=0;
        for (int i=0;uf(0)!=uf(1);i++)
        {
            int a=uf(e[i].a),b=uf(e[i].b);
            maxdist=max(maxdist,e[i].v);
            if (a!=b)
                f[a]=b;
        }

        printf("Scenario #%d\n",cnt++);
        printf("Frog Distance = %.3f\n\n",maxdist);
    }
    return 0;
}
