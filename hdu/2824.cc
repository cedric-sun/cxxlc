#include <cstdio>
#include <cstring>

const int N=3000000;

int p,prime[N];
long long phi[N+5];
bool isprime[N+5];

void init()
{
    memset(isprime,1,sizeof isprime);
    p=0;
    for (int i=2;i<=N;i++)
    {
        if (isprime[i])
        {
            prime[p++]=i;
            phi[i]=i-1;
        }
        for (int j=0,tmp;j<p && (tmp=i*prime[j])<=N;j++)
        {
            isprime[tmp]=0;
            if (!(i%prime[j]))
            {
                phi[tmp]=phi[i]*prime[j];
                break;
            }
            else
                phi[tmp]=phi[i]*(prime[j]-1);
        }
    }

    for (int i=3;i<N;i++)
        phi[i]+=phi[i-1];
}

int main()
{
    init();
    int a,b;
    while (~scanf("%d %d",&a,&b))
        printf("%I64d\n",phi[b]-phi[a-1]);
    return 0;
}
