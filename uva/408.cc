#include <iostream>
#include <iomanip>
using namespace std;
int ifhuzhi(int a,int b);
int main()
{
    int step,mod;
    while (cin>>step>>mod)
        cout<<setw(10)<<step<<setw(10)<<mod<<"    "<<(ifhuzhi(step,mod)?"Good Choice":"Bad Choice")<<endl<<endl;
    return 0;
}
int ifhuzhi(int a,int b)
{
    int temp;
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
    if (b==1)
        return 1;
    return 0;
}
