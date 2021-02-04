#include <cstdio>
#include <algorithm>
using namespace std;

const int N=10000+5;

template <class T>
int bsearch(const T a[],const int c[],int sz,const T &key)
{
    int l=1,r=sz;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (a[c[mid]]<key) l=mid+1;
        else r=mid;
    }
    return l;
}

template <class T>
int LIS(const T a[],int n,int dp[])
{
    int j,sz=1;
    int *c=new int[n+1];

    c[1]=1;
    dp[1]=1;

    for (int i=2;i<=n;i++)
    {
        if (a[i]<=a[c[1]])         j=1;
        else if (a[i]>a[c[sz]])    j=++sz;
        else                       j=bsearch(a,c,sz,a[i]);

        c[j]=i;
        dp[i]=j;
    }

    delete c;
    return sz;
}

int main()
{
    int n;
    int a[N];
    while (~scanf("%d",&n))
    {
        for (int i=1;i<=n;i++) scanf("%d",a+i);

        int dp1[N],dp2[N];

        LIS(a,n,dp1);
        reverse(a+1,a+n+1);
        LIS(a,n,dp2);

        int ans=0;
        for (int i=1;i<=n;i++)
            ans=max(ans,2*min(dp1[i],dp2[n-i+1])-1);

        printf("%d\n",ans);
    }
    return 0;
}
