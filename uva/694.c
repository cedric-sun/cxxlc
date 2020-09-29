#include <iostream>
using namespace std;
int main(){
	long long a,limit,b;
	int nCase=1;
	while(cin>>a>>limit){
		b=a;
		if(a==-1&&limit==-1)break;
		int total=0;
		while(1){
			if(a==1){
				total++;
				break;
			}
			if(a>limit){
				break;
			}
			if(a%2==0)a=a/2;
			else a=a*3+1;
			total++;
		}
	 	cout<<"Case "<<nCase++<<": A = "<<b<<", limit = "<<limit<<", number of terms = "<<total<<endl;
	}
	return 0;
}
