#include <cstdio>
using namespace std;

int main(){

	int t;
	scanf("%d",&t);
	while(--t>=0){
		int n,x;
		scanf("%d %d",&n,&x);
		int a[n];
		bool xEqualF = false;
		bool AllEqual = true;
		for(int i = 0 ; i < n; ++i){
			scanf("%d", a+i);
			xEqualF = xEqualF || a[i] == x;
			if(i > 0){
				AllEqual = AllEqual && a[i] == a[i-1];
			}
			
		}
		if(AllEqual && xEqualF){
			printf("0\n");
		}
		else if(xEqualF){
			printf("1\n");
		}
		else{
			int s = 0;
			for(int i = 0; i < n; ++i){
				s += a[i] - x;
			}
			if(!s){
				printf("1\n");
			}
			else{
				printf("2\n");
			}
		}
	}

}