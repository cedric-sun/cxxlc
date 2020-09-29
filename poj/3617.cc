#include <cstdio>
char init[2005],neo[2005];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf(" %c",init+i);
    int hp=0,ep=n-1;

    for (int i=0;i<n;i++)
    {
        if (init[hp]>init[ep]) neo[i]=init[ep--];
        else if (init[hp]<init[ep]) neo[i]=init[hp++];
        else
        {
            int thp=hp,tep=ep;
            while (init[++thp]==init[--tep] && thp<tep);
            if (init[thp]>init[tep]) neo[i]=init[ep--];
            else neo[i]=init[hp++];
        }
    }

    for (int i=0;i<n;i++)
    {
        if (i&&(!(i%80))) putchar('\n');
        putchar(neo[i]);
    }
    putchar('\n');
    return 0;
}
