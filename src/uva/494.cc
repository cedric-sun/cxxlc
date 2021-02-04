#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    int num_of_word;
    string line;
    while (getline(cin,line))
    {
        num_of_word=0;
        for (int i=1,isword=0;i<line.length();i++)
        {
            if (isalpha(line[i]))
            {
                if (isalpha(line[i-1]))
                    isword=1;
            }
            else
            {
                if (isword)
                    num_of_word++;
                isword=0;
            }
        }
        cout<<num_of_word<<endl;
    }
    return 0;
}
