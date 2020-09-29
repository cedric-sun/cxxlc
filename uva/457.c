#include <stdio.h>
#include <string.h>
int main()
{
    int cases,DNA[10],i,j,prevdisk[42],disk[42],firstcase=1;
    scanf("%d",&cases);
    while (cases--)
    {
        for (i=0;i<10;i++)
            scanf("%d",&DNA[i]);
        memset(disk,0,sizeof(disk));
        disk[20]=1;
        memcpy(prevdisk,disk,sizeof(disk));
        if (firstcase)
            firstcase=0;
        else
            printf("\n");
        for (i=0;i<50;i++)
        {
            for (j=1;j<41;j++)
            {
                switch(disk[j])
                {
                    case 0:putchar(' ');break;
                    case 1:putchar('.');break;
                    case 2:putchar('x');break;
                    case 3:putchar('W');break;
                }
                disk[j]=DNA[prevdisk[j-1]+prevdisk[j]+prevdisk[j+1]];
            }
              putchar('\n');
              memcpy(prevdisk,disk,sizeof(disk));
        }
    }
    return 0;
}
