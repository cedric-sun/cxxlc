#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

const int N=1000000;

int p,prime[N],asize;
bool isprime[N+5];
ll ans[N];

void init()
{
    memset(isprime,1,sizeof isprime);
    p=0;
    for (int i=2; i<=N; i++)
    {
        if (isprime[i]) prime[p++]=i;
        for (int j=0,tmp; j<p && (tmp=i*prime[j])<=N; j++)
        {
            isprime[tmp]=0;
            if (!(i%prime[j])) break;
        }
    }

    asize=0;
    for (int i=0;i<p;i++)
    {
    	ll tmp;
    	for (int j=2;(tmp=round(pow(prime[i],j)))<1e12;j++)
    		ans[asize++]=tmp;
    }

    sort(ans,ans+asize);
}

int main()
{
    init();
	int T;
    scanf("%d",&T);
	while (T--)
	{
		ll lb,ub;
		scanf("%lld %lld",&lb,&ub);
		printf("%d\n",(int)(upper_bound(ans,ans+asize,ub)-lower_bound(ans,ans+asize,lb)));
	}
	return 0;
}
