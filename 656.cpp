#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int solve(char str[],int n,int b,char c){
	if(n == 1){
		if(str[b] == c) return 0;
		else return 1;
	}
	int lefta = 0;
	int righta = 0;
	int m = n/2;
	for(int i=b;i<(b+m);++i){
		if(str[i] != c) ++lefta;
	}
	for(int i=b+m;i<(b+n);++i){
		if(str[i] != c) ++righta;
	}
	int leftb = solve(str,n/2,b,c+1);
	int rightb = solve(str,n/2,b+n/2,c+1);
	int mn = lefta+rightb;
	mn = min(mn,leftb+righta);
	return mn;
}

int main(){
	int t;scanf("%d",&t);
	while(--t>=0){
		int n;scanf("%d",&n);
		char str[n+100];
		scanf("%s",str);
		printf("%d\n",solve(str,n,0,'a'));
	}
}