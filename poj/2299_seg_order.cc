#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r

const int N=500000+10;

int a[N],b[N];
int segtree[N<<2];

int bs(int *arr,int l,int r,int key) //binary search
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

void update(int rt,int l,int r,int id)
{
    segtree[rt]++;
    if (l==r) return;
    int m=(l+r)>>1;
    if (id<=m) update(lson,id);
    else update(rson,id);
}

int query(int rt,int l,int r,int ql,int qr)
{
    if (ql<=l && r<=qr) return segtree[rt];
    int sum=0;
    int m=(l+r)>>1;
    if (ql<=m) sum+=query(lson,ql,qr);
    if (qr>m) sum+=query(rson,ql,qr);
    return sum;
}

int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",a+i);
        memcpy(b+1,a+1,sizeof(int)*n);
        sort(b+1,b+n+1);
        for (int i=1;i<=n;i++)
            a[i]=bs(b,1,n,a[i]);

        long long ans=0;
        memset(segtree,0,sizeof(segtree));

        for (int i=1;i<=n;i++)
        {
            ans+=query(1,1,n,a[i],n);
            update(1,1,n,a[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
