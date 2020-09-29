#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
struct person
{
    string dep,info[15];//理论上开7即可
};
int main()
{
    unsigned int numofdepartment,i,j,k,t,q;
    string department,line;
    person *p[500];//理论上开小一点也没问题
    k=-1;

//输入部分
    cin>>numofdepartment;
    getchar();
    while (numofdepartment--)
    {

        getline(cin,department);
        while (1)
        {
            getline(cin,line);
            if (!line.empty())
            {
                j=0;
                p[++k]=new person;
                for (i=0; i<line.length(); i++)
                    if (line[i]!=','&&line[i]!='\n')
                        p[k]->info[j]+=line[i];
                    else
                        j++;

                p[k]->dep=department;
            }
            else break;
        }

    }

//排序部分
    for (i=0; i<k; i++)
    {
        t=i;
        for (q=i+1; q<=k; q++)
            if (p[q]->info[2]<p[t]->info[2])
                t=q;
        if (t!=i)
        {
            person *temp;
            temp=p[t];
            p[t]=p[i];
            p[i]=temp;
        }
    }

//输出部分
    for (i=0; i<=k; i++)
    {
        cout<<"----------------------------------------\n";
        cout<<p[i]->info[0]<<" "<<p[i]->info[1]<<" "<<p[i]->info[2]<<endl;
        cout<<p[i]->info[3]<<endl;
        cout<<"Department: "<<p[i]->dep<<endl;
        cout<<"Home Phone: "<<p[i]->info[4]<<endl;
        cout<<"Work Phone: "<<p[i]->info[5]<<endl;
        cout<<"Campus Box: "<<p[i]->info[6]<<endl;
    }
    return 0;
}
