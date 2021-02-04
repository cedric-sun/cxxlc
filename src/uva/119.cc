#include <iostream>
#include <string>
using namespace std;
struct person
{
    int out, in;
    string name;
};
int main()
{
    int nop,firstgroup=1;
    string tempname, tempname2;
    person group[10];

    while (cin >> nop)
    {
        for (int i = 0; i<nop; i++)
        {
            group[i].in = 0;
            group[i].out = 0;
        }
        for (int i = 0; i<nop; i++)
        {
            cin >> group[i].name;
        }
        for (int i = 0; i<nop; i++)
        {
            cin >> tempname;
            for (int j = 0, temp, moneyperperson,outmoney; j<nop; j++)
                if (group[j].name == tempname)
                {
                    cin >>outmoney>> temp;
                    if (!temp)
                        break;
                    moneyperperson = outmoney/ temp;
                    group[j].out = temp*moneyperperson;
                    for (int k = 0; k<temp; k++)
                    {
                        cin >> tempname2;
                        for (int p = 0; p<nop; p++)
                        {
                            if (group[p].name == tempname2)
                            {
                                group[p].in += moneyperperson;
                                break;
                            }
                        }
                    }
                    break;
                }
        }
        if (firstgroup)
            firstgroup = 0;
        else
            cout << endl;
        for (int i = 0; i<nop; i++)
            cout << group[i].name << ' ' << group[i].in - group[i].out << endl;
    }
    return 0;
}
