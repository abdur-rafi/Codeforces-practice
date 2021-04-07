#include <bits/stdc++.h>
using namespace std;

int main(){

	int t = 1;
	scanf("%d",&t);
	while(--t>=0){
		int n; scanf("%d",&n);
		int a[n];
		for(int i=0;i<n;++i){
			scanf("%d",a+i);
		}
		for(int i=0;i<n;++i) printf("%d",*(a+i));
	}
}