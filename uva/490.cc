#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int maxlength=0;
    vector<string> input,output;
    string temp;
    while (getline(cin,temp))
    {
        if (temp.length()>maxlength)
            maxlength=temp.length();
        input.push_back(temp);
    }
    temp.clear();
    for (int i=0;i<maxlength;i++)
    {
        for (int j=input.size()-1;j>=0;j--)
        {
            if (i<input[j].length())
                temp+=input[j][i];
            else
                temp+=' ';

        }
        output.push_back(temp);
        temp.clear();
    }
    for (int i=0;i<maxlength;i++)
        cout<<output[i]<<endl;
    return 0;
}
