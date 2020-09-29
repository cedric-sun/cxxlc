#include <cstdio>
#include <cstring>

const int N=1<<15;

int p,prime[N];
bool isprime[N];

int bs(int x)
{
    int l=0,r=p-1,m;
    while (l<r)
    {
        m=(l+r)>>1;
        if (prime[m]>x) r=m;
        else l=m+1;
    }
    return l-1;
}

void init()
{
    memset(isprime,1,sizeof isprime);
    p=0;
    isprime[1]=0;
    for (int i=2;i<=1000;i++)
        if (isprime[i])
            for (int j=2;j*i<=N;j++) isprime[i*j]=0;

    for (int i=2;i<=N;i++)
        if (isprime[i])
            prime[p++]=i;
}

int calc(int n)
{
    int half=n>>1,cnt=0;
    for (int i=bs(n);prime[i]>=half;i--)
        if (isprime[n-prime[i]])
            cnt++;
    return cnt;
}

int main()
{
    int n;
    init();
    while (scanf("%d",&n),n)
        printf("%d\n",calc(n));
    return 0;
}
