#include <stdio.h>
int main()
{
    int n,A,F,firstcase=1,firstzq,i,j,k,m;
    scanf("%d",&n);
    while (n--)
    {
        if (firstcase)
            firstcase=0;
        else
            printf("\n");
        scanf("%d%d",&A,&F);
        for (i=0,firstzq=1;i<F;i++)
        {
            if (firstzq)
                firstzq=0;
            else
                printf("\n");
            for (j=1,k=0;j>=1;++k<A?j++:j--)
            {
                for (m=0;m<j;m++)
                   putchar(j+'0');
                    putchar('\n');
            }
        }
    }
    return 0;
}
