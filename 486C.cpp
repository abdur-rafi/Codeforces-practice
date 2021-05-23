#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n,p;
	scanf("%d %d",&n,&p);
	--p;
	char str[n + 10];
	scanf("%s", str);
	int cost[n];
	int indexes[2] = {n,0};
	for(int i = 0; i < (n / 2); ++i){
		int fi = i;
		int li = n - 1 - i;
		if(str[fi] != str[li]){
			indexes[0] = min(indexes[0],i);
			indexes[1] = max(indexes[1],i);
			int mx = max(str[li], str[fi]);
			int mn = min(str[li], str[fi]);
			cost[i] = min(mx - mn, 26 + mn - mx);
			cost[n - 1 - i] = cost[i];
			// printf("%d\n",cost[n-1-i] );
		}
		else{
			cost[i] = cost[n - 1 - i] = 0;
		}
	}
	if(n % 2)
		cost[n/2] = 0;
	if(indexes[0] == n) {
		printf("0\n");
		return 0;
	}
	// for(int i = 0; i < n; ++i){
	// 	printf("%d ",cost[i] );
	// }
	// printf("\n");
	int res = 0;
	int l = indexes[0];
	int r = indexes[1];

	// printf("%d %d\n",l,r );
	if(p >= (n/2)){
		int tmp = r;
		r = n - 1 - l;
		l = n - 1 - tmp;
	}
	// printf("%d %d\n",l,r );
	int lCost = 0, rCost = 0;
	for(int i = p; i >= l; --i){
		lCost += cost[i];
	}
	for(int i = p; i <= r; ++i){
		rCost += cost[i];
	}
	// printf("%d %d %d %d\n",l,r,lCost,rCost );

	if(p <= l){
		res = rCost + r - p;
	}
	else if(p >= r){
		res = lCost + p - l;
	}
	else{
		int dl = p - l;
		int dr = r - p;
		res = lCost + rCost + dl + dr-cost[p];
		if(dl > dr) res += dr;
		else res += dl;
	}
	printf("%d\n", res);
}