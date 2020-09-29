#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int sum(int *a);
void ysfj(int a,int *b);
int main()
{
    int num,ys[100];
    cout<<"PERFECTION OUTPUT"<<endl;
    while (cin>>num)
    {
        if (num==0)
            break;
            if (num==1)
            {
                cout<<setw(5)<<num<<"  "<<"ABUNDANT"<<endl;
                continue;
            }
        memset(ys,0,sizeof(ys));
        ysfj(num,ys);
        cout<<setw(5)<<num<<"  ";
        if (sum(ys)>num)
            cout<<"ABUNDANT";
        else if (sum(ys)<num)
            cout<<"DEFICIENT";
        else
            cout<<"PERFECT";
        cout<<endl;

    }
    cout<<"END OF OUTPUT";
}
void ysfj(int a,int *b)
{
    int i,j;
    j=0;
    for (i=1;i<a/2+1;i++)
        if (a%i==0)
        b[j++]=i;
}
int sum(int *a)
{
    int i,s;
    s=0;
    for (i=0;a[i]!=0;i++)
        s+=a[i];
    return s;
}
