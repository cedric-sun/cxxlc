#include <iostream>
using std::cin;
#include <cstdio>
int main()
{
    int cross,in,flag=1;
    double i,j,n;
    while (cin>>n)
    {
        cross=0,in=0;
        for (i=0;i<n-0.1;i++)
            for (j=0;j<n-0.1;j++)
            {
                if (i*i+j*j<(n-0.5)*(n-0.5))
                    if ((i+1)*(i+1)+(j+1)*(j+1)<(n-0.5)*(n-0.5))
                    in++;
                else
                    cross++;
            }
            if (flag)
                flag=0;
            else
                printf("\n");
            printf("In the case n = %d, %d cells contain segments of the circle.\n",(int)n,4*cross);
            printf("There are %d cells completely contained in the circle.\n",4*in);

    }
    return 0;
}
