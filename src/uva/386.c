#include <stdio.h>
int main()
{
    int a,b,c,d,apow,bpow,cpow,dpow;
    for (a=6;a<=200;a++)
    {
        apow=a*a*a;
        for (b=2;b<a-2;b++)
        {
            bpow=b*b*b;
            for (c=b+1;c<a-1;c++)
            {
                cpow=c*c*c;
                for (d=c+1;d<a;d++)
                {
                    dpow=d*d*d;
                    if (apow==bpow+cpow+dpow)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                }
            }
        }
    }
    return 0;
}
