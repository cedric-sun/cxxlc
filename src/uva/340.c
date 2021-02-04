#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,k,a,b,pw[1000],gs[1000],usedpw[1000],usedgs[1000],tempsum,games=1;
    while (scanf("%d",&k)!=EOF&&k)
    {
        for (i=0;i<k;i++)
            scanf("%d",&pw[i]);
            printf("Game %d:\n",games++);
        while (1)
        {

        tempsum=0;
        for (i=0;i<k;i++)
        {
            scanf("%d",&gs[i]);
            tempsum+=gs[i];
        }
        if (!tempsum)
            break;
        a=0,b=0;
        memset(usedpw,0,sizeof(usedpw));
        memset(usedgs,0,sizeof(usedgs));
            for (i=0;i<k;i++)
            {
                if (pw[i]==gs[i])
                {
                    usedpw[i]=1;
                    usedgs[i]=1;
                    a++;
                }
            }
        for (i=0;i<k;i++)
        {
            if (usedpw[i])
                continue;
            for (j=0;j<k;j++)
            {
                if (usedgs[j]||usedpw[i])
                    continue;
                if (pw[i]==gs[j])
                {
                    usedpw[i]=1;
                    usedgs[j]=1;
                        b++;
                }
            }
        }
        printf("    (%d,%d)\n",a,b);
        }
    }
    return 0;
}
