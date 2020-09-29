#include <cstdio>
long long rev(long long a)
{
    long long b=0;
    while (a)
    {
        b=b*10+a%10;
        a/=10;
    }
    return b;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int cnt=0;
        long long num,revnum;
        scanf("%lld",&num);
        while (num!=(revnum=rev(num)))
        {
            num+=revnum;
            cnt++;
        }
        printf("%d %lld\n",cnt,num);
    }
    return 0;
}
