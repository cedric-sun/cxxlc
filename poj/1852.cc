#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000000+5];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int len,n;
        scanf("%d %d",&len,&n);
        for (int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        int *it=upper_bound(a,a+n,len>>1);
        if (*it-(len>>1)>(len>>1)-*(it-1)) it--;
        int early=min(*it,len-*it),late=max(len-a[0],a[n-1]);
        printf("%d %d\n",early,late);
    }
    return 0;
}
