#include <stdio.h>
#include <stdbool.h>
static int storage[1000000];
static bool calced[1000000];
int main()
{
    int d1,d2,lb,ub,i,j,c,maxl;
    while (scanf("%d%d",&d1,&d2)!=EOF)
    {
        if (d1>d2)
            ub=d1,lb=d2;
        else
            ub=d2,lb=d1;
        maxl=0;
        for (i=lb; i<=ub; i++)
        {
            if (!calced[i])
            {
                j=i;
                c=1;
                while (j!=1)
                {
                    if (j%2)
                        j=j*3+1;
                    else
                        j>>=1;
                    c++;
                }
                storage[i]=c;
                calced[i]=true;
            }
            if (storage[i]>maxl)
                maxl=storage[i];
        }
        printf("%d %d %d\n",d1,d2,maxl);
    }
    return 0;
}
