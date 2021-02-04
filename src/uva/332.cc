#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
void yf(int *a,int *b);
int main()
{
    int k,i,j,fz,fm,lenofxs;
    char xs[30];
    while (cin>>j)
    {
        if (j==-1)
            break;
        cin>>xs;
        for (i=0; xs[i]!='.'; i++);
        lenofxs=strlen(xs);
        k=lenofxs-i-j-1;
        for (i=lenofxs; i<lenofxs+j; i++)
            xs[i]=xs[i-j];
        fz=(int)(pow(10,k+j)*atof(xs)-pow(10,k)*atof(xs)+0.5);
        fm=pow(10,k+j)-pow(10,k);
            yf(&fz,&fm);
            cout<<fz<<'/'<<fm<<endl;
    }
    return 0;
}
void yf(int *n,int *m)
{
    int temp,a,b;
    a=*n,b=*m;
    if (a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    temp=a%b;
    while (temp!=0)
    {
        a=b;
        b=temp;
        temp=a%b;
    }
    *n/=b;
    *m/=b;

}
