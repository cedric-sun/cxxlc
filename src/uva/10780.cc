#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=10000;

int p,prime[N];
bool isprime[N+5];

void init()
{
    memset(isprime,1,sizeof isprime);
    p=0;
    for (int i=2;i<=N;i++)
    {
        if (isprime[i]) prime[p++]=i;
        for (int j=0;j<p;j++)
        {
            int tmp=i*prime[j];
            if (tmp>N) break;
            isprime[tmp]=0;
            if (!(i%prime[j])) break;
        }
    }
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    for (int k=1;k<=T;k++)
    {
        int m,n,ans=0x7fffffff;
        scanf("%d %d",&m,&n);

        for (int i=0;i<p;i++)
        {
            if (!(m%prime[i]))
            {
                if (prime[i]>n) {ans=-1;break;}
                int cntm=0;
                while (!(m%prime[i]))
                {
                    cntm++;
                    m/=prime[i];
                }
                int tmp=n,cntn=0;
                while (tmp)
                    cntn+=tmp/=prime[i];
                ans=min(ans,cntn/cntm);
            }
        }
        printf("Case %d:\n",k);
        if (~ans)
            printf("%d\n",ans);
        else
            printf("Impossible to divide\n");
    }
    return 0;
}
