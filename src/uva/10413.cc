#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n,c[20],p[20],l[20];

int x,y,gcd;
void exgcd(int a,int b)
{
    if (!b) {x=1;y=0;gcd=a;return;}
    exgcd(b,a%b);
    int tmp=x;
    x=y;
    y=tmp-a/b*y;
    return;
}

bool solve(int i,int j,int m)
{
    int a=p[i]-p[j],b=m,ct=c[j]-c[i];
    exgcd(a,b);
    if (ct%gcd) return 0;
    int xc=x*ct/gcd;
    double tmp1=1.0*(1-xc)*gcd/b,tmp2=1.0*(min(l[i],l[j])-xc)*gcd/b;
    int lb,ub;
    if (b/gcd>0)
    {
        lb=ceil(tmp1);
        ub=floor(tmp2);
    }
    else
    {
        lb=ceil(tmp2);
        ub=floor(tmp1);
    }
    if (lb<=ub) return 1;
    return 0;
}
bool test(int m)
{
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (solve(i,j,m)) return 0;
    return 1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        int lb=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d %d %d",c+i,p+i,l+i);
            lb=max(lb,c[i]);
            --c[i];
        }
        int ans=-1;
        for (int i=lb;i<=1000000;i++)
            if (test(i))
            {
                ans=i;
                break;
            }
        printf("%d\n",ans);
    }
    return 0;
}
