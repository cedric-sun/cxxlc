#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N=5000000;

int p,ans[N+5],sum[N+5],prime[N+5];
bool isprime[N+5];

void init()
{
    memset(isprime,1,sizeof isprime);
    p=ans[1]=0;
    for (int i=2;i<=N;i++)
    {
        if (isprime[i])
        {
            prime[p++]=i;
            sum[i]=i;
        }
        for (int j=0;j<p && i*prime[j]<=N;j++)
        {
            isprime[i*prime[j]]=0;
            if (!(i%prime[j]))
            {
                sum[i*prime[j]]=sum[i];
                break;
            }
            else
            {
                sum[i*prime[j]]=sum[i]+prime[j];
            }
        }
        ans[i]=ans[i-1]+isprime[sum[i]];
    }
}

int main()
{
    init();
    int a,b;
    while (scanf("%d",&a),a)
    {
        scanf("%d",&b);
        printf("%d\n",ans[b]-ans[a-1]);
    }
    return 0;
}
