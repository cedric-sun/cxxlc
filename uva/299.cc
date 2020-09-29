#include <cstdio>
#include <algorithm>
using std::swap;
int n,a[55];
int calc()
{
    int cnt=0;
    for (int i=0;i<n-1;i++)
        for (int j=n-1;j>i;j--)
            if (a[j]<a[j-1])
                {swap(a[j],a[j-1]);cnt++;}
            return cnt;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",a+i);
        printf("Optimal train swapping takes %d swaps.\n",calc());
    }
    return 0;
}
