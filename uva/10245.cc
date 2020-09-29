#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_PN=10000+5;
const int INF=0x7fffffff;

struct point
{
    double x,y;
}p[MAX_PN];

int n;

inline double dist(int a,int b)
{
    return sqrt(pow(p[a].x-p[b].x,2) + pow(p[a].y-p[b].y,2) );
}

bool cmpx(const point &r1,const point &r2) {return r1.x<r2.x;}
bool cmpy(int r1,int r2) {return p[r1].y<p[r2].y;}

double POINT_SET_MIN_DIST(const int l,const int r)
{
    if (l==r) return INF;
    if (r-l==1) return dist(l,r);
    int mid=(l+r)>>1;
    double dl=POINT_SET_MIN_DIST(l,mid);
    double dr=POINT_SET_MIN_DIST(mid+1,r);
    double d=min(dl,dr);

    static int strip[MAX_PN],strip_size;
    strip_size=0;
    for (int i=l;i<=r;i++) if (fabs( p[i].x - p[mid].x )<=d) strip[strip_size++]=i;

    sort(strip,strip+strip_size,cmpy);

    for (int i=0;i<strip_size;i++)
        for (int j=i+1;j<strip_size;j++)
        {
            if (p[strip[j]].y-p[strip[i]].y>=d) break;
            double tmp=dist(strip[i],strip[j]);
            d=min(d,tmp);
        }

    return d;
}
int main()
{
    while (scanf("%d",&n),n)
    {
        for (int i=0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
        sort(p,p+n,cmpx);
        double ans=POINT_SET_MIN_DIST(0,n-1);
        if (ans>=1e4) puts("INFINITY");
        else printf("%.4f\n", ans);
    }
    return 0;
}
