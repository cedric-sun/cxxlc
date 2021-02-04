#include <stdio.h>
#include <string.h>
int main()
{
    int i,k,j,c1d,c1y,c2n,c2y,c2d,nod;
    char c1m[6];
    char c1ms[19][7]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin","mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
    char c2ds[20][8]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
    scanf("%d",&k);
    printf("%d\n",k);
    for (i=0;i<k;i++)
    {
        nod=0;
        scanf("%d.%s %d",&c1d,c1m,&c1y);
        while (c1y>0)
        {


            nod+=365;
            c1y--;
        }
            j=0;
        while (strcmp(c1m,c1ms[j]))
        j++;
        while (j>0)
        {


            nod+=20;
            j--;
        }
        nod+=c1d;

        c2n=nod/260;
        c2y=(nod%260)%13+1;
        c2d=(nod%260)%20;
        printf("%d %s %d\n",c2y,c2ds[c2d],c2n);

    }
    return 0;
}
