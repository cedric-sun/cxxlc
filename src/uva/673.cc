#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
inline bool match(char a,char b)
{
    if (a==')')
    {
        if (b=='(') return true;
    }
    else if (a==']')
    {
        if (b=='[') return true;
    }
    return false;
}
int main()
{
    int T,len;
    char temp;
    bool legal;
    string line;
    stack<char> s;
    cin>>T;
   // getchar();
    while (T--)
    {
        legal=1;
        getline(cin,line);
        len=line.length();
        for (int i=0; i<len; i++)
        {
            temp=line[i];
            if (temp=='('||temp=='[')
                s.push(temp);
            else
            {
                if (!s.empty()&&match(temp,s.top()))
                    s.pop();
                else
                {
                    legal=0;
                    break;
                }
            }
        }
        cout<<(legal?"Yes":"NO")<<'\n';
    }
}
