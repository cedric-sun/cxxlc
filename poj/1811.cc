#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;

typedef long long ll;

const int S=15;

ll maxf;

ll mod_mul(ll a, ll b, ll n)
{
    ll res = 0;
    while(b)
    {
        if(b&1)    res = (res + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
    return res;
}

ll mod_exp(ll a, ll b, ll n)
{
    ll res = 1;
    while(b)
    {
        if(b&1)    res = mod_mul(res, a, n);
        a = mod_mul(a, a, n);
        b >>= 1;
    }
    return res;
}

bool miller_rabin(ll n)
{
    if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11)    return true;
    if(n == 1 || !(n%2) || !(n%3) || !(n%5) || !(n%7) || !(n%11))    return false;

    ll x, pre, u;
    int i, j, k = 0;
    u = n - 1;

    while(!(u&1))
    {
        k++;
        u >>= 1;
    }

    //srand((ll)time(0));
    for(i = 0; i < S; ++i)
    {
        x = rand()%(n-2) + 2;
        if((x%n) == 0)    continue;

        x = mod_exp(x, u, n);
        pre = x;
        for(j = 0; j < k; ++j)
        {
            x = mod_mul(x, x, n);
            if(x == 1 && pre != 1 && pre != n-1)    return false;
            pre = x;
        }
        if(x != 1)    return false;
    }
    return true;
}


ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

ll pollard_rho(ll n, ll c)
{
    ll x, y, d;
    ll i, k;
    i = 1;
    k = 2;

    //srand((ll)time(0));
    x = rand()%(n-1) + 1;
    y = x;

    while(1)
    {
        i ++;
        x = (mod_exp(x, 2, n) + c) % n;
        d = gcd(y - x + n, n);
        if(d != 1 && d != n)    return d;
        if(x == y)    return n;
        if(i == k)
        {
            y = x;
            k *= 2;
        }
    }
}

void factor(ll n)
{
    if(n <= 1)    return ;
    if(miller_rabin(n))
    {
        maxf=max(maxf,n);
        return;
    }
    ll p=n;
    while (p>=n) p=pollard_rho(n,rand()%(n-1)+1);
    factor(p);
    factor(n/p);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n;
        scanf("%lld",&n);
        if (n==1)
        {
            printf("1\n");
            continue;
        }
        if (miller_rabin(n))
        {
            printf("Prime\n");
            continue;
        }
        maxf=0;
        factor(n);
        printf("%lld\n",maxf);
    }
    return 0;
}
