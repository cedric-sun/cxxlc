#include <cstdio>
#include <cmath>
int main()
{
    int curx,cury,p,n,x,y;
    double dist,ans;
    while (~scanf("%d",&n))
    {
        ans=0;
        while (n--)
        {
            scanf("%d %d %d",&x,&y,&p);
            dist=sqrt( pow(x-curx,2) + pow(y-cury,2) );
            if (dist>p)
                ans+=p;
            else
            {
                ans+=dist+1;
                curx=x;cury=y;
            }
        }
        ans+=sqrt( pow(100-curx,2) + pow(100-cury,2) )+1;
        printf("%.3lf\n",ans);
    }
    return 0;
}
