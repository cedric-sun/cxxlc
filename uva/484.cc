#include <iostream>
#include <vector>
using namespace std;
struct num
{
    int data,frequence;
};
int main()
{
    int n,flag;
    vector<num> a;
    while (cin>>n)
    {
        flag=0;
        for (unsigned i=0;i<a.size();i++)
        {
            if (a[i].data==n)
            {
                a[i].frequence++;
                flag=1;
                break;
            }
        }
        if (!flag)
        {
            num *p=new num;
            p->data=n;
            p->frequence=1;
            a.push_back(*p);
        }
    }
    /*≈≈–Ú
    for (unsigned i=0;i<a.size()-1;i++)
    {
        unsigned j=i;
        for (unsigned k=i+1;k<a.size();k++)
        {
            if (a[k].frequence>a[j].frequence)
                j=k;
        }
        if (j!=i)
        {
            int temp;
            temp=a[i].data;
            a[i].data=a[j].data;
            a[j].data=temp;
            temp=a[i].frequence;
            a[i].frequence=a[j].frequence;
            a[j].frequence=temp;
        }
    }
*/

    for (unsigned i=0;i<a.size();i++)
        cout<<a[i].data<<' '<<a[i].frequence<<endl;
    return 0;
}
