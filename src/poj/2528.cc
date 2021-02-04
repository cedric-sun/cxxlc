#include <bits/stdc++.h>
using namespace std;

const int N=10005;

int k,ans;
int hashp[N<<3],psize,seg[N<<4];
bool vis[N];

struct _post {int l,r;}post[N];

void lazydown(int rt)
{
    seg[rt<<1]=seg[rt<<1|1]=seg[rt];
    seg[rt]=-1;
}

void update(int rt,int l,int r,int &ul,int &ur,int &post_id)
{
    if (ul<=l && r<=ur)
    {
        seg[rt]=post_id;
        return;
    }
    if (seg[rt]!=-1) lazydown(rt);//不是目标区间，并且有ID标记
    int mid=(l+r)>>1;
    if (ul<=mid) update(rt<<1,l,mid,ul,ur,post_id);
    if (ur>mid)  update(rt<<1|1,mid+1,r,ul,ur,post_id);
}

void solve(int rt,int l,int r)
{
    if (seg[rt]!=-1)
    {
        if (!vis[seg[rt]])
        {
            ans++;
            vis[seg[rt]]=1;
        }
        return;
    }

    if (l==r) return;//seg[rt]==-1 && l==r : no post is on this point

    int mid=(l+r)>>1;
    solve(rt<<1,l,mid);
    solve(rt<<1|1,mid+1,r);
}

int main()
{
    int T;cin>>T;
    while (T--)
    {
        int n;cin>>n;
        psize=0;
        for (int i=0;i<n;i++)
        {
            cin>>post[i].l>>post[i].r;
            hashp[psize++]=post[i].l;
            hashp[psize++]=post[i].r;
        }
        sort(hashp,hashp+psize);
        psize=unique(hashp,hashp+psize)-hashp;
        for (int i=psize;i>0;i--)
            if (hashp[i]-hashp[i-1]>1)
                hashp[++k]=hashp[i]-1;
        sort(hashp,hashp+psize);

        memset(seg,-1,sizeof seg);
        for (int i=0;i<n;i++)
        {
            int ul=lower_bound(hashp,hashp+psize,post[i].l)-hashp+1;
            int ur=lower_bound(hashp,hashp+psize,post[i].r)-hashp+1;
            update(1,1,psize-1,ul,ur,i);
        }

        ans=0;
        memset(vis,0,sizeof vis);
        solve(1,1,psize-1);
        printf("%d\n",ans);
    }
}
