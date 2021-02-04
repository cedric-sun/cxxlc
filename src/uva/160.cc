#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int zssto[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int tj[25];
    int a,i,j,jmax,k;
    while (cin>>a)
    {
        if (!a)
            break;
        memset(tj,0,sizeof(tj));
        jmax=0;
        for (i=2;i<=a;i++)
        {
            k=i;
            for (j=0;j<25;j++)
            {
                while (k%zssto[j]==0)
                {


                    tj[j]++;
                    k/=zssto[j];
                }
                if (k<zssto[j])
                    break;
            }
            if (j>jmax)
                jmax=j;
        }
        printf("%3d! =",a);
        for (i=0;i<=jmax;i++)
        {


            printf("%3d",tj[i]);
            if (i==14&&jmax>14)
            {
                printf("\n      ");
            }
        }
        printf("\n");

    }
    return 0;
}
