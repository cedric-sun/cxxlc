#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int i,j,k;
    char line[200];
    while (gets(line)!=NULL)
    {
        j=0;
        for (i=0;i<=strlen(line);i++)
        {
            if (line[i]=='!'||line[i]=='\n')
            {
                printf("\n");
            }
            else if (isdigit(line[i]))
            {
                j+=line[i]-'0';
            }
            else if (line[i]!='b')
            {
                for (k=0;k<j;k++)
                    printf("%c",line[i]);
                j=0;
            }
            else
            {
                for (k=0;k<j;k++)
                    printf(" ");
                j=0;
            }
        }
        printf("\n");


    }
    return 0;
}
