#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    double a,b,result;
    char ac[1000],bc[1000],op;
    while (scanf("%s %c %s",ac,&op,bc)!=EOF)
    {
        printf("%s %c %s\n",ac,op,bc);
        a=atof(ac);
        b=atof(bc);
       switch(op)
        {
            case '+':result=a+b;break;
            case '*':result=a*b;break;

        }
        if (a>INT_MAX)
            printf("first number too big\n");
        if (b>INT_MAX)
            printf("second number too big\n");
        if (result>INT_MAX)
        printf("result too big\n");
    }

    return 0;

}
