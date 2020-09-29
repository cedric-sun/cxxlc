#include <iostream>
#include <string>
using namespace std;
int ys[20],ysmax;
void fjys(int a)
{
    int i;
    ysmax=0;
    for (i=1; i<=a/2; i++)
        if (a%i==0)
            ys[ysmax++]=i;
    ys[ysmax]=a;
}
int main()
{
    int i,j,k,l=1,t,n;
    string str;
    cin>>k;
    while (k--)
    {
        cin>>str;

        fjys(str.length());
        for (i=0; i<ysmax; i++)
        {
            t=str.length()/ys[i];


            for (j=0; j<ys[i]; j++)

            {

                for (n=0;n<t-1;n++)
                if (str.at(n*ys[i]+j)!=str.at(j+(n+1)*ys[i]))
                    goto jumper;

            }
            if (j==ys[i])
                break;
                jumper:;
        }
        if (l)
            l=0;
        else
            cout<<"\n";
        cout<<ys[i]<<"\n";
    }
    return 0;
}
