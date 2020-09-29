#include <cstdio>
const int N=100005;
struct node
{
    int l,r;
    long long v,add;
} segtree[N<<2];

void build(int rt,int l,int r)
{
    segtree[rt].l=l;
    segtree[rt].r=r;
    segtree[rt].v=0;
    if (l==r)
    {
        scanf("%lld",&segtree[rt].v);
        return;
    }
    int m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);

    segtree[rt].v=segtree[rt<<1].v+segtree[rt<<1|1].v;
}

void lazydown(int rt)
{
    if (segtree[rt].add)
    {
        int k=segtree[rt].r-segtree[rt].l+1;
        segtree[rt<<1].add+=segtree[rt].add;
        segtree[rt<<1|1].add+=segtree[rt].add;
        segtree[rt<<1].v+=segtree[rt].add*(k-(k>>1));
        segtree[rt<<1|1].v+=segtree[rt].add*(k>>1);
        segtree[rt].add=0;
    }
}

long long query(int rt,int ql,int qr)
{
    int l=segtree[rt].l,r=segtree[rt].r;
    if (ql==l && r==qr)
        return segtree[rt].v;

    lazydown(rt);

    int m=(l+r)>>1;

    if (qr<=m)
        return query(rt<<1,ql,qr);
    else if (ql>m)
        return query(rt<<1|1,ql,qr);
    else
        return query(rt<<1,ql,m)+query(rt<<1|1,m+1,qr);

}


void add(int rt,int al,int ar,long long addnum)
{
    int l=segtree[rt].l,r=segtree[rt].r;
    if (l==al && r==ar)
    {
        segtree[rt].v+=addnum*(r-l+1);
        segtree[rt].add+=addnum;
        return;
    }
    if (l==r) return;

    lazydown(rt);

    int m=(l+r)>>1;
    if (ar<=m)
        add(rt<<1,al,ar,addnum);
    else if (al>m)
        add(rt<<1|1,al,ar,addnum);
    else
    {
        add(rt<<1,al,m,addnum);
        add(rt<<1|1,m+1,ar,addnum);
    }
    segtree[rt].v=segtree[rt<<1].v+segtree[rt<<1|1].v;

}

int main()
{
    int n,q;
    while (~scanf("%d %d",&n,&q))
    {
        build(1,1,n);

        for (int i=0; i<q; i++)
        {
            char opt[2];
            scanf("%s",opt);
            if (opt[0]=='Q')
            {
                int l,r;
                scanf("%d %d",&l,&r);
                printf("%lld\n",query(1,l,r));
            }
            else
            {
                int l,r;
                long long addnum;
                scanf("%d %d %lld",&l,&r,&addnum);
                add(1,l,r,addnum);
            }

        }
    }
    return 0;
}
