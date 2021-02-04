#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main()
{
    int jz1,jz2,i,maxdigit1,maxdigit2,k;
    string num1,num2;
    while (cin>>num1>>num2)
    {
        maxdigit1=1,maxdigit2=1;
        for (i=0; i<num1.length(); i++)
        {

            k=num1[i]>'9'?num1[i]-'A'+10:num1[i]-'0';
            if (k>maxdigit1)
                maxdigit1=k;
        }
        for (i=0; i<num2.length(); i++)
        {

            k=num2[i]>'9'?num2[i]-'A'+10:num2[i]-'0';
            if (k>maxdigit2)
                maxdigit2=k;
        }

        for (jz1=maxdigit1+1; jz1<=36; jz1++)
            for (jz2=maxdigit2+1; jz2<=36; jz2++)
                if (strtol(num1.c_str(),NULL,jz1)==strtol(num2.c_str(),NULL,jz2))
                    goto found;



        printf("%s is not equal to %s in any base 2..36\n",num1.c_str(),num2.c_str());
        continue;
found:
        printf("%s (base %d) = %s (base %d)\n",num1.c_str(),jz1,num2.c_str(),jz2);
    }
    return 0;
}
