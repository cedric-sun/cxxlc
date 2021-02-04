#include <stdio.h>
#include <string.h>
int main()
{
    int I,D,i,cases;
    scanf("%d",&cases);
    while (cases--)
    {
        scanf("%d%d",&D,&I);
        int select=1;
        for (i=1;i<D;i++)
        {
            if (I%2) {select*=2;I=++I/2;}
            else {select=select*2+1;I/=2;}
        }
        printf("%d\n",select);
    }
    return 0;
}
