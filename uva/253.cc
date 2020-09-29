#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string str,tz1,tz2,tzt;
char temp;
void tx()
{
    temp=tzt[0],tzt[0]=tzt[3],tzt[3]=tzt[5],tzt[5]=tzt[2],tzt[2]=temp;
}
void ty()
{
    temp=tzt[0],tzt[0]=tzt[4],tzt[4]=tzt[5],tzt[5]=tzt[1],tzt[1]=temp;
}
void tz()
{
    temp=tzt[1],tzt[1]=tzt[2],tzt[2]=tzt[4],tzt[4]=tzt[3],tzt[3]=temp;
}
void turn(int i)
{
    int j;
    switch(i)
    {
        case 0:break;
        case 1:j=3;while (j--) ty();break;
        case 2:j=3;while (j--) tx();break;
        case 3:tx();break;
        case 4:ty();break;
        case 5:j=2;while (j--)tx();break;
    }
}
bool equals()
{
   for (int i=0;i<6;i++)
   {
       tzt=tz1;
       turn(i);
       for (int j=0;j<3;i++)
       {
           if (tzt==tz2)
            return true;
           tz();
       }
       if (tzt==tz2)
            return true;
   }
   return false;
}
int main()
{
    while (cin>>str)
    {
        tz1=str.substr(0,6),tz2=str.substr(6,6);
        cout<<(equals()?"TRUE":"FALSE")<<'\n';
    }
    return 0;
}
