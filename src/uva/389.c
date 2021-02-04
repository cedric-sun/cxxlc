#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char numtotrans[8],numaftertrans[8];
    int i,k,jzbt,jzat,sjz,sjz2,lenofnum;
    while (scanf("%s %d %d",numtotrans,&jzbt,&jzat)!=EOF)
    {
        sjz=strtol(numtotrans,NULL,jzbt);
        sjz2=sjz;
        for (i=0;sjz2!=0;i++)
        {
            switch(sjz2%jzat)
            {
                case 10:numaftertrans[i]='A';break;
                case 11:numaftertrans[i]='B';break;
                case 12:numaftertrans[i]='C';break;
                case 13:numaftertrans[i]='D';break;
                case 14:numaftertrans[i]='E';break;
                case 15:numaftertrans[i]='F';break;
                default:numaftertrans[i]=sjz2%jzat+'0';break;
            }
            sjz2/=jzat;

        }
        if (i>7)
            {
                printf("  ERROR\n");
                continue;
            }
            else if (i==0)
            {
                printf("      0\n");
                continue;
            }
            for (k=i;k<7;k++)
                printf(" ");
        for (i--;i>=0;i--)
            printf("%c",numaftertrans[i]);
        printf("\n");


    }
    return 0;
}
