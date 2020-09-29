#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int N=sqrt(32767);

int p,k,prime[N],ans[N][2];
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

void calc(int n)
{
    k=0;
    for (int i=0;i<p;i++)
    {
        if (!(n%prime[i]))
        {
            ans[k][0]=prime[i];
            ans[k][1]=0;
            while (!(n%prime[i]))
            {
                ans[k][1]++;
                n/=prime[i];
            }
            ++k;
        }
        if (n==1) break;
    }
    if (n!=1)
    {
        ans[k][0]=n;
        ans[k++][1]=1;
    }
}

int main()
{
    init();
    string line;
    while (getline(cin,line),line!="0")
    {
        stringstream ss(line);
        int a,exp,num=1;
        while (ss>>a>>exp)
            while (exp--) num*=a;

        calc(num-1);

        for (int i=k-1;i>=0;i--)
        {
            if (i!=k-1) putchar(' ');
            printf("%d %d",ans[i][0],ans[i][1]);
        }
        putchar('\n');
    }
    return 0;
}
