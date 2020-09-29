#include <cstdio>
#include <algorithm>
using namespace std;

const int N=10000+5;

int n;
int a[N];

int main()
{
    int case_cnt=0;
    while (scanf("%d",&n),n)
    {
        for (int i=0;i<n;i++) scanf("%d",a+i);

        sort(a,a+n);

        int bag_num=0,cnt=1;
        for (int i=1;i<n;i++)
        {
            if (a[i]!=a[i-1])
            {
                bag_num=max(bag_num,cnt);
                cnt=1;
            }
            else cnt++;
        }
        bag_num=max(bag_num,cnt);

        if (case_cnt++) putchar('\n');
        printf("%d\n",bag_num);
        for (int i=0;i<bag_num;i++)
        {
            printf("%d",a[i]);
            for (int j=i+bag_num;j<n;j+=bag_num) printf(" %d",a[j]);
            putchar('\n');
        }
    }
    return 0;
}
