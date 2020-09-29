#include <cstdio>

const int N=20000+5;

int n,ST,ED,maxS;
int a[N];

void calc()
{
    int dp=0,l=1;
    maxS=0x80000000;
    for (int i=0;i<n-1;i++)
    {
        if (dp>=0) dp+=a[i];
        else dp=a[i],l=i+1;
        if (dp>maxS || dp==maxS && i+2-l>ED-ST)
        {
            maxS=dp;
            ST=l;
            ED=i+2;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int k=1; k<=T; k++)
    {
        scanf("%d",&n);
        for (int i=0; i<n-1; i++) scanf("%d",a+i);
        calc();
        if (maxS<=0)printf("Route %d has no nice parts\n",k);
        else printf("The nicest part of route %d is between stops %d and %d\n",k,ST,ED);
    }
    return 0;
}
