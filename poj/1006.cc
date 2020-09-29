#include <cstdio>

/*
S=p+23k1      S≡p mod 23
S=e+28k2      S≡e mod 28
S=i+33k3      S≡i mod 33
*/

int main()
{
    int p,e,i,d,cnt=1;
    int lcm=21252,ntr1=5544,ntr2=14421,ntr3=1288;
    while (scanf("%d %d %d %d",&p,&e,&i,&d),~p)
    {
        int ans=(ntr1*p+ntr2*e+ntr3*i+lcm-d)%lcm;
        if (!ans) ans=lcm;
        printf("Case %d: the next triple peak occurs in %d days.\n",cnt++,ans);
    }
    return 0;
}
