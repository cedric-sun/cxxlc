#include <cstdio>
#include <cstring>

const int N=1000000,pow10[]={0,0,0,100,1000,10000,100000,1000000};

int p,cirpri[N],ansdic[N];
bool isprime[N];

/*
int bsupper(int x)
{
    int l=0,r=p,m;
    while (l<r)
    {
        m=(l+r)>>1;
        if (cirpri[m]>x) r=m;
        else l=m+1;
    }
    return l-1;
}
int bslower(int x)
{
    int l=0,r=p,m;
    while (l<r)
    {
        m=(l+r)>>1;
        if (cirpri[m]>=x) r=m;
        else l=m+1;
    }
    return l;
}
*/

inline int length(int x)
{
    if (x<1000) return 3;
    if (x<10000) return 4;
    if (x<100000) return 5;
    if (x<1000000) return 6;
    return -1;
}

bool iscirpri(int x)
{
    int tmp=x,len=length(x);
    do
    {
        if (!isprime[tmp]) return 0;
        tmp=(tmp%pow10[len])*10+tmp/pow10[len];
    }while (tmp!=x);

    return 1;
}

void init()
{
    memset(isprime,1,sizeof isprime);
    p=0;
    isprime[1]=0;
    for (int i=2;i<1000;i++)
        if (isprime[i])
            for (int j=2;i*j<N;j++) isprime[i*j]=0;

    ansdic[99]=0;
    for (int i=100;i<N;i++)
    {
        ansdic[i]=ansdic[i-1]+(isprime[i] && iscirpri(i));
        /*
        if (isprime[i] && iscirpri(i))
            cirpri[p++]=i;
            */
    }
}

int main()
{
    int a,b;
    init();
    while (scanf("%d",&a),~a)
    {
        scanf("%d",&b);
        int ans=ansdic[b]-ansdic[a-1];
        //int ans=bsupper(b)-bslower(a)+1;
        if (ans>1)
            printf("%d Circular Primes.\n",ans);
        else if (ans)
            printf("%d Circular Prime.\n",ans);
        else
            printf("No Circular Primes.\n");
    }
    return 0;
}
