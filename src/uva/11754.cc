#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int c,s,k_prod,max_xdivk_index;
int x[10],k[10],y[10][105];
ll lcm;

void exgcd(ll a,ll b,ll &gcd,ll &x,ll &y)//ax+by=gcd
{
	if(!b){gcd=a;x=1;y=0;return;}
	exgcd(b,a%b,gcd,y,x);
	y-=x*(a/b);
}

//return x if exist,which x*a mod n = 1
ll mod_inv(ll a,ll n)
{
	ll x,y,gcd;
	exgcd(a,n,gcd,x,y);
	return gcd==1?(x+n)%n:-1;
}

int calc(const int remainder[])
{
    ll ans=0;
    for (int i=0;i<c;++i)
    {
        ll Mi=lcm/x[i];
        ans=(ans+Mi*mod_inv(Mi,x[i])*remainder[i])%lcm;
    }
    return (ans+lcm)%lcm;
}

void dfs(int d,vll &solu)
{
    static int remainder[10];
    if (d>=c) {solu.push_back(calc(remainder));return;}
    for (int i=0;i<k[d];++i)
    {
        remainder[d]=y[d][i];
        dfs(d+1,solu);
    }
}

void small_scale_solu()
{
    vll solution;
    dfs(0,solution);
    sort(solution.begin(),solution.end());
    for (int i=0;s;++i)
        for (int j=0;j<solution.size();++j)
        {
            printf("%lld\n",lcm*i+solution[j]);
            if (!(--s)) break;
        }
    putchar('\n');
}

void big_scale_solu()
{
    set<int> remainders[10];
    for (int i=0;i<c;++i)
    {
        if (c==max_xdivk_index) continue;
        for (int j=0;j<k[i];++j)
            remainders[i].insert(y[i][j]);
    }

    for (int i=0;s;++i)
    {
        for (int j=0;j<k[max_xdivk_index];++j)
        {
            ll ans=(ll)x[max_xdivk_index]*i+y[max_xdivk_index][j];
            if (!ans) continue;
            bool ok=1;
            for (int t=0;t<c;++t)
            {
                if (t==max_xdivk_index) continue;
                if (!remainders[t].count(ans%x[t]))
                {
                    ok=0;
                    break;
                }
            }

            if (ok)
            {
                printf("%lld\n",ans);
                if (!(--s)) break;
            }
        }
    }
    putchar('\n');
}
int main()
{
    while (scanf("%d %d",&c,&s),c||s)
    {
        k_prod=1,max_xdivk_index=0;
        for (int i=0;i<c;++i)
        {
            scanf("%d %d",x+i,k+i);
            k_prod*=k[i];
            for (int j=0;j<k[i];++j)
                scanf("%d",y[i]+j);
            if (x[i]*k[max_xdivk_index]>x[max_xdivk_index]*k[i])
                max_xdivk_index=i;
        }
        lcm=1;
        for (int i=0;i<c;++i) lcm*=x[i];
        if (k_prod<=10000) small_scale_solu();
        else big_scale_solu();
    }
    return 0;
}
