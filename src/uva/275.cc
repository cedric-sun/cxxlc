#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int i,j,k,a,b,result[1001],yushu[1001],yscounter[1001];
    while (cin>>a>>b&&a+b!=0)
    {
        i=0,j=0;


        memset(result,0,sizeof(result));
        memset(yushu,0,sizeof(yushu));
        memset(yscounter,0,sizeof(yscounter));
        a=a%b;
        while (!yushu[a]&&a)
        {
            yushu[a]++;
            yscounter[j++]=a;
            a*=10;
            result[i++]=a/b;
            a=a%b;

        }
        if (a!=0)
        {


            yscounter[j]=a;
            for (k=j-1; yscounter[k]!=yscounter[j]; k--);
            cout<<".";
            for (j=0; j<i; j++)
            {
                if (j&&j%50==0)
                    cout<<endl;
                cout<<result[j];
            }
            cout<<endl<<"The last "<<i-k<<" digits repeat forever.";
        }
        else
            cout<<"This expansion terminates.";
        cout<<endl<<endl;


    }
    return 0;

}
