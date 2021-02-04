#include <cstdio>

const int N=100000+10;

int n,q;
long long seg[N<<2],lazy[N<<2];

void lazydown(int rt,int l,int r)
{
    int k=r-l+1;
    lazy[rt<<1]+=lazy[rt];
    lazy[rt<<1|1]+=lazy[rt];
    seg[rt<<1]+=lazy[rt]*(k-(k>>1));
    seg[rt<<1|1]+=lazy[rt]*(k>>1);
    lazy[rt]=0;
}

long long query(int rt,int l,int r,int ql,int qr)
{
    if (ql<=l && r<=qr) return seg[rt];

    if (lazy[rt]) lazydown(rt,l,r);

    long long ans=0;
    int m=(l+r)>>1;
    if (ql<=m) ans+=query(rt<<1,l,m,ql,qr);
    if (qr>m) ans+=query(rt<<1|1,m+1,r,ql,qr);
    return ans;
}

void update(int rt,int l,int r,int ul,int ur,long long v)
{
    if (ul<=l && r <=ur)
    {
        seg[rt]+=v*(r-l+1);
        lazy[rt]+=v;
        return;
    }

    if (lazy[rt]) lazydown(rt,l,r);

    int m=(l+r)>>1;
    if (ul<=m) update(rt<<1,l,m,ul,ur,v);
    if (ur>m) update(rt<<1|1,m+1,r,ul,ur,v);

    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}

int main()
{
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        update(1,1,n,i,i,tmp);
    }

    for (int i=0;i<q;i++)
    {
        char opt;
        scanf(" %c",&opt);
        if (opt=='Q')
        {
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%lld\n",query(1,1,n,a,b));
        }
        else
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            update(1,1,n,a,b,c);
        }
    }
    return 0;
}
