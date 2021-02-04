#include <iostream>
#include <cstring>
using namespace std;
struct city
{
    int num;
    city *next;
    city *prev;
};
void delpoint(city *p)
{
    p->prev->next=p->next;
    p->next->prev=p->prev;
}
int main()
{
    int numofcity,m;
    city *head,*p1,*p2,*pointer;
    while (cin>>numofcity)
    {
        if (numofcity==0)
            break;
        int i;

        for (m=1;;m++)
        {
            head=new city;
        head->num=1;
        p1=head;
        for (i=1;i<numofcity;i++)
        {
            p2=new city;
            p2->num=i+1;
            p1->next=p2;
            p2->prev=p1;
            p1=p2;
        }
        p2->next=head;
        head->prev=p2;
        pointer=head;
            while (pointer->next!=pointer)
            {
                if (pointer->num==2)
                    break;
                else
                {



                    delpoint(pointer);
                }
                for (i=0;i<m;i++)
                    pointer=pointer->next;
            }
            if (pointer->next==pointer)
                break;
        }
        cout<<m<<endl;

    }
    return 0;
}

