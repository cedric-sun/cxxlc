#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int length,maxlength,flag;
    long int a,b,x0,maxx,k,temp;
    while (cin>>a>>b)
    {
        if (a+b==0)
            break;
        maxlength=0;
        flag=0;
        if (a>b)
        {
            temp=a;
            a=b;
            b=temp;
            flag=1;
        }
        k=a;
        for (x0=a;x0<=b;x0++)
        {
            k=x0;
            length=0;
            do
            {


            if (k%2==0)
                k/=2;
            else
                k=3*k+1;
                length++;
            }while (k!=1);
            if (length>maxlength)
            {


                maxlength=length;
                maxx=x0;
            }
        }
        if (flag)
        {
            temp=a;
            a=b;
            b=temp;
        }
        printf("Between %ld and %ld, %ld generates the longest sequence of %d values.\n",a,b,maxx,maxlength);
    }
    return 0;
}
