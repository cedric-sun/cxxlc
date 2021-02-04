#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n,l,r,t;

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

bool dfs(int x,int y,int cur)
{
    if (!x && !y) return 1;
    int k=min(x,(n-cur)/r);
    if (cur+r<=n && k) return dfs(x-k,y,cur+k*r);
    k=min(y,cur/l);
    if (k) return dfs(x,y-k,cur-k*l);
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %d %d %d",&n,&l,&r,&t);//rx+ly+1=t,x>=0,y<=0
        if (t==1) {puts("0");continue;}
        --t;--n;
        exgcd(r,l);
        if (t%gcd) puts("uh-oh!");
        else
        {
            int N=ceil(max(-1.0*x*t/l,1.0*y*t/r));
            x=(x*t+l*N)/gcd;y=(y*t-r*N)/gcd;
            if (dfs(x,-y,0)) printf("%d\n",x-y);
            else puts("uh-oh!");
        }
    }
    return 0;
}
