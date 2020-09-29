#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int l=35;


int cake[l],goal[l],num;

int findx(int x)
{
    for (int i=1; i<num; i++)
        if (cake[i]==x)
            return i;
    return 0;
}
int main()
{
    string line;
    while (getline(cin,line))
    {
        cout<<line<<'\n';
        num=1;
        stringstream ss(line);
        int x;
        while (ss>>x) cake[num++]=x;

        memcpy(goal+1,cake+1,sizeof(int)*num);
        sort(goal+1,goal+num);

        for(int i=num-1; i>=1; i--)
        {
            int index=findx(goal[i]);
            if (index!=i)
            {
                if (index!=1)
                {
                    printf("%d ",num-index);
                    reverse(cake+1,cake+index+1);
                }

                printf("%d ",num-i);
                reverse(cake+1,cake+i+1);

            }
        }
        printf("0\n");
    }
    return 0;
}
