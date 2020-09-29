#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    int firstword;
    string line,word;
    while (getline(cin,line))
    {

    stringstream ss(line);
        firstword=1;
        while (ss>>word)
        {
        reverse(word.begin(),word.end());
        if (firstword)
            firstword=0;
        else
            cout<<' ';
        cout<<word;
        }
        cout<<endl;
    }
}
