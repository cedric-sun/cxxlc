#include <cstdio>
#include <algorithm>
#include <cmath>
using std::sort;
int n,id,f[100+5];
struct edge
{
    int u,v;
    double w;
    bool operator < (edge &ref) {return w<ref.w;}
}e[5000];
struct point
{
    double x,y;
}p[100+5];
inline double dist(int a,int b)
{
    return sqrt(pow( (p[a].x-p[b].x),2 )+pow((p[a].y-p[b].y),2));
}
int uf(int x)
{
    return f[x]==x?x:f[x]=uf(f[x]);
}
double calc()
{
    int cnt=0;
    double ans=0;
    for (int i=0;cnt<n-1 && i<id ;i++)
    {
        int u=uf(e[i].u),v=uf(e[i].v);
        if ( u!=v )
        {
            ans+=e[i].w;
            cnt++;
            f[u]=v;
        }
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int k=0;k<T;k++)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {scanf("%lf %lf",&p[i].x,&p[i].y);}
        id=0;
        for (int i=0;i<n-1;i++)
            for (int j=i+1;j<n;j++)
            {e[id].u=i;e[id].v=j;e[id++].w=dist(i,j);}

        for (int i=0;i<n;i++) f[i]=i;

        sort(e,e+id);
        if (k) putchar('\n');
        printf("%.2f\n",calc());
    }
    return 0;
}
