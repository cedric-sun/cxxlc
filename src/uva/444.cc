#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;
string input,output;
void translate()
{
    string str;
    reverse(input.begin(),input.end());
    if (input[0]>='0'&&input[0]<='9')
    {
        for (int i=0;i<input.length();)
        {

            if (input[i]=='1')
            {
                str.assign(input,i,3);
                i+=3;

            }
            else
            {
                str.assign(input,i,2);
                i+=2;
            }
            output+=atoi(str.c_str());
        }
    }
    else
    {
        for (int i=0;i<input.length();i++)
        {
            char a[4];
            sprintf(a,"%d",(int)input[i]);
            str=a;
            reverse(str.begin(),str.end());
            output+=str;
        }
    }
}
int main()
{
    while (getline(cin,input))
    {
        output.clear();
        translate();
        cout<<output<<endl;
    }
    return 0;
}
