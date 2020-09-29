#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=500000+10;

int n,a[N],b[N],bit[N];

int bs(int *arr,int l,int r,int key)
{
    int m;
    while (l<r)
    {
        m=(l+r)>>1;
        if (arr[m]>=key) r=m;
        else l=m+1;
    }
    return l;
}

void update(int k)
{
    while (k<=n)
    {
        bit[k]++;
        k+=k&-k;
    }
}
int sum(int k)
{
    int s=0;
    while (k)
    {
        s+=bit[k];
        k-=k&-k;
    }
    return s;
}
int main()
{
    while (scanf("%d",&n),n)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",a+i);
        memcpy(b+1,a+1,sizeof(int)*n);
        sort(b+1,b+n+1);

        for (int i=1;i<=n;i++)
            a[i]=bs(b,1,n,a[i]);

        long long ans=0;
        memset(bit,0,sizeof(bit));

        for (int i=1;i<=n;i++)
        {
            ans+=i-sum(a[i])-1;
            update(a[i]);
        }

        printf("%lld\n",ans);
    }
    return 0;
}
