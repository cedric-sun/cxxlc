#include <cstdio>
#include <algorithm>

using namespace std;

int a[10000+5];

int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        for (int i=0;i<n;i++) scanf("%d",a+i);
        int dp=0,maxS=0x80000000;
        for (int i=0;i<n;i++) dp=max(dp+a[i],a[i]),maxS=max(maxS,dp);
        if (maxS<=0) puts("Losing streak.");
        else printf("The maximum winning streak is %d.\n",maxS);
    }
    return 0;
}
