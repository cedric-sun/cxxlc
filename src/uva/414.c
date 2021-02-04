#include <stdio.h>
int main()
{
    int i,j,sumofx[100],row,numofx,maxofx,numofvoid;
    char temp;
    while (scanf("%d",&row)&&row!=0)
    {
        getchar();
        numofx=0;
        j=0;
        for (i=0;i<row;)
        {
            temp=getchar();
            if (temp=='X')
                numofx++;
            else if (temp=='\n')
            {
                sumofx[j++]=numofx;
                numofx=0;
                i++;
            }
        }
        maxofx=0;
        for (i=1;i<row;i++)
        {
            if (sumofx[i]>sumofx[maxofx])
                maxofx=i;
        }
        numofvoid=0;
        for (i=0;i<row;i++)
        {
            numofvoid+=sumofx[maxofx]-sumofx[i];
        }
        printf("%d\n",numofvoid);
    }
    return 0;
}
