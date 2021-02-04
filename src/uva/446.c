#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char sljz1[4],sljz2[4],ejz1[13],ejz2[13],operate;
    int sjz1,sjz2,sjz3,sjz4,lenofsljz1,lenofsljz2,k,i,j;
    scanf("%d",&k);
    while (k--)
    {
        scanf("%s %c %s",sljz1,&operate,sljz2);
        for (i=0;i<13;i++)
        {
            ejz1[i]='0';
        }
        for (i=0;i<13;i++)
        {
            ejz2[i]='0';
        }
        sjz1=strtol(sljz1,NULL,16);
        sjz2=strtol(sljz2,NULL,16);
        sjz3=sjz1;
        sjz4=sjz2;
        for (i=0;sjz3!=0;i++)
        {
            ejz1[i]=sjz3%2+'0';
            sjz3/=2;
        }
         for (j=0;sjz4!=0;j++)
        {
            ejz2[j]=sjz4%2+'0';
            sjz4/=2;
        }
        for (i=12;i>=0;i--)
            printf("%c",ejz1[i]);
        printf(" %c ",operate);
        for (j=12;j>=0;j--)
            printf("%c",ejz2[j]);
        switch(operate)
        {
            case '+':printf(" = %d\n",sjz1+sjz2);break;
            case '-':printf(" = %d\n",sjz1-sjz2);break;
        }

    }
    return 0;
}
