#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int z,l,i,m,temp,length,j,temp2,array[5000],k;
    j=1;
    while (cin>>z>>i>>m>>l)
    {
        k=0;
        memset(array,0,sizeof(array));
        if (z+i+m+l==0)
            break;
        length=0;
        temp2=-1;
        temp=(z*l+i)%m;
        while (temp2!=temp&&temp2!=l)
        {
            if (temp2==-1)
                temp2=temp;
        temp2=(z*temp2+i)%m;
        array[k++]=temp2;
            length++;
        }
        if (temp2==l)
        length++;
            cout<<"Case "<<j++<<": "<<length<<endl;
    }
    return 0;
}
