#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

PII intersect(int l1,int r1,int l2,int r2){
	if ((r1 < l2) ||  (r2 < l1)) return {-1,-1};
	int l = max(l1,l2);
	int r = min(r1,r2);
	return {l,r};
}

int main(){
	int t;scanf("%d",&t);
	while(--t>=0){
		bool pos = true;
		int n,k,l;scanf("%d %d %d",&n,&k,&l);
		int d[n];
		loop(i,n,0) scanf("%d",d+i);
		loop(i,n,0) d[i] += k;
		PII range = {0,2*k};
		loop(i,n,0){
			// printf("range :  %d %d\n",range.first,range.second );
			if(d[i] <= l ){
				range = {0,2*k};
			}
			else if(d[i] - k > l){
				pos = false;
				break;
			}
			else{
				int rem = d[i] - l;
				rem = k - rem;
				PII curr = {d[i]-l,d[i] - l + 2*rem};
				PII inter = intersect(range.first,range.second,
					curr.first,curr.second);
				if(inter.first == -1){
					pos = false;
					break;
				}
				if(inter.first == range.first){
					range = {inter.first + 1,curr.second};
				}
				else{
					range = {inter.first,curr.second};
				}
				if(range.first > range.second){
					pos	= false;
					break;
				}

			}
		}
		if(pos) printf("Yes\n");
		else printf("No\n");
	}
}