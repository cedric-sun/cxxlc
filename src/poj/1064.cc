#include <cstdio>
int n,k,cable[10005];
int cut(int x)
{
    int cnt=0;
    for (int i=0;i<n;i++)
        cnt+=cable[i]/x;
    return cnt;
}
int main()
{
    while (scanf("%d %d",&n,&k)!=EOF)
    {
        int sum=0;
        for (int i=0; i<n ;i++)
        {
            double temp;
            scanf("%lf",&temp);
            cable[i]=(int)(temp*100);
            sum+=cable[i];
        }

        int x=(sum/k)+1,y=1,m,ans=0;
        while (x>=y)
        {
            m=(x+y)/2;
            if (cut(m)>=k)
                {y=m+1;ans=m;}
            else
                x=m-1;
        }
        printf("%.2lf\n",ans*0.01);
    }
}
