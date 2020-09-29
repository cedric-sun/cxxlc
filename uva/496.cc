#include <iostream>
#include <cstring>
using namespace std;
int pdgx(string a[],string b[],int lenofa,int lenofb);
int main()
{
    int i,j,k;
    string line1,line2,tq1[20],tq2[20];
    while (getline(cin,line1)&&getline(cin,line2))
    {
        j=0;
       for (i=0;i<20;i++)
       {
           tq1[i]="";
           tq2[i]="";
       }
       for(i=0;i<line1.length();i++)
        if (line1.at(i)>='0'&&line1.at(i)<='9')
            tq1[j]+=line1.at(i);
            else
            {
                tq1[j]+='\0';
                j++;
            }
            k=0;
            for(i=0;i<line2.length();i++)
        if (line2.at(i)>='0'&&line2.at(i)<='9')
            tq2[k]+=line2.at(i);
            else
            {
                tq2[k]+='\0';
                k++;
            }
            switch(pdgx(tq1,tq2,j,k))
            {
                case 0:cout<<"A and B are disjoint";break;
                case 1:cout<<"I'm confused! ";break;
                case 2:cout<<"A equals B";break;
                case 3:cout<<"A is a proper subset of B";break;
                case 4:cout<<"B is a proper subset of A";break;
            }
            cout<<endl;


    }
    return 0;
}
int pdgx(string& a[],string& b[],int lenofa,int lenofb)
{
    int i,j,k;
    k=0;
    for (i=0;i<=lenofa;i++)
        for (j=0;j<=lenofb;j++)
            if (a[i]==b[j])
            k++;
        if (k==0)
            return 0;
        if (k<lenofa&&k<lenofb)
            return 1;
        if (k==lenofa&&k==lenofb)
            return 2;
        if (k==lenofa)
        return 3;
        if (k==lenofb)
            return 4;
}
