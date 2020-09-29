#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    char c;
    map<string,string> ans;
    while ((c=getchar())!='\n')
    {
        ungetc(c,stdin);
        char value[15],key[15];
        scanf("%s %s",value,key);
        getchar();
        ans[key]=value;
    }

    char query[15];
    while (~scanf("%s",query))
    {
        string a=ans[query];
        cout<<(a.empty()?"eh":a)<<'\n';
    }
    return 0;
}
