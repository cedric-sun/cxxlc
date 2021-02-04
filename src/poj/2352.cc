//1164K	219MS
//1164K	235MS
//1164K	172MS
#include<iostream>
#include<cstdio>
#include<cstring>
#define mid ((left+right)>>1)
#define lson rt<<1,left,mid
#define rson rt<<1|1,mid+1,right
using namespace std;

const int MAXN = 32005;

int sum[MAXN<<2],level[MAXN<<2];

void update(int rt,int left,int right,int data){
    ++sum[rt];
    if(left==right) return;
    if(data <= mid) update(lson,data);
    else update(rson,data);
}
int query(int rt,int left,int right,int l,int r){
    if(left==l && right==r) {
        return sum[rt];
    }
    int m = mid;
    if(r <= m) return query(lson,l,r);
    else if(l > m) return query(rson,l,r);
    else return query(lson,l,m)+query(rson,m+1,r);
}

int main(){
    int n,x,y;
    while(~scanf("%d",&n)){
        memset(sum, 0, sizeof(sum));
        memset(level, 0, sizeof(level));
        for(int i=0; i<n; ++i){
            scanf("%d%d",&x,&y);
            ++x;
            ++level[query(1,1,MAXN,1,x)];
            update(1,1,MAXN,x);
        }
        for(int i=0; i<n; ++i)
            printf("%d\n",level[i]);
    }
    return 0;
}
