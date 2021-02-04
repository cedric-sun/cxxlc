#include <cstdio>
int x,y,gcd;
void exgcd(int a,int b)
{
    if (!b) {x=1;y=0;gcd=a;return;}
    exgcd(b,a%b);
    int tmp=x;
    x=y;
    y=tmp-a/b*y;
    return;
}

int main()
{
    int a,b;
    while (~scanf("%d %d",&a,&b))
    {
        exgcd(a,b);
        printf("%d %d %d\n",x,y,gcd);
    }
    return 0;
}
