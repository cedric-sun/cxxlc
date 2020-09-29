#include <cstdio>
#include <queue>
#include <set>
using namespace std;

const int a[3]= {2,3,5};
int main()
{
    priority_queue<long long,vector<long long>,greater<long long> > q;
    set<long long> s;
    q.push(1);
    s.insert(1);
    for (int i=1; i<1500; i++)
    {
        long long temp=q.top();
        q.pop();

        for (int j=0; j<3; j++)
        {
            long long temp2=temp*a[j];
            if (!s.count(temp2))
            {
                s.insert(temp2);
                q.push(temp2);
            }
        }
    }
    printf("The 1500'th ugly number is %lld.\n",q.top());
    return 0;
}
